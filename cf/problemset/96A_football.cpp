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

	char c;
	char last = '-';
	int cont = 0;
	bool danger = false;
	while(cin >>c) {
		if(last != c) cont = 1;
		else cont++;
		if(cont >= 7) danger = true;
		last = c;
	}

	cout <<(danger? "YES" : "NO") <<endl;

    return 0;
}

