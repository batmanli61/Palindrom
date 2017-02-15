#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
typedef struct palindrom{  //palindrom ad�nda struct yap�s� olu�ur
char ch;              //de�i�ken tan�mlama
struct palindrom *ileri; }Palindrom;  
 
Palindrom *bas=NULL;  //yap�n�n bas pointer� bos olarak atan�r
 
void ekle(Palindrom **bas, char deger){  //ekle blo�ununda **bas ve deger parametre kullan.
Palindrom *gecici=(Palindrom *) malloc (sizeof(Palindrom)); //geciciye dinamik alan atamas� olur  
gecici->ch=deger;  //gecicinin ch na deger atan�r
gecici->ileri=*bas;  //gecicinin ilerisine *bas atan�r
*bas=gecici; }       //*bas a gecici atan�r
 
char sil(Palindrom **bas){  //sil blo�una **bas parametresi olu�turuldu
Palindrom *gecici;     //*gecici tan�mland�
gecici =*bas;          //geciciye *bas atan�r
char deger =gecici->ch;  //degere gecicinin ch si atan�r
*bas = (*bas)->ileri;  //*bas'a, *bas'�n ilerisi atan�r
free(gecici);         //malloc ile gecici i�in sa�lanan alan temizlenmi� olur
return deger; }       //deger d�nd�rme
 
int main(){          //ana blok
int i=0, sayac=0;    //deger tan�mlama
char *kelime=(char *)malloc(sizeof(char)); //*kelime ye char�n dinamik alan� kadar ayr�l�r    
printf("Bir kelime giriniz: ");  
scanf("%s", kelime);   //girilen deger kelimeye atan�r
while(kelime[i] != '\0'){  //kelimenin i. degeri bo� de�ilse
ekle(&bas, kelime[i]);     //ekle bloguna g�nder
i++; }    //iyi bir artt�r  (while d�ng�s�)
i=0;                        //deger atanmas�
for(sayac=0;sayac<strlen(kelime);sayac++)  //kelime uzunlu�una ba�l� d�ng� olu�turmak
if(sil(&bas)==kelime[sayac]) //sil blogundan gelen deger kelimedeki sayaca g�re e�itse
i++;    //+1 artt�r�r
if(i== strlen(kelime)) //e�itlik sa�lan�l�rsa
printf("\nPalindromdur\n"); 
else printf("\nPalindrom Degildir\n"); //sa�lanmazsa      
return 0; } 

