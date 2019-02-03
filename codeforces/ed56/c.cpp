#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;
	vector<ll> v;
	for(int i = 0; i < n/2; i++) {
		ll a; cin >>a;
		v.pb(a);
	}
    
	vector<ll> u;
	u.pb(0);
	for(int i = 1; i < v.size(); i++) {
		if((v[i]-u[i-1]) <= v[i-1]) {
			u.pb(u[i-1]);
		} else {
			u.pb(max(u[i-1], v[i] - (v[i-1])));
		}
		v[i] = v[i] - u[i];
	}
	for(int i = 0; i < u.size(); i++) {
		cout <<u[i] <<' ';
	}
	for(int i = v.size()-1; i >= 0; i--) {
		cout <<v[i] <<' ';
	}
	cout <<endl;

    return 0;
}

