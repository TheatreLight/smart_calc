/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Copyright (C) 2016 Intel Corporation.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtNetwork module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QHOSTADDRESS_H
#define QHOSTADDRESS_H

#include <QtNetwork/qtnetworkglobal.h>
#include <QtCore/qpair.h>
#include <QtCore/qstring.h>
#include <QtCore/qshareddata.h>
#if QT_VERSION < QT_VERSION_CHECK(7, 0, 0)
#include <QtNetwork/qabstractsocket.h>
#endif

struct sockaddr;

QT_BEGIN_NAMESPACE


class QHostAddressPrivate;

class Q_NETWORK_EXPORT QIPv6Address
{
public:
    inline quint8 &operator [](int index) { return c[index]; }
    inline quint8 operator [](int index) const { return c[index]; }
    quint8 c[16];
};

typedef QIPv6Address Q_IPV6ADDR;

class QHostAddress;
// qHash is a friend, but we can't use default arguments for friends (§8.3.6.4)
Q_NETWORK_EXPORT size_t qHash(const QHostAddress &key, size_t seed = 0) noexcept;

class Q_NETWORK_EXPORT QHostAddress
{
    Q_GADGET
public:
    enum SpecialAddress {
        Null,
        Broadcast,
        LocalHost,
        LocalHostIPv6,
        Any,
        AnyIPv6,
        AnyIPv4
    };
    enum ConversionModeFlag {
        ConvertV4MappedToIPv4 = 1,
        ConvertV4CompatToIPv4 = 2,
        ConvertUnspecifiedAddress = 4,
        ConvertLocalHost = 8,
        TolerantConversion = 0xff,

        StrictConversion = 0
    };
    Q_DECLARE_FLAGS(ConversionMode, ConversionModeFlag)

#if QT_VERSION < QT_VERSION_CHECK(7, 0, 0)
    using NetworkLayerProtocol = QAbstractSocket::NetworkLayerProtocol;
    static constexpr auto IPv4Protocol = QAbstractSocket::IPv4Protocol;
    static constexpr auto IPv6Protocol = QAbstractSocket::IPv6Protocol;
    static constexpr auto AnyIPProtocol = QAbstractSocket::AnyIPProtocol;
    static constexpr auto UnknownNetworkLayerProtocol = QAbstractSocket::UnknownNetworkLayerProtocol;
#else
    enum NetworkLayerProtocol {
        IPv4Protocol,
        IPv6Protocol,
        AnyIPProtocol,
        UnknownNetworkLayerProtocol = -1
    };
    Q_ENUM(NetworkLayerProtocol)
#endif

    QHostAddress();
    explicit QHostAddress(quint32 ip4Addr);
    explicit QHostAddress(const quint8 *ip6Addr);
    explicit QHostAddress(const Q_IPV6ADDR &ip6Addr);
    explicit QHostAddress(const sockaddr *address);
    explicit QHostAddress(const QString &address);
    QHostAddress(const QHostAddress &copy);
    QHostAddress(SpecialAddress address);
    ~QHostAddress();

    QHostAddress &operator=(QHostAddress &&other) noexcept
    { swap(other); return *this; }
    QHostAddress &operator=(const QHostAddress &other);
    QHostAddress &operator=(SpecialAddress address);

    void swap(QHostAddress &other) noexcept { d.swap(other.d); }

    void setAddress(quint32 ip4Addr);
    void setAddress(const quint8 *ip6Addr);
    void setAddress(const Q_IPV6ADDR &ip6Addr);
    void setAddress(const sockaddr *address);
    bool setAddress(const QString &address);
    void setAddress(SpecialAddress address);

    NetworkLayerProtocol protocol() const;
    quint32 toIPv4Address(bool *ok = nullptr) const;
    Q_IPV6ADDR toIPv6Address() const;

    QString toString() const;

    QString scopeId() const;
    void setScopeId(const QString &id);

    bool isEqual(const QHostAddress &address, ConversionMode mode = TolerantConversion) const;
    bool operator ==(const QHostAddress &address) const;
    bool operator ==(SpecialAddress address) const;
    inline bool operator !=(const QHostAddress &address) const
    { return !operator==(address); }
    inline bool operator !=(SpecialAddress address) const
    { return !operator==(address); }
    bool isNull() const;
    void clear();

    bool isInSubnet(const QHostAddress &subnet, int netmask) const;
    bool isInSubnet(const QPair<QHostAddress, int> &subnet) const;

    bool isLoopback() const;
    bool isGlobal() const;
    bool isLinkLocal() const;
    bool isSiteLocal() const;
    bool isUniqueLocalUnicast() const;
    bool isMulticast() const;
    bool isBroadcast() const;

    static QPair<QHostAddress, int> parseSubnet(const QString &subnet);

    friend Q_NETWORK_EXPORT size_t qHash(const QHostAddress &key, size_t seed) noexcept;

    friend bool operator ==(QHostAddress::SpecialAddress lhs, const QHostAddress &rhs)
    { return rhs == lhs; }
    friend bool operator!=(QHostAddress::SpecialAddress lhs, const QHostAddress &rhs)
    { return rhs != lhs; }

protected:
    friend class QHostAddressPrivate;
    QExplicitlySharedDataPointer<QHostAddressPrivate> d;
};
Q_DECLARE_OPERATORS_FOR_FLAGS(QHostAddress::ConversionMode)
Q_DECLARE_SHARED(QHostAddress)

#ifndef QT_NO_DEBUG_STREAM
Q_NETWORK_EXPORT QDebug operator<<(QDebug, const QHostAddress &);
#endif

#ifndef QT_NO_DATASTREAM
Q_NETWORK_EXPORT QDataStream &operator<<(QDataStream &, const QHostAddress &);
Q_NETWORK_EXPORT QDataStream &operator>>(QDataStream &, QHostAddress &);
#endif

QT_END_NAMESPACE

#endif // QHOSTADDRESS_H
