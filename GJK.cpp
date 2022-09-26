#include "GJK.h"

vec2 vec2::operator-(vec2& other)
{
    return vec2(x - other.x, y - other.y);
}

vec2::vec2(float x, float y)
{
    this->x = x;
    this->y = y;
}

vec2 vec2::perpendicular()
{
    return vec2(y, -x);
}

float vec2::dotProduct(vec2& first, vec2& second)
{
    return first.x * second.x + first.y * second.y;
}

float vec2::lengthSquared()
{
    return x * x + y * y;
}

vec2 vec2::tripleProduct(vec2& a, vec2& b, vec2& c)
{
    vec2 r;

    float ac = a.x * c.x + a.y * c.y; // perform a.dot(c)
    float bc = b.x * c.x + b.y * c.y; // perform b.dot(c)

    // perform b * a.dot(c) - a * b.dot(c)
    r.x = b.x * ac - a.x * bc;
    r.y = b.y * ac - a.y * bc;
    return r;
}

vec2 vec2::averagePoint(std::vector <vec2> shape)
{
    vec2 avg(0, 0);
    for (auto el : shape)
    {
        avg.x += el.x;
        avg.y += el.y;

    }
    avg.x = avg.x / shape.size();
    avg.y = avg.y / shape.size();
    return avg;
}

int vec2::indexOfFurthestPoint(std::vector<vec2> shape, vec2 d)
{
    float maxProduct = dotProduct(d, shape[0]);
    size_t index = 0;
    for (size_t i = 1; i < shape.size(); i++) {
        float product = dotProduct(d, shape[i]);
        if (product > maxProduct) {
            maxProduct = product;
            index = i;
        }
    }
    return index;
}

vec2 vec2::support(std::vector<vec2> shape1, std::vector<vec2> shape2, vec2 d)
{
    // get furthest point of first body along an arbitrary direction
    size_t i = indexOfFurthestPoint(shape1, d);

    // get furthest point of second body along the opposite direction
    size_t j = indexOfFurthestPoint(shape2, -d);

    // subtract (Minkowski sum) the two points to see if bodies 'overlap'
    return shape1[i] - shape2[j];
}

bool vec2::gjk(std::vector<vec2> shape1, std::vector<vec2> shape2)
{
    int iter_count = 0;
    size_t index = 0; // index of current vertex of simplex
    vec2 a, b, c, d, ao, ab, ac, abperp, acperp, simplex[3];

    vec2 position1 = averagePoint(shape1); // not a CoG but
    vec2 position2 = averagePoint(shape2); // it's ok for GJK )

    // initial direction from the center of 1st body to the center of 2nd body
    d = position1 - position2;

    // if initial direction is zero – set it to any arbitrary axis (we choose X)
    if ((d.x == 0) && (d.y == 0))
        d.x = 1.f;

    // set the first support as initial point of the new simplex
    a = simplex[0] = support(shape1, shape2, d);

    if (dotProduct(a, d) <= 0)
        return 0; // no collision

    d = -a; // The next search direction is always towards the origin, so the next search direction is negate(a)

    while (1) {
        iter_count++;

        a = simplex[++index] = support(shape1, shape2, d);

        if (dotProduct(a, d) <= 0)
            return 0; // no collision

        ao = -a; // from point A to Origin is just negative A

        // simplex has 2 points (a line segment, not a triangle yet)
        if (index < 2) {
            b = simplex[0];
            ab = b - a; // from point A to B
            d = tripleProduct(ab, ao, ab); // normal to AB towards Origin
            if (d.lengthSquared() == 0)
                d = ab.perpendicular();
            continue; // skip to next iteration
        }

        b = simplex[1];
        c = simplex[0];
        ab = b - a; // from point A to B
        ac = c - a; // from point A to C

        acperp = tripleProduct(ab, ac, ac);

        if (dotProduct(acperp, ao) >= 0) {

            d = acperp; // new direction is normal to AC towards Origin

        }
        else {

            abperp = tripleProduct(ac, ab, ab);

            if (dotProduct(abperp, ao) < 0)
                return 1; // collision

            simplex[0] = simplex[1]; // swap first element (point C)

            d = abperp; // new direction is normal to AB towards Origin
        }

        simplex[1] = simplex[2]; // swap element in the middle (point B)
        --index;
    }

    return 0;

}

vec2 operator-(vec2& other)
{
    return vec2(-other.x, -other.y);
}

