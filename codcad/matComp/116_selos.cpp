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
	
	ll n; cin >>n;
	bool ans = false;
    for(ll i = 2; i <= sqrt(n); i++) {
		if(n%i == 0 and n/i != i and n/i > 1) ans = true;
	}
    
	cout <<(ans?'S':'N') <<endl;
    return 0;
}

