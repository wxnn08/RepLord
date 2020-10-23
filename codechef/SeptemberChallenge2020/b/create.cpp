/* Feito por $%U%$ em $%D%$/$%M%$/$%Y%$*/
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

	int n; cin >>n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout <<(i-1)*n+j <<' ';
		}
		cout <<endl;
	}

    return 0;
}

