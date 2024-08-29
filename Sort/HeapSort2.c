#include<stdio.h>

//堆排序最坏，最好和平均时间复杂度均为o(nlogn)，，不稳定的排序， 仅适用于顺序存储的线性表
void HeapAdjust(int * a, int i, int n){  //i是父节点，n是长度
    int k = i;
    int left = 2*i+1; //左孩子
    int right = 2*i+2; //右孩子

    if(left < n && a[left] > a[k]){  //孩子比父节点大，则交换
        k = left;
    }
    if(right < n && a[right] > a[k]){
        k = right;
    }

    if(k != i){       //如果k与i不相等，说明根节点与父节点发生了交换
        int temp = a[i];
        a[i] = a[k]; 
        a[k] = temp;
        // HeapAdjust(a, k, n);
    }
}

void BuildHeap(int * a, int n){
    for(int i = n / 2 - 1; i >= 0; i--){ //从第下标为i的节点调整，一共需要调整i+1次
        HeapAdjust(a, i, n);  //调整堆
    }
}

void HeapSort(int * a, int n){
    BuildHeap(a, n);  //建立一个堆
    for(int i = n - 1; i > 0; i--){  //将第一个元素与最后一个元素进行交换，并且下次从数组长度减一开始进行堆排序
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        HeapAdjust(a, 0, i);  //从n-1再次排序
    }
}

int main(){
    int a[] = {9, 6, 8, 10, 3, 8, 10, 89, 6};
    int n = sizeof(a) / sizeof(a[0]);
    HeapSort(a, n);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}