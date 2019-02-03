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

    string s, t;
	cin >>s >>t;
	if(s.size() != t.size()) {
		cout <<"No" <<endl;
		return 0;
	}
	vector<int> v, u;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u')
			v.pb(1);
		else
			v.pb(0);
	}

	for(int i = 0; i < t.size(); i++) {
		if(t[i] == 'a' or t[i] == 'e' or t[i] == 'i' or t[i] == 'o' or t[i] == 'u')
			u.pb(1);
		else
			u.pb(0);
	}

	for(int i = 0; i < v.size(); i++) {
		if(v[i] != u[i]) {
			cout <<"No" <<endl;
			return 0;
		}
	}

	cout <<"Yes" <<endl;

    
    return 0;
}

