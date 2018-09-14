# Algoritmos

## Configuração

### vimrc

```pseudocode
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

### Compressão de coordenadas

```c++
const int N = 1e5 + 5;
ll n, v[N];

int main() {
    
    vector<ll> ve;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        ve.push_back(v[i]);
    }
    sort(ve.begin(), ve.end());
    ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
    
    map<ll, int> id;
    for(int i = 0; i < (int)ve.size(); i++) 
        id[ve[i]] = i;

    for(int i = 0; i < n; i++)
        v[i] = id[v[i]];

    return 0;
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

### Segmentation Tree com Lazy Propagation (log N)

``` c++
const int N = 1e5 + 5;
ll seg[4*N+1];
ll lazy[4*N+1];

void prop(int r, int i, int j){
	seg[r] += lazy[r]*(j-i+1);
	
	if(i != j) {
		lazy[2*r] += lazy[r];
		lazy[2*r+1] += lazy[r];
	}
	lazy[r] = 0;
}

ll query(int r, int i, int j, int a, int b){
	prop(r,i,j);
	if(i >b or j<a) return 0;
	if(i>=a and j<=b) return seg[r];
	
	int mid = (i+j)>>1;
	return query(2*r, i, mid, a, b) + query(2*r+1, mid+1, j, a, b);
}

void update(int r, int i, int j, int a, int b, int v){
	prop(r, i, j);
	if(i>b or j<a) return;
	if(i>=a and j<=b) {
		lazy[r] += (ll)v;
		prop(r, i, j);
		return;
	}
	int mid = (i+j)>>1;
	update(2*r, i, mid, a, b, v);
	update(2*r+1, mid+1, j, a , b, v);
	seg[r] = seg[2*r] + seg[2*r+1];
	return;
}

int main(){
    return 0;
}
```

### LIS s/ Seg Tree

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
#define MAXN 100100
int n; // número de vértices
int m; // número de arestas
vector<int> grafo[MAXN];
int grau[MAXN];
vector<int> lista; // dos vértices de grau zero
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
			// se o grau se tornar zero, acrescenta-se a lista
			if(grau[v] == 0) lista.push_back(v); 
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
#define MAXN 10100
#define INFINITO 999999999

// número de vértices e arestas
int n, m; 
int distancia[MAXN];	// o array de distâncias à fonte
int processado[MAXN];	
vector<pii> vizinhos[MAXN]; // <distancia, vertice>

int Prim(){
	for(int i = 2;i <= n;i++) distancia[i] = INFINITO; 
	distancia[1] = 0;                                  
	priority_queue< pii, vector<pii>, greater<pii> > fila; 
	// Colocamos o primeiro elemento como seja a distância do
	// vértice a Árvore Geradora Mínima e o segundo como sendo o próprio vértice
	fila.push( pii(distancia[1], 1) );                     

	while(true){ 
		int davez = -1;
		while(!fila.empty()){
			int atual = fila.top().second;
			fila.pop();
			
			if(!processado[atual]){ 
				davez = atual;
				break;
			}
		}
		if(davez == -1) break; 
		
		processado[davez] = true; 
		
		for(int i = 0;i < (int)vizinhos[davez].size();i++){
			
			int dist  = vizinhos[davez][i].first;
			int atual = vizinhos[davez][i].second;
			
			// A nova possível distância é dist.
			// Comparamos isso com distancia[atual].
			// Porém, é importante checar se o vértice atual não foi processado ainda
			if( distancia[atual] > dist && !processado[atual]){  
				distancia[atual] = dist;                         
				fila.push( pii(distancia[atual], atual) );       
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
	cout << Prim() << endl;
	return 0;
}
```



## Strings

### KMP

```c++
border = proper prefix that is suffix p[i] = 
    = length of longest border of prefix of length i, s[0...i-1]

const int N = 1e6 + 6;
int pi[N];
string p, t;

void pre () {
	p += '#';
	pi[0] = pi[1] = 0;
	for (int i = 2; i <= (int)p.size(); i++) {
		pi[i] = pi[i-1];

		while (pi[i] > 0 and p[pi[i]] != p[i-1])
			pi[i] = pi[pi[i]];

		if (p[pi[i]] == p[i-1])
			pi[i]++;
	}
}

void report (int at) {
	cout << "padrao encontrado em " << at << endl;
}

void KMP () {
	pre ();

	int k = 0;
	int m = p.size() - 1;

	for (int i = 0; i < (int)t.size(); i++) {
		while (k > 0 and p[k] != t[i])
			k = pi[k];
		
		if (p[k] == t[i])
			k++;
		if (k == m)
			report (i - m + 1);
	}

}
```

### Trie

```c++
struct Trie {
	int cnt, word;
	map <char, Trie> m;
 
	Trie () {
		word = cnt = 0;
		m.clear();
	}
 
	void add (const string &s, int i) {
		cnt++;
		if (i == (int)s.size()) {
			word++;
			return;
		}
 
		if (!m.count(s[i])) 
			m[s[i]] = Trie();
 
		m[s[i]].add(s, i + 1);
	}

	bool remove (const string &s, int i) {
		if (i == (int)s.size()) {
			if (word) {
				word--;
				return true;
			}
			return false;
		}
		if (!m.count(s[i]))
			return false;
		if (m[s[i]].remove(s, i + 1) == true) {
			cnt--;
			return true;
		}
		return false;
	}
 
	bool count (const string &s, int i) {
		if (i == (int)s.size())
			return word;
		if (!m.count(s[i]))
			return false;
		return m[s[i]].count(s, i + 1);
	}
 
	bool count_prefix (const string &s, int i) {
		if (word)	return true;
		if (i == (int)s.size())
			return false;
		if (!m.count(s[i]))
			return false;
		return m[s[i]].count_prefix(s, i + 1);
	}
 
	bool is_prefix (const string &s, int i) {
		if (i == (int)s.size())
			return cnt;
		if (!m.count(s[i]))
			return false;
		return m[s[i]].is_prefix(s, i + 1);
	}
 
	void add (const string &s) {
		add (s, 0);
	}
 
	bool remove (const string &s) {
		return remove(s, 0);
	}
 
	bool count (const string &s) {
		return count(s, 0);
	}
 
	// return if trie countains a string that is prefix os s
	// trie has 123, query 12345	returns true
	// trie has 12345, query 123 	returns false
	bool count_prefix (const string &s) {
		return count_prefix(s, 0);
	}
 
	// return if s is prefix of some string countained in trie
	// trie has 12345, query 123 	returns true
	// trie has 123, query 12345	returns false
	bool is_prefix (const string &s) {
		return is_prefix(s, 0);
	}
} T;
```

## Outros

### Tabela ASCII

![Imgur](https://i.imgur.com/tsyZFvh.png)

### Séries

![Imgur](https://i.imgur.com/BtYUYKn.png)



### Containers - Regional 2016

```c++
struct state {
	int v[2][4];
	state(){}
	
	void read(){
		fori(i,0,2)
			fori(j,0,4)
				cin >>v[i][j];
	}

	bool operator<(const state &b) const{
		fori(i,0,2)
			fori(j,0,4)
				if(v[i][j] != b.v[i][j]) 
					return v[i][j]<b.v[i][j];
		return false;
	}

	bool operator==(const state &b) const{
		if((*this)<b or b<(*this)) return false;
		return true;
	}

} beg, last;

int dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};

bool pode(int i, int j){
	return i>=0 and j>=0 and i<2 and j<4;
}

int go(){
	map<state, int> m;
	priority_queue<pair<int, state>, 
    	vector<pair<int, state> >, greater<pair<int,state> > > pq;
	m[beg] = 0;

	pq.emplace(0, beg);
	while(!pq.empty()){
		
		state at = pq.top().sec;
		int dist = pq.top().fi;
		pq.pop();
		
		if(at == last) 
			return dist;

		for(int i=0; i<2; i++){
			for(int j=0; j<4; j++){
				for(int k=0; k<4; k++){
					int ii = i+dir[k][0];
					int jj = j+dir[k][1];
					
					if(!pode(ii,jj)) continue;

					state next = at;
					swap(next.v[ii][jj], next.v[i][j]);

					int peso = next.v[ii][jj] + next.v[i][j];
					if(!m.count(next) or m[next]>peso+dist){
						m[next] = peso+dist;
						pq.emplace(peso+dist, next);
					}
				}
			}
		}
	}

	return INF;
}

 
int main(){
    ios_base::sync_with_stdio(false);

    beg.read();
    last.read();

    cout <<go() <<endl;

    return 0;
}
```

