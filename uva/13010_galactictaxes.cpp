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
typedef pair<double,int> di;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct node {
	int no;
	double A, B;
};

const int N = 1e3 + 5;
int n, m;
vector<node> g[N];

double tax(int ini, double t) {
	
	double d[N];
	bool visit[N];
	for(int i = 1; i <= n; i++) {
		d[i] = 99999999999999999.0;
		visit[i] = false;
	}

	double ans = 99999999999999999.0;

	priority_queue<di, vector<di>, greater<di>> pq;
	d[ini] = 0;
	pq.push(di(d[ini], ini));

	//double ans = 0;
	
	while(!pq.empty()) {
		int no = pq.top().se;
		pq.pop();

		if(visit[no]) continue;
		visit[no] = true;

		if(no > 1) ans = min(ans, d[no]);

		for(int i = 0; i < g[no].size(); i++) {
			node at = g[no][i];
			if(d[at.no] > d[no] + ((at.A*t)+at.B)) {
				d[at.no] = d[no] + ((at.A*t)+at.B);
				pq.push(di(d[at.no], at.no));
			}
		}
	}

	return d[n];
}

double tsearch(double l, double r) {
	int it = 200;
	while(it--) {
		double m1 = l + (r-l)/3;
		double m2 = r - (r-l)/3;
		if(tax(1, m1) < tax(1, m2)) l = m1;
		else r = m2;
	}
	return tax(1, l);
}

int main() {
	while(cin >>n >>m) {
		for(int i = 1; i <= n; i++) 
			g[i].clear();
		for(int i = 0; i < m; i++) {
			int x, y; double a, b;
			cin >>x >>y >>a >>b;
			g[x].pb({y, a, b});
			g[y].pb({x, a, b});
		}
		
		printf("%.5f\n", tsearch(0, 1440));
	}

    return 0;
}

