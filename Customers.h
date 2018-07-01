#include <vector>
#include <iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;

class Customers{
	protected:	vector<int> accountNumber;
				vector<int> identityNumber;
				vector<string> name;
				vector<string> address;
				vector<double> balance;

	protected: struct mutasi{
					vector<int> accountNumber;
					vector<string> type;
					vector<int> amount;
					vector<string> note;	
				}mutasi;

	public: void createAccount(){
		int _identityNumber;
		string _name, _address;

		cout<<"Masukan Nomor KTP : ";
		cin>>_identityNumber;
		cout<<"Masukan Nama : ";
		cin.ignore(); getline(cin, _name);;
		cout<<"Masukan Alamat : ";
		cin.ignore(); getline(cin, _address);

		this->accountNumber.push_back(this->createAccountNumber());
		this->identityNumber.push_back(_identityNumber);
		this->name.push_back(_name);
		this->address.push_back(_address);
		this->balance.push_back(0);
		cout<<"_________________________________________________________"<<endl;
		cout<<"Data berhasil Ditambahkan !"<<endl;
		cout<<"Nomor Rekening : "<<this->accountNumber[this->accountNumber.size()-1]<<endl;
		cout<<"Nomor KTP : "<<this->identityNumber[this->identityNumber.size()-1]<<endl;
		cout<<"Nama : "<<this->name[this->name.size()-1]<<endl;
		cout<<"Alamat : "<<this->address[this->address.size()-1]<<endl;
		cout<<"Saldo : Rp."<<this->balance[this->balance.size()-1]<<",-"<<endl;
		cout<<"_________________________________________________________"<<endl;

	}

	protected: int search(int accountNumber){
		int index = -1;
		for (int i = 0; i < this->accountNumber.size(); i++){
			if(this->accountNumber[i] == accountNumber){
				index = i;
			}
		}
		return index;
	}

	private: int createAccountNumber(){
		int accountNumberNow =  rand() % 100000 +  999999;
		if(this->accountNumber.size() != 0){
			for (int i = 0; i < this->accountNumber.size(); i++){
				if(this->accountNumber[i] == accountNumberNow){
					createAccountNumber();
				}else{
					return accountNumberNow;
				}
			}
		}else{
			return accountNumberNow;
		}
	}

	public: void getAllCustomers(){
		int pilihan;
		do{
		cout<<endl<<endl<<"      DAFTAR NASABAH BANK"<<endl;
                cout<<"|====|=================|========================|==============|==============|"<<endl;
                cout<<"| No |   No Rekening   |          Nama          |    Alamat    | Total Saldo  |"<<endl;
                cout<<"|====|=================|========================|==============|==============|"<<endl;
            for(int i = 0; i < this->accountNumber.size(); i++){
				cout<<setw(4)<<i+1;
                cout<<setw(17)<<this->accountNumber[i];
                cout<<setw(20)<<this->name[i];
                cout<<setw(18)<<this->address[i];
                cout<<setw(14)<<"Rp."<<this->balance[i]<<",-"<<endl;
			}
		cout<<"|====|=================|========================|==============|==============|"<<endl;

		
		
		cout<<"\n [1] Sorting by Balance Ascending \n [2] Sorting by Balance Ascending \n [0] Kembali ke menu utama \n";
		cout<<"======================"<<endl;
		cout<<"Masukan Pilihan : ";
		cin>>pilihan;
		cout<<"======================"<<endl;
		switch(pilihan){
			case 1: this->sortingByBalanceAsc(); break;
			case 2: this->sortingByBalanceDsc(); break;
			
		}
		}while(pilihan!=0);
	}

	protected: double cekBalance(int accountNumber){
		if(this->search(accountNumber) == -1){
			return -1;
		}else{
			int index = this->search(accountNumber);

			return this->balance[index];
		}
	}

	protected: bool setBalance(int accountNumber, double amount){
		if(this->search(accountNumber) == -1){
			return false;
		}else{
			int index = this->search(accountNumber);

			this->balance[index] = amount;

			return true;
		}
	}

	public: void information(){
		

		int accountNumber;
		cout<<"Masukan Nomor Rekening : ";
		cin>>accountNumber;

		int index = this->search(accountNumber);

		if(index != -1){
			cout<<"Nomor Rekening : "<<this->accountNumber[index]<<endl;
			cout<<"Nomor KTP : "<<this->identityNumber[index]<<endl;
			cout<<"Nama : "<<this->name[index]<<endl;
			cout<<"Alamat : "<<this->address[index]<<endl;
			cout<<"Saldo : Rp."<<this->balance[index]<<",-"<<endl;


				cout<<endl<<endl<<"      MUTASI REKENING"<<endl;
                cout<<"|====|==========|===============|=============================|"<<endl;
                cout<<"| No |   TYPE   |     JUMLAH    |          KETERANGAN         |"<<endl;
                cout<<"|====|==========|===============|=============================|"<<endl;
            for(int i = 0; i < this->mutasi.accountNumber.size(); i++){
            	if(this->mutasi.accountNumber[i] == this->accountNumber[index]){
					cout<<setw(4)<<i+1;
                	cout<<setw(8)<<this->mutasi.type[i];
                	cout<<setw(11)<<"Rp."<<this->mutasi.amount[i]<<",-";
                	cout<<setw(22)<<this->mutasi.note[i]<<endl;
            	}
			}
			cout<<"|====|==========|===============|=============================|"<<endl;

		}else{
			cout<<"nomor rekening tidak ditemukan !"<<endl;
		}


	}

	private: void sortingByBalanceAsc(){
		//Bubble Sort
		int tempAccountNumber, tempIdentityNumber;
		double temp;
		string tempName, tempAddress;
    
	    for(int i=1;i<this->balance.size();++i){
        	for(int j=0;j<(this->balance.size()-i);++j){
            	if(this->balance[j]<this->balance[j+1]){
                	temp=this->balance[j];
                	this->balance[j]=this->balance[j+1];
                	this->balance[j+1]=temp;

                	tempName=this->name[j];
                	this->name[j]=this->name[j+1];
                	this->name[j+1]=tempName;

                	tempAccountNumber=this->accountNumber[j];
                	this->accountNumber[j]=this->accountNumber[j+1];
                	this->accountNumber[j+1]=tempAccountNumber;

                	tempIdentityNumber=this->identityNumber[j];
                	this->identityNumber[j]=this->identityNumber[j+1];
                	this->identityNumber[j+1]=tempIdentityNumber;

                	tempAddress=this->address[j];
                	this->address[j]=this->address[j+1];
                	this->address[j+1]=tempAddress;
            	}
            }
    	}


	}

	private: void sortingByBalanceDsc(){
		//Bubble Sort
		int tempAccountNumber, tempIdentityNumber;
		double temp;
		string tempName, tempAddress;
    
	    for(int i=1;i<this->balance.size();++i){
        	for(int j=0;j<(this->balance.size()-i);++j){
            	if(this->balance[j]>this->balance[j+1]){
                	temp=this->balance[j];
                	this->balance[j]=this->balance[j+1];
                	this->balance[j+1]=temp;

                	tempName=this->name[j];
                	this->name[j]=this->name[j+1];
                	this->name[j+1]=tempName;

                	tempAccountNumber=this->accountNumber[j];
                	this->accountNumber[j]=this->accountNumber[j+1];
                	this->accountNumber[j+1]=tempAccountNumber;

                	tempIdentityNumber=this->identityNumber[j];
                	this->identityNumber[j]=this->identityNumber[j+1];
                	this->identityNumber[j+1]=tempIdentityNumber;

                	tempAddress=this->address[j];
                	this->address[j]=this->address[j+1];
                	this->address[j+1]=tempAddress;
            	}
            }
    	}


	}

};