func hasDuplicate(nums []int) bool {
    // brute force

    for i := range len(nums) {
        for j := i + 1; j < len(nums); j++ {
            if nums[i] == nums[j] {
                return true
            }
        }
    }
    return false
}
