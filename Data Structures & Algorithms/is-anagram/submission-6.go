import "maps"
func isAnagram(s string, t string) bool {
	if len(s) != len(t) || len(s) == 0 {
		return false
	}
	ms := make(map[rune]int)
	mt := make(map[rune]int)

	for _, runeS := range s {
		if num, ok := ms[runeS]; ok {
			num = num + 1
			ms[runeS] = num
		} else {
			ms[runeS] = 1
		}
	}

	for _, runeT := range t {
		if num, ok := mt[runeT]; ok {
			num = num + 1
			mt[runeT] = num
		} else {
			mt[runeT] = 1
		}
	}

	return maps.Equal(mt, ms)
}
