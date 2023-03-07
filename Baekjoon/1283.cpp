#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int INF = 987654321;

int N;
bool alphabet[26] = {false, };

bool isUpper(char A)
{
    return 0 <= A - 'A' && A - 'A' < 26; 
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; ++i)
    {
        string option;
        getline(cin, option);
        bool isFirstChecked = false;
        bool isOtherChecked = false;
        if ((isUpper(option[0]) && !alphabet[option[0] - 'A']))
        {
            alphabet[option[0] - 'A'] = true;
            cout << "[" << option[0] << "]" << option.substr(1) << '\n';
            continue;
        }
        else if(!isUpper(option[0]) && !alphabet[option[0] - 'a'])
        {
            alphabet[option[0] - 'a'] = true;
            cout << "[" << option[0] << "]" << option.substr(1) << '\n';
            continue;
        }
        for(int j = 1; j < option.length(); j++)
        {
            if (option[j] != ' ' && option[j - 1] == ' ')
            { 
                if (isUpper(option[j]) && !alphabet[option[j] - 'A'])
                {
                    alphabet[option[j] - 'A'] = true;
                    cout << option.substr(0, j) << "[" << option[j] << "]" << option.substr(j + 1) << '\n';
                    isFirstChecked = true;
                    break;
                }
                else if(!isUpper(option[j]) && !alphabet[option[j] - 'a'])
                {
                    alphabet[option[j] - 'a'] = true;
                    cout << option.substr(0, j) << "[" << option[j] << "]" << option.substr(j + 1) << '\n';
                    isFirstChecked = true;
                    break;
                }
            }
        }
        if(isFirstChecked)
        {
            continue;
        }
        for(int j = 1; j < option.length(); j++)
        {
            if(option[j] != ' ')
            {
                if(isUpper(option[j]) && !alphabet[option[j] - 'A'])
                {
                    alphabet[option[j] - 'A'] = true;
                    cout << option.substr(0, j) << "[" << option[j] << "]" << option.substr(j + 1) << '\n';
                    isOtherChecked = true;
                    break;
                }
                else if(!isUpper(option[j]) && !alphabet[option[j] - 'a'])
                {
                    alphabet[option[j] - 'a'] = true;
                    cout << option.substr(0, j) << "[" << option[j] << "]" << option.substr(j + 1) << '\n';
                    isOtherChecked = true;
                    break;
                }
            }
        }
        if(!isOtherChecked)
        {
            cout << option << '\n';
        }
    }
    return 0;
}

/*
예외 처리에 좀더 신경썼어야 했는데 그러지 않아 시간이 너무 많이 뺏겼다. 
*/