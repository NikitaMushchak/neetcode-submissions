import "slices"
func isAnagram(s string, t string) bool {
	if len(s) != len(t) || len(s) == 0 {
		return false
	}

	// sort s and t and then compare them

	rs := []rune(s)
	rt := []rune(t)

	slices.Sort(rs)
	slices.Sort(rt)

	return slices.Equal(rs, rt)
}
