# Bài 3.
sv <- 1:10
ques1 <- c(3,3,3,4,3,4,3,4,3,4)
ques2 <- c(5,3,5,5,2,2,5,5,4,2)
ques3 <- c(1,3,1,1,1,3,1,1,1,1)
# a. Tạo bang diem
Diem <- data.frame(sv, ques1, ques2, ques3)

# b. Tạo bảng kết quả riêng cho câu hỏi 1, 2
tab1 <- table(ques1); tab1
tab2 <- table(ques2); tab2
tab3 <- table(ques3); tab3
par(mfrow = c(1,3))

# c. Vẽ biểu đồ bar cho 3 câu hỏi
barplot(tab1); barplot(tab2); barplot(tab3)
par(mfrow = c(2,1))
# d. Vẽ biểu đồ bar đang nằm ngang cho câu hỏi 2, 3
barplot(tab2, horiz = T)
barplot(tab3, horiz = T)