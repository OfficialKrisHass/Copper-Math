#pragma once

//For some weird fucking reason, the vec4 struct has to bein this file, because if I literally
//Do the same as I did for the other 2 vectors it just doesn't work, WHY WHY DO YOU NOT WORK
//So it has to be in here, yay

namespace CMath {

	template<typename Type> struct vec3 {

		vec3() : x(Type(0)), y(Type(0)), z(Type(0)) {}
		vec3(Type all) : x(all), y(all), z(all) {}
		vec3(Type x, Type y, Type z = Type(0)) : x(x), y(y), z(z) {}
		vec3(vec2<Type> vec, Type z = Type(0)) : x(vec.x), y(vec.y), z(z) {}

		Type x;
		Type y;
		Type z;

		static vec3<Type> zero;
		static vec3<Type> one;
		static vec3<Type> minusOne;

		inline Type Dot(const vec3<Type>& other) const { return x * other.x + y * other.y + z * other.z; }
		inline vec3<Type> Cross(const vec3<Type>& other) const {

			return vec3<Type>(y * other.z - z * other.y,
							  z * other.x - x * other.z,
							  x * other.y - y * other.x);

		}

		inline float LengthSq() const { return x * x + y * y + z * z; }
		inline float Length() const { return sqrt(x * x + y * y + z * z); }

		inline vec3<Type> Normalized() const { return *this / Length(); }
		inline void Normalize() { *this /= Length(); }

		inline bool operator==(const vec3<Type>& other) { return x == other.x && y == other.y && z == other.z; }
		inline bool operator!=(const vec3<Type>& other) { return x != other.x || y != other.y || z != other.z; }

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

	};
	template<typename Type> struct vec4 {

		vec4() : x(Type(0)), y(Type(0)), z(Type(0)), w(Type(0)) {}
		vec4(Type all) : x(all), y(all), z(all), w(all) {}
		vec4(Type x, Type y, Type z, Type w = Type(0)) : x(x), y(y), z(z), w(w) {}
		vec4(vec3<Type> vec, Type w = Type(0)) : x(vec.x), y(vec.y), z(vec.z), w(w) {}

		Type x;
		Type y;
		Type z;
		Type w;

		static vec4<Type> zero;
		static vec4<Type> one;
		static vec4<Type> minusOne;

		inline Type Dot(const vec4<Type>& other) const { return x * other.x + y * other.y + z * other.z + w * other.w; }

		inline float LengthSq() const { return x * x + y * y + z * z + w * w; }
		inline float Length() const { return sqrt(x * x + y * y + z * z + w * w); }

		inline vec4<Type> Normalized() const { return *this / Length(); }
		inline void Normalize() { *this /= Length(); }

		inline bool operator==(const vec4<Type>& other) { return x == other.x && y == other.y && z == other.z && w == other.w; }
		inline bool operator!=(const vec4<Type>& other) { return x != other.x || y != other.y || z != other.z || w != other.w; }

		vec4<Type> operator+(const vec4<Type>& other) const { return vec4<Type>(x + other.x, y + other.y, z + other.z, w + other.w); }
		vec4<Type> operator-(const vec4<Type>& other) const { return vec4<Type>(x - other.x, y - other.y, z - other.z, w - other.w); }
		vec4<Type> operator*(const vec4<Type>& other) const { return vec4<Type>(x * other.x, y * other.y, z * other.z, w * other.w); }
		vec4<Type> operator/(const vec4<Type>& other) const { return vec4<Type>(x / other.x, y / other.y, z / other.z, w / other.w); }
		vec4<Type> operator%(const vec4<Type>& other) const {

			return vec4<Type>(x - other.x * (int32_t) ((int32_t) x / other.x),
							  y - other.y * (int32_t) ((int32_t) y / other.y),
							  z - other.z * (int32_t) ((int32_t) z / other.z),
							  w - other.w * (int32_t) ((int32_t) w / other.w));

		}

		vec4<Type> operator+(Type other) const { return vec4<Type>(x + other, y + other, z + other, w + other); }
		vec4<Type> operator-(Type other) const { return vec4<Type>(x - other, y - other, z - other, w - other); }
		vec4<Type> operator*(Type other) const { return vec4<Type>(x * other, y * other, z * other, w * other); }
		vec4<Type> operator/(Type other) const { return vec4<Type>(x / other, y / other, z / other, w / other); }
		vec4<Type> operator%(Type other) const {

			return vec4<Type>(x - other * (int32_t) ((int32_t) x / other),
							  y - other * (int32_t) ((int32_t) y / other),
							  z - other * (int32_t) ((int32_t) z / other),
							  w - other * (int32_t) ((int32_t) w / other));
		}

		vec4<Type>& operator+=(const vec4<Type>& other) {

			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return *this;

		}
		vec4<Type>& operator-=(const vec4<Type>& other) {

			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;
			return *this;

		}
		vec4<Type>& operator*=(const vec4<Type>& other) {

			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;
			return *this;

		}
		vec4<Type>& operator/=(const vec4<Type>& other) {

			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;
			return *this;

		}
		vec4<Type>& operator%=(const vec4<Type>& other) {

			x -= other.x * (int32_t) ((int32_t) x / other.x);
			y -= other.y * (int32_t) ((int32_t) y / other.y);
			z -= other.z * (int32_t) ((int32_t) z / other.z);
			w -= other.w * (int32_t) ((int32_t) w / other.w);
			return *this;

		}

		vec4<Type>& operator+=(Type other) {

			x += other;
			y += other;
			z += other;
			w += other;
			return *this;

		}
		vec4<Type>& operator-=(Type other) {

			x -= other;
			y -= other;
			z -= other;
			w -= other;
			return *this;

		}
		vec4<Type>& operator*=(Type other) {

			x *= other;
			y *= other;
			z *= other;
			w *= other;
			return *this;

		}
		vec4<Type>& operator/=(Type other) {

			x /= other;
			y /= other;
			z /= other;
			w /= other;
			return *this;

		}
		vec4<Type>& operator%=(Type other) {

			x -= other * (int32_t) ((int32_t) x / other);
			y -= other * (int32_t) ((int32_t) y / other);
			z -= other * (int32_t) ((int32_t) z / other);
			w -= other * (int32_t) ((int32_t) w / other);
			return *this;

		}

	};

	template<typename Type> vec3<Type> operator+(Type left, const vec3<Type>& right) { return vec3<Type>(right.x + left, right.y + left, right.z + left); }
	template<typename Type> vec3<Type> operator*(Type left, const vec3<Type>& right) { return vec3<Type>(right.x * left, right.y * left, right.z * left); }

	template<typename Type> vec4<Type> operator+(Type left, const vec4<Type>& right) { return vec4<Type>(right.x + left, right.y + left, right.z + left, right.w + left); }
	template<typename Type> vec4<Type> operator*(Type left, const vec4<Type>& right) { return vec4<Type>(right.x * left, right.y * left, right.z * left, right.w * left); }

	//ostream operator overloadings
	template<typename T> inline std::ostream& operator<<(std::ostream& os, const vec3<T>& vec) {

		os << "X: {" << vec.x << "} Y: {" << vec.y << "} Z: {" << vec.z << "}";
		return os;

	}
	template<typename T> inline std::ostream& operator<<(std::ostream& os, const vec4<T>& vec) {

		os << "X: {" << vec.x << "} Y: {" << vec.y << "} Z: {" << vec.z << "} W: {" << vec.w << "}";
		return os;

	}

	//Typedefs so that we don't have to use the templates
	typedef vec3<float> Vector3;
	typedef vec3<int32_t> Vector3I;
	typedef vec3<uint32_t> UVector3I;

	typedef vec4<float> Vector4;
	typedef vec4<int32_t> Vector4I;
	typedef vec4<uint32_t> UVector4I;

	//Static Members
	StaticMembers(Vector3)
	StaticMembers(Vector3I)
	StaticMembers(UVector3I)

	StaticMembers(Vector4)
	StaticMembers(Vector4I)
	StaticMembers(UVector4I)

	
}