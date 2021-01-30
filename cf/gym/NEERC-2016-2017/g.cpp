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
 
set<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n; cin >> n;

	for(int i = 2; i*i <= n; i++) 
		while(n%i == 0) v.insert(i), n /= i; 

	if(n > 1) v.insert(n);

	cout << (v.size() == 3? "YES" : "NO") << endl;

	return 0;
}

