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

const int N = 102;
int qtd[N];
int n, m;
bool can(int d) {
	int people = 0;
	if(d == 0) return true;
	for(int i = 0; i < N; i++) {
		people += (qtd[i]/d);
	}
	if(people >= n) return true;
	return false;
}

int bin(int ini, int fim) {
	
	int mid;
	while(ini <= fim) {
		mid = (ini+fim)/2;
		if(can(mid)) {
			ini = mid+1;
		} else {
			fim = mid-1;
		}
	}
	return mid;
}

int main(){
    ios_base::sync_with_stdio(false);
	
	cin >>n >>m;
	for(int i = 0; i < m; i++) {
		int a; cin >>a;
		qtd[a]++;
	}
    int v = bin(0, 100);
	cout <<(can(v)?v:v-1) <<endl;
    
    return 0;
}

