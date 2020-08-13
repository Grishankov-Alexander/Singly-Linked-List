#pragma once

#include <iostream>
#include <cstddef>
#include <cassert>

struct Node {
	int data;
	Node *next;

	Node(int d) : data{ d }, next{ nullptr } {}
};

class LinkedList {
private:
	Node *head;

public:
	LinkedList() : head{ nullptr } {}

	void insert_head(int d);
	void insert_position(int d, int p);
	void insert_tail(int d);

	void delete_head();
	void delete_position(int p);
	void delete_tail();

	void print_list();
};