#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 2e5 + 5;
int deck[N];
set<int> g[N];
bool visit[N];

bool solve(int at) {
	if(at == 1) return true;
	if(visit[at]) return false;
	visit[at] = true;
	
	set<int>::iterator it;
	bool ans = false;
	for(it = g[at].begin(); !ans and it != g[at].end(); it++) {
		ans |= solve(*it);
	}

	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n; cin >>n;
    for(int i = 1; i <= n; i++) {
		int t; cin >>t;
		deck[t] = i;
	}
	
	int q; cin >>q;
	for(int i = 0; i < q; i++) {
		for(int j = 1; j <= n; j++) {
			int t; cin >>t;
			g[j].insert(t);
		}
	}
	
	int x; cin >>x;

	cout <<(solve(deck[x])? "YES": "NO") <<endl; 

    return 0;
}

