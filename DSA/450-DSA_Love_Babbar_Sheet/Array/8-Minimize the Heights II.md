## [Minimize the Heights II](https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1)

#### Solution 1: C++ Sliding Window
```c++
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        vector<pair<int,int>> heights;
        
        for(int i = 0; i < n; i++) {
            if (arr[i] - k >= 0) 
                heights.push_back(make_pair(arr[i] - k, i));
            heights.push_back(make_pair(arr[i] + k, i));
        }
        
        sort(heights.begin(), heights.end());
        
        int answer = INT_MAX;
        int l = 0, r = 0;
        int uniqueBuildingsInsegment = 0;
        vector<int> freq(n, 0);
        while(r < heights.size()) {
            freq[heights[r].second]++;
            // adding this building increased unique building count
            if (freq[heights[r].second] == 1) uniqueBuildingsInsegment++;
            // adding this building covered n buildings in the segment
            while (uniqueBuildingsInsegment == n)  {
                answer = min(answer, heights[r].first - heights[l].first);
                freq[heights[l].second]--;
                if (freq[heights[l].second] == 0) uniqueBuildingsInsegment--;
                l++;
            }
            r++;
        }
        
        return answer;
    }
};
```