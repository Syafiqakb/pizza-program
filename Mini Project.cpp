#include<iostream>
#include<string>
#include <fstream>

using namespace std;
class product{
	public:
		string name;
		int price;
		int price_box;
};
class transaction
{
    public:
    product* data;
    int quantity;
    string type;
    int total;
};
class receipt
{
    public:
    string name;
    string method;
    transaction* data[100];
    int amount;
    int total;
    receipt* next;
};

void push(receipt** head_ref, receipt** node)
{
    /* 1. allocate node */
    receipt* new_node = new receipt();
 
    receipt *last = *head_ref; /* used in step 5*/
 
    /* 2. put in the data */
    new_node=*node;
 
    new_node->next = NULL;
 
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
 
    last->next = new_node;
    return;
}

void display(receipt *node)
{
	int i=0;
    while (node != NULL)
    {
        cout<<"Data "<<i+1<<endl
			<<"Name : "<<node->name<<endl
			<<"Order :"<<endl;
		for(int j=0;j<node->amount;j++){
			cout<<"\t"<<node->data[j]->data->name<<"\t"<<node->data[j]->quantity<<"\t"<<node->data[j]->total<<endl;
		}
		cout<<"Payment Method: "<<node->method<<endl;
		cout<<"Grand Total: "<<node->total<<endl;
		i++;
		node=node->next;
    }
}

int main()
{
    
    receipt* head =NULL;
    receipt* arr;
    product* data[100];
    int n=0;
    int m=0;
    while(true){
    	cout<<"<<<<<<<<<<<<< LOGIN >>>>>>>>>>>>>>"<<endl
			<<"----------------------------------"<<endl
			<<"1. Staff"<<endl
			<<"2. Costumer"<<endl
			<<"3. EXIT"<<endl
			<<"Enter your choice: ";
		string choice;
		cin>>choice;
		if(choice=="1"){
			while(true){
		    	cout<<"----------------------------------"<<endl;
				cout<<"MENU"<<endl
					<<"----------------------------------"<<endl
					<<"1. Add Pizza"<<endl
					<<"2. Show Pizza"<<endl
					<<"3. Edit Pizza"<<endl
					<<"4. Delete Pizza"<<endl
					<<"5. Find Pizza"<<endl
					<<"6. History"<<endl
					<<"7. EXIT"<<endl
					<<"Enter your choice : ";
				cin>>choice;
				if(choice=="1"){
					data[n] = new product();
					cout<<"Enter Pizza name : ";
					getline(cin,data[n]->name);
					getline(cin,data[n]->name);
					cout<<"Price of Pizza Per slice: ";
					cin>>data[n]->price;
					cout<<"Price of Pizza Per pan: ";
					cin>>data[n]->price_box;
					n++;
					cout<<"Data added successfully\n\n";
					
				}
				else if(choice =="2"){
					string myText;
					ifstream MyReadFile("pizza.txt");
					while (getline (MyReadFile, myText)) {
  					cout << myText << "\n";
					}
					MyReadFile.close();
					for(int i=0;i<n;i++){
						cout<<"Data "<<i+1<<endl
							<<"Name : "<<data[i]->name<<endl
							<<"Price of Pizza Per slice : "<<data[i]->price<<endl
							<<"Price of Pizza Per pan : "<<data[i]->price_box<<endl<<endl<<endl;
					}
				}
				else if(choice =="3"){
					for(int i=0;i<n;i++){
						cout<<"Data "<<i+1<<endl
							<<"Name : "<<data[i]->name<<endl
							<<"Price of Pizza Per slice : "<<data[i]->price<<endl
							<<"Price of Pizza Per pan : "<<data[i]->price_box<<endl<<endl<<endl;
					}
					int index;
					cout<<"Enter the index of the data you want to change: ";
					cin>>index;
					index--;
					cout<<"Enter pizza name : ";
					getline(cin,data[index]->name);
					getline(cin,data[index]->name);
					cout<<"Price of Pizza Per slice: ";
					cin>>data[index]->price;
					cout<<"Price of Pizza Per pan: ";
					cin>>data[index]->price_box;
					cout<<"Data changed successfully\n\n";
					
				}
				else if(choice =="4"){
					for(int i=0;i<n;i++){
						cout<<"Data "<<i+1<<endl
							<<"Name : "<<data[i]->name<<endl
							<<"Price of Pizza Per slice : "<<data[i]->price<<endl
							<<"Price of Pizza Per pan : "<<data[i]->price_box<<endl<<endl<<endl;
					}
					int index;
					cout<<"Enter the index of the data you want to delete ";
					cin>>index;
					index--;
					n--;
					data[index]->name = data[n]->name;
					data[index]->price_box = data[n]->price_box;
					data[index]->price = data[n]->price;
					cout<<"Data deleted successfully\n\n";
					
				}
				else if(choice =="5"){
					string name;
					cout<<"Name Pizza: ";
					getline(cin,name);
					int ada=0;
					for(int i=0;i<n;i++){
						if(name == data[i]->name){
							ada=1;
							cout<<"Name : "<<data[i]->name<<endl
								<<"Price of Pizza Per slice : "<<data[i]->price<<endl
								<<"Price of Pizza Per pan : "<<data[i]->price_box<<endl<<endl<<endl;
						}
					}
					if(ada==0){
						cout<<"Data not found\n";
					}
					
				}
				else if(choice =="6"){
					display(head);
					
				}
				else if(choice =="7"){
					break;
				}
			}
		}
		else if(choice == "2"){
			cout<<"Enter Customer Name :";
			arr = new receipt();
			getline(cin,arr->name);
			getline(cin,arr->name);
			int dum=0;
			arr->amount=0;
			arr->total=0;
			while(true){
		    	cout<<"----------------------------------"<<endl
					<<"COSTUMER MENU"<<endl
					<<"----------------------------------"<<endl
					<<"1. Show Pizza"<<endl
					<<"2. Order Pizza"<<endl
					<<"3. Find Pizza"<<endl
					<<"4. EXIT"<<endl
					<<"Enter your choice : ";
				cin>>choice;
				if(choice =="1"){
					cout<<"-----------Pizza Menu----------- "<<endl;
					string myText;
					ifstream MyReadFile("pizza.txt");
					while (getline (MyReadFile, myText)) {
  					cout << myText << "\n";
					}
					MyReadFile.close();
					for(int i=0;i<n;i++){
						cout<<"Data "<<i+1<<endl
							<<"Name : "<<data[i]->name<<endl
							<<"Price of Pizza Per slice : "<<data[i]->price<<endl
							<<"Price of Pizza Per pan : "<<data[i]->price_box<<endl<<endl<<endl;
					}
				}
				else if(choice =="2"){
					for(int i=0;i<n;i++){
						cout<<"Data "<<i+1<<endl
							<<"Name : "<<data[i]->name<<endl
							<<"Price of Pizza Per slice : "<<data[i]->price<<endl
							<<"Price of Pizza Per pan : "<<data[i]->price_box<<endl<<endl<<endl;
					}
					int index;
					arr->data[dum]= new transaction();
					cout<<"Enter the data index you want to order : ";
					cin>>index;
					index--;
					arr->data[dum]->data=data[index];
					cout<<"Enter the type of pizza [slice / pan]:: ";
					cin>>arr->data[dum]->type;
					cout<<"Quantity : ";
					cin>>arr->data[dum]->quantity;
					if(arr->data[dum]->type=="slice"){
						arr->data[dum]->total=arr->data[dum]->data->price*arr->data[dum]->quantity;
					}
					else{
						arr->data[dum]->total=arr->data[dum]->data->price_box*arr->data[dum]->quantity;
					}
					arr->total+=arr->data[dum]->total;
					dum++;
					arr->amount++;
					cout<<"You Order Successfully. Type 4 to proceed to payment\n\n";
					
				}
				else if(choice =="3"){
					string name;
					cout<<"Name Pizza: ";
					getline(cin,name);
					int ada=0;
					for(int i=0;i<n;i++){
						if(name == data[i]->name){
							ada=1;
							cout<<"Name : "<<data[i]->name<<endl
								<<"Price of Pizza Per slice : "<<data[i]->price<<endl
								<<"Price of Pizza Per pan : "<<data[i]->price_box<<endl<<endl<<endl;
						}
					}
					if(ada==0){
						cout<<"Data not found\n";
					}
					
				}
				else if(choice =="4"){
					cout<<"------------Receipt------------ "<<endl;
					cout<<"Name : "<<arr->name<<endl
						<<"Order :"<<endl;
					cout<<"\t"<<"Pizza"<<"\t"<<"quantity"<<"\t"<<"total"<<endl;
					for(int j=0;j<arr->amount;j++){
						cout<<"\t"<<arr->data[j]->data->name<<"\t"<<arr->data[j]->quantity<<"\t"<<arr->data[j]->total<<endl;
					}
					cout<<"Grand Total: "<<arr->total<<endl;
					cout<<"Payment Method : ";
					cin>>arr->method;
					cout<<"Go to the cash register for payment \n"<<endl;
					cout<<"Thank You \n"<<endl;
					cout<<"------------------------------- "<<endl<<endl;
					push(&head,&arr);
					break;
				}
			}
		}
		
		else if(choice=="3"){
			break;
		}
	}
     
    return 0;
}
