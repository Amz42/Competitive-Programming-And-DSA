### Quick Sort

##### C++
```c++
// Question: https://practice.geeksforgeeks.org/problems/quick-sort/1
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=91db6130868834191cbb7942e4bd2138&pid=700151&user=amanguptarkg6

class Solution{
public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high){
        if(high - low < 1) return;
        int index = partition(arr, low, high);
        quickSort(arr, low, index-1);
        quickSort(arr, index+1, high);
    }
public:
    int partition (int arr[], int low, int high){
       int pivot = arr[high];
       int p = low - 1;
       
       for(int i=low;i<high;i++){
           if(arr[i] < pivot)
                swap(arr[++p], arr[i]);
       }
       
       swap(arr[++p], arr[high]);
       
       return p;
    }
};
```