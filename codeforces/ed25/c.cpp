#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    ios_base::sync_with_stdio(false);

	int n;
	ll k;

	cin >>n >>k;
	vector<ll> v;
	for(int i = 0; i < n; i++) {
		ll t; cin >>t;
		v.pb(t);
	}
	sort(v.begin(), v.end());

	for(int i = 0; i < n; i++) {
		if(v[i] > (2LL*k)) {
			cout <<1 <<endl;
			return 0;
		}
		k = max(k, v[i]);
	}

	cout <<0 <<endl;
    return 0;
}

