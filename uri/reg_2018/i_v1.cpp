#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int N = 1e5 + 5;
int dp[N][5];
vector<int> g[N];

/*
 0 - posso iniciar boneco
 1 - tronco
 2 - braços
 3 - bunda
 4 - pés
*/

int solve(int no, int pos) {

	int &r = dp[no][pos];
	if(r != -1) {
		return r;
	}
	
	if(pos == 0 or pos == 2 or pos == 4) {
		int ans = 0;
		for(int i = 0; i < g[no].size(); i++) {
			int L = solve(g[no][i], 1) + 1;
			int R = solve(g[no][i], 0);
			ans += max({L, R});
		}
		return r = ans;
	}
	if(pos == 1) {
		if(g[no].size() < 3)
			return r = -INF;
		
		//melhores bundas
		vector<ii> v;
		for(int i = 0; i < g[no].size(); i++)
			v.eb(solve(g[no][i], 3), g[no][i]);
		sort(v.begin(), v.end(), greater<ii>());
		
		cout <<"no: " <<no <<" - pos: " <<pos <<endl;

		for(auto t:v) cout <<t.fi <<'-' <<t.sec <<' ';
		cout <<endl;

		//melhores braços
		vector<ii> vv;
		for(int i = 0; i < g[no].size(); i++)
			vv.eb(solve(g[no][i], 2), i);
		sort(vv.begin(), vv.end(), greater<ii>());
		
		int ans = -INF;
		for(int i = 0; i < min((int)v.size(), 3); i++) {
			for(int j = 0; j < min((int)vv.size(), 3); j++) {
				for(int k = j+1; k < min((int)vv.size(), 3); k++) {
					if(v[i].sec != v[j].sec and vv[i].sec != vv[k].sec) {
						if(v[i].fi > 0 and ans < v[i].fi + vv[j].fi + vv[k].sec) {
							
						}
					}
				}
			}
		}
		return r = ans;
	}
	if(pos == 3) {
		if(g[no].size() < 2)
			return r = -INF;

		//melhores pes
		vector<ii> v;
		for(int i = 0; i < g[no].size(); i++)
			v.eb(solve(g[no][i], 4), i);
		sort(v.begin(), v.end(), greater<ii>());
		
		return r = v[0].fi + v[1].fi;	
	}
	return -INF;
}

int main(){
    ios_base::sync_with_stdio(false);

	memset(dp, -1, sizeof(dp));
    int n;
	cin >>n;
	for(int i = 2; i <= n; i++) {
		int a; cin >>a;
		g[a].pb(i);
	}
    
	cout <<solve(1, 0) <<endl;

    return 0;
}

