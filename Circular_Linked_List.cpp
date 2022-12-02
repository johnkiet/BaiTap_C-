#include <stdio.h>
#include <iostream>

using namespace std;
int n;
struct Node
{
	int data;
	Node* next;
};

struct Stack
{
	Node* head;
	
	Node* tail;
};

void Init(Stack &s)
{
	s.head = NULL;
	
	s.tail = NULL;
}

bool isEmpty(Stack s){
	if(s.head == NULL) return true;
	return false;
}

Node *CreateNode(int x)
{
	Node *node = new Node;
	
	node->data = x;
	
	node->next = NULL;   
}

// Them 1 Node moi
void Add(Stack &s, int x){
	Node *p = CreateNode(x);
	if(isEmpty(s)) s.head = s.tail = p;
	else{
		p->next = s.head;
		s.head = p;
	}
	s.tail->next = s.head;
}

void Add_Tail(Stack &s, int x){
	Node *p = CreateNode(x);
	if(isEmpty(s)) s.head = s.tail = p;
	else{
		s.tail->next = p;
		s.tail = p;
	}
	s.tail->next = s.head;
}

Node *Find(Stack s, int k){
	Node *p = s.head;
	do{
		if(p->data == k){
			return p;
		}else{
			p = p->next;
		}
	}while(p != s.head);
	return NULL;
}

void Add_Mid(Stack &s, int x, int k){
	Node *p = Find(s,k);
	if(p!=NULL){
		Node *q = CreateNode(x);
		Node *r = p->next;
		p->next = q;
		q->next = r;
	}
}

void Add_At_K(Stack &s, int x, int k){
	if(isEmpty(s) || k<=1) {
		Add(s,x);
	}else if(k >= n) 
	{
		Add_Tail(s,x);	
	}else{
		Node *p = CreateNode(x);
		Node *q = new Node, *w = new Node;
		Node *r = s.head;
		int dem = 0;
		while(r!=NULL){
			dem++;
			q = r;
			if(dem == k) break;
			else r = r->next;
		}
		w = s.head;
		while(w->next != q) {
			w = w->next;
		}
		w->next = p;
		p->next = r;
	}
}


// Xoa 1 Node
void Delete(Stack &s){
	if(!isEmpty(s)){
		if(s.head != s.tail){
			Node *p = s.head;
			s.head = s.head->next;
			s.tail->next = s.head;
			delete p;
		}else s.head = NULL;
	}
}

void Delete_Tail(Stack &s){
	if(!isEmpty(s)){
		if(s.head != s.tail){
			Node *p = s.head;
			Node *q = new Node;
			while(p->next != s.tail){
				p = p->next;
			}
			q = p;
			p = p->next;
			s.tail = q;
			s.tail->next = NULL;
			s.tail->next = s.head;
			delete p;
		}else s.head = NULL;
	}
}

void Delete_K(Stack &s, int k){
	if(k <= 1){
		Delete(s);
	}else if(k >= n){
		Delete_Tail(s);
	}else{
		int dem = 0;
		if(!isEmpty(s)){
			Node *p = s.head;
			Node *q = new Node;
			while(p != NULL){
				dem++;
				q = p;
				if(dem == k){
					break;
				}else{
					p = p->next;
				}
			}
			Node *r = s.head;
			while(r->next != q){
				r =r->next;
			}
			r->next = q->next;
			delete q;
		}
	}
}

// Dao nguoc danh sach
void DaoNguocDS(Stack &s){
	if(s.head){
		if(s.head == s.tail) return;
		else if(s.tail == s.head->next){
			s.head = s.head->next;
			s.tail = s.tail->next;
		}else{
			Node *x, *y, *z;
			x = y = s.head;
			z = s.head->next;
			s.head = z->next;
			z->next = y;
			while(s.head->next != x){
				y = z;
				z = s.head;
				s.head = s.head->next;
				z->next = y;
			}
			s.head->next = z;
			s.tail = x;
			s.tail->next = s.head;
		}
	}else cout<< "\ndanh sach rong !!";
    
}




void Insert(Stack &s){
	cout<< "nhap so luong phan tu ban dau: "; cin>> n;
	for(int i = n;i >= 1; i--){
		Add(s,i);
	}
}

void Output(Stack s){
	if(!isEmpty(s)){
		Node *p = s.head;
		do{
			cout <<" "<< p->data;
			p = p->next;
		}while(p!= s.head);
	}else cout <<"\ndanh sach rong !";
	cout << endl;
}


int main(){
	Stack s;
	Init(s);
	Insert(s);
	Output(s);
	int lc, k, x;
	
	do{
		cout<<"\n__________Lua Chon__________"
		"\n1.Xuat danh sach"
		"\n2.Them vao dau danh sach "
		"\n3.Them vao cuoi danh sach "
		"\n4.Them vao danh sach sau phan tu K"
		"\n5.Them vao vi tri bat ki trong danh sach "
		"\n6.Xoa phan tu dau danh sach"
		"\n7.Xoa phan tu cuoi danh sach"
		"\n8.Xoa phan tu o vi tri K"
		"\n9.Dao nguoc danh sach"
		"\n0.Exit"
		"\nChon: ";
		cin>> lc;
		switch(lc){
			case 0: return 0;
					break;
			case 1: Output(s);
					break;
			case 2: cout<<"\n Nhap phan tu can them: ";
					cin>> k;
					cout<<" Da them thanh cong phan tu vao dau danh sach !";
					Add(s,k);
					n++;
					break;
			case 3: cout<<"\n Nhap phan tu can them: ";
					cin>> k;
					cout<<" Da them thanh cong phan tu vao cuoi danh sach !";
					Add_Tail(s,k);
					n++;
					break;
			case 4: cout<<"\n Nhap phan tu can them: ";
					cin>> x;
					cout<<"\n them vao sau phan tu: ";
					cin>> k;
					cout<<" Da them thanh cong phan tu vao danh sach !";
					Add_Mid(s,x,k);
					n++;
					break;
			case 5: cout<<"\n Nhap phan tu can them: ";
					cin>> x;
					cout<<"\n them vao vi tri: ";
					cin>> k;
					cout<<" Da them thanh cong phan tu vao danh sach !";
					Add_At_K(s,x,k);
					n++;
					break;
			case 6: Delete(s);
					cout<<" Delete thanh cong phan tu dau danh sach ! ";
					n--;
					break;
			case 7: Delete_Tail(s);
					cout<<" Delete thanh cong phan tu o cuoi danh sach ! ";
					n--;
					break;
			case 8: cout<<"\n xoa o vi tri: ";
					cin>> k;
					Delete_K(s,k);
					cout<<" Delete thanh cong phan tu o vi tri K ! ";
					n--;
					break;
			case 9: cout<<"\nDanh sach sau khi dao nguoc:\n";
					DaoNguocDS(s);
					Output(s);
					break;
			default: cout<<"\nThao Tac Sai, Vui Long Thu Lai !!! ";
		}
	}while(lc);
}
