rm(list=ls(all=TRUE))
#a.Doc file data11.csv
setwd("/Users/lyhai1502/Library/Mobile Documents/com~apple~CloudDocs/R/BTTH R")
data11 <- read.csv("data11.csv", header = TRUE)
attach(data11)
data11
#b. Viet ham tinh cac tham so mau cho bang tan so dang khoang
inf.plant <- function(d){
	y <- (a+b)/2
	x <- rep(y,n)
	m <- min(x) #chieu cao be nhat
	M <- max(x) #chieu cao lon nhat
	x.bar = mean(x) #trung binh mau
	s <- var(x) #phuong sai mau
	dat <- data.frame(Min = m, Max = M, Mean = x.bar, Var = s)
	rownames(dat) <- c(" ")
	return (dat)
}
ans <- inf.plant(data11)
ans


