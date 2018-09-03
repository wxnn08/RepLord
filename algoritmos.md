# Algoritmos

## Configuração

### vimrc

```c++
set number
set showmatch
 
set autoindent
set smartindent
set shiftwidth=4
set softtabstop=4
set tabstop=4

nnoremap <C-J> <C-W><C-J>
nnoremap <C-K> <C-W><C-K>
nnoremap <C-L> <C-W><C-L>
nnoremap <C-H> <C-W><C-H>

au BufNewFile ~/*.cpp 0r ~/.base.cpp
```

### base.cpp

```c++
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
    
    return 0;
}
```

## Tecnicas de programação

### Soma máxima

```c++
int max_sum(vector<int> s) {
	int resp = 0, maior = 0;
	for(int i = 0; i<s.size(); i++) {
		maior = max(0,maior+s[i]);
		resp = max(resp,maior);
	}
	return resp;
}
```

### Contagem de inversões

```c++
int merge_sort(vector<int> &v){
	
    int inv=0;
    // se o tamanho de v for 1, não há inversões
    if(v.size()==1) return 0;

    vector<int> u1, u2;

    // e faço cada um receber uma metade de v
    for(int i=0;i<v.size()/2;i++){
        u1.push_back(v[i]);
    }
    for(int i=v.size()/2;i<v.size();i++){
        u2.push_back(v[i]);
    }	
    // ordeno u1 e u2
    // adiciono a inv as inversões de cada metade do vetor
    inv += merge_sort(u1);
    inv += merge_sort(u2);
    u1.push_back(INF);
    u2.push_back(INF);

    int ini1=0, ini2=0;

    for(int i=0;i<v.size();i++){
        // se o menor não usado de u1 for menor o mesmo em u2
        if(u1[ini1]<=u2[ini2]){
            // então o coloco em v
            v[i]=u1[ini1];
            // e incremento o valor de ini1
            ini1++;
        }
        // caso contrário, faço o análogo com u2 e ini2
        else {
            v[i]=u2[ini2];
            ini2++;
            // não se esquecendo de adicionar o número de elementos em u1
            // ao total de inversões em v
            inv += u1.size()-ini1-1;
        }
    }

    return inv;
}
```

## Estruturas de dados

### Union-Find (log N)

```c++
const int MAX = 100;
int pai[MAX], peso[MAX], qtd[MAX];

int find(int x) {
	if(pai[x]==x) return x;
	return pai[x] = find(pai[x]);
}

void join(int x, int y) {
	x = find(x);
	y = find(y);
	if(x==y) return;

	if(peso[x] > peso[y]) {
		pai[y] = x;
		qtd[y] += qtd[x];
	}
	else if(peso[x] < peso[y]) {
		pai[x] = y;
		qtd[x] += qtd[y];
	}
	else {
		pai[x] = y;
		peso[y]++;
		qtd[x] += qtd[y];
	}
}
```

### LIS

- Quantidade de elementos na maior subsequencia crescente:

```c++
int lis(vector<int> &v){
	vector<int> pilha;
	for(int i=0; i<v.size(); i++){
		vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), v[i]);
		if(it==pilha.end()) pilha.pb(v[i]);
		else *it = v[i];
	}
	return pilha.size();
}
```

- Elementos da maior subsequencia crescente (um conjunto):

```c++
vector<int> lis(vector<int> &v){
	vector<int> pilha, resp;
	int pos[MAXN], pai[MAXN];
	for(int i=0; i<v.size(); i++){
		vector<int>::iterator it = lower_bound(pilha.begin(), pilha.end(), v[i]);
		int p = it-pilha.begin();
		
		if(it==pilha.end()) pilha.PB(v[i]);
		else *it = x;
		
        pos[p]=i;

        if(p==0) pai[i]=-1;
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
```
## Grafos

### BFS - O(M + N)

```c++
void BFS(int x){
	
	queue<int> fila;
	fila.push(x); // fila da nossa BFS
	
	componente[x] = valor; // colocamos o valor adequado aqui
	
	int atual = 0; // atual posição que estamos na fila
	
	while(!fila.empty()){ // Enquanto a fila não for vazia
		
		// vamos trabalhar com o primeiro da fila
		int v = fila.front();
		fila.pop(); // para movermos o elemento da fila
		
		for(int i = 0;i < (int)vizinhos[v].size();i++){
			
			int u = vizinhos[v][i];
			
			if(componente[u] == -1){
				
				// se u ainda não tiver sido visitado, o acrescentamos a fila
				componente[u] = componente[v];
				fila.push(u);
			}
		}
	}
}
```

### TopoSort - O(M + N)

```c++
#include <vector>
#include <iostream>
using namespace std;
//------------------------------
#define MAXN 100100
int n; // número de vértices
int m; // número de arestas
vector<int> grafo[MAXN];
int grau[MAXN];
vector<int> lista; // dos vértices de grau zero
//------------------------------
int main(){
	
	cin >> n >> m;

	for(int i = 1;i <= m;i++){
		int x, y;
		cin >> x >> y;

		// tarefa X tem que ser executada antes da tarefa Y
		grau[y]++;
		grafo[x].push_back(y);
	}
	
	for(int i = 1;i <= n;i++) if(grau[i] == 0) lista.push_back(i);
	
	// o procedimento a ser feito é semelhante a uma BFS
	int ini = 0;
	while(ini < (int)lista.size()){

		int atual = lista[ini];
		ini++;
		
		for(int i = 0;i < (int)grafo[atual].size();i++){
			int v = grafo[atual][i];
			grau[v]--;
			if(grau[v] == 0) lista.push_back(v); // se o grau se tornar zero, acrescenta-se a lista
		}
	}

	// agora, se na lista não houver N vértices,
	// sabemos que é impossível realizar o procedimento

	if((int)lista.size() < n) cout << "impossivel\n";
	else{
		for(int i = 0;i < (int)lista.size();i++) cout << lista[i] << " ";
		cout << endl;
	}
	
	return 0;
}
```

### Dijkstra - O(M log N)

```c++
int dijkstra(int S) {
	memset(dist, INF, sizeof dist);
	dist[S] = 0;
	priority_queue<pii, vector<pii>, greater<pii> > fila;
	fila.push(pii(dist[S], S));

	while(true) {
		int davez = -1;
		while(!fila.empty()) {
			int atual = fila.top().second;
			fila.pop();
			if(!visit[atual]) {
				davez = atual;
				break;
			}
		}
		if(davez == -1) break;

		visit[davez] = true;

		for(int i=0; i<(int)vizinhos[davez].size(); i++) {
			int dist = vizinho[davez][i]].fi;
			int atual = vizinho[davez][i]].sec;

			if(dist[atual] > dist[davez]+dist) {
				dist[atual = dist[davez]+dist;
				fila.push(pii(dist[atual], atual));
			}
		}
	}
}
```

### Floyd-Warshall - O(n³)

```c++
for(int k = 1;k <= n;k++)
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
	        distancia[i][j] = min(distancia[i][j], distancia[i][k] + distancia[k][j]);
```

### Kruskal - O(M log N)

```c++
int main(){
    cin >> n >> m;
    for(int i = 1;i <= m;i++)
        cin >> aresta[i].x >> aresta[i].y >> aresta[i].dis);

    for(int i = 1;i <= n;i++) pai[i] = i;
    
    sort(aresta+1, aresta+m+1, comp);
    
    int size = 0;
    for(int i = 1;i <= m;i++){
        if( find(aresta[i].x) != find(aresta[i].y) ){ 
            join(aresta[i].x, aresta[i].y);
            mst[++size] = aresta[i];
        }
    }

    for(int i = 1;i < n;i++) 
        cout << mst[i].x << " " << mst[i].y << " " << mst[i].dis) << "\n";
    
    return 0;
}

```

### Prim - O(M log N)

```c++

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;   // para não termos que digitar pair<int, int> várias vezes,
                              // fazemos isso para deixar o código mais organizado

//---------------------
#define MAXN 10100
// como não existe o Infinito no computador, usaremos um número bem grande
#define INFINITO 999999999

int n, m;                      // número de vértices e arestas
int distancia[MAXN];           // o array de distâncias à fonte
int processado[MAXN];          // o array que guarda se um vértice foi processado
vector<pii> vizinhos[MAXN];    // nossas listas de adjacência. O primeiro elemento do par representa a distância e o segundo representa o vértice
//---------------------

int Prim(){
	
	for(int i = 2;i <= n;i++) distancia[i] = INFINITO; // definimos todas as distâncias como infinito, exceto a de S = 1.
	distancia[1] = 0;                                  // Assim, garantimos que o primeiro vértice selecionado será o próprio 1.
	
	priority_queue< pii, vector<pii>, greater<pii> > fila; // Criamos uma fila de prioridade onde o menor fica no topo.
	fila.push( pii(distancia[1], 1) );                     // Como se pode ver, colocamos o primeiro elemento como seja a distância do
	                                                       // vértice a Árvore Geradora Mínima e o segundo como sendo o próprio vértice
	
	while(true){ // rodar "infinitamente"
		
		int davez = -1;
		
		// selecionamos o vértice mais próximo
		while(!fila.empty()){
			
			int atual = fila.top().second;
			fila.pop();
			
			if(!processado[atual]){ // podemos usar esse vértice porque ele ainda não foi processado
				davez = atual;
				break;
			}
			
			// se não, continuamos procurando
		}
		
		if(davez == -1) break; // se não achou ninguém, é o fim do algoritmo
		
		processado[davez] = true; // marcamos para não voltar para este vértice
		
		// agora, tentamos atualizar as distâncias
		for(int i = 0;i < (int)vizinhos[davez].size();i++){
			
			int dist  = vizinhos[davez][i].first;
			int atual = vizinhos[davez][i].second;
			
			// A nova possível distância é dist.
			// Comparamos isso com distancia[atual].
			// Porém, é importante checar se o vértice atual não foi processado ainda
			
			if( distancia[atual] > dist && !processado[atual]){  // vemos que vale a pena usar o vértice davez
				distancia[atual] = dist;                         // atualizamos a distância
				fila.push( pii(distancia[atual], atual) );       // inserimos na fila de prioridade
			}
		}
	}
	
	int custo_arvore = 0;
	for(int i = 1;i <= n;i++) custo_arvore += distancia[i];
	
	return custo_arvore;
}

int main(){
	
	cin >> n >> m;
	
	for(int i = 1;i <= m;i++){
		
		int x, y, tempo;
		cin >> x >> y >> tempo;
		
		vizinhos[x].push_back( pii(tempo, y) );
		vizinhos[y].push_back( pii(tempo, x) );
	}
	
	cout << Prim() << endl; // imprimimos a resposta
	
	return 0;
}
```