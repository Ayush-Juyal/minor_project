#include <iostream>  
using namespace std;  

//linear search
int linearSearch(int a[], int n, int val) {  
  // Going through array linearly  
  for (int i = 0; i < n; i++)  
    {  
        if (a[i] == val)  
        return i+1;  
    }  
  return -1;  
}  


//binary search
int binarySearch(int a[], int beg, int end, int val)    
{    
    int mid;    
    if(end >= beg)     
    {  
        mid = (beg + end)/2;    
/* if the item to be searched is present at middle */  
        if(a[mid] == val)    
        {                 
            return mid+1;    
        }    
            /* if the item to be searched is smaller than middle, then it can only be in left subarray */  
        else if(a[mid] < val)     
        {  
            return binarySearch(a, mid+1, end, val);    
        }    
        /* if the item to be searched is greater than middle, then it can only be in right subarray */      
    else     
        {  
            return binarySearch(a, beg, mid-1, val);    
        }         
    }    
    return -1;     
}   


//exponential search

int exponentialSearch(int arr[], int n, int x)
{
    // If x is present at first location itself
    if (arr[0] == x)
        return 0;
  
    // Find range for binary search by
    // repeated doubling
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i*2;
  
    //  Call binary search for the found range.
    return binarySearch(arr, i/2, 
                            min(i, n-1), x);
}

//interpolation search

int interpolationSearch(int arr[], int n, int x)
{
    // Find indexes of two corners
    int lo = 0, hi = (n - 1);
 
    // Since array is sorted, an element present
    // in array must be in range defined by corner
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        if (lo == hi)
        {
            if (arr[lo] == x) return lo;
            return -1;
        }
        // Probing the position with keeping
        // uniform distribution in mind.
        int pos = lo + (((double)(hi - lo) /
            (arr[hi] - arr[lo])) * (x - arr[lo]));
 
        // Condition of target found
        if (arr[pos] == x)
            return pos+1;
 
        // If x is larger, x is in upper part
        if (arr[pos] < x)
            lo = pos + 1;
 
        // If x is smaller, x is in the lower part
        else
            hi = pos - 1;
    }
    return -1;
}

 //bubble sort
 void bubble(int a[], int n) 
 {  
   int i, j, temp;  
   for(i = 0; i < n; i++)    
    {    
      for(j = i+1; j < n; j++)    
        {    
            if(a[j] < a[i])    
            {    
                temp = a[i];    
                a[i] = a[j];    
                a[j] = temp;     
            }     
        }     
    }     
 

 }  

  // heap sort
void heapify(int a[], int n, int i)  
{  
    int largest = i; // Initialize largest as root  
    int left = 2 * i + 1; // left child  
    int right = 2 * i + 2; // right child  
    // If left child is larger than root  
    if (left < n && a[left] > a[largest])  
        largest = left;  
    // If right child is larger than root  
    if (right < n && a[right] > a[largest])  
        largest = right;  
    // If root is not largest  
    if (largest != i) {  
        // swap a[i] with a[largest]  
        int temp = a[i];  
        a[i] = a[largest];  
        a[largest] = temp;  
          
        heapify(a, n, largest);  
    }  
} 

  void heapSort(int a[], int n)  
{  
  
    for (int i = n / 2 - 1; i >= 0; i--)  
        heapify(a, n, i);  
    // One by one extract an element from heap  
    for (int i = n - 1; i >= 0; i--) {  
        /* Move current root element to end*/  
        // swap a[0] with a[i]  
        int temp = a[0];  
        a[0] = a[i];  
        a[i] = temp;  
          
        heapify(a, i, 0);  
    }  
}   
  
  //quick sort
  int partition (int a[], int start, int end)  
{  
    int pivot = a[end]; // pivot element  
    int i = (start - 1);  
  
    for (int j = start; j <= end - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (a[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  
        }  
    }  
    int t = a[i+1];  
    a[i+1] = a[end];  
    a[end] = t;  
    return (i + 1);  
}  



    void quick(int a[], int start, int end) /* a[] = array to be sorted, start = Starting index, end = Ending index */  
    {  
    if (start < end)  
    {  
        int p = partition(a, start, end);  //p is the partitioning index  
        quick(a, start, p - 1);  
        quick(a, p + 1, end);  
    }  
    }  

  
  //printing the array
  void print(int a[], int n)   
    {  
    int i;  
    for(i = 0; i < n; i++)    
    {    
        printf("%d ",a[i]);     
    }        
    }  


int main() {  

  int v;
  int q;
  int res; 

  cout<<"\n you want to perform: \n 1.sorting \n 2. searching \n";
  cin>>q;

if(q==1) 
  {
    int ar[] = {10, 13, 12, 50, 18, 19, 20, 21,22, 23, 24, 33, 35, 42, 47}; 
    int m = sizeof(ar) / sizeof(ar[0]); // size of array
    cout<<"The elements of the array are -> ";  
    for (int i = 0; i < m; i++)   
    cout<<ar[i]<<" ";

    cout<<"\n which type of sorting you want to perform: \n 1.Bubble \n 2.heap sort \n 3.quick sort "<<"\n";
    cin>>v;

    switch (v)
    { 
        case 1:
        bubble(ar, m); 
        print(ar, m); 

        case 2:
        heapSort(ar, m); 
        print(ar, m);

        case 3:
        quick(ar, 0, m - 1);
        print(ar, m);
    }

  }

  else
  { 
  int a[] = {10, 12, 13, 16, 18, 19, 20, 21,22, 23, 24, 33, 35, 42, 47}; // given array
  int val = 18; // value to be searched  
  int n = sizeof(a) / sizeof(a[0]); // size of array

  
  cout<<"The elements of the array are -> ";  
  for (int i = 0; i < n; i++)  
  cout<<a[i]<<" "; 

  cout<<"\n which type of searching you want to perform: \n 1.linear search \n 2.binary search \n 3.interpolation \n 4. exponential search"<<"\n";
  cin>>v;
  
  switch (v)
  {
  
  case 1:
  cout<<"\nElement to be searched by linear search is -> "<<val;    
  res = linearSearch(a, n, val); // Store result  
  break;  
  
  case 2:
  cout<<"\nElement to be searched by binary search is -> "<<val;  
  res = binarySearch(a, 0, n-1, val); // Store result 
  break;

  case 3:
  cout<<"\nElement to be searched by interpolation search is -> "<<val;
  res = interpolationSearch(a, n, val);
  break;

  case 4:
   cout<<"\nElement to be searched by exponential search is -> "<<val;
   res = exponentialSearch(a, n, val);
  }

  if (res == -1)  
  cout<<"\nElement is not present in the array";  
  else  
  cout<<"\nElement is present at "<<res<<" position of array"; 
  
  }
  

}  