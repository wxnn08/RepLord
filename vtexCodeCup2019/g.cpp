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

const int N = 1e5 + 5;

struct node {
	ll t, d, id;

	bool operator < (const node &k) const {
		if(t != k.t) return t < k.t;
		return id < k.id;
	}
};

struct fila {
	ll tf, id;
};

pair<char, ll> ans[N];
vector<node> v;

int main() {
    ios_base::sync_with_stdio(false);

    int n, k;
	cin >>n >>k;

	for(int i = 0; i < n; i++) {
		int t, d;
		cin >>t >>d;
		v.pb({t, d, i});
	}

	sort(v.begin(), v.end());

	ll ta = 0, tb = 0;
	queue<ll> a, b;
	for(auto at:v) {
		while(!a.empty() and a.front() <= at.t) a.pop();
		while(!b.empty() and b.front() <= at.t) b.pop();

		if(a.size() <= b.size()) {
			if(a.size() == 0) {
				a.push(at.d+at.t);
				ta = a.front();
			} else {
				a.push(ta+at.d);
				ta += at.d;
			}
			ans[at.id] = mk('A', ta);
		} else {
			if(b.size() == 0) {
				b.push(k*at.d+at.t);
				tb = b.front();
			} else {
				b.push(tb+(k*at.d));
				tb += k*at.d;
			}
			ans[at.id] = mk('B', tb);
		}
	}
	
	for(int i = 0; i < n; i++) {
		cout <<ans[i].fi <<' ' <<ans[i].se <<endl;
	}
    
    return 0;
}

