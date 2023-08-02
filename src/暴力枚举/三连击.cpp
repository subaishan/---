//- [P1618 三连击（升级版）](https://www.luogu.com.cn/problem/P1618)

#include<iostream>
using namespace std;
int x[10]={0},a,b,c;
bool used[10]={0},ans=false;
int cons(int m){  
    int sum=0;
    for(int i=3*m-2;i<=3*m;i++){
        sum*=10;
        sum+=x[i];
    }
    return sum;
}
void solve(int n){
    if(n==10&&cons(1)*b==cons(2)*a&&cons(1)*c==cons(3)*a){  
        cout<<cons(1)<<" "<<cons(2)<<" "<<cons(3)<<endl;
        ans=true;
        return;
    }
    for(int i=1;i<=9;i++){
        if(!used[i]){
            x[n]=i; 
            used[i]=1;   
            solve(n+1);  
            used[i]=0; 
    }
    return;
}
int main(){
    cin>>a>>b>>c;
    solve(1);
    if(!ans) cout<<"No!!!"; 
    return 0;
}
