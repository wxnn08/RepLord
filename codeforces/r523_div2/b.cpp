#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

bool comp(int a, int b) {
	return a > b;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, m;
	cin >>n >>m;

	vector<ll> v;
	for(int i = 0; i < n; i++) {
		ll a; cin >>a;
		v.pb(a);
	}

	sort(v.begin(), v.end(), comp);
	ll posh = v[0];
	ll ans = 0;
	vector<ll> p;
	for(int i = 0; i < n-1; i++) {
		ll dif = max(1LL, posh - v[i+1]);
		p.pb(dif);
		if(posh > 0) posh = posh - dif;
	}

	p.pb(max(1LL, posh));

	for(int i = 0; i < n; i++)
		ans += v[i]-p[i];

	cout <<ans <<endl;

    return 0;
}

