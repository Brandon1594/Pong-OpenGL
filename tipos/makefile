## MAKEFILE PONG-OPENGL ##
## TIPOS ##


COMPILER = g++
EDITOR = geany
GPP_FLAGS = -lm -I$(INCLUDE_RUTE)/

.PHONY : clean edit
.SILENT :

INCLUDE_RUTE = include
SRC_RUTE = src
OBJ_RUTE = objects

OBJECTS = \
	$(OBJ_RUTE)/EspacioNormal.o \
	$(OBJ_RUTE)/PelotaNormal.o \
	$(OBJ_RUTE)/RaquetaNormal.o \
	$(OBJ_RUTE)/Vector.o \
	$(OBJ_RUTE)/PongException.o 

$(OBJ_RUTE)/%.o : $(SRC_RUTE)/%.cpp
	echo "\t* Compilando $< *"
	$(COMPILER) -o$@ $(GPP_FLAGS) -c $<
	
all: object $(OBJECTS)
	echo "\t* LISTO *"

object :
	-mkdir $(OBJ_RUTE)

clean:
	echo "* BORRANDO *"
	-rm -vf $(OBJECTS)
	echo "* LISTO *"

edit:
	$(EDITOR) $(INCLUDE_RUTE)/*.h $(SRC_RUTE)/*.cpp &
