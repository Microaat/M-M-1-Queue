#-------------------------------------------------
#
# Project created by QtCreator 2018-05-10T17:01:29
#
#-------------------------------------------------

QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = M-M-1_Queue
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    helpdialog.cpp \
    Graphics/station.cpp \
    controller.cpp \
    Widgets/simulationtable.cpp \
    mm1_model.cpp \
    Widgets/resultschart.cpp \
    Simulation/a_generator.cpp \
    Simulation/a_listener.cpp \
    Simulation/clock.cpp \
    Simulation/entity.cpp \
    Simulation/generator.cpp \
    Simulation/queue.cpp \
    Simulation/source.cpp \
    Simulation/statistics.cpp \
    Simulation/t_generator.cpp \
    Simulation/time.cpp \
    Simulation/t_container.cpp \
    Simulation/a_server.cpp \
    Simulation/server.cpp \
    Simulation/listener.cpp \
    Simulation/t_listener.cpp \
    Simulation/a_simulator.cpp \
    Simulation/simulator.cpp \
    Widgets/timeunit.cpp \
    savefilemanager.cpp \
    multiqueuewindow.cpp \
    Simulation/a_queue.cpp

HEADERS  += mainwindow.h \
    helpdialog.h \
    Graphics/station.h \
    controller.h \
    Widgets/simulationtable.h \
    mm1_model.h \
    mm1queue.h \
    Widgets/resultschart.h \
    Simulation/a_generator.h \
    Simulation/a_listener.h \
    Simulation/all.h \
    Simulation/clock.h \
    Simulation/components.h \
    Simulation/entity.h \
    Simulation/generator.h \
    Simulation/queue.h \
    Simulation/source.h \
    Simulation/statistics.h \
    Simulation/t_generator.h \
    Simulation/time.h \
    Simulation/t_container.h \
    Simulation/a_server.h \
    Simulation/server.h \
    Simulation/listener.h \
    Simulation/t_listener.h \
    Simulation/a_simulator.h \
    Simulation/simulator.h \
    Widgets/timeunit.h \
    savefilemanager.h \
    multiqueuewindow.h \
    Simulation/a_queue.h

FORMS    += mainwindow.ui \
    helpdialog.ui \
    mainwindow_v1.ui \
    multiqueuewindow.ui

DISTFILES += \
    todo.txt
