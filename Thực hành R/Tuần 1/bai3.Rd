#Bai 3
rm(list=ls(all=TRUE))
# Nhap du lieu tu file data01.csv vao R
setwd("/Users/lyhai1502/Library/Mobile Documents/com~apple~CloudDocs/R/BTTH R")
data01 <- read.csv("data01.csv", header = TRUE)
attach(data01)

# Tao bien va gan gia tri
n <- length(Age)
Index <- numeric(n)
for(i in 1:n){
	if(Age[i] <= 60) {Index[i] <- 0}
	else{
		if(Age[i] <=70) {Index[i] <- 1}
		else{
			if(Age[i] <= 80) {Index[i] <- 2}
			else{
				Index[i] <- 3
			}
		}
	}
}

ans <- data.frame(Age, Index);
ans
detach(data01)