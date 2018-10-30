TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += D:\boost_1_68_0-msvc-14.0-64\boost_1_68_0
#LIBS += D:\boost_1_68_0-msvc-14.0-64\boost_1_68_0\lib64-msvc-14.0\libboost_thread-vc140-mt-gd-x64-1_68.lib
#LIBS += D:\boost_1_68_0-msvc-14.0-64\boost_1_68_0\lib64-msvc-14.0\boost_thread-vc140-mt-gd-x64-1_68.lib
#LIBS += D:\boost_1_68_0-msvc-14.0-64\boost_1_68_0\lib64-msvc-14.0\boost_thread-vc140-mt-x64-1_68.lib
#LIBS += D:\boost_1_68_0-msvc-14.0-64\boost_1_68_0\lib64-msvc-14.0\libboost_thread-vc140-mt-s-x64-1_68.lib
#LIBS += D:\boost_1_68_0-msvc-14.0-64\boost_1_68_0\lib64-msvc-14.0\libboost_thread-vc140-mt-sgd-x64-1_68.lib
LIBS += D:\boost_1_68_0-msvc-14.0-64\boost_1_68_0\lib64-msvc-14.0\libboost_thread-vc140-mt-x64-1_68.lib

#LIBS += -LD:/boost_1_68_0-msvc-14.0-64/boost_1_68_0/lib64-msvc-14.0/-lboost_thread-vc140-mt-gd-x64-1_68
#LIBS += -LD:/boost_1_68_0-msvc-14.0-64/boost_1_68_0/lib64-msvc-14.0/-lboost_thread-vc140-mt-x64-1_68
#LIBS += -LD:/boost_1_68_0-msvc-14.0-64/boost_1_68_0/lib64-msvc-14.0/ -llibboost_thread-vc140-mt-gd-x64-1_68
#LIBS += -LD:/boost_1_68_0-msvc-14.0-64/boost_1_68_0/lib64-msvc-14.0/ -llibboost_thread-vc140-mt-sgd-x64-1_68
#LIBS += -LD:/boost_1_68_0-msvc-14.0-64/boost_1_68_0/lib64-msvc-14.0/ -llibboost_thread-vc140-mt-s-x64-1_68
#LIBS += -LD:/boost_1_68_0-msvc-14.0-64/boost_1_68_0/lib64-msvc-14.0/ -llibboost_thread-vc140-mt-x64-1_68

SOURCES += \
    test_boost_thread1.cpp
