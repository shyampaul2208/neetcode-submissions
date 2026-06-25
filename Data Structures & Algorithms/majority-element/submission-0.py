class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        mp = {}
        for i in range(len(nums)):
            mp[nums[i]] = 1+ mp.get(nums[i], 0)
        
        for key, value in mp.items():
            if value > len(nums)/2:
                return key




