//
// Created by Wiktor on 17.07.2026.
//

#ifndef FIRMWARE_WIFIMANAGER_H
#define FIRMWARE_WIFIMANAGER_H
#include "esp_wifi.h"

class WiFiManager {
    private:
    esp_netif_t *_sta_netif;
    esp_event_handler_instance_t _instance_any_id;
    esp_event_handler_instance_t _instance_got_ip;
    EventGroupHandle_t _s_network_event_group;

    public:
    WiFiManager(): _sta_netif(nullptr), _instance_any_id(nullptr), _instance_got_ip(nullptr), _s_network_event_group(nullptr) {};
    static void wifi_event_handler(void* arg, esp_event_base_t event_base,
                                int32_t event_id, void* event_data);
    void init_wifi_station();
};


#endif //FIRMWARE_WIFIMANAGER_H