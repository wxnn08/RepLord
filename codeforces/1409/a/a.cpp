/* Feito por wxn_ em 06/09/2020*/
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
		int a, b; 
		cin >>a >>b;
		int sub = abs(b-a);
		cout <<(sub/10)+(sub%10 != 0) <<endl;
	}

    return 0;
}
