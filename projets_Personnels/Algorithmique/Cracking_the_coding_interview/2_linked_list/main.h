#ifndef MAIN_H
#define MAIN_H
#include <iostream>

struct node
  {
    int data;
    node *next;
  };

class List {
    private:
    node *head, *tail;
    
    public:
    List(void) {
      head = nullptr;
      tail = nullptr;
    }

    void createnode(int value) {
      node *temp=new node;
      temp->data=value;
      temp->next=nullptr;
      if(head==nullptr)
      {
        head=temp;
        tail=temp;
        temp=nullptr;
      }
      else
      {	
        tail->next=temp;
        tail=temp;
      }
    }

    void display(void) {
        node *temp=new node;
        temp=head;
        while(temp!=nullptr)
        {
        std::cout<<temp->data<<"\t";
        temp=temp->next;
        }
    }

    void insert_start(int value) {
        node *temp=new node;
        temp->data=value;
        temp->next=head;
        head=temp;
    }

    void insert_position(int pos, int value) {
        node *pre=new node;
        node *cur=new node;
        node *temp=new node;
        cur=head;
        for(int i=1;i<pos;i++)
        {
            pre=cur;
            cur=cur->next;
        }
        temp->data=value;
        pre->next=temp;	
        temp->next=cur;
    }

  void delete_first(void) {
    node *temp=new node;
    temp=head;
    head=head->next;
    delete temp;
  }

  void delete_last(void) {
    node *current=new node;
    node *previous=new node;
    current=head;
    while(current->next!=nullptr)
    {
      previous=current;
      current=current->next;	
    }
    tail=previous;
    previous->next=nullptr;
    delete current;
  }

  void delete_position(int pos) {
    node *current=new node;
    node *previous=new node;
    current=head;
    for(int i=1;i<pos;i++)
    {
      previous=current;
      current=current->next;
    }
    previous->next=current->next;
  }
    void remove_duplicates(void){

    }
};
#endif