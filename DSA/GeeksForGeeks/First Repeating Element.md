### First Repeating Element

##### C++

```c++
// Question: https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1

// Solution-1: https://practice.geeksforgeeks.org/viewSol.php?subId=832d18277c83f68be1ca0355d9728ab6&pid=701716&user=amanguptarkg6

// Time: O(nlogn)
// Space: O(n)
class Solution1 {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
            v.push_back(make_pair(arr[i], i+1));
        
        sort(v.begin(), v.end(), [](pair<int,int>& x, pair<int,int>& y){
            return (
                x.first == y.first
                ? x.second < y.second
                : x.first < y.first
            );
        });
        
        int answer = n+1;
        for(int i=0;i<n-1;i++)
            if(v[i].first == v[i+1].first)
                answer = min(answer, v[i].second);
        
        return answer == n+1 ? -1 : answer;
    }
};


// Soltuion-2: https://practice.geeksforgeeks.org/viewSol.php?subId=4044494be352186f8deab8d20b59eb65&pid=701716&user=amanguptarkg6

// Time: O(n)
// Space: O(n)
class Solution2 {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        unordered_map<int,int> mp;
        
        int answer = n+1;
        
        for(int i=0; i<n; i++){
            if(mp[arr[i]])
                answer = min(answer, mp[arr[i]]);
            else
                mp[arr[i]] = i + 1;
        }
        
        return answer == n+1 ? -1 : answer;
    }
};
```