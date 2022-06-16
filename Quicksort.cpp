//1803020131 郑宇凡 电信18-1
#include "string.h"
//#define DEBUG
int Paritition1(int A[], int left, int right)
{
    int pivot = A[left]; 
    while (left < right) //直到左右指针重合跳出循环
    {
#ifdef DEBUG
        static int num[10];
        for (int i = 0; i < 10; i++)
        {
            num[i] = A[i];
        }
#endif
        while (left < right && A[right] >= pivot)
        {
            --right; //右指针左移直到右指针指向的数的值大于中轴
        }
        A[left] = A[right]; //把右指针指向位置的值赋给左指针指向位置
        while (left < right && A[left] <= pivot)
        {
            ++left; //左指针右移直到左指针指向的数的值小于中轴
        }
        A[right] = A[left]; //把左指针指向位置的值赋给右指针指向位置
    }
    A[left] = pivot; //这个时候左右指针已经重合把中心轴的值放在重合位置
    return left;
}

void QuickSort(int A[], int left, int right)
{

    int pivot;
#ifdef DEBUG
    static int num[10];
    for (int i = 0; i < 10; i++)
    {
        num[i] = A[i];
    }
#endif
    if (left < right)
    { //直到左子序列的左值等于右子序列右值。
        pivot = Paritition1(A, left, right);
        QuickSort(A, left, pivot - 1);  //先排左子序列
        QuickSort(A, pivot + 1, right); //再排右子序列
    }
}
int main()
{
    int num[10] = {19, 97, 9, 17, 1, 7, 3, 8, 9, 1};
    int left = 0, right = 9;
    QuickSort(num, left, right);

    return 0;
}
