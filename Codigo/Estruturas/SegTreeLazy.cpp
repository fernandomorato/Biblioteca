struct Lazy {
	// atributes

	Lazy() {
		// constructor
	}

	void reset() {

	}

	void operator += (Lazy o) {
		// merge
	}
};

struct Node {
	// atributes

	Node() {
		// empty node
	}

	Node() {
		// constructor
	}
 
	Node(const Node &l, const Node &r) {
		// merge
	}

	void apply(Lazy lazy) {

	}
};

// may be changed to iterative
template <class node_t, class e_t, class lazy_t = int>
class SegTree {
public:
	void init(vector<e_t> &_v) {
		v = _v;
		n = (int) v.size();
		tree.resize(4 * n + 1);
		lazy.resize(4 * n + 1);
		dirty.assign(4 * n + 1, false);
		build(1, 0, n - 1);
	}

	void update(int node, int l, int r, int ql, int qr, lazy_t x) {
		push(node, l, r);
		if (ql > r || l > qr)
			return;
		if (ql <= l && r <= qr) {
			apply(node, l, r, x);
			push(node, l, r);
			return;
		}
		int m = (l + r) / 2;
		update(2 * node, l, m, ql, qr, x);
		update(2 * node + 1, m + 1, r, ql, qr, x);
		tree[node] = node_t(tree[2 * node], tree[2 * node + 1]);
	}

	node_t query(int node, int l, int r, int ql, int qr) {
		push(node, l, r);
		if (ql > r || l > qr)
			return node_t();
		if (ql <= l && r <= qr)
			return tree[node];
		int m = (l + r) / 2;
		return node_t(query(2 * node, l, m, ql, qr), query(2 * node + 1, m + 1, r, ql, qr));
	}
private:
	int n;
	std::vector<e_t> v;
	std::vector<bool> dirty;
	std::vector<node_t> tree;
	std::vector<lazy_t> lazy;

	void apply(int node, int l, int r, Lazy &lz) {
		tree[node].apply(lz);
		if (l != r) {
			dirty[node] = true;
			lazy[node] += lz;
		}
	}

	void push(int node, int l, int r) {
		if (dirty[node]) {
			int m = (l + r) / 2;
			apply(2 * node, l, m, lazy[node]);
			apply(2 * node + 1, m + 1, r, lazy[node]);
			lazy[node].reset();
			dirty[node] = false;
		}
	}

	void build(int node, int l, int r) {
		if (l == r)  {
			tree[node] = node_t(v[l]);
		} else {
			int m = (l + r) / 2;
			build(2 * node, l, m);
			build(2 * node + 1, m + 1, r);
			tree[node] = node_t(tree[2 * node], tree[2 * node + 1]);
		}
	}
};