# TH XSTK Bai 3: Bien ngau nhien (Tuan 3-4)

# Vi du 1 a
# Tao vec to k có gia tri tu 0 den 8
k = 0:8
# Viet ham xac suat
p <- function(k) choose(8,k) * 0.3^k * 0.7^(8-k)
# Tinh gia tri xac suat P(X = k), k = 0,1,...,8
p(k)



# Vi du 1 b
# Viet ham mat do cua bien ngau nhien X ~ N(mu = 0,sigma^2 = 1)
f <- function(x, mu=0, sigma=1){
  1/sqrt(2*pi*sigma^2) * exp(-(x-mu)^2/(2*sigma^2))
}

# Tinh f(0)
f(0)



# Vi du 2 a
# Ve ham xac suat o vi du 1a
plot(k, p(k), type = "h", xlab = "k", ylab = "P(X = k)", main = "Ham xac suat cua bnn X")



# Vi du 2 b
# Ve ham mat do xac suat o vi du 1b
curve(f(x,0,1),from=-3,to=3, xlab = "x", ylab = "fX(x)", main = "Ham mat do cua bnn X")



# Vi du 3 a
# Viet ham pp xac suat FX
F <- function(k) sum(p(0:k))
# Vecto hoa ham FX
F <- Vectorize(F)
# Tinh F(4)
F(4)


# Vi du 3 b
# Viet ham pp xac suat
F2 <- function(a,mu = 0, sigma = 1){
  integrate(function(x) f(x,mu,sigma), lower = -Inf, upper =a)$value
}
# Vecto hoa ham 
F2 = Vectorize(F2)
F2(1.96)


# Vi du 4 a
plot(stepfun(k, c(0, F(k))), ylab = "FX(x)", main = "cdf of X")


# Vi du 4 b
curve(F2(x), from = -3, to = 3, ylab = "FX(x)", main = "cdf of X")


# Vi du 5 a
K = k[F(k) >= 0.25]
K[1]

# kiem tra lai
F(0)
F(1)


# Vi du 5 b
uniroot(function(x) F2(x)-0.975, c(-3,3))$root

# kiem tra lai
F2(1.96)
