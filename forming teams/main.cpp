#include <iostream>
#include <vector>
using namespace std;

char color[102];
vector<vector<int>> adj;
int p[101]={0};
int ans=0;
void dfs(int v,int dist){
    color[v]='g';
    for ( int i=0; i<adj[v].size(); i++){
        int m=adj[v][i];
        if(color[m]=='g'&&p[v]!=m&&dist%2==1){
            ans++;
        }
        if(color[m]=='w'){
            p[m]=v;
            dist++;
            dfs(m,dist);
        }
    }
    color[v]='b';
}
int main()
{

    int x,z;
    cin>>x>>z;
    for ( int i=1 ; i<=x+1 ; i++ ){
        color[i]='w';
    }
    for ( int i=0 ; i<=x+1 ; i++ ){
        adj.push_back({});
    }
    for ( int i=0 ; i<z ; i++ ){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for ( int i=1; i<x+1 ;i++){
            if(color[i]=='w'){
                    int dist=1;
                dfs(i,dist);
            }
    }
    if((x-ans)%2==0){
        cout<<ans;
    }
    else{
        cout<<ans+1;
    }
}
