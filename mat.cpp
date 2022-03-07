#include "mat.hpp"
#include <iostream>

using namespace std;
namespace ariel
{
    string mat(int cols, int rows, char ch1, char ch2)
    {
<<<<<<< HEAD
        string ans = " ";
=======
        string ans = "";
>>>>>>> f
        for (size_t i = 0; i < rows; i++)
        {
            ans.append("\n");
            for (size_t j = 0; j < cols; j++)
            {
                ans += ch1;
            }
        }
        return ans;
    }
}
