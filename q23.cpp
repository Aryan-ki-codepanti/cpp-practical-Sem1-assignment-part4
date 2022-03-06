#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{
    float a, b, c, base, height;

public:
    Triangle()
    {
        a = 0;
        b = 0;
        c = 0;
        base = 0;
        height = 0;
    }
    Triangle(float x, float y, float z)
    {
        a = x;
        b = y;
        c = z;
        base = 0;
        height = 0;
    }
    Triangle(float m, float n)
    {
        base = m;
        height = n;
        a = 0;
        b = 0;
        c = 0;
    }

    float area()
    {
        if (a == 0 && base == 0)
            return 0;

        float areaTriangle;
        if (a == 0)
            areaTriangle = 0.5 * base * height;
        else
        {
            float s = (a + b + c) / 2.0;
            areaTriangle = sqrt(s * (s - a) * (s - b) * (s - c));
        }
        return areaTriangle;
    }

    bool operator==(Triangle T)
    {
        return a == T.a && b == T.b && c == T.c && base == T.base && height == T.height;
    }

    void operator=(Triangle &T)
    {
        a = T.a;
        b = T.b;
        c = T.c;
        base = T.base;
        height = T.height;
    }
};

int main()
{
    Triangle a(4, 3), b(6, 4, 8);
    cout << "Area of a : " << a.area() << " sq.units" << endl;
    cout << "Area of b : " << b.area() << " sq.units" << endl;

    // Assignment operator
    Triangle c = b;
    cout << "Area of c : " << c.area() << " sq.units" << endl;
    // Equality operator
    if (c == b)
        cout << "Triangles C and B are equal" << endl;
    else
        cout << "Triangles C and B are not equal" << endl;
    return 0;
}