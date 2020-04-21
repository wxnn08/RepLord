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

const int N = 3e4+5;
int seg[4*N+1];

int query(int r, int i, int j, int a, int b){
	if(i>b or j<a) return 0;
	if(i>=a and j<=b) return seg[r];
	int mid = (i+j)>>1;
	return max(query(2*r, i, mid, a, b), query(2*r+1, mid+1, j, a, b));
}

void update(int r, int i, int j, int p, int val){
	if(i>p or j<p) return;
	if(i>=p and j<=p){
		seg[r] = val;
		return;
	}
	int mid = (i+j)>>1;
	update(2*r, i, mid, p, val);
	update(2*r+1, mid+1, j, p, val);
	seg[r] = max(seg[2*r], seg[2*r+1]);
	return;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;
	
	ll v[N];
	vector<ll> ve;
	fori(i,0,n){
		cin >>v[i];
		ve.pb(v[i]);
	}
	
	sort(ve.begin(), ve.end());
	ve.resize(unique(ve.begin(), ve.end())-ve.begin());
	
	map<ll,int> m;
	int cont = 1;
	fori(i,0,ve.size()){
		if(m[ve[i]]==0) m[ve[i]] = cont++;
	}
	fori(i,0,n){
		v[i] = m[v[i]];
	}
	fori(i,0,n){
		int q = query(1,0,N,0, v[i]-1);
		update(1,0,N,v[i], q+1);
	}
	cout <<seg[1] <<endl;
    return 0;
}

