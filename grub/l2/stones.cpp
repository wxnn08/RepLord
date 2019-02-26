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

// Solução 1:
	const int N = 50 + 5; //n pode ir ate 50, mais 5 do cagaço
	char c[N];
    int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf(" %c", &c[i]);
	}
    
	int ans = 0;
	for(int i = 1; i < n; i++) {
		if(c[i] == c[i-1]) ans++;
	}

	printf("%d\n", ans);

    return 0;
}

