# Leetcode 69: x的平方根

实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

### 二分查找

一翻自己居然还做过，典型二分法，以前的代码:

```c++
class Solution {
public:
    int mySqrt(int x) {
        if(x<=1)return x;
        int p1=1,p2=x;
        while(p1<=p2){
            int mid=p1+(p2-p1)/2;
            cout<<mid<<endl;
            if(mid<=x/mid&&mid+1>x/(mid+1))return mid;
            else if(mid>x/mid){
                p2=mid-1;
                continue;
            }
            else if(mid<x/mid){
                //if((mid+1)*(mid+1)>x)return mid;
                p1=mid+1;
                continue;
            }
        }
        return -1;
    }
};
```

### 牛顿迭代法
不断用(x, f(x))的切线来逼近方程 x^2-a=0的根。根号a实际上就是x^2-a=0的一个正实根，这个函数的导数是2x。也就是说，函数上任一点(x,f(x))处的切线斜率是2x。那么，x−f(x)/(2x) 就是一个比x更接近平方根的近似值。代入f(x)=x^2-a得到x-(x^2-a)/(2x)，也就是(x+a/x)/2。

```c++
class Solution {
public:
    int mySqrt(int x) {
        if(x<=1)return x;
        double x_cp = (double)x;
        //cout<<x_cp<<endl;
        double guess = x_cp;
        while(true){
            double temp = (guess + x/guess)/2;
            //cout<<temp;
            if(double delta = guess>temp?(guess-temp):(temp-guess);delta<0.000012){
                break;
            }
            guess=temp;
        }
        return (int)guess;
    }
};
```
结果非常amazing啊，C++运行0ms,时间空间复杂度都优于二分法。
Python代码:
```python
//为了偷懒，这个代码是我抄的
class Solution:
    def mySqrt(self, x):
        if x < 0:
            raise Exception('不能输入负数')
        if x == 0:
            return 0
        # 起始的时候在 1 ，这可以比较随意设置
        cur = 1
        while True:
            pre = cur
            cur = (cur + x / cur) / 2
            if abs(cur - pre) < 1e-6:
                return int(cur)
```
```python
//这样写也可以，不过感觉比较差一点，每次判断要多进行一次乘法运算
class Solution:
    def mySqrt(self, x: int) -> int:
        num = x
        while abs(x - num * num) > 0.01:
            num = (num + x/num) / 2
        return int(num)

```
