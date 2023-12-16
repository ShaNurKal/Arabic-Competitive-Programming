#include <iostream>
#include <algorithm>
#include <vector>
#define all(v)   (v).begin(),(v).end()
#define sz(v)     (int)((v).size())
using namespace std;

int main()
{
    vector<int> v ={3,4,2,3,6};
    sort(all(v));
    for ( int i=0 ; i<sz(v); i++) cout<<v[i]<<' ';

    return 0;
}
