//x_i=floor((a*i+b)/c), i=0,1,..n-1
//a,c>0, b>=0
//http://mathforum.org/library/drmath/view/73120.html
//https://min-25.hatenablog.com/entry/2018/04/27/225535

ll gauss_sum(ll n, ll a, ll b, ll c) {
	if (n == 0) return 0;
	ll res = 0;
	{
		ll p = a / c;
		res += n * (n-1) / 2 * p;
		a %= c;
	}
	{
		ll p = b / c;
		res += n * p;
		b %= c;
	}
	if (a == 0) return res;
	ll top = (a * (n-1) + b) / c;
	res += top * n;
	ll h = 1;
	if (h <= top) {
		res -= gauss_sum(top - h + 1, c, c * h - (b + 1), a) + top - h + 1;
	}
	return res;
}