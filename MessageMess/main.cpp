#include <iostream>
#include <bits/stdc++.h>
#define all(v)  v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v); i++)
#define clr(v, d)  memset(v, d, sizeof(v))
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
set <string> s;
string mess,gen;
int mem[52][52];
int solve(int i, int firstind, int siz ,string x){
    if(i==sz(mess)){
        if(siz==i){
            gen=x;
            return 1;
        }
        return 0;
    }
    if(mem[i][firstind]!=-1) return mem[i][firstind];
    int sol1,sol2;
    sol1=sol2=0;
    string t=mess.substr(firstind,(i-firstind)+1);
    if(s.count(t))
        sol1=solve(i+1,i+1,siz+sz(t),x+t+' ');
    sol2=solve(i+1,firstind,siz,x);
    return mem[i][firstind]=sol1+sol2;
}
class MessageMess
{
    public:
    int x=5;
     string restore(vector <string> dictionary, string message){
        clr(mem,-1);
        string sol;
        rep(i,dictionary){
            s.insert(dictionary[i]);
        }
        mess=message;
        int k=solve(0,0,0,"");
        if(k==0){
            sol="IMPOSSIBLE!";
        }
        else if(k==1){
            gen.pop_back();
            sol=gen;
        }
        else{
            sol="AMBIGUOUS!";
        }
        return sol;
    }

};

