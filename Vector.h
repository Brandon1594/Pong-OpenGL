/* Tipo Vector */

#ifndef _VECTOR
#define _VECTOR

typedef struct {
	int x;
	int y;
}Vector; 

const Vector operator+(const Vector v1, const Vector v2);
const Vector operator-(const Vector v1, const Vector v2);
const Vector operator+=(Vector& v1, const Vector v2);
const Vector operator-=(Vector& v1, const Vector v2);

#endif
