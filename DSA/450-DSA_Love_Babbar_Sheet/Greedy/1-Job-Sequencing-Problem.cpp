// Question: https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=009cf143310c82596529d09e98a136dd&pid=701367&user=amanguptarkg6

// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

// Prints minimum number of platforms reqquired 

bool job_sort(struct Job a, struct Job b){
    return a.profit > b.profit;
}

pair<int,int> JobScheduling(Job arr[], int n){
    int profit = 0, numjobs = 0;
    
    sort(arr, arr+n, job_sort);
    
    set<int> deadline;
    for(int i=1;i<=100;i++) deadline.insert(-i);
    
    for(int i=0;i<n;i++){
        Job k = arr[i];
        auto it = lower_bound(deadline.begin(), deadline.end(), -k.dead);
        if(it!=deadline.end()){
            deadline.erase(*it);
            profit += k.profit;
            numjobs++;
        }
    }
    
    return make_pair(numjobs, profit);
}

int main(){
    int t; cin >> t; while(t--){
        int n; cin >> n;
        Job arr[n];
        
        for(int i = 0;i<n;i++){
            int x, y, z; cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        pair<int,int> ans = JobScheduling(arr, n);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
	return 0; 
}