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
	scanf(" %d", &n);

	if(n%2 or n <= 2) printf("NO\n");
	else printf("YES\n");
    
    return 0;
}

