#include "azureiothub.h"
#include "azure_iot_creds.h"
#include "mqttexample.h"

#include <wolfmqtt/mqtt_types.h>
#include <wolfmqtt/mqtt_packet.h>

#include <stdio.h>

#define AZURE_KEEP_ALIVE_SEC    DEFAULT_KEEP_ALIVE_SEC
#define AZURE_CMD_TIMEOUT_MS    DEFAULT_CMD_TIMEOUT_MS

int main(void)
{
    int rc;
    MQTTCtx mqttCtx;
    char sasToken[400] = {0};

    memset(&mqttCtx, 0, sizeof(MQTTCtx));
    /* init defaults */
    //mqtt_init_ctx(&mqttCtx);
    mqttCtx.clean_session = 1;
    mqttCtx.app_name = "azureiothub";
    mqttCtx.host = AZURE_IOT_HUB_NAME;
    mqttCtx.port = 1883;
    mqttCtx.qos = MQTT_QOS_1;
    mqttCtx.keep_alive_sec = AZURE_KEEP_ALIVE_SEC;
    mqttCtx.client_id = AZURE_DEVICE_ID;
    mqttCtx.topic_name = AZURE_CLOUD_TO_DEV_TOPIC;
    //mqttCtx.topic_name = "$iothub/methods/POST/#";
    mqttCtx.cmd_timeout_ms = AZURE_CMD_TIMEOUT_MS;
    mqttCtx.use_tls = 1;
    mqttCtx.app_ctx = sasToken;

    struct timespec start;
    struct timespec end;

    do
    {
        clock_gettime(CLOCK_MONOTONIC, &start);
        rc = azureiothub_test(&mqttCtx);
        clock_gettime(CLOCK_MONOTONIC, &end);
        PRINTF("Connection establishing time: %ld us", (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_nsec - start.tv_nsec) / 1000);
        mqttCtx.stat = WMQ_BEGIN;
        rc = MQTT_CODE_CONTINUE;
        sleep(10);
    } while (rc == MQTT_CODE_CONTINUE);

    return (rc == 0) ? 0 : EXIT_FAILURE;
}
