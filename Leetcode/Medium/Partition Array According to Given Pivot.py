class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        res = []
        for x in nums:
            if(x < pivot):
                res.append(x)
        for x in nums:
            if(x == pivot):
                res.append(x)
        for i in nums:
            if(i > pivot):
                res.append(i)
        return res
