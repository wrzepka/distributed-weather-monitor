//
// Created by Wiktor on 24.07.2026.
//

#ifndef FIRMWARE_ITELEMETRYTRANSPORT_H
#define FIRMWARE_ITELEMETRYTRANSPORT_H
#include <esp_err.h>


class ITelemetryTransport {
public:
    virtual ~ITelemetryTransport() = default;

    virtual esp_err_t connect();

    virtual esp_err_t disconnect();

    virtual esp_err_t publish();
};

#endif //FIRMWARE_ITELEMETRYTRANSPORT_H
