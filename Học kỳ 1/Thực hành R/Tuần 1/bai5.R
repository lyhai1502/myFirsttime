#tim pham vi
phamvi <- function(x,p) {
    x <- sort(x)
    i <- (p/100)*length(x)
    if(i-round(i) != 0)
        quantilr =x, ceiling(i) 
    else quantilr = (x[i] + x[i+1])/2
    return (quantilr)
}
#tao vecto X
x <- round(runif(20,0,20),2)

#
q <- phamvi(x,25)
q