#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//*********************
using namespace std;
class korta
	{
	private:
		int n_Verte;
		char n_Nominalas[3];
		char n_Tipas ;
	public:
		korta();
								
		int rodytkorta();
		
		void korta_paversti(int);
		
			};
//******************************
class kalade											
	{
	private:
		korta n_kortumasyvas[52];				
		int n_paskutinedalinta;
	public:
		kalade();										
		void KurkKalade();							
		void MaisykKalade(int );
		int DalinkViena();
	//	int verte();
	
	};												
												
int main();

int atsitiktinis_sk(int min, int max);	// atsitiktinio skaiciaus generatorius
		
//*********************************

korta::korta()					
				
{
		int i;
		for(i=1;i<=3;i++)							
		{
			n_Nominalas[i] = ' ';
		}
		n_Tipas = ' ';							
		n_Verte = 0;
}

//**************************
int korta::rodytkorta()

{	int x;	
	cout << "   ";
	cout << n_Nominalas  ;
	cout.width(1);
	cout <<  n_Tipas;
	cout << " ";
	//cout<<n_Verte;
	//cout<<" ";
	x=n_Verte;
	//cout<<"rodyt korta siuncia reiksme nverte"<<x<<endl;
	return x;
	
}


//*****************************************************
void korta::korta_paversti(int num)

{

	int i = 0;
	char j;
	//cout<<"atejo pradine reiksme tokia"<<num<<endl;
	int face_num = num % 13;				 

	switch(face_num)								
	{
	case 0: strcpy(n_Nominalas," A");break;
	case 9: strcpy(n_Nominalas,"10");break;
	case 10: strcpy(n_Nominalas," J");break;
	case 11: strcpy(n_Nominalas," Q");break;
	case 12: strcpy(n_Nominalas," K");break;
	default:
		j = char(face_num + 49);					
		
		if(i<3)
		{
			n_Nominalas[i] = ' '; i++;
			n_Nominalas[i] = j;i++;
			n_Nominalas[i] = NULL; 
			break;
		}
	}

  	if(num <= 12)n_Tipas = 6;						
	if(num >12 && num <= 25)n_Tipas = 3;				
	if(num >25 && num <= 38)n_Tipas = 5;
	if(num >38 && num <= 51)n_Tipas = 4;

	if(face_num <= 9)n_Verte  = face_num + 1;
	if(face_num >= 10)n_Verte = 10;
	
	
}


//************************************************************
void kalade::KurkKalade()								// sukuria pilna kalade 

{
	n_paskutinedalinta = 51;								
	while(n_paskutinedalinta >-1)							
	{										
		n_kortumasyvas[n_paskutinedalinta].korta_paversti(n_paskutinedalinta);
		n_paskutinedalinta--;
		
	}										
}
//*****************************************************************
int atsitiktinis_sk(int min, int max)

{
	int sk_atsitiktinis;
	sk_atsitiktinis = rand();
	sk_atsitiktinis = sk_atsitiktinis % (max - min + 1) + min;
   	return sk_atsitiktinis;
}
//************************************************************************

void kalade::MaisykKalade(int kartai)

{
	int x, dalinti;
	cout << endl;
	for(x=0;x<=kartai;x++)							
	{	
		dalinti = atsitiktinis_sk(20,35);				
		kalade virsuskalades;								
		kalade apaciakalades;
		int i;
		int apaciakaladesindex = 1;
		int virsuskaladesindex = 1;
		for(i=0;i<=dalinti - 1;)						
		{
			virsuskalades.n_kortumasyvas[virsuskaladesindex] = this->n_kortumasyvas[i];
			virsuskaladesindex++;	
			i++;
		}
		for(i=(dalinti);i< 52;)						
		{
			apaciakalades.n_kortumasyvas[apaciakaladesindex] = this->n_kortumasyvas[i];
			apaciakaladesindex++;
			i++;
		}
		int kaladeoutindex = 0;					
		int numkortastomovetop;
		int numkortastomovebottom;
		int j;
		int h = 0;
	
		apaciakaladesindex = 52 - dalinti;				
		virsuskaladesindex =dalinti;						
		while(kaladeoutindex <= 51)
		{
			numkortastomovetop = atsitiktinis_sk(2,7);
			numkortastomovebottom = atsitiktinis_sk(2,7);
			for(j=0;j <=numkortastomovebottom;j++)		
			{
				if(apaciakaladesindex > 0)			
				{
					this->n_kortumasyvas[kaladeoutindex] = apaciakalades.n_kortumasyvas[apaciakaladesindex];
					kaladeoutindex++;
					apaciakaladesindex--;
				}
				for(h=0;h<=numkortastomovetop;h++)	
				{										
					if((virsuskaladesindex > 0) && (kaladeoutindex <=52)) 
					{											 	
						this->n_kortumasyvas[kaladeoutindex] = virsuskalades.n_kortumasyvas[virsuskaladesindex];
						kaladeoutindex++;
						virsuskaladesindex--;
					}
				}
			}
		}
	}	
	this->n_paskutinedalinta = -1;						
}
//*******************************
int kalade::DalinkViena() 

{int sk;
	
if(n_paskutinedalinta != 51)								
	{
		n_paskutinedalinta++;
		cout.width(5);
		cout <<"Korta:";
		sk=n_kortumasyvas[n_paskutinedalinta].rodytkorta();
		//cout<<"sk reiksme gavo x ir tapo lygus:"<<sk<<endl;
	}
return sk;
	
}
//*****************************************
/*
int kalade::verte()
{int s;

s=n_kortumasyvas[n_paskutinedalinta].korta_paversti(n_paskutinedalinta);
cout<<"kintamasis paskutine dalinat:"<<n_paskutinedalinta<<endl;
cout<<"s verte kuri keliaus i main funkcija:"<<s <<endl;
return s;	}										*/
//*****************************

kalade :: kalade()										

{
	
	int i;
	for(i=0;i<=51;i++)
	{
		n_kortumasyvas[i] = korta();							
	}												 
}
//*****************************************



int main()

{
	
	srand((unsigned)time( NULL ) );
	kalade kalade_1;
	korta korta_1;
	kalade_1.KurkKalade();								// sukuria kalade
	kalade_1.MaisykKalade(50);							// ismaiso kalade 50 kartu
	bool stop, dalink;
	int suma,//zmogaus suma
		k_suma,//kompiuterio suma
		m;
	char naujas, taip;
	stop=true;
	dalink=true;
	while (stop==true){//while stop ture
		cout<<"Naujas zaidimas spauskite Z iseiti - Q "<<endl;
		cin>>naujas;
		if (naujas=='z'){//if naujas z
			cout<<"\t\tZaidimas prasideda"<<endl;
		suma=0;
		k_suma=0;
		
		taip='t';
		m=kalade_1.DalinkViena();		
		k_suma=k_suma+m;
		cout<<"Kompiuterio suma:"<<k_suma<<endl;
			while (taip=='t')
			{//while tap
				m=kalade_1.DalinkViena();
				suma=suma+m;
				cout<<"Jusu suma:"<<suma<<endl;
				cout<<"Ar dar imsite korta? Taip spauskite t, ne - r"<<endl;
				cin>>taip;
				if (taip=='n')
				{stop=false;
					taip='n';
				}
				
			}//while tap
			
				while((suma <= 21) && (k_suma <= 21)){       
                
				m=kalade_1.DalinkViena();
				k_suma=k_suma+m;}
				cout<<"Kompiuteris surinko: "<<k_suma<<endl;
				cout<<"Jus surinkote: "<<suma<<endl;	
		}//if naujas z{
              
			if (suma==21)
				cout<<"Jus laimejote \n";
			 else if ((suma < 21) && (suma > k_suma))
					cout<<"Jus laimejote \n";
			else if	(k_suma>21&&suma<=21)
                     cout<<"Jus laimejote \n";
							
			else
				cout << "Gaila, bet laimejo kompiuteris.Bandykite dar karta" << endl;
	}//while stop ture
		
	return 1;									
}	