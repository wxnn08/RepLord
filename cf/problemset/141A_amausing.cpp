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
 
const int N = 30;
int qtd[N], nl[N];

int main(){
    ios_base::sync_with_stdio(false);
	
    string a, b, c;
	cin >>a >>b >>c;
	for(int i = 0; i < a.size(); i++) qtd[a[i]-'A']++;
	for(int i = 0; i < b.size(); i++) qtd[b[i]-'A']++;
	for(int i = 0; i < c.size(); i++) nl[c[i]-'A']++;
	
	bool ans = true;
	for(int i = 0; i < N; i++) {
		if(qtd[i] != nl[i]) ans = false;
	}
	
	cout <<(ans?"YES":"NO") <<endl;
    return 0;
}

