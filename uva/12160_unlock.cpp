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

const int N = 1e4;
vector<int> sum;

int bfs(int ini, int fim) {
	
	bool visit[N];
	memset(visit, 0, sizeof visit);
	queue<ii> q;
	q.emplace(ini, 0);
	visit[ini] = true;

	while(!q.empty()) {
		int at = q.front().fi;
		int w  = q.front().se;
		if(at == fim) return w;
		q.pop();
		for(auto s:sum) {
			int viz = (at+s)%N;
			if(visit[viz]) continue;
			visit[viz] = true;
			q.emplace(viz, w+1);
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);

	int l, u, r;
	int tc = 1;
	while(cin >>l >>u >>r) {
		if(l == 0 and u == 0 and r == 0) return 0;
		sum.clear();
		for(int i = 0; i < r; i++) {
			int a; cin >>a;
			sum.pb(a);
		}
		cout <<"Case " <<tc++ <<": ";
		int ans = bfs(l, u);
		if(ans == -1) cout <<"Permanently Locked" <<endl;
		else cout <<ans <<endl;
	}
	
	return 0;
}

