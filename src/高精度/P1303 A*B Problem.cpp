// [P1303 A*B Problem](https://www.luogu.com.cn/problem/P1303)

#include<iostream>
#include<string>
using namespace std;
int s1[2100] = { 0 };
int s2[2100] = { 0 };
int ans[2500] = { 0 };

void get_num(string str, int* nums)
{
    int len = str.length();
    for (int i = len; i > 0; i--)
        nums[i] = str[len - i] - 48;
    nums[0] = len;
}

void get_n(int* nums1, int* nums2)
{
    int u = 0;
    int v = 0;
    int l = 0;

    for (int i = 1; i <= nums1[0]; i++)
    {
        u = 0;
        for (int j = 1; j <= nums2[0]; j++)
        {
              u = nums1[i] * nums2[j] + v + ans[i + j - 1];
              ans[i + j - 1] = u % 10;
              v = u / 10;
        }
        l = i + nums2[0];
        while (v)
        {
            ans[l] = v % 10;
            v /= 10;
            l++;
        }
    }

    ans[0] = nums1[0] + nums2[0] + 5;
    while (ans[ans[0]] == 0 && ans[0] > 0)
    {
        ans[0]--;
    }
}

int main()
{
    string a, b;
    cin >> a >> b;

    get_num(a, s1);
    get_num(b, s2);
    if (a == "0" || b == "0")
    {
        cout << 0;
        return 0;
    }

    get_n(s1, s2);

    for (int i = ans[0]; i > 0; i--)
        cout << ans[i];
}
