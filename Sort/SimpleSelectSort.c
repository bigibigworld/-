//��ѡ������ʱ�临�Ӷ�Ϊo(n^2),���ȶ�����

#include<stdio.h>
#define n 6 
int main(){
    int a[n] = {9, 6, 8, 10, 3, 8};
    int k, j, i;
    
    for(i = 0; i < n; i++){      //һ������n-1������
        k = i;
        for(j = i + 1; j < n; j++){
            if(a[j] < a[k]){   //��Ԫ���������еıȽϴ�С
                k = j;         //��¼��Сֵ���±�
            }
        }
        if(k != i){  //˵��k��������Сֵ��k�����˸ı�
            int temp = a[i];  //�����м���������ڼ�¼a[i]��ֵ
            a[i] = a[k];
            a[k] = temp;
        }
    }

    for(i = 0 ; i < n; i++){  //��ӡ����������
        printf("%d ", a[i]);
    }
    return 0;
}