cmake_minimum_required(VERSION 3.16)

project(37_ObraceniPosloupnosti LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(37_ObraceniPosloupnosti main.cpp)

include(GNUInstallDirs)
install(TARGETS 37_ObraceniPosloupnosti
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
