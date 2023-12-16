#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include <map>
using namespace std;
 int xmov[8]={2,2,-2,-2,1,-1,1,-1};
 int ymov[8]={-1,1,-1,1,2,2,-2,-2};
 bool check( int i ,int j){
    if(i>=0&&i<8&&j>=0&&j<8) return true;
    return false;
 }
int main()
{
    string a[8][8];
    char row[8]={'a','b','c','d','e','f','g','h'};
    char col[8]={'1','2','3','4','5','6','7','8'};
    for ( int i=0 ; i<8 ; i++ ){
        for ( int j=0 ; j<8 ; j++ ){
            a[i][j]+=row[i];
            a[i][j]+=col[j];
        }
    }
    string s,e;
    while(cin>>s>>e){
        int k,l;
        for ( int i=0 ; i<8 ; i++ ){
            for ( int j=0 ; j<8 ; j++ ){
                if(a[i][j]==s) {
                        k=i,l=j;
                        break;
                }
            }
        }
        queue <pair<pair<int,int>,int>> board;
        bool visited[8][8];
        for ( int i=0 ; i<8 ; i++ ){
            for ( int j=0; j<8 ; j++ ){
                visited[i][j]=0;
            }
        }
        board.push({{k,l},0});
        while(!board.empty()){
            pair <int,int> c= board.front().first;
            int dis=board.front().second;
            board.pop();
            int i=c.first,j=c.second;
            visited[i][j]=1;
            if(a[i][j]==e){
                cout<<"To get from "<<s<<" to "<<e<<" takes "<<dis<<" knight moves.\n";
                break;
            }
            for ( int m=0; m<8 ; m++ ){
                int xc=i+xmov[m];
                int yc=j+ymov[m];
                if(check(xc,yc)&&visited[xc][yc]==0){
                    board.push({{xc,yc},dis+1});
                }
            }
        }

    }


    return 0;
}
