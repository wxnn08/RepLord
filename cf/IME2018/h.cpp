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
typedef pair<pair<int,int>, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e3 + 5;
int node {
	int dist, con;

	bool operator > (const node &t) const {
		return dist > t.dist;
	}
};

vector<ii> g[N];
iii dist[N];
bool visit[N];

void dij(int ini, int cost) {


	pq.push(ii(dist[ini], ini));

	while(!pq.empty()) {
		ii at = pq.top();
		pq.pop();
		if(visit[at.se]) continue;
		visit[at.se] = true;
		
		for(ii viz:g[at.se]) {
			if(dist[at.se]+viz.se < dist[viz.fi]) {
				dist[viz.fi] = dist[at.se] + viz.se;
				pq.push(ii(dist[viz.fi], viz.fi));
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >>n >>m;
	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >>a >>b >>c;
		g[a].eb(b, c);
	}

	int q;
	cin >>q;
	while(q--) {
		int dest, cost;
		cin >>dest >>cost;
		if(dist[dest] <= cost) cout <<"=] " <<dist[dest] <<endl;
		else cout <<"=[" <<endl;
	}

	return 0;
}

