//============================================================================
// Name        : LAB1.cpp
// Author      : ROHIT Saini
// Version     :
// Copyright   : Your copyright notice
// Description : Lab 1, Ansi-style
// Erp: 1032200897
//============================================================================

#include <iostream>
using namespace std;

class tnode
{
	string data;
	tnode *right;
	tnode *left;
	friend class tree;
};
class tree
{
	tnode *root;

public:
	tree()
	{
		root = NULL;
	}
	void create_nr();
	void create_r()
	{
		if (root == NULL)
		{
			root = new tnode;
			cout << "\nRoot Data: ";
			cin >> root->data;
			root->left = NULL;
			root->right = NULL;
		}
		create_r(root);
	}
	void inorder_r() // driver
	{
		inorder_r(root);
	}
	void preorder_r()
	{
		preorder_r(root);
	}
	void postorder_r() // driver
	{
		postorder_r(root);
	}
	void create_r(tnode *root);
	void inorder_r(tnode *root);
	void preorder_r(tnode *root);
	void postorder_r(tnode *root);
	void inorder_nr();
	void preorder_nr();
	void postorder_nr();
};

class stack
{
	int top;
	tnode *data[30];

public:
	stack()
	{
		top = -1;
	}

	void push(tnode *temp);
	tnode *pop();
	int empty();
	friend class tree;
} s;
void stack::push(tnode *temp)
{
	top++;
	s.data[top] = temp;
}

tnode *stack::pop()
{
	tnode *temp = s.data[top];
	top--;
	return temp;
}
int stack::empty()
{
	if (top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void tree::inorder_nr()
{
	tnode *temp = root;
	while (1)
	{
		while (temp != NULL)
		{
			s.push(temp);
			temp = temp->left;
		}
		if (s.empty())
		{
			break;
		}
		temp = s.pop();
		cout << temp->data << " ";
		temp = temp->right;
	}
}

void tree::preorder_nr()
{
	tnode *temp = root;
	while (1)
	{
		while (temp != NULL)
		{
			s.push(temp);
			cout << temp->data << " ";
			temp = temp->left;
		}
		if (s.empty())
		{
			break;
		}
		temp = s.pop();
		temp = temp->right;
	}
}

void tree::postorder_nr()
{
	tnode *temp = root;
	while (1)
	{
		while (temp != NULL)
		{
			s.push(temp);
			temp = temp->left;
		}
		if (s.data[s.top]->right == NULL)
		{
			temp = s.pop();
			cout << temp->data << " ";
		}
		while (!s.empty() && (s.data[s.top]->right == temp))
		{
			temp = s.pop();
			cout << temp->data << " ";
		}
		if (s.empty())
		{
			break;
		}
		temp = s.data[s.top]->right;
	}
}

void tree::create_r(tnode *root)
{
	tnode *curr, *temp = root;
	char ch;
	cout << "Want to add node to left(y/n): ";
	cin >> ch;
	if (ch == 'y')
	{
		curr = new tnode;
		cout << "Enter Left Node Data: ";
		cin >> curr->data;
		temp->left = curr;
		curr->left = NULL;
		curr->right = NULL;
		create_r(curr);
	}
	cout << "Want to add node to right(y/n): ";
	cin >> ch;
	if (ch == 'y')
	{
		curr = new tnode;
		cout << "Enter Right Node Data: ";
		cin >> curr->data;
		temp->right = curr;
		curr->left = NULL;
		curr->right = NULL;
		create_r(curr);
	}
}
void tree::create_nr()
{
	char ch, ch1;
	int flag;
	if (root == NULL)
	{
		root = new tnode;
		cout << "\nRoot Data: ";
		cin >> root->data;
		root->left = NULL;
		root->right = NULL;
	}
	do
	{
		tnode *curr, *temp = root;
		flag = 0;
		curr = new tnode;
		cout << "Enter New Data: ";
		cin >> curr->data;
		curr->left = NULL;
		curr->right = NULL;
		cout << "Want to add node:(l for left  /r for right) ";
		cin >> ch;
		while (flag == 0)
		{
			if (ch == 'l')
			{
				if (temp->left == NULL)
				{
					temp->left = curr;
					flag = 1;
				}
				temp = temp->left;
			}
			if (ch == 'r')
			{
				if (temp->right == NULL)
				{
					temp->right = curr;
					flag = 1;
				}
				temp = temp->right;
			}
		}
		cout << "Do you want add more: ";
		cin >> ch1;
	} while (ch1 == 'y' || ch == 'Y');
}

void tree::inorder_r(tnode *temp)
{
	if (temp != NULL)
	{
		inorder_r(temp->left);
		cout << temp->data << " ";
		inorder_r(temp->right);
	}
}

void tree::preorder_r(tnode *temp)
{
	if (temp != NULL)
	{
		cout << temp->data << " ";
		preorder_r(temp->left);
		preorder_r(temp->right);
	}
}
void tree::postorder_r(tnode *temp)
{
	if (temp != NULL)
	{
		postorder_r(temp->left);
		postorder_r(temp->right);
		cout << temp->data << " ";
	}
}
int main()
{
	tree t;
	int choice;
	while (choice != 9)
	{
		cout << "\nMENU\n1.Create.\n2.Create Recursive\n3.Inorder\n4.Preoder\n5.Postorder\n6.Inorder recursive\n7.Preorder Recursive\n8.Postorder Recursive\n9.Exit\nChoice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			t.create_nr();
			break;
		case 2:
			t.create_r();
			break;
		case 3:
			t.inorder_r();
			break;
		case 4:
			t.preorder_r();
			break;
		case 5:
			t.postorder_r();
			break;
		case 6:
			t.inorder_nr();
			break;
		case 7:
			t.preorder_nr();
			break;
		case 8:
			t.postorder_nr();
			break;
		}
	}
	return 0;
}
