#include<stdio.h>

void  Merge(int *a, int mid, int left, int right){
    int n1 = mid - left + 1; //���ڼ�¼��������С����ĳ���
    int n2 = right - mid;
    int l1[n1], l2[n2];
    for(int i = 0; i < n1;i++){
        l1[i] = a[left + i];      //��a�����е�ֵ���Ƶ�С������
    }
    for(int i = 0; i < n2; i++){
        l2[i] = a[mid + 1 + i];  
    }
    int k = left, i = 0, j = 0;
    while(i < n1&& j < n2){
        if(l1[i] <= l2[j])  //����ߵ�����ֵС���ұ�ʱ�����丳��a����
        {
            a[k] = l1[i];
            k++; //�������С������±궼Ҫ��һ
            i++;
        }
        else{
            a[k] = l2[j];
            k++;
            j++;
        }
    }
    while(i < n1){   //��ʱ˵��С�����л���Ԫ��δ��ֵ��a�����У���Զ��߽��и�ֵ����
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
        int mid = left + (right - left) / 2;  //��ֹ����̫��������
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