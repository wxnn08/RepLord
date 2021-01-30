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

void yes() {
	cout <<"YES" <<endl;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	cin >>n;
	
	ll sum1 = 0, sum2 = 0;
	map<ll, int> m1, m2;

	vector<ll> v;
	for(int i = 0; i < n; i++) {
		 ll at;
		 cin >>at;
		 v.pb(at);
		 sum2 += at;
		 m2[at]++;
	}
	
	for(auto at:v) {
		sum1 += at;
		sum2 -= at;
		m2[at]--;
		m1[at]++;

		if(sum2 == sum1) yes();

		if(sum2 > sum1) {
			if((sum2-sum1)%2 == 0) {
				ll num = (sum2-sum1)>>1;
				if(m2[num] > 0) yes();
			}
		} else {
			if((sum1-sum2)%2 == 0) {
				ll num = (sum1-sum2)>>1;
				if(m1[num] > 0) yes();
			}
		}
	}
	
	cout <<"NO" <<endl;

	return 0;
}

