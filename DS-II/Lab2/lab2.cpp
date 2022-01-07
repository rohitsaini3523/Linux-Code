//============================================================================
// Name        : LAB2.cpp
// Author      : ROHIT
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class tnode
{
	string word;
	string meaning;
	tnode *left;
	tnode *right;
	friend class bst;
};

class bst
{
	tnode *root;

public:
	bst()
	{
		root = NULL;
	}
	void inorder_r() //driver
	{
		inorder_r(root);
	}
	tnode *copy_r()
	{
		return copy_r(root);
	}
	void create_nr();
	void inorder_r(tnode *root);
	tnode *copy_r(tnode *root);
	void mirror_r()
	{
		mirror_r(root);
		inorder_r(root);
	}
	void mirror_nr();
	void mirror_r(tnode *root);
	/*void search_r()
	{
		string s;
		int flag =0;
		cout<<"Enter Word to Search:";
		cin>>s;
		flag =search_r(root,s);
		if(flag==1)
		{
			cout<<"Found";
		}
		else
		{
			cout<<"Not FOound";
		}
	}*/
	void delete_node();
	void BFS();
} b;

class queue
{
	int front;
	int rear;
	tnode *data[30];

public:
	queue()
	{
		front = rear = -1;
	}
	void insert(tnode *);
	tnode *remove();
	int empty();
	friend class bst;
};

void queue::insert(tnode *temp)
{
	rear++;
	data[rear] = temp;
}

tnode *queue::remove()
{
	front++;
	return (data[front]);
}

int queue::empty()
{
	if (front == rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void bst::inorder_r(tnode *temp)
{
	if (temp != NULL)
	{
		inorder_r(temp->left);
		cout << "Word: " << temp->word;
		cout << " Meaning: " << temp->meaning << endl;
		inorder_r(temp->right);
	}
}
tnode *bst::copy_r(tnode *root)
{
	tnode *temp;
	temp = NULL;
	if (root != NULL)
	{
		temp = new tnode;
		temp->word = root->word;
		temp->meaning = root->meaning;
		temp->left = copy_r(root->left);
		temp->right = copy_r(root->right);
	}
	return temp;
}

void bst::delete_node()
{
	int flag = 0;
	string keyword;
	tnode *temp, *parent, *curr, *s;
	cout << "\nEnter word to be deleted:";
	cin >> keyword;
	curr = root;
	while (curr != NULL)
	{
		if (curr->word == keyword)
		{
			flag = 1;
			break;
		}
		else if (keyword > curr->word)
		{
			parent = curr;
			curr = curr->right;
		}
		else
		{
			parent = curr;
			curr = curr->left;
		}
	}
	if (flag == 1)
	{
		if (curr == root)
		{
			if (curr->right == NULL)
			{
				root = root->left;
			}
			else if (curr->left == NULL)
			{
				root = root->right;
			}
			else if (curr->right != NULL && curr->left != NULL)
			{

				temp = curr->left;
				root = curr->right;
				s = curr->right;
				while (s->left != NULL)
				{
					s = s->left;
				}
				s->left = temp;
			}
		}
		else if (curr != root)
		{
			if (curr->left == NULL && curr->right == NULL)
			{
				if (parent->left == curr)
				{
					parent->left = NULL;
				}
				else
				{
					parent->right = NULL;
				}
			}
			else if (curr->left == NULL)
			{
				if (parent->left == curr)
				{
					parent->left = curr->right;
				}
				else
				{
					parent->right = curr->right;
				}
			}
			else if (curr->right == NULL)
			{
				if (parent->left == curr)
				{
					parent->left = curr->left;
				}

				else
				{
					parent->right = curr->left;
				}
			}
			else
			{
				s = curr->right;
				temp = curr->left;
				while (s->left != NULL)
				{
					s = s->left;
				}
				s->left = temp;
				if (parent->left == curr)
				{
					parent->left = curr->right;
				}
				else
				{
					parent->right = curr->right;
				}
			}
		}
		curr->left = NULL;
		curr->right = NULL;
		delete (curr);
	}
	else
	{
		cout << "\nKeyword doesn't exist!";
	}
}
void bst::BFS()
{
	tnode *temp, *curr;
	queue q;
	temp = root;
	q.insert(temp);
	while (!q.empty())
	{
		temp = q.remove();
		cout << temp->word << "\t\t";
		if (temp->left != NULL)
		{
			cout << "\t";
			q.insert(temp->left);
		}
		else if (temp->right != NULL)
		{
			cout << "\t";
			q.insert(temp->right);
		}
		else
			cout << endl;
	}
}
void bst::mirror_r(tnode *root)
{
	tnode *temp;
	temp = root->left;
	root->left = root->right;
	root->right = temp;
	if (root->left != NULL)
	{
		mirror_r(root->left);
	}
	if (root->right != NULL)
	{
		mirror_r(root->right);
	}
}

void bst::mirror_nr()
{
	tnode *temp = root;
	queue q;
	q.insert(temp);
	while (!q.empty())
	{
		temp = q.remove();
		temp = root->left;
		root->left = root->right;
		root->right = temp;
		if (temp->left != NULL)
			q.insert(temp->left);
		if (temp->right != NULL)
			q.insert(temp->right);
	}
}

void bst::create_nr()
{
	tnode *temp, *curr;
	int flag;
	char choice;
	if (root == NULL)
	{
		root = new tnode;
		cout << "\nRoot Word: ";
		cin >> root->word;
		cout << "Root Meaning: ";
		cin >> root->meaning;
		root->left = NULL;
		root->right = NULL;
	}
	do
	{
		temp = root;
		flag = 0;
		curr = new tnode;
		cout << "Word: ";
		cin >> curr->word;
		cout << "Meaning: ";
		cin >> curr->meaning;
		while (flag == 0)
		{
			if (curr->word < temp->word)
			{
				if (temp->left == NULL)
				{
					temp->left = curr;
					flag = 1;
				}
				else
					temp = temp->left;
			}
			else
			{

				if (temp->right == NULL)
				{
					temp->right = curr;
					flag = 1;
				}
				else
					temp = temp->right;
			}
		}
		cout << "Want to Add More:(y/n)";
		cin >> choice;
	} while (choice == 'y' || choice == 'Y');
}

int main()
{
	int ch;
	while (ch != 8)
	{
		cout << "\n\tMenu\n";
		cout << "\n1.Create\n2.Inorder Display\n3.Delete\n4.Level Wise Display\n5.Mirror(r)\n6.Copy(r)\n7.Mirror(nr)\n8.Exit\nChoice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			b.create_nr();
			break;
		case 2:
			cout << "Inorder Display: \n";
			b.inorder_r();
			break;
		case 3:
			b.delete_node();
			break;
		case 4:
			b.BFS();
			break;
		case 5:
			cout << "Mirror Tree:\n";
			b.mirror_r();
			break;
		case 6:
			cout << "Copy Tree: \n";
			b.inorder_r(b.copy_r());
			break;
		case 7:
			cout << "Mirror Using Non Recursive Method:";
			b.mirror_nr();
			b.BFS();
			break;
		}
	}
	return 0;
}