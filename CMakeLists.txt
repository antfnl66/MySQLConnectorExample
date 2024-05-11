cmake_minimum_required(VERSION 3.28)
project(MySQLConnectorExample)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find packages
find_package(Qt6 COMPONENTS Widgets REQUIRED)  # Make sure QtWidgets is included

# Include MySQL Connector/C++ headers
include_directories(/opt/homebrew/Cellar/mysql-connector-c++/8.3.0/include)

# Link directories for MySQL Connector/C++
link_directories(/opt/homebrew/Cellar/mysql-connector-c++/8.3.0/lib)

# Add sources
add_executable(MySQLConnectorExample
    main.cpp
    CustomerData.cpp
    mainwindow.cpp
)

# UI files, headers
target_sources(MySQLConnectorExample PRIVATE mainwindow.ui)

# Link libraries
target_link_libraries(MySQLConnectorExample Qt6::Widgets mysqlcppconn8)
