#pragma once

#define StaticMembers(Type) Type Type::zero = Type(Type(0));\
							Type Type::one = Type(Type(1));\
							Type Type::minusOne = Type(Type(-1));

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"