#pragma once
#include <iostream>
#include <cstring>

class TradeAlert {
public:
    char* alertMessage;

    TradeAlert(const char* msg);
    ~TradeAlert();

    void Print() const;
};

// Function signature causing pass-by-value shallow copy
void SendToTelegram(TradeAlert alertCopy);