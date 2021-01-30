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
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct cel {
	ll val;
	int a, b;

	bool operator <(const cel &a) const {
		return val < a.val;
	}
};


int n, m;
ll s1 = 0, s2 = 0;
ll ans = 0;
int nop = 0;
ii pri, sec;

void calc(auto at, auto it) {
	if(abs((s1-at.val+(it->val)) - (s2+at.val-(it->val))) < ans) {
		ans = abs((s1-at.val+(it->val)) - (s2+at.val-(it->val)));
		nop = 2;
		pri = mk(at.a, it->a);
		sec = mk(at.b, it->b);
	}
}

int main() {
    ios_base::sync_with_stdio(false);

	vector<ii> va, vb;
	cin >>n;
	for(int i = 0; i < n; i++) {
		int a; cin >>a;
		va.eb(a, i+1);
		s1 += a;
	}

	cin >>m;
	for(int i = 0; i < m; i++) {
		int a; cin >>a;
		vb.eb(a, i+1);
		s2 += a;
	}
	
	ans = abs(s1-s2);
	if(ans == 0) {
		cout <<0 <<endl <<0 <<endl;
		return 0;
	}
	ll t = s2-s1;

	vector<cel> v, w;
	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			v.pb({va[i].fi+va[j].fi, i+1, j+1});
		}
	}
    
	for(int i = 0; i < m; i++) {
		for(int j = i+1; j < m; j++) {
			w.pb({vb[i].fi+vb[j].fi, i+1, j+1});
		}
	}
	
	sort(vb.begin(), vb.end());
	for(int i = 0; i < n; i++) {
		ll val = (t+(2*va[i].fi))/2;
		auto it = lower_bound(vb.begin(), vb.end(), ii(val, 0));
		if(abs((s1-va[i].fi+(it->fi)) - (s2+va[i].fi-(it->se))) < ans) {
			ans = abs((s1-va[i].fi+(it->fi)) - (s2+va[i].fi-(it->se)));
			pri = ii(va[i].se, it->se);
			nop = 1;
		}
	}
	sort(w.begin(), w.end());
	
	for(auto at: v) {
		ll val = (t+(2*at.val))/2;
		auto it = lower_bound(w.begin(), w.end(), cel({val, 0, 0}));
		calc(at, it);
		if(it != w.begin()) calc(at, it-1);
		if(it != w.end()-1) calc(at, it+1);
	}

	cout <<ans <<endl;
	if(nop == 0) {
		cout <<0 <<endl;
		cout <<0 <<endl;
	}
	if(nop == 1) {
		cout <<nop <<endl;
		cout <<pri.fi <<' ' <<pri.se <<endl;
	}
	if(nop == 2) {
		cout <<nop <<endl;
		cout <<pri.fi <<' ' <<pri.se <<endl;
		cout <<sec.fi <<' ' <<sec.se <<endl;
	}

    return 0;
}

