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
ii seg[4*N+1];

ii query(int r, int i, int j, int a, int b) {
	if(i > b or j < a) return ii(-INF, INF);
	if(i >= a and j <= b) return seg[r];

	int mid = (i+j)>>1;
	ii aa = query(2*r, i, mid, a, b);
	ii bb = query(2*r+1, mid+1, j, a, b);
	if(aa.fi == bb.fi) return max(aa, bb);
	if(aa.se < bb.se) return aa;
	return bb;
}

void build(int r, int i, int j, int a, int b) {
	if(i > b or j < a) return;
	if(i == j) {
		seg[r].fi = 0;
		seg[r].se = i;
		return;
	}

	int mid = (i+j)>>1;
	build(2*r, i, mid, a, b);
	build(2*r+1, mid+1, j, a, b);
	if(seg[2*r].fi == seg[2*r+1].fi) seg[r] = seg[2*r];
	else seg[r] = max(seg[2*r], seg[2*r+1]);
}

void update(int r, int i, int j, int a, int b, int v) {
	if(i > b or j < a) return;
	if(i >= a and j <= b) {
		seg[r].fi += v;
		seg[r].se = a;
		return;
	}
	int mid = (i+j)>>1;
	update(2*r, i, mid, a, b, v);
	update(2*r+1, mid+1, j, a, b, v);
	if(seg[2*r].fi == seg[2*r+1].fi) seg[r] = seg[2*r];
	else seg[r] = max(seg[2*r], seg[2*r+1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int tc;
	cin >>tc;
	
	while(tc--) {
		int n, q;
		cin >>n >>q;
		build(1, 1, n, 1, n);
			
		ii id = query(1, 1, n, 1, n);
		int t = 0;
		for(int i = 1; i <= q; i++) {
			int team, pts;
			cin >>team >>pts;
			update(1, 1, n, team, team, pts);
			ii winner = query(1, 1, n, 1, n);
			id = query(1, 1, n, id.se, id.se);

			if(winner.se != id.se) {
				if(winner.fi > id.fi) {
					id = winner;
					t = i;
				}
				if(winner.fi == id.fi and winner.se < id.se) {
					id = winner;
					t = i;
				}
			}
		}
		cout <<t <<endl;
	}

	return 0;
}
