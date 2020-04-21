#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define eb emplace_back
#define endl '\n'
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);

	string s[2];
	cin >>s[0] >>s[1];
	int a, b, c, d;
	a = b = c = d = 0;
	for(int i = 0; i < s[0].size(); i++) {
		if(s[0][i]== '#' and s[1][i]== '.') a++;
		if(s[0][i]== '#' and s[1][i]== '#') b++;
		if(s[0][i]== '.' and s[1][i]== '#') c++;
		if(s[0][i]== '.' and s[1][i]== '.') d++;
	}

	if(a > 0 and c > 0 and b == 0) {
		cout <<"NO" <<endl;
		return 0;
	}

	cout <<"YES" <<endl;
	string ans[2];
	ans[0] = ans[1] = "";
	while(a--) { ans[0] += '#'; ans[1] += '.'; }
	while(b--) { ans[0] += '#'; ans[1] += '#'; }
	while(c--) { ans[0] += '.'; ans[1] += '#'; }
	while(d--) { ans[0] += '.'; ans[1] += '.'; }

	cout <<ans[0] <<endl <<ans[1] <<endl;
		
	return 0;
}

