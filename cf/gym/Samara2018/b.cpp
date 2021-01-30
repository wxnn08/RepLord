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
const ll INF = LLONG_MAX;
const double PI = acos(-1.0);
 
const int N = 2e5+10;
ii l[N];
ll calc(int i) {
	ll a = l[i].fi*l[i+1].se+l[i].se*l[i+2].fi+l[i+1].fi*l[i+2].se;
	ll b = l[i+1].se*l[i+2].fi+l[i].se*l[i+1].fi+l[i].fi*l[i+2].se;

	return a-b;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;
	
	ll ans;

	for(int i = 0; i < n; i++) {
		cin >>l[i].fi >>l[i].se;
	}
	l[n] = l[0];
	l[n+1] = l[1];
	
	ans = calc(0);
	for(int i = 0; i < n; i++) {
		ans = min(ans, calc(i));
	}

	cout <<ans <<endl;
    
    return 0;
}

