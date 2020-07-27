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
		DSLNode *ptrA,*ptrB,*ptrC,*ptrD,*ptrE,*ptrF,*ptrG,*ptrH,*ptrI,*ptrJ,*ptrK,*ptrL,*ptrM,*ptrN,*ptrO,*ptrP,*ptrQ,*ptrR,*ptrS,*ptrT,*ptrU,*ptrV,*ptrW,*ptrX,*ptrY,*ptrZ,*ptrSp;
	public:
		DoublyLinkedList();														// default constructor
		bool InsertAtHead(string GeoID,string Name);							// method to insert a node at head
		bool InsertAtTail(string GeoID,string Name);							// method to insert a node at tail
		bool DeleteAtHead();													// method to delete a node from head
		bool DeleteAtTail();													// method to delete a node from tail
		void PrintList();														// method to print the entire contents of list
		void ReadFromFile_City();												// method to read .csv file of city and synonyms
		void ReadFromFile_Country();											// method to read .csv file of country and synonyms
		void ReadFromFile_State();												// method to read .csv file of state and synonyms
		int Max();																// method to find the maximum length of name in the entire list
		void RadixSort();														// method to sort the entire contents of data
		void OverRideData(int index,string ID,string Name);						// method for overriding the data at the specified index
		void SelectionSorting();												// Selection sorting method to sort the data as per the length
		void SetPointers();														// Setting Pointers
};
		// definition of default constructor
DoublyLinkedList::DoublyLinkedList():Head(0),Tail(0),ListSize(0)
{
	AlphabetsCounters=new int[26];
	memset(AlphabetsCounters,0,sizeof(int)*26);
	
	ptrA=ptrB=ptrC=ptrD=ptrE=ptrF=ptrG=ptrH=ptrI=ptrJ=ptrK=ptrL=ptrM=ptrN=ptrO=ptrP=ptrQ=ptrR=ptrS=ptrT=ptrU=ptrV=ptrW=ptrX=ptrY=ptrZ=ptrSp=0;
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
		// definition of OverRideData method
void DoublyLinkedList::OverRideData(int index,string ID,string Name)
{
	if(Head!=0)
	{
		int Counter=0;
		DSLNode *Current=Head;
		while(Counter!=index)
		{
			Current=Current->next;
			Counter++;
		}
//		cout << Current->Name << "  " <<Current->GeographicalID << endl;
		Current->Name=Name;
		Current->GeographicalID=ID;
//		cout << Current->Name << "  " <<Current->GeographicalID;
	}
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
//	cout << "List Size: " << ListSize << endl;
	DSLNode *Current=Head;
	for(int i=0;i<ListSize;i++)
	{
		cout << Current->GeographicalID << "   " << Current->Name << endl;
		Current=Current->next;
	}

	
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
//		cout << "Queue of Original name: " << OriginalDataName.GetQueueSize() << endl;
//		cout << "Queue of Original id  : " << OriginalDataID.GetQueueSize() << endl;
//		cout << endl;
	}
	for(int j=0;j<ListSize;j++)
	{
		OverRideData(j,OriginalDataID.DeQueue(),OriginalDataName.DeQueue());
	}
}
		// definition of SetPointers method
void DoublyLinkedList::SetPointers()
{
	DSLNode *current=Head;
			// loop for setting pointer to A
	while(current!=0)
	{
		if(current->Name[0]=='a')
		{
			ptrA=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}	
		current=current->next;
	}
			// loop for setting pointer to B
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='b')
		{
			ptrB=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to C
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='c')
		{
			ptrC=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to D
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='d')
		{
			ptrD=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to E
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='e')
		{
			ptrE=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to F
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='f')
		{
			ptrF=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to G
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='g')
		{
			ptrG=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to H
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='h')
		{
			ptrH=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to I
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='i')
		{
			ptrI=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to J
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='j')
		{
			ptrJ=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to K
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='k')
		{
			ptrK=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to L
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='l')
		{
			ptrL=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to M
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='m')
		{
			ptrM=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to N
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='n')
		{
			ptrN=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to O
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='o')
		{
			ptrO=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to P
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='p')
		{
			ptrP=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to Q
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='q')
		{
			ptrQ=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to R
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='r')
		{
			ptrR=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to S
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='s')
		{
			ptrS=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to T
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='t')
		{
			ptrT=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to U
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='u')
		{
			ptrU=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to V
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='v')
		{
			ptrV=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to W
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='w')
		{
			ptrW=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to X
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='x')
		{
			ptrX=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to Y
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='y')
		{
			ptrY=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to Z
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]=='z')
		{
			ptrZ=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
			// loop for setting pointer to Special Characters
	current=Head;
	while(current!=0)
	{
		if(current->Name[0]<'a' || current->Name[0]>'z')
		{
			ptrSp=current;//new DSLNode(current->Name,current->GeographicalID,current->next);
			break;
		}
		current=current->next;
	}
	
//	if(ptrA!=0)
//		cout << "PtrA is Pointing to: " << ptrA->Name << endl;
//	if(ptrB!=0)
//		cout << "PtrB is Pointing to: " << ptrB->Name << endl;
//	if(ptrC!=0)
//		cout << "PtrC is Pointing to: " << ptrC->Name << endl;
//	if(ptrD!=0)
//		cout << "PtrD is Pointing to: " << ptrD->Name << endl;
//	if(ptrE!=0)
//		cout << "PtrE is Pointing to: " << ptrE->Name << endl;	
//	if(ptrF!=0)
//		cout << "PtrF is Pointing to: " << ptrF->Name << endl;
//	if(ptrG!=0)
//		cout << "PtrG is Pointing to: " << ptrG->Name << endl;
//	if(ptrH!=0)
//		cout << "PtrH is Pointing to: " << ptrH->Name << endl;
//	if(ptrI!=0)
//		cout << "PtrI is Pointing to: " << ptrI->Name << endl;
//	if(ptrJ!=0)
//		cout << "PtrJ is Pointing to: " << ptrJ->Name << endl;
//	if(ptrK!=0)
//		cout << "PtrK is Pointing to: " << ptrK->Name << endl;
//	if(ptrL!=0)
//		cout << "PtrL is Pointing to: " << ptrL->Name << endl;
//	if(ptrM!=0)
//		cout << "PtrM is Pointing to: " << ptrM->Name << endl;
//	if(ptrN!=0)
//		cout << "PtrN is Pointing to: " << ptrN->Name << endl;
//	if(ptrO!=0)
//		cout << "PtrO is Pointing to: " << ptrO->Name << endl;
//	if(ptrP!=0)
//		cout << "PtrP is Pointing to: " << ptrP->Name << endl;
//	if(ptrQ!=0)
//		cout << "PtrQ is Pointing to: " << ptrQ->Name << endl;
//	if(ptrR!=0)
//		cout << "PtrR is Pointing to: " << ptrR->Name << endl;
//	if(ptrS!=0)
//		cout << "PtrS is Pointing to: " << ptrS->Name << endl;
//	if(ptrT!=0)
//		cout << "PtrT is Pointing to: " << ptrT->Name << endl;
//	if(ptrU!=0)
//		cout << "PtrU is Pointing to: " << ptrU->Name << endl;
//	if(ptrV!=0)
//		cout << "PtrV is Pointing to: " << ptrV->Name << endl;
//	if(ptrW!=0)
//		cout << "PtrW is Pointing to: " << ptrW->Name << endl;
//	if(ptrX!=0)
//		cout << "PtrX is Pointing to: " << ptrX->Name << endl;
//	if(ptrY!=0)
//		cout << "PtrY is Pointing to: " << ptrY->Name << endl;
//	if(ptrZ!=0)
//		cout << "PtrZ is Pointing to: " << ptrZ->Name << endl;
//	if(ptrSp!=0)
//		cout << "PtrSp is Pointing to: " << ptrSp->Name << endl;
}
		// definition fo SelectionSorting method
void DoublyLinkedList::SelectionSorting()
{
	// selection sorting algorithm on for nodes starting with A
	
//	while(current!=ptrB || current!=ptrC || current!=ptrD || current!=ptrE || current!=ptrF || current!=ptrG || current!=ptrH || current!=ptrI || current!=ptrJ || current!=ptrK || current!=ptrL || current!=ptrM || current!=ptrN || current!=ptrO || current!=ptrP || current!=ptrQ || current!=ptrR || current!=ptrS || current!=ptrT || current!=ptrU || current!=ptrV || current!=ptrW || current!=ptrX || current!=ptrY || current!=ptrZ || current!=ptrSp)
//	{
//		cout << current->GeographicalID << "  " << current->Name;
//		current=current->next;
//	}

		// selection sorting algorithm for nodes starting with A
	if(ptrA!=0)
	{
		DSLNode *current=ptrA;
		for(int i=0;i<AlphabetsCounters[0];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[0];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
		// selection sorting algorithm for nodes starting with B
	if(ptrB!=0)
	{
		DSLNode *current=ptrB;
		for(int i=0;i<AlphabetsCounters[1];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[1];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
		// selection sorting algorithm for nodes starting with C
	if(ptrC!=0)
	{
		DSLNode *current=ptrC;
		for(int i=0;i<AlphabetsCounters[2];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[2];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
		// selection sorting algorithm for nodes starting with D
	if(ptrD!=0)
	{
		DSLNode *current=ptrD;
		for(int i=0;i<AlphabetsCounters[3];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[3];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
		// selection sorting algorithm for nodes starting with E
	if(ptrE!=0)
	{
		DSLNode *current=ptrE;
		for(int i=0;i<AlphabetsCounters[4];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[4];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
		// selection sorting algorithm for nodes starting with F
	if(ptrF!=0)
	{
		DSLNode *current=ptrF;
		for(int i=0;i<AlphabetsCounters[5];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[5];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
		// selection sorting algorithm for nodes starting with G
	if(ptrG!=0)
	{
		DSLNode *current=ptrG;
		for(int i=0;i<AlphabetsCounters[6];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[6];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
		// selection sorting algorithm for nodes starting with H
	if(ptrH!=0)
	{
		DSLNode *current=ptrH;
		for(int i=0;i<AlphabetsCounters[7];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[7];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
		// selection sorting algorithm for nodes starting with I
	if(ptrI!=0)
	{
		DSLNode *current=ptrI;
		for(int i=0;i<AlphabetsCounters[8];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[8];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
		// selection sorting algorithm for nodes starting with J
	if(ptrJ!=0)
	{
		DSLNode *current=ptrJ;
		for(int i=0;i<AlphabetsCounters[9];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[9];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
		// selection sorting algorithm for nodes starting with K
	if(ptrK!=0)
	{
		DSLNode *current=ptrK;
		for(int i=0;i<AlphabetsCounters[10];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[10];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
		// selection sorting algorithm for nodes starting with L
	if(ptrL!=0)
	{
		DSLNode *current=ptrL;
		for(int i=0;i<AlphabetsCounters[11];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[11];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
		// selection sorting algorithm for nodes starting with M
	if(ptrM!=0)
	{
		DSLNode *current=ptrM;
		for(int i=0;i<AlphabetsCounters[12];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[12];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
	if(ptrN!=0)
	{
		DSLNode *current=ptrN;
		for(int i=0;i<AlphabetsCounters[13];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[13];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
	if(ptrO!=0)
	{
		DSLNode *current=ptrO;
		for(int i=0;i<AlphabetsCounters[14];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[14];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
	if(ptrP!=0)
	{
		DSLNode *current=ptrP;
		for(int i=0;i<AlphabetsCounters[15];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[15];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
	if(ptrQ!=0)
	{
		DSLNode *current=ptrQ;
		for(int i=0;i<AlphabetsCounters[16];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[16];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
	if(ptrR!=0)
	{
		DSLNode *current=ptrR;
		for(int i=0;i<AlphabetsCounters[17];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[17];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}if(ptrS!=0)
	{
		DSLNode *current=ptrS;
		for(int i=0;i<AlphabetsCounters[18];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[18];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}if(ptrT!=0)
	{
		DSLNode *current=ptrT;
		for(int i=0;i<AlphabetsCounters[19];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[19];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}if(ptrU!=0)
	{
		DSLNode *current=ptrU;
		for(int i=0;i<AlphabetsCounters[20];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[20];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
	if(ptrV!=0)
	{
		DSLNode *current=ptrV;
		for(int i=0;i<AlphabetsCounters[21];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[21];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
	if(ptrW!=0)
	{
		DSLNode *current=ptrW;
		for(int i=0;i<AlphabetsCounters[22];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[22];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
	if(ptrX!=0)
	{
		DSLNode *current=ptrX;
		for(int i=0;i<AlphabetsCounters[23];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[23];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
	if(ptrY!=0)
	{
		DSLNode *current=ptrY;
		for(int i=0;i<AlphabetsCounters[24];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[24];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
	if(ptrZ!=0)
	{
		DSLNode *current=ptrZ;
		for(int i=0;i<AlphabetsCounters[25];i++)
		{
			DSLNode *min=current;
			DSLNode *temp=current->next;
			for(int j=i+1;j<AlphabetsCounters[25];j++)
			{
				if(min->Name.length() > temp->Name.length())
					min=temp;
				
				temp=temp->next;
			}
			if(min!=current)
			{
				string newNodeName=current->Name;
				string newNodeID=current->GeographicalID;
				current->Name=min->Name;
				current->GeographicalID=min->GeographicalID;
				min->Name=newNodeName;
				min->GeographicalID=newNodeID;
			}
			current=current->next;
		}
	}
	
}
		
		// driver program
int main()
{
	DoublyLinkedList city;
	city.ReadFromFile_City();
	cout << endl;
	city.RadixSort();
	city.SetPointers();
	city.SelectionSorting();
	city.PrintList();
	return 0;
}
