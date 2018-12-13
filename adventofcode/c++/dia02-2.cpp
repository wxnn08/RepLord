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

    vector<string> v;
	string s;
	while(cin >>s) {
		v.pb(s);
	}

	for(int i = 0; i < v.size(); i++) {
		for(int j = i+1; j < v.size(); j++) {
			if(v[i].size() != v[j].size()) continue;
			int c = 0, id = -1;
			for(int k = 0; k < v[i].size() and c < 2; k++) {
				if(v[i][k] != v[j][k]) {
					c++;
					id = k;
				}
			}
			if(c == 1) {
				for(int k = 0; k < v[i].size(); k++) {
					if(k != id) cout <<v[i][k];
				}
				cout <<endl;
				return 0;
			}
		}
	}
    
    return 0;
}

