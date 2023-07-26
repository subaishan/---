//- [P1601 A+B Problem（高精）](https://www.luogu.com.cn/problem/P1601)

#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int* get_num(string num)
{
	int len = num.length();
	int* s = new int[len + 1];
	s[0] = len;
	for (int i = 1; i <= len; i++)
	{
		s[i] = num[len - i] - 48;
	}

	return s;
}

int* get_c(int* nums1, int* nums2)
{
	int u = 0;
	int v = 0;
	int l = 0;
	int* ans = new int[100];
	for (int i = 0; i < 100; i++) ans[i] = 0;

	for (int i = 1; i <= nums1[0]; i++)
	{
		u = 0;
		for (int j = 1; j <= nums2[0]; j++)
		{
			v = nums1[i] * nums2[j] + u + ans[i + j - 1];
			ans[i + j - 1] = v % 10;
			u = v / 10;
		}
		l = i + nums2[0];
		while (u)
		{
			ans[l] = u % 10;
			u /= 10;
			l++;
		}
	}
	ans[0] = nums1[0] + nums2[0] + 5;
	while (ans[0] > 1 && ans[ans[0]] == 0)
		ans[0]--;

	return ans;
}

void get_j(int* ans, int* nums1)
{
	int len = nums1[0];
	int u = 0;
	int v = 0;
	int l = 0;
	for (int i = 1; i <= nums1[0]; i++)
	{
		v = nums1[i] + ans[i] + u;
		ans[i] = v % 10;
		u = v / 10;
	}
	l = nums1[0] + 1;
	while (u)
	{
		ans[l] = u;
		u = ans[l] / 10;
	}

	ans[0] = max(ans[0], nums1[0]) + 1;
	while (ans[0] > 1 && ans[ans[0]] == 0)
		ans[0]--;

}

void prin(int* arr)
{
	for (int i = arr[0]; i > 0; i--)
		cout << arr[i];
	cout << endl;
}

int main()
{
	int num;
	string str, s1;
	int* pc;
	int* sc = new int[100];
	int* ans = new int[100];
	for (int i = 0; i < 100; i++)
	{
		sc[i] = 1;
		ans[i] = 0;
	}
	cin >> num;

	if (num == 1)
	{
		cout << 1;
		return 0;
	}

	for (int i = 1; i <= num; i++)
	{
		for (int i = 0; i < 100; i++) sc[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			str = to_string(j);
			pc = get_c(sc, get_num(str));
			sc = pc;
		}
		get_j(ans, sc);
	}
	prin(ans);
}
