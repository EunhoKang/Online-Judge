#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int grid[3][3];
int thisturn = 0;

int otherPlayer(int turn)
{
    return turn == 1 ? 2 : 1;
}

int isEnd(int board[3][3])
{
    for(int i = 0; i < 3; ++i)
    {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != 0)
        {
            return board[0][i];
        }
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != 0)
        {
            return board[i][0];
        }
    }
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != 0)
    {
        return board[0][0];
    }
    if(board[2][0] == board[1][1] && board[2][0] == board[0][2] && board[0][2] != 0)
    {
        return board[2][0];
    }
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            if(board[i][j] == 0)
            {
                return -1;
            }
        }
    }
    return 0;
}

int backTrack(int board[3][3], int turn)
{
    int result = isEnd(board);
    if(result == -1)
    {
        int bestRes = 2;
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                if(board[i][j] == 0)
                {
                    board[i][j] = turn;
                    bestRes = min(bestRes, backTrack(board, otherPlayer(turn)));
                    board[i][j] = 0;
                }
            }
        }
        return bestRes == 1 ? -1 : (bestRes == 0 ? 0 : 1);
    }
    return result == 0 ? 0 : (result == turn ? 1 : -1);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 1)
            {
                thisturn--;
            }
            else if(grid[i][j] == 2)
            {
                thisturn++;
            }
        }
    }
    if(thisturn == -1)
    {
        thisturn = 2;
    }
    int answer = backTrack(grid, thisturn);
    if(answer == 0)
    {
        cout << "D";
    }
    else if(answer == -1)
    {
        cout << "L";
    }
    else
    {
        cout << "W";
    }
    return 0;
}

/*
반례가 생각했던 것보다 너무 많았다.
좀 더 일반적인 경우에 대해 생각해보는 연습이 필요하다.
*/