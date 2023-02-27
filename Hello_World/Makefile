ARCH=arm
COMPILER=arm-linux-gnueabi
KDIR ?= /lib/modules/`uname -r`/build
obj-m += Hello_world.o

all:
	make -C $(KDIR) M=$(PWD) arch=$(ARCH) CROSS_COMPILE=$(COMPILER) modules

clean:
	make -C $(KDIR) M=$(PWD) arch=$(ARCH) clean
