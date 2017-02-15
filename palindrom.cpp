#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
typedef struct palindrom{  //palindrom adýnda struct yapýsý oluþur
char ch;              //deðiþken tanýmlama
struct palindrom *ileri; }Palindrom;  
 
Palindrom *bas=NULL;  //yapýnýn bas pointerý bos olarak atanýr
 
void ekle(Palindrom **bas, char deger){  //ekle bloðununda **bas ve deger parametre kullan.
Palindrom *gecici=(Palindrom *) malloc (sizeof(Palindrom)); //geciciye dinamik alan atamasý olur  
gecici->ch=deger;  //gecicinin ch na deger atanýr
gecici->ileri=*bas;  //gecicinin ilerisine *bas atanýr
*bas=gecici; }       //*bas a gecici atanýr
 
char sil(Palindrom **bas){  //sil bloðuna **bas parametresi oluþturuldu
Palindrom *gecici;     //*gecici tanýmlandý
gecici =*bas;          //geciciye *bas atanýr
char deger =gecici->ch;  //degere gecicinin ch si atanýr
*bas = (*bas)->ileri;  //*bas'a, *bas'ýn ilerisi atanýr
free(gecici);         //malloc ile gecici için saðlanan alan temizlenmiþ olur
return deger; }       //deger döndürme
 
int main(){          //ana blok
int i=0, sayac=0;    //deger tanýmlama
char *kelime=(char *)malloc(sizeof(char)); //*kelime ye charýn dinamik alaný kadar ayrýlýr    
printf("Bir kelime giriniz: ");  
scanf("%s", kelime);   //girilen deger kelimeye atanýr
while(kelime[i] != '\0'){  //kelimenin i. degeri boþ deðilse
ekle(&bas, kelime[i]);     //ekle bloguna gönder
i++; }    //iyi bir arttýr  (while döngüsü)
i=0;                        //deger atanmasý
for(sayac=0;sayac<strlen(kelime);sayac++)  //kelime uzunluðuna baðlý döngü oluþturmak
if(sil(&bas)==kelime[sayac]) //sil blogundan gelen deger kelimedeki sayaca göre eþitse
i++;    //+1 arttýrýr
if(i== strlen(kelime)) //eþitlik saðlanýlýrsa
printf("\nPalindromdur\n"); 
else printf("\nPalindrom Degildir\n"); //saðlanmazsa      
return 0; } 

