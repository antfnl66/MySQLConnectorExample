cmake_minimum_required(VERSION 3.28)
project(MySQLConnectorExample)

set(CMAKE_CXX_STANDARD 17)

# Update the include directory to where xdevapi.h is located
include_directories(/opt/homebrew/Cellar/mysql-connector-c++/8.3.0/include)

# Set the library directory for linking
link_directories(/opt/homebrew/Cellar/mysql-connector-c++/8.3.0/lib)

# Add the executable and specify the source files
add_executable(MySQLConnectorExample main.cpp CustomerData.cpp
        CustomerData.cpp)

# Link with the specific version of MySQL Connector/C++ library
target_link_libraries(MySQLConnectorExample mysqlcppconn8)
