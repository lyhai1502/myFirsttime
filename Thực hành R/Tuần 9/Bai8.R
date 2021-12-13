load("/Users/vanlyhai/Code Collection/Năm 2/Thực hành R/Tuần 9/heights.rda")
summary(heights)
hist(heights)
heights
t.test(heights, alternative = 'two.sided', mu = 160, conf.level = 0.95)
t = qt(1 - 0.05 / 2, 124); t


# Bai 3:
# Dua du lieu vao R
data <- read.csv("/Users/vanlyhai/Code Collection/Năm 2/Thực hành R/Tuần 9/profit.csv")
data

# Tao vector
x <- data$profit; x
# Cau a: Ve do thi cua du lieu
hist(x)

# Cau b:Uoc luong khoan cho ky vong voi alpha = 1% cho mau co pp chuan:
# Loc ra nhugn ngay co doanh so ban hang lon hon 65tr
hi.pro <- x[x > 65]
# Tinh trung binh mau, do lech chuan mau
x.bar <- mean(hi.pro)
s <- sd(hi.pro)
n <- length(hi.pro)
alpha <- 0.01
epsilon = qnorm(1 - alpha / 2) * s / sqrt(n)
mu.lower = x.bar - epsilon
mu.upper = x.bar + epsilon
cat('Khoang tin cay', 100 * (1 - alpha), '% cho ky vong mu la:\n')
cat('[', mu.lower, ';', mu.upper, ']\n')

# Cau c: Su dung ham t.test de kiem dinh gia thuyet cho ky vong voi muc y nghia 1%
# Dat gia thuyet: H0: "mu <=60" ; H1: "mu>60"
t.test(x, alternative = "greater", mu = 60, conf.level = 0.99)
# Nhan xet: Ket qua cho ta p-value = 0.9699 > 0.01 = 1% = alpha
# Do do chua du co so de ba c bo gia thiet H0="mu<=60" voi muc y nghia 1%
# Ket luan: Voi muc y nghia 1%, phuong thuc ban hang moi khong mang lai hieu qua bang phuong thuc ban hang truoc do

# Bai 2
# Cau a: Bien doi du lieu ve dang vector
xi <- c(5,6,7,8,9,10)
ni <- c(5,10,15,20,12,8)
x <- rep(xi,ni); x

# Ve bieu do steam & leaf cho du lieu x:
stem(x)

# Cau b
# Viet ham test.geq.oneside

test.geq.oneside <- function(x, mu_0, alpha){
  x.bar = mean(x)
  s = sd(x)
  n = length(x)
  # Tinh gia tri thong ke kiem dinh t0:
  t_0 = (x.bar - mu_0)*sqrt(n)/s
  # Tinh p - value
  p.value = 1 - pt(t_0, n-1)
  cat('Voi muc y nghia alpha = ', alpha, ':\n')
  if(p.value <= alpha)
    cat('Bac bo H0 voi p-value = ', p.value)
  else
    cat('Chua du co so de bac bo H0 voi p-value = ', p.value)
}
# Ap dung:
test.geq.oneside(x,8,0.05)
# Kiem tra lai bang ham t.test:
t.test(x, alternative = "greater", mu = 8, conf.level = 0.95)