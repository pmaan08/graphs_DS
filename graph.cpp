#include<iostream>
#include<stdlib.h>
#define MAX 10
using namespace std;

class Node
{
	public:
	int vertex;
	Node *next;
	Node(int n=0)
	{
		vertex=n;
		next=NULL;
	}
};

class listgraph
{
	Node *list[MAX];
	int n;
	public:
		listgraph(int nov)
		{
			n=nov;
			for(int i=0;i<n;i++)
			list[i]=NULL;
		}
		void create();
		void display();
		void insert();
		void Delete();
};

void listgraph::create()
{
	Node *temp,*node;
	char ans;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"\nIs there an edge between vertex "<<i+1<<" and "<<j+1<<": ";
			cin>>ans;

			if(ans=='y')
			{
				node=new Node(j+1);
				if(list[i]==NULL)
				list[i]=temp=node;
				else
				{
					temp->next=node;
					temp=node;
				}
			}
		}
	}
}

void listgraph::display()
{
	Node *temp;
	for(int i=0;i<n;i++)
	{
		cout<<endl;
		cout<<"Vertex "<<i+1<<" -> ";
		temp=list[i];
		while(temp!=NULL)
		{
			cout<<"V"<<temp->vertex<<" -> ";
			temp=temp->next;
		}
		cout<<"NULL";
	}
}

void listgraph::insert()
{
	n+=1;
	int i,j;
	list[n-1]=NULL;
	Node *temp,*node;
	char ans;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==n-1||j==n-1)
			{
				cout<<"\nIs there an edge between vertex "<<i+1<<" and "<<j+1<<": ";
				cin>>ans;

				if(ans=='y')
				{
					node=new Node(j+1);
					if(list[i]==NULL)
					list[i]=temp=node;
					else
					{	temp=list[i];
						while(temp->next!=NULL)
						temp=temp->next;
						temp->next=node;
						temp=node;
					}
				}
			}
		}
	}
}

void listgraph::Delete()
{
	int v;
	cout<<"Enter node you want to delete: ";
	cin>>v;

}

main()
{
	int ch,n;
	cout<<"Enter number of vertices of graph: ";
	cin>>n;
	listgraph l(n);
	while(1)
	{
		system("cls");
		cout<<"\t\t\tMAIN MENU\n";
		cout<<"1. Create\n2. Display\n3. Insert\n4. Delete\n5. Exit\nEnter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: l.create();
					break;
			case 2: l.display();
					break;
			case 3: l.insert();
					break;
			case 4:
					break;
			case 5: exit(0);
			default:cout<<"Invalid Choice!!!";
		}
		cout<<"\n\nPress any key to continue...";
		getch();
	}
                                                  }
