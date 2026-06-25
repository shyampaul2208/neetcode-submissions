class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if(len(strs)==1):
            return strs[0]
        output = ""
        index = 0
        while(True):
            can_pass = True
            for j in range(1,len(strs)):
                if index >= len(strs[j]) or index >= len(strs[j-1]):
                    return output
                if(strs[j][index]!=strs[j-1][index]):
                    can_pass = False
                    return output

            if can_pass:
                output+=strs[0][index]
                index+=1;


            

                
                    