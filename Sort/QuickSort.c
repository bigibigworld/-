#include<stdio.h>
//��������ʱ�临�Ӷ�Ϊo(nlog2^n),�Ϊo(n^2),���ȶ���
int parttion(int * a, int low, int high){
    int pivot = a[low];
    while(low < high){
        while(low < high && a[high] >= pivot){  //���ڵ��ڱ�֤�����ұ�ȫ�����ڵ�����
            high--;
        }
        a[low] = a[high];  //������ֵ
        while(low < high && a[low] <= pivot){
            low++;
        }
        a[high] = a[low]; //����
    }
    a[high] = pivot;  //�����±�
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
    int n = sizeof(a) / sizeof(a[0]);  //��ȡ����ĳ���
    quicksort(a, 0, n-1); 
    for(int i = 0; i < n ;i++){ 
        printf("%d ", a[i]);
    }
}
