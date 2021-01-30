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

	int n, k;
	cin >>n >>k;
	string s; cin >>s;
	if(k == 0) {
		cout <<s <<endl;
		return 0;
	}

	if(n == 1) {
		cout <<'0' <<endl;
		return 0;
	}

	for(int i = 0; i < (int) s.size(); i++) {
		if(k > 0) {
			if(i == 0) {
				if(s[i] == '1') continue;
				s[i] = '1';
				k--;
			} else {
				if(s[i] == '0') continue;
				s[i] = '0';
				k--;
			}
		}
	}

	cout <<s <<endl;
	
	return 0;
}

