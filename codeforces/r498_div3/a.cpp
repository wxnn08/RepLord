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

    int n;
	cin >>n;
	fori(i,0,n){
		int aux;
		cin >>aux;
		if(aux%2 == 0){
			cout <<aux-1;
		} else {
			cout <<aux;
		}
		cout <<' ';
	}
	cout <<endl;
    
    return 0;
}

