"""
Problem Statement ::
    Write a Python program to compute following computation on matrix:
        a)  Addition of two matrices	
        b) Subtraction of two matrices
        c) Multiplication of two matrices 
        d) Transpose of a matrix
"""
class matrix:
    def set_mat(self,r,c):
        self.mat=[]
        self.r=r
        self.c=c
        for i in range(r):
            temp=[]
            for j in range(c):
                temp.append(float(input("Enter the elements")))
            self.mat.append(temp)

    def disp_mat(self):
        for i in  range(self.r):
            for j in range(self.c):
                print(self.mat[i][j], end = " ")
            print()

    def create(self,r,c,m):
        self.mat = m
        self.r=r
        self.c=c

    def add(self,obj):
        if(self.r==obj.r and self.c==obj.c):
            m=[]
            for i in range(self.r):
                temp=[]
                for j in range(self.c):
                    temp.append(self.mat[i][j]+obj.mat[i][j])
                m.append(temp)
            print("The addition of matrix will be: ")
            add=matrix()
            add.create(self.r,self.c,m)
            add.disp_mat()

         
        else:
            print("Addition of these matrix is not possible as no of rows and coloumns are different")


    def subtract(self, obj):
        if(self.r == obj.r and self.c == obj.c):
            m = []
            for i in range(self.r):
                temp = []
                for j in range(self.c):
                    temp.append(self.mat[i][j] - obj.mat[i][j])
                m.append(temp)
            print("The subtraction of matrix is :")
            sub=matrix()
            sub.create(self.r,self.c,m)
            sub.disp_mat()
          
        else:
            print("Subtracion of these matrix is not possible as no of rows and coloumns are different")


    def mul(self,obj):
        if(self.c==obj.r):
            m=[]
            for i in range(self.r):
                temp=[]
                for j in range(obj.c):
                    n=0
                    for x in range(obj.r):
                        n+=self.mat[i][x]*obj.mat[x][j]
                    temp.append(n)
                m.append(temp)
            print("The multiplication of matrix is :")
            mul = matrix()
            mul.create(self.r, obj.c, m)
            mul.disp_mat()
            
        else:
            print("Multiplication of these matrix is not possible")


    def transpose(self):
        print("The transpose of matrix will be :")
        m=[]
        for i in range(self.c):
            temp=[]
            for j in range(self.r):
                temp.append(self.mat[j][i])
            m.append(temp)
        trans=matrix()
        trans.create(self.c,self.r, m)
        trans.disp_mat()
        






list=[]

print("Menu")
print("1-> Add a matrix")
print("2-> Select 1 for Adding matrix")
print("3-> Select 3 for Subtraction matrix")
print("4->Select 4 for multiplication of  matrix")
print("5-> For transpose of a matrix")
print("-1 -. To Exit")
print("========")
while(True):
    ch=int(input("Enter your choice"))
    if(ch==1):
        a=matrix()
        list.append(a)
        r = int(input("no of rows"))
        c = int(input("no of col"))
        a.set_mat(r, c)
        a.disp_mat()
    elif(ch==2):
        print("On which matrix operation do you want to perform operation ")
        a, b = map(int, input().split())
        list[a-1].add(list[b-1])
    elif(ch==3):
        print("On which matrix operation do you want to perform operation ")
        a, b = map(int, input().split())
        list[a-1].subtract(list[b-1])
    elif(ch==4):
        print("On which matrix operation do you want to perform operation ")
        a, b = map(int, input().split())
        list[a-1].mul(list[b-1])
    elif(ch==5):
        print("On which matrix operation do you want to perform operation ")
        a=int(input())
        list[a-1].transpose()
    elif(ch==-1):
        break