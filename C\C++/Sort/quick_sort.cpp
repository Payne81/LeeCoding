/*
 * @Author: Payne
 * @Date: 2021-03-12 09:06:56
 * @LastEditors: Payne
 * @LastEditTime: 2021-03-13 09:08:36
 * @Description: quick_sort
 */
#include <iostream>

using namespace std;

/**
 * 稳定性: 稳定
 * 时间复杂度： O(nlogn)[平均]，O(n^2)[最坏]
 */
void Qsort(int arr[], int low, int high){
    if(low >= high)
        return;
    int key = arr[low];
    int i = low, j = high;
    while(i<j){
        while(arr[j]>=key){
            j--;
        }
        if(j>i){
            arr[i]=arr[j];
            arr[j]=key;
        }
        while(arr[i]<key){
            i++;
        }
        arr[j]=arr[i];
        arr[i]=key;
    }
    Qsort(arr,low,i-1);
    Qsort(arr,i+1,high);
}
int main()
{
    int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};
    Qsort(a, 0, 8);/*这里原文第三个参数要减1否则内存越界*/
    for(int i = 0; i < 9; i++){
        cout<<a[i]<<" ";
    }   
    cout<<"\n"; 
    return 0;
}
