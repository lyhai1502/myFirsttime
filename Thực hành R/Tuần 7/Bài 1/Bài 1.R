# Bài 1: Tạo vecto x = [1,2,5,7,-3,0,5,1,5,6] và Y = [2,2,0,-5,7,8,11,9,3,2]
# a. Tính x+y, x*y,x-y
x <- c(1, 2, 5, 7, -3, 0, 5, 1, 5, 6); x
y <- c(2, 2, 0, -5, 7, 8, 11, 9, 3, 2); y
# Tinh tổng, tích, hiệu
x+y; x*y; x-y

# b. Tách gía trị x chẳn gán vào z, giá trị của y lẻ cho t
z <- x[x%%2 == 0];z
t <- y[y%%2 == 1];t

# c.Tách giá trị dương của x và y
x[x>0]; y[y>0]

# d.
# Tính trung bình mẫu của x
mean(x)
# Độ lệch chuẩn của x
sd(x)
# Sai số chuẩn của x
sd(x)/sqrt(length(x)) 

# e. Tìm phần tử bé nhất và lớn nhất của x,y
min(x); max(x)
min(y); max(y)

# f. Sắp xếp x tăng dần, y giảm dần
sort(x, decreasing = FALSE) # sort(x)
sort(y, decreasing = TRUE) 

# g. Lưu biến x, y
save(x, file = 'varx.rda')
save(y, file = 'vary.rda')