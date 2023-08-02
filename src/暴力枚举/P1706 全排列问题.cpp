//- [P1706 全排列问题](https://www.luogu.com.cn/problem/P1706)

#include<iostream>
using namespace std;
int n;
int used[10], pd[10] = {0};

void dfs(int k)
{
	if (k == n)
	{
		for (int i = 0; i < n; i++) cout << "    " << used[i];
		cout << endl;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (pd[i] != 1)
		{
			pd[i] = 1;
			used[k] = i + 1;
			dfs(k + 1);
			pd[i] = 0;
		}
	}
}

int main()
{
	cin >> n;

	dfs(0);
}
