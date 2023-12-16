#include <iostream>
#include <cstring>
#define all(v)   v.begin(),v.end()
#define sz(v)    ((int)v.size())
#define lp(i,n)  for(int i=0; i<n; i++)
#define rep(i,v)  for(int i=0; i<sz(v); i++)
#define clr(v,d)  memset(v,d,sizeof(v))
typedef long long ll;
using namespace std;
const int OO=(int)1e7;
char table[1002][1002];
int x,y,n,m;
bool check( int s1, int s2){
    if( (s1>=x&&s1<=y) || (s2>=x&&s2<=y) ) return true;
    return false;
}
int calc( int column , int s1 ,int s2, bool valid ){
    if(s1>y || s2 >y){
            return OO;

    if(column == m){
        if(valid) return 0;
        else return OO;
    }

    int nw=0,nb=0;
    for ( int i=0 ; i<n ; i++ ){
         if(table[i][column]=='#') nb++;
         else nw++;
    }
    s1++,s2++;
    if( check(s1,s2) ) valid=true;
    else valid=false;

    int ch1=calc(column+1,s1,0,valid)+nb;
    int ch2=calc(column+1,0,s2,valid)+nw;

    return min(ch1,ch2);

}

int main()
{
    cin>>n>>m>>x>>y;
    lp(i,n)
        lp(j,m)
            cin>>table[i][j];
    cout<<calc(0,0,0,false);
    return 0;
}
