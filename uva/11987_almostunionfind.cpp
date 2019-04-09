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

struct node {
	ll pai, qtd, sum;
};

const int N = 1e5+5;
int v[N];
node p[N];

node find(ll x) {
	if(p[x].pai == x) return p[x];
	return find(p[x].pai);
}

void join(ll x, ll y) {
	node a = find(v[x]);
	node b = find(v[y]);
	if(a.pai == b.pai) return;

	if(a.qtd > b.qtd) swap(a, b);
	p[a.pai].pai = b.pai;
	p[b.pai].qtd += a.qtd;
	p[b.pai].sum += a.sum;
}

void move(ll x, ll y) {
	node a = find(v[x]);
	node b = find(v[y]);

	if(a.pai == b.pai) return;
	
	v[x] = b.pai;
	p[a.pai].qtd--;
	p[b.pai].qtd++;
	p[a.pai].sum -= x;
	p[b.pai].sum += x;
}

int main() {
    ios_base::sync_with_stdio(false);

	ll n, m;
	while(cin >>n >>m) {
		for(ll i = 0; i <= n; i++) {
			v[i] = i;
			p[i] = node({i, 1, v[i]});
		}
		
		for(int i = 0; i < m; i++) {
			int op, a, b;
			cin >>op >>a; 
			if(op == 1) {
				cin >>b;
				join(a, b);
			}
			if(op == 2) {
				cin >>b;
				move(a, b);
			}
			if(op == 3) {
				node ans = find(v[a]);
				cout <<ans.qtd <<' ' <<ans.sum <<endl;
			}
		}
	}

    return 0;
}

