#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int data;
    struct tree * left;
    struct tree * right;
}tree;

void createtree(tree ** l){
    printf("������ڵ���ֵ��0����ýڵ�Ϊ��: ");
    int val;
    scanf("%d", &val);
    if(val = 0){
        *l = NULL;
        return;
    }
    else{
        tree *node = malloc(sizeof(tree));
        node->data = val;
        (*l)->data = node;
        createtree(&((*l)->left));
        createtree(&(*l)->right);
    }
}

void printtree(tree *l){
    if(l == NULL){
        return;
    }
    else{
        printf("%d ", l->data);
        printtree(l->left);
        printtree(l->right);
    }
}

int main(){
    tree *l = NULL;
    createtree(&l);
    printtree(l);
}