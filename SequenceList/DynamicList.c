#include<stdio.h>
#include<stdlib.h>


#define max_size  10 

typedef struct list{   //定义动态顺序表的结构体
    int * data;  
    int capacity; //容量
    int length;  //此时顺序表的长度
}list;


//初始化顺序表
void initlist(list *l){
    l->data = malloc(sizeof(int)*max_size); //申请空间
    l->length = 0;
    l->capacity = max_size;  //初始容量
}

//添加元素
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

//根据下标添加数据(指定下标后面添加元素)
void insertbyindex(list*l, int index, int data){
    if(index < 0||index>l->length){
        printf("插入索引错误\n");
        return;
    }
    for( int i = l->length; i>=index;i--){  //从表的长度开始，往后移动元素，一直移动到要插入的索引的位置" >= "
        l->data[i+1] = l->data[i];
    } 
    l->data[index] = data;
    l->length++;  //由于是插入元素所以表长要加一，否则会溢出
}

//删除元素
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
        printf("没找到:%d \n", data);
    }else{
        printf("找到了%d并删除\n",data);
    }
}

//修改元素
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
        printf("未找到元素%d\n ", data);
    }else{
        printf("已将元素%d修改为%d\n", data, new);
    }
}

//打印顺序表
void printlist(list *l){
    printf("此时表内还有元素：");
    for(int i = 0 ;i < l->length; i++){
        printf("%d ", l->data[i]); 
    }
    printf("\n表长为%d 容量为%d 剩余空间为%d" ,l->length, l->capacity, l->capacity-l->length);//查看表长，以及剩余容量
    printf("\n");
}

int main(){
    list l; //定义名为l的list结构体
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