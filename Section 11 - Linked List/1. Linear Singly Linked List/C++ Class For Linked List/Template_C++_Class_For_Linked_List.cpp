#include <iostream>
using namespace std;

template < typename T>
class Node
{
	public:
		T data;
	  Node * next;
};

template < typename T>
	class LinkedList
	{
		private:
			Node<T> *head;

		public:

			LinkedList()
			{
				head = NULL;
			}

		LinkedList(int A[], int n);

		~LinkedList();

		void Display();

		void Insert(int index, T value);

		T DeletePos(int pos);

		int Length();

		void Reverse();

		void Middle();
	};

template < typename T>
	LinkedList<T>::LinkedList(int A[],
		int n)
	{
		Node<T> *t, *last;

		int i = 0;

		if (i == 0)

		{

			head = new Node<T> ;

			head->data = A[0];

			head->next = NULL;

			last = head;
		}

		for (i = 1; i < n; i++)

		{

			t = new Node<T> ;

			t->data = A[i];

			t->next = NULL;

			last->next = t;

			last = t;
		}
	}

template < typename T>
	LinkedList<T>::~LinkedList()
	{
		Node<T> *t = head;

		while (head != NULL)

		{

			head = head->next
			delete(t)
			t = head;
		}
	}

template < typename T>
	void LinkedList<T>::Display()
	{
		Node<T> *p = head;

		cout << "The elements are : ";

		while (p != NULL)

		{

			cout << p->data << "->";

			p = p->next;
		}

		cout << "NULL" << endl;
	}

template < typename T>
	void LinkedList<T>::Insert(int index,
		T value)
	{
		Node<T> *t, *p = head;

		int i;

		if (index < 0 || index > Length())

			return;

		t = new Node<T> ;

		t->data = value;

		if (index == 0)

		{

			t->next = head;

			head = t;
		}
		else

		{

			for (i = 0; i < index - 1; i++)

				p = p->next;

			t->next = p->next;

			p->next = t;
		}
	}

template < typename T>

	T LinkedList<T>::DeletePos(int pos)

{
	Node<T> *p = head;

	Node<T> *q = NULL;

	int x, i;

	if (pos == 1)

	{
		head = head->next;

		x = p->data;

		delete(p);

		return x;
	}
	else

	{
		for (i = 0; i < pos - 1; i++)

		{

			q = p;

			p = p->next;
		}

		x = p->data;

		q->next = p->next;

		delete(p);

		return x;
	}
}

template < typename T>

	int LinkedList<T>::Length()

{
	Node<T> *p = head;

	int count = 0;

	while (p != NULL)

	{
		p = p->next;

		count++;
	}

	return count;

}

template < typename T>

	void LinkedList<T>::Reverse()

{
	Node<T> *p = head;

	Node<T> *q = NULL;

	Node<T> *r = NULL;

	while (p != NULL)

	{
		r = q;

		q = p;

		p = p->next;

		q->next = r;
	}

	head = q;

}

template < typename T>

	void LinkedList<T>::Middle()

{
	Node<T> *p = head;

	Node<T> *q = head;

	while (q != NULL)

	{
		q = q->next;

		if (q != NULL)

			q = q->next;

		if (q != NULL)

			p = p->next;
	}

	cout << p->data << " is the middle element." << endl;

}

int
main()

{
	int i, n;

	cout << "Enter the number of nodes: ";

	cin >> n;

	int A[n];

	cout << "Enter the " << n << " elements: ";

	for (i = 0; i < n; i++)

		cin >> A[i];

	LinkedList<int> l(A, n);

	l.Display();

	l.Insert(2, 5);

	l.Display();

	cout << l.DeletePos(3) << endl;

	l.Display();

	cout << "The length is " << l.Length() << endl;

	l.Reverse();

	cout << "Linked List is reversed." << endl;

	l.Display();

	l.Middle();

}