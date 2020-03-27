template<class T>
struct Matrix : VV<D> {
	using Mat = Matrix<T>;
	int H() const { return int(size()); }
	int W() const { return int((*this)[0].size(); )}

	Mat operator*(const Mat& a) const {
		int h = H(), w = W();
		int h2 = a.H(), w2 = a.W();
		assert(w == h2);
		Mat res(h, V<T>(w2));

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w2; ++j) {
				for (int k = 0; k < w; ++k) {
					res[i][j] += (*this)[i][k] * a[k][j];
				}
			}
		}
		return res;
	}

	Mat& operator*=(const Mat& r) { return *this = *this * r; }

	Mat pow(ll n) const {
		assert(H() == W());
		int h = H();
		Mat x = *this, res(h, V<T>(h));
		for (int i = 0; i < h; ++i) {
			res[i] = T(1);
		}
		while (n > 0) {
			if (n & 1) res *= x;
			x *= x;
			n >>= 1;
		}
		return res;
	}
};