"""
   Problem Statement::
        Write a Python program to compute following operations on String:
            a)	To display word with the longest length
            b)	To determines the frequency of occurrence of particular character in the string
            c)	To check whether given string is palindrome or not
            d)	To display index of first appearance of the substring
            e)	To count the occurrences of each word in a given string

"""
class string:
    def frequency(self,s,char):
        cnt=0
        for i in s:
            if(i==char):
                cnt+=1
        return cnt
    def substr(self,str):
        w = ""
        all = []
        d=[]
        str = str + " "
        for i in range(0,len(str)):
            if (str[i] != ' '):
                w = w + str[i]
            else:
                all.append(w)
                w = ""
        for i in all:
            if(i not in d):
                d.append(i)
            else:
                continue
        for j in d:
            cnt=0
            for k in all:
                if(j==k):
                    cnt+=1
            print("the occurence of",j,"is:",cnt)
    def index(self,s,sub):
        l=len(sub)
        for i in range(len(s)):
            if(s[i:i+l]==sub):
                return i
    def is_palindrome(self,str):
        l=len(str)
        rev=""
        while l>0:
            rev+=str[l-1]
            l=l-1
        if(rev==str):
            return True
        else:
            return False
    def long_word(self,str):
        w = ""
        all = []
        str = str + " "
        for i in range(0, len(str)):
            if (str[i] != ' '):
                w = w + str[i]
            else:
                all.append(w)
                w= ""

        large = all[0]
        for j in all:
            if(len(j)>len(large)):
                large=j
        return large


a=string()
print("Operations")
print("1-> Enter a string to display a word with longest length")
print("2-> Enter a string to determine the frequency of occourence of particular character")
print("3-> Enter a string to check whether it is palindrome or not")
print("4-> Enter a string and substring to check the index of first appearance of substring")
print("5-> Enter a string to see the occurence of each word in the string")
print("======")
print()
while(True):
    ch=int(input("Enter your choice"))
    if(ch==1):
        str=input("Enter the string")
        print(a.long_word(str))
    elif(ch==2):
        str=input("Enter the string")
        char=input("Enter the character")
        print(a.frequency(str,char))
    elif(ch==3):
        str=input("Enter the string ")
        print(a.is_palindrome(str))
    elif(ch==4):
        str = input("Enter the string ")
        sub=input("Enter the substring ")
        print(a.index(str,sub))
    elif(ch==5):
        str = input("Enter the string ")
        print(a.substr(str))
    else:
        break
    print()
    print("enter 0 to exit")
