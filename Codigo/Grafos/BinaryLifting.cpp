// Binary Lifting
//
// 1e18d0
namespace BinaryLifting {
	const int MAXN = 2e5 + 5;
	const int LOG = 20;

	int h[MAXN];
	int anc[LOG][MAXN];

	void dfs(vector<vector<int>> &adj, int on, int par, int lvl = 0) {
		h[on] = lvl;
		anc[0][on] = par;
		for (int to : adj[on]) {
			if (to != par) {
				dfs(adj, to, on, lvl + 1);
			}
		}
	}

	void init(vector<vector<int>> &adj, int start = 0) {
		dfs(adj, start, start);
		for (int i = 1; i < LOG; i++) {
			for (int j = 0; j < (int) adj.size(); j++) {
				anc[i][j] = anc[i - 1][anc[i - 1][j]];
			}
		}
	}

	void up(int &x, int d) {
		for (int i = 0; i < LOG; i++) {
			if (d & (1 << i))
				x = anc[i][x];
		}
	}

	int getLCA(int a, int b) {
		if (h[a] > h[b]) {
			swap(a, b);
		}
		up(b, h[b] - h[a]);
		if (a == b) {
			return a;
		}
		for (int i = LOG - 1; i >= 0; i--) {
			if (anc[i][a] != anc[i][b]) {
				a = anc[i][a];
				b = anc[i][b];
			}
		}
		return anc[0][a];
	}

	int dist(int a, int b) {
		return h[a] + h[b] - 2 * h[getLCA(a, b)];
	}
}