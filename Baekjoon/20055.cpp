#include <iostream>
using namespace std;

int duration[200];
bool isRobot[200];
int up, down;
int n, k, brokenBelt;

void circulate()
{
    up = (up - 1 + 2 * n) % (2 * n);
    down = (down - 1 + 2 * n) % (2 * n);
    if(isRobot[down]) 
    {
        isRobot[down] = false;
    }
}

void moveRobot()
{
    for(int i = (down - 1 + 2 * n) % (2 * n); i != (up - 1 + 2 * n) % (2 * n); i = (i - 1 + 2 * n) % (2 * n))
    {
        int j = (i + 1) % (2 * n);
        if(isRobot[i] && !isRobot[j] && duration[j] > 0)
        {
            duration[j] --;
            if(duration[j] == 0)
            {
                brokenBelt ++;
            }
            isRobot[j] = true;
            isRobot[i] = false;
            if(j == down)
            {
                isRobot[down] = false;
            }
        }
    }
}

void setRobot()
{
    if(!isRobot[up] && duration[up] > 0)
    {
        isRobot[up] = true;
        duration[up] --;
        if(duration[up] == 0)
        {
            brokenBelt ++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < 2 * n; i++) 
    {
        cin >> duration[i];
    }
    up = 0;
    down = n - 1;
    brokenBelt = 0;
    int cnt = 0;
    do
    {
        circulate();
        moveRobot();
        setRobot();
        cnt ++;
    }while(brokenBelt < k);
    cout << cnt;
    return 0;
}