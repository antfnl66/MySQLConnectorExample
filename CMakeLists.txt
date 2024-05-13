cmake_minimum_required(VERSION 3.28)
project(MySQLConnectorExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)

# Ensure this path points exactly where the bin, lib, and include directories for Qt6 are located
set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt6")

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(MySQLConnectorExample
        main.cpp
        CustomerData.cpp
        MainWindow.cpp
        AddCustomerWidget.cpp
        ModifyCustomerWidget.cpp
        SearchViewCustomerWidget.cpp
)

target_link_libraries(MySQLConnectorExample Qt6::Widgets)