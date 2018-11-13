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

	int cont5 = 0, cont0 = 0, n;
	cin >>n;

	fori(i, 0, n) {
		int v;
		cin >>v;
		if(v == 5) cont5++;
		else cont0++;
	}
	
	if(cont0 > 0) {
		for(int i = cont5; i > 0; i--) {
			if((5*i)%9 == 0) {
				for(int j = 0; j < i; j++) cout <<5;
				for(int j = 0; j < cont0; j++) cout <<0;
				cout <<endl;
				return 0;
			}
		}
		cout <<0 <<endl;
	}
	else cout <<-1 <<endl;
    return 0;
}

