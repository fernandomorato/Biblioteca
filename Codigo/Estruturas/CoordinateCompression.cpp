template <typename T>
class CoordinateCompression {
public:
	CoordinateCompression(const std::vector<T> &_v) {
		v = _v;
		std::sort(v.begin(), v.end());
		v.resize(std::unique(v.begin(), v.end()) - v.begin());
	}

	int size() { return (int) v.size(); }

	int operator() (T x) {
		return (int) (std::lower_bound(v.begin(), v.end(), x) - v.begin());
	}
private:
	std::vector<T> v;
};