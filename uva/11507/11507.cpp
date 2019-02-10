// Problem definition: https://uva.onlinejudge.org/external/115/11507.pdf
// Accepted 

#include <iostream>
#include <string>

struct Vector
{
    int x;
    int y;
    int z;

    Vector(int inX, int inY, int inZ) : x{inX}, y{inY}, z{inZ} {}
};

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    if (v.x == 1 && v.y == 0 && v.z == 0)
    {
        return os << "+x";
    }
    else if (v.x ==-1 && v.y == 0 && v.z == 0)
    {
        return os << "-x";
    }
    else if (v.x == 0 && v.y == 1 && v.z == 0)
    {
        return os << "+y";
    }
    else if (v.x == 0 && v.y == -1 && v.z == 0)
    {
        return os << "-y";
    }
    else if (v.x == 0 && v.y == 0 && v.z == 1)
    {
        return os << "+z";
    }
    else
    {
        return os << "-z";
    }
}

void Rotate(const std::string& s, Vector& v)
{
    if (s == "+y")
    {
        if (v.x == 1)
        {
            v.x = 0;
            v.y = 1;
        }
        else if (v.y == 1)
        {
            v.y = 0;
            v.x = -1;
        }
        else if (v.x == -1)
        {
            v.x = 0;
            v.y = -1;
        }
        else if (v.y == -1)
        {
            v.x = 1;
            v.y = 0;
        }
    }
    else if (s == "-y")
    {
        if (v.x == 1)
        {
            v.x = 0;
            v.y = -1;
        }
        else if (v.y == 1)
        {
            v.y = 1;
            v.x = 0;
        }
        else if (v.x == -1)
        {
            v.x = 0;
            v.y = 1;
        }
        else if (v.y == -1)
        {
            v.x = -1;
            v.y = 0;
        }
    }
    else if (s == "+z")
    {
        if (v.x == 1)
        {
            v.x = 0;
            v.z = 1;
        }
        else if (v.x == -1)
        {
            v.x = 0;
            v.z = -1;
        }
        else if (v.z == 1)
        {
            v.x = -1;
            v.z = 0;
        }
        else if (v.z == -1)
        {
            v.x = 1;
            v.z = 0;
        }
    }
    else if (s == "-z")
    {
        if (v.x == 1)
        {
            v.x = 0;
            v.z = -1;
        }
        else if (v.x == -1)
        {
            v.x = 0;
            v.z = 1;
        }
        else if (v.z == 1)
        {
            v.x = 1;
            v.z = 0;
        }
        else if (v.z == -1)
        {
            v.x = -1;
            v.z = 0;
        }
    }
    else
    {
        // s == "No"
    }    
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    int length {0};

    while (std::cin >> length && length != 0)
    {
        Vector v{1,0,0};
        std::string move;
        while (--length)
        {
            std::cin >> move;
            Rotate(move, v);
        }

        std::cout << v << "\n";
    }
}
