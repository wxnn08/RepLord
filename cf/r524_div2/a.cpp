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
 
int main() {
    ios_base::sync_with_stdio(false);

    ll n, k;
	cin >>n >>k;

	ll ans = 0;

	ans += ((2*n)/k) + ((2*n)%k != 0?1:0);
	ans += ((5*n)/k) + ((5*n)%k != 0?1:0);
	ans += ((8*n)/k) + ((8*n)%k != 0?1:0);
	
	cout <<ans <<endl;

    return 0;
}

