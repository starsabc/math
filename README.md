# 实验课3  描述统计

library(tidyverse)
setwd('/Users/yuanyuan/Documents/R_2025/E_3/')


############################## 连续值变量 ###################################

library(readr)
d.cancer <- read_csv("cancer.csv", locale=locale(encoding = "GBK"))
d.cancer

# 连续性变量：集中趋势
str(d.cancer)
d.cancer$v0
summary(d.cancer$v0)
mean(d.cancer$v0)
median(d.cancer$v0)
quantile(d.cancer$v0,probs=c(0.25,0.50,0.75))

# 连续性变量：离散趋势
sd(d.cancer$v0)
max(d.cancer$v0)
min(d.cancer$v0)
max(d.cancer$v0) - min(d.cancer$v0)
IQR(d.cancer$v0)

# 两连续变量
cov(d.cancer$v0, d.cancer$v1)
cor(d.cancer$v0, d.cancer$v1)

R.iris <- cor(iris[,1:4])
print(round(R.iris, 2))  

# dplyr包 summarise()
library(dplyr)
summarise( d.cancer, 
           mean(v0), 
           median(v0), 
           quantile(v0,0.25), 
           sd(v0),
           max(v0),
           min(v0),
           IQR(v0) ) 

# 管道函数 
x<-runif(10,0,1)
print(x)

a <- log(x)
a <- abs(a)
a <- sqrt(a)
a <- round(a,2)
a

round(sqrt(abs(log(x))),2)

x %>% 
  log()%>% 
  abs() %>% 
  sqrt() %>% 
  round(2)

d.cancer %>% 
  summarise( mean(age),
             median(age),
             quantile(age,0.25), 
             sd(age),
             max(age),
             min(age),
             IQR(age)) 

d.cancer %>% 
  drop_na() %>% 
  summarise( mean(age),
             median(age),
             quantile(age,0.25), 
             sd(age),
             max(age),
             min(age),
             IQR(age)) 



############################## 分类变量 ###################################


##　base包: table()/prop.table()　####
# 一维列联表
table(d.cancer$type)
prop.table(table(d.cancer$type))
prop.table(table(d.cancer$type))*100

# 二维列联表
d.cancer <- d.cancer %>% mutate(Agecate=case_when(age < 50 ~ "less than 50",
                                                  age >= 50 & age < 60 ~ "50 ~ 60",
                                                  age >= 60 & age < 70 ~ "60 ~ 70",
                                                  TRUE ~ "more than 70"))
d.cancer
a <- table(d.cancer$sex,d.cancer$Agecate)
a
prop.table(a) #计算整个百分比
prop.table(a,1)  #计算行百分比
prop.table(a,2)  #计算列百分比

margin.table(a) #计算整个合计
margin.table(a,1) #计算行合计
margin.table(a,2) #计算列合计

addmargins(a) #添加行和列合计
addmargins(a,1) #添加一行进行合计
addmargins(a,2) #添加一列进行合计

addmargins(prop.table(a,1)) 

##　base包: xtabs()　####
xtabs(~ d.cancer$sex + d.cancer$Agecate)

## dplyr包：count() ####
d.cancer %>% count(sex) 
d.cancer %>% group_by(sex) %>% count(Agecate) 

# 分组描述(连续+分类) aggregate()
aggregate(d.cancer$v0,by=list(Gender=d.cancer$sex),mean)
aggregate(d.cancer$v0,by=list(Gender=d.cancer$sex),sd)

# summarise() + groupby()
d.cancer %>% 
  drop_na() %>%
  group_by(sex) %>%
  summarise( mean(age),
             median(age),
             quantile(age,0.25), 
             sd(age),
             max(age),
             min(age),
             IQR(age)) 



############################## 统计图 ###################################

# 1. 条形图
res1 <- table(d.cancer[,'sex']); print(res1)

barplot(res1)
par(family='STKaiti')
barplot(res1, main="性别分布", 
        col=c("brown2", "aquamarine1"))

barplot(res1, width=0.5, xlim=c(-2, 5),
        main="性别分布", 
        col=c("brown2", "aquamarine1"))

barplot(res1, main="性别分布", horiz = TRUE, 
        col=c("brown2", "aquamarine1"))


# 交叉分组频数
res2 <- with(d.cancer, table(sex, type)); res2
barplot(res2, legend=TRUE)
barplot(res2, beside=TRUE, legend=TRUE) # 并排展示
barplot(res2, beside=TRUE, legend=TRUE,
        main='不同种类病人的性别',
        ylim=c(0, 20),
        xlim=c(-1, 6), width=0.6,
        col=c("brown2", "aquamarine1"))


# 2. 饼图
pie(res1, main="Pie")

pie(res1, labels = c('Female', 'Male'), 
    main = "饼图示例 1", 
    col = c("red", "green"))


# 3. 直方图和密度曲线
x <- rnorm(200, mean=100, sd=1)
print(round(x,2))
hist(x)
hist(x, col=rainbow(15), 
     main='正态随机数', xlab='', ylab='频数')

hist(x, freq=FALSE,
     col=rainbow(15),
     main='正态随机数',
     xlab='', ylab='频数')
plot(density(x), lwd=2, col='blue')

hist(x, freq=FALSE,
     col=rainbow(15),
     main='正态随机数',
     xlab='', ylab='频数')
lines(density(x), lwd=2, col='blue')


# 4. 箱线图 & 小提琴图
with(d.cancer, boxplot(v0))
with(d.cancer, boxplot(v0 ~ sex))
with(d.cancer,
     boxplot(list('治疗前'=v0, '治疗后'=v1)))

library(vioplot)
with(d.cancer,
     vioplot(list('治疗前'=v0, '治疗后'=v1)))


# 5. 散点图
d.class <- read_csv("class.csv")
d.class 
plot(d.class$height, d.class$weight)

with(d.class,
     plot(height, weight))

with(d.class,
     plot(height, weight,
          main='体重与身高关系',
          xlab='身高', ylab='体重'))

with(d.class,
     plot(height, weight,
          pch=16, col='blue',
          cex=1))

with(d.class,
     plot(height, weight,
          pch=16, col='blue',
          cex=1 + (age - min(age))/(max(age)-min(age))))

with(d.class, 
     plot(height, weight,
          main='体重与身高关系',
          xlab='身高', ylab='体重',
          pch=16, 
          col=ifelse(sex=='M', 'blue', 'red'),
          cex=1 + (age - min(age))
          /(max(age)-min(age))))

# 散点图矩阵
pairs(d.class[, c('age', 'height', 'weight')])


############################## R作图 ###################################

# 1. 函数曲线
curve(1 - 3*x - x^2, -4, 2)
curve(sin, -2*pi, 2*pi)

x <- seq(0, 2*pi, length=200)
y <- sin(x)
plot(x,y)
plot(x,y, type='l')
plot(x,y, type='l', lwd=2)
plot(x,y, type='l', lwd=2, lty=3)


# 2. abline
abline(h=0, col='gray')

with(d.class, plot(height, weight))
abline(-143, 3.9, col="red", lwd=2)  # 截距、斜率
abline(v=c(55,60,65,70), col="gray")
abline(h=c(60,80,100,120,140), col="gray")

# 3. plot();points();lines()；text()
x <- seq(0, 2*pi, length=200)
y <- sin(x)
special <- list(x=(0:4)*pi/2, y=sin((0:4)*pi/2))
plot(x, y, type='l')
points(special$x, special$y, 
       col="red", pch=16, cex=2)
points(special, col="red", pch=16, cex=2)

lines(x, y, lwd=2, col="blue")

legend(0, -0.5, col=c("red", "blue"),
       lty=c(1,1), lwd=c(2,2), 
       legend=c("sin", "cos"))

legend('top', col=c("red", "blue"),
       lty=c(1,1), lwd=c(2,2), 
       legend=c("sin", "cos"))

text(4, 1, adj=0, '正弦函数和余弦函数')
text(4, 1, adj=1, '正弦函数和余弦函数')


# 一页多图
opar <- par(mfrow=c(2,2),    # 一页多图用mfrow参数或mfcol参数规定
            oma=c(0,0,2,0))  # oma指定四个外边空的行数
with(d.class, {hist(height);
  boxplot(height);
  qqnorm(height); qqline(height);
  plot(height)})
mtext(side=3, text='身高分布', cex=2, outer=T)


opar <- par(mfcol=c(2,2),    # 一页多图用mfrow参数或mfcol参数规定
            oma=c(0,0,2,0))  # oma指定四个外边空的行数
with(d.class, {hist(height);
  boxplot(height);
  qqnorm(height); qqline(height);
  plot(height)})
mtext(side=3, text='身高分布', cex=2, outer=T)
par(opar)

# 保存输出

pdf(file='fig-hw.pdf', height=4,
    width=4, family='GB1')
with(d.class, plot(height, weight,
                   main='体重与身高关系'))
dev.off()


png(file='fig-hw.png', height=500, width=500)
with(d.class, plot(height, weight,
                   main='weight&height'))
dev.off()


############################## ggplot作图 ###################################

library(ggplot2)
data(diamonds)
diamonds

small<-diamonds[sample(nrow(diamonds),1000),] 
head(small)
p <- ggplot(data=small, 
            mapping=aes(x=carat, y=price))
p+geom_point()


p <- ggplot(small, 
            aes(carat, price))
p+geom_point()
p + geom_point() + geom_smooth()


# 1. 数据和映射
# 加形状
p <- ggplot(data=small, mapping=aes(x=carat, y=price, shape=cut))
p+geom_point()

# 加颜色
p <- ggplot(data=small, mapping=aes(x=carat, y=price, shape=cut, colour=color))
p+geom_point()


# 2. 几何对象
### 直方图
ggplot(small)+geom_histogram(aes(x=price))
ggplot(small)+geom_histogram(aes(x=price, fill=cut))
ggplot(small)+geom_histogram(aes(x=price, fill=cut), position="dodge")
ggplot(small)+geom_histogram(aes(x=price, fill=cut), position="fill")

### 条形图
ggplot(small)+geom_bar(aes(x=clarity))

### 密度曲线
ggplot(small)+geom_density(aes(x=price, colour=cut))  # 曲线颜色
ggplot(small)+geom_density(aes(x=price, fill=clarity))  # 填充颜色

### 箱线图
ggplot(small)+geom_boxplot(aes(x=cut, y=price,fill=color))


# 3. 统计变换（Statistics）
### 连续值
ggplot(small, aes(x = cut, y = price)) +
  stat_summary(fun = mean, geom = "bar", fill = "skyblue", 
               position = position_dodge())

ggplot(small, aes(x = cut, y = price)) +
  stat_summary(fun = mean, geom = "point", fill = "skyblue")

ggplot(small, aes(x = cut, y = price)) +
  stat_summary(fun = sum, geom = "point", fill = "skyblue")

ggplot(small, aes(x = cut, y = price)) +
  stat_summary(fun = sd, geom = "point", fill = "skyblue")

### 分类值
ggplot(small, aes(x = color)) +
  stat_count()

ggplot(small, aes(x = cut)) +
  stat_count()


# 4. scale
ggplot(small)+
  geom_point(aes(x=carat, y=price, shape=cut, colour=color))+
  scale_colour_manual(values=rainbow(7))

ggplot(small)+
  geom_point(aes(x=carat, y=price, shape=cut, colour=color))+
  scale_y_log10()+
  scale_colour_manual(values=rainbow(7))


# 5. 坐标系
ggplot(small)+geom_bar(aes(x=cut, fill=cut))
## coord_flip()坐标轴翻转
ggplot(small)+geom_bar(aes(x=cut, fill=cut))+coord_flip()
## coord_polar()转极坐标
ggplot(small)+geom_bar(aes(x=factor(1), fill=cut))+coord_polar(theta="y")
## 靶心图
ggplot(small)+geom_bar(aes(x=factor(1), fill=cut))+coord_polar()
## 风玫瑰图
ggplot(small)+geom_bar(aes(x=clarity, fill=cut))+coord_polar()


# 6. 位置调整（position adjustment）
ggplot(small, aes(x = cut, y = price, fill = color)) +
  stat_summary(fun = mean, geom = "bar", position = 'dodge') 

ggplot(small, aes(x = cut, y = price, fill = color)) +
  stat_summary(fun = mean, geom = "bar", position = 'stack') 

ggplot(small, aes(x = cut, y = price, fill = color)) +
  stat_summary(fun = mean, geom = "bar", position = 'fill') 

ggplot(small, aes(x = cut, y = price, fill = color)) +
  stat_summary(fun = mean, geom = "bar", position = position_dodge(width=0.5)) 

ggplot(small, aes(x = cut, y = price, fill = color)) +
  stat_summary(fun = mean, geom = "bar", position = position_dodge(width=0.9)) 


# 7. 主题（theme）
ggplot(small, aes(x = cut, y = price)) +
  geom_point() + 
  labs(title = "Price of Diamonds by cut") 

ggplot(small, aes(x = cut, y = price,  color = color)) +
  geom_point() + 
  labs(title = "Price of Diamonds by cut") 

### 调整图的背景和标题
ggplot(small, aes(x = cut, y = price,  color = color)) +
  geom_point() + 
  labs(title = "Price of Diamonds by Cut and Color") + 
  theme(
    plot.title = element_text(size = 16, face = "bold"),
    plot.background = element_rect(fill = "lightyellow")
  )

### 调整面板背景和网格
ggplot(small, aes(x = cut, y = price,  color = color)) +
  geom_point() + 
  theme(
    panel.background = element_rect(fill = "lightblue"),
    panel.grid.major = element_line(color = "gray"),
    panel.grid.minor = element_blank()
  )

### 调整图例
ggplot(small, aes(x = cut, y = price,  color = color)) +
  geom_point() + 
  labs(title = "Price of Diamonds by Cut") +
  theme(
    legend.background = element_rect(fill = "lightgray"),
    legend.position = "right",
    legend.title = element_text(face = "bold")
  )

### 调整坐标轴
ggplot(small, aes(x = cut, y = price,  color = color)) +
  geom_point() + 
  labs(title = "Average Price of Diamonds by Cut") +
  theme(
    axis.title.x = element_text(face = "bold"),
    axis.title.y = element_text(face = "bold"),
    axis.text.x = element_text(angle = 45, hjust = 1)
  )

### R自带主题 theme_XX
p <- ggplot(small, aes(x = cut, y = price,  color = color)) +
        geom_point() + 
        labs(title = "Average Price of Diamonds by Cut") 

p + theme_bw()
p + theme_minimal()
library(ggthemes)
p + theme_wsj()


# 8. 分面
ggplot(small, aes(x=carat, y=price))+
  geom_point()+
  scale_y_log10()+
  facet_wrap(.~cut)+
  stat_smooth()

ggplot(small, aes(x=carat, y=price))+
  geom_point()+
  scale_y_log10()+
  facet_wrap(~cut, nrow = 1, ncol = 5)+
  stat_smooth()

ggplot(small, aes(x = carat, y = price)) +
  geom_point(stat = "identity", fill = "skyblue") +
  facet_grid(color ~ cut) +
  labs(title = "Price of Diamonds by Cut, Color, and Clarity")
