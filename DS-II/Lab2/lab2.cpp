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
		if(root ==NULL)
		{
			cout << "\n Binary Search";
		}
		else
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
	void mirror_r(tnode *root);
	void delete_node();
};
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
	string key;
	tnode *temp, *parent, *curr, *s;
	cout << "\nEnter word to be deleted:";
	cin >> key;
	curr = root;
	while (curr != NULL)
	//search function to find node
	{
		if (curr->word == key)
		{
			flag = 1;
			break;
		}
		else if (key > curr->word)
		{
			parent = curr;
			curr = curr->right;
		}
		else
		{
			parent = curr;
			curr = curr->left;
		}
	} //end of while

	if (flag == 1) //proceed if node found
	{
		if (curr == root)
		{ //deletion of root
			if (curr->right == NULL)
			{ // root with one child
				root = root->left;
			}
			else if (curr->left == NULL)
			{
				root = root->right;
			}
			else if (curr->right != NULL && curr->left != NULL)
			{
				//root with two children successor replace	
				temp=curr->left;
				root=curr->right;		
				s=curr->right;			
				while(s->left!=NULL)		
				{			  
					s=s->left;
				}			
				s->left=temp;			
			}
		}
	}
}

		void bst::mirror_r(tnode * root)
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
						temp = temp->left;
					}
					else if(curr->word > temp->word)
					{

						if (temp->right == NULL)
						{
							temp->right = curr;
							flag = 1;
						}
						temp = temp->right;
					}
				}
				cout << "Want to Add More:(y/n)";
				cin >> choice;
			} while (choice == 'y' || choice == 'Y');
		}
		int main()
		{
			bst b;
			int choice;
			while(choice !=7)
			{
				cout<<"\n________MENU______";
				cout << "\n1.Create(nr)";
				cout << "\n2.Inorder display(r) ";
				cout << "\n3.Delete(nr)";
				cout<<"\n4.Level wise display(nr) ";
				cout<<"5.Mirror image(nr) ";
				cout <<"\n6.Copy(r)";
				cout<<"7.Exit ";
				cout<< "\nEnter your choice:";
				cin>>choice;
                switch(choice)
				{
					case 1: b.create_nr();
						break;
					case 2:	cout << "Inorder Display: \n";
							b.inorder_r();
							break;
					case 3: cout << "Copy Tree: \n";
						    b.inorder_r(b.copy_r());
							break;
					case 4: cout << "Mirror Tree:\n";
							b.mirror_r();
							break;
					case 5:	b.delete_node();
						break;
				}

			}
			
			return 0;
		}
