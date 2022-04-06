// Heavy-Light Decomposition
//
// 2acdda
class HLD {
public:
	void init(int n) {
		p.resize(n);
		h.resize(n);
		in.resize(n);
		sz.resize(n);
		adj.resize(n);
		head.resize(n);
	}

	void addEdge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	void build(int root = 0) {
		t = 0;
		head[root] = p[root] = root;
		buildChains(root, root);
		buildHld(root, root);
	}

private:
	vector<int> p, h, in, sz, head;
	vector<vector<int>> adj;
	int t;

	void buildChains(int on, int par) {
		sz[on] = 1;
		p[on] = par;
		for (auto &to : adj[on]) {
			if (to == par) {
				swap(to, adj[on].back());
				continue;
			}
			h[to] = h[on] + 1;
			buildChains(to, on);
			sz[on] += sz[to];
			if (sz[to] > sz[adj[on][0]]) {
				swap(to, adj[on][0]);
			}
		}
	}

	void buildHld(int on, int par) {
		in[on] = t++;
		for (auto to : adj[on]) {
			head[to] = (to == adj[on][0] ? head[on] : to);
			buildHld(to, on);
		}
	}
};