all : common master node

common :
	make -C $@

master : common
	make -C $@

node : common
	make -C $@

clean :
	make clean -C common
	make clean -C master
	make clean -C node

.PHONY : all common master node clean
