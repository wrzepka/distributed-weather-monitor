//
// Created by Wiktor on 24.07.2026.
//

#ifndef FIRMWARE_MQTTTRANSPORT_H
#define FIRMWARE_MQTTTRANSPORT_H
#include <esp_event_base.h>

#include "ITelemetryTransport.h"


class MqttTransport : public ITelemetryTransport {
private:
    const char *m_brokerIp;
    uint16_t m_brokerPort;
    esp_mqtt_client_handle_t m_client;

    static void mqtt5_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data);

public:
    MqttTransport(const char *brokerIp, uint16_t brokerPort) : m_brokerIp(brokerIp), m_brokerPort(brokerPort), m_client(nullptr) {
    };

    esp_err_t connect() override;

    esp_err_t disconnect() override;

    esp_err_t publish() override;
};


#endif //FIRMWARE_MQTTTRANSPORT_H
