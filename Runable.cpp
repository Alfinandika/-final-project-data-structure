#include <iostream>
#include <cstdlib>
#include "Transaction.h"
#include "Queue.h"
using namespace std;


Transaction c;
Queue q;

int main(){

	int pilihan;
	do{
		cout<<endl;
		cout<<"|=================================================|"<<endl;
        cout<<"|           SISTEM INFORMASI PERBANKAN            |"<<endl;
        cout<<"|=================================================|"<<endl;
		cout<<"\n [1] Antrian \n [2] Pendaftaran Nasabah \n [3] Daftar Nasabah \n [4] Setor Tunai \n [5] Tarik Tunai \n [6] Transfer \n [7] Mutasi Rekening \n [0] Keluar \n";
		cout<<"======================"<<endl;
		cout<<"[Menu Utama] Masukan Pilihan : ";
		cin>>pilihan;
		cout<<"======================"<<endl;
		switch(pilihan){
			case 1: q.main(); break;
			case 2: c.createAccount(); break;
			case 3: c.getAllCustomers(); break;
			case 4: c.cashDeposit(); break;
			case 5: c.withDraw(); break;
			case 6: c.transfer(); break;
			case 7: c.information(); break;
			
		}
	}while(pilihan!=0);
}