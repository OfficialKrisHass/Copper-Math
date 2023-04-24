#pragma once

#include "Matrix.h"
#include "Trigonometry.h"

namespace CMATH_NAMESPACE {

	template<typename T> inline mat4<T> ViewMatrix(const vec3<T>& pos, const vec3<T>& forward, const vec3<T>& up) {

		vec3<T> f(forward.Normalized());
		vec3<T> s((f.Cross(up)).Normalized());
		vec3<T> u(s.Cross(f));

		mat4<T> ret;

		ret[0].x =  s.x;
		ret[1].x =  s.y;
		ret[2].x =  s.z;
		ret[0].y =  u.x;
		ret[1].y =  u.y;
		ret[2].y =  u.z;
		ret[0].z = -f.x;
		ret[1].z = -f.y;
		ret[2].z = -f.z;

		ret[3].x = -s.Dot(pos);
		ret[3].y = -u.Dot(pos);
		ret[3].z =  f.Dot(pos);

		return ret;

	}
	template<typename T> inline mat4<T> ProjectionMatrix(T fov, T aspectRatio, T nearPlane, T farPlane) {

		T tanHalfFov = Tan(fov / T(2));
		mat4<T> ret(T(0));

		ret[0].x =  T(1) / (aspectRatio / tanHalfFov);
		ret[1].y =  T(1) / tanHalfFov;
		ret[2].z = -(farPlane + nearPlane) / (farPlane - nearPlane);
		ret[2].w =  T(-1);
		ret[3].z = -(T(2) * farPlane * nearPlane) / (farPlane - nearPlane);

		return ret;

	}

}