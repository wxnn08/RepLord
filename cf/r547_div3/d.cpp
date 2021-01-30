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
 
int main() {
	ios_base::sync_with_stdio(false);
	
	int n; cin >>n;
	string a, b;
	cin >>a >>b;
	

	int cl = 0, cr = 0;
	string nl = "", nr = "";

	vector<pair<char, int>> l, r;
	
	for(int i = 0; i < n; i++) {
		l.pb(mk(a[i], i+1));
		r.pb(mk(b[i], i+1));
	}

	sort(l.begin(), l.end());
	sort(r.begin(), r.end());

	vector<ii> ans;
	vector<pair<char, int>> vl;
	vector<pair<char, int>> vr;
	
	while(cl < n or cr < n) {
		if(cl >= n) {
			while(cr < n) {
				vr.pb(mk(r[cr].fi, r[cr].se));
				cr++;
			}
			break;
		}
		if(cr >= n) {
			while(cl < n) {
				vl.pb(mk(l[cl].fi, l[cl].se));
				cl++;
			}
			break;
		}
		if(l[cl].fi == '?') {
			vl.pb(mk(l[cl].fi, l[cl].se));
			cl++;
			continue;
		}
		if(r[cr].fi == '?') {
			vr.pb(mk(r[cr].fi, r[cr].se));
			cr++;
			continue;
		}
		if(l[cl].fi != r[cr].fi) {
			if(l[cl].fi < r[cr].fi) {
				vl.pb(mk(l[cl].fi, l[cl].se));
				cl++;
			} else {
				vr.pb(mk(r[cr].fi, r[cr].se));
				cr++;
			}
		}
		else {
			ans.pb(mk(l[cl].se, r[cr].se));
			cr++;
			cl++;
		}
	}
	
	if(vl.size() > 0 and vr.size() > 0) {
		for(int i = 0; i < vl.size(); i++) {
			if(vl[i].fi == '?' or vr[vl.size()-1-i].fi == '?') {
				ans.pb(mk(vl[i].se, vr[vl.size()-1-i].se));
			}
		}
	}
	
	cout <<ans.size() <<endl;
	
	for(auto at:ans) {
		cout <<at.fi <<' ' <<at.se <<endl;
	}

	return 0;
}

