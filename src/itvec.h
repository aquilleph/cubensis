#ifndef __it_VEC_h__
#define __it_VEC_h__

#include "Arduino.h"
#include "math.h"

#define RAD2DEG 57.29577

typedef double it_float;

template <typename T>
struct ITVec3
{
    T arr[3];
    T& x = arr[0];
    T& y = arr[1];
    T& z = arr[2];

    ITVec3(T x=0, T y=0, T z=0)
            : arr{x, y, z}
    {};

    ITVec3(T* arr)
            : arr{arr[0], arr[1], arr[2]}
    {};

    void set(T x, T y, T z) {
        this->x = x;
        this->y = y;
        this->z = z;
    };

    // Math functions
    it_float magnitude() {
        return sqrt(x*x + y*y + z*z);
    };

    ITVec3<it_float> normalized() {
        return ITVec3<it_float>(x, y, z).normalize();
    };

    ITVec3<T>& normalize() {
        it_float magnitude = this->magnitude();
        x /= magnitude;
        y /= magnitude;
        z /= magnitude;
        return *this;
    };

    T dot(const ITVec3<T>& rhs) {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    };

    ITVec3<T> cross(const ITVec3<T>& rhs) {
        return ITVec3<T>(
                (y * rhs.z) - (z * rhs.y),
                (z * rhs.x) - (x * rhs.z),
                (x * rhs.y) - (y * rhs.x)
        );
    };

    // Operator overloading
    ITVec3<T> operator+(const ITVec3<T>& rhs)
    {
        return ITVec3<T>(x + rhs.x, y + rhs.y, z + rhs.z);
    };

    ITVec3<T> operator+(const T rhs)
    {
        return ITVec3<T>(x + rhs, y + rhs, z + rhs);
    };

    ITVec3<T> operator-(const ITVec3<T>& rhs)
    {
        return ITVec3<T>(x - rhs.x, y - rhs.y, z - rhs.z);
    };

    ITVec3<T> operator-(const T rhs)
    {
        return ITVec3<T>(x - rhs, y - rhs, z - rhs);
    };

    ITVec3<T> operator/(const ITVec3<T>& rhs)
    {
        return ITVec3<T>(x / rhs.x, y / rhs.y, z / rhs.z);
    };

    ITVec3<it_float> operator/(const T rhs)
    {
        return ITVec3<it_float>(x / (it_float) rhs, y / (it_float) rhs, z / (it_float) rhs);
    };

    ITVec3<T> operator*(const ITVec3<T>& rhs)
    {
        return ITVec3<T>(x * rhs.x, y * rhs.y, z * rhs.z);
    };

    ITVec3<T> operator*(const T rhs)
    {
        return ITVec3<T>(x * rhs, y * rhs, z * rhs);
    };


    ITVec3<T> &operator+=(const ITVec3<T>& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    };

    ITVec3<T> &operator+=(const T rhs)
    {
        x += rhs;
        y += rhs;
        z += rhs;
        return *this;
    };

    ITVec3<T> &operator-=(const ITVec3<T>& rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    };

    ITVec3<T> &operator-=(const T rhs)
    {
        x -= rhs;
        y -= rhs;
        z -= rhs;
        return *this;
    };

    ITVec3<T> &operator/=(const ITVec3<T>& rhs)
    {
        x /= rhs.x;
        y /= rhs.y;
        z /= rhs.z;
        return *this;
    };

    ITVec3<T> &operator/=(const T rhs)
    {
        x /= rhs;
        y /= rhs;
        z /= rhs;
        return *this;
    };

    ITVec3<T> &operator*=(const ITVec3<T>& rhs)
    {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        return *this;
    };

    ITVec3<T> &operator*=(const T rhs)
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        return *this;
    };

    operator T*() {
        return &arr[0];
    }

    T& operator[](int index) {
        switch (index) {
            case 0:  return x;
            case 1:  return y;
            case 2:  return z;
            default: return x;
        }
    };

    const T& operator[](int index) const {
        switch (index) {
            case 0:  return x;
            case 1:  return y;
            case 2:  return z;
            default: return x;
        }
    };

    void print() {
        Serial.print("x: ");
        Serial.print(x);
        Serial.print(", y: ");
        Serial.print(y);
        Serial.print(", z: ");
        Serial.print(z);
        Serial.print("\n");
    };
};


struct AccelerationVec: public ITVec3<it_float> {
    AccelerationVec(it_float x = 0, it_float y = 0, it_float z = 0)
            : ITVec3<it_float>(x, y, z) {}

    double roll() {
        return atan2(y, sqrt(x*x + z*z)) * RAD2DEG;
    };

    double pitch() {
        return atan2(x, sqrt(y*y + z*z)) * RAD2DEG;
    };
};


#endif