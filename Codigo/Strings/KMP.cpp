// KMP - Knuth Morris Pratt
//
// ce4156
template <class T>
vector<int> prefixFunction(const T &v) {
	vector<int> p((int) v.size(), 0);
	for (int i = 1; i < (int) v.size(); i++) {
		p[i] = p[i - 1];
		while (p[i] > 0 && v[p[i]] != v[i]) p[i] = p[p[i] - 1];
		if (v[p[i]] == v[i]) p[i]++;
	}
	return p;
}

// Assumes that there is a '#' at the end of pattern
template <class T, class F>
void match(const T &txt, const T &pat, const vector<int> &p, F f) {
	for (int i = 0, k = 0; i < (int) txt.size(); i++) {
		while (k > 0 && pat[k] != txt[i]) k = p[k - 1];
		if (pat[k] == txt[i]) k++;
		if (k + 1 == (int) pat.size()) {
			// a match was found!
			f(i - k + 1, i);
		}
	}
}