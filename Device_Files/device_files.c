#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/device.h>


#define AUTHOR "EF Driver"
#define DESCRIPTION "Dynamic Files Allocation"


dev_t device_ex = 0; 

static struct class *dev_class;

static struct device *EF_device;

static int __init init_func(void){

    if(alloc_chrdev_region(&device_ex,0,1,"EF Device") < 0){
        pr_info("ERRO MAJOR AND MINOR");
        return -1;

    }  //Registro do device e alocação dinamica do Major e Minor Number 
    
    pr_info("Major = %d\n",MAJOR(device_ex)); //Imprimindo o valor de major
    pr_info("Minor = %d\n",MINOR(device_ex)); //Imprimindo o valor de minor
    
    dev_class = class_create(THIS_MODULE,"EF_device_class"); //Criando a classe do devie

    if(IS_ERR(dev_class)){ // Validando se foi criada com sucesso
        pr_err("Cannot create the struct class for device\n");
    }

    EF_device = device_create(dev_class,NULL,device_ex,NULL,"EF_DEVICE");

    if(IS_ERR(EF_device)){
        pr_err("Cannot create the device\n");
    }

    pr_info("Module insert");
    return 0;
}

static void __exit deinit_func(void){

unregister_chrdev_region(device_ex,1); //Removendo o registor do device
device_destroy(dev_class,device_ex);
class_destroy(dev_class);
pr_info("Device Removed");


}   

module_init(init_func);
module_exit(deinit_func);


MODULE_LICENSE("GPL");
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);