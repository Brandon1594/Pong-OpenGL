/* Implementación de los operadores de Vector */

#include<Vector.h>

const Vector operator+(const Vector v1, const Vector v2){
	Vector suma = {v1.x + v2.x, v1.y + v2.y};
	return suma;
}

const Vector operator-(const Vector v1, const Vector v2){
	Vector resta = {v1.x - v2.x, v1.y - v2.y};
	return resta;
}

const Vector operator+=(Vector& v1, const Vector v2){
	return (v1 = v1 + v2);
}
const Vector operator-=(Vector& v1, const Vector v2){
	return (v1 = v1 - v2);
}
