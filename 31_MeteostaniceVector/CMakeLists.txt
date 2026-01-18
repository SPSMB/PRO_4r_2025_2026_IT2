cmake_minimum_required(VERSION 3.16)

project(31_MeteostaniceVector LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(31_MeteostaniceVector main.cpp
    meteostanice.h meteostanice.cpp)

include(GNUInstallDirs)
install(TARGETS 31_MeteostaniceVector
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
