class Solution:
    def majorityElement(self, nums: List[int]) -> int:

        count =0
        num = None
        for i in range(len(nums)):
            if (count == 0):
                print(nums[i])
                num = nums[i]
                count =1
            else:
                if nums[i]==num:
                    count+=1
                else:
                    count-=1
            
        return num








