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
bool pecas[15][15];
bool possivel;
int n, m, pri, ult;
 
void bt(int ant, int pos){

	if(pos==n && ant==ult){
		possivel=true;
		return;
	}

	for(int i=0; i<14 && possivel==false; i++){
		if(pecas[ant][i]==true){
			pecas[ant][i]=pecas[i][ant]=false;
			bt(i, pos+1);
			pecas[ant][i]=pecas[i][ant]=true;
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);

	cin >>n;
	while(n){
		cin >>m;
		memset(pecas, false ,sizeof(pecas));

		int aux1, aux2;
		cin >>aux1 >>pri;
		cin >>ult >>aux2;

		for(int i=0; i<m; i++){
			cin >>aux1 >>aux2;
			pecas[aux1][aux2]=pecas[aux2][aux1]=true;
		}

		possivel = false;
		bt(pri, 0);
		if(possivel) cout <<"YES";
		else cout <<"NO";
		cout <<endl;
		cin >>n;
	}
    return 0;
}

