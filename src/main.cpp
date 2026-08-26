#include "../include/Logger.h"
#include "../include/MarketData.h"
#include "../include/OrderManager.h"

int main() {
    std::cout << "=== TELAVIV CORE ENGINE STARTUP ===" << std::endl;

    //Module 1: Telemetry Logger check
    TradeAlert signalAlert("XAUUSD Buy Signal Triggered at 4030.16!");
    std::cout << "--> Dispatching Notification..." << std::endl;
    SendToTelegram(signalAlert); 
    std::cout << "--> Verifying Memory State..." << std::endl;
    signalAlert.Print(); // CRASHES HERE DUE TO DANGLING POINTER!

    // Module 2: Market Data Feed Check (TEL-102 Target Area)
    std::cout << "\n--> Fetching Live Market Ticks..." << std::endl;
    MarketTick emptyTick; // Instantiates via default constructor
    emptyTick.DisplayTick(); // CRITICAL BUG: Reads uninitialized garbage memory!

    // Module 3: Order Execution Check
    std::cout << "\n--> Initializing Order Manager..." << std::endl;
    OrderManager account(100.00); // $100 starting balance
    account.ProcessOrder(20.00);
    account.DisplayAccountStatus();
    

    return 0;
}