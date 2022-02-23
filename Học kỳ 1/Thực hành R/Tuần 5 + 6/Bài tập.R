# Bai 1: Pp sieu boi : X ~ H(N,M,n)
# Trong R: X ~ (M, N-M, k=n)
# Nhap gia tri cac tham so
x <- 0:15
m =25; n=100-25; k = 15
dhyper(x, m, n, k)
#Ve bieu do cot ham xs cua X ~ H(M, N-M, k=n)
barplot(dhyper(x,m,n,k))

# Bai 2: Tinh P(5<= X <= 12) co pp nhu bai tren

# Cách 1: Tinh bang tong xac suat: 
# P(5<=X<=12) = P(X=5) + P(X=6) + ... + P(X=12)
sum(dhyper(5:12,m,n,k))

# Cach 2: Ham pp tich luy FX(x) = P(X<=x)
# Tính bang FX : P(5<=X<=12) = Fx(12) - Fx(5-1)
phyper(12,m,n,k) - phyper(4,m,n,k)

# Bai 3: X la bien nn lien tuc
# a. Ve ham mat do X ~ exp(lambda = 0.6):
curve(dexp(x,0.6), from = 0, to = 10, col = "blue")
# b. Ve ham mat do cua X ~ exp(lambda = 0.3):
curve(dexp(x,0.3), from = 0, to = 10, col = "red", add = TRUE)
# c. Su dung ham phan phoi tich luy tinh dien tich ben duoi 2 ham mat do
# Tim nghiem cua phuong trinh: dexp(x,0.6) - dexp(x,0.3) = 0
x0 <- uniroot(function(x) dexp(x,0.6) - dexp(x,0.3), lower = 0, upper = 10)$root
x0
# Tinh dien tich ben duoi hai ham mat do
I1 = pexp(x0,0.3)
I2 = pexp(10, 0.6) - pexp(x0, 0.6)
I = I1 + I2; I
# Kiem tra lai bang cach tinh tich phan
S1 = integrate(function(x) dexp(x,0.3), lower =0, upper = 0)$value
S2 = integrate(function(x) dexp(x,0.6), lower = x0, upper = 10)$value
S = S1 + S2; S