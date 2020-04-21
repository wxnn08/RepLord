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

ll pot(int n, int m) {
	//n ^ m
	ll ans = 1;
	for(int i=0; i<m; i++) ans *= n;
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, bx, m, by;
	cin >>n >>bx;
	
	ll x = 0, y = 0;
	for(int i = 0; i < n; i++) {
		ll v;
		cin >>v;
		x += v * pot(bx, n-1-i);
	}

	cin >>m >>by;
	for(int i = 0; i < m; i++) {
		ll v;
		cin >>v;
		y += v * pot(by, m-1-i);
	}
	
	if(x == y) cout <<'=' <<endl;
	else if(x < y) cout <<'<' <<endl;
	else cout <<'>' <<endl;
	return 0;
}

