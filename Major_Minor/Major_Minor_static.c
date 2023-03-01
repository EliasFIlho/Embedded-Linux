#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>



#define AUTHOR "EF Driver"
#define DESCRIPTION "Dynamic Files Allocation"


dev_t device_ex = MKDEV(291,0); //Alocação estatica da struct de major e minor number



static int __init init_func(){

    register_chardev_region(device_ex,1,"EF Device"); //Registro do device 
    pr_info("Module insert");
    pr_info("Major = %d\n",MAJOR(device_ex)); //Imprimindo o valor de major
    pr_info("Minor = %d\n",MINOR(device_ex)); //Imprimindo o valor de minor
    


    return 0;
}

static void __exit deinit_func(){

unregister_chardev_region(device_ex,1); //Removendo o registor do device
pr_info("Device Removed");


}


module_init(init_func);
module_exit(deinit_func);


MODULE_LICENSE("GPL");
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);