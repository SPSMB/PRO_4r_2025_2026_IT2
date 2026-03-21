cmake_minimum_required(VERSION 3.16)

project(36_Rekurze LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(36_Rekurze main.cpp)

include(GNUInstallDirs)
install(TARGETS 36_Rekurze
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
