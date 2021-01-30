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

int main() {
	ios_base::sync_with_stdio(false);
	
	int n; cin >>n;
	vector<ll> v;
	for(int i = 0; i < n; i++) {
		ll t; cin >>t;
		v.pb(t);
	}

	sort(v.begin(), v.end());

	ll ans = 0;
	for(int i = 0; i < n-1; i++) {
		ans += (v[i+1]-v[i]);
	}

	

	return 0;
}

