/*
 * @Author: Payne
 * @Date: 2021-03-13 14:38:42
 * @LastEditors: Payne
 * @LastEditTime: 2021-03-13 15:35:35
 * @Description: 归并排序
 */
#include <iostream>
#include <vector>

using namespace std;


/************ 自己写的垃圾 仅供警示************************/
// Leetcode: 84ms
void Merge(vector<int> &nums, int left, int mid, int right){
    if(mid < left || mid >= right)
        return;
    vector<int> temp(right-left+1, 0);
    int i=left, j=mid+1, k = 0;
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }
    // 接上末尾
    while (i <= mid)
        temp[k++] = nums[i++];
    while (j <= right)
        temp[k++] = nums[j++];
    //不得已加上内存复制(?)
    for(int count = left; count <= right; count++)
        nums[count] = temp[count-left];
    return;
}
/**
 * 归并排序: 稳定
 * 时间复杂度: O(nlogn)
 */
void MergeSort(vector<int>& arr, int low, int high){
    if(low>=high)return;
    int mid = low + (high - low) / 2;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    Merge(arr,low,mid,high);
}

/************ Leetcode的牛逼代码(递归) **************/
// Leetcode 40ms
vector<int> tmp;
void mergeSort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);
    int i = l, j = mid + 1;
    int cnt = 0;
    while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) {
            tmp[cnt++] = nums[i++];
        }
        else {
            tmp[cnt++] = nums[j++];
        }
    }
    while (i <= mid) {
        tmp[cnt++] = nums[i++];
    }
    while (j <= r) {
        tmp[cnt++] = nums[j++];
    }
    for (int i = 0; i < r - l + 1; ++i) {
        nums[i + l] = tmp[i];
    }
}


/****************  迭代解法(!!重要) *******************/
// Leetcode 28ms
void mergesort(vector<int>& nums, int l, int r){

    int n=nums.size();
    vector<int> temp(n, 0);
    int left, right, mid, p1, p2, next;
    // i为步长
    for(int i=1; i < n; i*=2){
        // left, mid, right为一组merge
        for(int left=0; left < n-i; left = right){
            p1      = left;
            mid     = left+i;
            p2      = mid;
            right   = mid+i;
            if(right > n)
                right = n;
            next = 0;
            while(p1 < mid && p2 < right){
                if(nums[p1] < nums[p2])
                    temp[next++] = nums[p1++];
                else
                    temp[next++] = nums[p2++];
            }
            // 在递归的merge环节需要吧right剩下的复制，这里就不用了，处理left部分剩下的就可以了           
			while( p1 < mid )
				nums[--p2] = nums[--mid];
            // 将temp中排好序部分复制回来
            while( next > 0 )
                nums[--p2] = temp[--next];
        }
    }
}

int main(){
    vector<int> nums = {57, 68, 59, 52, 72, 28, 96, 33, 24};
    mergesort(nums,0,nums.size()-1);
    for(int i = 0; i < 9; i++){
        cout<<nums[i]<<" ";
    }   
    cout<<"\n"; 
    return 0;
}