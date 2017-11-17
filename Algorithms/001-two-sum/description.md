## 题目描述

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].

## 方案一

1. 检查当前元素 `p` 与其后每个元素的和是否等于`target`，如果有相等的元素对，则返回。
2. 将当前元素变为当前元素的下一个元素，重复步骤一中的操作。
3. 如果前两步都没有找到，则抛出错误。

时间复杂度: O(n^2)
空间复杂度: O(1)

## 方案二

1. 创建`Map`数据结构
2. 以数组的值为`key`, 以索引为 `value`，将数组的所有元素存储到 `Map` 中
3. 遍历数组的前`n-1`个元素
4. 判断当前元素与`target`的差值是否存在`Map`中
5. 如果存在，则返回结果
6. 如果不存在继续步骤`3`
7. 返回失败结果

时间复杂度: O(n)
空间复杂度: O(n)


## 方案三

1. 创建`Map`数据结构
2. 将数组第1个元素与`target`的差值存入`Map`
3. 从第2个元素开始遍历数组
4. 判断当前元素是否存在于`Map`中
5. 如果存在则返回结果
6. 如果不存在继续步骤`3`
7. 返回失败结果

时间复杂度: O(n)
空间复杂度: O(n)
