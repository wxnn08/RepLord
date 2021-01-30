#include <bits/stdc++.h>
using namespace std;

#define pb		push_back
#define eb		emplace_back
#define mk		make_pair
#define fi		first
#define se		second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl	'\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int countLucky(const string &s) {
	int ans = 0;
	for(int i = 0; i < s.size(); i++) 
		ans += (s[i] == '7' or s[i] == '4');
	return ans;
}

bool isLucky(int n) {
	if(n == 0) return false;
	while(n > 0) {
		int curr = n%10;
		if(curr != 4 and curr != 7) return false;
		n /= 10;
	}
	return true;
}
 
int main() {
    ios_base::sync_with_stdio(false);

	string s; cin >>s;
	int cont = countLucky(s);
	cout <<(isLucky(cont)? "YES" : "NO") <<endl;

    return 0;
}

