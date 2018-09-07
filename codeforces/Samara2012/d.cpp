#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);

    int n, k;
	cin >>n >>k;
	
	ll qtd = 1;
	int cont = 0;
	while(qtd<n){
		qtd += qtd*k;
		cont++;
	}
	cout <<cont <<endl;

    return 0;
}

