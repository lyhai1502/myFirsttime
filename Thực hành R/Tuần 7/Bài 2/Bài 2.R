# BÀI 2.
# Đọc dữ liệu từ file "data01.csv" vào R và gán vào biến data1
data1 <- read.csv('/Users/vanlyhai/Code Collection/Thực hành R/Tuần 7/Bài 2/data01.csv', header = TRUE)
attach(data1); names(data1)
data1

# a. Trung bình
mean(FPSA); mean(TPSA)
# Phuong sai
var(FPSA); var(TPSA)
# Trung vị
median(FPSA); median(TPSA)

# b. Vẽ biểu đồ dạng đường
plot(FPSA, type = "l")
plot(TPSA, type = "l")
# Vẽ biểu đồ boxplot
boxplot(FPSA)
boxplot(TPSA)

# c. Tách những giá trị của FPSA có K = 0
fpsa0 <- subset(FPSA, K==0)
# Tách những giá trị của FPSA có K = 1
fpsa1 <- subset(FPSA, K==1)
# Đọc đữ liệu từ file "data02.csv" vào R và gán vào biến data2
data2 <- read.csv('/Users/vanlyhai/Code Collection/Thực hành R/Tuần 7/Bài 2/data02.csv', header = TRUE)
names(data2)
#attach(data2)
# Ghep 2 data lại theo K
data <- data.frame(data1[1:3], data2); data
# Tạo biến tPSA theo yêu cầu đề bài
tPSA <- Age
tPSA[Age <= 60] <- 0
tPSA[Age > 60 & Age <= 70] <- 1
tPSA[Age > 70] <- 2
# Gan tPSA vào data
data <- data.frame(data, tPSA); data
