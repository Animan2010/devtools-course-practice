// Copyright 2016 Rumyantsev Alexander

#include "include/vector3d.h"

#include <math.h>
#include <string>
#include <limits>

const double eps = std::numeric_limits<double>::epsilon();

Vector3D::Vector3D() : x_(0.0), y_(0.0), z_(0.0) {}

Vector3D::Vector3D(const double x, const double y, const double z)
    : x_(x), y_(y), z_(z) {}

Vector3D::Vector3D(const Vector3D& v) : x_(v.x_), y_(v.y_), z_(v.z_) {}

Vector3D& Vector3D::operator=(const Vector3D& v) {
  if (this != &v) {
    x_ = v.x_;
    y_ = v.y_;
    z_ = v.z_;
  }

  return *this;
}

double Vector3D::getX() const {
  return x_;
}

double Vector3D::getY() const {
  return y_;
}

double Vector3D::getZ() const {
  return z_;
}

void Vector3D::setX(const double x) {
  x_ = x;
}

void Vector3D::setY(const double y) {
  y_ = y;
}

void Vector3D::setZ(const double z) {
  z_ = z;
}

bool Vector3D::isNullVector() const {
  return x_ < eps && x_ > -eps &&
         y_ < eps && y_ > -eps &&
         z_ < eps && z_ > -eps;
}

Vector3D Vector3D::operator+(const Vector3D& v) const {
  return Vector3D(x_ + v.x_, y_ + v.y_, z_ + v.z_);
}

Vector3D Vector3D::operator-(const Vector3D& v) const {
  return Vector3D(x_ - v.x_, y_ - v.y_, z_ - v.z_);
}

Vector3D Vector3D::operator-() const {
  return Vector3D(-x_, -y_, -z_);
}

Vector3D Vector3D::operator*(const double k) const {
  return Vector3D(k * x_, k * y_, k * z_);
}

Vector3D operator*(const double k, const Vector3D& v) {
  return Vector3D(k * v.x_, k * v.y_, k * v.z_);
}

Vector3D Vector3D::operator/(const double k) const {
  if (k < eps && k > -eps) {
    throw std::string("Can't devide by zero");
  } else {
    return Vector3D(x_ / k, y_ / k, z_ / k);
  }
}

bool Vector3D::operator==(const Vector3D& v) const {
  return (*this - v).isNullVector();
}

bool Vector3D::operator!=(const Vector3D& v) const {
  return !(*this == v);
}
