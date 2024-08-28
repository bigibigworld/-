#include<stdio.h>
#include<stdlib.h>


#define max_size  10 

typedef struct list{   //���嶯̬˳���Ľṹ��
    int * data;  
    int capacity; //����
    int length;  //��ʱ˳���ĳ���
}list;


//��ʼ��˳���
void initlist(list *l){
    l->data = malloc(sizeof(int)*max_size); //����ռ�
    l->length = 0;
    l->capacity = max_size;  //��ʼ����
}

//���Ԫ��
void insertlist(list *l, int data){
    if(l->data == NULL){
        return;
    }
    if(l->capacity==l->length){
        l->capacity += max_size;
        int * new = realloc(l->data, sizeof(int)*(l->capacity));
    }
    l->data[l->length] = data;
    l->length++;
}

//�����±��������(ָ���±�������Ԫ��)
void insertbyindex(list*l, int index, int data){
    if(index < 0||index>l->length){
        printf("������������\n");
        return;
    }
    for( int i = l->length; i>=index;i--){  //�ӱ�ĳ��ȿ�ʼ�������ƶ�Ԫ�أ�һֱ�ƶ���Ҫ�����������λ��" >= "
        l->data[i+1] = l->data[i];
    } 
    l->data[index] = data;
    l->length++;  //�����ǲ���Ԫ�����Ա�Ҫ��һ����������
}

//ɾ��Ԫ��
void deledata(list * l, int data){
    int flag = 0;
    for(int i = 0 ; i <= l->length;i++){
        if(l->data[i] == data){
            for(int j = i; j <= l->length; j++){
                l->data[j] = l->data[j+1]; 
            }
            i = i-1;
            l->length--;
            flag = 1;
        }
    }
    if(flag == 0){
        printf("û�ҵ�:%d \n", data);
    }else{
        printf("�ҵ���%d��ɾ��\n",data);
    }
}

//�޸�Ԫ��
void modifydata(list *l, int data , int new){
    int flag = 0;
    for (int i = 0; i < l->length; i++)
    {
        if(l->data[i] == data){
            l->data[i] = new;
            flag = 1;
        }
    }
    if(flag == 0){
        printf("δ�ҵ�Ԫ��%d\n ", data);
    }else{
        printf("�ѽ�Ԫ��%d�޸�Ϊ%d\n", data, new);
    }
}

//��ӡ˳���
void printlist(list *l){
    printf("��ʱ���ڻ���Ԫ�أ�");
    for(int i = 0 ;i < l->length; i++){
        printf("%d ", l->data[i]); 
    }
    printf("\n��Ϊ%d ����Ϊ%d ʣ��ռ�Ϊ%d" ,l->length, l->capacity, l->capacity-l->length);//�鿴�����Լ�ʣ������
    printf("\n");
}

int main(){
    list l; //������Ϊl��list�ṹ��
    initlist(&l);
    printf("%d\n", l.capacity);
    insertlist(&l, 5);
    insertlist(&l, 6);
    insertlist(&l, 8);
    insertlist(&l, 9);
    insertlist(&l, 5);
    insertbyindex(&l, 2, 12);
    modifydata(&l, 9, 10);
    deledata(&l, 6);
    printlist(&l);
}