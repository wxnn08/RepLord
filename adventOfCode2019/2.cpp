#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

ll solve(ll n) {
	ll v = ((n/3)-2);
	if(v <= 0LL) return 0LL;
	return  v + solve(v);
}

int main() {
	ios_base::sync_with_stdio(false);

	ll ans = 0, n;
	while(cin >>n) {
		ans += solve(n);
	}
	cout <<ans <<endl;
	
	return 0;
}

