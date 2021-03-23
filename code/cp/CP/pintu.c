#include<stdio.h>
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (int j = low; j <= high- 1; j++) 
    { 
         
        if (arr[j] < pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
int main(void)
{
    int t,m,n;
    scanf("%d",&t);
    while(t-->0)
    {
        scanf("%d %d",&n,&m);

        int arr1[n],arr2[n],arr3[m];

        for(int i=0;i<n;i++)
            scanf("%d",&arr1[i]);

        for(int i=0;i<n;i++)
            scanf("%d",&arr2[i]);

        for(int i=0;i<m;i++)
        {
            arr3[i]=0;
            int sum=0;
            for(int j=0;j<n;j++)
            {
                if(arr1[j]==(i+1))
                {
                    sum+=arr2[j];
                }
            }    
            arr3[i]+=sum;
        }
    int x = sizeof(arr3)/sizeof(arr3[0]); 
    quickSort(arr3, 0, x-1);  
    for(int i=0;i<m;i++)
    {
        if(arr3[i]!=0)
        {
            printf("%d\n",arr3[i]);
            break;
        }
    }
    }
    return 0;
}
 
  
