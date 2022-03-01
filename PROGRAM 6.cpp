#include<iostream>

using namespace std;

struct mie{
	string merek, jenis;
	int harga;
	
	mie *next;
	
};

mie *head, *tail, *cur, *newNode,*del, *after;


void createSingleLinkedList(string merek, string jenis, int hrg){
	head = new mie();
	head->merek = merek;
	head->jenis = jenis;
	head->harga = hrg;
	head->next = NULL;
	tail = head;
	
}

int countSingleLinkedList(){
	cur = head;
	int NO = 0;
	while(cur != NULL){
		NO++;
		cur = cur->next;
	}
	return NO;
}

void addFirst(string merek, string jenis, int hrg){
	newNode = new mie();
	newNode->merek = merek;
	newNode->jenis = jenis;
	newNode->harga = hrg;
	newNode->next = head;
	head = newNode;
}

void addMiddle(string merek, string jenis, int hrg, int posisi){
	newNode = new mie();
	newNode->merek = merek;
	newNode->jenis = jenis;
	newNode->harga = hrg;
	
	cur = head;
	int NO = 1;
	while(NO < posisi - 1 ){
		cur = cur->next;
		NO++;
	}
	
	newNode->next = cur->next;
	cur->next = newNode;
}

void removeMiddle(int posisi){
	if ( posisi < 1 || posisi > countSingleLinkedList() ){
		cout << "Posisi Diluar jangkauan " << endl;
	}else if( posisi == 1 || posisi == countSingleLinkedList() ){
		cout << "Posisi bukan posisi tengah " << endl;
	} else {
	int NO = 1;
	cur = head;
	while (NO <= posisi){
		if (NO == posisi -1){
			after = cur;
		}
		if (NO == posisi){
			del = cur;
		}
		cur = cur->next;
		NO++;
	}
	after->next = cur;
	delete del;
	}
}

void printSingleLinkedList(){
	cout << "Nomor data ada : " << countSingleLinkedList() << endl;
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
	
	addFirst("SARIMI", "Goreng", 4000);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	addMiddle("SEDAP", "Goreng", 3000, 2);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	addMiddle("INTERMI", "Kuah", 1000, 2);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
	
	removeMiddle(2);
	printSingleLinkedList();
	
	cout <<"\n\n"<<endl;
}
