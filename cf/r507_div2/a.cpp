#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
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

    int n, pw, pb, menor;
	cin >>n >>pb >>pw;
	menor = min(pw, pb);
	int res = 0;
    
	int a[25];
	fori(i,0,n) cin >>a[i];

	for(int i=0; i<n>>1; i++){
		int n1 = a[i], n2 = a[n-1-i];
		if((n1!=2 and n2!=2) and (n1 != n2)) {
			cout <<-1 <<endl;
			return 0;
		}
		if((n1==0 and n2==2) or (n1==2 and n2==0)) res +=pb;
		if((n1==1 and n2==2) or (n1==2 and n2==1)) res +=pw;
		if(n1==2 and n2==2) res += 2*menor;
	}
	if(n%2 == 1 and a[(n>>1)]==2) res+=menor;
	cout <<res <<endl;
    return 0;
}

