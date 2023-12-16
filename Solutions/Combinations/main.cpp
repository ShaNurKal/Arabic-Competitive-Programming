#include <iostream>
#include <bits/stdc++.h>
#define all(v)  v.begin(),v.end()
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))
using namespace std;
typedef long long ll;
typedef pair<double, double> pi;

ll arr[102][102];

int main()
{
    clr(arr,0);
    arr[0][0]=1;
    for ( int i=1; i<102 ; i++ ){
        arr[i][0]=1;
        for ( int j=1; j<102 ; j++){
            arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
        }
    }
    int x,y;
    while(cin>>x>>y && x||y){
        printf("%d things taken %d at a time is %lld exactly.\n",x,y,arr[x][y]);
    }
    return 0;
}
