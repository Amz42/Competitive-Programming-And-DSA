### GeeksForGeeks - Vertical sum

[Question](https://practice.geeksforgeeks.org/problems/vertical-sum/1/)
| [Solution](https://practice.geeksforgeeks.org/viewSol.php?subId=a47bc73a2140749349cf21aef7247530&pid=700602&user=amanguptarkg6)

##### C++
```c++
class Solution{
    int left;
    unordered_map<int,int> mp;
    void fun(Node* node, int index){
        if(node == NULL) return;
        left = min(left, index);
        mp[index] += node->data;
        fun(node->left, index - 1);
        fun(node->right, index + 1);
    }
public:
    vector <int> verticalSum(Node *root) {
        left = 0; mp.clear();
        fun(root, 0);
        
        vector<int> answer;
        while(mp[left] > 0)
            answer.push_back(mp[left++]);
        return answer;
    }
};
```