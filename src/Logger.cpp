#include "../include/Logger.h"

TradeAlert::TradeAlert(const char* msg) {
    alertMessage = new char[strlen(msg) + 1];
    strcpy(alertMessage, msg);
}

TradeAlert::~TradeAlert() {
    delete[] alertMessage;
}

// Deep Copy Constructor
TradeAlert::TradeAlert(const TradeAlert& other) {
    alertMessage = new char[strlen(other.alertMessage) + 1];
    strcpy(alertMessage, other.alertMessage);
}

// Deep Copy Assignment Operator
TradeAlert& TradeAlert::operator=(const TradeAlert& other) {
    if (this != &other) { // Guard against self-assignment
        delete[] alertMessage; // Free existing memory
        alertMessage = new char[strlen(other.alertMessage) + 1];
        strcpy(alertMessage, other.alertMessage);
    }
    return *this;
}

void TradeAlert::Print() const {
    std::cout << "[TELEMETRY ALERT]: " << alertMessage << std::endl;
}

void SendToTelegram(const TradeAlert& alertCopy) { //added pass-by-reference
    alertCopy.Print();
}