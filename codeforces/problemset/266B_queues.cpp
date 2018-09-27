#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

    int n, t;
	cin >>n >>t;

	string q;
	cin >>q;
	fori(i,0,t) {
		fori(j,0,n-1) {
			if(q[j] == 'B' and q[j+1] == 'G') {
				q[j] = 'G';
				q[j+1] = 'B';
				j++;
			}
		}
	}
    cout <<q <<endl;
    return 0;
}

