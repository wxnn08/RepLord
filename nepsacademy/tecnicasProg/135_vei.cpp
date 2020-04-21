#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
const int N = 1e3+5;
int n, m;
int moeda[N];
int dp[N];

bool troco(int val) {
	if(val<0) return 0;

	int &r = dp[val];
	if(r!=-1) return r;

	bool res = false;
	for(int i=0; i<n; i++){
		res += troco(val-moeda[i]);
	}
	return r = res;
}

int main(){
    ios_base::sync_with_stdio(false);

	cin >>n >>m;
	fori(i,0,n) cin >>moeda[i];
	memset(dp, -1, sizeof dp);
	
	dp[0] = 1;
	cout <<(troco(m)?'S':'N') <<endl;
    
    return 0;
}

