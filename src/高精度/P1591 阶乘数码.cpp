
//- [P1591 阶乘数码](https://www.luogu.com.cn/problem/P1591)

#include<iostream>
#include<string>
using namespace std;
int nums[10];
int sum[3000];

void get_num(int num)
{
	string str = to_string(num);
	int len = str.length();
	nums[0] = len;
	for (int i = len; i > 0; i--)
		nums[i] = str[len - i] - 48;
}

void get_c(int* a, int* nums2)
{
	int nums1[3000];
	int ans[3000];
	for (int i = 0; i < 3000; i++)
	{
		nums1[i] = a[i];
		ans[i] = 0;
	}

	int u = 0;
	int v = 0;
	int l = 0;

	for (int i = 1; i <= nums1[0]; i++)
	{
		u = 0;
		for (int j = 1; j <= nums2[0]; j++)
		{
			v = nums1[i] * nums2[j] + ans[i + j - 1] + u;
			ans[i + j - 1] = v % 10;
			u = v / 10;
		}
		l = nums2[0] + i;
		while (u)
		{
			ans[l] = u % 10;
			u /= 10;
		}
	}

	ans[0] = nums1[0] + nums2[0] + 5;
	while (ans[ans[0]] == 0 && ans[0] > 0) 
		ans[0]--;

	for (int i = 0; i <= ans[0]; i++) sum[i] = ans[i];
}

int main()
{
	int n;
	cin >> n;
	int a, b;
	int s = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		sum[0] = sum[1] = 1;
		s = 0;
		for (int i = 2; i < 500; i++) sum[i] = 0;
		for (int i = 2; i <= a; i++)
		{
			get_num(i);
			get_c(sum, nums);
		}
		
		for (int i = 1; i <= sum[0]; i++)
			if (sum[i] == b) s++;
		cout << s << endl;
	}
}
