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

int	const N = 1e5+5;
int val[N], n, maior=-1;
int dp[N];

int lul(int pos){
	if(pos>maior) return 0;
	if(dp[pos]!=-1) return dp[pos];
	return dp[N] = max(val[pos]*pos + lul(pos+2), lul(pos+1));
}

int main(){
    ios_base::sync_with_stdio(false);

	cin >>n;
	for(int i=0; i<n; i++){
		int tmp;
		cin >>tmp;
		val[tmp]++;
		maior = max(maior, tmp);
	}

	memset(dp, -1, sizeof(dp));
	cout <<lul(1) <<endl;
    
    return 0;
}

