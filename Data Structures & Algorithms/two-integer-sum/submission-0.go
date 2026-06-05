func twoSum(nums []int, target int) []int {
	for i := 0; i < len(nums); i++ {
		complent := target - nums[i]
		for j := i + 1; j < len(nums); j++ {
			if complent == nums[j] {
				return []int{i, j}
			}
		}
	}
	return []int{}
}
