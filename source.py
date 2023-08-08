class Node:
    def __init__(self, data=" "):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    
    def is_null(self):
        if self.head is None:
            return " "
        return "x"
    
    def insert(self, d):
        temp = Node(d)
        if self.head is None:
            self.head = temp
            self.tail = temp
        else:
            self.tail.next = temp
            self.tail = temp
    
    def delete_node(self):
        if self.head is None:
            return " "
        d = self.head.data
        temp = self.head
        self.head = temp.next
        del temp
        return d
    
    def display_ll(self):
        temp = self.head
        while temp is not None:
            print(temp.data, "--->", end="")
            temp = temp.next
        print("nullptr")
        

class Queue:
    def __init__(self):
        self.data = LinkedList()
        self.rare = 0
        self.front = 0
    
    def is_empty(self):
        if self.front == self.rare:
            return True
        return False
    
    def is_null(self):
        if self.data.is_null() == " ":
            return " "
        else:
            return "x"
    
    def enqueue(self, d):
        self.data.insert(d)
        self.rare += 1
    
    def dequeue(self):
        if not self.is_empty():
            if self.front == 0:
                x = self.data.delete_node()
                self.front += 1
            else:
                x = self.data.delete_node()
                self.front += 1
            return x
        else:
            print("The queue is empty.")
            return " "
    
    def display(self):
        while not self.is_empty():
            x = self.dequeue()
            print("Data:", x)

class CatchNemo:
    Question = Queue
    Answer = Queue
    Nemo = int
    
    def __init__(self):
        Question = None
        Answer = None
        Nemo = 0 
    
    def LoadGames(self, filename):
        
    
        
        
