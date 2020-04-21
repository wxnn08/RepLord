#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
typedef pair<int,int> pii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
 
int main(){
    ios_base::sync_with_stdio(false);

    string s;
    char c;

	while(cin >>c){
		if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') 
			s += c;
	}
	
	int tam = s.size();
	bool res = true;
	for(int i=0; i<tam/2 && res; i++){
		if(s[i]!=s[tam-1-i]) res = false;
	}

	cout <<(res?'S':'N') <<endl;
    return 0;
}

