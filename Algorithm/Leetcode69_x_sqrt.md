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