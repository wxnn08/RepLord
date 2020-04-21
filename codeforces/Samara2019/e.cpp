#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 3e6 + 5;
ii seg[4*N+1];
ii lazy[4*N+1];

void prop(int r, int i, int j){
	seg[r] = max(seg[r], lazy[r]);
	
	if(i != j) {
		lazy[2*r] = max(lazy[2*r], lazy[r]);
		lazy[2*r+1] = max(lazy[2*r+1], lazy[r]);
	}
	lazy[r] = mk(0, 0);
}

ii query(int r, int i, int j, int a, int b){
	prop(r,i,j);
	if(i >b or j<a) return ii(0, 0);
	if(i>=a and j<=b) return seg[r];
	
	int mid = (i+j)>>1;
	return max(query(2*r, i, mid, a, b), query(2*r+1, mid+1, j, a, b));
}

void update(int r, int i, int j, int a, int b, ii v){
	prop(r, i, j);
	if(i>b or j<a) return;
	if(i>=a and j<=b) {
		lazy[r] = max(lazy[r], v);
		prop(r, i, j);
		return;
	}
	int mid = (i+j)>>1;
	update(2*r, i, mid, a, b, v);
	update(2*r+1, mid+1, j, a , b, v);
	seg[r] = max(seg[2*r], seg[2*r+1]);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >>n >>m;
	vector<ii> in;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		int a, b; cin >>a >>b;
		v.pb(a); v.pb(b);
		v.pb(max(1, a-1)); v.pb(max(1, b-1));
		v.pb(max(m, a+1)); v.pb(min(b+1, m));
		in.eb(a, b);
	}
	v.pb(1);
	v.pb(m);

	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for(auto &at:in) {
		at.fi = lower_bound(v.begin(), v.end(), at.fi) - v.begin() + 1;
		at.se = lower_bound(v.begin(), v.end(), at.se) - v.begin() + 1;
	}
	m = lower_bound(v.begin(), v.end(), m) - v.begin() + 1;

	for(int i = 0; i < in.size(); i++) {
		ii at = in[i];
		update(1, 1, m, at.fi, at.se, mk(at.se+1, i+1));
	}
	
	int last = 1;
	vector<int> ans;
	while(last > 0) {
		ii v = query(1, 1, m, last, last);
		ans.pb(v.se);
		if(v.fi == m+1) {
			cout <<"YES" <<endl;
			cout <<ans.size() <<endl;
			for(auto at:ans) cout <<at <<' ';
			cout <<endl;
			return 0;
		}
		last = v.fi;
	}
	cout <<"NO" <<endl;
	
	return 0;
}

