#include <stdio.h>

void HeapAdjust(int *a, int n)
{
    while (1) // ��֪�Εr����ֹͣ������ֱ����ѭ��
    {
        int flag = 0; // ���ñ�ǩ
        for (int i = n / 2; i >= 1; i--)
        {

            int k = 2 * i;  // һ��������
            if (k + 1 <= n) // �ж��Ƿ����Һ���
            {
                if (a[k] < a[k + 1]) // �ж��Һ��Ӻ����ӵĴ�С
                {
                    k = k + 1;
                }
            }
            // ˫��ֻ��Ҫ�����ĺ��ӽ�������
            if (a[i] < a[k]) // �����ӽϴ�ʱ����˫�׽���
            {
                int temp = a[i];
                a[i] = a[k];
                a[k] = temp;
                
                flag = 1; // flag = 1, ��˵����˫�׺ͺ��ӽ����˽���
            }
        }
        if (flag == 0) // ѭ���������������ǽ���һ��֮��˫�׺ͺ��ӽڵ㲢δ����
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