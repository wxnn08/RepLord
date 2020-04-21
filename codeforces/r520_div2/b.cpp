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
	
	const int N = 1e6 + 5;
	int crivo[N];
    int n;
	cin >>n;
	for(int i = 2; i < N; i++) {
		if(crivo[i] == 0) {
			crivo[i] = i;
			for(int j = i+i; j < N; j += i) {
				crivo[j] = i;
			}
		}
	}
    
	int ans = 0;
	int t, k = n;
	while(true) {
		map<int, int> m;
		t = k;
		while(k > 1) {
			m[crivo[k]]++;
			k /= crivo[k];
		}
		map<int,int>::iterator it;
		bool opM = false;
		for(it = m.begin(); !opM and it != m.end(); it++) {
			if(it->sec > 1) opM = true;
		}

		if(!opM) break;
		
		int mult = 1, maior = -1;
		bool impar = false;
		for(it = m.begin(); it != m.end(); it++) {
			maior = max(maior, (it->sec%2 == 1? it->sec+1:it->sec));
			if(it->sec%2 == 1) impar = true;
		}
		for(it = m.begin(); impar and it != m.end(); it++) {
			mult *= pow(it->fi, (maior - it->sec));
		}
		if(mult != 1){
			t *= mult;
			ans++;
		}

		k = sqrt(t);
		ans++;
	}
	cout <<t <<' ' <<ans <<endl;

    return 0;
}

