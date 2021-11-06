### GeeksForGeeks - Reverse words in a given string

[Question](https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=c2013823762027d3a677d8aec62e9257&pid=701308&user=amanguptarkg6)

#### C++
```c++
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution{
    void reverse(string& s, int start, int end){
        while(start < end)
            swap(s[start++], s[end--]);
    }
public:
    string reverseWords(string s){
        int n = s.size();
        reverse(s, 0, n-1);
        
        for(int i=0;i<n;){
            int j = i;
            while(j+1 < n && s[j+1] != '.') j++;
            reverse(s, i, j);
            i = j + 2;
        }
        
        return s;
    } 
};
```