#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define cc(x)   cout << #x << " = " << x << endl
#define ok      cout << "ok" << endl

typedef pair<int,int> ii;
typedef long long ll;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int N = 1e5 + 5;
int dp[N][5];
vector<int> g[N];

/*
Quais os estados q vc consegue pensar?
0 -> nao tem nenhuma aresta de stick chegando no meu noh atual (Serua i noh mais a esquerda da imagem b)/tem uma aresta de mão/pé chegando no meu nó atual
1 -> tem uma aresta de cabeça chegando no nó atual
2 -> tem uma aresta de tronco chegando no meu nó atual
3 -> 
…
*/

int go(int at, int st){

    int &r = dp[at][st];
    if(r != -1)
        return r;

    r = 0;
    
    if(st == 0){
        for(int next : g[at])
            r += max(go(next, 0), go(next, 1) + 1));
    } else if(st == 1){
        if(g[at].size() < 3) return r = -INF;
        vector<ii> bunda, braco;
        for(int i = 0; i < g[at].size(); i++) {
            bunda.eb(go(g[at][i], 2), i);
            braco.eb(go(g[at][i], 2), i);
        }
        sort(bunda.begin(), bunda.end(), greater<ii>());
        sort(braco.begin(), braco.end(), greater<ii>());
        
//decidir quais bundas e quais bracos escolher:
//a ideia era pegar as min(bunda.size(), 3) bundas iniciais e os min(bracos.size(), 3) bracos iniciais e 
//combinar eles se os indices forem diferentes e ver o resultado -> pegar o maior e guardar os indices
//dai pega a melhor combinacao de bracos e bunda e soma todos os outros indices do braco (q nao sao bunda nem bracos oficiais)
//pra ter os valores caso eles fossem novas cabecas (q ja ta incluso no vetor bracos)
    } else if(st == 2){
    
    }

    return r;
}

int main(){
    ios_base::sync_with_stdio(false);

    memset(dp, -1, sizeof(dp));
        int n;
    cin >>n;
    for(int i = 2; i <= n; i++) {
        int a; cin >>a;
        g[a].pb(i);
    }
    
    cout << go(1, 0) << endl;

    return 0;
}

