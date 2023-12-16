#include <iostream>
#include <bits/stdc++.h>
#define all(v)  v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
using namespace std;

int main()
{
   int m;
   cin>>m;
   string x;
   cin>>x;
   if(m>26){
        cout<<-1;
        return 0;
   }
   int arr[26]={0};
   rep(i,x){
        arr[x[i]-'a']++;
   }
   int sum=0;
   lp(i,26){
        if(arr[i]>1){
            sum+=arr[i]-1;
        }
   }
   cout<<sum<<endl;
  return 0;
}
