#pragma once

#ifndef CMATH_PARENT_NAMESPACE
#define CMATH_NAMESPACE CMath
#else
#define CMATH_NAMESPACE CMATH_PARENT_NAMESPACE::CMath
#endif

//Forward declarations

namespace CMATH_NAMESPACE {

    template<unsigned int N, typename Type> struct mat;
    template<unsigned int N, typename Type> struct vec;

}

//Functions

#include "Trigonometry.h"
#include "Random.h"
#include "NumberManipulation.h"

//Vectors

#include "Vectors.h"

//Quaternions

#include "Quaternion.h"

//Matrices
#include "Matrix3.h"
#include "Matrix4.h"

#include "MatrixTransform.h"
#include "MatrixViewAndProjection.h"