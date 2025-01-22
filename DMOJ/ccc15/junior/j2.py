string = str(input())



str1 = string.replace(":-)", "")
str2 = string.replace(":-(", "")

if len(str1) < len(str2):
    print("happy")
elif len(str1) == len(str2) and len(str1) != len(string):
    print("unsure")
elif len(str1) == len(string) and len(str2) == len(string):
    print("none")
else:
    print('sad')
