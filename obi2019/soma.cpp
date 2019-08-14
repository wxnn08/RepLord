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

const int N = 5e5 + 5; 

int main() {
	ios_base::sync_with_stdio(false);

	int n, k;
	int v[N];
	cin >>n >>k;
	for(int i = 0; i < n; i++) 
		cin >>v[i];

	int l = -1, r = 0;
	int ans = 0;
	int sum = v[r];
	while(l < n) {
		cc(sum);
		if(sum == k and r != l) ans++;
		if((sum <= k or l == r) and r < n) {
			sum += v[++r];
		} else {
			sum -= v[++l];
		}
		cc(r);
		cc(l);
	}

	cout <<ans <<endl;
	return 0;
}

