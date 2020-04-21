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

int calc(vector<int> ds, vector<int> &ins) {
	vector<ii> groups;
	groups.eb(ds[0], 1);
	for(int i = 1; i < ds.size(); i++) {
		if(ds[i] == ds[i-1]+1) groups.back().se++;
		else groups.eb(ds[i], 1);
	}
	
	int ans = 0, acum = 0, qtd = 0;
	for(auto g:groups) {
		qtd = 0;
		for(auto in:ins) 
			if(g.fi-52 <= in) qtd++;
		ans += (g.se*(52-(qtd+acum)));
		acum += g.se;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	vector<int> ins;
	for(int i = 0; i < 4; i++) { 
		int a; cin >>a;
		ins.pb(a);
	}


	// int vv = calc({1, 2, 3 ,5}, ins);
	// cc(vv);
	// return 0;

	int ans = INF;
	vector<int> v;
	for(int i = 1; i <= 52; i++)
		for(int j = i+1; j <= 52; j++)
			for(int k = j+1; k <= 52; k++)
				for(int l = k+1; l <= 52; l++) {
					int val = calc({i+52, j+52, k+52, l+52}, ins);
					if(val < ans) ans = val, v = {i, j, k, l};
				}

	for(auto at:v)
		cout <<at <<' ';
	cout <<endl;
	
	return 0;
}

