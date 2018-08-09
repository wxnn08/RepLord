#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
			//avaliacao,preco
vector<pair<int,int>> v;
int dp[10000][1000];

int solve(int val, int pos){
	if(val==0) return 0;
	if(val<0) return -INF;
	if(pos>=v.size()) return 0;

	if(val<10000 && pos<1000){
		int &r = dp[val][pos];
		if(r!=-1) return r;
	}

	int L = solve(val-(v[pos].fi), pos+1)+v[pos].sec;
	int R = solve(val, pos+1);

	if(val<10000 && pos<1000){
		int &r = dp[val][pos];
		return r = max(L, R);
	}
	return max(L,R);
}

int main(){
    ios_base::sync_with_stdio(false);
	
	int TC;
    cin >>TC;
	while(TC--){
		int n;
		cin >>n;
		v.clear();
		memset(dp, -1, sizeof dp);
		fori(i,0,n){
			int u, g;
			cin >>u >>g;
			v.pb(mk(u,g));
		}
		int val;
		cin >>val;
		cout <<solve(val, 0) <<endl;
	}
    
    return 0;
}

