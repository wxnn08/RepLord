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

    int n;
	cin >>n;
	
	int maior = -1, cont = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		int v; cin >>v;
		if(v > maior) {
			maior = v;
			ans = 0;
			cont = 0;
		}
		if(v == maior) cont++;
		else cont = 0;
		ans = max(cont, ans);
	}
    
	cout <<ans <<endl;
    return 0;
}

