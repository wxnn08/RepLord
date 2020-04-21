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

struct t_aresta{
    int dis;
    int x, y;
};

bool comp(t_aresta a, t_aresta b){ 
	return a.dis < b.dis; 
}

const int TAMN = 50500;
const int TAMM = 200200;
int n, m;
t_aresta aresta[TAMM];

int pai[TAMN];
int distancia[TAMN];
t_aresta mst[TAMM];

int find(int x){
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(int a, int b){
    
    a = find(a);
    b = find(b);
    
    if(distancia[a] < distancia[b]) pai[a] = b;
    else if(distancia[b] < distancia[a]) pai[b] = a;
    else{
        pai[a] = b;
        distancia[b]++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    
    for(int i = 1;i <= m;i++)
        cin >> aresta[i].x >> aresta[i].y >> aresta[i].dis;
    
    for(int i = 1;i <= n;i++) pai[i] = i;
    
    sort(aresta+1, aresta+m+1, comp);
    
    int size = 0;
	int res = 0;
    for(int i = 1;i <= m;i++){
        if(find(aresta[i].x) != find(aresta[i].y)){
            join(aresta[i].x, aresta[i].y);
            res += aresta[i].dis;
        }
    }

	cout <<res <<endl;
    
    return 0;
} 
