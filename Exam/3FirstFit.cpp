/*
	Question:
		Implement a program to perform the first fit, best fit and worst fit allocation.
*/
#include<bits/stdc++.h>
using namespace std;

void firstFit(int blockSize[], int m,int processSize[], int n)
{
	int allocation[n];
	memset(allocation, -1, sizeof(allocation));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (blockSize[j] >= processSize[i])
			{
				allocation[i] = j;
				blockSize[j] -= processSize[i];
				break;
			}
		}
	}
	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++)
	{
		cout << " " << i+1 << "\t\t"
			<< processSize[i] << "\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}

int main()
{
	int b,p;
	cout<<"Enter total no. of Blocks : ";
	cin>>b;
	cout<<"\n";
	int blockSize[b];
	for (int i=0;i<b;i++)
	{
		cout<<"Enter size of Block "<<i+1<<" : ";
		cin>>blockSize[i];
	}
	cout<<"\n";
	cout<<"Enter total no. of Processes : ";
	cin>>p;
	cout<<"\n";
	int processSize[p];
	for (int i=0;i<p;i++)
	{
		cout<<"Enter size of Process "<<i+1<<" : ";
		cin>>processSize[i];
	}
	
	int m = sizeof(blockSize) / sizeof(blockSize[0]);
	int n = sizeof(processSize) / sizeof(processSize[0]);

	firstFit(blockSize, m, processSize, n);

	return 0 ;
}
/*
	Output:
		Enter total no. of Blocks : 5
		Enter size of Block 1 : 100
		Enter size of Block 2 : 500
		Enter size of Block 3 : 200
		Enter size of Block 4 : 300
		Enter size of Block 5 : 600

		Enter total no. of Processes : 4

		Enter size of Process 1 : 212
		Enter size of Process 2 : 417
		Enter size of Process 3 : 112
		Enter size of Process 4 : 426

		Process No.     Process Size    Block no.
		1              212             2
		2              417             5
		3              112             2
		4              426             Not Allocated
*/