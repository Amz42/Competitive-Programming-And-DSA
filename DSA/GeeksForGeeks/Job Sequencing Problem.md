### GeeksForGeeks - Job Sequencing Problem

[Question](https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=854746842853f27a40fe5784890ff984&pid=701367&user=amanguptarkg6)

##### C++
```c++
struct comp{
    bool operator()(Job const& x, Job const& y){
        return x.profit < y.profit;
    }
};

class Solution {
    public:
    vector<int> JobScheduling(Job a[], int n){
        // sort in descending accd. to deadline
        sort(a, a+n, [](Job& x, Job& y){
            return x.dead > y.dead;
        });
        
        priority_queue<Job, vector<Job>, comp> mxheap;
        
        int jobsDone = 0, totalProfit = 0;
        for(int i=0;i<n;i++){
            int slots = a[i].dead - (i+1 < n ? a[i+1].dead : 0);
            mxheap.push(a[i]);
            
            while(slots-- && mxheap.size() > 0){
                auto k = mxheap.top(); mxheap.pop();
                jobsDone++;
                totalProfit += k.profit;
            }
        }
        
        return (vector<int>{jobsDone, totalProfit});
    } 
};
```