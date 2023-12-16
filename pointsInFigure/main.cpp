#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    vector <vector<double>>r(10);
    char s;
    double siz=0;
    while(siz<=9){
        double x,y,m,n;
        char input[100];
        fgets(input,sizeof(input),stdin);
        if(input[0]=='*')
            break;
        else
            sscanf(input,"%c %lf %lf %lf %lf",&s,&x,&y,&m,&n);
        r[siz].push_back(x);
        r[siz].push_back(y);
        r[siz].push_back(m);
        r[siz].push_back(n);
        siz++;
    }
    double k,l;
    int point=1;
    while(cin>>k>>l&&k!=9999.9&&l!=9999.9){
        bool key=1;
        for(int i=0 ; i<siz; i++ ){
                //r[0][0] x
                //r[0][1] y
                //r[0][2] m
                //r[0][3] n
            if(r[i][0]<k&&r[i][2]>k&&r[i][3]<l&&r[i][1]>l){
                key=0;
                printf("Point %d is contained in figure %d\n",point,i+1);
            }
        }
        if(key){
                printf("Point %d is not contained in any figure\n",point);
        }
        point++;
    }
    return 0;
}
