#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

//˳���Ľṹ�� (��̬˳���)
typedef struct List{
    int data[MAX_SIZE];
    int length;
}list;

//��ʼ��˳���
void initlist(list *l){
     l->length = 0;
}

//��������,��β�����
void insertlist(list *l, int data){
    if(l->length < 10){
        l->data[l->length] = data;
        l->length++;
    }else{
        printf("�ռ䲻��,����ʧ��\n");
    }

};



//ɾ��˳����е�ĳ������
void deledata(list *l, int data){
    int m = 0;
    for(int i = 0; i < l->length; i++){
        if(l->data[i] == data){
            for(int j = i; j < l->length-1; j++){
                l->data[j] = l->data[j+1];
            }
            m = 1;
            i = i - 1;  //��������ȫ��ǰ��һλ��������Ҫ��i����һλ��������˳����ң��������©һλ���ݡ�
            l->length--;
        }
    }
    if(m == 1){
        printf("��ɾ��Ԫ��%d \n", data);
        // printlist(l);
    }else{
        printf("��Ԫ�ز�����");
    }
}


//���±�ɾ��Ԫ��
void deledatabyindex(list *l ,int i){
    if(i<0||i>l->length){
        printf("��������");
    }
    for(int j = i; j < l->length-1; j++){
        l->data[j] = l->data[j+1];
    }
    l->length--;
}

//�޸�����,����ֵ
void modifydata(list *l, int data,int new){
    int m = 0;
    for(int i = 0; i < l->length; i++){
        if(l->data[i] == data){
            l->data[i] = new;
            m = 1;
        }
    }
    if(m == 1){
        printf("�ѽ�Ԫ��%d �޸�Ϊ%d\n", data, new);
        // printlist(l);
    }else{
        printf("��Ԫ�ز�����");
    }
}

//���±��޸�Ԫ��
void modifydatabyindex(list *l ,int i, int data){
    if(i<0||i>l->length){
        printf("��������");
        return;
    }
    l->data[i] = data;
    printf("�ѽ��±�%d������ �޸�Ϊ%d\n", i, data);
}

//����ָ��Ԫ��
void finddata(list*l, int data){
    int flag = 0;
    int a[10] = {0};//����һ���������ڴ洢Ԫ�س��ֵ�λ�á�
    for(int i = 0; i < l->length; i++){
        if(l->data[i] == data){
            a[flag] = i + 1;
            flag++;
        }
    }
    if(a[0]!=0){
        printf("�ҵ�����%d,�����±�Ϊ", data);
        for(int i = 0; a[i] != 0; i++){
            printf("%d ", a[i]-1);
        }
        printf("��λ��\n");
    }
    else{
        printf("��ͽ���أ�\n");
    }
}


//��ӡ˳����е�����
void printlist(list *l){
    printf("��ʱ���е�Ԫ��Ϊ��");
    for(int i = 0; i < l->length; i++){
        printf("%d ", l->data[i]);
    }
    printf("\n��ʱ��Ϊ%d\n", l->length);
}

int main(){
    list l; //����һ����Ϊl��list�ṹ��
    initlist(&l);
    insertlist(&l, 5);
    insertlist(&l, 4);
    insertlist(&l, 3);
    insertlist(&l, 56);
    insertlist(&l, 8);
    insertlist(&l, 6);
    insertlist(&l, 78);
    insertlist(&l, 9);
    insertlist(&l, 6);
    insertlist(&l, 5);
    printlist(&l);
    modifydatabyindex(&l, 5, 55);
    finddata(&l , 101);
    printlist(&l);
}