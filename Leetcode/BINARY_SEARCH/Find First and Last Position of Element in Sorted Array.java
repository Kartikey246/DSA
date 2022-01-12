class Solution {
public:
     vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int start=0,end=nums.size()-1,mid,first=-1,second=-1;
        
        //first occurance
        while(start<=end)
        {
            mid=start+(end-start)/2;
            
            if(nums[mid]==target)
            {
                first=mid;
                end=mid-1;
            }
            
            else if(nums[mid]>target)
                end=mid-1;
            
            else if(nums[mid]<target)
                start=mid+1;
        }
        ans.push_back(first);
        start=0,end=nums.size()-1;
        
        
        //last occurance
        while(start<=end)
        {
         mid=start+(end-start)/2;
            
            if(nums[mid]==target)
            {
                second=mid;
                start=mid+1;
            }
            
            else if(nums[mid]>target)
                end=mid-1;
            
            else if(nums[mid]<target)
                start=mid+1;
        }
        ans.push_back(second);
           
        return ans;
    }
};
