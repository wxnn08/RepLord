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
 
int nextYear(int n) {
	int mult = 1;
	int last = -1;
	if(n/10 == 0) return n+1;
	while(n > 0) {
		if(last != -1) mult *= 10;
		last = n%10;
		n /= 10;
	}

	return (last+1)*mult;
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >>n;

	int nxt = nextYear(n);
	cout <<nxt-n <<endl;
	return 0;
}

