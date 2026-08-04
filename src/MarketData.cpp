#include "../include/MarketData.h"

// Default Constructor (BROKEN: Uninitialized member variables!)
MarketTick::MarketTick() {
    // Leaves symbol, bidPrice, askPrice, and spread with GARBAGE memory values!
}

// Parameterized Constructor
MarketTick::MarketTick(const char* sym, double bid, double ask) {
    strncpy(symbol, sym, sizeof(symbol) - 1);
    symbol[sizeof(symbol) - 1] = '\0';
    bidPrice = bid;
    askPrice = ask;
    spread = askPrice - bidPrice;
}

void MarketTick::DisplayTick() const {
    std::cout << "[MARKET DATA] Asset: " << symbol 
              << " | Bid: " << bidPrice 
              << " | Ask: " << askPrice 
              << " | Spread: " << spread << " pts" << std::endl;
}