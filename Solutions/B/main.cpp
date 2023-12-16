#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string x;
    cin>>x;
    string res;
    while(n!=0){
        if(n%2==0){
            res.insert(0,1,x[0]);
        }
        else{
            res.push_back(x[0]);
        }
        x.erase(x.begin());
        n--;
    }
    cout<<res;
    return 0;
}
