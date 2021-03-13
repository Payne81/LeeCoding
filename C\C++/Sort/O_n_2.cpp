/*
 * @Author: Payne
 * @Date: 2021-03-13 08:56:56
 * @LastEditors: Payne
 * @LastEditTime: 2021-03-13 10:36:54
 * @Description: O(n^2)的三个基本排序
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * 插入排序: 稳定
 * 时间复杂度: O(n)
 */
void InsertSort(vector<int> &nums){
    int temp = 0;
    for(int i=0; i < nums.size(); i++){
        int j=i-1;
        temp = nums[i];
        while(j>=0 && nums[j]>temp){
            nums[j+1]=nums[j];
            j--;
        }
        nums[j+1]=temp;
    }
    return;
}

/**
 * 插入排序: --------不稳定！！！！-----------
 * 时间复杂度: O(n)
 */
void SelectSort(vector<int> &nums){
    int temp,min_num;
    // 最后一个数不用排序了
    for(int i=0; i < nums.size()-1; i++){
        temp = nums[i];
        min_num = i;
        for(int j=i; j < nums.size(); j++){
            if(nums[j]<temp){
                temp = nums[j];
                min_num = j;
            }
        }
        nums[min_num] = nums[i];
        nums[i] = temp;
    }
    return;
}

/**
 * 冒泡排序: 稳定
 * 时间复杂度: O(n)
 */
void BubbleSort(vector<int> &nums){
    int temp;
    for(int i=0; i<nums.size()-1; i++){
        for(int j=nums.size()-1; j>i; j--){
            if(nums[j]<nums[j-1]){
                temp        =nums[j];
                nums[j]     =nums[j-1];
                nums[j-1]   =temp;
            }
        }
    }
    return;
}

int main(){
    vector<int> nums = {57, 68, 59, 52, 72, 28, 96, 33, 24};
    // InsertSort(nums);
    //SelectSort(nums);
    BubbleSort(nums);
    for(int i = 0; i < 9; i++){
        cout<<nums[i]<<" ";
    }   
    cout<<"\n"; 
    return 0;
}