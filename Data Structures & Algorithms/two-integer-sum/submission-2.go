func twoSum(nums []int, target int) []int {
    m := make(map[int]int)

	for i, num := range nums {
		m[num] = i
	}

	for i := 0; i < len(nums); i++ {
		complement := target - nums[i]

		if idx, ok := m[complement]; ok && idx != i {
			return []int{i, idx}
		}
	}
	return []int{}
}
