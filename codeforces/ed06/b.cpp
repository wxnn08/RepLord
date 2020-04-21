#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int v[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int calc(int num) {
	if(num == 0) return v[0];
	int ans = 0;
	while(num > 0) {
		ans += v[num%10];
		num /= 10;
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
	
	int a, b;
	cin >>a >>b;
	
	int ans = 0;
	for(int i = a; i <= b; i++) {
		ans += calc(i);
	}
    
	cout <<ans <<endl;
    return 0;
}

