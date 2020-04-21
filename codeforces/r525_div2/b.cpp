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

    int n, k;
	cin >>n >>k;
	vector<ll> v;
	for(int i = 0; i < n; i++) {
		int a; cin >>a;
		v.pb(a);
	}

	sort(v.begin(), v.end());

	ll sum = 0;
	for(int i = 0; i < k; i++) {
		if(i >= v.size()) {
			cout <<0 <<endl;
		} else {
			if(v[i] - sum <= 0) {
				k++;
				continue;
			}
			cout <<v[i] - sum <<endl;
			sum += (v[i] - sum);
		}
	}
    
    return 0;
}

