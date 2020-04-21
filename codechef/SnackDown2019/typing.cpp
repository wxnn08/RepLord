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

    int tc;
	cin >>tc;
	map<char, int> m;
	m['d'] = 1;
	m['f'] = 1;
	m['j'] = 2;
	m['k'] = 2;

	while(tc--) {
		int nWords; cin >>nWords;
		int ans = 0, time;
		map<string, int> dic;
		while(nWords--) {
			time = 0;
			string s; cin >>s;
			if(dic[s]) {
				ans += (dic[s]/2);
				continue;
			}
			for(int i = 0; i < s.size(); i++) {
				if(i == 0 or m[s[i]] != m[s[i-1]]) time += 2;
				else time += 4;
			}
			dic[s] = time;
			ans += time;
		}
		cout <<ans <<endl;
	}
    
    return 0;
}

