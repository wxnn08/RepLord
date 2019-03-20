#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main() {
    ios_base::sync_with_stdio(false);
	
	int n, p, q;
	cin >>n >>p >>q;
	string s;
	cin >>s;

	for(int i = 0; i < 101; i++) {
		int r = n-p*i;
		if(r < 0) break;
		if(r%q == 0) {
			cout <<i+(r/q) <<endl;
			int cont = 0;
			for(int j = 0; j < i; j++) {
				for(int k = 0; k < p; k++) {
					cout <<s[cont+k];
				}
				cont += p;
				cout <<endl;
			}

			for(int j = 0; j < r/q; j++) {
				for(int k = 0; k < q; k++) {
					cout <<s[cont+k];
				}
				cont += q;
				cout <<endl;
			}
			return 0;
		}
	}
	
	cout <<-1 <<endl;
    return 0;
}

