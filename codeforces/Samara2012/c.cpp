#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 2e2+5;
const int mod = 1e9+7;
int dp[N][N];
int n, k;

int solve(int val, int qtd){
	if(val>n) return 0;
	if(qtd == k) return 1;
	
	int &r = dp[val][qtd];
	if(r != -1) return r;

	return r = (solve(val+1, qtd+1) + solve(val+1, qtd))%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

    cin >>k >>n;
	memset(dp, -1, sizeof dp);
	cout <<solve(0, 0) <<endl;
    
    return 0;
}

