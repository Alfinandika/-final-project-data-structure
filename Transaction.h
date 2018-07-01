#include <iostream>
#include <cstdlib>
#include "Customers.h"
using namespace std;

class Transaction: public Customers{
	
	public: void transfer(){
		int from, to;
		double amount;
		cout<<"Masukan nomor rekening asal : ";
		cin>>from;
		if(this->search(from) == -1){
			cout<<"Nomor rekening tidak ditemukan !"<<endl;
			transfer();
		}
		cout<<"Masukan nomor rekening tujuan : ";
		cin>>to;

		if(this->search(to) == -1){
			cout<<"Nomor rekening tidak ditemukan !"<<endl;
			cout<<to;
			transfer();
		}
		cout<<"Masukan Jumlah Transfer : ";

		cin>>amount;

		double balanceFrom = this->cekBalance(from);
		double balanceTo = this->cekBalance(to);
		if(amount > balanceFrom){
			cout<<"Saldo Tidak Mencukupi";
		}else{

			this->setBalance(to, balanceTo+amount);
			this->setBalance(from, balanceFrom-amount);
			cout<<"Transfer berhasil dari rekening "<<from<<" ke rekening "<<to<<" sebesar Rp."<<amount<<",-";

			//mutasi pengirim
			mutasi.accountNumber.push_back(from);
			mutasi.type.push_back("Keluar");
			mutasi.amount.push_back(amount);
			mutasi.note.push_back("Transfer tunai");
		
			//mutasi ppenerima
			mutasi.accountNumber.push_back(to);
			mutasi.type.push_back("Masuk");
			mutasi.amount.push_back(amount);
			mutasi.note.push_back("Transfer tunai");
		}

		cout<<endl;	
		
		
	}

	public:  void cashDeposit(){
		int accountNumber;
		double amount;
		cout<<"Masukan nomor rekening : ";
		cin>>accountNumber;
		if(this->search(accountNumber) == -1){
			cout<<"Nomor rekening tidak ditemukan !"<<endl;
			cashDeposit();
		}else{
			cout<<"Masukan Jumlah Setoran : ";
			cin>>amount;
			double balanceNow = this->cekBalance(accountNumber);
			this->setBalance(accountNumber, balanceNow+amount);
			cout<<"Setor Tunai sebesar Rp."<<amount<<",- berhasil. Saldo saat ini Rp."<<this->cekBalance(accountNumber)<<",-";

			mutasi.accountNumber.push_back(accountNumber);
			mutasi.type.push_back("Masuk");
			mutasi.amount.push_back(amount);
			mutasi.note.push_back("Setor tunai");
		}
	}

	public: void withDraw(){
		int accountNumber;
		double amount;
		cout<<"Masukan nomor rekening : ";
		cin>>accountNumber;
		if(this->search(accountNumber) == -1){
			cout<<"Nomor rekening tidak ditemukan !"<<endl;
			cashDeposit();
		}

		cout<<"Masukan Jumlah Tarik : ";
		cin>>amount;
		double balanceNow = this->cekBalance(accountNumber);

		if(amount > balanceNow){
			cout<<"Saldo Tidak Mencukupi";
		}else{
			this->setBalance(accountNumber, balanceNow-amount);
			cout<<"Tarik Tunai sebesar Rp."<<amount<<",- berhasil. Saldo saat ini Rp."<<this->cekBalance(accountNumber)<<",-";

			mutasi.accountNumber.push_back(accountNumber);
			mutasi.type.push_back("Keluar");
			mutasi.amount.push_back(amount);
			mutasi.note.push_back("Tarik tunai");
		}	
		
	}
};