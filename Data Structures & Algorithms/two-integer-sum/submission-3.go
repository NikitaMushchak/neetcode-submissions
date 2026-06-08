func twoSum(nums []int, target int) []int {
    m := make(map[int]int)

	for i, num := range nums {
		complement := target - num
		if idx, ok := m[complement]; ok && i != idx {
			if i < idx {
				return []int{i, idx}
			} else {
				return []int{idx, i}
			}
		} else {
			m[num] = i
		}
	}
	return []int{}
}
