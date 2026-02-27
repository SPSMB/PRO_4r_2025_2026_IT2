cmake_minimum_required(VERSION 3.16)

project(34_Morseovka LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(34_Morseovka main.cpp)

include(GNUInstallDirs)
install(TARGETS 34_Morseovka
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
