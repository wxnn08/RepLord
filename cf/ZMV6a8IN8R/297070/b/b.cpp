/* Feito por wxn_ em 02/10/2020*/
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
 
int main() {
    ios_base::sync_with_stdio(false);

	string s;
	cin >>s;
	int ans = 0;
	int n = s.size();
	for(int i = 0; i < n/2; i++) {
		ans += (int)(s[i] != s[n-1-i]);
	}
	cout <<ans <<endl;

    return 0;
}
