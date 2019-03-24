cmake_minimum_required(VERSION 3.6)

project(azure_mqtt)

add_subdirectory(deps/)

set(app_src main.c)
set(mqtt_src mqttexample.c mqttnet.c azureiothub.c certs.c)

get_target_property(MQTT_INC wolfmqtt INCLUDE_DIRECTORIES)
add_executable(${PROJECT_NAME} ${app_src} ${mqtt_src})
target_compile_definitions(${PROJECT_NAME} PRIVATE WOLFMQTT_USER_SETTINGS
    WOLFSSL_USER_SETTINGS WOLFMQTT_NONBLOCK ENABLE_MQTT_TLS)
target_include_directories(${PROJECT_NAME} PUBLIC ${MQTT_INC})
target_link_libraries(${PROJECT_NAME} wolfmqtt wolfssl m)
