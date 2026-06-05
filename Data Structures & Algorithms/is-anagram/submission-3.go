func isAnagram(s string, t string) bool {
	if len(s) != len(t) || len(s) == 0 {
		return false
	}
	rs := []rune(s)
	rt := []rune(t)

	// first approach is brute force
	// we going to check if all letters from the other
	// appear

	for len(rs) > 0 {
		var firstS rune = rs[0]
		rs = rs[1:]
		for i, runeT := range rt {
			if firstS == runeT {
				// extract runeT from t
				rt = append(rt[:i], rt[i+1:]...)
				break
			}
		}
	}
	if len(rs) == 0 && len(rt) == 0 {
		return true
	}
	return false
}
