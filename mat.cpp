#include "mat.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;

namespace ariel
{

    string mat(int cols, int rows, char ch1, char ch2)
    {
        if (cols % 2 == 0 || rows % 2 == 0 || cols < 0 || rows < 0)
        {
            throw invalid_argument("invalid_argument");
        }

        char **arr = new char *[rows];
        for (int i = 0; i < rows; ++i)
        {
            arr[i] = new char[cols];
        }

        int enter = min(cols, rows)/2;
        char currCh = ch1;
        for (size_t i = 0; i <= enter; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                arr[i][j] = currCh;
                arr[rows - 1 - i][j] = currCh;
            }

            for (size_t j = 0; j < rows; j++)
            {
                arr[j][i] = currCh;
                arr[j][cols - 1 - i] = currCh;
            }
            currCh = (currCh == ch1) ? ch2 : ch1;
        }
        string ans = "";
        for (int i = 0; i < rows; i++)
        {
            ans+="\n";
            for (int j = 0; j < cols; j++)
            {
                ans += arr[i][j];
            }
        }

        return ans;
    }
}
