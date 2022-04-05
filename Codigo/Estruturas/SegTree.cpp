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
};

template <class node_t, class e_t>
class SegTree {
public:
	void init(vector<e_t> &v) {
		n = (int) v.size();
		tree.resize(2 * n);
		for (int i = 0; i < n; i++) {
			tree[i + n] = node_t(v[i]);
		}
		for (int i = n - 1; i > 0; i--) {
			tree[i] = node_t(tree[2 * i], tree[2 * i + 1]);
		}
	}

	void update(int p, e_t x) {
		p += n;
		tree[p] = node_t(x);
		for (p /= 2; p > 0; p /= 2) {
			tree[p] = node_t(tree[2 * p], tree[2 * p + 1]);
		}
	}

	node_t query(int l, int r) {
		node_t ln, rn;
		for (l += n, r += n; l < r; l /= 2, r /= 2) {
			if (l & 1) ln = node_t(ln, tree[l++]);
			if (r & 1) rn = node_t(tree[--r], rn);
		}
		return node_t(ln, rn);
	}

private:
	int n;
	std::vector<node_t> tree;
};