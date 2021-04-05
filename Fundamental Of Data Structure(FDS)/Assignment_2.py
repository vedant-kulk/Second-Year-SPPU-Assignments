"""
   Problem Statement
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


# class String:
#     def __init__(self,arr):
#         self.length = 0
#         self.list = []
#         for i in arr:
#             self.list.append(i)
#             self.length = self.length + 1
#
#     def add(self,val):
#         self.list.append(val)
#
#     def remove(self,val):
#         self.list.remove(val)
#         self.length-=1
#
#     def list_strings(self):
#         l=String([])
#         a = []
#         for i in self.list:
#             if (i != ' '):
#                 a.append(i)
#             else:
#                 l.add(a)
#                 a = []
#                 l.length+=1
#         l.add(a)
#         l.length += 1
#         return l
#
#     def longest(self):
#         max = 0
#         for i in range(self.list_strings().length):
#             c = 0
#             for j in self.list_strings().list[i]:
#                 c += 1
#             if (max < c):
#                 max = c
#                 g = self.list_strings().list[i]
#         print("Longest Word is '",end="")
#         for i in range(max):
#             print(g[i],end="")
#         print("' and its length is",max)
#
#
#     def frequency(self,i):
#         count = 0
#         for j in self.list:
#             if (j == i[0]):
#                 count += 1
#         print("Frequency of '",end="")
#         for j in i:
#             print(j,end="")
#         print("' is",count)
#
#     def palindrome(self):
#         c=0
#         for i in range(self.length):
#             if (self.list[i] == self.list[self.length - 1 - i]):
#                 c=c+1
#         if(c==self.length):
#             print("Palindrome")
#         else:
#             print("Not a palindrome")
#
#     def exists(self,val):
#         for i in self.list:
#             if(i==val):
#                 return True
#         return False
#
#     def remove_duplicates(self):
#         unique=String([])
#         for i in range(self.list_strings().length):
#             if(unique.exists(self.list_strings().list[i])==False):
#                 unique.add(self.list_strings().list[i])
#                 unique.length+=1
#         for i in range(unique.length):
#                 if (unique.list[i] == [] ):
#                     unique.remove(unique.list[i])
#         return unique
#
#     def word_freq(self):
#         for i in range(self.remove_duplicates().length):
#             count=0
#             for j in range(self.list_strings().length):
#                 if(self.remove_duplicates().list[i]==self.list_strings().list[j]):
#                     count+=1
#
#             print("Frequency of '",end="")
#             for j in self.remove_duplicates().list[i]:
#                 print(j,end="")
#             print("' =======>",count)
#
#     def index(self,s2):
#             c=0
#             for i in range(self.length):
#                 d = 0
#                 for j in range(s2.length):
#                     if(i+j<self.length):
#                         if (self.list[i + j] == s2.list[j]):
#                             d = d + 1
#                         if d == s2.length:
#                             break
#                 if (d == s2.length):
#                     print("Index of '",end="")
#                     for j in s2.list:
#                         print(j,end="")
#                     print("' is",i)
#                     c=c+1
#                     break
#             if(c==0):
#                 print("Not Present in the String")
#
#
# a = list(input("Enter the string\n"))
# s = String(a)
#
# print("\n--------------------------------------------------------------------\n")
# print("Choices:\n1-To display word with the longest length \n2-To determines the frequency of occurrence of particular character in the string\n3-To check whether given string is palindrome or not\n4-To display index of first appearance of the substring\n5-To count the occurrences of each word in a given string")
# print("\n--------------------------------------------------------------------\n")
# while(True):
#     choice = int(input("Enter your choice:\n"))
#     if choice==1:
#         s.longest()
#
#     elif choice==2:
#         a=list(input("Enter the character for which you want to find frequency:\n"))
#         s.frequency(a)
#
#     elif choice==3:
#         s.palindrome()
#
#     elif choice==4:
#         s2=String(list(input("Enter the substring you want to find out:\n")))
#         s.index(s2)
#     elif choice ==5:
#         print("Frequency of each word:\n")
#         s.word_freq()
#
#     elif(choice<1 or choice>5 or choice!=0):
#         print("Please enter proper choice")
#
#     print("-------------------------------------------------------------------")
#     while(True):
#         wish=input("Do you wish to continue further? Y/N\n")
#         if (wish.upper() == "N"):
#             print("Exit Successful\nThank You")
#             exit()
#         elif(wish.upper()=="Y"):
#             break
#         else:
#             print("Please give correct input\n")
#             continue
#    print("\n-------------------------------------------------------------------")