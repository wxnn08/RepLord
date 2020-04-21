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
 
int main() {
    ios_base::sync_with_stdio(false);

    int n;
	cin >>n;
	
	vector<int> v;
	map<int, int> m;
	bool isValid = false;
	for(int i = 0; i < n; i++) {
		int a; cin >>a;
		v.pb(a);
		m[a]++;
		if(m[a] > 1) isValid = true;
	}

	vector<ii> ans;
	if(!isValid) {
		cout <<-1 <<endl;
	} else {
		map<int, int> aux;
		int ini = 1;
		for(int i = 0; i < n;) {
			m[v[i]]--;
			aux[v[i]]++;
			if(aux[v[i]] == 2) {
				i++;
				while(i < n and m[v[i]] == 1) i++;
				ans.eb(ini, i);
				ini = i+1;
				aux.clear();
			} else {
				i++;
			}
		}
		
		cout <<ans.size() <<endl;
		for(auto at:ans) {
			cout <<at.fi <<' ' <<at.se <<endl;
		}
	}
	
    
    return 0;
}

