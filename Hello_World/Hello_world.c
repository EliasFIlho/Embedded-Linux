#include <linux/module.h>
#include <linux/kernel.h>


static int __init init(void){

    printk(KERN_DEBUG "Hello World");
    return 0;


}

static void __exit deinit(void)
{
    printk(KERN_DEBUG "Goodbye World\n");
}

module_init(init);
module_exit(deinit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("EF Driver");
MODULE_DESCRIPTION("Simple Hello World Driver");