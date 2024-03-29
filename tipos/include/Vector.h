/* Tipo Vector */

#ifndef _VECTOR
#define _VECTOR

typedef struct {
	double x;
	double y;
}Vector; 

const Vector operator+(const Vector v1, const Vector v2);
const Vector operator-(const Vector v1, const Vector v2);
const Vector operator*(const int esc, const Vector v);
const Vector operator*(const Vector v, const int esc);
const Vector operator/(const Vector v, const int esc);
const double operator*(const Vector v1, const Vector v2);
const Vector operator+=(Vector& v1, const Vector v2);
const Vector operator-=(Vector& v1, const Vector v2);
const Vector operator*=(Vector& v1, const int esc);
const Vector operator/=(Vector& v1, const int esc);

const double mod(const Vector v);

#endif
