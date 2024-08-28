#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

//顺序表的结构体 (静态顺序表)
typedef struct List{
    int data[MAX_SIZE];
    int length;
}list;

//初始化顺序表
void initlist(list *l){
     l->length = 0;
}

//插入数据,在尾部添加
void insertlist(list *l, int data){
    if(l->length < 10){
        l->data[l->length] = data;
        l->length++;
    }else{
        printf("空间不足,插入失败\n");
    }

};



//删除顺序表中的某个数据
void deledata(list *l, int data){
    int m = 0;
    for(int i = 0; i < l->length; i++){
        if(l->data[i] == data){
            for(int j = i; j < l->length-1; j++){
                l->data[j] = l->data[j+1];
            }
            m = 1;
            i = i - 1;  //由于数据全部前移一位，所以需要将i回溯一位，来保持顺序查找，否则会遗漏一位数据。
            l->length--;
        }
    }
    if(m == 1){
        printf("已删除元素%d \n", data);
        // printlist(l);
    }else{
        printf("该元素不存在");
    }
}


//按下标删除元素
void deledatabyindex(list *l ,int i){
    if(i<0||i>l->length){
        printf("索引错误");
    }
    for(int j = i; j < l->length-1; j++){
        l->data[j] = l->data[j+1];
    }
    l->length--;
}

//修改数据,按照值
void modifydata(list *l, int data,int new){
    int m = 0;
    for(int i = 0; i < l->length; i++){
        if(l->data[i] == data){
            l->data[i] = new;
            m = 1;
        }
    }
    if(m == 1){
        printf("已将元素%d 修改为%d\n", data, new);
        // printlist(l);
    }else{
        printf("该元素不存在");
    }
}

//按下标修改元素
void modifydatabyindex(list *l ,int i, int data){
    if(i<0||i>l->length){
        printf("索引错误");
        return;
    }
    l->data[i] = data;
    printf("已将下标%d的数据 修改为%d\n", i, data);
}

//查找指定元素
void finddata(list*l, int data){
    int flag = 0;
    int a[10] = {0};//创建一个数组用于存储元素出现的位置。
    for(int i = 0; i < l->length; i++){
        if(l->data[i] == data){
            a[flag] = i + 1;
            flag++;
        }
    }
    if(a[0]!=0){
        printf("找到你了%d,你在下标为", data);
        for(int i = 0; a[i] != 0; i++){
            printf("%d ", a[i]-1);
        }
        printf("的位置\n");
    }
    else{
        printf("我徒弟呢？\n");
    }
}


//打印顺序表中的数据
void printlist(list *l){
    printf("此时表中的元素为：");
    for(int i = 0; i < l->length; i++){
        printf("%d ", l->data[i]);
    }
    printf("\n此时表长为%d\n", l->length);
}

int main(){
    list l; //定义一个名为l的list结构体
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