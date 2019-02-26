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
	
	const int N = 1e3 + 5;
    int n;
	scanf(" %d", &n);
	
	int v[N];
	for(int i = 0; i < n; i++) 
		scanf(" %d", &v[i]);
	
	int ans = 0;
	for(int i = 1; i < n; i++) {
		ans += min(10, v[i]-v[i-1]);
	}
    
	printf("%d\n", ans+10);
    return 0;
}

