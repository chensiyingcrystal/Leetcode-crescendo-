"""Leetcode problem1 TwoSums"""
# def twosums(nums, target):
#     for i in range(0, len(nums)):
#         for j in range(i + 1, len(nums)):
#             if nums[i] + nums[j] == target:
#                 return [i, j]


def twosums(nums, target):
    output = {}
    for i in range(0, len(nums)):
        if (target - nums[i]) in output:
            return [target - nums[i], i]
        else:
            output[nums[i]] = i


nums = [2, 7, 11, 15]
target = 9
print(twosums(nums, target))