INSTALL_DIR=modules
ifneq (${KERNELRELEASE},)
	obj-m := mycdd.o

mycdd-objs := initFunc.o exitFunc.o openSerialDevice.o releaseSerialDevice.o writeSerialDevice.o readSerialDevice.o creatScull.o

else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	# KERNELDIR ?= /lib/modules/5.15.0-82-generic/build
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	@rm -rf ${INSTALL_DIR}
	@mkdir ${INSTALL_DIR}
	@mv -f *.o *.ko *.mod.c .*.cmd ${INSTALL_DIR}
clean:
	rm -rf ${INSTALL_DIR}
	rm -f *.o
	
endif