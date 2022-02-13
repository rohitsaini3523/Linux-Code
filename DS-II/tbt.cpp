#include<iostream>
using namespace std;

class tbtnode
{
	public:
		bool lbit;	
		tbtnode *left;
		char data;
		tbtnode *right;
		bool rbit;	
		friend class tbt;
		tbtnode();
};

tbtnode::tbtnode()
{
	lbit = 1;
	left = NULL;
	data = '\0';
	right = NULL;
	rbit = 1;
}

class tbt
{
	tbtnode *head;
	public:
		void create();
		void preorder();
		void inorder();
		tbtnode* insuccr(tbtnode *);
		tbt();
};
		

tbt::tbt()
{
	head = new tbtnode();
	head->rbit = 0;
	head->left = head->right = head;
}

void tbt::create()
{
	tbtnode *temp,*curr,*root;
	char ch,choice;
	int flag ;
	root = new tbtnode();
	cout<<"\nEnter the Data: ";
	cin>>root->data;
	root->left = root->right = head;
	head->left = root;
	head->lbit = 0;
	do{
		flag = 0;
		temp = root;
		curr = new tbtnode();
		cout<<"Enter the Data : ";
		cin>>curr->data;
		while(flag == 0)
		{
			cout<<"Where do you want to attach (l/r) of "<< temp->data << " :";
			cin>>ch;
			if(ch == 'l')
			{
				if(temp->lbit == 1)
				{
					curr->right = temp;	
					curr->left = temp->left;
					temp->left =  curr;
					temp->lbit = 0;
					flag = 1;
				}
				else
				{
					temp = temp->left;
				}
			}
			else
			{
				if(temp->rbit == 1)
				{
					curr->left = temp;	
					curr->right = temp->right;
					temp->right =  curr;
					temp->rbit = 0;
					flag = 1;
				}
				else
				{
					temp = temp->right;
				}
			}
		}
	cout<<"Do you want to continue(y/n) : ";
	cin>>choice;
	}while(choice == 'y');
}

void tbt::inorder()
{
	tbtnode *temp;
	temp = head;
	while(1)
	{
		temp = insuccr(temp);	
		if(temp == head)
		{
			break;
		}
	cout<<" "<<temp->data<<" ";
	}
}

tbtnode* tbt::insuccr(tbtnode *temp)
{
	tbtnode	*x;
	x = temp->right;
	if(temp->rbit == 0)
	{
		while(x->lbit == 0)
			x = x->left;
	}
	return x;
}

void tbt::preorder()
{
	tbtnode *temp;
	temp = head->left;
	while(temp != head)
	{
		cout<<temp->data<<" ";
		while(temp->lbit != 1)
		{
			temp = temp->left;
			cout<<temp->data<<" ";
		}
		while(temp->rbit == 1)
		{
			temp = temp->right;
		}
	temp = temp->right;
	}
}
	


int main(){
	tbt t;
	int ch;
	do
	{
		cout<<"\n----------MENU-----------"<<endl;
		cout<<"\n1.Create(nr)\n2.Inorder\n3.Preorder\n4.Exit\n---------------------------\nEnter Your Choice : ";
		cin>>ch;
		switch(ch)
			{
				case 1:
					t.create();
					break;
				case 2:
					cout<<"Inorder : ";
					t.inorder();
					break;
				case 3:
					cout<<"Preorder : ";
					t.preorder();
					break;
				case 4:
					return 0;

				default:
					cout<<"\nEnter the Valid Choice!!!!";
			}
	}while(ch<5);
		return 0;
}

	
	
	
	


 	
			
	
