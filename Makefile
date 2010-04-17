## MAKEFILE PONG-OPENGL ##
## MAIN ##

SHELL = /bin/bash

COMPILER = g++
EDITOR = geany
GPP_FLAGS = $(INCLUDES) -lm -lglut -ggdb

.PHONY : clean edit
.SILENT :

SUBMAKES_DIRS = tipos dibujado
INCLUDES = -Itipos/include  -Idibujado/include
OBJECTS = tipos/objects/*.o dibujado/objects/*.o
	
all :
	for dir in $(SUBMAKES_DIRS);\
	do\
		echo "** EJECUTANDO MAKE EN $$dir/ **";\
		make -C $$dir;\
		echo "** LISTO **";\
	done
	
	echo -e "\n** COMPILANDO EJECUTABLE \"Pong\"**"
	$(COMPILER) $(GPP_FLAGS) -oPong main.cpp $(OBJECTS)
	echo "** LISTO **";\

clean:
	for dir in $(SUBMAKES_DIRS); do\
		echo "** EJECUTANDO MAKE CLEAN EN $$dir/ **";\
		make -C $$dir clean;\
		echo "** LISTO **";\
	done\

edit:
	for dir in $(SUBMAKES_DIRS); do\
		echo "** EJECUTANDO MAKE EDIT EN $$dir/ **";\
		make -C $$dir edit;\
		echo "** LISTO **";\
	done
