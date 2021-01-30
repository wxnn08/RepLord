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
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e5 + 5;
ii seg[4*N+1];
ll lazy[4*N+1];

void prop(int r, int i, int j){
	seg[r].fi -= lazy[r]*(j-i+1);
	
	if(i != j) {
		lazy[2*r] += lazy[r];
		lazy[2*r+1] += lazy[r];
	}
	lazy[r] = 0;
}

ll query(int r, int i, int j, int a, int b){
	prop(r,i,j);
	if(i > b or j < a) return 0;
	if(i>=a and j<=b) return seg[r].fi;
	
	int mid = (i+j)>>1;
	return query(2*r, i, mid, a, b) + query(2*r+1, mid+1, j, a, b);
}

void update(int r, int i, int j, int a, int b, int v){
	prop(r, i, j);
	if(i>b or j<a or seg[r].fi == 0) return;
	if(i>=a and j<=b and seg[r].se >= v) {
		lazy[r] += (ll)v;
		prop(r, i, j);
		return;
	}
	int mid = (i+j)>>1;
	update(2*r, i, mid, a, b, v);
	update(2*r+1, mid+1, j, a , b, v);
	seg[r].fi = seg[2*r].fi + seg[2*r+1].fi;
	seg[r].se = min(seg[2*r].se, seg[2*r+1].se);
	return;
}

vector<ll> v;
void build(int r, int i, int j) {
	if(i > b or j < a) return;
	if(i == j) {
		seg[r].fi = seg[r].se = v[i];
		return;
	}
	int mid = (i+j)>>1;
	update(2*r, i, mid, a, b, v);
	update(2*r+1, mid+1, j, a , b, v);
	seg[r].fi = seg[2*r].fi + seg[2*r+1].fi;
	seg[r].se = min(seg[2*r].se, seg[2*r+1].se);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >>n >>q;
	for(int i = 0; i < n; i++) {
		ll a; cin >>a;
		v.pb(a);
	}
	build(1, 0, n-1);
	
	return 0;
}

