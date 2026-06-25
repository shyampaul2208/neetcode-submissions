class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        # print(''.join(sorted(strs[0])))
        hash_map = defaultdict(list)
        for i in range(len(strs)):
            hash_map[''.join(sorted(strs[i]))].append(strs[i])
        
        ans =[]
        for key, value in hash_map.items():
            ans.append(value)
        
        return ans
        

        