### GeeksForGeeks - Majority Element

[Question](https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=258c3c650c2b7981c0dc44c457c9917b&pid=701220&user=amanguptarkg6)

##### C++
```c++
int majorityElement(int a[], int size){
    int e = a[0];
    int count = 1;
    
    for(int i=1;i<size;i++){
        if(a[i]==e) count++;
        else{
            count--;
            if(count==0) e = a[i], count =1;
        }
    }
    
    count = 0;
    
    for(int i=0;i<size;i++){
        if(a[i]==e) count++;
    }
    
    if(count>size/2) return e;
    return -1;
}
```