#include <iostream>
#include <stdio.h>
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
int movx[8]={0,0,1,-1};
int movy[8]={1,-1,0,0};
bool visited[32][82];
int row,col;
char a[32][82],block;
string x;
bool check( int i , int j ){
    return (i>=0&&i<row&&j>=0&& j<=col);
    return false;
}
void dfs( int i, int j){
    visited[i][j]=1;
    a[i][j]='#';
    for ( int k=0 ; k<4 ; k++ ){
        int xc=i+movx[k];
        int yc=j+movy[k];
        if(check(xc,yc)&&!visited[xc][yc]&&a[xc][yc]!=block){
            dfs(xc,yc);
        }
    }

}
int main()
{
    int t;
    cin>>t;
    bool y=0;
    while(t--){
        clr(a,' ');
        clr(visited,0);
        row=0,col=0;
        int posx,posy;
        while(getline(cin,x)){
            col=max(col,sz(x));
            if(x[0]=='_') break;
            int m=sz(x);
            rep(i,x){
                if(x[i]=='*'){
                     posx=row,posy=i;
                }
                if(x[i]!='*'|| x[i]!=' '){
                    block=x[i];
                }
                a[row][i]=x[i];
            }
            row++;
        }
        rep(i,x){
            a[row][i]=x[i];
        }
        dfs(posx,posy);
        int i=(!y)? 1 : 0;
        y=1;
        for ( ; i<=row ;i++){
            lp(j,col){
                cout<<a[i][j];
            }
            cout<<endl;
        }
    }
}
