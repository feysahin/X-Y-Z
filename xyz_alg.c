#include<stdio.h>

double bisection_kok(double ust_taban, double kuvvet1, int sayi, int flag1);
double us(double taban1, int kuvvet1);

int main(){
	int i, j, x, y, z, kat=2, flag_z, flag, tekrar=1; 
	double kok;
	
	while(tekrar==1){	
	
	    flag=0;
		flag_z=0;	
	
	    printf("\n\nx: ");	    
	    scanf("%d", &x);
	    printf("y: ");
	    scanf("%d", &y);
	    printf("z: ");
	    scanf("%d", &z);
	    
	    if(z<0){      
		    //z'nin negatifli�ine sonda �s al�rken bakabilmek i�in                       
		    flag_z=1;   
			      
			//z'nin �slerine bakabilmek i�in pozitif de�erini alma              
		    z=abs(z);                        
	    }
	    
	    //payda asla 0 olamaz.
	    if(z==0) printf("Islem yapilamaz!");  
		                 
		//her say�n�n 0. kuvveti 1'dir.                                        
	    else if(y==0){
	    	//0^0 hari� (belirsiz)
	    	if(x==0) printf("Belirsiz.");
	    	else     printf("sonuc: 1");                      
	    }
	    
	    //0'�n her kuvveti yine 0'd�r.
	    else if(x==0) printf("sonuc: 0");                      
		    
		//z 1 ise x'in direkt y �ss� al�n�r.    
	    else if(z==1 && y*z>0) printf("sonuc: %f", us(x,y));   
		    
		//1'in her kuvveti 1'dir.    
	    else if(x==1) printf("sonuc: 1");                      
	    
	    else if(x<0 && z%2==0) printf("Negatif bir sayinin cift koku olamaz.");
		    
	    else{
	        // �r: x=27 z=3
		    if(us(z,z)==abs(x)) kok=z;
		    
		    /*k�k kesinlikle 0 ile z aras�nda olacak.
		    �r: x=16 z=4 */
		    else if(us(z,z)>abs(x)){
		        kok=bisection_kok(z,z,abs(x),flag);	
			}
			
			//�r: x=15620 z=3
			else if(us(z,z)<abs(x)){
				
				kok=z*z;
				while(us(kok,z)<abs(x)){
					kok = kok * z;					
				}
				if(us(kok,z)>abs(x)){
					flag=1;
					kok=bisection_kok(kok,z,abs(x),flag);
				}
				
			}		
			
			//k�k�, x'in mutlak de�eri ile bulmu�tuk, x negatifse k�k� de negatif olmal�.	
	        if(x<0) kok=-kok;
	        
	        /*k�k�, z'nin mutlak de�erini alarak bulmu�tuk, 
			z negatifse i�aretini a�a��daki kontrollerde net �ss�n i�areti i�in de�i�tirmemiz gerekir.
	        */
			if(flag_z==1) z=-z;
	    
	        //net �s i�areti pozitifken
	        if(y*z>0) printf("sonuc: %f", us(kok,y));
	    
	        //net �ss�n i�areti negatifse, sonucun �arpma i�lemine g�re tersi al�nmal�.
	        else if(y*z<0) printf("sonuc: %f", 1.0/(1.0*us(kok,y)));
	    }    	    
	    printf("\n\nYeni islem icin 1:\nSonlandirmak icin 0: ");
	    scanf("%d", &tekrar);
	}	
}

//�s alma fonksiyonu
double us(double taban1, int kuvvet1){
	int i;
	double sonuc1 = taban1;
	for(i=1; i<abs(kuvvet1); i++){       
		sonuc1 = sonuc1 * taban1;
	}
	return sonuc1;
}

//k�k bulma fonksiyonu
double bisection_kok(double ust_taban, double kuvvet1, int sayi, int flag_){
	double orta, alt_taban;
	int sayac = 0;
	
	//x eksiyken kesin buraya girecek
	if(flag_==0){ 
	    alt_taban = 0;
	}
	
	else if(flag_==1){
		
		//alt taban�, 'kok' de�erinin bir �nceki ad�m�na e�itleriz.
		alt_taban=ust_taban/kuvvet1;
	}
	
	orta=(ust_taban+alt_taban)/2;
	
	while(sayac<30 && us(orta,kuvvet1)!=sayi){
	    if(us(orta,kuvvet1)>sayi){
	    	ust_taban=orta;
		}
		else if(us(orta,kuvvet1)<sayi){
			alt_taban = orta;
		}
		orta=(ust_taban+alt_taban)/2;
		sayac++;
	}	
	return orta;
}
