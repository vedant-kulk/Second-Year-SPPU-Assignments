"""
    Problem Statement::
        a)	Write a Python program to store roll numbers of student in array
            who attended training program in random order. Write function for searching 
            whether particular student attended training program or not, using Linear search and Sentinel search.
"""
class search:
    def __init__(self):

        self.length=0
    def get_array(self):
        self.list = []
        l=int(input("Enter the total number of students who attended the program"))
        for i in range(l):
            a=int(input("Enter the roll numbers who attended the program"))
            self.list.append(a)
        self.length=l

    def disp_array(self):
        print(self.list)

    def linear(self,ele):
        for i in range(self.length):
            if(self.list[i]==ele):
                return i
        return -1


    def sentinel(self,ele):
        last=self.list[self.length-1]
        self.list[self.length - 1]=ele
        j=0
        while(self.list[j]!=ele):
            j=j+1
        self.list[self.length - 1]=last

        if((j<self.length-1) or (self.list[self.length-1]==ele)):
            return j
        return -1


c=search()

print("MENU")
print("---------------------------")
print("1: Add an array")
print("2: Display an array")
print("3: Search the element by linear search")
print("4: Search the element by Sentinel search")
print("---------------------------")
while(True):
    ch=int(input("Enter your choice"))
    if(ch==1):
        c.get_array()
        print("---------------------------")
    elif(ch==2):
        c.disp_array()
        print("---------------------------")
    elif(ch==3):
        ele=int(input("Which roll no is to be searched"))
        y=c.linear(ele)
        if(y!=-1):
            print("This student attended the training program and present at index :",y)
        else:
            print("This student did not attended")
        print("---------------------------")
    elif(ch==4):
        ele = int(input("Which roll no is to be searched"))
        z=c.sentinel(ele)
        if (z != -1):
            print("This student attended the training program and present at index :", z)
        else:
            print("This student did not attended")
        print("---------------------------")
    print()
    print()
    choice=input("Do you want to continue Y/N")
    if(choice=='Y'):
        continue
    else:
        break


