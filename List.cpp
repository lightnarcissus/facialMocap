#include "List.h"

Node* ListOrganizer::newNode(std::string n) {
	Node *q;
	q = new Node();
	q->data = n;
	q->next = NULL;
	return q;
}

void ListOrganizer::freeNode(Node *p) {
	delete(p);
	return;
}

List* ListOrganizer::newList() {
	List *p;
	p = new List();
	p->front = NULL;
	p->rear = NULL;
	return p;
}

Node* ListOrganizer::nextNode(Node *p) {
	return p->next;
}

List* ListOrganizer::clearList(List *p) {
	Node *q, *w;
	q = p->front;
	while (q != NULL) {
		w = nextNode(q);
		freeNode(q);
		q = w;
	}
	p->front = NULL;
	p->rear = NULL;
	return p;
}

void ListOrganizer::freeList(List *p) {
	clearList(p);
	delete(p);
	return;
}

bool ListOrganizer::emptyList(List *p) {
	if (p->front == NULL)
		return true;
	else
		return false;
}

List* ListOrganizer::insertAtFront(List *p, std::string n) {
	Node *q;
	q = newNode(n);
	q->next = p->front;
	p->front = q;
	if (p->rear == NULL)
		p->rear = q;
	return p;
}

List* ListOrganizer::insertAfter(List *p, Node *w, std::string n) {
	Node *q;
	if (w == NULL || p->front == NULL)
		return insertAtFront(p, n);
	q = newNode(n);
	q->next = w->next;
	w->next = q;
	if (w == p->rear)
		p->rear = q;
	return p;
}

List* ListOrganizer::insertAtRear(List *p, std::string n) {
	Node *q;
	q = p->rear;
	return insertAfter(p, q, n);
}

std::string ListOrganizer::removeFromFront(List *p) {
	std::string n;
	Node *q;
	if (emptyList(p)) {
		return NULL;
	}
	n = p->front->data;
	q = p->front;
	p->front = p->front->next;
	freeNode(q);
	if (p->front == NULL)
		p->rear = NULL;
	return n;
}

Node* ListOrganizer::findInList(List *p, std::string n) {
	Node *q;
	q = p->front;
	while (q != NULL) {
		if (q->data == n)
			break;
		q = nextNode(q);
	}
	return q;
}