#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> adj;
vector<int> top;
bool visited[101];

void dfs( int v){
    visited[v]=1;
    for ( int i=0 ; i<adj[v].size(); i++ ){
        int m=adj[v][i];
        if(!visited[m]){
            dfs(m);
        }
    }
    top.push_back(v);
}
int main()
{
    int n,m;
    while(cin>>n>>m&&n!=0){
        for ( int i=0 ; i<=n ;i++){
            adj.push_back({});
            visited[i]=0;
        }
        for ( int i=0 ; i<m ; i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        for ( int i=1 ;i<=n ; i++ ){
                if(!visited[i]){
                    dfs(i);
                }
        }
        for ( int i=top.size()-1 ;i>=0; i--){
            cout<<top[i]<<' ';
        }
        adj.clear();
        top.clear();
        cout<<endl;
    }

    return 0;
}
