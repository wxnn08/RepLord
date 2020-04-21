#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)

typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main(){
    ios_base::sync_with_stdio(false);
	
	int tc = 0;
	while(++tc) {
		int n, m;
		cin >>n >>m;
		if(n == 0 and m == 0) break;

		int arr[105], maior = 0;
		memset(arr, 0, sizeof arr);
		for(int i = 0; i < 2*m; i++) {
			int a; cin >>a;
			arr[a]++;
			maior = max(arr[a], maior);
		}

		cout <<"Teste " <<tc <<endl;
		for(int i = 1; i <= n; i++) {
			if(arr[i] == maior) cout <<i <<' ';
		}
		cout <<endl;
	}
    
    return 0;
}

