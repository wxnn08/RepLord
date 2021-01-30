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

	ll n;
	cin >>n;
	
	ll v[3] = {1234567, 123456, 1234};
	
	ll k = n;
	for(ll i = 0; n >= i*v[0]; i++) {

		k = n - (i*v[0]);

		for(ll j = 0; k >= j*v[1]; j++) {
			ll t = k - (j*v[1]);

			if(t%v[2] == 0) {
				cout <<"YES" <<endl;
				return 0;
			}
		}
	}

	cout <<"NO" <<endl;
    return 0;
}

