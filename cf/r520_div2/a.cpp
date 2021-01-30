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
 
int main(){
    ios_base::sync_with_stdio(false);
    const int N = 1e3 + 5;
    int n; cin >>n;
    int v[N], v2[N];
    for(int i = 0; i < n; i++) cin >>v[i];
	for(int i = 1; i < n; i++) v2[i] = v[i] - v[i-1];

	int cont = 0, idI = 0, ans = 0;
	bool f = 0;
	v2[0] = v[0];

	for(int i = 0; i < n; i++) {
		if(v2[i] == 1) {
			if(!f) idI = i;
			f = 1;
			cont++;
		}
		if(f and (v2[i] != 1 or i == n-1)) {
			f = false;
			if(idI == 0 and i != n-1) {
				ans += cont-1;
			} 
			if(idI != 0 and i == n-1) {
				if(v2[i] == 1 and v[i] == 1000) {
					ans += cont;
				} else {
					ans += cont-1;
				}
			}
			if(idI != 0 and i != n-1) {
				ans += cont-1;
			}
			if(idI == 0 and i == n-1) {
				ans += cont-1;
			}
			cont = 0;
		}
	}
	
	cout <<ans <<endl;

    return 0;
}

