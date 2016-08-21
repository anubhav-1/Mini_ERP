# include <iostream>
# include <cstring>
# include <fstream>
# include <ctime>

class address {
		public: 
		int house_number;
		char street[100];
		char district[100];
		char state[100];
		char country[100];
	    void inputaddress(void);
	    void outaddress(void);
		
	} ;	
	
	void address :: inputaddress(void)
	{
		fflush(stdin);
		fflush(stdin);
		std:: cout << "\n Please Enter your address\n House Number:";
		
		std:: cin >> house_number;
		fflush(stdin);
		std:: cout << "\n Street:";
		gets(street);
		std:: cout << "\n District:";
		gets(district);
		std:: cout << "\n State:";
		gets(state);
		std:: cout << "\n Country:";
		gets(country);
		
		
	}
	
	void address::outaddress(void)
	{
		std:: cout<< "\n House number: "<< house_number;
		std:: cout<< "\n Street: "<< street;
		std:: cout<< "\n District: "<< district;
		std:: cout<< "\n State: "<< state;
		std:: cout<< "\n Country "<< country;
		std::cout<<"\n\n\n";
	}

class student : public address {
	  public:
	char name[100];
	int roll_number;
	char father[100];
    char branch[50];
    void input(void);
    void output(void);
    
};
void student::input(void){
	fflush(stdin);
	fflush(stdin);
	std:: cout << "\n Please input your details here \n Roll Number: ";
		
	std:: cin>> roll_number;
	fflush(stdin);
	std:: cout << "\n Name: ";
	gets(name);
	std:: cout << "\n Father's Name: ";
	gets(father);
	std:: cout << "\n Branch: ";
	gets(branch);
	
}

void student::output(void){
	std::cout<<"\n\n\n\nPlease verify your details:";
	std:: cout << "\n Roll number: "<<roll_number;
	std:: cout << "\n Name: "<<name;
	std:: cout << "\n Father's Name': "<<father;
	std:: cout << "\n Branch: "<<branch;
}



int main()
{
	using namespace std;
	int n;
	char date[9],choice,c;
	student s[100];
	std::cout << "\t\t\t\a Student's Registration software- beta\n";
	std::cout<< "\n 1. (Enter) Details\n 2. (Delete) a Record\n 3. (Update) Existing Record\n 4. (Show) Complete Record\n";
	std:: cin>> choice;
	fstream record;
	loop :{
	if (choice == 'e'){
	std::cout << "Please enter the number of students: ";
	std:: cin>> n;
	for(int i=0;i<n;i++){
		s[i].input();
		s[i].inputaddress();
		s[i].output();
		s[i].outaddress();
	
		 
		record.open("data.txt",ios::app);
		record << "\n Roll number: "<<s[i].roll_number;
		record << "\n Name: "<<s[i].name;
		record << "\n Father's Name: "<<s[i].father;
		record << "\n Branch: "<<s[i].branch;
		record << "\n House number: "<< s[i].house_number;
		record << "\n Street: "<< s[i].street;
		record << "\n District: "<< s[i].district;
		record << "\n State: "<< s[i].state;
		record << "\n Country: "<< s[i].country;
		_strdate(date);
	    record << endl<<date << endl;
		record << "\n\t\t\t *************************************************************************************";
		
		record.close();
		fflush(stdin);
		std::cout<<"\n\n Successful copied to file"; 
		
	}
    std::cout<<"\n Do you want to perform any other task?\n(y/n): ";
		std::cin>>c;
	if(c=='y'){
	std::cout<< "\n 1. (Enter) Details\n 2. (Delete) a Record\n 3. (Update) Existing Record\n 4. (Show) Complete Record\n";
	std::cin>> choice;
	goto loop;
	}

	


		
	}
	if (choice== 'd'){

		int del,index;
		std::cout<<"\n Please enter the roll number of the record to be deleted: ";
		std::cin>> del;
		
		fstream record;
		record.open("data.txt",ios:: in);
		for(int i=0;i<n;i++){
		record >> s[i].roll_number;
		record >> s[i].name;
		record >> s[i].father;
		record >> s[i].branch;
		record >> s[i].house_number;
		record >> s[i].street;
		record >> s[i].district;
		record >> s[i].state;
		record >> s[i].country;  
		
	
	record.close();
	}
	

	ofstream rrecord;
		rrecord.open("data.txt",ios::trunc);
		for(int i=0;i<n;i++){
			if(s[i].roll_number==del){
				index=i;

			}
		}

		for(int i=0;i<index;i++){
		rrecord << "\n Roll number: "<<s[i].roll_number;
		rrecord << "\n Name: "<<s[i].name;
		rrecord << "\n Father's Name: "<<s[i].father;
		rrecord << "\n Branch: "<<s[i].branch;
		rrecord << "\n House number: "<< s[i].house_number;
		rrecord << "\n Street: "<< s[i].street;
		rrecord << "\n District: "<< s[i].district;
		rrecord << "\n State: "<< s[i].state;
		rrecord << "\n Country: "<< s[i].country;
		rrecord<<"\n\n";
		_strdate(date);
	    record << endl<<date << endl;
		record << "\n\t\t\t *************************************************************************************";
		}
		for (int i=index+1;i<n;i++){
		rrecord << "\n Roll number: "<<s[i].roll_number;
		rrecord << "\n Name: "<<s[i].name;
		rrecord << "\n Father's Name: "<<s[i].father;
		rrecord << "\n Branch: "<<s[i].branch;
		rrecord << "\n House number: "<< s[i].house_number;
		rrecord << "\n Street: "<< s[i].street;
		rrecord << "\n District: "<< s[i].district;
		rrecord << "\n State: "<< s[i].state;
		rrecord << "\n Country: "<< s[i].country;
			rrecord<<"\n\n";
		_strdate(date);
	    record << endl<<date << endl;
		record << "\n\t\t\t *************************************************************************************";
		}
	

       rrecord.close();
	   std::cout<<"\n Record Deleted ...";
	   std::cout<<"\n Do you want to perform any other task?\n(y/n): ";
		std::cin>>c;
	if(c=='y'){
	std::cout<< "\n 1. (Enter) Details\n 2. (Delete) a Record\n 3. (Update) Existing Record\n 4. (Show) Complete Record\n";
	std::cin>> choice;
	goto loop;
	}
	}

	if(choice=='u'){

		std::cout<<"\n Please enter the roll number of the record to be updated: ";
		int up,holder;
		std::cin>> up;
		std::cout<< "\n Here is the previous record ";
		ifstream urecord;
		urecord.open("data.txt",ios::in);
		for(int i=0;i<n;i++){
			if(s[i].roll_number==up){
				holder=i;
		urecord >> s[i].roll_number;
		urecord >> s[i].name;
		urecord >> s[i].father;
		urecord >> s[i].branch;
		urecord >> s[i].house_number;
		urecord >> s[i].street;
		urecord >> s[i].district;
		urecord >> s[i].state;
		urecord >> s[i].country;  

	
		std::cout << "\n Roll number: "<<s[i].roll_number;
		std::cout << "\n Name: "<<s[i].name;
		std::cout << "\n Father's Name: "<<s[i].father;
		std::cout << "\n Branch: "<<s[i].branch;
		std::cout << "\n House number: "<< s[i].house_number;
		std::cout << "\n Street: "<< s[i].street;
		std::cout << "\n District: "<< s[i].district;
		std::cout << "\n State: "<< s[i].state;
		std::cout << "\n Country: "<< s[i].country;
		urecord.close();
		std::cout<<"\n Do you want to edit it (y/n)";
		char inf;
		std::cin>> inf;
		if(inf=='y'|| inf=='Y'){
		s[holder].input();
		s[holder].inputaddress();
		s[holder].output();
		s[holder].outaddress();
			ifstream uprecord;
			uprecord.open("data.txt",ios::in);
			for(int i=0;i<n;i++){
		uprecord >> s[i].roll_number;
		uprecord >> s[i].name;
		uprecord >> s[i].father;
		uprecord >> s[i].branch;
		uprecord >> s[i].house_number;
		uprecord >> s[i].street;
		uprecord >> s[i].district;
		uprecord >> s[i].state;
		uprecord >> s[i].country;
			}
			uprecord.close();

			fstream upprecord;
			upprecord.open("tdata.txt",ios::out);
			for (int i=0;i<holder;i++){                                     // n-> holder
		upprecord << "\n Roll number: "<<s[i].roll_number;
		upprecord << "\n Name: "<<s[i].name;
		upprecord << "\n Father's Name: "<<s[i].father;
		upprecord << "\n Branch: "<<s[i].branch;
		upprecord << "\n House number: "<< s[i].house_number;
		upprecord << "\n Street: "<< s[i].street;
		upprecord << "\n District: "<< s[i].district;
		upprecord << "\n State: "<< s[i].state;
		upprecord << "\n Country: "<< s[i].country;
		_strdate(date);
	    record << endl<<date << endl;
		record << "\n\t\t\t *************************************************************************************";
		upprecord<<"\n\n";
		
				
			}
		upprecord << "\n Roll number: "<<s[holder].roll_number;
		upprecord << "\n Name: "<<s[holder].name;
		upprecord << "\n Father's Name: "<<s[holder].father;
		upprecord << "\n Branch: "<<s[holder].branch;
		upprecord << "\n House number: "<< s[holder].house_number;
		upprecord << "\n Street: "<< s[holder].street;
		upprecord << "\n District: "<< s[holder].district;
		upprecord << "\n State: "<< s[holder].state;
		upprecord << "\n Country: "<< s[holder].country;
		_strdate(date);
	    record << endl<<date << endl;
		record << "\n\t\t\t *************************************************************************************";
		upprecord<<"\n\n";
		

		for (int i=holder+1;i<n;i++){                                     // n-> holder
		upprecord << "\n Roll number: "<<s[i].roll_number;
		upprecord << "\n Name: "<<s[i].name;
		upprecord << "\n Father's Name: "<<s[i].father;
		upprecord << "\n Branch: "<<s[i].branch;
		upprecord << "\n House number: "<< s[i].house_number;
		upprecord << "\n Street: "<< s[i].street;
		upprecord << "\n District: "<< s[i].district;
		upprecord << "\n State: "<< s[i].state;
		upprecord << "\n Country: "<< s[i].country;
		upprecord<<"\n\n";
		_strdate(date);
	    record << endl<<date << endl;
		record << "\n\t\t\t *************************************************************************************";
		


		}
		upprecord.close();
		std::cout<<"\n File successfully Updated and stored in tdata.txt";

				}
		}

		

		
	}


	 std::cout<<"\n Do you want to perform any other task?\n(y/n): ";
		std::cin>>c;
	if(c=='y'){
	std::cout<< "\n 1. (Enter) Details\n 2. (Delete) a Record\n 3. (Update) Existing Record\n 4. (Show) Complete Record\n";
	std::cin>> choice;
	goto loop;
	}

}

}
if(choice=='s'){
	std::cout<<"\n\n Close this windows and lookout for a file named tdata.txt\n If not available then lookout for data.txt\n hope you are COMFORTABLE :-)";
}
return 0;
}
	
	
	
	
	

	





