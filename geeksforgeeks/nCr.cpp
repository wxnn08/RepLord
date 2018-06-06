#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int MOD = 1e9+7;
const int MAX = 1e4+5;
ll dp[MAX][MAX];

ll nCr(int n, int r){
    if(dp[n][r]!=0) return dp[n][r];
    if(n==r || r==0) return dp[n][r] = 1;
    return dp[n][r] = (nCr(n-1, r)%MOD + nCr(n-1, r-1)%MOD)%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);

    int t; 
    cin >>t;
    int n, r;
    for(int i=0; i<t; i++){
	cin >>n >>r;
	cout <<nCr(n, r) <<endl;
    }
    
    return 0;
}

