#include "vector.h"
#include <stdio.h>

Vector3D::Vector3D()
{
  this->x = 0;
  this->y = 0;
  this->z = 0;
}

Vector3D::Vector3D(double x, double y, double z)
{
  this->x = x;
  this->y = y;
  this->z = z;
}

Vector3D::~Vector3D() { }

double Vector3D::getX() const { return this->x; }
double Vector3D::getY() const { return this->y; }
double Vector3D::getZ() const { return this->z; }

Vector3D Vector3D::operator+(const Vector3D & secondVector) const
{
  return Vector3D(
    this->x + secondVector.x,
    this->y + secondVector.y,
    this->z + secondVector.z
  );
}

Vector3D Vector3D::operator-(const Vector3D & secondVector) const
{
  return Vector3D(
    this->x - secondVector.x,
    this->y - secondVector.y,
    this->z - secondVector.z
  );
}

Vector3D Vector3D::operator-() const
{
  return Vector3D(
    -this->x,
    -this->y,
    -this->z
  );
}

Vector3D Vector3D::operator*(double number) const
{
  return Vector3D(
    this->x * number,
    this->y * number,
    this->z * number
  );
}

Vector3D operator*(double number, const Vector3D & vector)
{
  return vector * number;
}

std::istream & operator>>(std::istream & iStream, Vector3D & vector)
{
  std::string input;
  iStream >> input;
  sscanf(input.c_str(), "(%lf,%lf,%lf)", &vector.x, &vector.y, &vector.z);
  return iStream;
}

std::ostream & operator<<(std::ostream & oStream, const Vector3D & vector)
{
  return oStream << "(" << vector.x << "," << vector.y << "," << vector.z << ")";
}
