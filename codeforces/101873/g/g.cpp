/* Feito por wxn_ em 07/09/2020*/
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
typedef pair<ll,ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    ios_base::sync_with_stdio(false);

	int n; cin >>n;
	ll b = 0, s = 0;
	ii x, y, first;
	cin >>x.fi >>x.se;
	first = x;
	for(int i = 1; i < n; i++) {
		cin >>y.fi >>y.se;
		s += (x.fi*y.se - y.fi*x.se);
		b += __gcd(abs(x.fi-y.fi), abs(x.se-y.se));
		x = y;
	}
	y = first;
	s += (x.fi*y.se - y.fi*x.se);
	b += __gcd(abs(x.fi-y.fi), abs(x.se-y.se));

	cout <<(abs(s)-b+2)/2 <<endl;

    return 0;
}
