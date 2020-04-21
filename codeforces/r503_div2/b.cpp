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
 
const int N = 1e3 + 5;
bool visit[N];

int main(){
    ios_base::sync_with_stdio(false);

    int n; cin >>n;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		int a; cin >>a;
		v.pb(a-1);
	}

    for(int i = 0; i < n; i++) {
		int j = i;
		memset(visit, 0, sizeof visit);
		while(true) {
			if(visit[j])
				break;
			else
				visit[j] = true;
			j = v[j];
		}
		cout <<j+1 <<' ';
	}
	cout <<endl;

    return 0;
}

