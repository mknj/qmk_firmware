all:
	ln -s -f ../../markus qmk_firmware/keyboards/
	make -C qmk_firmware markus:default
	sleep 3
	mount  /media/
	cp qmk_firmware/markus_default.uf2 /media/
	umount /media/	
old:
	ln -s -f ../../markus qmk/keyboards/
	make -C qmk markus:default
	sleep 3
	mount  /media/
	cp qmk /markus_default.uf2 /media/
	umount /media/
