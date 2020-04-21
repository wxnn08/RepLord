#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 64;

void sum(vector<ll> &v, vector<ll> &t) {
	for(int i = 0; i < t.size(); i++) {
		v[i] += t[i];
	}
}

void calc_pot(vector<ll> &t, ll v, ll k) {
	if(v == 0) {
		t.pb(0);
		return;
	}
	t.pb(v%k);
	calc_pot(t, v/k, k);
}
 
void print(vector<ll> &t) {
	for(auto a:t) cout <<a <<' ';
	cout <<endl;
}
int main() {
    ios_base::sync_with_stdio(false);

	int tc; cin >>tc;
	while(tc--) {
		vector<ll> v(N, 0);
		ll n, k;
		cin >>n >>k;
		for(int i = 0; i < n; i++) {
			ll a; cin >>a;
			vector<ll> t;
			calc_pot(t, a, k);
			sum(v, t);
		}

		bool ans = true;
		for(int i = 0; i < N; i++) 
			if(v[i] > 1LL) ans = false;
		cout <<(ans?"YES":"NO") <<endl;
	}

    return 0;
}

