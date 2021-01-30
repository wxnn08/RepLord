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

const int MAX = 3e5;
ll war[MAX];

int busca(int ini, int fim, ll x){
    int mid = (ini+fim)/2;
    if(war[mid]==x) return mid;
    if(ini>=fim) return mid-1;

    if(x>war[mid]) busca(mid+1, fim, x);
    else if(x<war[mid]) busca (ini, mid-1, x);
}

int main(){
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >>n >>q;
    
    fori(i, 0, n) {
	cin >>war[i];
	if(i>0) war[i]+=war[i-1];
    }
    
    ll danoTotal=0, dano;
    while(q--){
	cin >>dano;
	danoTotal += dano;
	if(danoTotal>=war[n-1]){
	    danoTotal=0;
	    cout <<n <<endl;
	}
	else {
	    int num = busca(0, n-1, danoTotal);
	    cout <<n-(num+1) <<endl;
	    
	}
    }
    
    return 0;
}

