class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        bucket = set()
        for ele in nums:
            if ele in bucket:
                return True
            
            bucket.add(ele)
        
        return False
        