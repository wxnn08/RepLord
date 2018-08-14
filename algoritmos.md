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

