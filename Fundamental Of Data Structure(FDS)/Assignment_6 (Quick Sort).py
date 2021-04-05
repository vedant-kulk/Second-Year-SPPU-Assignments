"""
    Problem Statement::
        Write a Python program to store first year percentage of students in array.
        Write function for sorting array of floating point numbers in ascending order using quick sort
        and display top five scores.
"""
class sort:
    def __init__(self):
        self.list=[]
        self.length=0
    def get_array(self,x):
        for i in range(x):
            while(True):
                a = float(input("Enter the percentage of student ->"))
                if(a>0 and a<100):
                    self.list.append(a)
                    break
                else:
                    print("!!! Enter valid percentage")
        self.length=x


    def disp_array(self):
        if(self.length==0):
            print("Empty")
        else:
            print(self.list)



    def part(self,lp,hp):
        i=lp-1
        pivot=self.list[hp]                             # declaring pivot as the last element
        for j in range(lp,hp):
            if(self.list[j]<pivot):
                i+=1
                self.list[i],self.list[j]=self.list[j],self.list[i]
        self.list[i+1],self.list[hp]=self.list[hp],self.list[i+1]
        return i+1



        
    def quick_sort(self,l,h):
        if(l<h):
            par=self.part(l,h)
            self.quick_sort(l,par-1)
            self.quick_sort(par+1,h)



    def top(self):
        if(self.length<5):
            print("Enter percentage for atleast 5 students")
        else:
            print("TOP 5 PERENTAGE ARE")
            cnt = 0
            j = self.length - 1
            while (cnt != 5):
                print(self.list[j])
                j = j - 1
                cnt = cnt + 1
c=sort()
k=0
print("MENU")
print("1  : ADD STUDENTS PERCENTAGE ")
print("2  : SORT THE PERCENTAGE USING QUICK SORT AND DISPLAY TOP 5 SCORES")
print("-1 : BREAK ")
while(True):
    ch=int(input("Enter your choice"))
    if(ch==1):
        n=int(input("Total number of students : "))
        c.get_array(n)
        c.disp_array()
        k+=1
        print("-------------------------------------------------")
    elif(ch==2):
        if(k==0):
            print("NO PERCENTAGE ARE ADDED !!")
        else:
            c.quick_sort(0,n-1)
            c.disp_array()
            c.top()
            print("-------------------------------------------------")
    elif(ch==-1):
        break