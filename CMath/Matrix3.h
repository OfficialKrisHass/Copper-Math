#pragma once

#ifdef INCLUDE_GLM
	#include <GLM/glm.hpp>
	#include <GLM/mat3x3.hpp>
#endif

#include "Vectors.h"

namespace CMATH_NAMESPACE {

	template<typename Type> mat<3, Type> Inverse(const mat<3, Type>& m);

	template<typename Type> struct mat<3, Type> {

		explicit mat(Type identity = Type(1)) {

			cols[0].x = identity;
			cols[1].y = identity;
			cols[2].z = identity;

		}
		mat(const vec<3, Type>& col0, const vec<3, Type>& col1, const vec<3, Type>& col2) {

			cols[0] = col0;
			cols[1] = col1;
			cols[2] = col2;

		}

		mat(const mat<4, Type>& mat) {

			cols[0] = mat.cols[0];
			cols[1] = mat.cols[1];
			cols[2] = mat.cols[2];

		}

		vec<3, Type> cols[3];

		//----Math Funcions----
		inline mat<3, Type>& TurnInverse() {
			
			Type det = Type(1) / (cols[0].x * (cols[1].y * cols[2].z - cols[2].y * cols[1].z) -
								  cols[1].x * (cols[0].y * cols[2].z - cols[2].y * cols[0].z) +
								  cols[2].x * (cols[0].y * cols[1].z - cols[1].y * cols[0].z));

			mat<3, Type> ret;
			ret[0].x =  (cols[1].y * cols[2].z - cols[2].y * cols[1].z) * det;
			ret[1].x = -(cols[1].x * cols[2].z - cols[2].x * cols[1].z) * det;
			ret[2].x =  (cols[1].x * cols[2].y - cols[2].x * cols[1].y) * det;

			ret[0].y = -(cols[0].y * cols[2].z - cols[2].y * cols[0].z) * det;
			ret[1].y =  (cols[0].x * cols[2].z - cols[2].x * cols[0].z) * det;
			ret[2].y = -(cols[0].x * cols[2].y - cols[2].x * cols[0].y) * det;

			ret[0].z =  (cols[0].y * cols[1].z - cols[1].y * cols[0].z) * det;
			ret[1].z = -(cols[0].x * cols[1].z - cols[1].x * cols[0].z) * det;
			ret[2].z =  (cols[0].x * cols[1].y - cols[1].x * cols[0].y) * det;

			return ret;
			
		}

		//----Math Operators----
		inline mat<3, Type> operator+(const mat<3, Type>& other) const { return mat<3, Type>(cols[0] + other.cols[0], cols[1] + other.cols[1], cols[2] + other.cols[2]); }
		inline mat<3, Type> operator-(const mat<3, Type>& other) const { return mat<3, Type>(cols[0] - other.cols[0], cols[1] - other.cols[1], cols[2] - other.cols[2]); }
		inline mat<3, Type> operator*(const mat<3, Type>& other) const { return mat<3, Type>(cols[0] * other.cols[0], cols[1] * other.cols[1], cols[2] * other.cols[2]); }
		
		inline mat<3, Type> operator+(const Type scalar) const { return mat<3, Type>(cols[0] + scalar, cols[1] + scalar, cols[2] + scalar); }
		inline mat<3, Type> operator-(const Type scalar) const { return mat<3, Type>(cols[0] - scalar, cols[1] - scalar, cols[2] - scalar); }
		inline mat<3, Type> operator*(const Type scalar) const { return mat<3, Type>(cols[0] * scalar, cols[1] * scalar, cols[2] * scalar); }

		inline vec<3, Type> operator*(const vec<3, Type>& v) {

			return vec<3, Type>(cols[0].x * v.x + cols[1].x * v.y + cols[2].x * v.z,
								cols[0].y * v.x + cols[1].y * v.y + cols[2].y * v.z,
								cols[0].z * v.x + cols[1].z * v.y + cols[2].z * v.z);

		}
		inline vec<3, Type> operator/(const vec<3, Type>& vec) {

			return Inverse(*this) * vec;

		}

		//----Math and Assignement Operators----
		inline mat<3, Type>& operator=(const mat<3, Type>& other) {

			cols[0] = other.cols[0];
			cols[1] = other.cols[1];
			cols[2] = other.cols[2];

		}
		inline mat<3, Type>& operator+=(const mat<3, Type>& other) {

			cols[0] += other.cols[0];
			cols[1] += other.cols[1];
			cols[2] += other.cols[2];
			return *this;

		}
		inline mat<3, Type>& operator-=(const mat<3, Type>& other) {

			cols[0] -= other.cols[0];
			cols[1] -= other.cols[1];
			cols[2] -= other.cols[2];
			return *this;

		}
		inline mat<3, Type>& operator*=(const mat<3, Type>& other) {

			cols[0] *= other.cols[0];
			cols[1] *= other.cols[1];
			cols[2] *= other.cols[2];
			return *this;

		}
		inline mat<3, Type>& operator/=(const mat<3, Type>& other) {

			return *this * Inverse(other);

		}

		inline mat<3, Type>& operator+=(const Type scalar) {

			cols[0] += scalar;
			cols[1] += scalar;
			cols[2] += scalar;
			return *this;

		}
		inline mat<3, Type>& operator-=(const Type scalar) {

			cols[0] -= scalar;
			cols[1] -= scalar;
			cols[2] -= scalar;
			return *this;

		}
		inline mat<3, Type>& operator*=(const Type scalar) {

			cols[0] *= scalar;
			cols[1] *= scalar;
			cols[2] *= scalar;
			return *this;

		}
		inline mat<3, Type>& operator/=(const Type scalar) {

			cols[0] /= scalar;
			cols[1] /= scalar;
			cols[2] /= scalar;
			return *this;

		}

		//----Comparison Operators----

		inline bool operator==(const mat<3, Type>& other) { return cols[0] == other.cols[0] && cols[1] == other.cols[1] && cols[2] == other.cols[2]; }
		inline bool operator!=(const mat<3, Type>& other) { return !(*this == other); }

	#ifdef INCLUDE_GLM
		inline bool operator==(const glm::mat<3, 3, Type>& other) { return cols[0] == other[0] && cols[1] == other[1] && cols[2] == other[2]; }
		inline bool operator!=(const glm::mat<3, 3, Type>& other) { return !(*this == other); }

		inline operator glm::mat<3, 3, Type>() const { return glm::mat<3, 3, Type>(cols[0], cols[1], cols[2]); }
	#endif

		//----Increments and Decrements----

		mat<3, Type>& operator++() {

			++cols[0];
			++cols[1];
			++cols[2];
			return *this;

		}
		mat<3, Type>& operator--() {

			--cols[0];
			--cols[1];
			--cols[2];
			return *this;

		}
		mat<3, Type>  operator++(int) {

			mat<3, Type> ret = *this;
			++*this;
			return ret;

		}
		mat<3, Type>  operator--(int) {

			mat<3, Type> ret = *this;
			--*this;
			return ret;

		}

		//----Misc. Operators

		inline mat<3, Type> operator-() const { return mat<3, Type>(-cols[0], -cols[1], -cols[2]); }
		inline vec<3, Type>& operator[](uint32_t index) { return cols[index]; }

	};
	template<typename Type> mat<3, Type> Inverse(const mat<3, Type>& m) {

		Type det = Type(1) / (m.cols[0].x * (m.cols[1].y * m.cols[2].z - m.cols[2].y * m.cols[1].z) -
							  m.cols[1].x * (m.cols[0].y * m.cols[2].z - m.cols[2].y * m.cols[0].z) +
							  m.cols[2].x * (m.cols[0].y * m.cols[1].z - m.cols[1].y * m.cols[0].z));

		mat<3, Type> ret;
		ret[0].x =  (m.cols[1].y * m.cols[2].z - m.cols[2].y * m.cols[1].z) * det;
		ret[1].x = -(m.cols[1].x * m.cols[2].z - m.cols[2].x * m.cols[1].z) * det;
		ret[2].x =  (m.cols[1].x * m.cols[2].y - m.cols[2].x * m.cols[1].y) * det;

		ret[0].y = -(m.cols[0].y * m.cols[2].z - m.cols[2].y * m.cols[0].z) * det;
		ret[1].y =  (m.cols[0].x * m.cols[2].z - m.cols[2].x * m.cols[0].z) * det;
		ret[2].y = -(m.cols[0].x * m.cols[2].y - m.cols[2].x * m.cols[0].y) * det;

		ret[0].z =  (m.cols[0].y * m.cols[1].z - m.cols[1].y * m.cols[0].z) * det;
		ret[1].z = -(m.cols[0].x * m.cols[1].z - m.cols[1].x * m.cols[0].z) * det;
		ret[2].z =  (m.cols[0].x * m.cols[1].y - m.cols[1].x * m.cols[0].y) * det;

		return ret;

	}

	template<typename Type> mat<3, Type> operator+(Type scalar, const mat<3, Type>& m) { return mat<3, Type>(m.cols[0] + scalar, m.cols[1] + scalar, m.cols[2] + scalar); }
	template<typename Type> mat<3, Type> operator-(Type scalar, const mat<3, Type>& m) { return mat<3, Type>(m.cols[0] - scalar, m.cols[1] - scalar, m.cols[2] - scalar); }
	template<typename Type> mat<3, Type> operator*(Type scalar, const mat<3, Type>& m) { return mat<3, Type>(m.cols[0] * scalar, m.cols[1] * scalar, m.cols[2] * scalar); }

	template<typename Type> vec<3, Type> operator*(const vec<3, Type>& v, const mat<3, Type>& m) {

		return vec<3, Type>(m.cols[0].x * v.x + m.cols[0].y * v.y + m.cols[0].z * v.z,
						  	m.cols[1].x * v.x + m.cols[1].y * v.y + m.cols[1].z * v.z,
						  	m.cols[2].x * v.x + m.cols[2].y * v.y + m.cols[2].z * v.z);

	}
	template<typename Type> vec<3, Type> operator/(const vec<3, Type>& vec, const mat<3, Type>& m) { return vec * Inverse(m); }
	
	typedef mat<3, float> Matrix3;
	typedef mat<3, int32_t> Matrix3I;
	typedef mat<3, uint32_t> UMatrix3I;

}