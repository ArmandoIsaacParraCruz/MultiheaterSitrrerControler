#pragma once
#include <Arduino.h>
#include <WiFi.h>
#include <esp_now.h>
#include "StructureMessages.h"

enum MessageStatus{received, notReceived};

class RemoteCommunication_2
{
    public:
    RemoteCommunication_2() = default;
        static void beginRemoteCommunication();
        static void sendMeasurements(measurements& message);
        static void sendManualAdjustmentParameters(manualAdjustmentParameters& message);
        static struct ProcessesSpecificationsMessage processesSpecificationsMessage;
        static MessageStatus getProcessesSpecificationsMessageStatus();
        static void setProcessesSpecificationsMessageStatus(MessageStatus status);
    private:
        static MessageStatus processesSpecificationsMessageStatus;
        static uint8_t mac_multiHeaterStirrer[6];
        static uint8_t mac_HMI[6];
        static esp_now_peer_info_t peerInfo;
        static void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);
        static void IRAM_ATTR OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);     
};