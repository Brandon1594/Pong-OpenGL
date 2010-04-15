/* Tipo PongException */
//Tipo para lanzar las excepciones de posng-opengl

#ifndef _PONG_EXCEPTION
#define _PONG_EXCEPTION

#include <iostream>
#include <cstring>

class PongException : public std::exception {
	private:
		char* mensExcp;
			
	public:
		PongException(const char* cadena);	
		const char* what() const throw();
}

#endif
