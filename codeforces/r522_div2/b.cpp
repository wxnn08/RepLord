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

    string s;
	cin >>s;
	int tam = s.size();
	
	int b = 20;
	int a = tam/b;
	if(tam%b != 0) a++;
    
	if(tam <= b) {
		cout <<1 <<' ' <<tam <<endl;
		cout <<s <<endl;
		return 0;
	}

	int na = a;
	while(na == a and b-1 > 0) {
		na = tam/(b-1);
		if(tam%(b-1) != 0) na++;
		b--;
	}
	b++;
	int qtd = (a*b)%tam;
	int last = 0;
	cout <<a <<' ' <<b <<endl;
	for(int i = 0; i < a; i++) {
		int el = b;
		if(qtd > 0) {
			qtd--;
			el--;
			cout <<'*';
		}
		for(int j = 0; j < el; j++) {
			cout <<s[last++];
		}
		cout <<endl;
	}
	
    return 0;
}

