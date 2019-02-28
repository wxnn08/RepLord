#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    ios_base::sync_with_stdio(false);

    int ini, exp;
	cin >>ini >>exp;
	
	int ans = 0;
	for(int i = 0; i <= ini; i++) {
		int at = 0;
		if(i*2 > exp) break;
		int qtd = i + min((ini-i)/2, exp-i*2);
		ans = max(ans, qtd);
	}

	cout <<ans <<endl;
    
    return 0;
}

