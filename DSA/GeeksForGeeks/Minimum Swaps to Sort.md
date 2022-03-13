## GeeksForGeeks - Minimum Swaps to Sort

### [Question](https://practice.geeksforgeeks.org/problems/minimum-swaps/1/)

### [C++ Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=b67b1ae50de0b32dc5889f83702191d1&pid=700384&user=amanguptarkg6)
```c++
class Solution {
private:
public:
	int minSwaps(vector<int>&nums){
	    int n = nums.size();
	    
	    vector<pair<int,int>> v(n);
	    for(int i=0;i<n;i++) v[i] = {nums[i], i};
	    sort(v.begin(), v.end());
	    
	    int answer = 0;
	    for(int i=0;i<n;i++){
	        if(v[i].second != i){
	            answer++;
	            swap(v[i], v[v[i].second]);
	            i--;
	        }
	    }
	    
	    return answer;
	}
};
```