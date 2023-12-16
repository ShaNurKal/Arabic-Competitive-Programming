#include <iostream>
#include <cstring>
#include <vector>
#define all(v)  (v.begin(),v.end())
#define sz(v)    (int)(v.size())
#define lp(i,n) for(int i=0 ; i<n ; i++)
#define rep(i,v) for(int i=0 ; i< (int)sz(v) ; i++)
#define clr(v, d)  memset(v, d, sizeof(v))
typedef long long ll;

using namespace std;
const int OO=(int)1e6;
int MAX;
int days[102];
int mem [MAX][4];
int finMin ( int i, int prev ){
    if (i==MAX) return 0;

    int ret=OO;
    if(days[i]==0) return ret=min(ret,1+finMin(++i,4));

    else if(days[i]==1) {
            if(prev!=1)
                ret=finMin(++i,1);
            else
            return ret=min(ret,1+finMin(++i,2));
    }
    else if(days[i]==2) {
            if(prev!=2)
                 ret=finMin(++i,2);
            else
            return ret=min(ret,1+finMin(++i,2));
    }
    else if(days[i]==3) {
           if (prev==1)
              ret=finMin(++i,2);
           else
             ret=finMin(++i,1);
    }
    return ret;

}


int main()
{
    int n;
    cin>>n;
    MAX=n;
    lp(i,n) cin>>days[i];
    cout<<finMin(0,4);

    return 0;
}
