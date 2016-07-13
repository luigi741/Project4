#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include <iostream>

using namespace std;

//Type== Vertex
template<class Type> class Node
{
	private:
		Type* storedVertex;
		Node<Type>* next;

	public:
		Node()
		{
			storedVertex = NULL;
			next = NULL;
		}

		Node(Type &vertex): next(NULL)
		{
			storedVertex = &vertex;
		}

		Type* get_Vertex()
		{
			return storedVertex;
		}

		Node<Type>* get_Next()
		{
			return this->next;
		}

		void set_Next(Node<Type>* _node)
		{
			this->next = _node;
		}

};

//Type == Vertex
template<class Type> class LinkList
{
	private:
		int sz; //number of entries in linked list.
		Node<Type>* head;
		Node<Type>* tail;

	public:
		LinkList():sz(0), head(NULL), tail(NULL)
		{
		    //O(1)
		}

		~LinkList()
		{}
		
		//Mutators
		void re_size_Big(int x)
		{


		}

		void delNode(Node<Type> _node)
		{
			
		}

        void del_All()
        {
            while (head != NULL)
            {
                Node<Type>* tmp = head;
                head = head->get_Next();
                delete tmp;
            }
            sz = 0;
            tail = NULL;
        }
// /*
        void push_Front(Type _vertex)
        {
        	Node<Type>* _node = new Node<Type>(_vertex);
        	if(head == NULL)
        	{
        		head = _node;
        		tail = _node;
        		sz++;
        	}
        	else
        	{
        		_node->next = head;
        		head = _node;
        		sz++;
        	}
        }

		void add_node(Type _vertex)
		{
			Node<Type>* _node = new Node<Type>(_vertex);
			cout << "DEBUG:: in add_Node()" << endl;
			Node<Type>* ptr = head;
			cout << "DEBUG:: head set" << endl;
			//Adds node to the back of the linkList.

	        if (ptr == NULL)
	        {
	        	cout << "DEBUG:: IN IF" << endl;
	        	//cout << "ptr" << ptr->getNext() << endl;
	            head = _node;
	            tail = _node;
	            sz++;
	        }
	        else
	        {
	        	//cout << "DEBUG:: IN ELSE" << endl;
	            while(ptr->get_Next() != NULL)
	            {
	                ptr = ptr->get_Next();
	            }
	            ptr->set_Next(_node);
	            this->tail = _node;
	            sz++;
	        }
        	//LinkList::printList();
		}

//Accessors
		int size()
		{
			return sz;
		}

		bool search_for(string data)
		{
			cout << "DEBUG 3" << endl;
			if(head == NULL)
			{
				cout << "DEBUG 3.5" << endl;
				return false;
			}
			else
			{
				cout << "DEBUG 4" << endl;
				Node<Type>* ptr = head;
				if(ptr == NULL) return false;
				cout << "DEBUG AGAIN" << endl;

				cout << "search_for() while loop was ";
				while(ptr != NULL)
				{
					if(ptr->get_Vertex()->get_Data() == data)
					{
						cout << "not skipped" << endl;
						return true;
					}
					ptr = ptr->get_Next();
					cout << "not ";
				}
				cout << "skipped.";

				return false;
			}
		}

        bool is_Empty()
        {
        	if(head==0) cout << "Empty" << endl;
            return head==0;
        }

		Node<Type>* get_Head()
		{
			cout << "DEBUG:: IN GET HEAD" << endl;
			if(head == NULL) return NULL;
			return head;
		}

		void set_Head(Node<Type> _Node)
		{
			push_Front(_Node);
		}

		Type get_Tail()
		{
			if(tail == NULL) return NULL;
		    return tail;
		}

		void print_List() const
		{
	        Node<Type>* ptr = head;
	        int i = 1;
	        while(ptr !=NULL )
	        {
	        	cout << "(" << i << ")";
	            cout << "Node[" << ptr->get_Vertex()->get_Data() <<"] --> ";
	            ptr = ptr->get_Next();
	            i++;
	        }
	        cout << "end" << endl;
    	}
};



#endif // TREENODE_H_INCLUDED
