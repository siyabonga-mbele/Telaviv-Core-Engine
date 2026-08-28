#include "../include/Logger.h"

// Standard Constructor: Dynamically allocates memory for the message string
TradeAlert::TradeAlert(const char* msg) {
    alertMessage = new char[strlen(msg) + 1];
    strcpy(alertMessage, msg);
}

// Destructor: Prevents memory leaks by releasing heap allocation
TradeAlert::~TradeAlert() {
    delete[] alertMessage;
}

// Deep Copy Constructor: Prevents shallow copy pointer duplication
TradeAlert::TradeAlert(const TradeAlert& other) {
    alertMessage = new char[strlen(other.alertMessage) + 1];
    strcpy(alertMessage, other.alertMessage);
}

// Deep Copy Assignment Operator: Safely handles object re-assignment
TradeAlert& TradeAlert::operator=(const TradeAlert& other) {
    if (this != &other) { // Guard against self-assignment (e.g., alert = alert)
        delete[] alertMessage; // Free existing dynamic memory first
        alertMessage = new char[strlen(other.alertMessage) + 1];
        strcpy(alertMessage, other.alertMessage);
    }
    return *this;
}

// Display function: Prints telemetry data without duplicating lines
void TradeAlert::Print() const {
    if (alertMessage) {
        std::cout << "[TELEMETRY ALERT]: " << alertMessage << std::endl;
    }
}

// Pass-by-const-reference: Avoids unnecessary copying overhead
void SendToTelegram(const TradeAlert& alertCopy) {
    alertCopy.Print();
}