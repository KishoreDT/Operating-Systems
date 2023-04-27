#include<bits/stdc++.h>
using namespace std;

void worstFit(int blockSize[], int m, int processSize[],int n)
{
	int allocation[n];
	memset(allocation, -1, sizeof(allocation));
	for (int i=0; i<n; i++)
	{
		int wstIdx = -1;
		for (int j=0; j<m; j++)
		{
			if (blockSize[j] >= processSize[i])
			{
				if (wstIdx == -1)
					wstIdx = j;
				else if (blockSize[wstIdx] < blockSize[j])
					wstIdx = j;
			}
		}
		if (wstIdx != -1)
		{
			allocation[i] = wstIdx;
			blockSize[wstIdx] -= processSize[i];
		}
	}

	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++)
	{
		cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
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
	
	int m = sizeof(blockSize)/sizeof(blockSize[0]);
	int n = sizeof(processSize)/sizeof(processSize[0]);

	worstFit(blockSize, m, processSize, n);

	return 0 ;
}
