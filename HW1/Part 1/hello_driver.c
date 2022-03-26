#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Atahan Caldir");
MODULE_DESCRIPTION("CS350 HW1 Part 1");
MODULE_VERSION("1.0");

static int __init hello_driver_init(void) {
  printk(KERN_ALERT "Hello world!");
  return 0;
}

static void __exit hello_driver_exit(void) {
  printk(KERN_ALERT "Goodbye world!");
}

module_init(hello_driver_init);
module_exit(hello_driver_exit);
