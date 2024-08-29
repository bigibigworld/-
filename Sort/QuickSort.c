#include<stdio.h>
//快速排序时间复杂度为o(nlog2^n),最坏为o(n^2),不稳定。
int parttion(int * a, int low, int high){
    int pivot = a[low];
    while(low < high){
        while(low < high && a[high] >= pivot){  //大于等于保证枢轴右边全部大于等于它
            high--;
        }
        a[low] = a[high];  //交换数值
        while(low < high && a[low] <= pivot){
            low++;
        }
        a[high] = a[low]; //交换
    }
    a[high] = pivot;  //返回下标
    return high;
}

void quicksort(int *a, int low, int high){
    if(low < high){
        int pivtops = parttion(a, low, high);
        quicksort(a, low, pivtops-1);
        quicksort(a, pivtops+1, high);
    }

}
int main(){
    int a[] = {9, 6, 8, 10, 3, 8, 10, 89, 6, 45, 101, 101};
    int n = sizeof(a) / sizeof(a[0]);  //获取数组的长度
    quicksort(a, 0, n-1); 
    for(int i = 0; i < n ;i++){ 
        printf("%d ", a[i]);
    }
}
