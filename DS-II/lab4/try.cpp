#include<iostream>
using namespace std;

class treenode
{
	string keyword;
	string meaning;
	treenode *left;
	treenode *right;
	friend class tree;
};

class tree
{
	treenode *root;
	
	public:
	tree();

	void create_nr();
	void inorder_r();
	void inorder_r(treenode *);
	void delete_nr();
	void breadthfd_nr();
	void copy_r();
	treenode* copy_r(treenode *);
	void mirror_r();
	void mirror_r(treenode *);
	void mirror_nr();
};

tree::tree()
{
	root = NULL;
}

void tree::create_nr()
{
	treenode *temp,*curr;
	int flag;
	char ch;
	if(root == NULL)
	{
		root = new treenode();
		cout<<"\nEnter the Keyword:";
		cin>>root->keyword;
		cout<<"\nEnter the Meaning:";
		cin>>root->meaning;
		root->left = root->right  = NULL;
	}
	do
	{
		flag = 0;
		temp = root;
		curr = new treenode();
		cout<<"\nEnter the Keyword:";
		cin>>curr->keyword;
		cout<<"\nEnter the Meaning:";
		cin>>curr->meaning;
	//	curr->left = curr->right  = NULL;
		while(flag == 0)
		{
			if(curr->keyword < temp->keyword)
			{
				if(temp->left == NULL)
				{
					temp->left = curr;
					flag = 1;
				}
			temp = temp->left;		
			}
			else if(curr->keyword > temp->keyword)
			{
				if(temp->right == NULL)
				{
					temp->right = curr;
					flag = 1;
				}
			temp = temp->right;		
			}
		}
		cout<<"\nDo you want to continue (y/n): ";
		cin>>ch;
	}while(ch == 'y');
}

void tree::inorder_r()
{
	if(root == NULL)
	{
		cout<<"\nBinary search tree empty!!";
	}
	else
	{
		inorder_r(root);
	}
}

void tree::inorder_r(treenode *temp)
{
	if(temp != NULL)
	{
		inorder_r(temp->left);
		cout<<temp->keyword<<":"<<temp->meaning<<endl;
		inorder_r(temp->right);
	}
}

void tree::delete_nr()
{
	int flag = 0;
	string key;
	treenode *temp, *parent, *curr , *s;
	cout<<"\nEnter keyword to be deleted : ";
	cin>>key;
	curr = root;
	
	while(curr!=NULL)
	{
		if(curr->keyword == key)
		{
			flag = 1;
			break;
		}
		else if(key > curr->keyword)
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
	if(flag==1)
	{
		if(curr == root)
		{
			if(curr->right == NULL)
			{
				root = root->left;
			}
			else if(curr->left == NULL)
			{
				root = root->right;
			}
			else if(curr->right != NULL && curr->left !=  NULL)
			{
				temp = curr->left;
				root = curr->right;
				s = curr->right;
				while(s->left != NULL)
				{
					s = s->left;
				}
				s->left = temp;	
			}
		}
	else if(curr != root)
	{
		if(curr->left == NULL)
		{
			if(parent->left == curr)
			{
				parent->left = curr->right;
			}
			else
			{
				parent->right = curr->right;
			}
		}
		else if(curr->right == NULL)
		{
			if(parent -> left == curr)
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
			while(s->left != NULL)
			{
				s = s->left;
			}
			s->left = temp;
			if(parent->left = curr)
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
	delete(curr);
	}
	else
	{
		cout<<"\nKeyword doesn't exist!";
	}
}

class queue
{
	int front,rear;
	treenode *data[30];
	public:
		queue();
		void insert(treenode *);
		treenode* remove();
		int empty();	
		friend class tree;
};

queue::queue()
{
	front = rear = -1;
}

void queue::insert(treenode *temp)
{
	rear++;
	data[rear] = temp;
}

treenode* queue::remove()
{
	front++;
	return(data[front]);
}

int queue::empty()
{
	if(front == rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void tree::breadthfd_nr()
{
	treenode *temp;
	queue q;
	if(root == NULL)
	{
		cout<<"Binary search tree empty!";
	}
	else
	{
		int p = 1 , r = 0;
		temp = root;
		q.insert(temp);
		while(!q.empty())
		{
			for(int i = 0 ; i < p ; i++)
			{
				temp = q.remove();
				cout<<temp->keyword<<"\t"<<temp->meaning<<"\t\t";
				if(temp->left!=NULL)
				{
					q.insert(temp->left);
					r++;
				}
				if(temp->right!=NULL)
				{
					q.insert(temp->right);
					r++;
				}
			}
			cout<<endl;
			p = r;
			r = 0;
		}
	}		
}

void tree::copy_r()
{
	cout<<"\nThe Orignal BST is :\n";
	inorder_r(root);
	treenode *root2;
	root2 = copy_r(root);
	cout<<"\nSuccessfully copied into root2";
	cout<<"\nThe Copied BST is :\n";
	inorder_r(root2);
}

treenode* tree::copy_r(treenode* root)
{
	treenode *temp = NULL;
	if(root != NULL)
	{
		temp = new treenode;
		temp->keyword = root->keyword;
		temp->meaning = root->keyword;
		temp->left = copy_r(root->left);
		temp->right = copy_r(root->right);
	}
	return temp;
}

void tree :: mirror_r()
{
	if (root == NULL)   {
		cout<<"\nBinary search tree empty!";
	}
	else  {
	     mirror_r(root);
	}
}

void tree :: mirror_r(treenode *temp)
{
	treenode *swap;
	if (temp!=NULL)
	{
		swap=temp->left	;							
		temp->left=temp->right;
		temp->right=swap;
		mirror_r(temp->left);
		mirror_r(temp->right);
	}
}

void tree::mirror_nr()
{
	treenode *temp,*ptr;
	queue q;
	temp=root;
	q.insert(temp);
	while(!q.empty())
		{
			temp=q.remove();
			ptr=temp->left;
			temp->left=temp->right;
			temp->right=ptr;
			if(temp->left!=NULL)
			{
				q.insert(temp->left);
			}
			if(temp->right!=NULL)
			{
				q.insert(temp->right);
			}
		}
}




			
		

int main()
{
	tree bst;
	int ch;
	do
	{
		cout<<"\n----------MENU-----------"<<endl;
		cout<<"\n1.Create(nr)\n2.Inorder\n3.Delete\n4.Level Wise Display(nr)\n5.Mirror image(r)\n6.Mirror image(nr)\n7.Copy(r)\n8.Exit\n---------------------------\nEnter Your Choice : ";
		cin>>ch;
		switch(ch)
			{
				case 1:
					bst.create_nr();
					break;
				case 2:
					cout<<"Inorer Traversal "<<endl;
					bst.inorder_r();
					break;
				case 3:
					cout<<"The tree is: \n";
					bst.delete_nr();
					break;
				case 4:
					cout<<"Level Wise printing"<<endl;
					bst.breadthfd_nr();
					break;	
				case 5:
					cout<<"\nThe original tree is:\n";					   
					bst.breadthfd_nr();					   
					bst.mirror_r();					   
					cout<<"\nThe mirror image is:\n";				  
					bst.breadthfd_nr();					  
					break;
				case 6:
					cout<<"\nThe original tree is:\n";						
					bst.breadthfd_nr();					
					bst.mirror_nr();					
					cout<<"\nThe mirror image is:\n";				
					bst.breadthfd_nr();					
					break;
				case 7:
					bst.copy_r();
					break;
				case 8:
					return 0;
				default:
					return 0;
			}
		}
		while(ch<9);
			return 0;
}