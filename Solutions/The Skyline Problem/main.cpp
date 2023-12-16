#include <iostream>
#include <bits/stdc++.h>
#define all(v)  v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v)    (int)(v.size())
#define lp(i,n)  for(int i=0; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;


int main()
{
    int l,h,r;
    int i=0;
    vector <int> res;
    while(cin>>l>>h>>r){
        if(i=0){
            res.push_back(l),res.push_back(h),res.push_back(r);
            i=2;
        }
        if(l>res[i]){
            for ( const auto x : {0,l,h,r}){
                res.push_back(x);
                i++;
            }
        }
        else if(l==res[i]){
            for ( const auto x : {h,r}){
                res.push_back(x);
                i++;
            }
        }
        else{
            i--;
            if(res[i]>h){
                i++;
                if(arr[i]<r){
                    for ( const auto x : {h,r}){
                        res.push_back(x);
                        i++;
                    }
                }
            }
            else if(res[i]==h){
                i++;
                if(arr[i]<r){
                    res[i]=r;
                }
            }
            else{
               i=sz(res)-1;

            }
        }

    }
    return 0;
}
