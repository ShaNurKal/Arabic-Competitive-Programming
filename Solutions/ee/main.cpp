#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#define all(v)  (v.begin(),v.end())
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0 ; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))


typedef long long ll;

using namespace std;
char arr[52][52];
bool visited[52][52];
map < pair <int,int> ,pair <int,int> > parent;
int n,m;
string ans="No";
int movx[4]={0,0,1,-1};
int movy[4]={1,-1,0,0};
bool check( int i , int j){
    if(i>=0&&i<n&&j>=0&&j<m) return true;
    else return false;
}
void dfs ( int i, int j ,int dis){
    visited[i][j]=1;
      for ( int k=0 ; k<4 ; k++ ){
            int xc=i+movx[k];
            int yc=j+movy[k];
            if(check(xc,yc)&&arr[i][j]==arr[xc][yc]){
                    pair<int,int>p1={xc,yc};
                    pair<int,int>p2={i,j};
                    if(!visited[xc][yc]){
                       parent[p1]=p2;
                       dfs(xc,yc,dis+1);
                    }
            }
    }
}
int main()
{
    cin>>n>>m;
    lp(i,n)
        lp(j,m) cin>>arr[i][j];

    lp(i,n){
        lp(j,m){
                int dis=0;
                if(!visited[i][j]){
                    dfs(i,j,0);
                }
        }
    }
    for (  auto it : parent){
        cout<<it.first.first<<" "<<it.first.second<<endl;
        cout<<it.second.first<<" "<<it.second.second<<endl;
        cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
