#include <iostream>
#include <vector>
using namespace std;
int arr[27][27];
bool visited[27][27]={0};
int adjX[8]={0,0,-1,1,-1,-1,1,1};
int adjY[8]={1,-1,0,0,1,-1,1,-1};

bool inRange(int i,int j,int x){
 if(i>=0 && j>=0 && i<x  && j<x)
    return true;
 else
    return false;
}
void dfs (int i, int j, int x){
    if(visited[i][j])
        return;
    visited[i][j]=1;
    for ( int k=0 ; k<8 ; k++){
        int adX= adjX[k]+i;
        int adY= adjY[k]+j;
        if( inRange(adX,adY,x) && !visited[adX][adY] && arr[adX][adY]==1){
            dfs(adX,adY,x);
        }
    }
}
int main()
{
    int x,con=1;
    while (cin>>x){
         for ( int i=0 ; i<27; i++){
            for ( int j=0 ; j<27 ;j++ ){
                visited[i][j]=0;
            }
        }
        int ans=0;
        for ( int i=0 ; i<x; i++){
            string k;
            cin>>k;
            for ( int j=0 ; j<x ;j++ ){
                arr[i][j]=int(k[j])-48;
            }
        }
         for ( int i=0 ; i<x; i++){
            for ( int j=0 ; j<x ;j++){
                if(arr[i][j]==1&&visited[i][j]==0){
                    dfs(i,j,x);
                    ans++;
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",con,ans);
        con++;
    }
    return 0;
}
