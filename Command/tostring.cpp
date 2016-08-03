#include "Tostring.h"

std::string toString0(int x)
{
    std::string st = "";
    if (x == 0)
    {
        st = "0";
    }
    else
    {
        while (x)
        {
            int p = x % 10;
            st = static_cast <char> (p + 48) + st;
            x /= 10;
        }
    }

    return st;
}
