"""
Problem Statement
    Consider telephone book database of N clients. Make use of a hash table 
    implementation to quickly look up client‘s telephone number. Make use of two 
    collision handling techniques and compare them using number of comparisons 
    required to find a set of telephone numbers (use linear probing with replacement and 
    without replacement)


"""



size = 10


def hashFunction(key):
    return key % size


class Data:
    def __init__(self):
        self.tel = -1
        self.name = ""

    def __init__(self, tel, name):
        self.tel = tel
        self.name = name

    def displayClient(self):
        print("Name: ", self.data)
        print("Contact: ", self.key)


class HashTable:

    def __init__(self):
        self.count = 0

    def display(self):
        # print("index","Telephone Number","Name")
        for i in range(0, size):
            # if (self.table[i].tel != -1):
            print(i, self.table[i].name, self.table[i].tel)

    def search(self, tel):
        u = hashFunction(tel)
        comp = 0
        if (self.table[u].tel == tel):
            comp = comp + 1
            print("Found in ", comp, "comparison")
            print(u, self.table[u].tel, self.table[u].name)
            return
        else:
            comp = 1
            range = u
            u = u + 1
            while (u != range):
                if (self.table[u].tel == tel):
                    comp = comp + 1
                    print("Found in ", comp, "comparison")
                    print(u, self.table[u].tel, self.table[u].name)
                    return
                u = (u + 1) % size
                comp = comp + 1
        print("Not Found in ", comp, "comparison")


    def search_key(self, tel):
        u = hashFunction(tel)
        if (self.table[u].tel == tel):
            return u
        else:
            before = u
            u = u + 1
            while (u != before):
                if (self.table[u].tel == tel):
                    return u
                u = (u + 1) % size
        return -1




    def delete_num(self, tel):
        u = self.search_key(tel)
        if (u == -1):
            print("Number Not Found")
            return

        temp = u + 1
        before = u - 1
        while (temp != before):
            if (hashFunction(self.table[temp].tel) == u):
                self.table[u] = self.table[temp]
                self.table[temp] = Data(-1, "")
                self.count = self.count - 1
                print("Deleted Succesfully")
                print("_________________________________")
                return
            temp = (temp + 1) % size

        self.table[u] = Data(-1, "")
        self.count = self.count - 1
        print("Deleted Succesfully")
        print("_________________________________")


class replace(HashTable):
    table = [Data(-1, "")] * size

    def insertWithReplacement(self, name, tel):

        collision = 0
        person = Data(-1, "")
        if (self.count == size):
            print("Table Full")
            return
        u = hashFunction(tel)
        if (self.table[u].tel != -1 and hashFunction(self.table[u].tel) != u):
            prevtel = self.table[u].tel
            prevname = self.table[u].name
            self.table[u].tel = tel
            self.table[u].name = name
            u = hashFunction(prevtel)
            while (self.table[u].tel != -1):
                collision = collision + 1
                u = (u + 1) % size
            person = Data(prevtel, prevname)


        else:
            while (self.table[u].tel != -1):
                collision = collision + 1
                if (self.table[u].tel == tel):
                    print("Telephone Number already Present")
                    print("_________________________________")
                    return
                u = (u + 1) % size

            person = Data(tel, name)
        self.table[u] = person
        self.count = self.count + 1

        print("Telephone Number Inserted in ", collision, " collision")
        print("_________________________________")


class without_replace(HashTable):
    table = [Data(-1, "")] * size

    def insertWithoutReplacement(self, name, tel):
        u = hashFunction(tel)
        collision = 0
        if (self.count == size):
            print("Table is Full")
            return
        while (self.table[u].tel != -1):
            collision = collision + 1
            if (self.table[u].tel == tel):
                print("Telephone Number already Present")
                print("_________________________________")
                return
            u = (u + 1) % size

        person = Data(tel, name)
        self.table[u] = person
        self.count = self.count + 1

        print("Telephone Number Inserted in ", collision, " collision")
        print("_________________________________")


wr = replace()
wor = without_replace()

print("MENU")
print("1: With Replacement")
print("2: Without Replacement")
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
                tel = int(input("Enter Telephone Number"))
                name = input("Enter Client Name")
                wr.insertWithReplacement(name, tel)
            elif (choice == 2):
                tel = int(input("Enter Telephone Number to be searched"))
                wr.search(tel)
            elif (choice == 3):
                tel = int(input("Enter Telephone Number to be deleted"))
                wr.delete_num(tel)
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
                tel = int(input("Enter Telephone Number"))
                name = input("Enter Client Name")
                wor.insertWithoutReplacement(name, tel)
            elif (choice == 2):
                tel = int(input("Enter Telephone Number to be searched"))
                wor.search(tel)
            elif (choice == 3):
                tel = int(input("Enter Telephone Number to be deleted"))
                wor.delete_num(tel)
            elif (choice == 4):
                wor.display()
            elif (choice == -1):
                break



