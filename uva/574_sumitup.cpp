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
vector <int> num;
vector <int> perc;
int sof, n;
set <string> resultados;

void bt(int pos, int total){

	if(total==sof){
		string res;
		for(int i=0; i<perc.size(); i++){
			res+=to_string(perc[i]);
			if(i<perc.size()-1) res+='+';
		}
		if(!resultados.count(res)) {
			cout <<res <<endl;
			resultados.insert(res);
		}
		return;
	}
	
	for(int i=pos; i<num.size(); i++){
		if(total+num[i]<=sof){
			perc.pb(num[i]);
			bt(i+1, total+num[i]);
			perc.pop_back();
		}
	}

	return;
}

int main(){
    ios_base::sync_with_stdio(false);
    
    cin >>sof >>n;
	
	while(sof!=0 && n!=0){
		num.clear();
		resultados.clear();
		perc.clear();

		int aux;
		for(int i=0; i<n; i++){
			cin >>aux;
			num.pb(aux);
		}
		cout <<"Sums of " <<sof <<":" <<endl;
		bt(0, 0);
		if(resultados.size()==0) cout <<"NONE" <<endl;

		cin >>sof >>n;
	}

    return 0;
}

