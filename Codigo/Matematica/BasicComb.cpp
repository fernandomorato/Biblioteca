// Combinatoria
//
// fe3faa

// remember to change BOUNDS accordingly!!!

using T = Mint<>;

T fat[MAXN], ifat[MAXN];

long long inv(long long a, long long b) {
	return a > 1 ? b - inv(b % a, a) * b / a : 1;
}

void setup() {
	fat[0] = ifat[0] = 1;
	for (int i = 1; i < MAXN; i++) {
		fat[i] = fat[i - 1] * i;
	}
	ifat[MAXN - 1] = inv(fat[MAXN - 1], MOD);
	for (int i = MAXN - 2; i >= 1; i--) {
		ifat[i] = ifat[i + 1] * (i + 1);
	}
}

// C(n, k) = n choose k, number of ways to choose a set of k elements from a set of n elements
T C(int n, int k) {
	if (n < k || k < 0)
		return T(0);
	return fat[n] * ifat[k] * ifat[n - k];
}

// C(n) = n-th Catalan number - number of valid parenthesis sequences of size 2 * n
T C(int n) {
	return C(2 * n, n) - C(2 * n, n + 1);
}