vector<PT> convexHull(vector<PT> &p, bool sorted = false) {
	int n = (int) p.size(), k = 0;
	if (!sorted) // may change this later, since p is a reference
		sort(p.begin(), p.end());
	vector<PT> h(2 * n);
	for (int i = 0; i < n; i++) {
		while (k >= 2 && (p[i] - h[k - 2]) % (h[k - 1] - h[k - 2]) > 0)
			k--;
		h[k++] = p[i];
	}
	for (int i = n - 2, t = k + 1; i >= 0; i--) {
		while (k >= t && (p[i] - h[k - 2]) % (h[k - 1] - h[k - 2]) > 0)
			k--;
		h[k++] = p[i];
	}
	reverse(h.begin(), h.begin() + k);
	h.resize(k - 1);
	return h;
}