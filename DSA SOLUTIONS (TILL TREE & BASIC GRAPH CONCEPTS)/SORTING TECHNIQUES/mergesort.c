#include <stdio.h>



void merge(int a[],int mid,int low ,int high){

  int i,j,k,b[100];
  i=low;
  j=mid+1;
  k=low;
  while(i<=mid && j<= high){
    if(a[i]<a[j]){
      b[k]=a[i];
      i++;
      k++;

    }
    else{
      b[k]=a[j];
      j++;
      k++;
    }}

    while(i<=mid){
      b[k]=a[i];
      i++;
      k++;

    }

    while(j<=high){

      b[k]=a[j];
      k++;
      j++;

    }
  
  for(int i=low;i<=high;i++){
    a[i]=b[i];

  }

  }



void mergesort( int a[],int low,int high){
  int mid;

  if(low<high){
    mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,mid,low,high);
  }

}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {9,14,4,8,7,6};
    int arr_size = 6;

    printf("Original array: \n");
    printArray(arr,6);

    mergesort(arr, 0, 5);

    printf("Sorted array: \n");
    printArray(arr,6);

    return 0;
}
