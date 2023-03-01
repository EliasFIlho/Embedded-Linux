KDIR ?= /lib/modules/`uname -r`/build
obj-m += file_operation.o

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean
