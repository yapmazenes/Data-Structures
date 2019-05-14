/**
* @file ODEV1_VY
* @description Bu sinifta icerisinde Okul nesnesini gosterecek bir pointer, okul sinifindan elde edilen tek bir sinifi gosterecek Sinif pointeri vb sistemin isleyisini kolaylastiracak elde edilen verileri barindiran veriler bulunmaktadir.
* @course 1.Öğretim C Grubu
* @assignment 1.Ödev
* @date 26.10.2018
* @author B161210300-Muzaffer Enes Yapmaz-(yapmazenes@gmail.com)/ B161210303-Fatih Sözüer-(fatihsozuer0@gmail.com)
*/

#include "Yonetim.hpp"
#include <string.h>
#include <algorithm> 
using namespace std;

  void Yonetim::Baslat(){
    char sec;
	char veri1;
	char veri2;
	int tekrar;
	int bas=0;
	int sinifSayisi;
	sinifSayisi=getSinifSayisi();

	Okul * okul=getOkul(sinifSayisi);
	dosyaOku(*okul);
	do {
	
	bas=0;
		if(sinifSayisi%5!=0)
	    	tekrar=(sinifSayisi/5)+1;
		else
			 tekrar=(sinifSayisi/5);
	for(int i=0;i<tekrar;i+=1){

		if(i==tekrar-1) yazdir(*okul,bas,sinifSayisi);
		else yazdir(*okul,bas,bas+5);
		bas=bas+5;
			}
		
		cout<<"1.Sinif Degistir"<<endl;
		cout<<"2.Ogrenci Degistir"<<endl;
		cout<<"3.Cikis"<<endl<<"=>";

	
	cin>>sec;
	switch(sec)
	{		case '1':cout<<"1. Sinif Adi:";
				cin>>veri1;
				cout<<"2. Sinif Adi:";
				cin>>veri2;
					okul->sinifDegistir(veri1,veri2);
				cin.ignore();
			
			break;
			case '2':
				cout<<"1. Ogrenci:";
				cin>>veri1;
				cout<<"2. Ogrenci:";
				cin>>veri2;
					ogrenciDegistir(veri1,veri2,*okul);
				cin.ignore();
			break;
			case '3':break;
			break;
		default:
		cout<<"Yanlis tercih yaptiniz !"<<endl;
		break;
	}
}
while(sec!='3');


delete okul;
   }


	Yonetim:: Yonetim(){
		sinifSayisi=0;
		satirSay();	
	}
	Okul * Yonetim::getOkul(int snfSayisi){
		return new Okul(snfSayisi);	
	}

	char* Yonetim:: boyutarttir(char *eskialan , int eskiboyut,int eklenecekmiktar){
		char *yenialan=new char[eskiboyut+eklenecekmiktar];
		for(int i=0;i<eskiboyut;i++)
			yenialan[i]=eskialan[i];
		delete [] eskialan;
		return yenialan;
}
int Yonetim::getSinifSayisi()const{
	return sinifSayisi;
}
	
void Yonetim::dosyaOku(Okul & okul){
	 
	myfile.open("Okul.txt",ios::out);
     string line;
	 bool baslangic;  
      ogrenciIsimleri=new char[2]();
	  size_t i=0;
	  size_t kacinciSinif=0;
	  string delimiter = " ";
    while ( getline (myfile,line) )
    { 
		if(rtrim(line))
		{ 
		i=0;
      ogrenciSayisi=0;
	  string s = line;
 	 // s=ltrim(s);
	 baslangic=true;//Ilk karakter
  char * pch;
  int n = s.length();  
  char str[n+1];
    
    strcpy(str, s.c_str());  
  pch = strtok (str," ");
   while (pch != NULL)
  {
	if(baslangic)
	{
		sinifIsim=*(pch);
		baslangic=false;
	}
	else{
		if((i%2)==0){
			ogrenciIsimleri=boyutarttir(ogrenciIsimleri,i,5);
		}
 ogrenciIsimleri[i]=*(pch);
 ogrenciSayisi++;
 i++;
	}
    pch = strtok (NULL, " ");
	cout<<endl;
  }
okul.okulaSinifEkle(sinifIsim,ogrenciSayisi,kacinciSinif);
okul.getSinif(kacinciSinif)->sinifaOgrencileriEkle(ogrenciIsimleri);
kacinciSinif++;	

	}

	}delete [] ogrenciIsimleri;	
	//okul.sinifSirala();
	}
	///////////////////////////////////////////////////////////////////////

	void Yonetim::satirSay(){
	myfile.open("Okul.txt");
	string line;
	string kontrol;

  if (myfile.is_open())
  {
	 while ( getline (myfile,line) )
    {	
		kontrol=line;
		if(rtrim(kontrol)) sinifSayisi++;
    }
    myfile.close();
  }

	}

	 bool Yonetim:: rtrim(string s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
	if(s.size()>1) return true;
	else return false;
}

string  Yonetim:: rtrimDegistir(string str)
{
    str.erase(str.find_last_not_of(" ") + 1);
    return str;
}

	string  Yonetim:: ltrim(string str)
{
    str.erase(0, str.find_first_not_of(" "));
    return str;
}
	void Yonetim::ogrenciDegistir(char ogrenci1,char ogrenci2, Okul & okul){
		
		Ogrenci *ogr1;
		Ogrenci *ogr2;//Hangi sinif hangi ogrenci
		int snf1No,snf2No,ogr1No=-1,ogr2No=-1,bayrak=0;

		int ogrSayisi;
		Ogrenci *gelenOgrenci;
		char gelenIsim;
		bool oncedenGirildiMi=false,oncedenGirildiMi2=false;
	for(int i = 0; i < sinifSayisi; i++){
		ogrSayisi=okul.getSinif(i)->getOgrenciSayisi();
		
		for(int j = 0; j <ogrSayisi ; j++){
			if(bayrak!=2){
		  
		   gelenOgrenci= okul.getSinif(i)->getOgrenci(j); 
		   gelenIsim=(gelenOgrenci)->getIsim();
	
		 if (gelenIsim==ogrenci1 && oncedenGirildiMi==false) {
			ogr1=gelenOgrenci;
			ogr1No=j;
			snf1No=i;
			bayrak++;
			oncedenGirildiMi=true;
		     }
		else if(gelenIsim==ogrenci2 && oncedenGirildiMi2==false){
			ogr2=gelenOgrenci;
			ogr2No=j;
			snf2No=i;
			bayrak++;
			oncedenGirildiMi2=true;
			}
	
	}
	else break;
	}
	}
		if(ogr1No==-1)
		{
			cout<<"Ogrenci 1 bulunamadi"<<endl;
			cin.ignore();
		}
	 if(ogr2No==-1)
		{
			cout<<"Ogrenci 2 bulunamadi"<<endl;
			cin.ignore();
		}
	 if(ogr1No==-1 && ogr2No==-1){
			cout<<"Ogrenci 1 ve 2 bulunamadi"<<endl;
			cin.ignore();
	 }
	 if(ogr1No!=-1 && ogr2No!=-1) {
	
	okul.getSinif(snf1No)->ogrenciDegistir(ogr1No,ogr2);
	okul.getSinif(snf2No)->ogrenciDegistir(ogr2No,ogr1);
	 }
   ogr1=nullptr;
   ogr2=nullptr;
   gelenOgrenci=nullptr;
	}
	
	void Yonetim::yazdir(Okul & okul,int baslangic,int son){
		if(baslangic==0)
		 system("CLS");
		 int parcala;
    for(int i = baslangic; i <son; i++){
		cout<<*(okul.getSinif(i));
			if(i==son-1)
			cout<<endl;
		}
	int k=0;
	int bayrak=baslangic;
		while(bayrak!=son){	
		bayrak=baslangic;	
		for(int i = baslangic; i < son; i++){
				if(okul.getSinif(i)->ogrenciVarmi(k) ==true){						
				cout<<*(okul.getSinif(i)->getOgrenci(k));
				}
				else{	
					bayrak++;
					for(int i=0;i<15;i++)
					cout<<" ";
				}
			}
			k++;
		cout<<endl;
		}
		//cout<<endl;
	}
