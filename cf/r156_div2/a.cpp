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

	int a[3];
	memset(a, 0, sizeof a);
	int n; cin >>n;

    for(int i = 0; i < n; i++) {
		int v; cin >>v;
		a[i%3] += v;
	}
	
	if(a[0] > a[1] and a[0] > a[2])
		cout <<"chest" <<endl;

	if(a[1] > a[0] and a[1] > a[2])
		cout <<"biceps" <<endl;

	if(a[2] > a[1] and a[2] > a[0])
		cout <<"back" <<endl;

    return 0;
}

