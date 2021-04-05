 """
  Problem Statement::
        In second year computer engineering class, group A student’s play cricket, group B students play badminton and group C students play football.
        Write a Python program using functions to compute following: -
            a)	List of students who play both cricket and badminton
            b)	List of students who play either cricket or badminton but not both
            c)	Number of students who play neither cricket nor badminton
            d)	Number of students who play cricket and football but not badminton.
        (Note- While realizing the group, duplicate entries should be avoided, Do not use SET built-in functions)
"""

class sports:
    all=[]
    cricket=[]
    badminton=[]
    football=[]
    def data(self):
        self.name=input("Enter name")
        sports.all.append(self.name)
        print("Add your sports detail")
        print("give input 0 for no and 1 for yes")
        c=int(input("do you play cricket"))
        b=int(input("do you play badminton"))
        f =int(input("do you play football"))
        if(c==1):
            sports.cricket.append(self.name)
        if(b == 1):
            sports.badminton.append(self.name)
        if(f == 1):
            sports.football.append(self.name)
n=int(input("total no of students"))
for i in range(0,n):
    s1=sports()
    s1.data()
print("=======")
print("operations")
print("1: Students playing both cricket and badminton")
print("2: Students playing either cricket or badminton but not both")
print("3: Students playing neither cricket not badminton")
print("4: Students playing criket and football but not badminton")
print("5: Finished")

print("==========")
print("list of students")
print("students playing cricket -> ",sports.cricket)
print("students playing badminton -> ",sports.badminton)
print("students playing football -> ",sports.football)

while(True):
    x = int(input("enter your choice"))
    if(x==1):
        cri_bad=[]
        for j in sports.cricket:
            if j in sports.badminton:
                cri_bad.append(j)
        print("These students play cricket and badminton : ",cri_bad)
    if(x==2):
        e=[]
        for j in sports.cricket:
            if j not in cri_bad:
                e.append(j)
        for j in sports.badminton:
            if j not in cri_bad:
                e.append(j)
        print("These students play either cricket or badminton: ",e)
    if(x==3):
        n=[]
        for j in sports.football:
            if (j not in sports.cricket and j not in sports.badminton):
                n.append(j)
        print("These students neither play cricket not football: ",n)
    if(x==4):
        t=[]
        cri_foot = []
        for j in sports.cricket:
            if j in sports.football:
                cri_foot.append(j)
        for j in cri_foot:
            if j not in sports.badminton:
                t.append(j)
        print("These students play only cricket and football: ",t)
    if(x==5):
        break