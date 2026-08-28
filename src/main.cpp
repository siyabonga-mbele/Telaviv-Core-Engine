#include <iostream>
#include "../include/Logger.h"
#include "../include/MarketData.h"
#include "../include/OrderManager.h"

int main() {
    std::cout << "==================================================" << std::endl;
    std::cout << "      TELAVIV CORE ENGINE - INITIALIZING...       " << std::endl;
    std::cout << "==================================================\n" << std::endl;

    // 1. Telemetry Logger Test (TEL-101 / TEL-104)
    std::cout << "--- [MODULE 1: TELEMETRY SYSTEM] ---" << std::endl;
    TradeAlert startupAlert("System online. Network socket initialized.");
    SendToTelegram(startupAlert);
    std::cout << std::endl;

    // 2. Market Data Processing (TEL-102)
    std::cout << "--- [MODULE 2: MARKET DATA FEED] ---" << std::endl;
    MarketTick defaultTick; // Verifies clean constructor initialization
    std::cout << "Default Tick Check:" << std::endl;
    defaultTick.DisplayTick();

    MarketTick goldTick("XAUUSD", 2500.50, 2500.80);
    std::cout << "Live Tick Check:" << std::endl;
    goldTick.DisplayTick();
    std::cout << std::endl;

    // 3. Order Manager & Retry System (TEL-103)
    std::cout << "--- [MODULE 3: ORDER MANAGER & RISK EXECUTOR] ---" << std::endl;
    OrderManager account(10000.00); // Initial account balance
    account.DisplayAccountStatus();

    // Execute standard trade
    std::cout << "\nExecuting primary order..." << std::endl;
    account.ProcessOrder(250.00);
    account.DisplayAccountStatus();

    // Simulate network retry handling down to zero attempts
    std::cout << "\nSimulating network failure retry sequence..." << std::endl;
    unsigned int retriesLeft = 2;
    account.RetryOrder(retriesLeft, 250.00); // Attempt 1 -> 1 left
    account.RetryOrder(retriesLeft, 250.00); // Attempt 2 -> 0 left
    account.RetryOrder(retriesLeft, 250.00); // Attempt 3 -> Underflow check triggers!

    std::cout << "\n==================================================" << std::endl;
    std::cout << "      ENGINE SHUTDOWN - ALL SYSTEMS NOMINAL       " << std::endl;
    std::cout << "==================================================" << std::endl;

    return 0;
}