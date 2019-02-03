#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 1e3 + 5;
int n, m;
int a[N], b[N];

bool can(double qtd) {
	double w = (double) m;
	for(int i = 0; i < n; i++) {
		qtd -= ((double)(w+qtd)/a[i]);
		if(qtd < 0) break;
		qtd -= ((double)(w+qtd)/b[(i+1)%n]);
		if(qtd < 0) break;
	}
	if(qtd >= 0) return true;
	return false;
}

double solve() {
	double ini = 0, fim = 2e9, mid;
	bool t = false;
	while(abs(fim - ini) > 1e-6) {
		mid = (fim+ini)/2;
		if(can(mid)) {
			fim = mid;
		}
		else
			ini = mid;
	}
	if(mid > 1e9+1) return -1;
	return mid;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	cin >>n >>m;
	for(int i = 0; i < n; i++) {
		cin >>a[i];
	}
    
	for(int i = 0; i < n; i++) {
		cin >>b[i];
	}
	
	double ans = solve();
	if(ans < 0) cout <<-1 <<endl;
	else cout <<fixed <<setprecision(7) <<ans <<endl;

    return 0;
}

