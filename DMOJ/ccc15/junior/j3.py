string = str(input())

alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
alphabet_consonant = ['b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z']

vowels = ['a','e','i','o','u']

newString = ""
for char in string:
    if char not in vowels:
   
        vowel = ""
        best = 10000
        for let in alphabet:
            if let in vowels:
                if abs(alphabet.index(let) - alphabet.index(char)) < best:
                
                    best = abs(alphabet.index(let) - alphabet.index(char))
                   
                    vowel = let
                
        
        if alphabet_consonant[alphabet_consonant.index(char)] == 'z':
            newString += char + vowel + 'z'
        else:
            newString += char + vowel + alphabet_consonant[alphabet_consonant.index(char) + 1]
    else:
        newString += char
print(newString)