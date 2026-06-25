class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        for(int i =0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        vector<vector<int>> freq(nums.size()+1);
        for(auto x:mp){
            freq[x.second].push_back(x.first);
        }

        vector<int> ans;
        for(int i = freq.size()-1;i>=0;i--){
            if(freq[i].size()>0){
                for(int j=0;j<freq[i].size();j++){
                    ans.push_back(freq[i][j]);
                    if(ans.size()==k){
                        return ans;
                    }
                }
            }

        }

        return ans;

       
    
        

        
        
    }
};

// Time Complexity:O(nlogn); //you are sorting
// Space Complexity:o(3n);


//Bucket Sort
// based on how many time an element is repeating max an element can repeat for length of the array