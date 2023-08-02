//- [P2036 [COCI2008-2009#2] PERKET](https://www.luogu.com.cn/problem/P2036)

#include<iostream>
#include<math.h>
using namespace std;
int n, pd[10] = { 0 };
int Min = 0x7fffffff;
struct pi {
	int s;
	int d;
}nums[10];

//c1代表酸度,c2代表苦度
void dfs(int index, int c1, int c2)
{
	if (index >= n)
	{
		if (c1 == 1 && c2 == 0) return;
		else Min = min(Min, abs(c1 - c2));
		return;
	}
	dfs(index + 1, c1, c2);
	dfs(index + 1, c1 * nums[index].s, c2 + nums[index].d);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> nums[i].s >> nums[i].d;

	dfs(0,1,0);
	cout << Min;
}
