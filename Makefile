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
		if [ $$? -eq 0 ]; then\
			OBJECTS=$$OBJECTS $$dir/objects/*.o;\
		fi;\
	done\
		
	#$(COMPILER) $(INCLUDES_RUTES) -oPong $$OBJECTS

clean:
	for dir in $(SUBMAKES_DIRS)
		make -C $$dir/makefile clean

edit:
	for dir in $(SUBMAKES_DIRS)
		make -C $$dir/makefile edit
