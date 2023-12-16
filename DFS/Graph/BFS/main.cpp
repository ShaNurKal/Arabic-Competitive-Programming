#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void bfs(){
    q.push(s);
    color[s]='G';
    while(!q.empty()){
        int tmp=q.pop();
        for ( int i=0 ; i< x[tmp].size(); i++){
            if(color[x[tmp][i]]=='w'){
               color[x[tmp][i]]='g';
               d[x[tmp][i]]=d[tmp]+1;
               p[x[tmp][i]]=tmp;
            }
        }
        color[tmp]='b';
    }
}
////////////////////
int time=0;
void dfs(){
    d[s]=time+1;
    time++;
    color[s]='g';
    for ( int i=0 ; i< x[s].size(); i++){
            if(color[x[s][i]]=='w'){
               color[x[s][i]]='g';
               dis[x[s][i]]=time+1;
               time++;
               p[x[s][i]]=s;
               dfs();
            }
        }
        f[s]=time+1;
        time++;
        color[s]='b';
    }
///////////////////
void graph(){
    j=0;
    while(j!=k){
    nodelist[i].push_back(j);
    j++;
    }
    color[i]='w'l
    dis[i]=0;
    f[i]=0;
    d[i]=0;
    p[i]=0;
}

int main()
{
    queue q;
    q.empty
    return 0;
}
