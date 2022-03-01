#include<iostream>

using namespace std;

struct mie{
	string merek, jenis;
	int harga;
	
	mie *next;
	
};

mie *head, *tail, *cur, *newNode;


void createSingleLinkedList(string merek, string jenis, int hrg){
	head = new mie();
	head->merek = merek;
	head->jenis = jenis;
	head->harga = hrg;
	head->next = NULL;
	tail = head;
	
}

void addFirst(string merek, string jenis, int hrg){
	newNode = new mie();
	newNode->merek = merek;
	newNode->jenis = jenis;
	newNode->harga = hrg;
	newNode->next = head;
	head = newNode;
}

void printSingleLinkedList(){
	cur = head;
	while(cur != NULL){
		cout << "Merek mie : "<< cur->merek <<endl;
		cout << "Jenis mie : "<< cur->jenis <<endl;
		cout << "harga mie : "<< cur->harga <<endl;
		
		cur = cur->next;
	}
}

int main(){
	
	createSingleLinkedList("INDOMIE", "KUAH", 3000);
	
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	addFirst("SEDAP", "GORENG", 3000);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
}
