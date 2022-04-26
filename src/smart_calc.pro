QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    _my_stack.c \
    credit.c \
    grapfdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    plot/qcustomplot.cpp \
    rpn.c

HEADERS += \
    _my_stack.h \
    credit.h \
    grapfdialog.h \
    mainwindow.h \
    plot/qcustomplot.h \
    rpn.h

FORMS += \
    grapfdialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
