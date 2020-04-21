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
	
	int tc; cin >>tc;
	//              0  1  2  3  4  5  6  7  8  9
	int dig[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	char num[8] = {'-', '-', '1', '7', '4', '5', '9', '8'};
	while(tc--) {
		int n;
		cin >>n;
		string s;
		cin >>s;
		int sum = 0;
		for(int i = 0; i < s.size(); i++) {
			char at = s[i];
			sum += (dig[at-'0']-2);
			s[i] = '1';
		}

		for(int i = 0; i < s.size(); i++) {
			if(sum >= 4) {
				s[i] = '9';
				sum -= 4;
			} else if(sum >= 1) {
				s[i] = '7';
				sum -= 1;
			}
		}
		
		for(int i = s.size()-1; sum > 0; i--) {
			int v = min(7-dig[s[i]-'0'], sum);
			sum -= v;
			s[i] = num[v+dig[s[i]-'0']];
		}
		cout <<s <<endl;
	}

	return 0;
}

