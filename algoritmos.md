# Algoritmos

## Estruturas de dados

### Union-Find

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

## Técnicas de programação

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

