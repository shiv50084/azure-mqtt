cmake_minimum_required(VERSION 3.6)

project(azure_mqtt)

add_subdirectory(deps/)

set(app_src main.c)
add_executable(${PROJECT_NAME} ${app_src})
