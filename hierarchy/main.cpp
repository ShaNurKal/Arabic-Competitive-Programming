#include <iostream>
#include <vector>
using namespace std;

vector < vector<int> > adj;
vector <int> top;
char color[100200];
int p[100200];
void dfs(int v){
    color[v]='g';
    for ( int i=0 ; i<adj[v].size() ; i++ ){
        int m=adj[v][i];
        if(color[m]=='w'){
            p[m]=v;
            dfs(m);
        }
    }
    top.push_back(v);
    color[v]='b';

}
int main()
{
    int n,k;
    cin>>n>>k;
    for ( int i=0 ; i<=n ; i++ ){
        adj.push_back({});
        color[i]='w';
        p[i]=0;
    }
    for ( int i=1 ; i<=k ; i++ ){
        int w,a;
        cin>>w;
        for ( int j=0 ; j<w ; j++ ){
            cin>>a;
            adj[i].push_back(a);
        }
    }
     for ( int i=1 ; i<=n ; i++ ){
        if (color[i]=='w'){
            dfs(i);
        }
    }
    for ( int i=n-2; i>=0 ; i-- ){
        p[top[i]]=top[i+1];
    }
    for ( int i=1 ; i<=n ; i++ ){
        cout<<p[i]<<endl;
    }
    return 0;
}
