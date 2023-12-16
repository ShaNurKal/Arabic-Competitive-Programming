#include <iostream>
#include <queue>
#define sz(v)  v.size()
using namespace std;

int v,e,cost[502],total;
int bfs(vector< vector <int> > adj, int query){
    int c=0;
    int visited[v+1]={0};
    visited[query]=1;
    queue<int> s;
    s.push(query);
    while(!s.empty()){
        int tmp=s.front();
        s.pop();
        c+=cost[tmp];
        for ( int j=0 ; j<sz(adj[tmp]) ; j++){
            int x=adj[tmp][j];
            if(visited[x]==0){
                s.push(x);
                visited[x]=1;
            }
        }
    }
    return c;
}
int main()
{
    int t=1;
    while(cin>>v>>e&&v!=0){
        bool visited[v+1]={0};
        total=0;
        int x,y;
        vector< vector <int> > adj(v+1);
        vector< vector <int> >adjrev(v+1);
        for ( int i=1; i<=v ;i++){
                cin>>cost[i];
                total+=cost[i];
            }
        while(e--){
            cin>>x>>y;
            adj[x].push_back(y);
            adjrev[y].push_back(x);
        }
        int q;
        cin>>q;
        printf("Case #%d:\n",t);
        for ( int i=0 ; i<q ; i++ ){
            int qu;
            cin>>qu;
            int mat,mit=0,c;
            c=bfs(adj,qu);
            mat=total-c;
            mit=bfs(adjrev,qu);
            mit-=cost[qu];
            cout<<mat-mit<<endl;
        }
        cout<<endl;
        t++;
    }
    return 0;
}
