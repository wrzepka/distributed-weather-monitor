//
// Created by Wiktor on 24.07.2026.
//

#ifndef FIRMWARE_MQTTTRANSPORT_H
#define FIRMWARE_MQTTTRANSPORT_H
#include "ITelemetryTransport.h"


class MqttTransport : public ITelemetryTransport {
private:
    const char *m_brokerIp;
    uint16_t m_brokerPort;

public:
    MqttTransport(const char *brokerIp, uint16_t brokerPort) : m_brokerIp(brokerIp), m_brokerPort(brokerPort) {
    };

    esp_err_t connect() override;

    esp_err_t disconnect() override;

    esp_err_t publish() override;
};


#endif //FIRMWARE_MQTTTRANSPORT_H
