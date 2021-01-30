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
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n, a, b, k;
	cin >>n >>a >>b >>k;
	vector<ll> in;
	for(int i = 0; i < n; i++) {
		ll a; cin >>a;
		in.pb(a);
	}

	vector<ll> cost;
	for(int i = 0; i < n; i++) {
		ll h = in[i];
		ll qtd = h/(a+b);
		ll rem = h%(a+b);
		ll ans = 0LL;

		if(qtd == 0) {
			if(rem > a) ans = 1LL;
		}
		else {
			while((rem == 0 or rem > a) and qtd > 0) {
				rem = (rem + b)%(a+b);
				qtd--;
				ans++;
			}
		}
		cost.pb(ans);
	}

	sort(cost.begin(), cost.end());

	ll l = 0, r = 0;
	ll sum = 0, ans = 0;
	while(l < cost.size() and r < cost.size()) {
		sum += cost[r++];
		while(sum > k) sum -= cost[l++];
		ans = max(ans, r-l);
	}

	cout <<ans <<endl;

    return 0;
}

