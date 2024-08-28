#include <stdio.h>

void HeapAdjust(int *a, int n)
{
    while (1) // 不知何時才能停止，所以直接死循环
    {
        int flag = 0; // 设置标签
        for (int i = n / 2; i >= 1; i--)
        {

            int k = 2 * i;  // 一定有左孩子
            if (k + 1 <= n) // 判断是否有右孩子
            {
                if (a[k] < a[k + 1]) // 判断右孩子和左孩子的大小
                {
                    k = k + 1;
                }
            }
            // 双亲只需要和最大的孩子交换即可
            if (a[i] < a[k]) // 当孩子较大时，与双亲交换
            {
                int temp = a[i];
                a[i] = a[k];
                a[k] = temp;
                
                flag = 1; // flag = 1, 则说明和双亲和孩子进行了交换
            }
        }
        if (flag == 0) // 循环结束的条件就是进行一轮之后，双亲和孩子节点并未交换
        {
            break;
        }
    }
}

void HeapSort(int *a, int n)
{
    while (n > 1)
    {
        HeapAdjust(a, n);
        int temp = a[1];
        a[1] = a[n];
        a[n] = temp;
        n--;
    }
}

int main()
{
    int a[] = {0, 49, 38, 101, 97, 76, 13, 27, 49};
    int n = sizeof(a) / sizeof(a[0]) - 1;
    HeapSort(a, n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }
}