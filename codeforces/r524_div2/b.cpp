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

    int q;
	cin >>q;

	while(q--) {
		int a, b;
		cin >>a >>b;
		if(a == b) {
			cout <<a*(a%2==0?1:-1) <<endl;
		}
		else {
			if(a%2 == 0 and b%2 == 0) {
				cout <<((b-a)/2)+1+(a-1) <<endl;;
			}
			if(a%2 == 0 and b%2 == 1) {
				cout <<(-1)*(b-a+1)/2 <<endl;
			}
			if(a%2 == 1 and b%2 == 0) {
				cout <<(b-a+1)/2 <<endl;
			}
			if(a%2 == 1 and b%2 == 1) {
				cout <<(-1)*((b-a)/2)+1+(-a-1) <<endl;;
			}
		}
	}
    
    return 0;
}

