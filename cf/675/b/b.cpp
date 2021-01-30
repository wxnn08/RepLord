#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
	ios_base::sync_with_stdio(false);

	ll n, a, b, c, d;
	cin >>n >>a >>b >>c >>d;
	ll maior = max({a+b, a+c, c+d, b+d});
	ll menor = min({a+b, a+c, c+d, b+d});
	cout <<max(0LL, n*(n-(maior-menor))) <<endl;
	
	return 0;
}

