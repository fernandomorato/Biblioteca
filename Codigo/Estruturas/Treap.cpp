// Treap Implicita
//
// 2f6de4
namespace treap {
	// mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

	struct node {
		node *l, *r;
		int value;
		int prior, sz;
		bool rev;

		node (int _v): value(_v) {
			sz = 1;
			prior = rng();
			rev = false;
			l = r = NULL;
		}
	};

	inline int getSize(node *nd) {
		return (nd ? nd->sz : 0);
	}

	inline void update(node *&nd) {
		nd->sz = getSize(nd->l) + getSize(nd->r) + 1;
	}

	void push(node *nd) {
		if (nd && nd->rev) {
			nd->rev = false;
			swap(nd->l, nd->r);
			if (nd->l) {
				nd->l->rev ^= true;
			}
			if (nd->r) {
				nd->r->rev ^= true;
			}
		}
	}

	void merge(node *&root, node *l, node *r) {
		push(l), push(r);
		if (!l || !r) {
			root = (l ? l : r);
		} else {
			if (l->prior > r->prior) {
				merge(l->r, l->r, r);
				root = l;
			} else {
				merge(r->l, l, r->l);
				root = r;
			}
			update(root);
		}
	}

	void split(node *root, node *&l, node *&r, int pos) {
		if (!root) {
			l = r = NULL;
		} else {
			push(root);
			int p = getSize(root->l) + 1;
			if (p <= pos) {
				split(root->r, root->r, r, pos - p);
				l = root;
			} else {
				split(root->l, l, root->l, pos);
				r = root;
			}
			update(root);
		}
	}

	void insert(node *&root, int value, int pos) {
		node *l = NULL, *r = NULL, *aux = new node(value);
		split(root, l, r, pos);
		merge(l, l, aux);
		merge(root, l, r);
	}

	void reverse(node *&root, int ll, int rr) {
		// reverses interval [ll, rr]
		node *l = NULL, *r = NULL, *k = NULL;
		split(root, l, r, ll - 1);
		split(r, k, r, rr - ll + 1);
		k->rev ^= true;
		merge(r, k, r);
		merge(root, l, r);
	}

	void shift(node *&root, int ll, int rr) {
		// right-cyclic-shift on interval [ll, rr]
		node *l = NULL, *r = NULL, *k = NULL, *t = NULL;
		split(root, l, r, ll - 1);
		split(r, k, r, rr - ll + 1);
		split(k, k, t, rr - ll);
		merge(k, t, k);
		merge(r, k, r);
		merge(root, l, r);
	}

	int query(node *&root, int pos) {
		// returns which node is at position "pos"
		node *l = NULL, *r = NULL, *k = NULL;
		split(root, l, r, pos);
		split(l, l, k, pos - 1);
		int ans = k->value;
		merge(l, l, k);
		merge(root, l, r);
		return ans;
	}
}
