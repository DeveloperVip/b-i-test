#include <iostream>
#include <stack>
using namespace std;

string nhap(string a)
{
    int n = 1;
    stack<char> c;
    string b = "";
    int i = 0;
    while (cin >> a[i])
    {
        c.push(a[i]);
        i++;
    }
    char temp1;
    while (!c.empty())
    {
        char temp = c.top();
        if (temp == temp1)
        {
            n++;
                }
        else
        {
            b = temp + to_string(n) + b;
            n = 1;
        }
        temp1 = temp;
        c.pop();
    }
    return b;
}

int main()
{
    string c;
    cout << nhap(c);
    return 0;
}