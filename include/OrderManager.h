#pragma once
#include <iostream>

class OrderManager {
private:
    double accountBalance;
    int activeOrderCount;

public:
    OrderManager(double initialBalance);
    
    bool ProcessOrder(double riskAmount);
    bool RetryOrder(unsigned int& retryCount, double riskAmount);
    void DisplayAccountStatus() const;
};