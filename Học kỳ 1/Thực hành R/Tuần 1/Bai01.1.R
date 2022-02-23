#Văn Lý Hải - 20120073 - Chiều T3 - Ca 1
#So sinh vien
n <- 40
#tao vecto sinh vien x
x <- round(runif(n,0,10),2)
x

#ham tinh ki vong
kyvong <- function(x)
{
	ans = 0
	n <- length(x)
	for(i in 1:n)
		ans = ans + x[i]
	kyvong = ans/n
	return (kyvong)
}
kyvongans <- round(kyvong(x),2) 
kyvongans

#ham tinh phuong sai
phuongsai <- function(x)
{
	ans = 0
	n <- length(x)
	for(i in 1:n)
		ans = ans + (x[i]-kyvongans)^2
	ps = 1/(n-1) * ans
	return (ps)
}
phuongsaians <- round(phuongsai(x),2)
phuongsaians

	

