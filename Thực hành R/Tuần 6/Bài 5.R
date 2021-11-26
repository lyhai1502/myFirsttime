# Bai1. Mau ngau nhien phan phoi chuan

# Mo phong 1: Cho X1,..Xn ~ N(mu, sigma). Khi do X.bar ~ N(mu, sigma^2/n)
# Gan cac gia tri
n = 10; mu = 2; sigma = 2

# Tao vecto X = (X1,...Xn) ~ N(mu, sigma)
VecX <- function(n) rnorm(n,mu, sigma)

# Tinh gia tri trung binh mau
MeanX <- function() mean(VecX(n))

# Lap lai qua tri tren them m lan
SampleMeanX <- function(m) replicate(m, MeanX())

# Ve bieu do tan do cho du lieu vua tao
hist(SampleMeanX(1000), freq = 0, breaks = 40)

# Kiem tra lai bang cahc ve ham mat do pp N(mu, sigma^2/n)
curve(dnorm(x,mu,sigma/sqrt(n)), col = "blue", lty = 1, lwd = 2, add = T)

# Mo phong 1.2: Cho X1,....Xn ~ N(mu, sigma)
# Khi do (n-1)*S*^2/sigma^2 ~ X^2(n-1)

# Tinh gia tri bien S = (n-1)*var(VecX(n))/sigma^2
S <- function() (n-1)*var(VecX(n))/sigma^2

# Lap lai qua trinh tren m lan
SampleS <- function(m) replicate(m, S())

# Ve bieu do tan so cho du lieu vua ta
hist(SampleS(10000), freq = F, breaks = 40)

# Ve ham mat do cua pp X^2(n-1)
curve(dchisq(x,n-1), col = "red", lty = 1, lwd = 1, add = T)

# -------------------- PHAN BAI TAP ----------------------------
# Bai 1
# Viet ham tao MauY
mau=0; sigma=1
MauY <- function(){
	X1 <- rnorm(1,mau,sigma)
	X2 <- rnorm(1,mau,sigma)
	Y = (X1)^2 + (X2)^2
}
Y <- function(n) replicate(n, MauY())
draw <- function(m){
	#Ve bieu do tan suat
	hist(Y(m), freq = F, breaks = 40)
	#Ve ham mat do cua pp Chi binh phuong voi 2 bac tu do vao cung 1 bieu do (add = TRUE)
	curve(dchisq(x,2), col = "blue", lty = 1, lwd = 2, add = TRUE)
}
par(mfrow = c(1,3))
draw(100)
draw(1000)
draw(10000)

