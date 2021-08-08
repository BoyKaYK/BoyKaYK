#include "print.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void print(int matx[10][10],int n ,int n1) {
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n1; j++)
        {
            cout << matx[i][j] << " ";

        }
        cout << endl;
    }
}



