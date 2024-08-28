//简单选择排序：时间复杂度为o(n^2),不稳定排序。

#include<stdio.h>
#define n 6 
int main(){
    int a[n] = {9, 6, 8, 10, 3, 8};
    int k, j, i;
    
    for(i = 0; i < n; i++){      //一共进行n-1次排序
        k = i;
        for(j = i + 1; j < n; j++){
            if(a[j] < a[k]){   //将元素与数组中的比较大小
                k = j;         //记录最小值的下标
            }
        }
        if(k != i){  //说明k本身不是最小值，k发生了改变
            int temp = a[i];  //定义中间变量，用于记录a[i]的值
            a[i] = a[k];
            a[k] = temp;
        }
    }

    for(i = 0 ; i < n; i++){  //打印排序后的数组
        printf("%d ", a[i]);
    }
    return 0;
}