func isAnagram(s string, t string) bool {
if len(s) != len(t) || len(s) == 0 {
		return false
	}

	letters := [26]rune{}

	for i := 0; i < len(s); i++ {
		letters[s[i]-'a']++
		letters[t[i]-'a']--
	}

	for _, val := range letters {
		if val != 0 {
			return false
		}
	}
	return true
}
