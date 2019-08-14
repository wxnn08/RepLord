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

    string s;
	cin >>s;
	
	int sum = 0;
	for(char at:s) sum += at-'0';

	if(sum%3 == 0) {
		cout <<s <<endl;
		return 0;
	}
	
	for(int i = 1; i < s.size(); i++) {
		int at = (s[i]-'0')%3;
		if(at == sum%3) {
			for(int j = 0; j < s.size(); j++) {
				if(j != i) cout <<s[i];
			}
			cout <<endl;
			return 0;
		}
	}
    
    return 0;
}

