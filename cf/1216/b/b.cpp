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
typedef pair<ll, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e3 + 5;

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	vector<ii> v;
	for(int i = 0; i < n; i++) {
		ll a; cin >>a;
		v.eb(a, i+1);
	}
	sort(v.begin(), v.end(), 
			[](const ii &a, const ii &b) {
				if(a.fi != b.fi) return a.fi > b.fi;
				return a.se < b.se;
			});
	
	ll sum = 0;
	vector<int> ans;
	for(int i = 0; i < n; i++) {
		ans.pb(v[i].se);
		sum += (v[i].fi*i+1);
	}

	cout <<sum <<endl;
	for(auto at:ans) cout <<at <<' ';
	cout <<endl;

	return 0;
}

