## GeeksForGeeks - Non Repeating Character

### [Question](https://practice.geeksforgeeks.org/problems/non-repeating-character-1587115620/1)

### [C++ Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=86402aa563a1e0d3cff9bbc2fc693313&pid=701322&user=amanguptarkg6)
```c++
class Solution{
public:
    char nonrepeatingCharacter(string S) {
        vector<pair<int,int>> count(256, make_pair(0, -1));
        
        for(int i = 0; i < S.size(); i++) {
            char ch = S[i];
            count[ch].first++;
            if(count[ch].first == 1) 
                count[ch].second = i;
        }
        
        
        int pos = S.size();
        char answer = '$';
        for(int i = 0; i < 256; i++)
            if(count[i].first == 1 && count[i].second < pos)
                pos = count[i].second,
                answer = i;
        
        return answer;
    }
};
```