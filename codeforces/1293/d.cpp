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
 
const ll N = (1LL<<62);

ll dist(ii s, ii t) {
	return abs(s.fi-t.fi) + abs(s.se-t.se);
}

int main() {
    ios_base::sync_with_stdio(false);

	ll x0,y0,ax,ay,bx,by,xs,ys,t;
	cin >>x0 >>y0 >>ax >>ay >>bx >>by >>xs >>ys >>t;
	
	vector<ii> p;
	ll x = x0, y = y0;
	while(true) {
		p.eb(x,y);
		if((N-bx)/ax < x or (N-by)/ay < y) break;
		x = ax*x + bx;
		y = ay*y + by;
	}
	
	ii ori = ii(xs, ys);
	int ans = 0;
	for(int i = 0; i < p.size(); i++) {
		for(int j = 0; j < p.size(); j++) {
			ll cost = dist(ori, p[i]);
			if(cost > t) continue;
			if(dist(p[i], p[j]) <= t - cost) ans = max(ans, abs(i-j)+1);
 			
		}
	}
	cout <<ans <<endl;
    return 0;
}

