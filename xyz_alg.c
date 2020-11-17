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
		    //z'nin negatifliðine sonda üs alýrken bakabilmek için                       
		    flag_z=1;   
			      
			//z'nin üslerine bakabilmek için pozitif deðerini alma              
		    z=abs(z);                        
	    }
	    
	    //payda asla 0 olamaz.
	    if(z==0) printf("Islem yapilamaz!");  
		                 
		//her sayýnýn 0. kuvveti 1'dir.                                        
	    else if(y==0){
	    	//0^0 hariç (belirsiz)
	    	if(x==0) printf("Belirsiz.");
	    	else     printf("sonuc: 1");                      
	    }
	    
	    //0'ýn her kuvveti yine 0'dýr.
	    else if(x==0) printf("sonuc: 0");                      
		    
		//z 1 ise x'in direkt y üssü alýnýr.    
	    else if(z==1 && y*z>0) printf("sonuc: %f", us(x,y));   
		    
		//1'in her kuvveti 1'dir.    
	    else if(x==1) printf("sonuc: 1");                      
	    
	    else if(x<0 && z%2==0) printf("Negatif bir sayinin cift koku olamaz.");
		    
	    else{
	        // ör: x=27 z=3
		    if(us(z,z)==abs(x)) kok=z;
		    
		    /*kök kesinlikle 0 ile z arasýnda olacak.
		    ör: x=16 z=4 */
		    else if(us(z,z)>abs(x)){
		        kok=bisection_kok(z,z,abs(x),flag);	
			}
			
			//ör: x=15620 z=3
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
			
			//kökü, x'in mutlak deðeri ile bulmuþtuk, x negatifse kökü de negatif olmalý.	
	        if(x<0) kok=-kok;
	        
	        /*kökü, z'nin mutlak deðerini alarak bulmuþtuk, 
			z negatifse iþaretini aþaðýdaki kontrollerde net üssün iþareti için deðiþtirmemiz gerekir.
	        */
			if(flag_z==1) z=-z;
	    
	        //net üs iþareti pozitifken
	        if(y*z>0) printf("sonuc: %f", us(kok,y));
	    
	        //net üssün iþareti negatifse, sonucun çarpma iþlemine göre tersi alýnmalý.
	        else if(y*z<0) printf("sonuc: %f", 1.0/(1.0*us(kok,y)));
	    }    	    
	    printf("\n\nYeni islem icin 1:\nSonlandirmak icin 0: ");
	    scanf("%d", &tekrar);
	}	
}

//üs alma fonksiyonu
double us(double taban1, int kuvvet1){
	int i;
	double sonuc1 = taban1;
	for(i=1; i<abs(kuvvet1); i++){       
		sonuc1 = sonuc1 * taban1;
	}
	return sonuc1;
}

//kök bulma fonksiyonu
double bisection_kok(double ust_taban, double kuvvet1, int sayi, int flag_){
	double orta, alt_taban;
	int sayac = 0;
	
	//x eksiyken kesin buraya girecek
	if(flag_==0){ 
	    alt_taban = 0;
	}
	
	else if(flag_==1){
		
		//alt tabaný, 'kok' deðerinin bir önceki adýmýna eþitleriz.
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
