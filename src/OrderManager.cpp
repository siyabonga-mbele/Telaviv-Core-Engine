#include "../include/OrderManager.h"

OrderManager::OrderManager(double initialBalance) 
    : accountBalance(initialBalance), activeOrderCount(0) {}

bool OrderManager::ProcessOrder(double riskAmount) {
    if (riskAmount <= accountBalance) {
        accountBalance -= riskAmount;
        activeOrderCount++;
        std::cout << "[ORDER EXECUTED] Risk: $" << riskAmount 
                  << " | Remaining Balance: $" << accountBalance << std::endl;
        return true;
    } else {
        std::cout << "[ORDER REJECTED] Insufficient Margin!" << std::endl;
        return false;
    }
}

// FIXED: Prevents unsigned int underflow when retrying failed orders
bool OrderManager::RetryOrder(unsigned int& retryCount, double riskAmount) {
    if (retryCount == 0) {
        std::cout << "[NETWORK ERROR] Max retries exhausted! Order aborted." << std::endl;
        return false;
    }

    retryCount--; // Safe to decrement now because retryCount > 0
    std::cout << "[NETWORK RETRY] Retrying order... Attempts left: " << retryCount << std::endl;
    return ProcessOrder(riskAmount);
}

void OrderManager::DisplayAccountStatus() const {
    std::cout << "[ACCOUNT] Active Orders: " << activeOrderCount 
              << " | Balance: $" << accountBalance << std::endl;
}