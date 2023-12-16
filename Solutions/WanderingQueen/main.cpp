#include <iostream>
#include <stdio.h>
#include <queue>
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
typedef pair< pi,int > v;
int n,m;
pi s;
int movx[8]={0,0,-1,1,1,-1,-1,1};
int movy[8]={1,-1,0,0,1,-1,1,-1};
inline bool check( int i, int j){
  return (i>=0&&i<n&&j>=0&&j<m);
}
char a[1005][1005];
int visited[1005][1005];
int d[1005][1005];
void solve(){
    queue <pi> q;
    q.push(s);
    visited[s.F][s.S]=255;
    d[s.F][s.S]=0;
    while(!q.empty()){
        pi tmp=q.front();
        q.pop();
        if(a[tmp.F][tmp.S]=='F'){
            printf("%d\n",d[tmp.F][tmp.S]);
            return;
        }
        for ( int i=0 ; i<8 ; i++ ){
              int xc=tmp.F+movx[i];
              int yc=tmp.S+movy[i];
              while(a[xc][yc]!='X'&&check(xc,yc)&&!(visited[xc][yc]&(1<<i))){
                    visited[xc][yc]|=(1<<i);
                    d[xc][yc]=d[tmp.F][tmp.S]+1;
                    q.push({xc,yc});
                    xc+=movx[i];
                    yc+=movy[i];
                }
            }
        }

    puts("-1");
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        lp(i,n){
            lp(j,m){
                scanf(" %c",&a[i][j]);
                if(a[i][j]=='S') s={i,j};
                visited[i][j]=0;
            }
        }
       solve();
    }
    return 0;
}
