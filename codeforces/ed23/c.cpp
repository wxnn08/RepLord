#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

bool check(ll n) {
	ll v1 = n%10;
	n /= 10;
	ll v2 = n%10;

	return v2 == v1+1;
}

int main() {
	ios_base::sync_with_stdio(false);

	ll n, s;
	cin >>n >>s;

	ll qtd = s/9LL;
	if(qtd*9LL < s) qtd++;
	if(check(qtd)) qtd++;
	
	cout <<max(0LL, n-(qtd*10LL)+1LL) <<endl;
	return 0;
}

