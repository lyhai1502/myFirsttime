# Thuc Hanh Xac suat thong ke ngay 12/19/2021

# Bai 0.1.2: Xuc sac

sixes = function(n){
	x = sample(1:6, n, replace = TRUE)	
	d = which(x == 6)
	if (length(d) > 0) 
		return(TRUE)
	else
		return(FALSE)
}

play = function(n, N){
	dem = 0
 	for (i in 1:N)
		if (sixes(n)==TRUE) 
			dem = dem + 1
	return(dem / N)
}

play(5, 20)

# xoa cac bien
rm(list=ls(all=TRUE))