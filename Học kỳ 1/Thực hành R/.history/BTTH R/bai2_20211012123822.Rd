# tinh the thich hinh cau voi ban kinh R tu 3 den 20

#ham tinh the tich
Thetich <- function(){
	r <- 3:20
	v <- round(4*pi*r^3/3,3)
	d <- data.frame(Radius = r, Volume = v)
	return(d)
}

ans <- Thetich()
ans