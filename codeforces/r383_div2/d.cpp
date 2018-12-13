#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

struct grupo {
	vector<ii> v;
	int totalP, totalB;
};

const int N = 1e3 + 5;
vector<int> g[N];
ii gps[N];
ii garotas[N]; 
vector<grupo> gg;
int dp[N][N], qtdGrupos;

void dfs(int at, int cont) {
	if(gps[at].fi != 0) return;
	gps[at].fi = cont;
	gps[at].sec = at;
	for(int i = 0; i < g[at].size(); i++) {
		dfs(g[at][i], cont);
	}
	return;
}

int solve(int peso, int grup) {
	if(peso < 0) return -INF;
	if(peso == 0 or grup >= qtdGrupos) return 0;
	
	int &r = dp[peso][grup];
	if(r > 0) return r;

	int A, B, C = -INF;
	A = gg[grup].totalB + solve(peso-gg[grup].totalP, grup+1);
	B = solve(peso, grup+1);
	for(int i = 0; i < gg[grup].v.size(); i++) {
		int pg = gg[grup].v[i].fi;
		int bg = gg[grup].v[i].sec;
		C = max(bg + solve(peso-pg, grup+1), C);
	}
	return r = max(A, max(B, C));
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, m, w;
	cin >>n >>m >>w;
	fori(i, 1, n+1) cin >>garotas[i].fi;
	fori(i, 1, n+1) cin >>garotas[i].sec;
	while(m--) {
		int a, b; cin >>a >>b;
		g[a].pb(b); g[b].pb(a);
	}
    
	int cont = 1;
	for(int i = 1; i <= n; i++)
		if(gps[i].fi == 0) dfs(i, cont++);
	
	sort(gps+1, gps+n+1);
	
	for(int i = 1; i <= n; i++) {
		int atg = gps[i].fi;
		int atp = gps[i].sec;
		if(gg.size() < atg) {
			grupo tmp;
			tmp.totalP = garotas[atp].fi;
			tmp.totalB = garotas[atp].sec;
			tmp.v.pb(ii(garotas[atp].fi, garotas[atp].sec));
			gg.pb(tmp);
		} else {
			gg[atg-1].v.pb(ii(garotas[atp].fi, garotas[atp].sec));
			gg[atg-1].totalP += garotas[atp].fi;
			gg[atg-1].totalB += garotas[atp].sec;
		}
	}
	
	qtdGrupos = cont - 1;
	memset(dp, -1, sizeof(dp));
	cout <<solve(w, 0) <<endl;

    return 0;
}

