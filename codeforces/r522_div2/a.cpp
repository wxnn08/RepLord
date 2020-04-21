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

const int N = 1e2 + 5;
int v[N];

int main(){
    ios_base::sync_with_stdio(false);
	
	int n, k;
	cin >>n >>k;

	int maior = -1;
	fori(i, 0, n) {
		int a; cin >>a;
		v[a]++;
		maior = max(maior, v[a]);
	}
	
	int quant;
	if(maior%k != 0) {
		quant = maior/k;
		quant = (quant+1) * k;
	} else {
		quant = maior;
	}
	
	int ans = 0;
	for(int i = 0; i < N; i++) {
		if(v[i] != 0) ans += (quant - v[i]);
	}
	
	cout <<ans <<endl;
    return 0;
}

