#pragma once
#include <iostream>

class OrderManager {
private:
    double accountBalance;
    int activeOrderCount;

public:
    OrderManager(double initialBalance);
    
    bool ProcessOrder(double riskAmount);
    void DisplayAccountStatus() const;
};