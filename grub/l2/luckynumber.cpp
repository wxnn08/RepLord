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

    ll a;
	scanf(" %lld", &a);
	
	int qtd = 0;
	while(a != 0) {
		if(a%10 == 7 or a%10 == 4) qtd++;
		a /= 10;
	}
	if(qtd == 4 or qtd == 7) printf("YES\n");
	else printf("NO\n");
    return 0;
}

