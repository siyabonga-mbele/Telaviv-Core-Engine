#pragma once
#include <iostream>
#include <cstring>

class MarketTick {
public:
    char symbol[10];
    double bidPrice;
    double askPrice;
    double spread; // Calculated difference between Ask and Bid

    // Default Constructor
    MarketTick();
    
    // Parameterized Constructor
    MarketTick(const char* sym, double bid, double ask);

    void DisplayTick() const;
};