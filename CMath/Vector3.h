#pragma once

//For some weird fucking reason, the vec4 struct has to bein this file, because if I literally
//Do the same as I did for the other 2 vectors it just doesn't work, WHY WHY DO YOU NOT WORK
//So it has to be in here, yay

#ifdef INCLUDE_GLM
	#include <GLM/glm.hpp>
#endif

#include "Vector2.h"

namespace CMATH_NAMESPACE {

	template<typename Type> struct vec4;

	template<typename Type> struct vec3 {

		vec3() : x(Type(0)), y(Type(0)), z(Type(0)) {}

		explicit vec3(Type all) : x(all), y(all), z(all) {}
		vec3(Type x, Type y, Type z = Type(0)) : x(x), y(y), z(z) {}

		vec3(const vec2<Type>& xy, Type z = Type(0)) : x(xy.x), y(xy.y), z(z) {}
		vec3(Type x, const vec2<Type>& yz) : x(x), y(yz.x), z(yz.x) {}

		vec3(const vec4<Type>& vec);

		Type x;
		Type y;
		Type z;

		static vec3<Type> zero;
		static vec3<Type> one;
		static vec3<Type> minusOne;

		//----Math Functions----

		inline Type Dot(const vec3<Type>& other) const { return x * other.x + y * other.y + z * other.z; }
		inline vec3<Type> Cross(const vec3<Type>& other) const {

			return vec3<Type>(y * other.z - z * other.y,
							  z * other.x - x * other.z,
							  x * other.y - y * other.x);

		}

		inline float LengthSq() const { return x * x + y * y + z * z; }
		inline float Length() const { return sqrt(x * x + y * y + z * z); }

		inline vec3<Type> Normalized() const { return *this / Length(); } //Returns a Normalized version of the vector
		inline void Normalize() { *this /= Length(); } //Modifies the Vector to it's Normalized version

		//----Math Operators----

		vec3<Type> operator+(const vec3<Type>& other) const { return vec3<Type>(x + other.x, y + other.y, z + other.z); }
		vec3<Type> operator-(const vec3<Type>& other) const { return vec3<Type>(x - other.x, y - other.y, z - other.z); }
		vec3<Type> operator*(const vec3<Type>& other) const { return vec3<Type>(x * other.x, y * other.y, z * other.z); }
		vec3<Type> operator/(const vec3<Type>& other) const { return vec3<Type>(x / other.x, y / other.y, z / other.z); }
		vec3<Type> operator%(const vec3<Type>& other) const {

			return vec3<Type>(x - other.x * (int32_t) ((int32_t) x / other.x),
							  y - other.y * (int32_t) ((int32_t) y / other.y),
							  z - other.z * (int32_t) ((int32_t) z / other.z));

		}

		vec3<Type> operator+(Type other) const { return vec3<Type>(x + other, y + other, z + other); }
		vec3<Type> operator-(Type other) const { return vec3<Type>(x - other, y - other, z - other); }
		vec3<Type> operator*(Type other) const { return vec3<Type>(x * other, y * other, z * other); }
		vec3<Type> operator/(Type other) const { return vec3<Type>(x / other, y / other, z / other); }
		vec3<Type> operator%(Type other) const {

			return vec3<Type>(x - other * (int32_t) ((int32_t) x / other),
							  y - other * (int32_t) ((int32_t) y / other),
							  z - other * (int32_t) ((int32_t) z / other));
		}

		//----Math and Assigenement Operators----

		vec3<Type>& operator=(const vec3<Type>& other) {

			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			return *this;

		}
		vec3<Type>& operator+=(const vec3<Type>& other) {

			x += other.x;
			y += other.y;
			z += other.z;
			return *this;

		}
		vec3<Type>& operator-=(const vec3<Type>& other) {

			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;

		}
		vec3<Type>& operator*=(const vec3<Type>& other) {

			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;

		}
		vec3<Type>& operator/=(const vec3<Type>& other) {

			x /= other.x;
			y /= other.y;
			z /= other.z;
			return *this;

		}
		vec3<Type>& operator%=(const vec3<Type>& other) {

			x -= other.x * (int32_t) ((int32_t) x / other.x);
			y -= other.y * (int32_t) ((int32_t) y / other.y);
			z -= other.z * (int32_t) ((int32_t) z / other.z);
			return *this;

		}

		vec3<Type>& operator+=(Type other) {

			x += other;
			y += other;
			z += other;
			return *this;

		}
		vec3<Type>& operator-=(Type other) {

			x -= other;
			y -= other;
			z -= other;
			return *this;

		}
		vec3<Type>& operator*=(Type other) {

			x *= other;
			y *= other;
			z *= other;
			return *this;

		}
		vec3<Type>& operator/=(Type other) {

			x /= other;
			y /= other;
			z /= other;
			return *this;

		}
		vec3<Type>& operator%=(Type other) {

			x -= other * (int32_t) ((int32_t) x / other);
			y -= other * (int32_t) ((int32_t) y / other);
			z -= other * (int32_t) ((int32_t) z / other);
			return *this;

		}

		//----Comparison Operators----

		inline bool operator==(const vec3<Type>& other) { return x == other.x && y == other.y && z == other.z; }
		inline bool operator!=(const vec3<Type>& other) { return x != other.x || y != other.y || z != other.z; }

	#ifdef INCLUDE_GLM
		inline bool operator==(const glm::vec<3, Type>& other) { return x == other.x && y == other.y && z == other.z; }
		inline bool operator!=(const glm::vec<3, Type>& other) { return x != other.x || y != other.y || z != other.z; }

		operator glm::vec<3, Type>() const { return glm::vec<3, Type>(x, y, z); }
	#endif

		//----Increments and Decrements----

		vec3<Type>& operator++() {

			x++;
			y++;
			z++;
			return *this;

		}
		vec3<Type>& operator--() {

			x--;
			y--;
			z--;
			return *this;

		}
		vec3<Type>  operator++(int) {

			vec3<Type> ret = *this;
			++*this;
			return ret;

		}
		vec3<Type>  operator--(int) {

			vec3<Type> ret = *this;
			--*this;
			return ret;

		}

		//----Misc. Operators----

		vec3<Type> operator-() const { return vec3<Type>(-x, -y, -z); }
	
	};
	

	template<typename Type> vec3<Type> operator+(Type left, const vec3<Type>& right) { return vec3<Type>(right.x + left, right.y + left, right.z + left); }
	template<typename Type> vec3<Type> operator*(Type left, const vec3<Type>& right) { return vec3<Type>(right.x * left, right.y * left, right.z * left); }
	
	//ostream operator overloadings
	template<typename T> inline std::ostream& operator<<(std::ostream& os, const vec3<T>& vec) {

		os << "X: {" << vec.x << "} Y: {" << vec.y << "} Z: {" << vec.z << "}";
		return os;

	}
	
	//Typedefs so that we don't have to use the templates
	typedef vec3<float> Vector3;
	typedef vec3<int32_t> Vector3I;
	typedef vec3<uint32_t> UVector3I;

	//Static Members
	StaticMembers(Vector3);
	StaticMembers(Vector3I);
	StaticMembers(UVector3I);

}

#include "Vector4.h"

namespace CMATH_NAMESPACE {

	template<typename Type> vec3<Type>::vec3(const vec4<Type>& vec) : x(vec.x), y(vec.y), z(vec.z) {}

}