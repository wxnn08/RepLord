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

    int q;
	cin >>q;

	for(int i = 0; i < q; i++) {
		int l, r, d;
		cin >>l >>r >>d;
		if(l > d)
			cout <<d <<endl;
		else
			cout <<((r/d)+1)*d <<endl;
	}
    
    return 0;
}

