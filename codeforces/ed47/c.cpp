#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

double solve(ll n, ll x, ll d) {
	ll v = 0;

	for(ll i = 0; i < n; i++) {
		v += (x + i*d);
	}

	return (double)v/n;
}

int main(){
    ios_base::sync_with_stdio(false);

    ll n, m;
	cin >>n >>m;
	ll x = 0, d = 0;
	for(int i = 0; i < m; i++) {
		ll a, b;
		cin >>a >>b;
		x += a;
		d += b;
	}

	double ans = solve(n, x, d);
    cout <<fixed <<setprecision(9) <<ans <<endl; 

    return 0;
}

