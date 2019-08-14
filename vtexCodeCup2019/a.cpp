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

vector<pair<int,int>> v;

int main() {
    ios_base::sync_with_stdio(false);

    int n; cin >>n;
	for(int i = 0; i < n; i++) {
		int ti, tf;
		cin >>ti >>tf;
		v.eb(ti, tf);
	}
	
	sort(v.begin(), v.end());
	
	int at = 0, ans = 0;
	while(at < v.size()) {
		int mi = v[at].fi, mf = v[at].se;
		int dif = 0;

		int ini = at;
		at++;
		while(at < v.size() and v[at].fi < mf) {
			mf = max(v[at].se, mf);
			at++;
		}

		for(int i = ini+1; i < at; i++) {
			ans = max(ans, v[i].fi-v[i-1].fi);
		}
		ans = max(ans, mf-v[at-1].fi);
	}

	cout <<ans <<endl;
    
    return 0;
}

