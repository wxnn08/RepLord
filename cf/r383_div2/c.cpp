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
const int N = 100 + 3;
 
int main(){
    ios_base::sync_with_stdio(false);
	int n; cin >> n;
	int v[N];
	ll ans[N];
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	for(int i = 1; i <= n; i++) {
		int cont = 1;
		int j = v[i];
		while(j != i and cont < 103) {
			cont++;
			j = v[j];
		}
		ans[i] = cont;
		if(ans[i] % 2 == 0) ans[i] /= 2;
	}
	ll mmc = ans[1];
	for(int i = 1; i <= n; i++) {
		if(ans[i] == 103) {
			cout << -1 << endl;
			return 0;
		}
		mmc = (mmc * ans[i])/__gcd(mmc,ans[i]); 
	}
	cout << mmc << endl;
    
    return 0;
}

