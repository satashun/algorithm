//g(S) = Σ[S⊆T]f(T)
rep(i, n) rep(j, 1 << n) if(!(j & 1 << i)) f[j] += f[j | (1 << i)];

//g(S) = Σ[T⊆S]f(T)
rep(i, n) rep(j, 1 << n) if (j & (1 << i)) f[j] += f[j ^ (1<<i)];

//mobius f(S) = Σ[T⊆S](-1)^|S - T| g(T) 
rep(i, n) rep(j, 1 << n) if(j & 1 << i) f[j] -= f[j ^ 1 << i];

//including mask
for (int i = mask; i < (1 << n); i = ((i+1) | mask)) ;

//subset of mask 
for (int i = mask; i >= 0; --i) {
	i &= mask;
}