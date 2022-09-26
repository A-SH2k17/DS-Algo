from hashlib import new


class node:
    def __init__(self,data = None,next = None):
            self.data = data
            self.next = next
class linked_list:
    def __init__(self):
        self.head = None

    def insert(self,data):
        new_node = node(data)
        if self.head is None:
            self.head = new_node
            return
        itr = self.head
        while itr.next:
            itr = itr.next
        itr.next = new_node
    
    def inser_at_start(self,data):
        new_node = node(data,self.head)
        self.head = new_node
    
    def print_list(self):
        if self.head is None:
            print("the list is empty")
            return
        itr = self.head
        while itr:
            print(itr.data,end="-->")
            itr = itr.next
        print()
    
    def delete_last_node(self):
        if self.head is None:
            print("the list is already empty")
            return
        elif self.head.next is None:
            self.head = None
            return
        last = self.head.next
        new_last = self.head
        while last.next:
            last = last.next
            new_last = new_last.next
        new_last.next = None

    def delete_from_node(self,number):
        current = self.head
        prev = self.head
        while current:
            if current.data == number and current == self.head:
                self.head = current.next
                current = self.head
                prev = self.head
                continue
            elif current.data == number:
                prev.next = current.next
                if current.next is not None and current.next.data != number:
                    prev = current.next
            else:
                if current.next is not None and current.next.data != number:
                    prev = current.next
            current = current.next

    def reverse_list(self):
        prev , next = None,None
        current = self.head
        if current is None:
            print("the list is empty")
            return
        while current:
            next = current.next
            current.next = prev
            prev = current
            current = next
        self.head = prev


list1 = linked_list()
list1.inser_at_start(9)
list1.inser_at_start(8)
list1.insert(7)
list1.inser_at_start(3)
list1.insert(3)
list1.insert(3)
list1.insert(5)
list1.insert(3)
list1.print_list()
list1.delete_from_node(3)
list1.print_list()
list1.reverse_list()
list1.print_list()