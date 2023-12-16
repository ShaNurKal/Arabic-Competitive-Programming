#include <iostream>
#include <bits/stdc++.h>
#define all(v)  (v.begin(),v.end())
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
int main()
{
    int n;
    cin>>n;
    int arr[n],res=0;
    lp(i,n){
        cin>>arr[i];
        if(arr[i]) res++;
    }
    bool open=0;
    int num=0;
    lp(i,n){
        if(!res)
            break;
        if(arr[i]){
            open=1;
            num++;
            res--;
        }
        if(!arr[i]&&open){
            open=0;
            num++;
        }
    }
    cout<<num<<endl;
    return 0;
}
