#tim pham vi
phamvi <- function(x,p) {
    x <- sort(x)
    i <- (p/100)*length(x)
    if(i-round(i) != 0)
    {
        quantile(x, ceiling(i))

    }
}