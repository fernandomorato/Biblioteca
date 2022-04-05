// based on: https://github.com/tfg50/Competitive-Programming/blob/master/Biblioteca/Strings/Aho.cpp
template <const int ALPHA = 26, class T = string, const int OFFSET = 'a'>
struct Aho {
	struct Node {
		int nxt[ALPHA];
		int size;
		int link, elink;
		bool end;

		Node() {
			for (int i = 0; i < ALPHA; i++) {
				nxt[i] = 0;
			}
			size = 0;
			link = elink = 0;
			end = false;
			// initialize new stuff here
		}
		// add new stuff here
	};

	vector<Node> nodes;

	Aho() {
		nodes.push_back(Node());
	}

	template <class F>
	void goUp(int on, F f) {
		for (on = nodes[on].end ? on : nodes[on].elink; on > 0; on = nodes[on].elink) {
			f(nodes[on]);
		}
	}

	template <class C>
	int nextState(int on, C c) const {
		return nodes[on].nxt[c - OFFSET];
	}

	int add(const T &s) {
		int cur = 0;
		for (auto ch : s) {
			if (nodes[cur].nxt[ch - OFFSET] == 0) {
				nodes[cur].nxt[ch - OFFSET] = (int) nodes.size();
				nodes.push_back(Node());
				nodes.back().size = nodes[cur].size + 1;
			}
			cur = nodes[cur].nxt[ch - OFFSET];
		}
		// mark this node as the end of a word
		nodes[cur].end = true;
		return cur;
	}

	void build() {
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			nodes[cur].elink = (nodes[nodes[cur].link].end ? nodes[cur].link : nodes[nodes[cur].link].elink);
			for (int i = 0; i < ALPHA; i++) {
				int &nxt = nodes[cur].nxt[i];
				if (nxt) {
					nodes[nxt].link = (cur == 0 ? 0 : nodes[nodes[cur].link].nxt[i]);
					q.push(nxt);
				} else {
					nxt = nodes[nodes[cur].link].nxt[i];
				}
			}
		}
	}
};