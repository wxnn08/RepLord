#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

bool isLucky(int c, int b) {
	int num = 0, p = 1;
	while(c != 0) {
		int t = c%10;
		if(t == 4 or t == 7) {
			num += (t*p);
			p *= 10;
		}
		c /= 10;
	}
	if(num == b) return true;
	return false;
}

int main(){
    ios_base::sync_with_stdio(false);

    int a, b;
	cin >>a >>b;
	
	int i = a+1;
	while(true) {
		if(isLucky(i, b))
			break;
		i++;
	}
    
	cout <<i <<endl;
    return 0;
}

