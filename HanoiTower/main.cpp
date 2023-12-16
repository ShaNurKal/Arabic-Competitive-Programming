#include <iostream>
#include <bits/stdc++.h>
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0; i<n ; i++)
#define rep(i,v) for(int i=0 ; i<(int)sz(v); i++)
#define clr(v, d)  memset(v, d, sizeof(v))
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
string x,y;
int num=-1,con=0;
void Hanoi(int N, int From, int To, int Temp){
  if (N>0)
  {
    Hanoi(N - 1, From, Temp, To);
    //cout<<N<<' '<<From<<' '<<To<<endl;
    con++;
    x[N-1]=To+'0';
    if(x==y){
        num=con;
    }
    //cout<<x<<"      "<<con<<endl;
    Hanoi(N - 1, Temp, To, From);
  }
}
int main()
{
   x=y="";
   int n,d;
   scanf("%d",&n);
   lp(i,n){
       scanf("%d",&d);
       x+='1';
       y+=d+'0';
   }
   if(x==y){
    cout<<0<<endl;
    return 0;
   }
   Hanoi(n,1,2,3);
   cout<<num<<endl;
   return 0;
}
