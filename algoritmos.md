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
#define eb emplace_back
#define mk make_pair
#define fi first
#define sec second
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl

typedef pair<int,int> ii;
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

### Soma máxima circular

```c++
int kadane(int a[], int n);
// The function returns maximum circular contiguous sum
// in a[]
int maxCircularSum(int a[], int n) {
   // Case 1: get the maximum sum using standard kadane'
   // s algorithm
   int max_kadane = kadane(a, n);
   // Case 2: Now find the maximum sum that includes
   // corner elements.
   int max_wrap = 0, i;
   for (i=0; i<n; i++) {
        max_wrap += a[i]; // Calculate array-sum
        a[i] = -a[i];  // invert the array (change sign)
   }
 
   // max sum with corner elements will be:
   // array-sum - (-max subarray sum of inverted array)
   max_wrap = max_wrap + kadane(a, n);
   // The maximum circular sum will be maximum of two sums
   return (max_wrap > max_kadane)? max_wrap: max_kadane;
}
 
int kadane(int a[], int n) {
    int max_so_far = 0, max_ending_here = 0;
    int i;
    for (i = 0; i < n; i++) {
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}
int main() {
    int a[] =  {11, 10, -20, 5, -3, -5, 8, -13, 10};
    int n = sizeof(a)/sizeof(a[0]);
    printf("Maximum circular sum is %dn", maxCircularSum(a, n));
    return 0;
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

### Caminho Euleriano

```c++
// variáveis usadas -------------
vector<int> caminho; // guardará nosso Caminho Euleriano (invertido)
vector<int> vizinhos[MAXN]; // nossa lista de adjacência
map< pair<int, int>, bool > deletada; // mapa que checa se a aresta já foi deletada
// isso aumenta um pouco nossa complexidade, mas não de forma preocupante
//-------------------------------

// algoritmo:

void acha_caminho(int v) {
	// percorremos os vizinhos de v e chamamos a função recursiva neles
	// se não tivermos mais nenhuma chamada recursiva a fazer, este for não terá efeito
	
	for(int i = 0;i < (int)vizinhos[v].size();i++){
		
		int viz = vizinhos[v][i];
		// caso já tenhamos deletado essa aresta
		if( deletada[make_pair(v, viz)] == true ) continue; 
		
		// agora, deletamos a aresta e chamamos a função recursivamente
		deletada[make_pair(v, viz)] = true;
		deletada[make_pair(viz, v)] = true;
		
		acha_caminho(viz); 
	}
	// após processarmos os vizinhos (caso existam), adicionamos ao caminho
	caminho.push_back(v); 
}
```

### Bipart

```c++
// variáveis usadas --------------
int n;                      // número de vértices
vector<int> vizinhos[MAXN]; // a lista de adjacência de cada vértice
int cor[MAXN]; // a cor de cada vértice. Inicialmente, cor[i] = -1 para todos os vértices.
			   // definimos cor[i] = 0 como sendo azul e cor[i] = 1 como sendo rosa.
//--------------------------------

void colore(int x){ // x é o vértice inicial que começaremos colorindo.
	
	cor[x] = 0; // definimos a cor de x como sendo azul
	
	vector<int> fila; // a fila de execução de BFS
	fila.push_back(x); // adicionamos x a fila
	
	int pos = 0; // a posição que estamos na fila
	
	while(pos < (int)fila.size()){ // BFS
		
		int atual = fila[pos]; // o vértice que trabalharemos agora
		pos++;
		
		for(int i = 0;i < (int)vizinhos[atual].size();i++){
			
			int v = vizinhos[atual][i];
			
			if(cor[v] == -1){ // caso v ainda não tenha sido colorido
                // isso faz com que a cor de v seja a oposta a do vértice atual			
				cor[v] = 1 - cor[atual]; 
				fila.push_back(v); // adicionamos v a fila da BFS
			}
		}
	}
}

bool checa_bipartido() {
	// executaremos a BFS enquanto existirem vértices não coloridos.
	// cada chamada a BFS corresponde a uma nova componente conexa do grafo
	
	for(int i = 1;i <= n;i++){
		if(cor[i] == -1){       // achamos um vértice em uma nova componente conexa.
			colore(i);          // começamos a colorir a partir desse vértice
		}
	}
	
	// agora, checamos se existem dois vértices vizinhos com a mesma cor
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < (int)vizinhos[i].size();j++){

			int v = vizinhos[i][j];
             // se os dois vizinhos possuem a mesma cor, o grafo não é bipartido
			if(cor[i] == cor[v]) return false;
		}
	}
	return true; // se não encontramos nenhum problema, o grafo é bipartido
}
```

### LCA

```c++
#define MAXL    20
#define MAXN 50500

// básico
int n;
int c[MAXN];
int par[MAXN];

// LCA
int pai[MAXN];
int nivel[MAXN];
int ancestral[MAXN][MAXL];

// grafo
vector<int> lista[MAXN];
//--------------------------

void dfs(int u){
	
	for(int i = 0;i < (int)lista[u].size();i++){
		int v = lista[u][i];
		
		if(nivel[v] == -1){
			pai[v] = u;
			nivel[v] = nivel[u]+1;
			
			dfs(v);
		}
	}
	
}

int LCA(int u, int v){
	
	if(nivel[u] < nivel[v]) swap(u, v);
	
	for(int i = MAXL-1;i >= 0;i--)
		if(nivel[u] - (1<<i) >= nivel[v])
			u = ancestral[u][i];
	
	if(u == v) return u;
	
	for(int i = MAXL-1;i >= 0;i--)
		if(ancestral[u][i] != -1 && ancestral[u][i] != ancestral[v][i]){
			u = ancestral[u][i];
			v = ancestral[v][i];
		}
			
	return pai[u];
}

int main(){
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		int x;
		cin >> x;
		
		// isto é somente para definir os pares de cartas
		if(c[x]){
			par[i] = c[x];
			par[c[x]] = i;
		}
		c[x] = i;
	}
	
	for(int i = 1;i < n;i++){
		int a, b;
		cin >> a >> b;
		
		// montar a lista
		lista[a].push_back(b);
		lista[b].push_back(a);
	}
	
	// inicializações
	for(int i = 0;i < MAXN;i++) pai[i] = nivel[i] = -1;

	for(int i = 0;i < MAXN;i++)
		for(int j = 0;j < MAXL;j++)
			ancestral[i][j] = -1;
	
	// descobrir o pai e o nível de todo mundo
	nivel[1] = 0;
	dfs(1);
	
	// montar tabela de ancestral
	for(int i = 1;i <= n;i++) ancestral[i][0] = pai[i];
	
	for(int j = 1;j < MAXL;j++)
		for(int i = 1;i <=   n;i++)
			ancestral[i][j] = ancestral[ ancestral[i][j-1] ][j-1];
	
	// agora, sim, calcular a resposta
	long long resposta = 0LL;
	for(int i = 1;i <= n;i++)
		resposta += (long long)( nivel[i] + nivel[par[i]] - 2*nivel[ LCA(i, par[i]) ]);
	
	// dividimos por 2 porque calculamos cada distâncias duas vezes
	cout << resposta/2 << endl;
	
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

## Matemática

### MDC

```c++
int mdc(int a, int b){
  return (b == 0 ? a : mdc(b, a%b)); 
}
// mmc(a,b) = a*b / mdc(a,b)
```

### Distância ponto e reta

```c++
double dist(point a, line b){
  double crs = cross(point(a - b.first), point(b.second - b.first));
  return abs(crs/dist(b.first, b.second));
}
```

### Área polígono

```c++
double area(vector <point> p){
  double ret = 0;
  for(int i = 2; i < p.size(); ++i){
    ret += cross(p[i] - p[0], p[i - 1] - p[0])/2;
  }
  return abs(ret);
}
```

### CCW

```c++
double ccw(point a, point b, point c){
  double ret = cross(b - a, c - b);
  return ret < 0;
}
```

### Geometry - geral

```c++
/* 
 *     /|
 *    /A|
 *  c/  |b  
 *  /   |
 * /B__C|
 *   a
 * Lei dos Cossenos: a**2 = b**2 + c**2 - 2*b*c*cos(A)
 * Lei dos Senos: a/sin(A) = b/sin(B) = c/sin(C)
 *
 * */

ll gcd (ll a, ll b) {
	if (!b)
		return a;
	else
		return gcd(b, a%b);
}

double norm(double x) {
    if(x > 0)   return 1;
    if(x < 0)   return -1;
    return 0;
}

double sig_mul(double a, double b) {
    a = norm(a);
    b = norm(b);
    return a*b;
}

class Point {
public:
	double x, y;

	Point () { }

	Point (double x, double y) {
		this->x = x;
		this->y = y;
	}

	/**/
	bool operator == (const Point &b) const {
		return (abs (x - b.x) < EPS and abs (y - b.y) < EPS);
	}

	/**/
	bool operator < (const Point &b) const {
		return ((x < b.x) or ((x == b.x) and y < b.y));
	}

	//Produto vetorial
	// p^q = |p|*|q|*sin(ang)	ang: directed ang from p to q(-PI < ang <= PI)
	// p^q = 0 => ang = 0 or PI, p and q are colinear
	// p^q > 0 => 0 < ang < PI / p^q < 0 => -PI < ang < 0
	// p^q = directed area of paralelogram formed by vectors p and q
	// dist point p to line ab = ||ab^p|| / ||ab||
	double operator ^ (const Point &b) const {
		return (this->x * b.y) - (this->y * b.x); 
	}

	//Produto escalar
	// p*q = |p|*|q|*cos(ang)	ang: inner ang (0 <= ang < PI)
	// p*q = 0 => ang = 90 / p*q > 0 => ang < 90 / p*q < 0 => ang > 90
	// p*p = |p|^2  => |p| = sqrt(p*p)
	double operator * (const Point &b) const {
		return (this->x * b.x) + (this->y * b.y);
	}

	/**/
	Point operator * (double k) const {
		return Point (x*k, y*k);
	}

	Point operator / (double k) const {
		if (k == 0.0) cout << "Class Point (operador /): divisao por zero" << endl;
		return Point (x/k, y/k);
	}
	
	/**/
	Point operator + (const Point &b) const {
		return Point (x + b.x, y + b.y);
	}

	/**/
	Point operator - (const Point &b) const {
		return Point (x - b.x, y - b.y);
	}

	/**/
	double len () const {
		return sqrt (x*x + y*y);
	}

	double dpp2 (const Point &b) const {
		return ((*this)-b)*((*this)-b);
	}

	/*Distancia ponto a ponto*/
	double dpp (const Point &b) const {
		return ((*this)-b).len();
	}

	/*Oriented relative length of projection of this over b*/
	double relative_proj (Point &b) const {
		return ((*this)*b)/(b.len()*b.len());
	}

	Point norm () const {
		return Point (x/this->len(), y/this->len());
	}

	/*Retorna o vetor perpendicular ao vetor (0,0) -> (Point)
	Sentido clockwise*/
	Point perp () const {
		return Point (this->y, -1.0 * this->x);
	}

	// Distancia do ponto p ao segmento ab, tambem retorna por 
	// referencia o ponto (c) do segmento mais perto de p
	double distToSegment (const Point a, const Point b, Point &c) const {
		// formula: c = a + u * ab
		Point p = *this;
		if (a == b) return p.dpp(a);
		Point ap = Point(p - a), ab = Point(b - a);
		double u = ap.relative_proj(ab);
		if (u < 0.0) u = 0.0;
		if (u > 1.0) u = 1.0;
		c = a + ab * u;
		return p.dpp(c);
	}

	// Projection of this over v
	Point proj (const Point &v) const {
		return v*((*this)*v);
	}

	/**/
	Point rotaciona (double ang) const {
		double c = cos(ang), s = sin(ang);
		double X = x*c - y*s;
		double Y = x*s + y*c;
		return Point(X,Y);
	}

	/*area de um poligono concavo ou convexo
	dado vetor de vertices ordenados clockwise ou
	counter clockwise*/
	static double area (vector <Point> v) {
		double area = 0.0;
		for (int i = 0; i < (int)v.size(); i++) 
			area += v[i] ^ v[(i+1)%v.size()];
		return abs(area/2.0);
	}

	/* return counter clock points of convex hull
	 * WITHOUT COLINEAR POINTS*/
	static vector <Point> convex_hull (vector <Point> p) {
		if (p.size() <= 2) return p;

		int n = p.size(), k = 0;
		vector <Point> H(2*n);

		sort(p.begin(), p.end());

		for (int i = 0; i < n; i++) {
			while (k >= 2 and ((H[k-1]-H[k-2])^(p[i]-H[k-2])) <= 0.0) k--;
			H[k++] = p[i];
		}

		for (int i = n-2, t = k+1; i >= 0; i--) {
			while (k >= t and ((H[k-1]-H[k-2])^(p[i]-H[k-2])) <= 0.0) k--;
			H[k++] = p[i];
		}

		H.resize(k-1);

		return H;
	}
	
	/*Angulo em forma de fracao reduzida entre o vetor Op (p é o ponto)
	 e o eixo x, se paralelo ao eixo x retorna (1,0) ou (-1,0)
	 se paralelo ao eixo y retorna (0,1) ou (0,-1)
	 SÓ FUNCIONA PARA PONTOS INTEIROS*/ 
	static ii ang (Point p) {
		ll a = p.x, b = p.y;
		if (a == 0) return mk(0, b/abs(b));
		else if (b == 0) return mk(a/abs(a), 0);
		return mk(a/gcd(a,b), b/gcd(a,b));
	}

    // Check if segment ab intersects with cd, considera endpoints como dentro
	static bool inter (const Point &a, const Point &b, const Point &c, const Point &d) {
        Point ab = b-a;
        Point ac = c-a;
        Point ad = d-a;

        Point cd = d-c;
        Point ca = a-c;
        Point cb = b-c;

        // a, b, c, d -> Colineares
        // Se estiver desconsiderando endpoints nao precisa, essa parte +- testada
        if(abs(ab^ac) < EPS and abs(ab^ad) < EPS) {
            Point bc = c-b;
            Point bd = d-b;
            Point da = a-d;
            Point db = b-d;
            if((ac*ad) <= 0.0)  //< para descosiderar endpoints(soh igual a zero quando c=d)
                return true;
            if((bc*bd) <= 0.0)  //< para descosiderar endpoints(soh igual a zero quando c=d)
                return true;
            if((ca*cb) <= 0.0)  //< para descosiderar endpoints(soh igual a zero quando c=d)
                return true;
            if((da*db) <= 0.0)  //< para descosiderar endpoints(soh igual a zero quando c=d)
                return true;
            return false;
        }

        // >= para desconsiderar endpoints
        if(sig_mul(ab^ac, ab^ad) > 0.0)
            return false;

        // >= para desconsiderar endpoints
        if(sig_mul(cd^ca, cd^cb) > 0.0)
            return false;

        return true;
    }

	/*Interseccao de dois vetores somandos a pontos, returns t that p1 + v1*t = P_inter*/
	static double intersect (Point p1, Point v1, Point p2, Point v2) {
		if (abs(v2 ^ v1) >= EPS) {
			Point c = p1 - p2;
			return (c ^ v2)/(v2 ^v1);
		} else {
			cout << "Class Point (funcao inter): retas paralelas" << endl;
			cout << "Talvez deva ajustar o EPS" << endl;
		}
		return 0.0;
	}

	/* Retorna se point p esta dentro do poligono convexo v, pontos de v estao
	 * em counter clockwise
	 * Considera borda como fora
	 * O(log2(v.size()))*/
	static bool inside(const vector<Point> &v, const Point &p) {
		// V DEVE ESTAR EM COUNTER CLOCKWISE
		int n = v.size();

		if(n < 3)
			return false;
	
		// Considerar borda como dentro: mudar para <
		if(((v[1]-v[0])^(p-v[0])) <= 0)
			return false;

		int bot = 2, top = n-1;
		int ans = -1;
		while(bot <= top) {
			int mid = (bot+top)>>1;

			// Considerar borda como dentro: mudar para <=
			if(((v[mid]-v[0])^(p-v[0])) < 0) {
				ans = mid;
				top = mid-1;
			} else {
				bot = mid+1;
			}
		}

		if(ans == -1)
			return false;

		// Considerar borda como dentro: mudar para <
		if(((v[ans]-v[ans-1])^(p-v[ans-1])) <= 0)
			return false;

		return true;
	}

	/*Retorna o retangulo (pontos em anti clockwise) que tem a menor valor
	min(Xmax -Xmin, Ymax - Ymin)*/
	static vector <Point> minRetangulo (vector <Point> v) {
		vector <Point> at;
		at.pb(Point(-1e18, -1e18));
		at.pb(Point(1e18, -1e18));
		at.pb(Point(1e18, 1e18));
		at.pb(Point(-1e18, 1e18));
		v = convex_hull(v);
		int n = v.size();
		for (int i = 0; i < n; i++) {
			int j = (i+1)%n;
			Point vec = v[j] - v[i];
			double ang = atan2(vec.y, vec.x);
			vector <Point> ve;
			for (int j = 0; j < n; j++) {
				ve.pb(v[j].rotaciona(ang));
			}
			double minx = DBL_MAX, miny = DBL_MAX, maxx = -DBL_MAX, maxy = -DBL_MAX;
			for (int j = 0; j < n; j++) {
				if (ve[j].x < minx) minx = ve[j].x;
				if (ve[j].x > maxx) maxx = ve[j].x;
				if (ve[j].y < miny) miny = ve[j].y;
				if (ve[j].y > maxy) maxy = ve[j].y;
			}
			double mini = min(maxx - minx, maxy - miny);
			if (mini < min(at[2].x - at[0].x, at[2].y - at[0].y)) {
				at.clear();
				at.pb(Point(minx, miny));
				at.pb(Point(maxx, miny));
				at.pb(Point(maxx, maxy));
				at.pb(Point(minx, maxy));
			}
		}

		return at;
	}

	// distance of 2 farthest points. O(n) + O(convex_hull)
	// Rotating Calipers
	static double max_dist (vector <Point> p) {
		double ret = 0;
		p = Point::convex_hull(p);

		int n = p.size();
		if (n <= 1)
			return 0;
		if (n == 2)
			return p[0].dpp(p[1]);

		int at = 1;
		for (int i = 0; i < n; i++) {
			int j = (i + 1)%n;

			Point v = p[j] - p[i];
			int nxt = (at + 1)%n;
			while (nxt != i and (v^(p[nxt]-p[i])) >= (v^(p[at]-p[i]))) {
				at = nxt;
				nxt = (at + 1)%n;
			}

			ret = max (ret, max (p[i].dpp(p[at]), p[j].dpp(p[at])));
		}

		return ret;
	}

//	** MIN DIST BEGIN	O(N*LOG2(N))	N = number of points
	static bool compy (const Point &a, const Point &b) {
		if (a.y != b.y)	return a.y < b.y;
		return a.x < b.x;
	}

	static void min_dist (const Point &p, const vector <Point> &v, int i, double &d) {
		while (i < (int)v.size() and v[i].y - p.y < d) {
			d = min (d, p.dpp(v[i]));
			i++;
		}
	}

	// divide and conquer
	static vector <Point> min_dist (const vector <Point> &p, int l, int r, double &d) {
		vector <Point> ret;
		if (l == r)	{
			ret.pb(p[l]);
			return ret;
		}
		int mid = (l + r)>>1;

		vector <Point> L = min_dist (p, l, mid, d);
		vector <Point> R = min_dist (p, mid + 1, r, d);

		vector <Point> vl, vr;
		for (auto it : L) 
			if (p[mid].x - it.x < d)
				vl.pb(it);

		for (auto it : R) 
			if (it.x - p[mid + 1].x < d)
				vr.pb(it);

		int i = 0, j = 0;

		while (i < (int)vl.size() and j < (int)vr.size()) {
			if (vl[i].y < vr[j].y) {
				min_dist (vl[i], vr, j, d);
				i++;
			} else {
				min_dist (vr[j], vl, i, d);
				j++;
			}
		}

		ret.resize(r - l + 1);
		merge (L.begin(), L.end(), R.begin(), R.end(),
				ret.begin(), compy);
		return ret;
	}

	// PUBLIC
	static double min_dist (vector <Point> p) {
		if (p.size() <= 1)	return 0.0;
		sort (p.begin(), p.end());

		double dist = p[0].dpp(p[1]);
		min_dist (p, 0, p.size() - 1, dist);
		return dist;
	}
//	** MIN DIST END

//	** MAX A*X + B*Y	BEGIN
	// ternary search
	static double max_ab (const vector <Point> &p, int bot, int top, const Point &ab) {
		if (bot > top)	return -1e18;
		double ret = max (ab*p[bot], ab*p[top]);
		top--;

		while (bot <= top) {
			int mid = (bot + top)>>1;

			ret = max (ret, max(p[mid]*ab, p[mid+1]*ab));

			if (p[mid]*ab > p[mid+1]*ab) {
				top = mid - 1;
			} else {
				bot = mid + 1;
			}
		}

		return ret;
	}

	static double max_ab (const vector <Point> &p, const Point &ab) {
		int n = p.size();

		if (n < 10) {
			double ret = ab*p[0];
			for (int i = 1; i <= n; i++)
				ret = max(ret, ab*p[i]);
			return ret;
		}

		Point perp = ab.perp();

		int split = 0;
		int bot = 0, top = n - 1;

		double dir = perp^(p[1]-p[0]);
		if (!dir) {
			bot = 1;
			dir = perp^(p[2]-p[0]);
		}

		if (dir > 0)
			dir = 1;
		else 
			dir = -1;

		// normal divides the convex hull, to get 2 ranges where ternary search is possible
		while (bot <= top) {
			int mid = (bot + top)>>1;

			if ((perp^(p[mid]-p[0])) * dir > 0) {
				bot = mid + 1;
				split = mid;
			} else {
				top = mid - 1;
			}
		}

		return max (max_ab(p, 0, split, ab), max_ab(p, split + 1, n, ab));
	}

	// PUBLIC
	// O(convex_hull(p)) + ab.size()*log2(p.size())
	static vector <double> max_ab (vector <Point> p, const vector <Point> &ab) {
		// convex_hull WITHOUT COLINEAR POINTS
		p = Point::convex_hull(p);
		vector <double> ans(ab.size());

		int n = ab.size();
		for (int i = 0; i < n; i++) 
			ans[i] = max_ab(p, ab[i]);

		return ans;
	}
//	** MAX A*X + B*Y	END

    /*
    Teorema de Pick:
    Um polígono construído sobre uma grade de pontos equidistantes.
    Dado um polígono simples construído sobre uma grade de pontos equidistantes 
    (i.e., pontos com coordenadas inteiras) 
    de tal forma que todos os vértices do polígono sejam pontos da grade, o teorema de
    Pick fornece uma fórmula simples 
    para o cálculo da área A desse polígono em termos do número i de pontos interiores
    localizados no polígono, 
    e o número b de pontos fronteiriços localizados no perímetro do polígono:
        A = i + b/2 - 1
        i = A - b/2 + 1
    Os pontos devem ser inteiros
    */
	static ll pick_theorem(const vector<Point> &p) {
        int n = p.size();
        ll A = 0, b = 0;

        for(int i = 0; i < n; i++) {
            int j = (i+1)%n;
            A += p[i]^p[j];

			ll xx = abs(p[j].x - p[i].x);
			ll yy = abs(p[j].y - p[i].y);

            b += gcd(xx, yy);
        }

        if(A < 0)   A *= -1;
        A>>=1;

        ll ans = A - (b>>1) + 1;
        return ans;
	}
};

ostream &operator<<(ostream &os, Point const &p) {
	return os << p.x << " " << p.y;
}

class Circle {
public:
	Point c;
	double r;

	Circle () {}

	Circle (const Point &c, double r) : c(c), r(r) {}

	/*Interseccao de dois circulos
	OBS: se ha infinitas interseccoes retorna o vetor vazio
	OBS: se existe só um ponto retorna 2 pontos iguais*/
	vector <Point> intersect (Circle b) {
		vector <Point> ret;
		Point c1 = this->c, c2 = b.c;
		double r1 = this->r, r2 = b.r;

		if (c1 == c2) return ret;

		double d = c1.dpp(c2);
		
		if (d > r1 + r2 + EPS) return ret;
		if (d + EPS < abs(r1 - r2)) return ret;

		double a = (r1*r1 - r2*r2 + d*d)/(2.0*d);
		double h = sqrt(max(0.0, r1*r1 - a*a));

		Point pc = c1 + ((c2 - c1)*a)/d;

		/*X EH MENOS E Y EH MAIS*/
		double x = pc.x - ((h*(c2.y - c1.y))/d);
		double y = pc.y + ((h*(c2.x - c1.x))/d);
		ret.pb(Point(x,y));

		x = pc.x + ((h*(c2.y - c1.y))/d);
		y = pc.y - ((h*(c2.x - c1.x))/d);
		ret.pb(Point(x,y));

		return ret;
	}

	// Circumcircle of a triangle, TAKE CARE WITH 3 COLINEAR POINTS
	static Circle circumcircle (const Point &a, const Point &b, const Point &c) {
		Point ab = b - a, bc = c - b;
		Point mab = a + ab * 0.5;
		Point mbc = b + bc * 0.5;

		double a1 = ab.x, b1 = ab.y;
		double c1 = -a1 * mab.x - b1 * mab.y;
		
		double a2 = bc.x, b2 = bc.y;
		double c2 = -a2 * mbc.x - b2 * mbc.y;
		
		double den = a1 * b2 - a2 * b1;

		double x = (-c1 * b2 + b1 * c2)/den;
		double y = (-c2 * a1 + a2 * c1)/den;
		
		Point center(x, y);
		return Circle(center, (a-center).len());
	}

	// Randomize O(p.size())
	// Return circle that covers all point in p with minimum radius
	// Idea: if some point pt is outside of current circle, make new circle with previous 
    // 		 points
	// in circle, this circle will have point pt on the border
	// With 3 points on the border its easy to get the circle (Circumcicle)
	static Circle cover (vector <Point> p, vector <Point> border = vector <Point>()) {
		random_shuffle(p.begin(), p.end());

		Circle res;
		if (border.size() == 0) 
			res = Circle(p[0], 0.0);
		else if (border.size() == 1) 
			res = Circle(border[0], 0.0);
		else if (border.size() == 2)
			res = Circle((border[0] + border[1])*0.5, (border[0].dpp(border[1]))/2.0);
		else 
			return circumcircle (border[0], border[1], border[2]);

		vector <Point> p2;
		for (auto pt : p) {
			if (res.c.dpp(pt) > res.r) {
				border.pb(pt);
				res = cover (p2, border);
				border.pop_back();
			}
			p2.pb(pt);
		}

		return res;
	}
};

/* Get area of a nondegenerate triangle, with sides a, b, c */
double getAreaTriangle (double a, double b, double c) {
	double p = (a + b + c)/2.0;
	return sqrt (p * (p - a) * (p - b) * (p - c));
}
```

## Outros

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

### Tabela ASCII

![Imgur](https://i.imgur.com/tsyZFvh.png)

### Séries

![Imgur](https://i.imgur.com/BtYUYKn.png)



