/* O nosso maior medo não é sermos inadequados.
O nosso maior medo é sermos infinitamente poderosos.
É a nossa própria luz, não a nossa escuridão, que nos amedronta.
Sermos pequenos não engrandece o mundo.
Não há nada de transcendente em sermos pequenos,
pois assim os outros não se sentirão inseguros ao nosso lado.
Todos estamos destinados a brilhar, como as crianças.
Não apenas alguns de nós, mas todos.
E, enquanto irradiamos a nossa admirável luz interior,
inconscientemente estamos a permitir aos outros fazer o mesmo.
E, quando nos libertarmos dos nossos próprios medos,
a nossa presença automaticamente libertará os medos dos outros.  */

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector<int> lis(vector<int> &v){

    vector<int> pilha, resp;
    int pos[MAXN], pai[MAXN];

    for(int i=0; i<v.size(); i++){

        vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), v[i]);

        int p = it-pilha.begin();

        if(it==pilha.end()) pilha.PB(v[i]);
        else *it = x;

        pos[p]=i;

        if(p==0) pai[i]=-1; // seu pai será -1
        else pai[i]=pos[p-1];
    }
    int p = pos[pilha.size()-1];

    while(p>=0){
        resp.PB(v[p]);
        p=pai[p];
    }
    reverse(resp.begin(), resp.end());
    return resp;
}


int main() {
	ios_base::sync_with_stdio(false);

	
	
	return 0;
}

