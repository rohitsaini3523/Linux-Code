#include <iostream>
using namespace std;

int main()
{
	int no_process;
	int no_resources;
	cout << "\nEnter Number of process: ";
	cin >> no_process;
	cout << "Enter Number of Resources: ";
	cin >> no_resources;
	int **alocation = new int *[no_process];
	int **max = new int *[no_process];
	int **need = new int *[no_process];
	int *available = new int[no_resources];
	int *max_instance = new int[no_resources];
	int *finished = new int[no_process];
	for (int i = 0; i < no_process; i++)
		finished[i] = 0;
	for (int i = 0; i < no_process; i++)
	{
		max[i] = new int[no_resources];
		need[i] = new int[no_resources];
		alocation[i] = new int[no_resources];
	}
	cout << "\nAvailable Resources: \n";
	for (int i = 0; i < no_resources; i++)
	{
		cout << "Available Max Instance of Resource R" << i << ": ";
		cin >> max_instance[i];
		available[i] = 0;
		available[i] = max_instance[i];
	}
	cout << "\n Allocation: \n";
	for (int i = 0; i < no_process; i++)
	{
		cout << "Enter P" << i << ": ";
		for (int j = 0; j < no_resources; j++)
		{
			cin >> alocation[i][j];
			available[j] -= alocation[i][j];
		}
	}
	cout << "\nMax: \n";
	for (int i = 0; i < no_process; i++)
	{
		cout << "Enter P" << i << ": ";
		for (int j = 0; j < no_resources; j++)
			cin >> max[i][j];
	}
	cout << "Need Matrix: " << endl;
	for (int i = 0; i < no_process; i++)
	{
		for (int j = 0; j < no_resources; j++)
		{
			need[i][j] = max[i][j] - alocation[i][j];
			cout << need[i][j] << " ";
		}
		cout << "\n";
	}
	char choice;
	cout << "Do you Want to request process(y/n):";
	cin >> choice;
	if (choice == 'y')
	{
		char ch;
		do
		{
			int request_process;
			int ispossible = 0;
			cout << "Which process is requesting resource: ";
			cin >> request_process;
			int *requested = new int[no_resources];
			cout << "Enter Required Resources: ";
			for (int j = 0; j < no_resources; j++)
			{
				cin >> requested[j];
			}
			for (int j = 0; j < no_resources; j++)
			{
				if (requested[j] > available[j])
				{
					ispossible = 1;
				}
			}
			for (int j = 0; j < no_resources; j++)
			{
				if (requested[j] > need[request_process][j])
				{
					cout << "Resources unavailable at the moment!";
					return 0;
				}
			}
			if (ispossible == 1)
			{
				cout << "\nRequest Cannont Possible";
				cout << endl;
			}
			else if (ispossible == 0)
			{
				for (int j = 0; j < no_resources; j++)
				{
					available[j] -= requested[j];
					alocation[request_process][j] += requested[j];
					need[request_process][j] -= requested[j];
				}
			}
			cout << "\n\nAllocation\tMax\t\tNeed\t\tAvailable\n";
			for (int i = 0; i < no_process; i++)
			{
				for (int j = 0; j < no_resources; j++)
				{
					cout << alocation[i][j] << " ";
				}
				cout << "\t\t";
				for (int j = 0; j < no_resources; j++)
				{
					cout << max[i][j] << " ";
				}
				cout << "\t\t";
				for (int j = 0; j < no_resources; j++)
				{
					cout << need[i][j] << " ";
				}
				cout << "\t\t";
				for (int j = 0; (j < no_resources) && (i < 1); j++)
				{
					cout << available[j] << " ";
				}
				cout << endl;
			}
			cout << "Do you want to request additional resoures(y/n): ";
			cin >> ch;
		} while (ch != 'n');
	}
	cout << "\n\n";
	cout << "\nAllocation\tMax\t\tNeed\t\tAvailable\n";
	for (int i = 0; i < no_process; i++)
	{
		for (int j = 0; j < no_resources; j++)
		{
			cout << alocation[i][j] << " ";
		}
		cout << "\t\t";
		for (int j = 0; j < no_resources; j++)
		{
			cout << max[i][j] << " ";
		}
		cout << "\t\t";
		for (int j = 0; j < no_resources; j++)
		{
			cout << need[i][j] << " ";
		}
		cout << "\t\t";
		for (int j = 0; (j < no_resources) && (i < 1); j++)
		{
			cout << available[j] << " ";
		}
		cout << endl;
	}
	int *safe_sequence = new int[no_process], ind = 0;
	int *work = new int[no_resources];
	for (int i = 0; i < no_resources; i++)
		work[i] = available[i];

	for (int k = 0; k < no_process; k++)
	{
		for (int i = 0; i < no_process; i++)
		{
			if (finished[i] == 0)
			{

				int flag = 0;
				for (int j = 0; j < no_resources; j++)
				{
					if (need[i][j] > work[j])
					{
						flag = 1;
						break;
					}
				}

				if (flag == 0)
				{
					safe_sequence[ind++] = i;
					for (int y = 0; y < no_resources; y++)
						work[y] += alocation[i][y];
					finished[i] = 1;
				}
			}
		}
	}
	int flag = 1;

	for (int i = 0; i < no_process; i++)
	{
		if (finished[i] == 0)
		{
			flag = 0;
			cout << "The given sequence is not safe\n";
			cout << "Dead Lock Occur!";
			break;
		}
	}

	if (flag == 1)
	{
		cout << "Following is the SAFE Sequence" << endl;
		for (int i = 0; i < no_process - 1; i++)
			cout << " P" << safe_sequence[i] << " ->";
		cout << " P" << safe_sequence[no_process - 1] << endl;
	}
	return 0;
}