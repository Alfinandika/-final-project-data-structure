#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 100

class Queue{
	

	private: struct queue{
		int data[100];
		int awal, akhir;
	} antrean;

	private: void init(){
		antrean.awal=-1;
		antrean.akhir=-1;
	}

	private: bool full(){
		if(antrean.akhir == MAX-1){
			return true;
		}else{
			return false;
		}
	}

	private: bool empty(){
		if(antrean.akhir==-1){
			return true;
		}else{
			return false;
		}
	}

	private: void deQueue(){
		int i;
		if(!empty()){
			for(i = antrean.awal; i<antrean.akhir; i++){
				antrean.data[i]=antrean.data[i+1];
			}
			antrean.akhir--;
		}else{
			cout<<"Antrean Kosong"<<endl;
		}
	}

	private: void clear(){
		antrean.awal=-1;
		antrean.akhir=-1;
	}

	private: void setQueue(){
		int jml;
		cout<<"Masukan jumlah Antrian untuk hari ini : "; cin>>jml;

		this->clear();
		for (int i = 0; i < jml; ++i){
			antrean.data[antrean.akhir]=i+1;
			antrean.akhir++;
		}

		cout<<jml<<" Antrian berhasil ditambahkan !"<<endl;
		

	}

	private: void queueNow(){
		cout<<"|===========================|===========|"<<endl;
        cout<<"|   NOMOR ANTRIAN SAAT INI  |    ";if(!empty()){cout<<antrean.data[antrean.awal];}else{cout<<0;};cout<<"      |"<<endl;
        cout<<"|===========================|===========|"<<endl;
        cout<<"|   SISA ANTRIAN            |    ";if(!empty()){cout<<antrean.akhir;}else{cout<<0;};cout<<"     |"<<endl;
        cout<<"|===========================|===========|"<<endl;
	}

	public: void main(){
		int pilihan;
		do{
			queueNow();
			cout<<"\n [1] Ambil Antrian \n [2] Set Antrian \n [3] Clear Antrian \n [0] Menu Utama \n";
			cout<<"======================"<<endl;
			cout<<"[Menu Queue] Masukan Pilihan : ";
			cin>>pilihan;
			cout<<"======================"<<endl;
			switch(pilihan){
				case 1: this->deQueue(); break;
				case 2: this->setQueue(); break;
				case 3: this->clear(); break;
			
			}
		}while(pilihan!=0);
	}
};