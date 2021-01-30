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
	
	int tc;
	cin >>tc;

	while(tc--) {
		string s;
		cin >>s;
		
		set<char> st;
		for(char at:s) 
			st.insert(at);

		if(st.size() == 1) {
			cout <<s <<endl;
			continue;
		}
		
		char a = '-', b = '-';
		int cont = 0;
		map<char, char> m;
		for(auto at:st) {
			if(s[cont] != at) {
				m[s[cont]] = at;
				m[at] = s[cont];
				break;
			} else {
				while(cont < s.size() and s[cont] <= at) cont++;
			}
		}
		
		for(char at:s) {
			if(m[at] > 0) cout <<m[at];
			else cout <<at;
		}
		cout <<endl;
	}

	return 0;
}

