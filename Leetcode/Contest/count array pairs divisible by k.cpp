class Solution {
public:
    int count[100001];
    int count_of_multiples[100001];
    
    long long coutPairs(vector<int>& nums, int k) {
        int n=nums.size();

        for(int i=0;i<n;i++)  count[nums[i]]++;  // counting frequency of elements
        
        for(int i=1;i<100001;i++){
            for(int j=i;j<100001;j=j+i)  count_of_multiples[i]+=count[j]; //counting total elements present in array which are multiple of i
        }
        
        long long ans=0;
        for(int i=0;i<n;i++){
            long long factor=__gcd(k,nums[i]);
            long long remaining_factor= ( k / factor);
            long long j = count_of_multiples[remaining_factor];
            if(nums[i]%remaining_factor==0)j--;        // if nums[i] itself is multiple of remaining factor then we to ignore it as  i!=j
            ans+=j;
        }
        
        ans/=2;  // as we have counted any distinct pair (i,j) two times , we need to take them only once
        return ans;
    }
};
