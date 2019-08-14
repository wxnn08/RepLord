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

const int N = 2e5 + 5;
bool visit[N][2];
vector<int> g[N];
int dist[N][2];

void preenche(int at, int val, int player) {
	dist[at][player] = val;
	visit[at][player] = true;
	for(int viz:g[at]) {
		if(!visit[viz][player]) 
			preenche(viz, val+1, player);
	}
}

int procuraMaior(int at) {
	int ans = at;
	for(int i = 1; i < N; i++) {
		if(dist[i][1] < dist[i][0]) {
			if(dist[i][0] > dist[ans][0])
				ans = i;
		}
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);

	int n, x;
	cin >>n >>x;

	for(int i = 0; i < n-1; i++) {
		int a, b; cin >>a >>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	preenche(1, 0, 0); //Alice
	preenche(x, 0, 1); //Bob
	int no = procuraMaior(x);
	
	cout <<dist[no][0]*2 <<endl;

    return 0;
}

