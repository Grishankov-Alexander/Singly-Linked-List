// This file implements the methods for the LinkedList class
// By: Nick from CoffeeBeforeArch

#include "interface.h"

using namespace std;

void LinkedList::insert_head(int d)
{
	Node *new_head = new Node(d);
	new_head->next = head;
	head = new_head;

	cout << "Head insert with data " << d << endl;
	print_list();
}

void LinkedList::insert_position(int d, int p)
{
	Node *new_node = new Node(d);
	if (head == nullptr) {
		if (p == 0) head = new_node;
		else assert(head == nullptr && p == 0);
	}
	else {
		Node *temp = head;
		Node *prev = nullptr;
		for (int i = 0; i < p; ++i) {
			assert(temp != nullptr);
			prev = temp;
			temp = temp->next;
		}
		if (prev == nullptr) {
			head = new_node;
			head->next = temp;
		}
		else {
			prev->next = new_node;
			new_node->next = temp;
		}
	}

	cout << "Position " << p << " insert with data " << d << endl;
	print_list();
}

void LinkedList::insert_tail(int d)
{
	Node *new_tail = new Node(d);
	if (head == nullptr) {
		head = new_tail;
	}
	else {
		Node *temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = new_tail;
	}

	cout << "Tail insert with data " << d << endl;
	print_list();
}

void LinkedList::delete_head()
{
	assert(head != nullptr);
	Node *temp = head;
	head = head->next;
	delete temp;

	cout << "Head delete" << endl;
	print_list();
}

void LinkedList::delete_position(int p)
{
	assert(head != nullptr);
	Node *temp = head;
	Node *prev = nullptr;
	for (int i = 0; i < p; ++i) {
		assert(temp != nullptr);
		prev = temp;
		temp = temp->next;
	}
	if (prev == nullptr) head = temp->next;
	else prev->next = temp->next;
	delete temp;

	cout << "Position " << p << " delete" << endl;
	print_list();
}

void LinkedList::delete_tail()
{
	assert(head != nullptr);
	Node *temp = head;
	Node *prev = nullptr;
	while (temp->next != nullptr) {
		prev = temp;
		temp = temp->next;
	}
	if (prev == nullptr)
		head = head->next;
	else prev->next = nullptr;
	delete temp;

	cout << "Tail delete" << endl;
	print_list();
}

void LinkedList::print_list()
{
	for (int i = 0; i < 72; ++i) cout << '-';
	cout << endl << "List:\t";
	Node *temp = head;
	while (temp != nullptr) {
		cout << temp->data << '\t';
		temp = temp->next;
	}
	cout << endl;
	for (int i = 0; i < 72; ++i) cout << '-';
	cout << endl;
}