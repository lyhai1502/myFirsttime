# Ham xac suat nhi thuc bien roi rac
# Dung lenh co san: X ~ B(n=8, p=0.3)
dbinom(0:8, 8, 0.3)

# Ham mat do cua bien ngau nhien
# Dung lenh co san: X ~ N(mu = 0, sigma^2 = 1)
dnorm(0,0,1) #dnorm(0)

# Chia cua so do thi thanh 2 dong 1 cot
par(mfrow = c(2,1))
#lenh chia cua so do thi:	par(mfrow=c(n,m)): Dien t->p, t!d
#par(mfcol=c(n,m)) t!d,t->p

# Ve do thi ham xs o vidu 1a
# Dung lenh co san: X ~ B(n=8, p=0.3)
plot(0:8, dbinom(0:8,8,0.3), type = "h", xlab ="k", ylab = "P(X = k)", main = "Ham xac suat cua bnn X") 

# Ve do thi ham mat do xs o vidu 1b
# Dung lenh co san:
curve(dnorm(x,0,1),from=-3,to=3, xlab = "x", ylab = "dnorm(x)", main = "Ham mat do cua bnn X")

# 3a.Ham phan phoi xac suat FX
# Dung lenh co san: X ~ B(n=8, p=0.3)
pbinom(4,8,0.3)
pbinom(0:8,8,0.3)

# 3b. Ham pp xac suat
# Dung lenh co san: X ~ N(mu = 0, sigma^2 = 1)
pnorm(1.96, 0,1)
pnorm(1.96)

# 4a. Ve ham ppxs vd 1a
# Dung lenh co san: X ~ B(n=8, p=0.3)
plot(stepfun(0:8, c(0, pbinom(0:8,8,0.3))), ylab = "FX(x)", main = "cdf of X")