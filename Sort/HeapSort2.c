#include<stdio.h>

//�����������ú�ƽ��ʱ�临�ӶȾ�Ϊo(nlogn)�������ȶ������� ��������˳��洢�����Ա�
void HeapAdjust(int * a, int i, int n){  //i�Ǹ��ڵ㣬n�ǳ���
    int k = i;
    int left = 2*i+1; //����
    int right = 2*i+2; //�Һ���

    if(left < n && a[left] > a[k]){  //���ӱȸ��ڵ���򽻻�
        k = left;
    }
    if(right < n && a[right] > a[k]){
        k = right;
    }

    if(k != i){       //���k��i����ȣ�˵�����ڵ��븸�ڵ㷢���˽���
        int temp = a[i];
        a[i] = a[k]; 
        a[k] = temp;
        // HeapAdjust(a, k, n);
    }
}

void BuildHeap(int * a, int n){
    for(int i = n / 2 - 1; i >= 0; i--){ //�ӵ��±�Ϊi�Ľڵ������һ����Ҫ����i+1��
        HeapAdjust(a, i, n);  //������
    }
}

void HeapSort(int * a, int n){
    BuildHeap(a, n);  //����һ����
    for(int i = n - 1; i > 0; i--){  //����һ��Ԫ�������һ��Ԫ�ؽ��н����������´δ����鳤�ȼ�һ��ʼ���ж�����
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
        HeapAdjust(a, 0, i);  //��n-1�ٴ�����
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