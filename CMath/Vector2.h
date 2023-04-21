#pragma once

namespace CMath {

	template<typename Type> struct vec2 {

		vec2() : x(Type(0)), y(Type(0)) {}
		vec2(Type all) : x(all), y(all) {}
		vec2(Type x, Type y) : x(x), y(y) {}

		Type x;
		Type y;

		static vec2<Type> zero;
		static vec2<Type> one;
		static vec2<Type> minusOne;

		inline Type Dot(const vec2<Type>& other) const { return x * other.x + y * other.y; }

		inline float LengthSq() const { return x * x + y * y; }
		inline float Length() const { return sqrt(x * x + y * y); }

		inline vec2<Type> Normalized() const { return *this / Length(); }
		inline void Normalize() { *this /= Length(); }

		inline bool operator==(const vec2<Type>& other) { return x == other.x && y == other.y; }
		inline bool operator!=(const vec2<Type>& other) { return x != other.x || y != other.y; }

		vec2<Type> operator+(const vec2<Type>& other) const { return vec2<Type>(x + other.x, y + other.y); }
		vec2<Type> operator-(const vec2<Type>& other) const { return vec2<Type>(x - other.x, y - other.y); }
		vec2<Type> operator*(const vec2<Type>& other) const { return vec2<Type>(x * other.x, y * other.y); }
		vec2<Type> operator/(const vec2<Type>& other) const { return vec2<Type>(x / other.x, y / other.y); }
		vec2<Type> operator%(const vec2<Type>& other) const {
			
			return vec2<Type>(x - other.x * (int32_t) ((int32_t) x / other.x),
							  y - other.y * (int32_t) ((int32_t) y / other.y));
		
		}

		vec2<Type> operator+(Type other) const { return vec2<Type>(x + other, y + other); }
		vec2<Type> operator-(Type other) const { return vec2<Type>(x - other, y - other); }
		vec2<Type> operator*(Type other) const { return vec2<Type>(x * other, y * other); }
		vec2<Type> operator/(Type other) const { return vec2<Type>(x / other, y / other); }
		vec2<Type> operator%(Type other) const {
			
			return vec2<Type>(x - other * (int32_t) ((int32_t) x / other),
							  y - other * (int32_t) ((int32_t) y / other));
		}

		vec2<Type>& operator+=(const vec2<Type>& other) {

			x += other.x;
			y += other.y;
			return *this;

		}
		vec2<Type>& operator-=(const vec2<Type>& other) {

			x -= other.x;
			y -= other.y;
			return *this;

		}
		vec2<Type>& operator*=(const vec2<Type>& other) {

			x *= other.x;
			y *= other.y;
			return *this;

		}
		vec2<Type>& operator/=(const vec2<Type>& other) {

			x /= other.x;
			y /= other.y;
			return *this;

		}
		vec2<Type>& operator%=(const vec2<Type>& other) {

			x -= other.x * (int32_t) ((int32_t) x / other.x);
			y -= other.y * (int32_t) ((int32_t) y / other.y);
			return *this;

		}

		vec2<Type>& operator+=(Type other) {

			x += other;
			y += other;
			return *this;

		}
		vec2<Type>& operator-=(Type other) {

			x -= other;
			y -= other;
			return *this;

		}
		vec2<Type>& operator*=(Type other) {

			x *= other;
			y *= other;
			return *this;

		}
		vec2<Type>& operator/=(Type other) {

			x /= other;
			y /= other;
			return *this;

		}
		vec2<Type>& operator%=(Type other) {

			x -= other * (int32_t) ((int32_t) x / other);
			y -= other * (int32_t) ((int32_t) y / other);
			return *this;

		}

	};

	template<typename Type> vec2<Type> operator+(Type left, const vec2<Type>& right) { return vec2<Type>(right.x + left, right.y + left); }
	template<typename Type> vec2<Type> operator*(Type left, const vec2<Type>& right) { return vec2<Type>(right.x * left, right.y * left); }

	//ostream operator overloadings
	template<typename T> inline std::ostream& operator<<(std::ostream& os, const vec2<T>& vec) {

		os << "X: {" << vec.x << "} Y: {" << vec.y << "}";
		return os;

	}

	//Typedefs so that we don't have to use the templates
	typedef vec2<float> Vector2;
	typedef vec2<int32_t> Vector2I;
	typedef vec2<uint32_t> UVector2I;

	//Static Members
	StaticMembers(Vector2)
	StaticMembers(Vector2I)
	StaticMembers(UVector2I)

}