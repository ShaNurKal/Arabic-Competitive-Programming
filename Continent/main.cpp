#include <iostream>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>
#define all(v)  (v.begin(),v.end())
#define sz(v)    (int)(v.size())
#define lp(i,n) for(int i=0 ; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))
typedef long long ll;
using namespace std;
char arr[22][22];
int movx[4]={0,0,1,-1};
int movy[4]={-1,1,0,0};
bool visited[22][22];
int m,n;
int xm,ym;
char l;
bool check( int i, int j){
    if(i<m && i>=0 && j<n && j>=0 ) return true;
    else false;
}
void dfs( int i, int j ,int& num,bool & ch ){
    if(i==xm&&j==ym){
        ch=1;
    }
    visited[i][j]=1;
    num++;
    for ( int k=0; k<4 ; k++ ){
        int xc=i+movx[k];
        int yc=j+movy[k];
        if(yc==-1&&(xc==i)) yc=n-1;
        if(yc==n&&(xc==i)) yc=0;
        char tmp=arr[xc][yc];
        if(tmp==l&&visited[xc][yc]==0&&check(xc,yc)){
            dfs(xc,yc,num,ch);
        }
    }
}
int main()
{
    while(cin>>m>>n){
        clr(visited,0);
        lp(i,m){
            lp(j, n)
                cin>>arr[i][j];
        }
        cin>>xm>>ym;
        l=arr[xm][ym];
        int res=0;
        lp(i,m){
            lp(j, n){
                if(visited[i][j]==0&&arr[i][j]==l){
                    int num=0;
                    bool ch=0;
                    dfs(i,j,num,ch);
                    if(!ch)
                        res=max(res,num);
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
