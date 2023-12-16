#include <iostream>

using namespace std;
bool seen[101][101];
int movx[4]={0,0,1,-1};
int movy[4]={1,-1,0,0};
bool inRange( int i, int j, int n){
    if(i>=0&&j>=0&&i<n&&j<n){
        return true;
    }
    else
        return false;
}
template<typename TwoD>
void dfs( int i , int j , TwoD& arr,int n){
    if(arr[i][j]=='.')
        return;
    seen[i][j]=true;
    for ( int k=0; k<3 ; k++){
        int xc= movx[k]+i;
        int yc= movy[k]+j;
        if (inRange(xc,yc,n)&&arr[xc][yc]=='x'&&seen[xc][yc]==0){
            dfs(xc,yc,arr,n);
        }
        else if(inRange(xc,yc,n)&&arr[xc][yc]=='@'&&seen[xc][yc]==0){
            dfs(xc,yc,arr,n);
        }
    }
}
int main()
{
   int t;
   cin>>t;
   for ( int i=0 ; i<t ; i++ ){
     int n,ans=0;
     cin>>n;
     char arr[101][101];
     for ( int j=0 ; j<n  ; j++){
         for ( int k=0 ; k<n  ; k++){
            cin>>arr[j][k];
            seen[j][k]=0;
        }
     }
      for ( int j=0 ; j<n  ; j++){
         for ( int k=0 ; k<n  ; k++){
            if(arr[j][k]=='x'&&seen[j][k]==0){
                dfs(j,k,arr,n);
                ans++;
            }
        }
     }
     printf("Case %d: %d\n",i+1,ans);

   }

    return 0;
}
