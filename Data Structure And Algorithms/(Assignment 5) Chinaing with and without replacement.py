"""
Prblem Statement
    Implement all the functions of a dictionary (ADT) using hashing and handle P:F-LTL-UG / 01 / R0 2
    collisions using chaining with / without replacement.
    Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be 
    comparable, Keys must be unique. Standard Operations: Insert(key, value), 
    Find(key), Delete(key)

"""



size=10
def hashFunction(key):
    return len(key) % size


class Data:
    def __init__(self):
        self.key = ""
        self.value = ""
        self.chain=-1

    def __init__(self, key, value, x):
        self.key=key
        self.value = value
        self.chain = x



class HashTable:

    def __init__(self):
        self.count = 0

    def display(self):

        for i in range(0, size):
            print(i, self.table[i].key, self.table[i].value,self.table[i].chain)


    def search(self,key):
        u=hashFunction(key)
        i=0
        while(i<size and self.table[u].key!="" and hashFunction(key)!=hashFunction(self.table[u].key)):
            i=i+1
            u=(u+1)%size
        if(self.table[u].key=="" or i==size):
            return -1
        while(self.table[u].key!=""):
            if(self.table[u].key==key):
                return u
            else:
                u=self.table[u].chain
        return -1


    def delete_num(self,key):
        u=self.search(key)
        if(u==-1):
            print("Key Not Present")
            return

        if(u==hashFunction(key)):
            if(self.table[u].chain!=-1):
                r=self.table[u].chain
                self.table[u]=self.table[r]
                self.table[r]=Data("", "", -1)
                u=r
            else:
                self.table[u]=Data("", "", -1)
        else:
            for i in range(size):
                if(self.table[i].key !="" ):
                    if(self.table[i].chain==u):
                        self.table[i].chain=self.table[u].chain
                        self.table[u]=Data("", "", -1)
                        break
            else:
                self.table[u]=Data("", "", -1)
        print("Deleted Succesfully")
        while(1):
            temp=u
            for j in range(size):
                if (self.table[(u + j) % size].key != "" and hashFunction(self.table[(u + j) % size].key) == u):
                    self.table[u] = self.table[(u + j) % size]
                    self.table[(u + j) % size] = Data("", "", -1)
                    u = (u + j) % size
                    break
            if (temp == u):
                break






class without_replace(HashTable):
    table = [Data("", "", -1)] * size

    def insert(self, key, value):
        u = hashFunction(key)
        i = 0
        flag = 0
        while (i < size and self.table[u].key != "" and hashFunction(key) != hashFunction(self.table[u].key)):                # Find start of the chain
            i = i + 1
            u = (u + 1) % size
        if (i == size):
            print("Hashtable Full")
            return

        while (self.table[u].chain != -1):                                                                                   #Identifying the last element of chain
            u = self.table[u].chain

        temp = u
        while (self.table[temp].key != "" and i < size):
            if (self.table[temp].key == key):                                                                                 # Identifying empty location
                print("Already Present")
                flag = 1
                break
            else:
                temp = (temp + 1) % size
                i = i + 1
        if (flag == 0):
            if (i == size):
                print("Hashtable Full")
                return
            else:
                person = Data(key, value, -1)
                self.table[temp] = person
                self.count = self.count + 1
                if (temp != u):
                    self.table[u].chain = temp




class with_replace(HashTable):
    table = [Data("", "", -1)] * size

    def insert(self,key,value):
        u=hashFunction(key)

        if(self.table[u].key==""):
            person=Data(key,value,-1)
            self.table[u]=person
            return

        if(hashFunction(self.table[u].key)!=u):
            empty=u
            i=0
            while(self.table[empty].key!="" and i<size):
                empty=(empty+1)%size
                i=i+1                                                                                            #find empty location
            if(i==size):
                print("Hashtable Full")
                return

            prev=hashFunction(self.table[u].key)
            while(self.table[prev].chain!=u):
                prev=self.table[prev].chain                                                                   #update the chain
            # self.table[prev].chain=self.table[u].chain
            self.table[prev].chain = empty

            # while(self.table[prev].chain!=-1):
            #     prev=self.table[prev].chain


            per=Data(self.table[u].key,self.table[u].value,self.table[u].chain)
            self.table[empty]=per                                                                                  # insert current index



            person=Data(key,value,-1)
            self.table[u]=person


        else:
            i=0
            empty=u

            while(self.table[empty].key!="" and i<size):
                empty=(empty+1)%size
                i=i+1

            if(i==size):
                print("Hashtable Full")
                return

            person=Data(key,value,-1)
            self.table[empty]=person

            j=u
            while(self.table[j].chain!=-1):

                j=self.table[j].chain
            self.table[j].chain=empty



wr = with_replace()
wor = without_replace()

print("MENU")
print("1: Chaining With Replacement")
print("2: Chaining Without Replacement")
print("-1 Exit")
while (1):
    ch = int(input("Enter Choice"))
    if (ch == 1):
        while (1):
            print("________________________")
            print("1 Insert")
            print("2 Search")
            print("3 Delete")
            print("4 Display")
            print("-1 Exit")
            print("________________________")
            choice = int(input("Enter choice"))
            if (choice == 1):
                key = input("Enter key")
                value = input("Enter value")
                wr.insert(key,value)
            elif (choice == 2):
                key = input("Enter key to be searched")
                wr.search(key)
            elif (choice == 3):
                key = input("Enter key to be deleted")
                wr.delete_num(key)
            elif (choice == 4):
                wr.display()
            elif (choice == -1):
                break
    elif (ch == 2):
        while (1):
            print("________________________")
            print("1 Insert")
            print("2 Search")
            print("3 Delete")
            print("4 Display")
            print("-1 Exit")
            print("________________________")
            choice = int(input("Enter choice"))
            if (choice == 1):
                key = input("Enter key")
                value = input("Enter value")
                wor.insert(key, value)
            elif (choice == 2):
                key = input("Enter key to be searched")
                wor.search(key)
            elif (choice == 3):
                key = input("Enter key to be deleted")
                wor.delete_num(key)
            elif (choice == 4):
                wor.display()
            elif (choice == -1):
                break

