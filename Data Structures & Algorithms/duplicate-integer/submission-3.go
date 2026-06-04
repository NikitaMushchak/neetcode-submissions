func sortArray(nums [] int) [] int {
    var bubble int
    sorted  := nums
    for i := 1; i < len(sorted); i++ {
        for j := 0; j < len(sorted) - i; j++ {
            if sorted[j] > sorted[j + 1] {
                bubble = sorted[j]
                sorted[j] = sorted[j + 1]
                sorted[j + 1] = bubble
            }
        }
    }

    return sorted
}

func hasDuplicate(nums []int) bool {
    // sort and check current and next values
    sorted := sortArray(nums)

    for i := 1; i < len(sorted); i++ {
        if (sorted[i] == sorted[i-1]) {
            return true
        }
    }
    return false
}
