//- [P1149 [NOIP2008 提高组] 火柴棒等式](https://www.luogu.com.cn/problem/P1149)

#include<iostream>
#include<map>
using namespace std;
map<int, int> tabel;

int get_num(int num)
{
	int sum = 0;
	if (num == 0)  sum = 6;
	while (num)
	{
		sum += tabel.find(num % 10)->second;
		num /= 10;
	}
	return sum;
}

int main()
{
	tabel.insert({ 0,6 });
	tabel.insert({ 1,2 });
	tabel.insert({ 2,5 });
	tabel.insert({ 3,5 });
	tabel.insert({ 4,4 });
	tabel.insert({ 5,5 });
	tabel.insert({ 6,6 });
	tabel.insert({ 7,3 });
	tabel.insert({ 8,7 });
	tabel.insert({ 9,6 });

	int n = 0;
	cin >> n;
	int ans = 0;
	int t = 0;
	for (int i = 0; i < 900; i++)
	{
		for (int j = 0; j < 900; j++)
		{
			if (i == j && get_num(i) + get_num(j) + 4 + get_num(i + j) == n) t = 0;
			if (get_num(i) + get_num(j) + 4 + get_num(i + j) == n)
			{
				ans++;
			}
		}
	}

	cout << ans - t;
}
