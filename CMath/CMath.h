#pragma once

#ifndef CMATH_PARENT_NAMESPACE
#define CMATH_NAMESPACE CMath
#else
#define CMATH_NAMESPACE CMATH_PARENT_NAMESPACE::CMath
#endif

//Functions

#include "Trigonometry.h"
#include "Random.h"
#include "NumberManipulation.h"

//Vectors

#include "Vectors.h"

//Matrices

#include "Matrix3.h"
#include "Matrix4.h"

#include "MatrixTransform.h"
#include "MatrixViewAndProjection.h"