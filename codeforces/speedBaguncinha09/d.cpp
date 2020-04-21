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

ll calc(int n) {
	ll ans = 0;
	while(n > 1) {
		n /= 2;
		ans++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >>n;

	vector<ll> v;
	for(int i = 0; i < n; i++) {
		ll a; cin >>a;
		v.pb(a);
	}
	sort(v.begin(), v.end(), greater<ll>());
	for(int i = 1; i < n; i++) v[i] += v[i-1];
	
	int qtd = 1;
	ll sum = 0;
	while(qtd <= n) {
		sum += v[qtd-1];
		qtd *= 4;
	}

	cout <<sum <<endl;
	return 0;
}

