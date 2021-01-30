/* Feito por wxn_ em 29/08/2020*/
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
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
using namespace std;

const int N = 1e3 + 5;
vector<ll> g[N];
bool visited[N];

struct Point {
    ll x;
    ll y;
};

bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

ll orientation(Point p, Point q, Point r) {
    ll val1 = (q.y - p.y) * (r.x - q.x);
	ll val2 = (q.x - p.x) * (r.y - q.y);
	ll val = val1 - val2;
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    ll o1 = orientation(p1, q1, p2);
    ll o2 = orientation(p1, q1, q2);
    ll o3 = orientation(p2, q2, p1);
    ll o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4) return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false;
}

void createGraph(ll n) {
	vector<pair<Point, Point>> ls;

	for(ll i = 0; i < n; i++) {
		ll p1, q1, p2, q2; cin >>p1 >>p2 >>q1 >>q2;
		pair<Point, Point> lineIn = mk(Point({p1, p2}), Point({q1, q2}));

		for(ll j = 0; j < ls.size(); j++) {
			pair<Point, Point> lineCurr = ls[j];
			if(doIntersect(lineIn.fi, lineIn.se, lineCurr.fi, lineCurr.se)) {
				g[i].pb(j);
				g[j].pb(i);
			}
		}
		ls.pb(lineIn);
	}
	return;
}

ll atomCyclesQuantity(ll curr, ll parent) {
	visited[curr] = true;
	ll ans = 0;
	for(auto viz : g[curr]) {
		ans += (visited[viz] and viz != parent);
		if(!visited[viz]) ans += atomCyclesQuantity(viz, curr);
	}
	return ans;
}

void printGraph(ll n) {
	for(ll i = 0; i < n; i++) {
		cout <<i <<": ";
		for(auto viz : g[i]) {
			cout <<viz <<' ';
		}
		cout <<endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n; cin >>n;

	createGraph(n);
	cout <<atomCyclesQuantity(0, -1)/2LL <<endl;

	return 0;
}
