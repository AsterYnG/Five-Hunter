#pragma once
#include <vector>
struct vec2
{
	float x, y;
	vec2 operator -(vec2& other);
	vec2(float x = 0, float y = 0);
	friend vec2 operator-(vec2& other);

	vec2 perpendicular();
	static float dotProduct(vec2& first, vec2& second);
	float lengthSquared();
	static vec2 tripleProduct(vec2& a, vec2& b, vec2& c);
	static vec2 averagePoint(std::vector <vec2> shape);
	static int indexOfFurthestPoint(std::vector <vec2> shape, vec2 d);
	static vec2 support(std::vector <vec2> shape1, std::vector <vec2> shape2, vec2 d);
	static bool gjk(std::vector <vec2> shape1, std::vector <vec2> shape2);
};

