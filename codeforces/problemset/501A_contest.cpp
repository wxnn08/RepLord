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

	int a, b, c, d;
	cin >>a >>b >>c >>d;
	int pm = max(3*a/10, a - a*c/250);
	int pv = max(3*b/10, b - b*d/250);

	if(pm == pv) cout <<"Tie" <<endl;
	else cout <<(pm > pv? "Misha" : "Vasya") <<endl;

    return 0;
}

