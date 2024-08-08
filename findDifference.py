class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        sets1 = set(nums1)
        sets2 = set(nums2)
        return (list(sets1 - sets2), list(sets2 - sets1))
        