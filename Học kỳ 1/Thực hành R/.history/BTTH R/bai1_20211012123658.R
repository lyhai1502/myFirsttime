#Bai1
#Nhap gia tri cho n
n <- 40
# tao 1 vecto chua n, tinh tong tich luy den vi tri i 
Tong <- function(x,i){
	tong = 0
 	for(j in 1:i)
 		tong = tong + x[j]
 	return(tong)
 }
 # Tao va kiem tra vecto x
 #x <- sample(0:100, n, replace = TRUE)
 x <- round(runif(n,0,10),2)
 
 #Kiem tra ham 
 tong1 <- Tong(x,6)
 tong1