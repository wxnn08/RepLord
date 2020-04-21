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
typedef pair<ll,ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

ii oper(ll a, ll b) {
	if(a >= 2*b) {
		ll v = a/(2*b);
		if(v == 0) v++;
		v = v*(2*b);
		a -= v;
	}
	else if(b >= 2*a) {
		ll v = b/(2*a);
		if(v == 0) v++;
		v = v * (2*a);
		b -= v;
	}
	return ii(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);

	ll a, b;
	cin >>a >>b;

	while(a > 0 and b > 0) {
		if(a == 0 or b == 0) break;
		ii ans = oper(a, b);
		if(ans.fi == a and ans.se == b) break;
		a = ans.fi;
		b = ans.se;
	}
	cout <<a <<' ' <<b <<endl;
	return 0;
}

