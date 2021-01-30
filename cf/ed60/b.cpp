#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    ios_base::sync_with_stdio(false);

	ll n, m, k;
	cin >>n >>m >>k;
	vector<ll> v;
	for(int i = 0; i < n; i++) {
		ll a; cin >>a;
		v.pb(a);
	}
    sort(v.begin(), v.end(), greater<ll>());

	ll ans = m/(k+1)*(k*v[0] + v[1]);
	ans += m%(k+1)*v[0];

	cout <<ans <<endl;

    return 0;
}

