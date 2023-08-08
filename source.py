import os


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
            return True
        else:
            return False

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

    def empty(self):
        while not self.is_empty():
            x = self.dequeue()

    def display(self):
        while not self.is_empty():
            x = self.dequeue()
            print("Data:", x)


class CatchNemo:
    Nemo = int
    Questions = Queue()
    Answers = Queue()

    def __init__(self):
        self.Nemo = 0

    def LoadGames(self, filename, Stagename):
        os.system("clear")
        self.Questions.empty()
        self.Answers.empty()
        print("Current Nemo(s):", self.Nemo)
        with open(filename, "r") as fin:  # OPENING FILE IN READ MODE
            if not fin:
                print(
                    "\n\n Stage 1 questions are not stored, Press any key to continue...!!")
                input()
                exit()

            print("\n\t\t\t <---------------------Catch The Nemo---------------------> ")
            print("\n\t\t  	                 <---" + Stagename + "--->")

            for line in fin:  # WHILE LOOP TO RUN UNTIL THE END OF FILE
                line = line.strip()  # Removing leading/trailing whitespace
                if not line:  # ENDS LOOP WHEN EMPTY LINE IS FOUND
                    break

                # SEPARATING LINE BASED ON DELIMITER (COMMA)
                str_arr = line.split(';')
                self.Questions.enqueue(str_arr[0])  # TURNING STRING TO INTEGER
                self.Answers.enqueue(str_arr[1])
        while not self.Questions.is_empty():
            print("\n\t\t", self.Questions.dequeue(),
                  "\n\t\t Enter your Answer here: ")
            line = input()
            line = line.upper()  # Transform the string to uppercase
            if line != self.Answers.dequeue():
                print("\n\t\tWrong Answer......!!!!!! Press any key to start Over")
                flag = 0
                if self.Nemo > 0:
                    choice = input(
                        "\n\tOr You can lose 1 nemo to skip this question. (y/n): ")
                    choice = choice.lower()
                    while flag == 0:
                        if choice == 'y':
                            self.Nemo -= 1
                            flag = 1
                        elif choice == 'n':
                            self.LoadGames(filename)
                            flag = 1
                        else:
                            print(
                                "\tYou selected the wrong choice, Please select from y/n:")
                            choice = input().lower()
                if flag == 0:
                    input()
                    self.LoadGames(filename)

        self.Nemo += 1
        print("\n\t\t\tCongrats!! You cleared the stage 1 of the Easy level.")
        print("\n\t\t\t You caught your First Nemo, hurrah!!")
        print("\n\t\t\t Now you have", self.Nemo, "Nemos in your bag.")
        input()

        with open("records.txt", "w") as fout:  # OPENING FILE IN WRITE MODE
            fout.write("1;2;" + str(self.Nemo))
            exit(self.Nemo)


game = CatchNemo()
game.LoadGames("EasyStage1.txt", "Easy level Stage 1")
