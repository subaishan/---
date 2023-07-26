//- [P1601 A+B Problem（高精）](https://www.luogu.com.cn/problem/P1601)

#include<iostream>
#include<math.h>
using namespace std;
int s1[505] = { 0 };
int s2[505] = { 0 };
int c[505] = { 0 };

void get_num(string num, int* n)
{
    int len = num.length();
    for (int i = len; i > 0; i--)
        n[i] = num[len - i] - 48;
    n[0] = len;
}

int main()
{
    string a, b;
    cin >> a >> b;

    get_num(a, s1);
    get_num(b, s2);

    int len = max(s1[0], s2[0]);
    for (int i = 1; i <= len; i++)
    {
        c[i] = s1[i] + s2[i] + c[i];
        if (c[i] >= 10)
        {
            c[i] = c[i] % 10;
            c[i + 1]++;
        }
    }
    c[0] = len;
    if (c[len + 1] > 0) c[0]++;

    for (int i = c[0]; i > 0; i--)
        cout << c[i];
}
