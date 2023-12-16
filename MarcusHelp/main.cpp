#include <iostream>

using namespace std;
int movx[3]={-1,0,0};
int movy[3]={0,1,-1};
string mov[3]={"forth","right","left"};
string puzzle="@IEHOVA#";
bool inRange( int i , int j){
  if(i>=0&& j>=0 && i<6 && j<5)
    return true;
  else
    return false;
}
template <typename TwoD>
void dfs(TwoD& arr,int i , int j, int in){
    int xc,yc;
    for ( int k=0 ; k<3 ; k++ ){
        xc = movx[k] + i;
        yc = movy[k] + j;
        if (arr[xc][yc]==puzzle[in]){
            if(puzzle[in]=='#'){
                cout<<mov[k]<<endl;
                return;
            }
            else{
            cout<<mov[k]<<' ';;
            in++;
            break;
            }
        }
    }
    dfs(arr,xc,yc,in);

}
int main()
{
    int x;
    cin>>x;
    for ( int i=0 ; i<x ; i++ ){
        int m,n,in=1,ax,ay;
        cin>>m>>n;
        char arr[9][9];
        for ( int j=0; j<m ; j++ ){
            for ( int k=0 ; k<n ; k++ ){
                 cin>>arr[j][k];
                if(arr[j][k]=='@')
                    ax=j,ay=k;
            }
        }
        dfs(arr, ax, ay, in);
    }
    return 0;
}
