/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtQml module of the Qt Toolkit.
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

#ifndef QQMLCOMPONENTATTACHED_P_H
#define QQMLCOMPONENTATTACHED_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtQml/qqml.h>
#include <private/qtqmlglobal_p.h>
#include <QtCore/QObject>

QT_BEGIN_NAMESPACE


class Q_QML_PRIVATE_EXPORT QQmlComponentAttached : public QObject
{
    Q_OBJECT

    // Used as attached object for QQmlComponent. We want qqmlcomponentattached_p.h to be #include'd
    // when registering QQmlComponent, but we cannot #include it from qqmlcomponent.h. Therefore we
    // force an anonymous type registration here.
    QML_ANONYMOUS
    QML_ADDED_IN_VERSION(2, 0)
public:
    QQmlComponentAttached(QObject *parent = nullptr);
    ~QQmlComponentAttached();

    void insertIntoList(QQmlComponentAttached **listHead)
    {
        m_prev = listHead;
        m_next = *listHead;
        *listHead = this;
        if (m_next)
            m_next->m_prev = &m_next;
    }

    void removeFromList()
    {
        *m_prev = m_next;
        if (m_next)
            m_next->m_prev = m_prev;
        m_next = nullptr;
        m_prev = nullptr;
    }

    QQmlComponentAttached *next() const { return m_next; }

Q_SIGNALS:
    void completed();
    void destruction();

private:
    QQmlComponentAttached **m_prev;
    QQmlComponentAttached *m_next;
};

QT_END_NAMESPACE

#endif // QQMLCOMPONENTATTACHED_P_H
