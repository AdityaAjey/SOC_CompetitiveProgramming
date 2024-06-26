class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> mySet;  
        for(int i=0;i<nums.size();i++){
            if(myset.count(nums[i])>0){
                return true;
            }
            mySet.insert(nums[i]);
        }
    }
};