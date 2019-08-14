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

    int p1, p2, p3;
	int g, p, b;

	cin >>p1 >>p2 >>p3;
	cin >>g >>p >>b;
	
	bool ans = true;
	
	if(p1 > g) ans = false;
	int gp = (g-p1)+p;

	if(p2 > gp) ans = false;
	int gpb = (gp-p2)+b;

	if(p3 > gpb) ans = false;

	cout <<(ans?"YES":"NO") <<endl;

    return 0;
}

