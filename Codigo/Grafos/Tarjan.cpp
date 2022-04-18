// Tarjan - SCC
//
// Algoritmo de Tarjan para compenentes fortemente conexos (SCC)
// O Hash nao conta com os vetores
//
// 7332da

vector<int> adj[MAXN], comp[MAXN], stk;
int vis[MAXN], tin[MAXN];

void dfs(int on, int &t) {
	stk.push_back(on);
	int low = tin[on] = ++t;
	vis[on] = 1;
	for (int to : adj[on]) {
		if (vis[to] == 1) {
			low = min(low, tin[to]);
		} else if (!vis[to]) {
			low = min(low, dfs(to, t));
		}
	}	
	if (low == tin[on]) {
		while (1){
			int v = stk.back();
			stk.pop_back();
			vis[v] = 2;
			comp[on].push_back(v);
			if (v == on) break;
		}
	}
	return low;
}

void build_scc(int n) {
	int t = 0;
	for (int i = 0; i < n; i++) {
		tin[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i]) dfs(i, t);
	}
}