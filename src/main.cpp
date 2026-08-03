#include "../include/Logger.h"

int main() {
    std::cout << "=== TELAVIV CORE ENGINE STARTUP ===" << std::endl;

    TradeAlert signalAlert("XAUUSD Buy Signal Triggered at 4030.16!");

    std::cout << "--> Dispatching Notification..." << std::endl;
    SendToTelegram(signalAlert); 

    std::cout << "--> Verifying Memory State..." << std::endl;
    signalAlert.Print(); // CRASHES HERE DUE TO DANGLING POINTER!

    return 0;
}