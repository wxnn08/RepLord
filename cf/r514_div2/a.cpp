#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

    int n, l, a;
    cin >>n >>l >>a;
	
	int last = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		int u, v;
		cin >>u >>v;
		ans += ((u-last)/a);
		last = u+v;
	}

	ans += ((l-last)/a);

	cout <<ans <<endl;
    return 0;
}

