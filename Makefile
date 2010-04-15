## MAKEFILE PONG-OPENGL ##
## MAIN ##

SHELL = /bin/bash

COMPILER = g++
EDITOR = geany
GPP_FLAGS = $(INCLUDES)

.PHONY : clean edit
.SILENT :

SUBMAKES_DIRS = tipos
INCLUDES_RUTES = -Itipos/include
	
all :
	OBJECTS = "";\
	for dir in $(SUBMAKES_DIRS);\
	do\
		echo "** EJECUTANDO MAKE EN $$dir/ **";\
		make -C $$dir;\
		echo "** LISTO **";\
		if [ $$? -eq 0 ]; then \
			OBJECTS="$$OBJECTS $$dir/objects/*.o";\
		fi;\
		echo "** ENCONTRADOS LOS SIGUIENTES OBJETOS: $$OBJECTS **";\
	done
		
	#$(COMPILER) $(INCLUDES_RUTES) -oPong $$OBJECTS

clean:
	for dir in $(SUBMAKES_DIRS); do\
		echo "** EJECUTANDO MAKE CLEAN EN $$dir/ **";\
		make -C $$dir clean;\
		echo "** LISTO **";\
	done\

edit:
	for dir in $(SUBMAKES_DIRS); do\
		echo "** EJECUTANDO MAKE CLEAN EN $$dir/ **";\
		make -C $$dir edit;\
		echo "** LISTO **";\
	done
