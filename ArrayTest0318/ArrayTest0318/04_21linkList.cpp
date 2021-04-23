// 20303 ±Ë∞Ê«ı
#include <iostream>

using namespace std;

typedef struct linked {
	int data;
	struct  linked* next;
}node;

node* head = NULL;
node* tail = NULL;

void init();
void insert(node* ptr);
void printList(node* ptr);
void insertData(node* ptr);
void Delete(node* ptr);

int main() {
	int menu = 0;
	init();
	while (1)
	{
		cout << "1. ¿‘∑¬ 2.√‚∑¬ 3.ª¿‘ 4. ªË¡¶ 5.¡æ∑·" << endl;
		cout << "input menu : ";
		cin >> menu;
		switch (menu)
		{
		case 1:
			insert(tail);
			break;
		case 2:
			printList(head);
			break;
		case 3:
			insertData(head);
			break;
		case 4:
			Delete(head);
			break;
		case 5:
			break;
		default:
			cout << "select menu error" << endl;
		}
		if (menu == 5)
			break;
	}

	return 0;
}

void init() {
	head = new node;

	head->data = 0;
	head->next = NULL;

	tail = head;

	return;
}
void insert(node* ptr) {
	node* newnode = new node;
	int num = 0;
	cout << "input number : ";
	cin >> num;

	newnode->data = num;
	newnode->next = NULL;

	ptr->next = newnode;
	tail = newnode;

	return;
}

void printList(node* ptr) {
	node* view = ptr->next;
	while (view != NULL) {
		cout << view->data;
		view = view->next;
	}
	cout << endl;
	return;
}

void insertData(node* ptr) {
	node* newnode = new node;
	int index = 0, num = 0;
	int i;
	cout << "input InsertData index : ";
	cin >> index;
	cout << "input data : ";
	cin >> num;

	for (i = 0; i < index; i++)
		ptr = ptr->next;

	newnode->data = num;
	newnode->next = NULL;
	
	if (ptr->next == NULL) {
		ptr->next = newnode;
		tail = newnode;
	}
	else {
		newnode->next = ptr->next;
		ptr->next = newnode;
	}
	return;
}
void Delete(node* ptr) {
	node* temp = 0;
	int i;
	int index;
	if (head == tail) {
		cout << "not found data" << endl;
		return;
	}
	cout << "input delete index :";
	cin >> index;
	for (i = 0; i < index - 1; i++) {
		ptr = ptr->next;
	}
	temp = ptr->next;
	if (temp->next == NULL) {
		ptr->next = NULL;
		tail = ptr;
	}
	else {
		ptr->next = temp->next;
	}
	delete(temp);
	return;
}