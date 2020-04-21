#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
	ios_base::sync_with_stdio(false);

	int tc;
	cin >>tc;
	while(tc--) {
		int n, r;
		cin >>n >>r;
		vector<ll> v;
		for(int i = 0; i < n; i++) {
			int a; cin >>a;
			v.pb(a);
		}
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
		ll cont = 0;
		ll ans = 0;
		for(int i = v.size()-1; i >= 0; i--) {
			if(v[i]-cont*r > 0) ans++, cont++;
		}
		cout <<ans <<endl;
	}
	
	return 0;
}

