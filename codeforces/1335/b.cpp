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

	int tc; cin >>tc;
	while(tc--) {
		int n, a, b; cin >>n >>a >>b;
		string base = "";

		for(int i = b; i < a; i++) base += 'a';
		for(int i = 0; i < b; i++) base += (char)('a'+i);

		for(int i = 0; i < (n/a); i++) 
			cout <<base;
		for(int i = 0; i < (n%a); i++)
			cout <<base[i];
		cout <<endl;
	}

    return 0;
}

