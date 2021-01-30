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

    ll n, m;
	cin >>n >>m;

	if(n%2 == 0) {
		ll need = (n/2);
		cout <<max(0LL, 2*(need-m)) <<' ';
	} else {
		ll need = (n/2)+1;
		cout <<max(0LL, 2*(need-m)-1) <<' ';
	}
	
	ll v = 0;
	while(true) {
		if(v*(v-1)/2 >= m or v >= n) break;
		v++;
	}
    
	cout <<n-v <<endl;

    return 0;
}

