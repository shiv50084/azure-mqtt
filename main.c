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
    char sasToken[] = AZURE_MQTT_PASSWORD;

    /* init defaults */
    mqtt_init_ctx(&mqttCtx);
    mqttCtx.app_name = "azureiothub";
    mqttCtx.host = AZURE_IOT_HUB_NAME;
    mqttCtx.qos = MQTT_QOS_1;
    mqttCtx.keep_alive_sec = AZURE_KEEP_ALIVE_SEC;
    mqttCtx.client_id = AZURE_DEVICE_ID;
    mqttCtx.topic_name = AZURE_CLOUD_TO_DEV_TOPIC;
    mqttCtx.cmd_timeout_ms = AZURE_CMD_TIMEOUT_MS;
    mqttCtx.use_tls = 1;
    mqttCtx.app_ctx = sasToken;

    do
    {
        rc = azureiothub_test(&mqttCtx);
    } while (rc == MQTT_CODE_CONTINUE);

    return (rc == 0) ? 0 : EXIT_FAILURE;
}
