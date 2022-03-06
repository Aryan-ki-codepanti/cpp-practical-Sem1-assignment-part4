#include <iostream>
using namespace std;

class Box
{
    float length, breadth, height;

public:
    friend bool operator==(Box A, Box B);

    Box()
    {
        length = 0;
        breadth = 0;
        height = 0;
    }

    Box(float l, float b, float h)
    {
        length = l;
        breadth = b;
        height = h;
    }

    void printBox()
    {
        cout << "Length : " << length << "units" << endl;
        cout << "Length : " << breadth << "units" << endl;
        cout << "Height: " << height << "units" << endl;
    }

    float surfaceArea()
    {
        return 2 * (length * breadth + breadth * height + height * breadth);
    }

    float volume()
    {
        return length * breadth * height;
    }

    void tellDimension()
    {
        if (length == breadth && breadth == height)
            cout << "Box is cube" << endl;
        else
            cout << "Box is cuboid" << endl;
    }

    // Assignment Operator
    void operator=(Box &B)
    {
        length = B.length;
        breadth = B.breadth;
        height = B.height;
    }

    // Prefix increment
    Box &operator++()
    {
        length++;
        breadth++;
        height++;
        return *this;
    }

    // Postfix increment
    Box operator++(int)
    {
        Box tmp = *this;
        ++*this;
        return tmp;
    }

    // Prefix decrement
    Box &operator--()
    {
        length--;
        breadth--;
        height--;
        return *this;
    }

    // Postfix decrement
    Box operator--(int)
    {
        Box tmp = *this;
        --*this;
        return tmp;
    }
};

// Equality operator
bool operator==(Box A, Box B)
{
    return A.length == B.length && A.breadth == B.breadth && A.height == B.height;
}

int main()
{

    float a, b, c;
    cout << "Enter sides of box" << endl;
    cin >> a >> b >> c;
    char choice;
    Box box = Box(a, b, c);

    while (true)
    {
        cout << "------MENU------" << endl;
        cout << "1.Surface Area" << endl;
        cout << "2.Volume" << endl;
        cout << "3.Is cuboid/cube" << endl;
        cout << "4.Increment box" << endl;
        cout << "5.Decrement box" << endl;
        cout << "6.Assignment box" << endl;
        cout << "7.Check equality of boxes" << endl;
        cout << "8.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == '8')
        {
            cout << "Exiting program..." << endl;
            break;
        }
        else if (choice == '1')
        {
            cout << box.surfaceArea() << " sq units." << endl;
        }
        else if (choice == '2')
        {
            cout << box.volume() << " cu units." << endl;
        }
        else if (choice == '3')
        {
            box.tellDimension();
        }
        else if (choice == '4')
        {
            cout << "Initially" << endl;
            box.printBox();
            box++;
            cout << "After incrementing" << endl;
            box.printBox();
        }
        else if (choice == '5')
        {
            cout << "Initially" << endl;
            box.printBox();
            box--;
            cout << "After decrementing" << endl;
            box.printBox();
        }
        else if (choice == '6')
        {
            Box B;
            B = box;
            cout << "Dimensions of Box B" << endl;
            B.printBox();
        }
        else if (choice == '7')
        {
            cout << "Enter dimensions of other box" << endl;
            cin >> a >> b >> c;
            Box other = Box(a, b, c);
            if (other == box)
                cout << "Boxes are equal" << endl;
            else
                cout << "Boxes are not equal" << endl;
        }
        else
        {
            cout << "Enter a valid  " << endl;
        }
    }

    return 0;
}