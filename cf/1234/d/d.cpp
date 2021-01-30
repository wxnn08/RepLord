/* Aí, você já parou pra pensar, por que que você vive?
 * O que é que te move?
 * Aquele momento que decodifica o segredo da sua alma
 * E de repente tudo começa a fazer sentido.
 * É um chamado legítimo que vem lá do íntimo 
 * É quando a poesia entra em sincronia com o ritmo 
 * E te faz pensar 
 * Se não fosse isso eu podia até respirar, mas vivo eu também não ia tá!
 */
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

const int N = 1e5 + 100;
int seg[4*N];
string s;

void build(int r, int i, int j) {
	if(i == j) {
		seg[r] = 1<<(s[i]-'a');
		return;
	}
	int mid = (i+j)>>1;
	build(2*r, i, mid);
	build(2*r+1, mid+1, j);
	seg[r] = seg[2*r]|seg[2*r+1];
	return;
}

void update(int r, int i, int j, int pos, int v) {
	if(i >= pos and j <= pos) {
		seg[r] = v;
		return;
	}
	if(i > pos or j < pos) return;
	int mid = (i+j)>>1;
	update(2*r, i, mid, pos, v);
	update(2*r+1, mid+1, j, pos, v);
	seg[r] = seg[2*r]|seg[2*r+1];
	return;
}

int query(int r, int i, int j, int a, int b) {
	if(i >= a and j <= b) return seg[r];
	if(i > b or j < a) return 0;
	int mid = (i+j)>>1;
	return query(2*r, i, mid, a, b) | query(2*r+1, mid+1, j, a, b);
}
 
int main() {
	ios_base::sync_with_stdio(false);

	cin >>s;
	int q, tam = s.size();
	build(1, 0, tam-1);
	cin >>q;
	while(q--) {
		int op;
		cin >>op;
		if(op == 1) {
			int pos; char c;
			cin >>pos >>c;
			update(1, 0, tam-1, pos-1, 1<<(c-'a'));
		} else {
			int a, b;
			cin >>a >>b;
			cout << __builtin_popcount(query(1, 0, tam-1, a-1, b-1)) <<endl;
		}
	}
	
	return 0;
}

