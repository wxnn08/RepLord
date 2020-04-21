#include <bits/stdc++.h>
using namespace std;
 
#define pb      push_back
#define eb      emplace_back
#define mk      make_pair
#define fi      first
#define se      second
#define cc(x)   cout << #x << " = " << x << endl
#define ok      cout << "ok" << endl
#define endl    '\n'
 
typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int CONT = 0;
int LAST_ROOT = 0;
const int N = 1e3 + 5;
 
int root[N];
int seg[4*N];
ii children[4*N];
 
int build(int i, int j) {
    int idNode = ++CONT;
    if(i == j) {
        seg[idNode] = 0;
        return idNode;
    }
   
    int mid = (i+j)>>1;
    int idL = build(i, mid);
    int idR = build(mid+1, j);
    seg[idNode] = seg[idL] + seg[idR];
    children[idNode] = ii(idL, idR);
 
    return idNode;
}
 
int query(int node, int i, int j, int a, int b) {
    if(j < a or i > b) return 0;
    if(i >= a and j <= b) return seg[node];
    int mid = (i+j)>>1;
    return query(children[node].fi, i, mid, a, b) + query(children[node].se, mid+1, j, a, b);
}
 
int add(int node, int i, int j, int pos, int val) {
    if(i > pos or j < pos) return node;
 
    int idNode = ++CONT;
    if(pos == i and pos == j) {
        seg[idNode] = seg[node]+val;
        return idNode;
    }
 
    int mid = (i+j)>>1;
    int idL = add(children[node].fi, i, mid, pos, val);
    int idR = add(children[node].se, mid+1, j, pos, val);
 
    seg[idNode] = seg[idL] + seg[idR];
    children[idNode] = ii(idL, idR);
 
    return idNode;
}
 
void add_version(int i, int j, int pos, int val) {
    root[++LAST_ROOT] = add(root[LAST_ROOT], i, j, pos, val);
}
 
int solve(int a, int b, int k, int n) {
	int l = 0;
	int r = n-1;

	int ans = 0;
	while(l <= r) {
		int mid = (l+r)>>1;
		int qtdA = query(root[a-1], 0, n-1, 0, mid-1);
		int qtdB = query(root[b], 0, n-1, 0, mid-1);

	}
}

int main() {
    ios_base::sync_with_stdio(false);
 
    int n, m;
    cin >>n >>m;
 
    root[0] = build(0, n-1);
 
    for(int i = 1; i <= n; i++) {
        int val; cin >>val;
        add_version(0, n-1, val, 1);
 
        print(root[i], 0, n-1);
        cout <<endl;
    }
 
	while(m--) {
		int a, b, k;
		cin >>a >>b >>k;
		cout <<solve(a-1, b-1, k) <<endl;
	}

 
    return 0;
}
