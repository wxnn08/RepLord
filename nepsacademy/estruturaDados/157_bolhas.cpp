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

const int N = 1e5 + 5;
int t[N];

int query(int x) {
	int s = 0;
	while(x > 0) {
		s += t[x];
		x -= (x & -x);
	}
	return s;
}

void update(int x, int v) {
	while(x < N) {
		t[x] += v;
		x += (x & -x);
	}
}

int main(){
    ios_base::sync_with_stdio(false);

    while(true) {
		int qtd; cin >>qtd;
		if(qtd == 0) return 0;

		memset(t, 0, sizeof t);
		int ans = 0;

		for(int i = 0; i < qtd; i++) {
			int x; cin >>x;
			ans += (query(1e5) - query(x));
			update(x, 1);
		}
		
		cout <<(ans%2?"Marcelo":"Carlos") <<endl;
	}
    
    return 0;
}

