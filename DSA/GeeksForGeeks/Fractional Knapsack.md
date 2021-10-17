### GeeksForGeeks - Fractional Knapsack

[Question](https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=6d88e72837a4685552636fc4378bd620&pid=701365&user=amanguptarkg6)

##### C++
```c++
class Solution{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item a[], int n){
        double profit = 0;
        
        sort(a, a+n, [&](Item& x, Item& y){
            return ((double)x.value/x.weight) > ((double)y.value/y.weight);
        });
        
        int i=0;
        while(W > 0 && i < n){
            double take = min(W, a[i].weight);
            W -= take;
            profit += (a[i].value * take / a[i].weight);
            i++;
        }
        
        return profit;
    }
};
```