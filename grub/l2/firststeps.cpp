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
	
	const int N = 1e5 + 5;
    int n;
	scanf(" %d", &n);
	
	int v[N];
	for(int i = 0; i < n; i++) {
		scanf(" %d", &v[i]);
	}
	
	int cont = 1, ans = 1;
	for(int i = 1; i < n; i++) {
		if(v[i] >= v[i-1]) cont++;
		if(v[i] < v[i-1] or i == n-1) {
			ans = max(ans, cont);
			cont = 1;
		}
	}
    
	printf("%d\n", ans);

    return 0;
}

