cmake_minimum_required(VERSION 3.28)
project(MySQLConnectorExample)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Assuming Qt6 is installed in a standard Homebrew location
list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt6")

# Find packages
find_package(Qt6 COMPONENTS Widgets Sql REQUIRED)

add_executable(MySQLConnectorExample
        main.cpp
        CustomerData.cpp
        MainWindow.cpp
        AddCustomerWidget.cpp
        ModifyCustomerWidget.cpp
        SearchViewCustomerWidget.cpp
)

target_link_libraries(MySQLConnectorExample Qt6::Widgets Qt6::Sql)
