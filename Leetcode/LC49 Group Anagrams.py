class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        arr = {}
        count = 0
        for s in strs:
            #print('count =' + str(count))
            a = list(s)
            a.sort()
            a = "".join(a)
            if len(arr) != 0:
                if a not in arr.keys():
                    arr[a] = count
                    count += 1
                    
            else:
                arr[a] = count
                count +=1
        ans = []
       # print(len(arr))
        for x in range(len(arr)):
            ans.append([])
        for s in strs:
            a = list(s)
            a.sort()
           # print(a)
            a = "".join(a)
            ans[arr[a]].append(s)
        return ans
            
            