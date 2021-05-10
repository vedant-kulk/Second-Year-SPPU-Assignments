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

class Set:
    def __init__(self,length):
        self.list=[]
        self.length=length

    def addelement(self):
        print("Enter the name of student:")
        a=0
        for i in range(self.length):
            val=input()
            if (self.exists(val) == False ):
                self.list.append(val)
                a = a + 1
        self.length=a

    def exists(self, val):
        for i in self.list:
            if (i == val):
                return True
        return False


    def union(self,b):
        Uni=Set(0)
        for i in self.list:
            Uni.list.append(i)
            Uni.length +=1
        for i in b.list:
            if(i not in Uni.list):
                Uni.list.append(i)
                Uni.length += 1
        return Uni

    def intersection(self,b):
        int=Set(0)
        for i in self.list:
            if(i in b.list):
                int.list.append(i)
                int.length += 1
        return int


    def difference(self,b):
        diff=Set(0)
        for i in self.list:
            if(i not in b.list):
                diff.list.append(i)
                diff.length+=1
        return diff

    def symmetric_difference(self,b):
        sym=Set(0)
        x=self.union(b).list
        y=self.intersection(b).list
        for j in x:
            if(j not in y):
                sym.list.append(j)
                sym.length+=1
        return sym

    def display(self):
        print(self.list)

c=int(input("Enter the number of students who play cricket"))
Cricket=Set(c)
Cricket.addelement()
print("-------------------------------------------------------------------")
f=int(input("Enter the number of students who play football"))
Football=Set(f)
Football.addelement()
print("-------------------------------------------------------------------")
b=int(input("Enter the number of students who play badminton"))
Badminton=Set(b)
Badminton.addelement()
print("-------------------------------------------------------------------")
print("cricket players are")
Cricket.display()
print("football player are")
Football.display()
print("Badminton players are")
Badminton.display()
print("\n____________________________________________________________________\n")
print("Choices:\n1-List of students who play both cricket and badminton \n2-List of students who play either cricket or badminton but not both\n3-Number of students who play neither cricket nor badminton\n4-Number of students who play cricket and football but not badminton\n5-To exit enter 0")
print("\n____________________________________________________________________\n")

while(True):
    choice = int(input("Enter your choice:\n"))
    if choice==1:
        print("List of students who play both cricket and badminton:")
        print(Badminton.intersection(Cricket).list)

    elif choice==2:
        print("List of students who play either cricket or badminton but not both:")
        print(Badminton.symmetric_difference(Cricket).list)

    elif choice==3:
        print("List of students who play neither cricket nor badminton:")
        print(Football.difference((Cricket.union(Badminton))).list)
        print("Number of students who play neither cricket nor badminton are",(Football.difference(Cricket.union(Badminton)).length))

    elif choice==4:
        print("List of students who play cricket and football but not badminton:")
        print((Cricket.intersection(Football)).difference(Badminton).list)
        print("Number of students who play cricket and football but not badminton:",((Cricket.intersection(Football)).difference(Badminton)).length)

    elif(choice<1 or choice>4):
        print("Exit Successful")
        break
    print("____________________________________________________________________")
    if (input("Do you wish to continue further? Y/N") == "N"):
            break
    print("\n____________________________________________________________________")