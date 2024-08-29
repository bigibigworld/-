#include<stdio.h>

void  Merge(int *a, int mid, int left, int right){
    int n1 = mid - left + 1; //用于记录左右两个小数组的长度
    int n2 = right - mid;
    int l1[n1], l2[n2];
    for(int i = 0; i < n1;i++){
        l1[i] = a[left + i];      //将a数组中的值复制到小数组中
    }
    for(int i = 0; i < n2; i++){
        l2[i] = a[mid + 1 + i];  
    }
    int k = left, i = 0, j = 0;
    while(i < n1&& j < n2){
        if(l1[i] <= l2[j])  //当左边的数组值小于右边时，将其赋给a数组
        {
            a[k] = l1[i];
            k++; //大数组和小数组的下标都要加一
            i++;
        }
        else{
            a[k] = l2[j];
            k++;
            j++;
        }
    }
    while(i < n1){   //此时说明小数组中还有元素未赋值到a数组中，则对二者进行赋值操作
        a[k] = l1[i];
        i++;
        k++;
    }
    while(j < n2){
        a[k] = l2[j];
        j++;
        k++;
    }
}


void MergeSort(int * a, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;  //防止数据太大造成溢出
        MergeSort(a, left, mid);
        MergeSort(a, mid + 1, right);
        Merge(a, mid, left, right);
    }
}


int main(){
    int a[] = {9, 6, 8, 10, 3, 8, 10, 89, 6};
    int n = sizeof(a) / sizeof(a[0]) - 1;
    MergeSort(a, 0, n);
    for(int i = 0; i <= n; i++){
        printf("%d ", a[i]);
    }
}