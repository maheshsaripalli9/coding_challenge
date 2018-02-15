/*
 * singleLinkedList.cpp
 *
 *  Created on: Feb 14, 2018
 *      Author: maheshsaripalli
 */


#include<iostream>
#include<iomanip>

using namespace std;

struct node{
	int data;
	node* next;
};

class list{

	private:

		typedef struct node* nodePtr;

		nodePtr head, tail;


	public:

		list()
		{
			head = NULL;
			tail = NULL;
		}

		void createNode(int value){
			nodePtr temp = new node;
			temp->data = value;
			temp->next = NULL;

			if(head == NULL)
			{
				head = temp;
				tail = temp;
				temp = NULL;
			}
			else
			{
				tail->next = temp;
				tail = temp;
			}
		}

		void insert_start(int value){
			nodePtr temp = new node;
			temp->data = value;
			temp->next = head;
			head = temp;

		}

		void insert_end(int value)
		{
			nodePtr temp = new node();
			temp->data = value;
			temp->next = NULL;
			tail->next = temp;
			tail = temp;

		}
		 void insert_position(int value,int pos){
			 nodePtr temp = new node;
			 nodePtr curr = new node;
			 nodePtr prev = new node;
			 temp->data = value;
			 curr = head;
			 for(int i=1 ; i<pos; i++)
			 {
				 prev = curr;
				 curr = curr->next;
			 }
			 prev->next = temp;
			 temp->next = curr;
		 }

		 void delete_first(){
			 nodePtr temp= new node;
			 temp = head;
			 head = head->next;
			 delete temp;
		 }

		 void delete_last(){
			 //nodePtr temp= new node;
			 nodePtr curr = new node;
			 nodePtr prev = new node;
			 curr = head;
			 while(curr->next !=NULL)
			 {
				 prev= curr;
				 curr = curr->next;
			 }
			 tail = prev;
			 prev->next = NULL;
			 delete curr;
		 }

		 void delete_pos(int pos){
			 //nodePtr temp = new node;
			 nodePtr curr = new node;
			 nodePtr prev = new node;
			 curr = head;
			 for(int i=1; i<pos; i++)
			 {
				 prev= curr;
				 curr=curr->next;
			 }
			 prev->next = curr->next;
			 //curr->next = NULL;
			 delete curr;
		 }

		 void display(){
			 nodePtr temp = new node;
			 temp=head;
			 while(temp!=NULL)
			 {
				 cout<< " " << temp->data;
				 temp = temp->next;
			 }
			 cout<<endl;
		 }
};

int main(){

	list obj;
	obj.createNode(20);
	obj.insert_start(10);
	obj.insert_end(30);
	obj.insert_position(25,3);
	obj.display();
	obj.delete_first();
	obj.delete_last();
	obj.display();
	obj.delete_pos(2);
	obj.display();
}

