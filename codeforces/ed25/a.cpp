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
	string s;
	cin >>s;
	
	int cont = 0;
	int at = s.size()-1;
	string ans = "";
	while(at >= 0) {
		cont = 0;
		while(at >= 0 and s[at] == '1') {
			cont++;
			at--;
		}
		char d = '0'+cont;
		ans = d + ans;
		at--;
	}

	cout <<ans <<endl;

    return 0;
}

