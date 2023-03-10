#include<iostream>
#include<Windows.h>
     
using namespace std;

class Bank{
    private:
    int total=0;
    string id;
    struct person{
        string Name,ID,Address;
        int Contact,Cash;
    }person[100];

    public:
        Bank(){
            total=0;
        }
        void choice(); 
        void perdata();
        void show(); 
        void update(); 
        void search();
        void transactions();
        void del();

};

void Bank::choice(){

    int a;
    bool flag=true;
    while(flag){
    cout<<"\nPress..!"<<endl;
    cout<<"1. Create a new account"<<endl;
    cout<<"2. View costumer list"<<endl;
    cout<<"3. Update information of existing account"<<endl;
    cout<<"4. Check the details of an existing account"<<endl;
    cout<<"5. For transactions"<<endl;
    cout<<"6. Remove existing account"<<endl;
    cout<<"7. Exit"<<endl;
    
    cin>>a;

        switch(a){
            case 1:
                Bank::perdata();
                break;
            case 2:
                if(total==0){
                    cout<<"No data found"<<endl;
                }else{
                Bank::show();
                }
                break;
            case 3:
             if(total==0){
                    cout<<"No data is entered"<<endl;
                }else{    
                Bank::update();
                }
                break;
            case 4:
             if(total==0){
                    cout<<"No data is entered"<<endl;
                }else{
                Bank::search();
                }
                break;
            case 5:
                if(total==0){
                    cout<<"No data is entered"<<endl;
                }else{   
                Bank::transactions();
                }                
                break;
            case 6:
                if(total==0){
                    cout<<"No data is entered"<<endl;
                }else{   
                Bank::del();
                }
                break;  
            case 7:
                exit(0);
                break;
            default:
            flag=false;
                cout<<"Invalid Input"<<endl;
                break; 
                         
        }

    }
}
void Bank::perdata(){
    cout<<"Enter data of person"<<total+1<<endl;
    cout<<"Enter name: "<<endl;
    cin>>person[total].Name;
    cout<<"Enter ID: "<<endl;
    cin>>person[total].ID;
    cout<<"Enter Addres: "<<endl;
    cin>>person[total].Address;
    cout<<"Enter Contact: "<<endl;
    cin>>person[total].Contact;
    cout<<"Total Cash: "<<endl;
    cin>>person[total].Cash;
    total++;
}
void Bank::show(){
    for(int i=0; i<total; i++){
        cout<<"Data of person "<<i+1<<endl;
        cout<<"Name: "<<person[i].Name<<endl;
        cout<<"ID: "<<person[i].ID<<endl;
        cout<<"Address: "<<person[i].Address<<endl;
        cout<<"Contact: "<<person[i].Contact<<endl;
        cout<<"Cash: "<<person[i].Cash<<endl;
        
    }
}
void Bank::update(){
    cout<<"Enter ID of person to update data: "<<endl;
    cin>>id;
   
    for(int i=0; i<total; i++){
        if(id==person[i].ID){
            
            cout<<"Perevious Data: "<<endl;
                
                cout<<"Data of person "<<i+1<<endl;
                cout<<"Name: "<<person[i].Name<<endl;
                cout<<"ID: "<<person[i].ID<<endl;
                cout<<"Address: "<<person[i].Address<<endl;
                cout<<"Contact: "<<person[i].Contact<<endl;
                cout<<"Cash: "<<person[i].Cash<<endl;
            
            cout<<"Enter new data: "<<endl;
            
                cout<<"Enter name: "<<endl;
                cin>>person[i].Name;
                cout<<"Enter ID: "<<endl;
                cin>>person[i].ID;
                cout<<"Enter Addres: "<<endl;
                cin>>person[i].Address;
                cout<<"Enter Contact: "<<endl;
                cin>>person[i].Contact;
                cout<<"Total Cash: "<<endl;
                cin>>person[i].Cash;
                break;

        }
        if (i==total-1){
            cout<<"No such record found"<<endl;
        }   
    }

}
void Bank::search(){
    cout<<"Enter ID of person to search data: "<<endl;
    cin>>id;
    for(int i=0; i<total; i++){
       
        if(id==person[i].ID){
            cout<<"Data of person "<<i+1<<endl;
            cout<<"Name: "<<person[i].Name<<endl;
            cout<<"ID: "<<person[i].ID<<endl;
            cout<<"Address: "<<person[i].Address<<endl;
            cout<<"Contact: "<<person[i].Contact<<endl;
            cout<<"Cash: "<<person[i].Cash<<endl; 
            break;   
        }
         if (i==total-1){
            cout<<"No such record found"<<endl;
           }
    }
}
void Bank::transactions(){
    int b;
    int cash;
    cout<<"Enter ID of person to perform transaction: "<<endl;
    cin>>id;

        for(int i=0; i<total; i++){
       
            if(id==person[i].ID){
                
                cout<<"Name: "<<person[i].Name<<endl;
                cout<<"ID: "<<person[i].ID<<endl;
                cout<<"Address: "<<person[i].Address<<endl;

                cout<<"\nExisting Cash: "<<person[i].Cash<<endl;
                cout<<"Press 1 to deposit"<<endl;
                cout<<"Press 2 to withdraw"<<endl;
                
            cin>>b;

            switch(b){
                case 1:
                    cout<<"How much cash do you want to deposit: "<<endl;
                    cin>>cash;
                    person[i].Cash+=cash;
                    cout<<"Your new cash is: "<<person[i].Cash<<endl;
                    break;
                case 2:
                    back:
                    cout<<"How much cash do you want to withdraw: "<<endl;
                    cin>>cash;
                    
                    if (cash>person[i].Cash){
                        cout<<"Your exisiting cash is just: "<<person[i].Cash<<endl;
                            Sleep(3000);
                            goto back;
                    }
                    
                    person[i].Cash-=cash;
                        cout<<"Your new cash is: "<<person[i].Cash<<endl;
                        break;
                    
                    //if user give wrong input.
                    default:
                        cout<<"Invalid input"<<endl;
                        break;
                
                    }
            break;
            }
                if (i==total-1){
                    cout<<"No such record found"<<endl;
                    }
    }

}
void Bank::del(){
    int c;
    
    cout<<"Press 1 to remove specific record"<<endl;
    cout<<"Press 2 to remove full record"<<endl;
    cin>>c;

    switch(c){
        case 1:
            cout<<"Enter id of person you want to delete: "<<endl;
            cin>>id;
           
            for(int i=0; i<total; i++){
                if(id==person[i].ID){
                    for(int j=i; j<total; j++){
                         person[j].Name=person[j+1].Name;
                        person[j].ID=person[j+1].Name;
                        person[j].Address=person[j+1].Name;
                        person[j].Contact=person[j+1].Contact;
                        person[j].Cash=person[j+1].Cash;
                        total--;
                        cout<<"Your required data is deleted"<<endl;
                        break;
                   }
            }
            if (i==total-1){
                    cout<<"No such record found"<<endl;
                    }
        }
            break;
        case 2:
            total=0;
            cout<<"All record is deleted"<<endl;
            break;
        default:
            cout<<"Invalid Input"<<endl;
            break;    
    }
}
int main(){
    Bank b;
    b.choice();
    return 0;
}