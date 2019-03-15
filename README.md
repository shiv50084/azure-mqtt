# Azure IoT Hub MQTT with WolfSSL + WolfMQTT

To use the example you should create the `azure_iot_creds.h` file in
the project root with the following content:

```c
#ifndef AZURE_MQTT_AZURE_IOT_CREDS_H
#define AZURE_MQTT_AZURE_IOT_CREDS_H

#define AZURE_IOT_HUB_NAME "<Your IoT Hub name>"
#define AZURE_DEVICE_ID "<Your Device ID>"
#define AZURE_MQTT_USERNAME AZURE_IOT_HUB_NAME"/"AZURE_DEVICE_ID"/?api-version=2018-06-30"
#define AZURE_CONNECTION_STRING "<Connection String>"
#define AZURE_SHARED_KEY "<Shared Key>" // may be extracted from the connection string

#define AZURE_DEV_TO_CLOUD_TOPIC "devices/"AZURE_DEVICE_ID"/messages/events/"
#define AZURE_CLOUD_TO_DEV_TOPIC "devices/"AZURE_DEVICE_ID"/messages/devicebound/#"

#endif //AZURE_MQTT_AZURE_IOT_CREDS_H
```