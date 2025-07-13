cmake_minimum_required(VERSION 3.14)

project(qtgarden VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Quick REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS QuickControls2)

add_executable(${PROJECT_NAME}
    main.cpp
    CalculatorModel.cpp
    CalculatorModel.h
    qml.qrc
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt5::Quick Qt5::QuickControls2
)
