def removeConsecutiveDuplicates(string):
    i = 0
    while i < len(string):
        while i + 2 < len(string) and string[i] == string[i + 1]:
            string = string[0: i + 1] + string[i + 2: len(string)]
        i += 1
    return string
s = "aabccbaa"
a = "baabbsbbahsahbahshhbhsjjjj"
print(removeConsecutiveDuplicates(s))
print(removeConsecutiveDuplicates(a))
