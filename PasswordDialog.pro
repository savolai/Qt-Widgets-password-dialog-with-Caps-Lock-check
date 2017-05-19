#-------------------------------------------------
#
# Project created by QtCreator 2017-05-19T16:39:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PasswordDialog
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

#caps lock detection in PasswordDialog requires this
#
#https://social.msdn.microsoft.com/Forums/vstudio/en-US/e4abbf36-20d6-47ca-89ec-931423138091/calling-getkeystate-results-in-unresolved-external-symbol-in-makefile-projects?forum=vcgeneral
#While it is possible to change directly in the makefile(s),
# a more handy way in this case is to change in the .pro file
# (Qt project file), and add "LIBS += User32.Lib" (without
#quotation signs), when the .pro file is changed, qmake will
# have to be executed again, and the Makefiles will be overwritten.
#Changing in the .pro file this will generate updated Makefiles
#the next time qmake is run in that folder.
win32{
    LIBS += User32.Lib
}

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        passworddialog.cpp

HEADERS  += passworddialog.h

FORMS    += passworddialog.ui
