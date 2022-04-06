// Division Trick
//
// by tfg
// found at: https://github.com/tfg50/Competitive-Programming/blob/master/Biblioteca/Math/DivisionTrick.cpp
// O(sqrt(n))
for(int l = 1, r; l <= n; l = r + 1) {
	r = n / (n / l);
	// n / i has the same value for l <= i <= r
}