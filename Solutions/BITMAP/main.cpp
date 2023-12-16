#include <iostream>
#include <bits/stdc++.h>
#define all(v)  v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
int n,m;
int movx[4]={0,0,1,-1};
int movy[4]={-1,1,0,0};
bool check( int x, int y){
 if(x>=0 && x<n && y>=0 && y<m ) return true;
 return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector < vector <pi> > s(n);
        bool visited[n][m];
        clr(visited,0);
         queue<pi> q;
        pi tmp;
        lp(i,n){
            string x;
            cin>>x;
            lp(j,m){
              s[i].push_back({x[j]-'0',0});
              if(x[j]=='1'){
                q.push({i,j});
              }
            }
         }
         while(!q.empty()){
            tmp=q.front();
            q.pop();
            visited[tmp.first][tmp.second]=1;
            pi z;
            lp(i,4){
                int xc=movx[i]+tmp.first;
                int yc=movy[i]+tmp.second;
                if(check(xc,yc)){
                    if(!visited[xc][yc]){
                        visited[xc][yc]=1;
                        z=s[xc][yc];
                        if(z.first==1) s[xc][yc].second=0;
                        else s[xc][yc].second=s[tmp.first][tmp.second].second+1;
                        q.push({xc,yc});
                    }
                }
            }
         }
        lp(i,n){
            lp(j,m){
                cout<<s[i][j].second<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}
