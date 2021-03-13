/*
 * @Author: Payne
 * @Date: 2021-03-13 14:41:34
 * @LastEditors: Payne
 * @LastEditTime: 2021-03-13 14:48:00
 * @Description: 
 */


/**
 * 堆排序: 稳定
 * 时间复杂度: O(nlogn)
 */
void HeapSort(vector<int> &nums){
    
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