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

void OrderManager::DisplayAccountStatus() const {
    std::cout << "[ACCOUNT] Active Orders: " << activeOrderCount 
              << " | Balance: $" << accountBalance << std::endl;
}