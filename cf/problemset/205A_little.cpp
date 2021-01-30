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

    int n;
	cin >>n;
	
	int menor = 2e9;
	int qtd = 1;
	int id = -1;
	for(int i = 0; i < n; i++) {
		int v; cin >>v;
		if(v == menor) qtd++;
		if(v < menor) {
			id = i+1;
			menor = v;
			qtd = 1;
		}
	}
    
	if(qtd > 1) cout <<"Still Rozdil" <<endl;
	else cout <<id <<endl;
    return 0;
}

