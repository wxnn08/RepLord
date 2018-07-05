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

string s;
bool verifica(int i){
	if(s[i]=='A'){

		if(s[i+1]=='B')
			if(s[i+2]=='C') return true;

		if(s[i+1]=='C')
			if(s[i+2]=='B') return true;
	}

	if(s[i]=='B'){

		if(s[i+1]=='A')
			if(s[i+2]=='C') return true;

		if(s[i+1]=='C')
			if(s[i+2]=='A') return true;
	}

	if(s[i]=='C'){

		if(s[i+1]=='A')
			if(s[i+2]=='B') return true;

		if(s[i+1]=='B')
			if(s[i+2]=='A') return true;
	}

	return false;
}

int main(){
    ios_base::sync_with_stdio(false);

	cin >>s;
    
	// ABC ACB BAC BCA CAB CBA
	bool valido = false;
	if(s.length()<3) valido = false;
	else {
		for(int i=0; i<s.length()-2; i++){
			if(verifica(i)) valido = true;
		}
	}

	if(valido) cout <<"Yes";
	else cout <<"No";
	cout <<endl;
    return 0;
}

