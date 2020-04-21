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

const int N = 1024000 + 10;
int seg[4*N+1];
int lazy[4*N+1];

/*
 * 0- nada
 * 1- seta 0
 * 2- seta 1
 * 3- inverte
 */

void prop(int node, int i, int j) {
	if(lazy[node] == 1) {
		seg[node] = 0;
		lazy[2*node] = lazy[2*node+1] = 1;
	}
	if(lazy[node] == 2) {
		seg[node] = (j-i)+1;
		lazy[2*node] = lazy[2*node+1] = 2;
	}
	if(lazy[node] == 3) {
		seg[node] = (j-i)+1 - seg[node];
		lazy[2*node] = 3 - lazy[2*node];
		lazy[2*node+1] = 3 - lazy[2*node+1];
	}
	
	lazy[node] = 0;
}

void build(int node, int a, int b, int i, int j, string &s) {
	lazy[node] = 0;
	if(j < a or i > b) return;
	if(i == j){
		seg[node] = s[i] - '0';
		return;
	}
	
	int mid = (i+j)/2;
	build(node*2, a, b, i, mid, s);
	build(node*2+1, a, b, mid+1, j, s);
	seg[node] = seg[node*2]+seg[node*2+1];
	return;
}

void update(int node, int a, int b, int i, int j, int val) {
	prop(node, i, j);
	if(j < a or i > b) return;
	if(i >= a and j <= b) {
		lazy[node] = val;
		prop(node, i, j);
		return;
	}

	int mid = (i+j)/2;
	update(2*node, a, b, i, mid, val);
	update(2*node+1, a, b, mid+1, j, val);
	seg[node] = seg[2*node] + seg[2*node+1];
	return;
}

int query(int node, int a, int b, int i, int j) {
	prop(node, i, j);
	if(j < a or i > b) return 0;
	if(i >= a and j <= b) {
		prop(node, i, j);
		return seg[node];
	}
	int mid = (i+j)/2;
	return query(2*node, a, b, i, mid) + query(2*node+1, a, b, mid+1, j);
}

int main() {
	
    int tc; 
	scanf(" %d", &tc);
	for(int i = 1; i <= tc; i++) {
		printf("Case %d:\n", i);
		int m; 
		scanf(" %d", &m);
		int tam = 0;
		string pirates = "";
		while(m--) {
			int qtd; 
			char s[55]; 
			scanf(" %d %s", &qtd, s);
			tam += (qtd*strlen(s));
			while(qtd--) pirates += s;
		}
		build(1, 0, tam-1, 0, tam-1, pirates);
		int q; 
		scanf(" %d", &q);
		int cont = 1;
		for(int j = 1; j <= q; j++) {
			char op; int a, b;
			scanf(" %c %d %d", &op, &a, &b);
			if(op == 'E') update(1, a, b, 0, tam-1, 1);
			if(op == 'F') update(1, a, b, 0, tam-1, 2);
			if(op == 'I') update(1, a, b, 0, tam-1, 3);
			if(op == 'S') printf("Q%d: %d\n", cont++, query(1, a, b, 0, tam-1));
			
		}
	}

    return 0;
}

