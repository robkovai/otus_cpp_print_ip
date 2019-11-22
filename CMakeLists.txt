cmake_minimum_required(VERSION 3.2)

project(otus_cpp_print_ip VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

add_executable(print_ip "main.cpp" "print_ip.h" "utils.h")

set_target_properties(print_ip PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra")

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_NAME "print_ip")
set(CPACK_PACKAGE_CONTACT "dedi4@mail.ru")
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
include(CPack)
