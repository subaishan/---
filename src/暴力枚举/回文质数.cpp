//- [P1217 [USACO1.5] 回文质数 Prime Palindromes](https://www.luogu.com.cn/problem/P1217)

#include<iostream>
#include<math.h>
using namespace std;

bool is_palindrome(int num)
{
    int a = 0;
    int b = num;
    while(b != 0)
    {
        a *= 10;
        a += b%10;
        b /= 10;
    }
    if(num == a) return true;
    return false;
}

bool is_prime(int num)
{
    int s = sqrt(num);
    for(int i = 2; i <= s; i++)
    {
        if(num % i == 0) return false;
    }
    return true;
}

int main()
{
    int a,b;
    cin >> a >> b;
    
    for(; a <= b; a++)
    {
        if(a >= 10000000) return 0;
        
        if(is_palindrome(a) && is_prime(a))
            cout << a << endl;
    }
}
