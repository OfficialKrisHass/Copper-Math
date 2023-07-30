#pragma once

#ifdef INCLUDE_GLM
	#include <GLM/glm.hpp>
#endif

namespace CMATH_NAMESPACE {

	template<typename Type> struct vec<4, Type> {

		vec() : x(Type(0)), y(Type(0)), z(Type(0)), w(Type(0)) {}

		explicit vec(Type all) : x(all), y(all), z(all), w(all) {}
		vec(Type x, Type y, Type z, Type w = Type(0)) : x(x), y(y), z(z), w(w) {}

		vec(const vec<2, Type>& xy, Type z = Type(0), Type w = Type(0)) : x(xy.x), y(xy.y), z(z), w(w) {}
		vec(Type x, const vec<2, Type>& yz, Type w = Type(0)) : x(x), y(yz.x), z(yz.x), w(w) {}
		vec(Type x, Type y, const vec<2, Type>& zw) : x(x), y(y), z(zw.x), w(zw.y) {}
		vec(const vec<2, Type>& xy, const vec<2, Type>& zw) : x(xy.x), y(xy.y), z(zw.x), w(zw.y) {}

		vec(const vec<3, Type>& xyz, Type w = Type(0)) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}
		vec(Type x, const vec<3, Type>& yzw) : x(x), y(yzw.x), z(yzw.y), w(yzw.z) {}

#ifdef INCLUDE_GLM
		vec(const glm::vec<4, Type>& vec) : x(vec.x), y(vec.y), z(vec.z), w(vec.w) {}
		vec(const glm::vec<3, Type>& vec, Type w = Type(0)) : x(vec.x), y(vec.y), z(vec.z) {}
#endif

		Type x;
		Type y;
		Type z;
		Type w;

		static vec<4, Type> zero;
		static vec<4, Type> one;
		static vec<4, Type> minusOne;

		//----Math functions----

		inline Type Dot(const vec<4, Type>& other) const { return x * other.x + y * other.y + z * other.z + w * other.w; }

		inline float LengthSq() const { return x * x + y * y + z * z + w * w; }
		inline float Length() const { return sqrt(x * x + y * y + z * z + w * w); }

		//Returns a Normalized version of the vector
		inline vec<4, Type> Normalized() const { return *this / Length(); }
		//Modifies the Vector to it's Normalized version
		inline void Normalize() { *this /= Length(); } 

		//----Math Operators----

		vec<4, Type> operator+(const vec<4, Type>& other) const { return vec<4, Type>(x + other.x, y + other.y, z + other.z, w + other.w); }
		vec<4, Type> operator-(const vec<4, Type>& other) const { return vec<4, Type>(x - other.x, y - other.y, z - other.z, w - other.w); }
		vec<4, Type> operator*(const vec<4, Type>& other) const { return vec<4, Type>(x * other.x, y * other.y, z * other.z, w * other.w); }
		vec<4, Type> operator/(const vec<4, Type>& other) const { return vec<4, Type>(x / other.x, y / other.y, z / other.z, w / other.w); }
		vec<4, Type> operator%(const vec<4, Type>& other) const {

			return vec<4, Type>(x - other.x * (int32_t) ((int32_t) x / other.x),
							  y - other.y * (int32_t) ((int32_t) y / other.y),
							  z - other.z * (int32_t) ((int32_t) z / other.z),
							  w - other.w * (int32_t) ((int32_t) w / other.w));

		}

		vec<4, Type> operator+(Type other) const { return vec<4, Type>(x + other, y + other, z + other, w + other); }
		vec<4, Type> operator-(Type other) const { return vec<4, Type>(x - other, y - other, z - other, w - other); }
		vec<4, Type> operator*(Type other) const { return vec<4, Type>(x * other, y * other, z * other, w * other); }
		vec<4, Type> operator/(Type other) const { return vec<4, Type>(x / other, y / other, z / other, w / other); }
		vec<4, Type> operator%(Type other) const {

			return vec<4, Type>(x - other * (int32_t) ((int32_t) x / other),
							  y - other * (int32_t) ((int32_t) y / other),
							  z - other * (int32_t) ((int32_t) z / other),
							  w - other * (int32_t) ((int32_t) w / other));
		}

		//----Math and Assignement operators----

		vec<4, Type>& operator=(const vec<4, Type>& other) {

			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			this->w = other.w;
			return *this;

		}
		vec<4, Type>& operator+=(const vec<4, Type>& other) {

			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return *this;

		}
		vec<4, Type>& operator-=(const vec<4, Type>& other) {

			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;
			return *this;

		}
		vec<4, Type>& operator*=(const vec<4, Type>& other) {

			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;
			return *this;

		}
		vec<4, Type>& operator/=(const vec<4, Type>& other) {

			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;
			return *this;

		}
		vec<4, Type>& operator%=(const vec<4, Type>& other) {

			x -= other.x * (int32_t) ((int32_t) x / other.x);
			y -= other.y * (int32_t) ((int32_t) y / other.y);
			z -= other.z * (int32_t) ((int32_t) z / other.z);
			w -= other.w * (int32_t) ((int32_t) w / other.w);
			return *this;

		}

		vec<4, Type>& operator+=(Type other) {

			x += other;
			y += other;
			z += other;
			w += other;
			return *this;

		}
		vec<4, Type>& operator-=(Type other) {

			x -= other;
			y -= other;
			z -= other;
			w -= other;
			return *this;

		}
		vec<4, Type>& operator*=(Type other) {

			x *= other;
			y *= other;
			z *= other;
			w *= other;
			return *this;

		}
		vec<4, Type>& operator/=(Type other) {

			x /= other;
			y /= other;
			z /= other;
			w /= other;
			return *this;

		}
		vec<4, Type>& operator%=(Type other) {

			x -= other * (int32_t) ((int32_t) x / other);
			y -= other * (int32_t) ((int32_t) y / other);
			z -= other * (int32_t) ((int32_t) z / other);
			w -= other * (int32_t) ((int32_t) w / other);
			return *this;

		}

		//----Comparison Operators----

		inline bool operator==(const vec<4, Type>& other) { return x == other.x && y == other.y && z == other.z && w == other.w; }
		inline bool operator!=(const vec<4, Type>& other) { return x != other.x || y != other.y || z != other.z || w != other.w; }

	#ifdef INCLUDE_GLM
		inline bool operator==(const glm::vec<4, Type>& other) { return x == other.x && y == other.y && z == other.z && w == other.w; }
		inline bool operator!=(const glm::vec<4, Type>& other) { return x != other.x || y != other.y || z != other.z || w != other.w; }

		operator glm::vec<4, Type>() const { return glm::vec<4, Type>(x, y, z, w); }
	#endif

		//----Increments and Decremenets----

		vec<4, Type>& operator++() {

			x++;
			y++;
			z++;
			w++;
			return *this;

		}
		vec<4, Type>& operator--() {

			x--;
			y--;
			z--;
			w--;
			return *this;

		}
		vec<4, Type>  operator++(int) {

			vec<4, Type> ret = *this;
			++* this;
			return ret;

		}
		vec<4, Type>  operator--(int) {

			vec<4, Type> ret = *this;
			--* this;
			return ret;

		}

		//----Misc. Operators----

		vec<4, Type> operator-() const { return vec<4, Type>(-x, -y, -z, -w); }
		Type& operator[](uint32_t index) { return (&x)[index]; }
		const Type& operator[](uint32_t index) const { return (&x)[index]; }

	};

	template<typename Type> vec<4, Type> operator+(Type left, const vec<4, Type>& right) { return vec<4, Type>(right.x + left, right.y + left, right.z + left, right.w + left); }
	template<typename Type> vec<4, Type> operator*(Type left, const vec<4, Type>& right) { return vec<4, Type>(right.x * left, right.y * left, right.z * left, right.w * left); }

	template<typename T> inline std::ostream& operator<<(std::ostream& os, const vec<4, T>& vec) {

		os << "X: {" << vec.x << "} Y: {" << vec.y << "} Z: {" << vec.z << "} W: {" << vec.w << "}";
		return os;

	}

	typedef vec<4, float> Vector4;
	typedef vec<4, int32_t> Vector4I;
	typedef vec<4, uint32_t> UVector4I;

	StaticMembers(Vector4);
	StaticMembers(Vector4I);
	StaticMembers(UVector4I);

}