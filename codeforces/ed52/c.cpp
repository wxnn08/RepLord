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

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 2e5 + 5;
ll seg[4*N+1];
ll lazy[4*N+1];

void prop(int r, int i, int j) {
	seg[r] += lazy[r]*(j-i+1);
	if(i != j) {
		lazy[2*r] += lazy[r];
		lazy[2*r+1] += lazy[r];
	}
	lazy[r] = 0;
}

ll query(int r, int i, int j, int a, int b) {
	prop(r,i,j);
	if(i > b or j < a) return 0;
	if(i >= a and j <= b) return seg[r];

	int mid = (i+j)>>1;
	return query(2*r, i, mid, a, b) + query(2*r+1, mid+1, j, a, b);
}

void update(int r, int i, int j, int a, int b, int v) {
	prop(r,i,j);
	if(i > b or j < a) return;
	if(i >= a and j <= b) {
		lazy[r] += (ll)v;
		prop(r,i,j);
		return;
	}

	int mid = (i+j) >> 1;
	update(2*r, i, mid, a, b, v);
	update(2*r+1, mid+1, j, a, b, v);
	seg[r] = seg[2*r] + seg[2*r+1];
	return;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, k, menor = INF, maior = 0;
	cin >>n >>k;
	for(int i = 0; i < n; i++) {
		int val; cin >>val;

		update(1, 0, N, 1, val, 1);

		menor = min(menor, val);
		maior = max(maior, val);
	}

/*
	int verifica;
	cin >>verifica;
	while(verifica--) {
		int ini, fim; cin >>ini >>fim;
		cout <<query(1, 0, N, ini+1, fim) <<endl;
	}
*/
	int cortes = 0;
	for(int i = maior-1; i >= menor; i--) {
		if(query(1, 0, N, i, maior) > k) {
			cortes++;
			maior = i;
		} else if(i == menor) {
			cortes++;
		}
	}

	cout <<cortes <<endl;
    return 0;
}
