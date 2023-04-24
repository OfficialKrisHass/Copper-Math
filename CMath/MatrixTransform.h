#pragma once

#include "Matrix.h"
#include "Trigonometry.h"

namespace CMATH_NAMESPACE {

	/*
	* Translates the matrix specified by the position represented as a Vector3.
	* @param mat - the Matrix you want to translate. This function does modify the matrix.
	* @param vec - the Position represented as a Vector3 that you want to translate mat with.
	*/
	template<typename T> inline void TranslateMatrix(mat4<T>& mat, const vec3<T>& vec) {

		mat.cols[3] = mat.cols[0] * vec.x + mat.cols[1] * vec.y + mat.cols[2] * vec.z + mat.cols[3];

	}

	/*
	* Rotate the matrix specified around the axis specified by an angle in Degrees
	* @param mat - The Matrix you want to rotate. This function does modify the matrix.
	* @param axisToRotate - The Axis you want to rotate mat around, specified as an Vector3.
	* @param angle - The Angle you want to rotate mat around axisToRotate. The angle needs to be in degrees.
	*/
	template<typename T> inline void RotateMatrix(mat4<T>& mat, const vec3<T>& axisToRotate, T angle) {

		angle = DegreesToRadians(angle);
		T cos = Cos(angle);
		T sin = Sin(angle);

		vec3<T> axis = axisToRotate.Normalized();
		vec3<T> tmp((T(1) - cos) * axis);

		mat4<T> rotationMat(0.0f);
		rotationMat[0].x = cos + tmp.x * axis.x;
		rotationMat[0].y = tmp.x * axis.y + sin * axis.z;
		rotationMat[0].z = tmp.x * axis.z - sin * axis.y;

		rotationMat[1].x = tmp.y * axis.x - sin * axis.z;
		rotationMat[1].y = cos + tmp.y * axis.y;
		rotationMat[1].z = tmp.y * axis.z + sin * axis.x;

		rotationMat[2].x = tmp.z * axis.x + sin * axis.y;
		rotationMat[2].y = tmp.z * axis.y - sin * axis.x;
		rotationMat[2].z = cos + tmp.z * axis.z;

		mat4<T> final;
		final[0] = mat[0] * rotationMat[0].x + mat[1] * rotationMat[0].y + mat[2] * rotationMat[0].z;
		final[1] = mat[0] * rotationMat[1].x + mat[1] * rotationMat[1].y + mat[2] * rotationMat[1].z;
		final[2] = mat[0] * rotationMat[2].x + mat[1] * rotationMat[2].y + mat[2] * rotationMat[2].z;

		mat[0] = final[0];
		mat[1] = final[1];
		mat[2] = final[2];

	}

	/*
	* Scales the Matrix specified by the Vector3 specified.
	* @param mat - The Matrix you want to scale. This function does modify the matrix.
	* @param scale - the scale factor.
	*/
	template<typename T> inline void ScaleMatrix(mat4<T>& mat, const vec3<T>& scale) {

		mat[0] *= scale.x;
		mat[1] *= scale.y;
		mat[2] *= scale.z;

	}
	

}