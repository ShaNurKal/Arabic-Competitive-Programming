#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,s,e;
    cin>>x>>y>>s>>e;
    int res;
    if(e>s){
    res=(abs(e-s)-1)*(x+(2*y));
    res+=(2*y);
    cout<<res;

    }
    else if(e<s){
    res=(abs(e-s)+1)*(x+(2*y));
    res-=(2*y);
    cout<<res;

    }
    else {
        cout<<x;
    }
    return 0;
}
