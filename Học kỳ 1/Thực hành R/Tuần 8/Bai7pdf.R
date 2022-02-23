# Bài tập ví dụ
m = 50; n= 30; p = .5; alpha = .05 #Tung 30 đồng xu cân đối 50 lần
y = rbinom(m,n,p);y
p.hat = y/n # Ti le mau

epsilon = qnorm(1-alpha/2)*sqrt(p.hat*(1-p.hat)/n) # Dung sai
matplot(rbind(p.hat - epsilon, p.hat + epsilon),
          rbind(1:m,1:m),type="l",lty=1,
          xlab = "Vi tri cac khoang tin cay",
          ylab = "50 khoang tin cay")

# Ve 50 khoang tin cay
abline(v=p) # Ve duong thang p = 0.5


#########################################################
# Bai 1
# Tao mau 35 gia tri cua bien ngau nhien X ~ N(10,5,2)
n = 35
x <- rnorm(n,10,5);x
# TIm KTC 95% cho ky vong, alpha = 5%
x.bar = mean(x)
alpha = .05
s = 5
epsilon = qnorm(1-alpha/2)*s/sqrt(n)
cat('KTC', 100*(1-alpha),'% cho ky vong mu la:\n')
cat('[', x.bar - epsilon, ';', x.bar + epsilon, ']\n')

# Xoa du lieu duoc gan
rm(list = ls(all=T))

# Bai 2
# a. Nhap du lieu tu file data31.xls vao R
dat31 <- read.csv('/Users/vanlyhai/Code Collection/Năm 2/Thực hành R/Tuần 8/data31.csv', header = T)
attach(dat31); names(dat31)
dat31
# b. Viet ham ci.mean
ci.mean <- function(x, alpha){
  n = length(x) # Co mau
  x.bar = mean(x) # Trung binh mau
  s = sd(x) # Do lech tieu chuan mau
  t = qt(1-alpha/2, n-1) # Phan vi muc (1-alpha/2) cua T~t(n-1)
  ep = t*s/sqrt(n) # Sai so uoc luong
  cat('KTC', 100*(1-alpha), '% cho ky vong mu la:\n')
  cat('[', x.bar - ep, ';', x.bar + ep, ']\n')
}

# Ap dung
# KTC 95% cho mu => alpha = 0.05
ci.mean(profit, 0.05)
# KTC 99% cho ky vong mu => alpha = 0.01
ci.mean(profit, 0.01)

# Bai 3
# Nhap du lieu tu file data32.xls vao R
dat32 <- read.csv('/Users/vanlyhai/Code Collection/Năm 2/Thực hành R/Tuần 8/data32.csv', header = T)
attach(dat32); is.na(KHTN)
dat32
# a. Uoc luong khoang cho thoi gian tu hoc trung binh cua sv truong KHTN
# Dung ci.mean de lap KTC 95% cho thoi gian tu hoc sv KHTN
ci.mean(KHTN, 0.05)

# b. Viet ham ci.prop
ci.prop <- function(f, n ,alpha){
  p.hat = f/n #Ty Le mau
  ep = qnorm(1-alpha/2)*sqrt(p.hat*(1-p.hat)/n) #Sai so
  cat('KTC', 100*(1-alpha), '% cho ty le p la:\n')
  cat('[', p.hat - ep, ';', p.hat + ep, ']\n')
}
# Tinh f, n
n = length(KHTN)
f = length(KHTN[KHTN >5])
# Ap dung
ci.prop(f,n,0.1)
ci.prop(f,n,0.05)
ci.prop(f,n,0.01)

# Bai 4
# a. Dua du lieu bang ve dang vector
a <- seq(1.2, 2.0, by = 0.2)
b <- seq(1.4, 2.2, by = 0.2)
m <- (a+b)/2
N <- c(6,34, 31,42, 12)
x <- rep(m,N); x

ci.mean(x,0.05)