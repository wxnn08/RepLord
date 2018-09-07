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

typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);
	
	int n;
	cin >>n;
	if(n<=2) {
		cout <<"No" <<endl;
		return 0;
	}

	cout <<"Yes" <<endl;
	if(n==3){
		cout <<"1 2" <<endl;
		cout <<"2 1 3" <<endl;
		return 0;
	}
	
	
	bool par = 0;
	ll s1 = 0;
	for(int i=1; i<=n; i+=2) s1 += i;
	if(s1%2==1) par = 1;
	
	if(par == 1){
		cout <<(n/2)-1 <<' ';
		for(int i=4; i<=n; i+=2){
			cout <<i <<' ';
		}
		cout <<endl;
		
		cout <<(n/2)+2 <<' ';
		cout <<"1 2 ";
		for(int i=3; i<=n; i+=2){
			cout <<i <<' ';
		}
		cout <<endl;
	} else {
		cout <<n/2 <<' ';
		for(int i=2; i<=n; i+=2){
			cout <<i <<' ';
		}
		cout <<endl;
		
		cout <<(n/2)+1 <<' ';
		for(int i=1; i<=n; i+=2){
			cout <<i <<' ';
		}
		cout <<endl;
	}
}

