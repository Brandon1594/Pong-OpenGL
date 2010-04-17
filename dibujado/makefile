## MAKEFILE PONG-OPENGL ##
## DIBUJADO ##


COMPILER = g++
EDITOR = geany
GPP_FLAGS = -lm -I$(INCLUDE_RUTE)/ -I../tipos/include/

.PHONY : clean edit
.SILENT :

INCLUDE_RUTE = include
SRC_RUTE = src
OBJ_RUTE = objects
OBJ_RUTE_DBG = $(OBJ_RUTE)

OBJECTS = $(OBJ_RUTE)/Dibujado.o

$(OBJ_RUTE)/%.o : $(SRC_RUTE)/%.cpp
	echo "\t* Compilando $< *"
	$(COMPILER) -ggdb -o$@ $(GPP_FLAGS) -c $<
	
all: object $(OBJECTS)
	echo "\t* LISTO *"

object :
	-mkdir $(OBJ_RUTE) 2> /dev/null

clean:
	echo "* BORRANDO *"
	-rm -vf $(OBJECTS)
	echo "* LISTO *"

edit:
	$(EDITOR) $(INCLUDE_RUTE)/*.h $(SRC_RUTE)/*.cpp &
