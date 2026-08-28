#pragma once
#include <iostream>
#include <cstring>

class TradeAlert {
public:
    char* alertMessage;

    //Constructor
    TradeAlert(const char* msg);

    //Destructor
    ~TradeAlert();

    //Copy Constructor (deep copy)
    TradeAlert(const TradeAlert& other);

    //Copy Assignment Operator (Deep copy)
    TradeAlert& operator=(const TradeAlert& other);

    void Print() const;
};

// Function signature causing pass-by-value shallow copy
void SendToTelegram(TradeAlert alertCopy);