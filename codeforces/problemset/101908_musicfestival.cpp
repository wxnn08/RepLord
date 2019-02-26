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

struct show {
	int ini, fim, c, stage;
	bool operator < (const show &a) const {
		return ini < a.ini;
	}
};

const int M = 1e3 + 5;
const int N = 2e3;
int to[M];
int dp[M][N];
int goal = 0;
vector<show> v;

int nextShow(int fim) {
	int l = 0, r = v.size()-1, mid;
	while(l < r) {
		mid = (l+r)>>1;
		if(v[mid].ini >= fim) r = mid;
		else l = mid+1;
	}
	if(v[l].ini < fim) return v.size();
	return l;
}

int solve(int at, int mask) {
	if(at == v.size()) {
		if(mask == goal) return 0;
		return -INF;
	}
	
	int &r = dp[at][mask];
	if(r != -1) return r;

	int L = solve(at+1, mask);
	int R = solve(to[at], mask|(1<<v[at].stage)) + v[at].c;

	return r = max(L, R);
}

int main() {
    ios_base::sync_with_stdio(false);
	
	int n; cin >>n;

	for(int st = 0; st < n; st++) {
		int qt; cin >>qt;
		while(qt--) {
			int a, b, c; cin >>a >>b >>c;
			v.pb(show({a,b,c,st}));
		}
		goal |= 1<<st;
	}

	sort(v.begin(), v.end());
    
	for(int i = 0; i < v.size(); i++) 
		to[i] = nextShow(v[i].fim);
	
	memset(dp, -1, sizeof dp);
	int ans = solve(0, 0);
	cout <<(ans<0?-1:ans) <<endl;
    return 0;
}

