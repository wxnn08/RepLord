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
typedef pair<ll,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 2e5 + 5;
ii v[N];

bool cmp(ii a, ii b) {
	return a.se < b.se;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, m, k;
	cin >>n >>m >>k;

	for(int i = 0; i < n; i++) {
		cin >>v[i].fi;
		v[i].se = i;
	}

	sort(v, v+n, greater<ii>());
	sort(v, v+(m*k), cmp);
	
	ll ans = 0;
	vector<int> ansp;
	for(int i = 0; i < m*k; i++) {
		ans += v[i].fi;
		if((i+1)%m == 0 and i != (m*k)-1) {
			ansp.pb(v[i].se+1);
		}
	}

	cout <<ans <<endl;
	for(auto at:ansp) {
		cout <<at <<' ';
	}
	cout <<endl;
    
    return 0;
}

