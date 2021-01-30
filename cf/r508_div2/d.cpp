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

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 2*1e2+5;
struct node{
	int c1, v, c2;
	bool operator<(const node &o) const{
		return v<o.v;
	}
};
int cont;
map<string,int> m;
vector<string> v;
vector<int> g[N];
int vis[N];

string cria(int a, int b, int c){
	return ""+a+"."+b+"."+c.
}

ll dfs(int at){
	if(vis[at]==true) return 0;
	vis[at] = true;
	ll ans = v[at].v;
	for(int i=0; i<g[at].size(); i++){
		ans += dfs(g[at][i]);
	}
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	int n;
	cin >>n;
	
	fori(i,0,n){
		int u, p, q;
		cin >>u >>p >>q;
		v.pb(cria(u,p,q));
		v.pb(cria(q,p,u));
	}


	cont = 0;
	fori(i,0,v.size()){
		cout <<v[i].c1 <<' ' <<v[i].v <<' ' <<v[i].c2 <<endl;
		cc(m[v[i]]);
		if(m[v[i]]==0){	
			m[v[i]] = cont++;
			ok;
		}
	}

	map<node, int>::iterator it;
	for(it = m.begin(); it!=m.end(); it++){
		cout <<(it->fi).v <<"->" <<it->sec <<endl;
	}
	
	fori(i,0,cont){
		fori(j,i+1+(i%2==0), cont){
			if(v[i].c2 == v[j].c1)
				g[m[v[i]]].pb(m[v[j]]);
		}
	}
	
	ll maior = 0;
	fori(i,0,cont){
		memset(vis, 0, sizeof vis);
		maior = max(maior, dfs(i));
	}

	cout <<maior <<endl;
    return 0;
}

