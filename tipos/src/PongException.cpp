/* Implementación del tipo PongException */

#include <PongException.h>

/* Atributos:
 * 		char* mensExcp;
 */

PongException::PongException(const char* cadena) : exception(){
	char* mensExcp;
	
	try{
		c_cad = new char [strlen(cadena)+1];
		strcpy (mensExcp, cadena);
	}catch(std::bad_alloc){}
}

PongException::const char* what() const throw(){	
	return mensExcp;
}
