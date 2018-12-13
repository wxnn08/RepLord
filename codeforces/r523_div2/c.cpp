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

int n;
const int N = 1e6 + 5;
vector<int> v[N];



int main(){
    ios_base::sync_with_stdio(false);

	for(int i = 2; i < N; i++) {
		if(v[i].size() == 0) {
			for(int j = i; j < N; j += i) {
				v[j].pb(i);
			}
		}
	}
	
	cin >>n;
	for(int i = 0; i < n; i++) {
		cout <<i <<"-> ";
		for(int j:v[i]) cout <<j <<' ';
		cout <<endl;
	}

    return 0;
}

