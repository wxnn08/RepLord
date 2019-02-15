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

const int N = 1e5 + 5;
int pai[N], tam[N]; 

struct edge {
	int a, b, ord;
	bool operator < (const edge &x) const {
		return ord < x.ord;
	}
	bool operator > (const edge &x) const {
		return  ord > x.ord;
	}
};

void init(int n) {
	for(int i = 0; i < n; i++) {
		pai[i] = i;
		tam[i] = 0;
	}
	return;
}

int find(int x) {
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}

void join(int x, int y) {
	int a = find(x);
	int b = find(y);
	if(a == b) return;
	if(tam[a] > tam[b]) swap(a, b);
	pai[a] = b;
	tam[b] += tam[a];
	return;
}

vector<edge> v;

int main() {
    ios_base::sync_with_stdio(false);

    int n, m; cin >>n >>m;
	for(int i = 0; i < m; i++) {
		int a, b; cin >>a >>b;
		v.pb(edge({a, b, 0}));
	}

	int q; cin >>q;
	int cont = 0;
	for(int i = 0; i < q; i++) {
		int t; cin >>t;
		v[t-1].ord = ++cont;
	}
	init(n+1);
	sort(v.begin(), v.end());
    
	int qtd = n;
	for(int i = 0; i < v.size() and v[i].ord == 0; i++) 
		if(find(v[i].a) != find(v[i].b)) {
			qtd--;
			join(v[i].a, v[i].b);
		}

	sort(v.begin(), v.end(), greater<edge>());
	stack<int> ans;
	ans.push(qtd);

	int at = 1;
	while(at < v.size() and v[at].ord != 0) {
		if(find(v[at-1].a) != find(v[at-1].b)) {
			qtd--;
			join(v[at-1].a, v[at-1].b);
		}
		ans.push(qtd);

		at++;
	}

	while(!ans.empty()) {
		cout <<ans.top();
		if(ans.size() != 1) cout <<' ';
		ans.pop();
	}

	cout <<endl;

    return 0;
}

