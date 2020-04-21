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

    int q, s;
	cin >>q >>s;
    
	const int N = 5e3+5;
	pair<int, int> p[N];
	for(int i = 0; i < s; i++) {
		cin >>p[i].fi >>p[i].sec;
	}
	sort(p, p+s);
	
	cout <<p[0].fi <<' ';
	int maior = p[0].sec;
	for(int i = 1; i < s; i++) {
		if(p[i].fi > maior) {
			cout <<maior <<endl <<p[i].fi <<' ';
		}
		maior = max(maior, p[i].sec);
	}
	cout <<maior <<endl;

    return 0;
}

