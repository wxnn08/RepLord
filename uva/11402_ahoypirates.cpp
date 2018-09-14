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

const int N = 1024000+3;
int seg[4*N+1];
int lazy[4*N+1];

/* lazy = 0 -> nothing
 * lazy = 1 -> set to 0
 * lazy = 2 -> set to 1
 * lazy = 3 -> invert
 */

void reset(int r, int i, int j){
	if(i==j) return;
	int mid = (i+j)>>1;
	reset(2*r, i, mid);
	reset(2*r+1, mid+1, j);
	return;
}

void prop(int r, int i, int j){
	if(i != j) {
		if(lazy[r] == 1 || lazy[r] == 2){
			seg[r] = (j-i+1)*(lazy[r]-1);
			lazy[2*r] = lazy[2*r+1] = lazy[r];

		} else if(lazy[r] == 3){
			seg[r] = (j-i+1) - seg[r];
			lazy[2*r] = 3-lazy[2*r];
			lazy[2*r+1] = 3-lazy[2*r+1];
		}
	} else {
		if(lazy[r] == 1) seg[r] = 0;
		if(lazy[r] == 2) seg[r] = 1;
		if(lazy[r] == 3) seg[r] = 1-seg[r];
	}

	lazy[r] = 0;
}

int query(int r, int i, int j, int a, int b){
	prop(r, i, j);
	if(i >b or j<a) return 0;
	if(i>=a and j<=b) return seg[r];
	int mid = (i+j) >> 1;
	return query(2*r, i, mid, a, b)+query(2*r+1, mid+1, j, a, b);
}

void update(int r, int i, int j, int a, int b, int v){
	prop(r, i, j);
	if(i>b or j<a) return;
	if(i>=a and j<=b) {
		lazy[r] = v;
		prop(r, i, j);
		return;
	}
	int mid = (i+j) >> 1;
	update(2*r, i, mid, a, b, v);
	update(2*r+1, mid+1, j, a, b, v);
	seg[r] = seg[2*r]+seg[2*r+1];
	return;
}

int main(){

    int TC;
	scanf(" %d", &TC);
	
	int test = 1;
	while(test <= TC){
		printf("Case %d:\n" ,test++);

		int m;
		scanf(" %d", &m);
		
		string s = "";
		fori(i,0,m){
			int qtd;
			char tmp[50];
			scanf(" %d %s", &qtd, &tmp[0]);
			fori(i,0,qtd) s += tmp;
		}

		int tam = s.size()-1;
		fori(i,0,s.size()) update(1, 0, tam, i, i, (s[i]-'0')+1);

		int q, a, b;
		char op;
		scanf("%d", &q);

		int god = 1;
		reset(1, 0, tam-1);
		for(int i=0; i<q; i++){
			scanf(" %c%d%d", &op, &a, &b);
			//cin >>op >>a >>b;
			if(op == 'F') update(1, 0, tam-1, a, b, 2);
			if(op == 'E') update(1, 0, tam-1, a, b, 1);
			if(op == 'I') update(1, 0, tam-1, a, b, 3);
			if(op == 'S'){
				int ans = query(1,0,tam-1, a, b);
				printf("Q%d: %d\n", god++, ans);
			}
		}
	}
    return 0;
}

