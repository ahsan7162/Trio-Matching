#include<iostream>
using namespace std;
#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<time.h>
#include<string.h>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;

			// Node Class for single Data i.e. Name or GeoID
class Node{
	private:
		string Data;
		Node *next;
	public:
		friend class SinglyLinkedList;
		Node();									// default constructor
		Node(string Data,Node* nextnode);		// parameterized constructor
};

		// definition of default constructor
Node::Node():Data(0),next(0)
{
	
}
		// definition of parameterized constructor
Node::Node(string Data,Node* nextnode=0)
{
	this->Data=Data;
	next=nextnode;
}

			// Singly Linked List class For maintaining queue
class SinglyLinkedList{
	private:
		Node *Head;
		Node *Tail;
		int ListSize;
	public:
		SinglyLinkedList();								// default constructor
		bool InsertAtTail(string Data);					// wrapper method for inserting a data in the queue at tail FILO
		const string DeleteAtHead();					// wrapper method for returning a value at the head of the queue
		int GetListSize() const;						// method returning the size of current list
};		
		// definition of default constructor
SinglyLinkedList::SinglyLinkedList():Head(0),Tail(0),ListSize(0)
{
	
}
		// definition of Insert At Tail method
bool SinglyLinkedList::InsertAtTail(string Data)
{
	Node* new_node=new Node(Data);
	Node *current;
	if(Head!=0)
	{
		current = Head;
		while(current->next!=0)		//a node will be added at tail
		{
			current = current->next;
		}
		current->next=new_node;
		new_node->next = 0;
	}
	else 
	{
		Head = new_node;
	}
	ListSize++;
	return true;
}
		// definition of DeleteAtHead method
const string SinglyLinkedList::DeleteAtHead()
{
	if(Head!=0)
	{
		string temp;
		temp=Head->Data;
		Head=Head->next;
		ListSize--;
		return temp;
	}
}
		// definition of GetListSize method
int SinglyLinkedList::GetListSize() const
{
	return ListSize;
}
			
			// Queue class for Radix Sorting on Data
class Queue{
	private:
		SinglyLinkedList *queue;
	public:
		Queue();					// default constructor
		bool isEmpty();				// method to check if the Queue is empty or not
		const string DeQueue();	// method for popping the first element from the queue
		bool EnQueue(string Data);	// method for pushing the element at the tail of the queue
		int GetQueueSize() const;	// method for returning the size of queue
};
		// definition of default constructor
Queue::Queue()
{
	queue=new SinglyLinkedList();
}
		// definition of isEmpty method
bool Queue::isEmpty()
{
	if(queue->GetListSize()==0)
		return true;
	else
		return false;
}
		// definition of EnQueue function
bool Queue::EnQueue(string Data)	
{
	queue->InsertAtTail(Data);
	return true;	
}
		// definition of DeQueue method
const string Queue::DeQueue()
{
	if(queue->GetListSize()!=0)
	{
		string temp;
		temp=queue->DeleteAtHead();
		return temp;	
	}	
}
		// definition of GetQueueSize method
int Queue::GetQueueSize() const
{
	return queue->GetListSize();	
}	

			// Node Class for country name, state name, city name
class DSLNode{
	private:
		string GeographicalID;
		string Name;
		DSLNode *next;
		DSLNode *previous;
	public:
		friend class DoublyLinkedList;
		DSLNode();									// default constructor
		DSLNode(string,string,DSLNode*,DSLNode*);		// parameterized constructor for Doubly Skip List
};

		// definition of default constructor
DSLNode::DSLNode():GeographicalID(0),Name(0),next(0),previous(0)
{
	
}
		// definition of parameterized constructor for Doubly Skip List
DSLNode::DSLNode(string GeoID,string Name,DSLNode *nextNode=0,DSLNode *previousNode=0)
{
	this->GeographicalID=GeoID;
	this->Name=Name;
	this->next=nextNode;
	this->previous=previousNode;
}

			// Doubly Linked List class
class DoublyLinkedList{
	private:
		DSLNode *Head;
		DSLNode *Tail;
		long ListSize;
		int *AlphabetsCounters;
	public:
		DoublyLinkedList();														// default constructor
		bool InsertAtHead(string GeoID,string Name);							// method to insert a node at head
		bool InsertAtTail(string GeoID,string Name);							// method to insert a node at tail
		bool InsertAtIndex(int indexPosition,string GeoID,string Name);			// method to insert a node at a certain index
		bool DeleteAtHead();													// method to delete a node from head
		bool DeleteAtTail();													// method to delete a node from tail
		bool DeleteAtIndex(int index);											// method to delete a node from a certain index
		void PrintList();														// method to print the entire contents of list
		void ReadFromFile_City();												// method to read .csv file of city and synonyms
		void ReadFromFile_Country();											// method to read .csv file of country and synonyms
		void ReadFromFile_State();												// method to read .csv file of state and synonyms
		int Max();																// method to find the maximum length of name in the entire list
		void RadixSort();														// method to sort the entire contents of data
};
		// definition of default constructor
DoublyLinkedList::DoublyLinkedList():Head(0),Tail(0),ListSize(0)
{
	AlphabetsCounters=new int[26];
	memset(AlphabetsCounters,0,sizeof(int)*26);
}
		// definition of InsertAtHead method
bool DoublyLinkedList::InsertAtHead(string GeoID,string Name)
{
	for(int i=0;i<Name.length();i++)
	{
		Name[i]=tolower(Name[i]);
	}
	
	DSLNode *newNode=new DSLNode(GeoID,Name);
	if(Head==0)
		Head=Tail=newNode;
	else
	{
		newNode->next=Head;
		Head->previous=newNode;
		Head=newNode;
	}
	
	if(tolower(Name[0])=='a')
		AlphabetsCounters[0]++;
	else if(tolower(Name[0])=='b')
		AlphabetsCounters[1]++;
	else if(tolower(Name[0])=='c')
		AlphabetsCounters[2]++;
	else if(tolower(Name[0])=='d')
		AlphabetsCounters[3]++;
	else if(tolower(Name[0])=='e')
		AlphabetsCounters[4]++;
	else if(tolower(Name[0])=='f')
		AlphabetsCounters[5]++;
	else if(tolower(Name[0])=='g')
		AlphabetsCounters[6]++;
	else if(tolower(Name[0])=='h')
		AlphabetsCounters[7]++;
	else if(tolower(Name[0])=='i')
		AlphabetsCounters[8]++;
	else if(tolower(Name[0])=='j')
		AlphabetsCounters[9]++;
	else if(tolower(Name[0])=='k')
		AlphabetsCounters[10]++;
	else if(tolower(Name[0])=='l')
		AlphabetsCounters[11]++;
	else if(tolower(Name[0])=='m')
		AlphabetsCounters[12]++;
	else if(tolower(Name[0])=='n')
		AlphabetsCounters[13]++;
	else if(tolower(Name[0])=='o')
		AlphabetsCounters[14]++;
	else if(tolower(Name[0])=='p')
		AlphabetsCounters[15]++;
	else if(tolower(Name[0])=='q')
		AlphabetsCounters[16]++;
	else if(tolower(Name[0])=='r')
		AlphabetsCounters[17]++;
	else if(tolower(Name[0])=='s')
		AlphabetsCounters[18]++;
	else if(tolower(Name[0])=='t')
		AlphabetsCounters[19]++;
	else if(tolower(Name[0])=='u')
		AlphabetsCounters[20]++;
	else if(tolower(Name[0])=='v')
		AlphabetsCounters[21]++;
	else if(tolower(Name[0])=='w')
		AlphabetsCounters[22]++;
	else if(tolower(Name[0])=='x')
		AlphabetsCounters[23]++;
	else if(tolower(Name[0])=='y')
		AlphabetsCounters[24]++;
	else if(tolower(Name[0])=='z')
		AlphabetsCounters[25]++;
		
	ListSize++;
	return true;
}
		// definition of InsertAtTail method
bool DoublyLinkedList::InsertAtTail(string GeoID,string Name)
{
	for(int i=0;i<Name.length();i++)
	{
		Name[i]=tolower(Name[i]);
	}
	
	if(Tail!=0)
	{
		Tail=new DSLNode(GeoID,Name,0,Tail);
		Tail->previous->next=Tail;
	}
	else
		Head=Tail=new DSLNode(GeoID,Name);
	
	if(tolower(Name[0])=='a')
		AlphabetsCounters[0]++;
	else if(tolower(Name[0])=='b')
		AlphabetsCounters[1]++;
	else if(tolower(Name[0])=='c')
		AlphabetsCounters[2]++;
	else if(tolower(Name[0])=='d')
		AlphabetsCounters[3]++;
	else if(tolower(Name[0])=='e')
		AlphabetsCounters[4]++;
	else if(tolower(Name[0])=='f')
		AlphabetsCounters[5]++;
	else if(tolower(Name[0])=='g')
		AlphabetsCounters[6]++;
	else if(tolower(Name[0])=='h')
		AlphabetsCounters[7]++;
	else if(tolower(Name[0])=='i')
		AlphabetsCounters[8]++;
	else if(tolower(Name[0])=='j')
		AlphabetsCounters[9]++;
	else if(tolower(Name[0])=='k')
		AlphabetsCounters[10]++;
	else if(tolower(Name[0])=='l')
		AlphabetsCounters[11]++;
	else if(tolower(Name[0])=='m')
		AlphabetsCounters[12]++;
	else if(tolower(Name[0])=='n')
		AlphabetsCounters[13]++;
	else if(tolower(Name[0])=='o')
		AlphabetsCounters[14]++;
	else if(tolower(Name[0])=='p')
		AlphabetsCounters[15]++;
	else if(tolower(Name[0])=='q')
		AlphabetsCounters[16]++;
	else if(tolower(Name[0])=='r')
		AlphabetsCounters[17]++;
	else if(tolower(Name[0])=='s')
		AlphabetsCounters[18]++;
	else if(tolower(Name[0])=='t')
		AlphabetsCounters[19]++;
	else if(tolower(Name[0])=='u')
		AlphabetsCounters[20]++;
	else if(tolower(Name[0])=='v')
		AlphabetsCounters[21]++;
	else if(tolower(Name[0])=='w')
		AlphabetsCounters[22]++;
	else if(tolower(Name[0])=='x')
		AlphabetsCounters[23]++;
	else if(tolower(Name[0])=='y')
		AlphabetsCounters[24]++;
	else if(tolower(Name[0])=='z')
		AlphabetsCounters[25]++;
	
	ListSize++;
	return true;
}
		// definition of Max method
int DoublyLinkedList::Max()
{
	DSLNode *current=Head;
	int Max=0,ind=0;
	for(int i=0;i<ListSize;i++)
	{
		int val=current->Name.length();
		if(Max<val)
		{
			ind=i;
			Max=val;
		}
		current=current->next;
	}
		
		return Max;
//	cout << "Maximum Node: " << Max;
//	cout << endl << "Maximum Node Index: " << ind << endl;
}
		// definition of DeleteAtTail method
bool DoublyLinkedList::DeleteAtTail()
{
	if(Head!=0)
	{
		DSLNode *current=Head;
		while(current->next!=Tail)
		{
			current=current->next;
		}
		Tail=current;
		Tail->next=0;
		ListSize--;
		return true;
	}
	return false;
}
		// definition of ReadFromFile_City method
void DoublyLinkedList::ReadFromFile_City()
{
	ifstream FileReading("admin_synonyms_US.csv");
	if(FileReading.is_open())
	{
		clock_t t1;
    	t1=clock();
		string read;
		cout << "File Loaded successfully" << endl;
		FileReading >> read;
//		cout << read;
		while(!FileReading.eof())
		{
			char Read;
			string CityName="",CityID="";
			while(!FileReading.eof())
			{
				FileReading >> Read;
				if(Read==',')
					break;
				else
					CityID+=Read;
			}
			while(!FileReading.eof())
			{
				FileReading >> Read;
				if(Read==',')
					break;
				else
					CityName+=Read;
			}
			FileReading >> read;
//			cout << read;
//			cout << endl;
//			cout << "City ID: " << CityID << "\tCity Name: " << CityName << "\tCityLength: " << CityName.length() << endl;
	//		cout << "City Length: " << CityName.length() << endl;
//			cout << endl;
			InsertAtTail(CityID,CityName);
//			break;
		}
		cout << endl;
		t1= clock()-t1;
		cout << "File Reading succesfully completed! " << endl;
		cout<< "Time: " << ((float) t1)/ CLOCKS_PER_SEC << " sec" << endl;
		cout << endl;
		DeleteAtTail();
	}
	else
	{
		cout << "Unable to open File";
	}
	FileReading.close();
	
	char var='A';
	for(int i=0;i<26;i++)
	{
		cout << "Counter of City Names starting with " << var << " : " << AlphabetsCounters[i] << endl;
		var++;
	}
}
		// definition of PrintList method
void DoublyLinkedList::PrintList()
{
	cout << "List Size: " << ListSize << endl;
	
}
		// definition of RadixSort method
void DoublyLinkedList::RadixSort()
{	
	DSLNode *current=Head;
	Queue OriginalDataName;
	Queue OriginalDataID;	
	while(current!=0)
	{
		OriginalDataName.EnQueue(current->Name);
		OriginalDataID.EnQueue(current->GeographicalID);
		current=current->next;
	}
//	cout << "Size of Name Queue: " << OriginalDataName.GetQueueSize() << "   Size of ID Queue: " << OriginalDataID.GetQueueSize() << endl;

	int MaxNodeSize=Max();
//	cout << "Max Node Size: " << MaxNodeSize;

	for(int i=1;i<=1;i++)
	{
		int LengthOfQueue=OriginalDataName.GetQueueSize();
		Queue SortedName[27];
		Queue SortedID[27];
//		cout << "I'm here!" << endl;
		for(int j=0;j<LengthOfQueue;j++)
		{
//			cout << "Inside j" << endl;
			string NodeDataName=OriginalDataName.DeQueue();
			string NodeDataID=OriginalDataID.DeQueue();
			int NodeValue=int(NodeDataName[0]);
			NodeValue=NodeValue - 97;
//			cout << NodeValue << endl;
			if(NodeValue >= 0 && NodeValue<=25)
			{
				SortedName[NodeValue].EnQueue(NodeDataName);
				SortedID[NodeValue].EnQueue(NodeDataID);
			}
			else
			{
				SortedName[26].EnQueue(NodeDataName);
				SortedID[26].EnQueue(NodeDataID);
			}
		}
//		cout << "Queue of Original name: " << OriginalDataName.GetQueueSize() << endl;
//		cout << "Queue of Original id  : " << OriginalDataID.GetQueueSize() << endl;
		for(int j=0;j<27;j++)
		{
			int NodeSize=SortedName[j].GetQueueSize();
			for(int k=0;k<NodeSize;k++)
			{
				string DeQueuedNodeName=SortedName[j].DeQueue();
				string DeQueuedNodeID=SortedID[j].DeQueue();
//				cout << DeQueuedNodeName << "  " << DeQueuedNodeID << endl;
				OriginalDataName.EnQueue(DeQueuedNodeName);
				OriginalDataID.EnQueue(DeQueuedNodeID);
			}
		}
		cout << "Queue of Original name: " << OriginalDataName.GetQueueSize() << endl;
		cout << "Queue of Original id  : " << OriginalDataID.GetQueueSize() << endl;
		cout << endl;
	}
	for(int j=0;j<ListSize;j++)
		cout << OriginalDataName.DeQueue() << "  " << OriginalDataID.DeQueue() << endl;	
}
		
		// driver program
int main()
{
	DoublyLinkedList city;
	city.ReadFromFile_City();
	city.PrintList();
	city.RadixSort();
//	city.PrintList();

	
	return 0;
}
