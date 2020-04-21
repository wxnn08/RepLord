#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " -> " << x << endl

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 100+5;

int n;
vector<int> g[N];
int dp[N][2];


int solve(int at, bool pai, int par){
	
	int L = 1, R = 0;
	
	int &r = dp[at][pai];
	if(r!=-1) return r;

	for(int i=0; i<g[at].size(); i++){
		int next = g[at][i];
		if(next == par) continue;
		L += solve(next, true, at);
		R += solve(next, false, at);
	}
	
	if(pai==false) return r = L;

	return r = min(L,R);
}

int ans[N];
void trace(int at, bool pai, int par){
	
	int L = 1, R = 0;

	for(int i=0; i<g[at].size(); i++){
		int next = g[at][i];
		if(next == par) continue;
		L += dp[next][1];
		R += dp[next][0];
	}
	
	if(pai==false or L<R) {
		ans[at] = 1;
		for(int i=0; i<g[at].size(); i++){
			int next = g[at][i];
			if(next == par) continue;
			trace(next, 1, at);
		}
	} else {
		ans[at] = 0;
		for(int i=0; i<g[at].size(); i++){
			int next = g[at][i];
			if(next == par) continue;
			trace(next, 0, at);
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
	
	freopen("input.txt", "r+", stdin);
	freopen("output.txt", "w+", stdout);

	cin >>n;

	fori(i,0,n-1){
		int a, b;
		cin >>a >>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	memset(dp, -1, sizeof dp);
	solve(1,1,0); 
	
	trace(1,1,0);

	if(n==1){
		cout <<1 <<endl;
		return 0;
	}

	fori(i,1,n+1) cout <<ans[i] <<' ';
	cout <<endl;

    return 0;
}

