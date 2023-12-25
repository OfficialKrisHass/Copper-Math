#pragma once

#ifdef INCLUDE_GLM
	#include <GLM/glm.hpp>
#endif

namespace CMATH_NAMESPACE {

	template<typename Type> struct vec<3, Type> {

		vec() : x(Type(0)), y(Type(0)), z(Type(0)) {}

		explicit vec(Type all) : x(all), y(all), z(all) {}
		vec(Type x, Type y, Type z = Type(0)) : x(x), y(y), z(z) {}

		vec(const vec<2, Type>& xy, Type z = Type(0)) : x(xy.x), y(xy.y), z(z) {}
		vec(Type x, const vec<2, Type>& yz) : x(x), y(yz.x), z(yz.y) {}

		vec(const vec<4, Type>& vec)  : x(vec[0]), y(vec[1]), z(vec[2]) {}

#ifdef INCLUDE_GLM
		vec(const glm::vec<3, Type>& vec) : x(vec.x), y(vec.y), z(vec.z) {}
		vec(const glm::vec<4, Type>& vec) : x(vec.x), y(vec.y), z(vec.z) {}
#endif

		Type x;
		Type y;
		Type z;

		static vec<3, Type> zero;
		static vec<3, Type> one;
		static vec<3, Type> minusOne;

		//----Math Functions----

		inline Type Dot(const vec<3, Type>& other) const { return x * other.x + y * other.y + z * other.z; }
		inline vec<3, Type> Cross(const vec<3, Type>& other) const {

			return vec<3, Type>(y * other.z - z * other.y,
							  	z * other.x - x * other.z,
							  	x * other.y - y * other.x);

		}

		inline float LengthSq() const { return x * x + y * y + z * z; }
		inline float Length() const { return sqrt(x * x + y * y + z * z); }

		inline vec<3, Type> Normalized() const { return *this / Length(); } //Returns a Normalized version of the vector
		inline void Normalize() { *this /= Length(); } //Modifies the Vector to it's Normalized version

		//----Math Operators----

		vec<3, Type> operator+(const vec<3, Type>& other) const { return vec<3, Type>(x + other.x, y + other.y, z + other.z); }
		vec<3, Type> operator-(const vec<3, Type>& other) const { return vec<3, Type>(x - other.x, y - other.y, z - other.z); }
		vec<3, Type> operator*(const vec<3, Type>& other) const { return vec<3, Type>(x * other.x, y * other.y, z * other.z); }
		vec<3, Type> operator/(const vec<3, Type>& other) const { return vec<3, Type>(x / other.x, y / other.y, z / other.z); }
		vec<3, Type> operator%(const vec<3, Type>& other) const {

			return vec<3, Type>(x - other.x * (int32_t) ((int32_t) x / other.x),
							  y - other.y * (int32_t) ((int32_t) y / other.y),
							  z - other.z * (int32_t) ((int32_t) z / other.z));

		}

		vec<3, Type> operator+(Type other) const { return vec<3, Type>(x + other, y + other, z + other); }
		vec<3, Type> operator-(Type other) const { return vec<3, Type>(x - other, y - other, z - other); }
		vec<3, Type> operator*(Type other) const { return vec<3, Type>(x * other, y * other, z * other); }
		vec<3, Type> operator/(Type other) const { return vec<3, Type>(x / other, y / other, z / other); }
		vec<3, Type> operator%(Type other) const {

			return vec<3, Type>(x - other * (int32_t) ((int32_t) x / other),
							  y - other * (int32_t) ((int32_t) y / other),
							  z - other * (int32_t) ((int32_t) z / other));
		}

		//----Math and Assigenement Operators----

		vec<3, Type>& operator=(const vec<3, Type>& other) {

			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			return *this;

		}
		vec<3, Type>& operator+=(const vec<3, Type>& other) {

			x += other.x;
			y += other.y;
			z += other.z;
			return *this;

		}
		vec<3, Type>& operator-=(const vec<3, Type>& other) {

			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;

		}
		vec<3, Type>& operator*=(const vec<3, Type>& other) {

			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;

		}
		vec<3, Type>& operator/=(const vec<3, Type>& other) {

			x /= other.x;
			y /= other.y;
			z /= other.z;
			return *this;

		}
		vec<3, Type>& operator%=(const vec<3, Type>& other) {

			x -= other.x * (int32_t) ((int32_t) x / other.x);
			y -= other.y * (int32_t) ((int32_t) y / other.y);
			z -= other.z * (int32_t) ((int32_t) z / other.z);
			return *this;

		}

		vec<3, Type>& operator+=(Type other) {

			x += other;
			y += other;
			z += other;
			return *this;

		}
		vec<3, Type>& operator-=(Type other) {

			x -= other;
			y -= other;
			z -= other;
			return *this;

		}
		vec<3, Type>& operator*=(Type other) {

			x *= other;
			y *= other;
			z *= other;
			return *this;

		}
		vec<3, Type>& operator/=(Type other) {

			x /= other;
			y /= other;
			z /= other;
			return *this;

		}
		vec<3, Type>& operator%=(Type other) {

			x -= other * (int32_t) ((int32_t) x / other);
			y -= other * (int32_t) ((int32_t) y / other);
			z -= other * (int32_t) ((int32_t) z / other);
			return *this;

		}

		//----Comparison Operators----

		inline bool operator==(const vec<3, Type>& other) const { return x == other.x && y == other.y && z == other.z; }
		inline bool operator!=(const vec<3, Type>& other) const { return x != other.x || y != other.y || z != other.z; }

	#ifdef INCLUDE_GLM
		inline bool operator==(const glm::vec<3, Type>& other) const { return x == other.x && y == other.y && z == other.z; }
		inline bool operator!=(const glm::vec<3, Type>& other) const { return x != other.x || y != other.y || z != other.z; }

		operator glm::vec<3, Type>() const { return glm::vec<3, Type>(x, y, z); }
	#endif

		//----Increments and Decrements----

		vec<3, Type>& operator++() {

			x++;
			y++;
			z++;
			return *this;

		}
		vec<3, Type>& operator--() {

			x--;
			y--;
			z--;
			return *this;

		}
		vec<3, Type>  operator++(int) {

			vec<3, Type> ret = *this;
			++*this;
			return ret;

		}
		vec<3, Type>  operator--(int) {

			vec<3, Type> ret = *this;
			--*this;
			return ret;

		}

		//----Misc. Operators----

		vec<3, Type> operator-() const { return vec<3, Type>(-x, -y, -z); }
		Type& operator[](uint32_t index) { return (&x)[index]; }
		const Type& operator[](uint32_t index) const { return (&x)[index]; }
	
	};
	

	template<typename Type> vec<3, Type> operator+(Type left, const vec<3, Type>& right) { return vec<3, Type>(right.x + left, right.y + left, right.z + left); }
	template<typename Type> vec<3, Type> operator*(Type left, const vec<3, Type>& right) { return vec<3, Type>(right.x * left, right.y * left, right.z * left); }
	
	//ostream operator overloadings
	template<typename T> inline std::ostream& operator<<(std::ostream& os, const vec<3, T>& vec) {

		os << "X: {" << vec.x << "} Y: {" << vec.y << "} Z: {" << vec.z << "}";
		return os;

	}
	
	//Typedefs so that we don't have to use the templates
	typedef vec<3, float> Vector3;
	typedef vec<3, int32_t> Vector3I;
	typedef vec<3, uint32_t> UVector3I;

	//Static Members
	StaticMembers(Vector3);
	StaticMembers(Vector3I);
	StaticMembers(UVector3I);

}