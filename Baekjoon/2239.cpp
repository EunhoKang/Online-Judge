#include <bits/stdc++.h>
using namespace std;
const int INF = 2087654321;

int grid[9][9];
bool row[9][10];
bool column[9][10];
bool cube[3][3][10];

bool sudoku(int i, int j)
{
    if(i == 9)
    {
        for(int i = 0; i < 9; ++i)
        {
            for(int j = 0; j < 9; ++j)
            {
                cout << grid[i][j];
            }
            cout << '\n';
        }
        return true;
    }
    if(grid[i][j] == 0)
    {
        for(int k = 1; k < 10; ++k)
        {
            if(!(row[i][k] || column[j][k] || cube[i / 3][j / 3][k]))
            {
                grid[i][j] = k;
                row[i][k] = true;
                column[j][k] = true;
                cube[i / 3][j / 3][k] = true;
                if(sudoku(j == 8 ? i + 1 : i, j == 8 ? 0 : j + 1))
                {
                    return true;
                }
                grid[i][j] = 0;
                row[i][k] = false;
                column[j][k] = false;
                cube[i / 3][j / 3][k] = false;
            }
        }
    }
    else
    {
        return sudoku(j == 8 ? i + 1 : i, j == 8 ? 0 : j + 1);
    }
    return false;
}

int main()
{
    for(int i = 0; i < 9; ++i)
    {
        string line;
        cin >> line;
        for(int j = 0; j < 9; ++j)
        {
            grid[i][j] = line[j] - '0';
            row[i][grid[i][j]] = true;
            column[j][grid[i][j]] = true;
            cube[i / 3][j / 3][grid[i][j]] = true;
        }
    }
    sudoku(0, 0);
}

/*
탐색 중단 조건을 잘 둘것.

*/