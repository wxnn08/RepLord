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

	int n;
	cin >>n;
	int soma = 0;
	set<int> s;

	for(int i = 0; i < n; i++) {
		int a; cin >>a;
		s.insert(a);
		soma += a;
	}
	
	set<int>::iterator ita, itb;
	for(ita = s.begin(); ita != s.end(); ita++) {
		int v1 = *ita;
		for(itb = s.begin(); itb != s.end(); itb++) {
			int v2 = *itb;
			for(int i = 1; i <= v2; i++) {
				if(v2%i == 0) {
					int nv = v2/i;
					int nm = v1*i;
					soma = min(soma, soma - v1 - v2 + nv + nm);
				}
			}
		}
	}

	cout <<soma <<endl;

    return 0;
}

