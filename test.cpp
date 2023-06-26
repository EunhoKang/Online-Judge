#include <iostream>
#include <vector>
#include <sstream>

using namespace std;
const int INF = 2087654321;

vector<string> split(string str, char delimiter)
{
    vector<string> internal;
    stringstream ss(str);
    string temp;
    while (getline(ss, temp, delimiter))
        internal.push_back(temp);
    return internal;
}

int rule1index = -1;

bool rule1(vector<string> v)
{
    for(int i = 0; i < v.size(); ++i)
    {
        if(v[i] == "dip")
        {
            if(!(i + 1 < v.size() && v[i + 1] == "twirl") && !(i - 2 >=  0 && v[i - 2] == "jiggle") && !(i - 1 >= 0 && v[i - 1] == "jiggle"))
            {
                rule1index = i;
                return false;
            }
        }
    }
    return true;
}

bool rule2(vector<string> v)
{
    int end = v.size() - 1;
    return end > 1 && v[end - 2] == "clap" && v[end - 1] == "stomp" && v[end] == "clap";
}

bool rule3(vector<string> v)
{
    bool twirl = false;
    bool hop = false;
    for(auto step : v)
    {
        if(step == "twirl")
        {
            twirl = true;
        }
        else if(step == "hop")
        {
            hop = true;
        }
    }
    return !twirl || hop;    
}

bool rule4(vector<string> v)
{
    int end = v.size() - 1;
    return end >= 0 && v[0] != "jiggle";
}

bool rule5(vector<string> v)
{
    for(auto step : v)
    {
        if(step == "dip")
        {
            return true;
        }
    }
    return false;
}



int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string str;
    while(getline(cin, str))
    {
        if(str == "")break;
        rule1index = -1;
        vector<string> v = split(str, ' ');
        vector<int> errors;
        if(!rule1(v))
        {
            errors.push_back(1);
        }
        if(!rule2(v))
        {
            errors.push_back(2);
        }
        if(!rule3(v))
        {
            errors.push_back(3);
        }
        if(!rule4(v))
        {
            errors.push_back(4);
        }
        if(!rule5(v))
        {
            errors.push_back(5);
        }
        if(rule1index != -1)
        {
            v[rule1index] = "DIP";
        }
        cout << "form ";
        if(errors.size() == 0)
        {
            cout << "ok: ";
        }
        else
        {
            if(errors.size() > 1)
            {
                cout << "errors ";
            }
            else
            {
                cout << "error ";
            }
            for(int i = 0; i < errors.size(); i++)
            {
                if(i == errors.size() - 1 && errors.size() > 1)
                {
                    cout << "and ";
                }
                cout << errors[i];
                if(i < errors.size() - 1)
                {
                    if(errors.size() > 2 && i < errors.size() - 2)
                    {
                        cout << ", ";
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
            cout << ": ";
        }
        for(auto s : v)
        {
            cout << s << " ";
        }
        cout << '\n';
    }
    return 0;
}