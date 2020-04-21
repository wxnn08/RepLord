#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
 
int main(){
    ios_base::sync_with_stdio(false);

    //le c e n
    int c, n;
    cin >>c >>n;

    //armazena progs instalados
    map<int, int> inst;
    pair <int, int> p;
    for(int i=0; i<c; i++){
	cin >>p.fi >>p.se;
	inst[p.fi] = p.se;
    }
    //le progs da internet, se algum for melhor q o atual, armazenar
    map<int,int>::iterator it;
    vector<int> progsNovos;
    for(int i=0; i<n; i++){
	cin >>p.fi >>p.se;
	it = inst.find(p.fi);
	
	//ve se é a v mais att
	if(it!=inst.end()){
	    if((p.se)>(it->se)){
		it->se = p.se;
		progsNovos.pb(it->fi);
	    }
	}
    }
    //imprime progs melhores
    for(int i=0; i<progsNovos.size(); i++){
	it=inst.find(progsNovos[i]);
	cout <<it->fi <<' ' <<it->se <<endl;
    }
    return 0;
}

