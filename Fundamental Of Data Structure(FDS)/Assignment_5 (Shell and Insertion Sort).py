"""
    Problem Statement::
        Write a Python program to store second year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
            a)	Insertion sort
            b)	Shell Sort and display top five scores

"""
class sort:
    def __init__(self):
        self.list=[]
        self.length=0
    def get_array(self):
        l = int(input("Enter the total number of students "))
        for i in range(l):
            a=float(input("Enter the marks of student"))
            self.list.append(a)
        self.length=l

    def disp_array(self):
        if(self.length==0):
            print("Empty")
        else:
            print(self.list)


    def insertion_sort(self):
        for i in range(1,self.length):

            x = self.list[i]
            j = i - 1
            while j > -1 and self.list[j]>x:
                self.list[j + 1] = self.list[j]
                j -= 1
            self.list[j + 1] = x

    def shell_sort(self):
        g=self.length//2
        while(g>0):
            for i in range(g,self.length):
                x=self.list[i]
                j=i
                while(j>=g and self.list[j-g]>x):
                    self.list[j]=self.list[j-g]
                    j=j-g
                self.list[j]=x
            g=g//2

    def top(self):
        if(self.length<5):
            print("You have to enter marks for atleast 5 students")
        else:
            print("Top 5 percentages are")
            cnt=0
            j=self.length-1
            while(cnt!=5):
                print(self.list[j])
                j=j-1
                cnt=cnt+1



    
b=sort()
k=0


print("MENU")
print("---------------------------")
print("1: Add an array")
print("2: Display an array")
print("3: Sort the array")

print("4 Top 5 percentage")
print("-1: To exit")
print("---------------------------")
while(True):
    ch=int(input("Enter your choice"))
    if(ch==1):
        b.get_array()
        k=k+1
        print("---------------------------")

    elif(ch==2):

        b.disp_array()
        print("---------------------------")
        print()
    elif(ch==3):
        print("1:Insertion sort \n 2:Shell sort")
        ch=int(input("Which sort method is to be used"))
        if(ch==1):
            if(k==0):
                print("No marks are added")
            else:
                b.insertion_sort()
                print("Marks are sorted")
                b.disp_array()
        elif(ch==2):
            if(k==0):
                print("No marks are added")
            else:
                print("Marks are sorted")
                b.shell_sort()
                b.disp_array()
        else:
            print("Wrong choice Please enter valid choice")


        print("---------------------------")





    elif(ch==4):
        b.top()
        print("---------------------------")

    elif(ch==-1):
        break


    else:
        print("wrong choice !!")
        print()
