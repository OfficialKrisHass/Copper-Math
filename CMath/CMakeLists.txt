list(APPEND CMathSources CMath.h Matrix3.h Matrix4.h MatrixTransform.h MatrixViewAndProjection.h NumberManipulation.h Quaternion.h Random.h Trigonometry.h Vector2.h
                         Vector3.h Vector4.h Vectors.h)
list(TRANSFORM CMathSources PREPEND CMath/)