# include "stdio.h"

int binarySearch(int *arr,int key,int length)
{
    int low = 0;
    int high = length;
    int mid;
    while ((low <= high))
    {
        mid = (low + high) / 2;
        if (key < arr[mid])
        {
            high = mid - 1;//到左边找
        }
        else if (arr[mid] < key)
        {
            low = mid +1;//到右找
        }
        else
        {
            return mid;
        }
    }
    return -1;

    
}
int main()
{
    int arr[] = {13, 45, 78, 90, 127, 189, 243, 355};
    printf("%d",binarySearch(arr,78,sizeof(arr)/sizeof(arr[0])-1));
    return 0;
}
