#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/device.h>
#include <linux/cdev.h>


#define AUTHOR "EF Drivers"
#define DESCRIPTION "Files Operation"


dev_t device_ex = 0; 
static struct class *dev_class;
static struct cdev EF_cdev;

//Prototipos

static int      EF_open(struct inode *inode, struct file *file);
static int      EF_release(struct inode *inode, struct file *file);
static ssize_t  EF_read(struct file *filp, char __user *buf, size_t len,loff_t * off);
static ssize_t  EF_write(struct file *filp, const char *buf, size_t len, loff_t * off);
static int __init init_func(void);
static void __exit deinit_func(void);


static struct file_operations fops =
{
    .owner      = THIS_MODULE,
    .read       = EF_read,
    .write      = EF_write,
    .open       = EF_open,
    .release    = EF_release,
};



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



    if(IS_ERR(device_create(dev_class,NULL,device_ex,NULL,"EF_DEVICE"))){
        pr_err("Cannot create the device\n");
    }

    cdev_init(&EF_cdev,&fops);

    if(cdev_add(&EF_cdev,device_ex,1) < 0 ){
        pr_err("Cannot add the cdev struct");
    }


    pr_info("Module insert");
    return 0;
}

static void __exit deinit_func(void){

unregister_chrdev_region(device_ex,1); //Removendo o registor do device
device_destroy(dev_class,device_ex);
class_destroy(dev_class);
cdev_del(&EF_cdev);
pr_info("Device Removed");
}   




static int      EF_open(struct inode *inode, struct file *file){

    pr_info("File Open Function");
    return 0;

}

static int      EF_release(struct inode *inode, struct file *file){
    pr_info("File Release Function");
    return 0;


}


static ssize_t  EF_read(struct file *filp, char __user *buf, size_t len,loff_t * off){

    pr_info("File Read Function");
    return 0;


}
static ssize_t  EF_write(struct file *filp, const char *buf, size_t len, loff_t * off){
    pr_info("File Write Function");
    return 0;
}


module_init(init_func);
module_exit(deinit_func);


MODULE_LICENSE("GPL");
MODULE_AUTHOR(AUTHOR);
MODULE_DESCRIPTION(DESCRIPTION);