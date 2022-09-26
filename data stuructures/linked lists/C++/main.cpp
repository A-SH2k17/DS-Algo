/*this file is to practice the concept of linked lists
author: ali el sharkawi
date: 12/9/2022

algorithm to create a linked list:
.)create a class called node
.)inside the node class:
    declare a data variable and a ponter variable with the type of node and call it next
.)create a class called linked list
.)inside the linked list:
    .declare a pointer variable with the type of node called head and assign NULL to it
    .create function to insert node that accepts one parameter called input
    .create function to delete last node
    .create functoin to display items in the linked list


algorithm to insert a node:
.)create a pointer node called new node;
.)assign the assign the value of the parameter to the data varibale in the new nodde
.)assign NULL to the "next" variable in the new node
.)if head is null:
    assign the new node to the head
else:
    .create a pointer called current node and assign head to it
    .while(the next node after the current node is not null)
        move the current node to become the next node
    .assign "the new node" to the next of the current node


algo to delete the last element in the list:
create a ponter called current head that points to the head node
if current pointer is empty print that the list is already empty
else if the the next of the current pointer is null:
    assign NULL to the head
else:
    assign the next of the current pointer to the current pointer
    create a new last pointer and assign it the head node
    while(the next of the current node is not null):
        move the current node to bcome the next node
        move the new last node to become the next node
    assign null to the next of the new last node


algorithm to delete occurances of a specific number from a linked list:
.create a pointer called current and previous and assign them both the head node
.if the data of the current matches the number:
    if the the current is the head:
        move the current and previous pointers to the next node
    else:
        link the node next to the current to the previous by assigning it to the next variable of the previous
        if the next node of the current is not null and the data is not equal to the number set the previous to that node
        set the current node to the next node
else:
    if the ext node of the current is not null and the data is not equal to the number set the previous to that node
    det the current node to the next node



algorithm to reverse linked lists:
create 3 pointers: previous,current,next
assign the head to the current pointer and Null to the other two
while the current doesn't equal to null:
    move the next pointer to the node after the current
    assign the previous pointer to the next of the current node
    assign the current node to the previous poointer
    assign the next node to the current node
assign the previous node to the head
*/

#include <bits/stdc++.h>
 
 using namespace std;

class node{
public:
    int data;
    node* next;
};

class linked_lists{
public:
    node* head = NULL;

    void dipslay(){
        node* current_node = head;
        if(current_node == NULL)
            cout<<"the list is empty\n";
        else{
            while(current_node != NULL){
                cout<<current_node->data<<" ";
                current_node = current_node ->next;
            }
            cout<<endl;
        }
    }

    void insert_node(int input){
        node* new_node = new node;
        new_node -> data = input;
        new_node -> next = NULL;
        if(head == NULL)
            head = new_node;
        else{
            node* current_node = head;
            while(current_node->next !=NULL)
                current_node = current_node->next;
            current_node -> next = new_node;
        }
    }

    void delete_last_node(){
        node* current_last = head;
        if(current_last==NULL)
            cout<<"The list is already empty";
        else if(current_last -> next == NULL)
            head = NULL;
        else{
            current_last = current_last -> next;
            node* new_last = head;
            while(current_last->next != NULL){
                current_last = current_last ->next;
                new_last = new_last->next;
            }
            new_last -> next = NULL;
        }
    }

    void delete_from_nodes(int input){
        node* current = head;
        node* prev = head;
        if(current == NULL){
            cout<<"the list is already empty\n";
            return;
        }
        while(current!=NULL){
            if(current ->data == input){
                if(current == head){
                    head = current ->next;
                    current = head;
                    prev = head;
                }
                else{
                    prev ->next = current ->next;
                    if(current-> next != NULL && current->next->data != input)
                        prev = current -> next;
                    current = current->next;
                }
            }
            else{
                if(current-> next != NULL && current->next->data != input)
                        prev = current -> next;
                current = current->next;
            }
        }
    }


    void reverse_list(){
        if(head==NULL || head->next ==NULL){
            if(head ==NULL)
                cout<<"the list is empty\n";
            return;
        }

        node* current = head;
        node* next = NULL, *prev = NULL;
        while(current != NULL){
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }
};
 int main(){
     linked_lists list1;
     list1.delete_from_nodes(3);
     list1.insert_node(9);
     list1.insert_node(2);
     list1.insert_node(1);
     list1.insert_node(8);
     list1.reverse_list();
     list1.delete_last_node();
     list1.dipslay();
 }