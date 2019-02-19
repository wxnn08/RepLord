#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<ll,ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e5 + 5;
ii p[N];
ll xi, yi, xf, yf, n;

bool possible(ll day) {
	ll x = xi + (day/n)*p[n].fi;
	ll y = yi + (day/n)*p[n].se;
	x += p[day%n].fi;
	y += p[day%n].se;
	
	ll qtd = abs(xf-x)+abs(yf-y);
	return qtd <= day;
}

int main() {
    ios_base::sync_with_stdio(false);

	cin >>xi >>yi >>xf >>yf >>n;
	
	for(int i = 1; i <= n; i++) {
		char c; cin >>c;
		if(c == 'L') p[i] = mk(p[i-1].fi-1, p[i-1].se);
		if(c == 'R') p[i] = mk(p[i-1].fi+1, p[i-1].se);
		if(c == 'U') p[i] = mk(p[i-1].fi, p[i-1].se+1);
		if(c == 'D') p[i] = mk(p[i-1].fi, p[i-1].se-1);
	}

	ll ini = 0, fim = 1e17+5, mid;
	while(ini <= fim) {
		mid = (ini+fim)>>1;
		if(possible(mid)) fim = mid-1;
		else ini = mid+1;
	}

	cout <<(ini>=1e17? -1:ini) <<endl;

    return 0;
}

