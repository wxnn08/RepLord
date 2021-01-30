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
 
bool low, num, up;
int qtdLow, qtdNum, qtdUp;
bool valida(string s) {
	low = up = num = false;
	for(int i=0; i<s.size(); i++) {
		if(s[i] >= 'a' and s[i] <= 'z') low = true;
		if(s[i] >= 'A' and s[i] <= 'Z') up = true;
		if(s[i] >= '0' and s[i] <= '9') num = true;
	}

	return low and up and num;
}

void change(string &s, int k, char c1, char c2) {
	if(k == 1) {
		for(int i = 0; i < s.size(); i++) {
			char aux = s[i];
			s[i] = c1;
			if(valida(s)) return;
			s[i] = aux;
		}
	} else {
		for(int i = 1; i < s.size(); i++) {
			for(int j = 0; j < s.size()-i; j++) {
				char aux1, aux2;
				aux1 = s[j];
				aux2 = s[j+i];
				s[j] = c1;
				s[j+i] = c2;
				if(valida(s)) return;
				s[j] = c2;
				s[j+i] = c1;
				if(valida(s)) return;
				s[j] = aux1;
				s[j+i] = aux2;
			}
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);

    int tc;
	cin >>tc;

	while(tc--) {
		string s;
		cin >>s;
		if(valida(s)) {
			cout <<s <<endl;
			continue;
		}

		if(num == 0 and low == 0 and up == 0) cout <<"?" <<endl;
		else if(num == 0 and low == 0 and up == 1) change(s, 2, '1', 'a');
		else if(num == 0 and low == 1 and up == 0) change(s, 2, 'A', '1');
		else if(num == 0 and low == 1 and up == 1) change(s, 1, '1', '-');
		else if(num == 1 and low == 0 and up == 0) change(s, 2, 'a', 'A');
		else if(num == 1 and low == 0 and up == 1) change(s, 1, 'a', '-');
		else if(num == 1 and low == 1 and up == 0) change(s, 1, 'A', '-');
		else if(num == 1 and low == 1 and up == 1);
		cout <<s <<endl;
	}
    
    return 0;
}

