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

typedef struct trio {
	ll a, b, c;
} trio;

ll search(ll ini, ll v) {
	if(v-ini >= ini) return v-ini;
	ll i = ini, j = ini;
	while(true) {
		if((i != 0 and i <= 1e6 and v%i == ini) or (j > 0 and v%j == ini))
			break;
		i++;
		j--;
	}
	return (v%i == ini? i : j);
}

int main(){
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;
	vector<ll> v;
	vector<trio> ans;
	for(ll i = 1; i <= n; i++) {
		ll a;
		cin >>a;
		v.pb(a);
	}
	ll sum = 4200;
	if(sum != 0) {
		trio s;
		s.a = 1;
		s.b = n;
		s.c = sum;
		ans.pb(s);
	}
	for(ll i = 0; i < n; i++) {
		v[i] += sum;
	}

	for(ll i = 0; i < n; i++) {
		trio s;
		s.a = 2;
		s.b = i+1;
		s.c = search(i, v[i]);
		ans.pb(s);
	}
    
	cout <<ans.size() <<endl;
	for(int i = 0; i < ans.size(); i++) {
		cout <<ans[i].a <<' ' <<ans[i].b <<' ' <<ans[i].c <<endl;
	}
    return 0;
}
