#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define sz(v)    (int)(v.size())
#define all(v)   (v).begin(), (v).end()
#define lp(i,n)  for(int i=0; i<n ; i++)
#define rep(i,v) for(int i=0 ; i<(int)sz(v); i++)
#define clr(v, d)  memset(v, d, sizeof(v))
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
using namespace std;

void solve(){
    string s;
    cin>>s;
    int x,y;
    x=y=0;
    rep(i,s){
        if(s[i]=='x') x++;
        else y++;
    }
    if(x>y){
        x-=y;
        cout<< string(x,'x')<<endl;
    }
    else{
        y-=x;
        cout<< string(y,'y')<<endl;
    }
}
int main() {
    solve();
    return 0;
}
