## Coding Ninja - Minimum Number Of Taps To Water Garden

### [Question](https://www.codingninjas.com/codestudio/problems/minimum-number-of-taps-to-water-garden_873369)

### C++ Solution
```c++
int minimumTapsToFillGarden(vector<int> &ranges, int n) {
    vector<int> jumps(n+1, -1);
	
	for(int i=0;i<=n;i++) {
		int l = max(0, i - ranges[i]);
		int r = min(n, i + ranges[i]);	
		jumps[l] = max(jumps[l], r);
	}
	
	int i = 0, answer = 1;
	int curr_reach = jumps[0];
	while(curr_reach < n) {
		int max_reach = curr_reach;
		while(i <= curr_reach)
			max_reach = max(max_reach, jumps[i++]);
		
		if(max_reach == curr_reach)
			return -1;
		
		curr_reach = max_reach;
		answer++;
	}
	
	return answer;
}
```