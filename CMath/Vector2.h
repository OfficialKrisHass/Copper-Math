#pragma once

#ifdef INCLUDE_GLM
	#include <GLM/glm.hpp>
#endif

#include <ostream>

#define StaticMembers(Type)  template<> const Type inline Type::zero = Type(0);\
							 template<> const Type inline Type::one = Type(1);\
							 template<> const Type inline Type::minusOne = Type(-1);

namespace CMATH_NAMESPACE {

	template<typename Type> struct vec<2, Type> {

		vec() : x(Type(0)), y(Type(0)) {}

		explicit vec(Type all) : x(all), y(all) {}
		vec(Type x, Type y) : x(x), y(y) {}

		vec(const vec<3, Type>& vec) : x(vec[0]), y(vec[1]) {}
		vec(const vec<4, Type>& vec) : x(vec[0]), y(vec[1]) {}

#ifdef INCLUDE_GLM
		vec(const glm::vec<2, Type>& vec) : x(vec.x), y(vec.y) {}
#endif

		Type x;
		Type y;

		static const vec<2, Type> zero;
		static const vec<2, Type> one;
		static const vec<2, Type> minusOne;

		//----Math Functions----

		inline Type Dot(const vec<2, Type>& other) const { return x * other.x + y * other.y; }

		inline float LengthSq() const { return x * x + y * y; }
		inline float Length() const { return sqrt(x * x + y * y); }

		inline vec<2, Type> Normalized() const { return *this / Length(); } //Returns a Normalized version of the vector
		inline void Normalize() { *this /= Length(); } //Modifies the Vector to it's Normalized version

		//----Math Operators----

		vec<2, Type> operator+(const vec<2, Type>& other) const { return vec<2, Type>(x + other.x, y + other.y); }
		vec<2, Type> operator-(const vec<2, Type>& other) const { return vec<2, Type>(x - other.x, y - other.y); }
		vec<2, Type> operator*(const vec<2, Type>& other) const { return vec<2, Type>(x * other.x, y * other.y); }
		vec<2, Type> operator/(const vec<2, Type>& other) const { return vec<2, Type>(x / other.x, y / other.y); }
		vec<2, Type> operator%(const vec<2, Type>& other) const {
			
			return vec<2, Type>(x - other.x * (int32_t) ((int32_t) x / other.x),
							  y - other.y * (int32_t) ((int32_t) y / other.y));
		
		}

		vec<2, Type> operator+(Type other) const { return vec<2, Type>(x + other, y + other); }
		vec<2, Type> operator-(Type other) const { return vec<2, Type>(x - other, y - other); }
		vec<2, Type> operator*(Type other) const { return vec<2, Type>(x * other, y * other); }
		vec<2, Type> operator/(Type other) const { return vec<2, Type>(x / other, y / other); }
		vec<2, Type> operator%(Type other) const {
			
			return vec<2, Type>(x - other * (int32_t) ((int32_t) x / other),
							  y - other * (int32_t) ((int32_t) y / other));
		}

		//----Math and Assignement Operators----

		vec<2, Type>& operator=(const vec<2, Type>& other) {

			this->x = other.x;
			this->y = other.y;
			return *this;

		}
		vec<2, Type>& operator+=(const vec<2, Type>& other) {

			x += other.x;
			y += other.y;
			return *this;

		}
		vec<2, Type>& operator-=(const vec<2, Type>& other) {

			x -= other.x;
			y -= other.y;
			return *this;

		}
		vec<2, Type>& operator*=(const vec<2, Type>& other) {

			x *= other.x;
			y *= other.y;
			return *this;

		}
		vec<2, Type>& operator/=(const vec<2, Type>& other) {

			x /= other.x;
			y /= other.y;
			return *this;

		}
		vec<2, Type>& operator%=(const vec<2, Type>& other) {

			x -= other.x * (int32_t) ((int32_t) x / other.x);
			y -= other.y * (int32_t) ((int32_t) y / other.y);
			return *this;

		}

		vec<2, Type>& operator+=(Type other) {

			x += other;
			y += other;
			return *this;

		}
		vec<2, Type>& operator-=(Type other) {

			x -= other;
			y -= other;
			return *this;

		}
		vec<2, Type>& operator*=(Type other) {

			x *= other;
			y *= other;
			return *this;

		}
		vec<2, Type>& operator/=(Type other) {

			x /= other;
			y /= other;
			return *this;

		}
		vec<2, Type>& operator%=(Type other) {

			x -= other * (int32_t) ((int32_t) x / other);
			y -= other * (int32_t) ((int32_t) y / other);
			return *this;

		}

		//----Comparison Operators----

		inline bool operator==(const vec<2, Type>& other) const { return x == other.x && y == other.y; }
		inline bool operator!=(const vec<2, Type>& other) const { return x != other.x || y != other.y; }

	#ifdef INCLUDE_GLM
		inline bool operator==(const glm::vec<2, Type>& other) const { return x == other.x && y == other.y; }
		inline bool operator!=(const glm::vec<2, Type>& other) const { return x != other.x || y != other.y; }

		operator glm::vec<2, Type>() const { return glm::vec<2, Type>(x, y); }
	#endif

		//----Increments and Decrements----

		vec<2, Type>& operator++() {

			x++;
			y++;
			return *this;

		}
		vec<2, Type>& operator--() {

			x--;
			y--;
			return *this;

		}
		vec<2, Type>  operator++(int) {

			vec<2, Type> ret = *this;
			++*this;
			return ret;

		}
		vec<2, Type>  operator--(int) {

			vec<2, Type> ret = *this;
			--*this;
			return ret;

		}

		//----Misc Operators----

		vec<2, Type> operator-() const { return vec<2, Type>(-x, -y); }
		Type operator[](uint32_t index) { return (&x)[index]; }
		const Type operator[](uint32_t index) const { return (&x)[index]; }

	};

	template<typename Type> vec<2, Type> operator+(Type left, const vec<2, Type>& right) { return vec<2, Type>(right.x + left, right.y + left); }
	template<typename Type> vec<2, Type> operator*(Type left, const vec<2, Type>& right) { return vec<2, Type>(right.x * left, right.y * left); }

	//ostream operator overloadings
	template<typename T> inline std::ostream& operator<<(std::ostream& os, const vec<2, T>& vec) {

		os << "X: {" << vec.x << "} Y: {" << vec.y << "}";
		return os;

	}

	typedef vec<2, float> Vector2;
	typedef vec<2, int32_t> Vector2I;
	typedef vec<2, uint32_t> UVector2I;

	StaticMembers(Vector2)
	StaticMembers(Vector2I)
	StaticMembers(UVector2I)

}
