#include "../include/Logger.h"

TradeAlert::TradeAlert(const char* msg) {
    alertMessage = new char[strlen(msg) + 1];
    strcpy(alertMessage, msg);
}

TradeAlert::~TradeAlert() {
    delete[] alertMessage;
}

TradeAlert::Print() const {
    std::cout << "[TELEMETRY ALERT]: " << alertMessage << std::endl;
}

void SendToTelegram(const TradeAlert& alertCopy) { //added pass-by-reference
    alertCopy.Print();
}