include(gtest_dependency.pri)

QT += core gui sql widgets printsupport
TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG += thread
#CONFIG -= qt

HEADERS += \
        tst_test001.h \
    ../src/doc_image.h \
    ../src/settings.h \
    ../src/functions.h \
    tst_test001.h

SOURCES += \
        main.cpp \
    ../src/doc_image.cpp \
    ../src/settings.cpp \
    ../src/functions.cpp \
    ../../googletest-master/googletest/src/gtest.cc \
    main.cpp
