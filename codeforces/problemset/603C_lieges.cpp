#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int sg[7] = {0, 1, 0, 1, 2, 0, 2};
int sgi(int n) {
	if(n < 7) return sg[n];;
	if(n&1) return 0;
	return (sgi(n>>1) == 1? 2:1);
}

int sgp(int n) {
	if(n <= 2) return n;
	return 1 - n&1;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, k;
	cin >>n >>k;
	
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int at; cin >>at;
		if(k&1) ans ^= sgi(at);
		else ans ^= sgp(at);
	}
    
	cout <<(ans?"Kevin":"Nicky") <<endl;
    return 0;
}

