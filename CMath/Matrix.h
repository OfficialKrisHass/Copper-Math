#pragma once

#ifdef INCLUDE_GLM
	#include <GLM/glm.hpp>
	#include<GLM/mat4x4.hpp>
#endif

#include <stdint.h>

#include "Vectors.h"

namespace CMath {

	template<typename Type> struct mat4;
	template<typename Type> mat4<Type> Inverse(const mat4<Type>& m);

	template<typename Type> struct mat4 {

		mat4(Type identity = 1.0f) {

			cols[0].x = identity;
			cols[1].y = identity;
			cols[2].z = identity;
			cols[3].w = identity;

		}
		mat4(vec4<Type> col0, vec4<Type> col1, vec4<Type> col2, vec4<Type> col3) {

			cols[0] = col0;
			cols[1] = col1;
			cols[2] = col2;
			cols[3] = col3;

		}

		vec4<Type> cols[4];

		inline mat4<Type>& TurnInverse() {

			//This is definitely not stolen from GLM. I Swear.
			//Go check out GLM, and use their library not mine.
			//mine is bad :c

			Type c00 = cols[2].z * cols[3].w - cols[3].z * cols[2].w;
			Type c02 = cols[1].z * cols[3].w - cols[3].z * cols[1].w;
			Type c03 = cols[1].z * cols[2].w - cols[2].z * cols[1].w;

			Type c04 = cols[2].y * cols[3].w - cols[3].y * cols[2].w;
			Type c06 = cols[1].y * cols[3].w - cols[3].y * cols[1].w;
			Type c07 = cols[1].y * cols[2].w - cols[2].y * cols[1].w;

			Type c08 = cols[2].y * cols[3].z - cols[3].y * cols[2].z;
			Type c10 = cols[1].y * cols[3].z - cols[3].y * cols[1].z;
			Type c11 = cols[1].y * cols[2].z - cols[2].y * cols[1].z;

			Type c12 = cols[2].x * cols[3].w - cols[3].x * cols[2].w;
			Type c14 = cols[1].x * cols[3].w - cols[3].x * cols[1].w;
			Type c15 = cols[1].x * cols[2].w - cols[2].x * cols[1].w;

			Type c16 = cols[2].x * cols[3].z - cols[3].x * cols[2].z;
			Type c18 = cols[1].x * cols[3].z - cols[3].x * cols[1].z;
			Type c19 = cols[1].x * cols[2].z - cols[2].x * cols[1].z;

			Type c20 = cols[2].x * cols[3].y - cols[3].x * cols[2].y;
			Type c22 = cols[1].x * cols[3].y - cols[3].x * cols[1].y;
			Type c23 = cols[1].x * cols[2].y - cols[2].x * cols[1].y;

			vec4<Type> f0(c00, c00, c02, c03);
			vec4<Type> f1(c04, c04, c06, c07);
			vec4<Type> f2(c08, c08, c10, c11);
			vec4<Type> f3(c12, c12, c14, c15);
			vec4<Type> f4(c16, c16, c18, c19);
			vec4<Type> f5(c20, c20, c22, c23);

			vec4<Type> vec0(cols[1].x, cols[0].x, cols[0].x, cols[0].x);
			vec4<Type> vec1(cols[1].y, cols[0].y, cols[0].y, cols[0].y);
			vec4<Type> vec2(cols[1].z, cols[0].z, cols[0].z, cols[0].z);
			vec4<Type> vec3(cols[1].w, cols[0].w, cols[0].w, cols[0].w);

			vec4<Type> inv0(vec1 * f0 - vec2 * f1 + vec3 * f2);
			vec4<Type> inv1(vec0 * f0 - vec2 * f3 + vec3 * f4);
			vec4<Type> inv2(vec0 * f1 - vec1 * f3 + vec3 * f5);
			vec4<Type> inv3(vec0 * f2 - vec1 * f4 + vec2 * f5);
			
			vec4<Type> a( 1, -1,  1, -1);
			vec4<Type> b(-1,  1, -1,  1);

			mat4<Type> inverse(inv0 * a, inv1 * b, inv2 * a, inv3 * b);

			vec4<Type> r0(inverse[0].x, inverse[1].x, inverse[2].x, inverse[3].x);
			vec4<Type> d0(cols[0] * r0);

			Type d1 = (d0.x + d0.y) + (d0.z + d0.w);
			
			return inverse * (Type(1) / d1);

		}

	#pragma region OperatorOverloads
		inline bool operator==(const mat4<Type>& other) { return cols[0] == other.cols[0] && cols[1] == other.cols[1] && cols[2] == other.cols[2] && cols[3] == other.cols[3]; }
		inline bool operator!=(const mat4<Type>& other) { !(*this == other); }

	#ifdef INCLUDE_GLM
		inline bool operator==(const glm::mat<4, 4, Type>& other) { return cols[0] == other[0] && cols[1] == other[1] && cols[2] == other[2] && cols[3] == other[3]; }
		inline bool operator!=(const glm::mat<4, 4, Type>& other) { !(*this == other); }

		inline operator glm::mat<4, 4, Type>() const { return glm::mat<4, 4, Type>(cols[0], cols[1], cols[2], cols[3]); }
	#endif

		inline mat4<Type> operator+(const mat4<Type>& other) const { return mat4<Type>(cols[0] + other.cols[0], cols[1] + other.cols[1], cols[2] + other.cols[2], cols[3] + other.cols[3]); }
		inline mat4<Type> operator-(const mat4<Type>& other) const { return mat4<Type>(cols[0] - other.cols[0], cols[1] - other.cols[1], cols[2] - other.cols[2], cols[3] - other.cols[3]); }
		inline mat4<Type> operator*(const mat4<Type>& other) const { return mat4<Type>(cols[0] * other.cols[0], cols[1] * other.cols[1], cols[2] * other.cols[2], cols[3] * other.cols[3]); }

		inline mat4<Type> operator+(const Type scalar) const { return mat4<Type>(cols[0] + scalar, cols[1] + scalar, cols[2] + scalar, cols[3] + scalar); }
		inline mat4<Type> operator-(const Type scalar) const { return mat4<Type>(cols[0] - scalar, cols[1] - scalar, cols[2] - scalar, cols[3] - scalar); }
		inline mat4<Type> operator*(const Type scalar) const { return mat4<Type>(cols[0] * scalar, cols[1] * scalar, cols[2] * scalar, cols[3] * scalar); }

		inline mat4<Type>& operator=(const mat4<Type>& other) {

			cols[0] = other.cols[0];
			cols[1] = other.cols[1];
			cols[2] = other.cols[2];
			cols[3] = other.cols[3];
			return *this;

		}
		inline mat4<Type>& operator+=(const mat4<Type>& other) {

			cols[0] += other.cols[0];
			cols[1] += other.cols[1];
			cols[2] += other.cols[2];
			cols[3] += other.cols[3];
			return *this;

		}
		inline mat4<Type>& operator-=(const mat4<Type>& other) {

			cols[0] -= other.cols[0];
			cols[1] -= other.cols[1];
			cols[2] -= other.cols[2];
			cols[3] -= other.cols[3];
			return *this;

		}
		inline mat4<Type>& operator*=(const mat4<Type>& other) {

			cols[0] *= other.cols[0];
			cols[1] *= other.cols[1];
			cols[2] *= other.cols[2];
			cols[3] *= other.cols[3];
			return *this;

		}
		inline mat4<Type>& operator/=(const mat4<Type>& other) {
			
			return *this *= Inverse(other);

		}

		inline mat4<Type>& operator+=(const Type scalar) {

			cols[0] += scalar;
			cols[1] += scalar;
			cols[2] += scalar;
			cols[3] += scalar;
			return *this;

		}
		inline mat4<Type>& operator-=(const Type scalar) {

			cols[0] -= scalar;
			cols[1] -= scalar;
			cols[2] -= scalar;
			cols[3] -= scalar;
			return *this;

		}
		inline mat4<Type>& operator*=(const Type scalar) {

			cols[0] *= scalar;
			cols[1] *= scalar;
			cols[2] *= scalar;
			cols[3] *= scalar;
			return *this;

		}
		inline mat4<Type>& operator/=(const Type scalar) {

			cols[0] /= scalar;
			cols[1] /= scalar;
			cols[2] /= scalar;
			cols[3] /= scalar;
			return *this;

		}

		inline mat4<Type>& operator++() {

			++cols[0];
			++cols[1];
			++cols[2];
			++cols[3];
			return *this;

		}
		inline mat4<Type>& operator--() {

			--cols[0];
			--cols[1];
			--cols[2];
			--cols[3];
			return *this;

		}
		inline mat4<Type>  operator++(int) {

			mat4<Type> ret = *this;
			++*this;
			return ret;

		}
		inline mat4<Type>  operator--(int) {

			mat4<Type> ret = *this;
			--*this;
			return ret;

		}

		inline mat4<Type> operator-() const { return mat4<Type>(-cols[0], -cols[1], -cols[2], -cols[3]); }
		inline vec4<Type>& operator[](uint32_t index) { return cols[index]; }

	#pragma endregion

	};
	template<typename Type> mat4<Type> Inverse(const mat4<Type>& m) {

		//This is definitely not stolen from GLM. I Swear.
		//Go check out GLM, and use their library not mine.
		//mine is bad :c

		Type c00 = m.cols[2].z * m.cols[3].w - m.cols[3].z * m.cols[2].w;
		Type c02 = m.cols[1].z * m.cols[3].w - m.cols[3].z * m.cols[1].w;
		Type c03 = m.cols[1].z * m.cols[2].w - m.cols[2].z * m.cols[1].w;

		Type c04 = m.cols[2].y * m.cols[3].w - m.cols[3].y * m.cols[2].w;
		Type c06 = m.cols[1].y * m.cols[3].w - m.cols[3].y * m.cols[1].w;
		Type c07 = m.cols[1].y * m.cols[2].w - m.cols[2].y * m.cols[1].w;

		Type c08 = m.cols[2].y * m.cols[3].z - m.cols[3].y * m.cols[2].z;
		Type c10 = m.cols[1].y * m.cols[3].z - m.cols[3].y * m.cols[1].z;
		Type c11 = m.cols[1].y * m.cols[2].z - m.cols[2].y * m.cols[1].z;

		Type c12 = m.cols[2].x * m.cols[3].w - m.cols[3].x * m.cols[2].w;
		Type c14 = m.cols[1].x * m.cols[3].w - m.cols[3].x * m.cols[1].w;
		Type c15 = m.cols[1].x * m.cols[2].w - m.cols[2].x * m.cols[1].w;

		Type c16 = m.cols[2].x * m.cols[3].z - m.cols[3].x * m.cols[2].z;
		Type c18 = m.cols[1].x * m.cols[3].z - m.cols[3].x * m.cols[1].z;
		Type c19 = m.cols[1].x * m.cols[2].z - m.cols[2].x * m.cols[1].z;

		Type c20 = m.cols[2].x * m.cols[3].y - m.cols[3].x * m.cols[2].y;
		Type c22 = m.cols[1].x * m.cols[3].y - m.cols[3].x * m.cols[1].y;
		Type c23 = m.cols[1].x * m.cols[2].y - m.cols[2].x * m.cols[1].y;

		vec4<Type> f0(c00, c00, c02, c03);
		vec4<Type> f1(c04, c04, c06, c07);
		vec4<Type> f2(c08, c08, c10, c11);
		vec4<Type> f3(c12, c12, c14, c15);
		vec4<Type> f4(c16, c16, c18, c19);
		vec4<Type> f5(c20, c20, c22, c23);

		vec4<Type> vec0(m.cols[1].x, m.cols[0].x, m.cols[0].x, m.cols[0].x);
		vec4<Type> vec1(m.cols[1].y, m.cols[0].y, m.cols[0].y, m.cols[0].y);
		vec4<Type> vec2(m.cols[1].z, m.cols[0].z, m.cols[0].z, m.cols[0].z);
		vec4<Type> vec3(m.cols[1].w, m.cols[0].w, m.cols[0].w, m.cols[0].w);

		vec4<Type> inv0(vec1 * f0 - vec2 * f1 + vec3 * f2);
		vec4<Type> inv1(vec0 * f0 - vec2 * f3 + vec3 * f4);
		vec4<Type> inv2(vec0 * f1 - vec1 * f3 + vec3 * f5);
		vec4<Type> inv3(vec0 * f2 - vec1 * f4 + vec2 * f5);

		vec4<Type> a(1, -1, 1, -1);
		vec4<Type> b(-1, 1, -1, 1);

		mat4<Type> inverse(inv0 * a, inv1 * b, inv2 * a, inv3 * b);

		vec4<Type> r0(inverse[0].x, inverse[1].x, inverse[2].x, inverse[3].x);
		vec4<Type> d0(m.cols[0] * r0);

		Type d1 = (d0.x + d0.y) + (d0.z + d0.w);

		return inverse * (Type(1) / d1);

	}

	template<typename Type> mat4<Type> operator+(Type scalar, const mat4<Type>& mat) { return mat4<Type>(cols[0] + scalar, cols[1] + scalar, cols[2] + scalar, cols[3] + scalar); }
	template<typename Type> mat4<Type> operator-(Type scalar, const mat4<Type>& mat) { return mat4<Type>(cols[0] - scalar, cols[1] - scalar, cols[2] - scalar, cols[3] - scalar); }
	template<typename Type> mat4<Type> operator*(Type scalar, const mat4<Type>& mat) { return mat4<Type>(cols[0] * scalar, cols[1] * scalar, cols[2] * scalar, cols[3] * scalar); }
	
	typedef mat4<float> Matrix4;
	typedef mat4<int32_t> Matrix4I;
	typedef mat4<uint32_t> UMatrix4I;

}