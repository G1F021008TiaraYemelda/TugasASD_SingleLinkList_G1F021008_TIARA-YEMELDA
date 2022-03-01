#include<iostream>

using namespace std;

struct mie{
	string merek, jenis;
	int harga;
	
	mie *next;
	
};

mie *head, *tail, *cur, *newNode, *del;


void createSingleLinkedList(string merek, string jenis, int hrg){
	head = new mie();
	head->merek = merek;
	head->jenis = jenis;
	head->harga = hrg;
	head->next = NULL;
	tail = head;
	
}

void addLast(string merek, string jenis, int hrg){
	newNode = new mie();
	newNode->merek = merek;
	newNode->jenis = jenis;
	newNode->harga = hrg;
	newNode->next = NULL;
	tail->next = newNode;
	tail=newNode;
}

void removeLast(){
	del = tail;
	cur = head;
	while(cur->next != tail){
		cur = cur->next;
	}
	tail= cur;
	tail->next =NULL;
	delete del;
}

void printSingleLinkedList(){
	cur = head;
	while(cur != NULL){
		cout << "Merek mie : "<< cur->merek <<endl;
		cout << "Jenis mie : "<< cur->jenis <<endl;
		cout << "Harga mie : "<< cur->harga <<endl;
		
		cur = cur->next;
	}
}

int main(){
	
	createSingleLinkedList("INDOMIE", "Kuah", 3000);
	
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	addLast("SARIMI", "Goreng", 4000);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	removeLast();
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
}
