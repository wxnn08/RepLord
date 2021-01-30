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

	vector<ll> v, t;
	int n;
	cin >>n;

	ll maior = -1;
	for(int i = 0; i < n; i++) {
		ll a;
		cin >>a;
		maior = max(maior, a);
		v.pb(a);
	}

	ll z = -1;
	for(int i = 0; i < n; i++) {
		ll at = maior-v[i];
		if(at == 0) continue;
		if(z == -1) z = at;
		else z = __gcd(z, at);
	}
	
	ll y = 0;
	for(auto at:v) {
		y += ((maior-at)/z);
	}
	cout <<y <<' ' <<z <<endl;

	return 0;
}

