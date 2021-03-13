/*
 * @Author: Payne
 * @Date: 2021-03-13 14:41:34
 * @LastEditors: Payne
 * @LastEditTime: 2021-03-13 14:48:00
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/**
 * 堆排序: 稳定
 * 时间复杂度: O(nlogn)
 * 空间复杂度: 本来应该原地O(1),用priority_queue是O(n)
 * Leetcode 24ms
 */
void HeapSort(vector<int> &nums){
    priority_queue<int> maxheap;
    for(int i=0; i < nums.size(); i++)
        maxheap.push(nums[i]);
    for(int j=nums.size()-1; j>=0; j--){
        nums[j] = maxheap.top();
        maxheap.pop();
    }
}

int main(){
    vector<int> nums = {57, 68, 59, 52, 72, 28, 96, 33, 24};
    HeapSort(nums);
    for(int i = 0; i < 9; i++){
        cout<<nums[i]<<" ";
    }   
    cout<<"\n"; 
    return 0;
}