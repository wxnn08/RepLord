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

const int N = 1e5+5;
int mod = 1e9+7;
int dp[N];
int k;

int lul(int pos){
	if(pos==0)return 1;
	if(pos<0) return 0;

	if(dp[pos]!=-1) return dp[pos];
	return dp[pos] = (lul(pos-1)+lul(pos-k))%mod; 
}

int main(){
    ios_base::sync_with_stdio(false);

    memset(dp, -1, sizeof(dp));
	int TC;
	cin >>TC >>k;
	lul(1e5);
	dp[0]=0;
															
	ll soma[N];
	soma[0]=dp[0];
	for(int i=1; i<N; i++)
		soma[i]=soma[i-1]+dp[i];

	while(TC--){
		int ini, fim;
		cin >>ini >>fim;
		cout <<(soma[fim]-soma[ini-1])%mod <<endl;
	}
    
    return 0;
}

