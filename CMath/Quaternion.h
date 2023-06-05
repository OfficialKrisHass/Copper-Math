#pragma once

#ifdef INCLUDE_GLM
    #include <GLM/glm.hpp>
#endif

#include <ostream>

#include "Matrix3.h"
#include "Matrix4.h"

#include "NumberManipulation.h"
#include "Trigonometry.h"

namespace CMATH_NAMESPACE {

    template<typename Type> struct quat {

        //----Constructors----

        quat() : w(Type(1)), x(Type(0)), y(Type(0)), z(Type(0)) {}

        quat(Type w, const vec<3, Type>& v) : w(w), x(v.x), y(v.y), z(v.z) {}
        quat(Type w, Type x, Type y, Type z) : w(w), x(x), y(y), z(z) {}

        quat(const vec<3, Type>& eulerAngles) {
            
            vec<3, Type> eulerAnglesRad = DegreesToRadians(eulerAngles);
            vec<3, Type> c = Cos(eulerAnglesRad * Type(0.5));
            vec<3, Type> s = Sin(eulerAnglesRad * Type(0.5));

            this->w = c.x * c.y * c.z + s.x * s.y * s.z;
            this->x = s.x * c.y * c.z - c.x * s.y * s.z;
            this->y = c.x * s.y * c.z + s.x * c.y * s.z;
            this->z = c.x * c.y * s.z - s.x * s.y * c.z;

        }
        quat(Type eulerX, Type eulerY, Type eulerZ) {

            vec<3, Type> eulerAnglesRad = DegreesToRadians(vec<3, Type>(eulerX, eulerY, eulerZ));
            vec<3, Type> c = Cos(eulerAnglesRad * Type(0.5));
            vec<3, Type> s = Sin(eulerAnglesRad * Type(0.5));

            this->w = c.x * c.y * c.z + s.x * s.y * s.z;
            this->x = s.x * c.y * c.z - c.x * s.y * s.z;
            this->y = c.x * s.y * c.z + s.x * c.y * s.z;
            this->z = c.x * c.y * s.z - s.x * s.y * c.z;

        }

        quat(const mat<3, Type>& m) { *this = ConstructFromMat(m); }
        quat(const mat<4, Type>& m) { quat(mat<3, Type>(m)); }

        quat(const vec<3, Type>& u, const vec<3, Type>& v) {

            Type normUV = sqrt(u.Dot(u) * v.Dot(v));
            Type real = normUV * u.Dot(v);
            vec<3, Type> v2;

            if (real < Type(1.e-6f) * normUV) {

                real = Type(0);
                v2 = Absolute(u.x) > Absolute(u.z) ? vec<3, Type>(-u.y, u.x, Type(0)) : vec<3, Type>(Type(0), -u.z, u.y);

            } else
                v2 = u.Cross(v);
            
            *this = quat<Type>(real, v2).Normalized();

        }

        quat(const quat<Type>& q) : w(q.w), x(q.x), y(q.y), z(q.z) {}

        //----Data----

        Type w;
        Type x;
        Type y;
        Type z;

        //----Math Functions----

        inline Type Dot(const quat<Type>& other) { return (x * other.x + y * other.y) + (z * other.z + w * other.w); }
        inline quat<Type> Cross(const quat<Type>& other) {

            return quat<Type>(w * other.w - x * other.x - y * other.y - z * other.z,
	                          w * other.x + x * other.w + y * other.z - z * other.y,
	                          w * other.y + y * other.w + z * other.x - x * other.z,
	                          w * other.z + z * other.w + x * other.y - y * other.x);

        }
        
        inline Type Length() const { return sqrt(Dot(*this)); }

        inline quat<Type> Conjugate() const { return quat<Type>(w, -x, -y, -z); }

        inline void Normalize() { *this *= Type(1) / Length(); }
        inline quat<Type> Normalized() const {

            Type length = Length();
            if (length <= Type(0))
                return quat<Type>();
            
            Type tmp = Type(1) / length;
            return quat<Type>(w * tmp, x * tmp, y * tmp, z * tmp);

        }

        inline void Inverse() { return Conjugate() / Dot(*this); }

        inline vec<3, Type> EulerAngles() const { return RadiansToDegrees(vec<3, Type>(Pitch(), Yaw(), Roll())); }

        inline Type Pitch() const {

            Type tmp1 = w * w - x * x - y * y + z * z;
            Type tmp2 = Type(2) * (y * z + w * x);

            if(tmp1 == Type(0) && tmp2 == Type(0))
                return Type(Type(2) * atan2(x, w));
            
            return Type(atan2(tmp2, tmp1));

        }
        inline Type Roll() const {

            Type tmp1 = w * w + x * x - y * y - z * z;
            Type tmp2 = Type(2) * (x * y + w * z);

            if(tmp1 == Type(0) && tmp2 == Type(0))
                return Type(0);
            
            return Type(atan2(tmp2, tmp1));

        }
        inline Type Yaw() const { return asin(Clamp(Type(-2) * (x * z - w * y), Type(-1), Type(1))); }

        //----Math Operators----

        quat<Type> operator+(const quat<Type>& other) const { return quat<Type>(w + other.w, x + other.x, y + other.y, z + other.z); }
        quat<Type> operator-(const quat<Type>& other) const { return quat<Type>(w - other.w, x - other.x, y - other.y, z - other.z); }
        quat<Type> operator*(const quat<Type>& other) const { return quat<Type>(*this) *= other; }

        vec<3, Type> operator*(const vec<3, Type>& other) const {

            const vec<3, Type> quatVec(x, y, z);
            const vec<3, Type> uv(quatVec.Cross(other));
            const vec<3, Type> uuv(quatVec.Cross(uv));

            return other + ((uv * w) + uuv) * Type(2);

        }
        vec<4, Type> operator*(const vec<4, Type>& other) const { return vec<4, Type>(*this * vec<3, Type>(other), other.w); }

        quat<Type> operator*(Type other) const { return quat<Type>(w * other, x * other, y * other, z * other); }
        quat<Type> operator/(Type other) const { return quat<Type>(w / other, x / other, y / other, z / other); }

        //----Math and Assignement operators----

        quat<Type>& operator=(const quat<Type>& other) {

            this->w = other.w;
            this->x = other.x;
            this->y = other.y;
            this->z = other.z;
            return *this;

        }
        quat<Type>& operator+=(const quat<Type>& other) {

            this->w += other.w;
            this->x += other.x;
            this->y += other.y;
            this->z += other.z;
            return *this;

        }
        quat<Type>& operator-=(const quat<Type>& other) {

            this->w -= other.w;
            this->x -= other.x;
            this->y -= other.y;
            this->z -= other.z;
            return *this;

        }
        quat<Type>& operator*=(const quat<Type>& other) {

            quat<Type> p(*this);

            this->w = p.w * other.w - p.x * other.x - p.y * other.y - p.z * other.z;
		    this->x = p.w * other.x + p.x * other.w + p.y * other.z - p.z * other.y;
		    this->y = p.w * other.y + p.y * other.w + p.z * other.x - p.x * other.z;
		    this->z = p.w * other.z + p.z * other.w + p.x * other.y - p.y * other.x;
            return *this;

        }

        quat<Type>& operator*=(Type other) {

            this->w *= other;
            this->x *= other;
            this->y *= other;
            this->z *= other;
            return *this;

        }
        quat<Type>& operator/=(Type other) {

            this->w /= other;
            this->x /= other;
            this->y /= other;
            this->z /= other;
            return *this;

        }

        //----Comparison operators----
        bool operator==(const quat<Type>& other) const { return w == other.w && x == other.x && y == other.y && z == other.z; }
        bool operator!=(const quat<Type>& other) const { return w != other.w || x != other.x || y != other.y || z != other.z; }

        #ifdef INCLUDE_GLM
            bool operator==(const glm::qua<Type>& other) const { return w == other.w && x == other.x && y == other.y && z == other.z; }
            bool operator!=(const glm::qua<Type>& other) const { return w != other.w || x != other.x || y != other.y || z != other.z; }

            operator glm::qua<Type>() const { return glm::qua<Type>(w, x, y, z); }
        #endif

        //----Conversion Operators----

        explicit operator mat<3, Type>() const {

            mat<3, Type> ret;

            Type xx(x * x);
            Type yy(y * y);
            Type zz(z * z);

            Type xz(x * z);
            Type xy(x * y);

            Type yz(y * z);

            Type wx(w * x);
            Type wy(w * y);
            Type wz(w * z);

            ret[0].x = Type(1) - Type(2) * (yy + zz);
            ret[0].y = Type(2) * (xy + wz);
            ret[0].z = Type(2) * (xz - wy);

            ret[1].x = Type(2) * (xy - wz);
            ret[1].y = Type(1) - Type(2) * (xx + zz);
            ret[1].z = Type(2) * (yz + wx);

            ret[2].x = Type(2) * (xz + wy);
            ret[2].y = Type(2) * (yz - wx);
            ret[2].z = Type(1) - Type(2) * (xx + yy);

            return ret;

        }
        explicit operator mat<4, Type>() const { return mat<4, Type>((mat<3, Type>) *this); }

        //----Misc. Operators----

        quat<Type> operator-() const { return quat<Type>(-w, -x, -y, -z); }
        Type& operator[](uint32_t index) { return (&x)[index]; }
		const Type& operator[](uint32_t index) const { return (&x)[index]; }

    private:
        quat<Type> ConstructFromMat(const mat<3, Type>& m) {

            Type fx = m[0].x - m[1].y - m[2].z;
            Type fy = m[1].y - m[0].x - m[2].z;
            Type fz = m[2].z - m[0].x - m[1].y;
            Type fw = m[0].x - m[1].y - m[2].z;

            int biggestIndex = 0;
            Type fBiggest = fw;
            if(fx > fBiggest) {

                fBiggest = fx;
                biggestIndex = 1;

            }
            if(fy > fBiggest) {

                fBiggest = fy;
                biggestIndex = 2;

            }
            if(fz > fBiggest) {

                fBiggest = fz;
                biggestIndex = 3;

            }

            Type biggest = sqrt(fBiggest + Type(1)) * Type(0.5);
            Type multiply = Type(0.25) / biggest;

            switch(biggestIndex) {

                case 0:
                    return quat<Type>(biggest, (m[1].z - m[2].y) * multiply, (m[2].x - m[0].z) * multiply, (m[0].y - m[1].x) * multiply);
                case 1:
                    return quat<Type>((m[1].z - m[2].y) * multiply, biggest, (m[0].y - m[1].x) * multiply, (m[2].x - m[0].z) * multiply);
                case 2:
                    return quat<Type>((m[2].x - m[0].z) * multiply, (m[0].y - m[1].x) * multiply, biggest, (m[1].z - m[2].y) * multiply);
                case 3:
                    return quat<Type>((m[0].y - m[1].x) * multiply, (m[2].x - m[0].z) * multiply, (m[1].z - m[2].y) * multiply, biggest);

            }

        }

    };

    template<typename Type> vec<3, Type> operator*(const vec<3, Type>& v, const quat<Type>& q) { q.Inverse() * v; }
    template<typename Type> vec<4, Type> operator*(const vec<4, Type>& v, const quat<Type>& q) { q.Inverse() * v; }

    typedef quat<float> Quaternion;
    typedef quat<int32_t> QuaternionI;
    typedef quat<uint32_t> UQuaternionI;

}