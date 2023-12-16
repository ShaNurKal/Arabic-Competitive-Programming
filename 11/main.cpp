#include <iostream>
#include <cstdio>
#include<list>
#include<iomanip>
#include<cmath>
#include<queue>
#include <functional>
#include<stdio.h>
#include<assert.h>
#include<stack>
#include<sstream>
#include <cstdlib>
#include<map>
#include<algorithm>
#include<iostream>
#include<set>
#include<utility>
#include<memory.h>
#include<string>
#include<vector>
#include<numeric>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);
#define ll  long long
#define pb push_back
#define fi(ss) freopen (ss,"r",stdin)
#define fo(ss) freopen (ss,"w",stdout)
#define sz(v)               ((int)((v).size()))
#define all(x)          (x).begin(),(x).end()
#define REP(i, v)       for(int i=0;i<sz(v);i++)
#define lp(i,n) for(int i = 0 ; i < n ; ++i)
#define hash ___hash
#define next ___next
#define prev ___prev
#define left ___left
#define time __time
typedef pair<int,int> pii;
#define F first
#define S second
#define MP make_pair
const int maxn = 4*100005;
int arr[5];
int found = 0;
bool vis[5];
void backtrack(int len,int value,int first) {

	if(found)
		return;
	if(len == 5) {
		found |= (value == 23);
		return;
	}
	for (int j = 0 ; j < 5 ; ++j) {
		if(vis[j])
			continue;
		// do
		vis[j] = 1;

		if(first) {
			backtrack(len + 1,value + arr[j],1);
			backtrack(len + 1,value - arr[j],1);
			backtrack(len + 1,value * arr[j],1);
		} else {
			backtrack(len + 1,arr[j],1);
		}
		// undo
		vis[j] = 0;
	}

}
// Bijetive
/*
 *  f(1) = 2, f(2) = 1 ----> OK
 *
 *  f(1) = 1, f(2) = 1 ---> NOT OK
 *
 */
// 5 * 3 * 5 * 3 * 5 * 3 * 5 * 3 * 5 = 84735!
int main() {
	while(1) {
		found = 0;
		int sum = 0;
		for (int i = 0 ; i < 5 ; ++i) {
			scanf("%d",&arr[i]);
			sum += arr[i];
		}
		if(!sum) return 0;
		backtrack(0,0,0);
		if(found) puts("Possible");
		else puts("Impossible");
	}

}
