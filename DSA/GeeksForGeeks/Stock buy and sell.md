### Stock buy and sell

##### C++
```c++
// Question: https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1#
// Solution: https://practice.geeksforgeeks.org/viewSol.php?subId=4cb851c3cc7fad5a692d8397efbba981&pid=701212&user=amanguptarkg6

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        vector<pair<int,int>> v;
        v.push_back({0, 0});
        
        for(int i=1;i<n;i++){
            if(A[i] > A[v.back().second])
                v.back().second = i;
            else
                v.push_back({i, i});
        }
        
        vector<vector<int>> answer;
        for(auto k: v)
            if(k.first != k.second)
                answer.push_back(vector<int>{k.first, k.second});
        
        return answer;
    }
};
```