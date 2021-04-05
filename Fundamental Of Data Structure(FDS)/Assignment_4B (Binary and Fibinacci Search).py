"""
    Problem Statement::
        a)	Write a Python program to store roll numbers of student in array
            who attended training program in random order. Write function for searching 
            whether particular student attended training program or not, using Binary search and Fibonacci search.
"""
class search:
    def __init__(self):
        self.list=[]
        self.length=0
    def get_array(self):
        l = int(input("Enter the total number of students who attended the program"))
        for i in range(l):
            a=int(input("Enter the roll numbers who attended the program"))
            self.list.append(a)
        self.length=l

    def disp_array(self):
        print(self.list)

    def binary(self,ele):
        low=0
        high=(self.length)-1
        while(low<=high):
            mid=(low+high)//2
            if self.list[mid] == ele:
                return mid                         #left
            elif self.list[mid] > ele:
                high = mid - 1
            else:
                low = mid + 1
        return -1

    def fibo_search(self,ele):
        f0=0
        f1=1
        Fib=f0+f1

        while(Fib<self.length):
            f0=f1
            f1=Fib
            Fib=f0+f1

        offset=-1
        while Fib>1:
            i=min(offset+f0,self.length-1)
            if(self.list[i]<ele):
                Fib=f1
                f1=f0
                f0=Fib-f1
                offset=i
            elif self.list[i]>ele:
                Fib=f0
                f1=f1-f0
                f0=Fib-f1
            else:
                return i

        if(f1 and self.list[offset+1]==ele):
            return offset+1


        return -1
c=search()
print("MENU")
print("---------------------------")
print("1: Add an array")
print("2: Display an array")
print("3: Search the element by Binary search")
print("4: Search the element by Fibonacci search")
print("-1: To exit")
print("---------------------------")
while(True):
    ch=int(input("Enter your choice"))
    if(ch==1):
        c.get_array()
        print("---------------------------")
        print()
    elif(ch==2):
        c.disp_array()
        print("---------------------------")
        print()
    elif(ch==3):
        ele=int(input("Which roll no is to be searched"))
        y=c.binary(ele)
        if(y!=-1):
            print("This student attended the training program and present at index :",y)
        else:
            print("This student did not attended")
        print("---------------------------")
    elif (ch == 4):
        ele = int(input("Which roll no is to be searched"))
        z = c.fibo_search(ele)
        if (z != -1):
            print("This student attended the training program and present at index :", z)
        else:
            print("This student did not attended")
        print("---------------------------")
        print()
    elif (ch==-1):
        break
    else:
        print("wrong choice !!")
        print()




