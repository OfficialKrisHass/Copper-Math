#pragma once

#ifdef INCLUDE_GLM
	#include <GLM/glm.hpp>
	#include <GLM/mat3x3.hpp>
#endif

#include "Vectors.h"
#include "Matrix4.h"

namespace CMATH_NAMESPACE {

	template<typename Type> struct mat3;
	template<typename Type> mat3<Type> Inverse(const mat3<Type>& m);

	template<typename Type> struct mat3 {

		explicit mat3(Type identity = Type(1)) {

			cols[0].x = identity;
			cols[1].y = identity;
			cols[2].z = identity;

		}
		mat3(const vec3<Type>& col0, const vec3<Type>& col1, const vec3<Type>& col2) {

			cols[0] = col0;
			cols[1] = col1;
			cols[2] = col2;

		}

		mat3(const mat4<Type>& mat) {

			cols[0] = mat.cols[0];
			cols[1] = mat.cols[1];
			cols[2] = mat.cols[2];

		}

		vec3<Type> cols[3];

		//----Math Funcions----
		inline mat3<Type>& TurnInverse() {
			
			Type det = Type(1) / (cols[0].x * (cols[1].y * cols[2].z - cols[2].y * cols[1].z) -
								  cols[1].x * (cols[0].y * cols[2].z - cols[2].y * cols[0].z) +
								  cols[2].x * (cols[0].y * cols[1].z - cols[1].y * cols[0].z));

			mat3<Type> ret;
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
		inline mat3<Type> operator+(const mat3<Type>& other) const { return mat3<Type>(cols[0] + other.cols[0], cols[1] + other.cols[1], cols[2] + other.cols[2]); }
		inline mat3<Type> operator-(const mat3<Type>& other) const { return mat3<Type>(cols[0] - other.cols[0], cols[1] - other.cols[1], cols[2] - other.cols[2]); }
		inline mat3<Type> operator*(const mat3<Type>& other) const { return mat3<Type>(cols[0] * other.cols[0], cols[1] * other.cols[1], cols[2] * other.cols[2]); }
		
		inline mat3<Type> operator+(const Type scalar) const { return mat3<Type>(cols[0] + scalar, cols[1] + scalar, cols[2] + scalar); }
		inline mat3<Type> operator-(const Type scalar) const { return mat3<Type>(cols[0] - scalar, cols[1] - scalar, cols[2] - scalar); }
		inline mat3<Type> operator*(const Type scalar) const { return mat3<Type>(cols[0] * scalar, cols[1] * scalar, cols[2] * scalar); }

		inline vec3<Type> operator*(const vec3<Type>& vec) {

			return vec3<Type>(cols[0].x * vec.x + cols[1].x * vec.y + cols[2].x * vec.z,
							  cols[0].y * vec.x + cols[1].y * vec.y + cols[2].y * vec.z,
							  cols[0].z * vec.x + cols[1].z * vec.y + cols[2].z * vec.z);

		}
		inline vec3<Type> operator/(const vec3<Type>& vec) {

			return Inverse(*this) * vec;

		}

		//----Math and Assignement Operators----
		inline mat3<Type>& operator=(const mat3<Type>& other) {

			cols[0] = other.cols[0];
			cols[1] = other.cols[1];
			cols[2] = other.cols[2];

		}
		inline mat3<Type>& operator+=(const mat3<Type>& other) {

			cols[0] += other.cols[0];
			cols[1] += other.cols[1];
			cols[2] += other.cols[2];
			return *this;

		}
		inline mat3<Type>& operator-=(const mat3<Type>& other) {

			cols[0] -= other.cols[0];
			cols[1] -= other.cols[1];
			cols[2] -= other.cols[2];
			return *this;

		}
		inline mat3<Type>& operator*=(const mat3<Type>& other) {

			cols[0] *= other.cols[0];
			cols[1] *= other.cols[1];
			cols[2] *= other.cols[2];
			return *this;

		}
		inline mat3<Type>& operator/=(const mat3<Type>& other) {

			return *this * Inverse(other);

		}

		inline mat3<Type>& operator+=(const Type scalar) {

			cols[0] += scalar;
			cols[1] += scalar;
			cols[2] += scalar;
			return *this;

		}
		inline mat3<Type>& operator-=(const Type scalar) {

			cols[0] -= scalar;
			cols[1] -= scalar;
			cols[2] -= scalar;
			return *this;

		}
		inline mat3<Type>& operator*=(const Type scalar) {

			cols[0] *= scalar;
			cols[1] *= scalar;
			cols[2] *= scalar;
			return *this;

		}
		inline mat3<Type>& operator/=(const Type scalar) {

			cols[0] /= scalar;
			cols[1] /= scalar;
			cols[2] /= scalar;
			return *this;

		}

		//----Comparison Operators----

		inline bool operator==(const mat3<Type>& other) { return cols[0] == other.cols[0] && cols[1] == other.cols[1] && cols[2] == other.cols[2]; }
		inline bool operator!=(const mat3<Type>& other) { return !(*this == other); }

	#ifdef INCLUDE_GLM
		inline bool operator==(const glm::mat<3, 3, Type>& other) { return cols[0] == other[0] && cols[1] == other[1] && cols[2] == other[2]; }
		inline bool operator!=(const glm::mat<3, 3, Type>& other) { return !(*this == other); }

		inline operator glm::mat<3, 3, Type>() const { return glm::mat<3, 3, Type>(cols[0], cols[1], cols[2]); }
	#endif

		//----Increments and Decrements----

		mat3<Type>& operator++() {

			++cols[0];
			++cols[1];
			++cols[2];
			return *this;

		}
		mat3<Type>& operator--() {

			--cols[0];
			--cols[1];
			--cols[2];
			return *this;

		}
		mat3<Type>  operator++(int) {

			mat3<Type> ret = *this;
			++*this;
			return ret;

		}
		mat3<Type>  operator--(int) {

			mat3<Type> ret = *this;
			--*this;
			return ret;

		}

		//----Misc. Operators

		inline mat3<Type> operator-() const { return mat3<Type>(-cols[0], -cols[1], -cols[2]); }
		inline vec3<Type>& operator[](uint32_t index) { return cols[index]; }

	};
	template<typename Type> mat3<Type> Inverse(const mat3<Type>& mat) {

		Type det = Type(1) / (mat.cols[0].x * (mat.cols[1].y * mat.cols[2].z - mat.cols[2].y * mat.cols[1].z) -
							  mat.cols[1].x * (mat.cols[0].y * mat.cols[2].z - mat.cols[2].y * mat.cols[0].z) +
							  mat.cols[2].x * (mat.cols[0].y * mat.cols[1].z - mat.cols[1].y * mat.cols[0].z));

		mat3<Type> ret;
		ret[0].x =  (mat.cols[1].y * mat.cols[2].z - mat.cols[2].y * mat.cols[1].z) * det;
		ret[1].x = -(mat.cols[1].x * mat.cols[2].z - mat.cols[2].x * mat.cols[1].z) * det;
		ret[2].x =  (mat.cols[1].x * mat.cols[2].y - mat.cols[2].x * mat.cols[1].y) * det;

		ret[0].y = -(mat.cols[0].y * mat.cols[2].z - mat.cols[2].y * mat.cols[0].z) * det;
		ret[1].y =  (mat.cols[0].x * mat.cols[2].z - mat.cols[2].x * mat.cols[0].z) * det;
		ret[2].y = -(mat.cols[0].x * mat.cols[2].y - mat.cols[2].x * mat.cols[0].y) * det;

		ret[0].z =  (mat.cols[0].y * mat.cols[1].z - mat.cols[1].y * mat.cols[0].z) * det;
		ret[1].z = -(mat.cols[0].x * mat.cols[1].z - mat.cols[1].x * mat.cols[0].z) * det;
		ret[2].z =  (mat.cols[0].x * mat.cols[1].y - mat.cols[1].x * mat.cols[0].y) * det;

		return ret;

	}

	template<typename Type> mat3<Type> operator+(Type scalar, const mat3<Type>& mat) { return mat3<Type>(mat.cols[0] + scalar, mat.cols[1] + scalar, mat.cols[2] + scalar); }
	template<typename Type> mat3<Type> operator-(Type scalar, const mat3<Type>& mat) { return mat3<Type>(mat.cols[0] - scalar, mat.cols[1] - scalar, mat.cols[2] - scalar); }
	template<typename Type> mat3<Type> operator*(Type scalar, const mat3<Type>& mat) { return mat3<Type>(mat.cols[0] * scalar, mat.cols[1] * scalar, mat.cols[2] * scalar); }

	template<typename Type> vec3<Type> operator*(const vec3<Type>& vec, const mat3<Type>& mat) {

		return vec3<Type>(mat.cols[0].x * vec.x + mat.cols[0].y * vec.y + mat.cols[0].z * vec.z,
						  mat.cols[1].x * vec.x + mat.cols[1].y * vec.y + mat.cols[1].z * vec.z,
						  mat.cols[2].x * vec.x + mat.cols[2].y * vec.y + mat.cols[2].z * vec.z);

	}
	template<typename Type> vec3<Type> operator/(const vec3<Type>& vec, const mat3<Type>& mat) { return vec * Inverse(mat); }
	
	typedef mat3<float> Matrix3;
	typedef mat3<int32_t> Matrix3I;
	typedef mat3<uint32_t> UMatrix3I;

}