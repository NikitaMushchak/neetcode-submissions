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

func Merge(left [] int, right [] int) [] int {
    var merged [] int

    if left[0] < right[1] {
        merged = append(left, right...)
    } else {
        merged = append(right, left...)
    }
    return merged
}

func mergeSort(nums []int) [] int {

    if len(nums) < 2 {
        return nums
    }

    mid := len(nums) / 2

    left := nums[:mid]
    right := nums[mid:]

    left = mergeSort(left)
    right = mergeSort(right)

    return Merge(left, right)
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
