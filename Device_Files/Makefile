KDIR ?= /lib/modules/`uname -r`/build
obj-m += device_files.o

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean
