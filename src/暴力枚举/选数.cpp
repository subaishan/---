//- [P1036 [NOIP2002 普及组] 选数](https://www.luogu.com.cn/problem/P1036)

#include<iostream>
#include<math.h>
using namespace std;
int dat[20], used[20];
int n, m, sum, ans = 0;

bool is_pri(int num)
{
	if (num == 1 || num == 0) return false;
	int s = floor(sqrt((double)num));
	for (int i = 2; i <= s; i++)
	{
		if (num % i == 0) return false;
	}
	return true;
}

void dfs(int index,int k)
{
	for (int i = index; i < n; i++)
	{
		used[k] = dat[i];
		if (k < m - 1)	dfs(i + 1, k + 1);
		else
		{
			sum = 0;
			for (int i = 0; i < m; i++) sum += used[i];
			if (is_pri(sum)) ans++;
		}

	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> dat[i];

	dfs(0, 0);
	cout << ans;
}
