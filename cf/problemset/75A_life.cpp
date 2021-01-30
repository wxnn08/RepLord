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

int transform(int n) {
	int ans = 0;
	int p = 1;
	while(n > 0) {
		int v = n%10;
		if(v != 0) {
			ans += (p*v);
			p *= 10;
		}
		n /= 10;
	}
	return ans;
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >>n >>m;

	int res = n + m;
	res = transform(res);

	n = transform(n);
	m = transform(m);

	cout <<(res == n+m?"YES":"NO") <<endl;
    return 0;
}

