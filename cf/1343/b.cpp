#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    ios_base::sync_with_stdio(false);

	// O(tc*n)
	int tc; cin >>tc;
	while(tc--) {
		int n; cin >>n;
		if((n/2)%2 == 1) {
			cout <<"NO" <<endl;
			continue;
		}

		vector<int> v;
		cout <<"YES" <<endl;
		int cont = 0;
		for(int i = 0; i < n/2; i+=2) {
			int t = 2;
			cont += 2;
			while(t--) {
				cout <<cont <<' ';
				v.pb(cont);
				cont += 2;
			}
		}
		for(int i = 0; i < v.size(); i += 2) 
			cout <<v[i]-1 <<' ' <<v[i+1]+1 <<' ';
		cout <<endl;
	}

    return 0;
}

