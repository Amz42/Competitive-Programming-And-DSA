### Minimum no. of operations required to make an array palindrome

```c++
// Question: https://app.glider.ai/practice/problem/basic-programming/make-array-palindrome/problem

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define false 0
#define true 1
typedef int bool;



/*
 * implement method/function with name 'merge' below.
 *
 * The function is expected to return a value of type int.
 * The function accepts following parameters:
 * 1. ar is of type int.
 */


int  merge(int ar_count,int ar[ar_count]) {
    //Write your code here
    
    int n = ar_count;
    
    int answer = 0;
    int l = 0, r = n-1;
    
    while(l<r){
        if(ar[l] == ar[r]){
            l++, r--;
            continue;
        }
        
        if(ar[l] < ar[r]){
            ar[l+1] += ar[l];
            l++;
        }else{
            ar[r-1] += ar[r];
            r--;
        }
        answer++;
    }

    return answer;
}

int main()
{
    FILE* fout = fopen(getenv("OUTPUT_FILE_PATH"),"w");
    fprintf(fout,"\n");
    fclose(fout);
    fout = fopen(getenv("OUTPUT_FILE_PATH"),"a");

    int i,j;
    size_t nbytes = 1024;
    char *lineInput;

    lineInput = (char *) malloc (nbytes + 1);
    getline(&lineInput, &nbytes, stdin);
    int ar_count = strtol(lineInput,NULL,10);
    char* ar_rest;
    ar_rest = (char *) malloc (nbytes + 1);
    getline(&ar_rest, &nbytes, stdin);
    int ar[ar_count];
    for(i=0;i<ar_count;i++) {
        char* token = strtok_r(ar_rest, " ", &ar_rest);
        ar[i] = strtol(token,NULL,10);
    }

    int outcome = merge( ar_count,ar);

    fprintf(fout,"%d",outcome);
    fprintf(fout,"\n");
    fclose(fout);

    return 0;
}
```