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

    int a, b, c;
	scanf(" %d %d %d", &a, &b, &c);
	
	if(a < b and b < c) {
		printf("1\n2\n3\n");
	}
	if(a < c and c < b) {
		printf("1\n3\n2\n");
	}
	if(b < a and a < c) {
		printf("2\n1\n3\n");
	}
	if(b < c and c < a) {
		printf("2\n3\n1\n");
	}
	if(c < a and a < b) {
		printf("3\n1\n2\n");
	}
	if(c < b and b < a) {
		printf("3\n2\n1\n");
	}
    
    return 0;
}

