#include <iostream>
#include <queue>
#include <bits/stdc++.h>
int visited[504]={0};
bool adj[504][504];

void dfs( int x , int &mt, int q , int v, int node[] ) {
    visited[x]=1;
    if(x==q) return;
    mt+=node[x];
    for ( int i=1 ; i<=v ; i++ ){
        if(adj[x][i]==1&&visited[i]==0)
        dfs(i,mt,q,v,node);
    }

}
using namespace std;
int main()
{

    int v,e,t=1;
    while(cin>>v>>e&&v!=0){
        int node[v+1]={0};
        for ( int i=1 ; i<=v ; i++ ){
            cin>>node[i];
            visited[i]=0;
        }
        for ( int i=1 ; i<=v ; i++ ){
            for ( int j=1; j<=v; j++ ){
                adj[i][j]=0;
            }
        }
        for ( int i=0;  i<e ; i++ ){
            int x,y;
            cin>>x>>y;
            adj[x][y]=1;
        }
        int qur;
        cin>>qur;
        int z[qur];
        for (int i=0 ; i<qur ; i++)
            cin>>z[i];
        printf("\nCase #%d:\n",t);
        for(int k=0 ; k<qur ; k++){
            int q=z[k];
            int mt=0,mint=0;
             for ( int i=1 ; i<=v; i++){
                if(adj[q][i]==1)
                visited[i]=1;
            }
            for ( int i=1 ; i<=v; i++){
                if(visited[i]==0)
                dfs(i,mt,q,v,node);
            }
            queue<int> s;
            s.push(q);
            while(!s.empty()){
                int k=s.front();
                s.pop();
                mint+=node[k];
                for ( int i=1 ; i<=v ;i++){
                    if(adj[i][k]==1) s.push(i);
                }
            }
            mint-=node[q];
            cout<<abs(mt-mint)<<endl;
            for ( int i=1 ; i<=v; i++){
                visited[i]=0;
            }
        }
        cout<<endl;
        t++;
    }
    return 0;
}
