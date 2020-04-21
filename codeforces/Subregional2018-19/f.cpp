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

struct show {
	int ini, fim, msc, palc;
	show(){}
	show(int ini, int fim, int msc, int palc) {
		this->ini = ini;
		this->fim = fim;
		this->msc = msc;
		this->palc = palc;
	}

	bool operator <(const show &o) const {
		if(ini < o.ini) return true;
		if(fim < o.fim) return true;
		return false;
	}
};

int dp[1010][1050];
int n, tam;
vector<show> v;

int solve(int at, int vis) {
	if(at == v.size()) {
		if(vis == tam) return 0;
		return -INF;
	}
	
	int &r = dp[at][vis];
	if(r != -1) return r;
	
	int R = solve(at+1, vis);
	int L = v[at].msc + solve(at+1, vis|(1<<v[at].palc));

	return r = max(L,R);
}

int main(){
    //ios_base::sync_with_stdio(false);

	cin >>n;
	
	for(int i=0; i<n; i++){
		int qtd;
		cin >>qtd;
		for(int j=0; j<qtd; j++) {
			int a, b, c;
			cin >>a >>b >>c;
			v.pb(show(a,b,c,i));
		}
	}
	
	tam = pow(2,n);
    sort(v.begin(), v.end());
	
	for(int i=0; i<v.size(); i++) {
		printf
	}

	memset(dp, -1, sizeof dp);
	cout <<solve(0,0) <<endl;


    return 0;
}

