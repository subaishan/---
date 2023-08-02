//- [P1157 组合的输出](https://www.luogu.com.cn/problem/P1157)

#include<iostream>
#include<iomanip>
using namespace std;
int used[21];
int n, m;

void dfs(int index, int k)
{
	for (int i = index; i < n; i++)
	{
		used[k] = i + 1;
		if (k < m - 1) dfs(i + 1, k + 1);
		else if(k == m - 1)
		{
			for (int c = 0; c < m; c++) cout << setw(3) << used[c];
			cout << endl;
		}
	}
}

int main()
{
	cin >> n >> m;

	dfs(0,0);
}
