#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int m, n;
const int TAM = 1e3+5;
int dp[TAM];
int a[TAM];

ll f(int v){
	if(dp[v]!=INF) return dp[v];
	int res=0;
	for(int i=1; i<=n; i++)
		res += (a[i]*f(v-i)) % m;
	
	return dp[v] = res%m;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	int k;
	cin >>n >>k >>m;
	
	memset(dp, INF, sizeof dp);
	fori(i, 1, n+1){
		cin >>a[i];
	}
	fori(i, 1, n+1){
		cin >>dp[i];
	}

	cout <<f(k) <<endl;
    
    return 0;
}

