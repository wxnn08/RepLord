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
 
int main(){
    ios_base::sync_with_stdio(false);

    int n, h, a, b, k;
	cin >>n >>h >>a >>b >>k;
	for(int i = 0; i < k; i++) {
		int ta, fa, tb, fb, ans = 0;
		cin >>ta >>fa >>tb >>fb;
		if(ta == tb) {
			cout <<abs(fa-fb) <<endl;
			continue;
		}
		int ff = fa;
		if(fa > b or fa < a) {
			ans += min(abs(fa-a), abs(fa-b));
			if(abs(fa-a) < abs(fa-b))
				ff = a;
			else
				ff = b;
		}
		ans += abs(ta-tb);
		ans += abs(ff-fb);
		cout <<ans <<endl;
	}
    
    return 0;
}

