#include "tanimlar.h"
#include "teste.h"
#include "cekimler.h"
#include "bilgiler.h"
#include "yardimci.h"
#include "voir.h"
#include "sampiyon.h"
#include <time.h>


static int  puanhesapla( int puan, int yansay, int hanz )
{
	int dog=8, zamanlar[13]={0,10, 6, 10, 5, 7, 8, 8, 10, 10, 8, 6, 8};

	if ( yansay ) seskotu();
	else sesiyi();
	if ( hanz==3 ) dog=3;
	puan+=zamanlar[hanz]*(dog-yansay);
	return( puan );
}
static void  puanyaz( int puan )
{
	char a[40]="Vos Points Sont: ", b[10];
	int esrn=eskirenk();

	textattr( YELLOW + (BROWN<<4) );
	itoa(puan, b, 10); strcat(a,b);
	ortayayaz(a, 3); textattr( esrn );
}

static int  verbesec(char *verbe)
{
    int sayi, bul;

    sayi=verbesayisi();

    randomize();
    bul=random( sayi );
	oku( bul, verbe );

    if ( verbe[0]=='s' ) {
        if ( verbe[1]==39 ) {
            strcpy(verbe, &verbe[2]);
            return ('p');
        }
        if ( verbe[1]=='e' && verbe[2]==' ' ) {
            strcpy(verbe, &verbe[3]);
            return ('p');
        }
    }

}


void teste()
{
   char verbe[MAXFILUZ], kisi[9*MAXCEKUZ], boskisi[9*MAXCEKUZ], fiil[MAXFILUZ]="se";
   int num, farklar[9], puan=0, maxpuan=0, a, zsk=12, fsk=13.8;
   int avet, pronor, i, j, zs=0, fs, tekrar, esrn=eskirenk();
   int zamanlar[13]={0,10, 6, 10, 5, 7, 8, 8, 10, 10, 8, 6, 8};
   struct tt *tablo, tbl;
   extern struct men menu[6];
   char sayi[4], isim[20];
   float fl1, fl2;

   ekranyeni(); clrscr();
   islevyaz("TESTE DE CONJUGAISON");

   for( i=0; i<3; i++ ) for( j=0; j<4; j++ )
           if ( menu[i].centik[j] ) zs++;
   if ( !zs ) return;

   textcolor( LIGHTRED );
   gotoxy(25, 4); cputs("Combien de Verbes Voulez-vous ?");
   textattr( esrn );
   cerceve(35-1, 6-1, 35+3, 6+1 );
   do {
	   if ( -1 == cumleal(0, sayi, 35, 6, 3 ) ) return;
       fs=atoi( sayi );
   }while( fs<1 );

   puan=maxpuan=fs*fsk + zs*zsk;


   for( tekrar=0; tekrar<fs; tekrar++ ) {
       pronor=verbesec( verbe );
       if ( pronor == -1 ) return;

	   if ( pronor == 'p' )  kesme( fiil, verbe[0] );
       else fiil[0]=NULL;
       strcat( fiil, verbe );

       num=numbul(verbe);
       if ( num==-1 ) {
		   gotoxy(18,15); cputs("Ce ne peut pas ˆtre un verbe Fran‡ais !");
		   seskotu(); tusbekle(); return;
       }

       if ( pronor != 'p' )   avet=auxilbul(verbe);
       if ( pronor == 'p' )   avet='e';

	   tbl=tablobul(num); tablo=&tbl;

       if ( menu[0].centik[0] ) {
           zamanyaz("PRESENT"); verbeyaz( fiil );
           puanyaz( puan );
		   present(tablo, pronor, verbe, kisi);
		   maxpuan+=zamanlar[1]*8;
           bos( boskisi, farklar );
		   if ( -1==tumfilal( verbe, &kisi[0], &boskisi[0], 5, 6 ) ) return;
           karsilastir( kisi, boskisi, farklar );
           puan=puanhesapla( puan, farklar[8], 1 );
       }



      if ( menu[0].centik[1] ) {
          zamanyaz("IMPARFAIT"); verbeyaz( fiil );
          puanyaz( puan );
		  imparfait(tablo, pronor, verbe, kisi);
		  maxpuan+=zamanlar[2]*8;
          bos( boskisi, farklar );
		  if ( -1==tumfilal( verbe, &kisi[0], &boskisi[0], 5, 6 ) ) return;
          karsilastir( kisi, boskisi, farklar );
		  puan=puanhesapla( puan, farklar[8], 2 );
      }


	  if ( menu[0].centik[2] && pronor!='i' ) {
          zamanyaz("IMPERATIF"); verbeyaz( fiil );
          puanyaz( puan );
		  imperatif(tablo, pronor, verbe, kisi);
		  maxpuan+=zamanlar[3]*3;
          bos( boskisi, farklar );
		  if ( tumfilal( verbe, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
          karsilastir( kisi, boskisi, farklar );
		  puan=puanhesapla( puan, farklar[8], 3 );
      }


      if ( menu[0].centik[3] ) {
          zamanyaz("FUTUR SIMPLE"); verbeyaz( fiil );
          puanyaz( puan );
		  fsimple(tablo, pronor, verbe, kisi);
		  maxpuan+=zamanlar[4]*8;
          bos( boskisi, farklar );
		  if ( tumfilal( verbe, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
          karsilastir( kisi, boskisi, farklar );
		  puan=puanhesapla( puan, farklar[8], 4 );
      }


      if ( menu[1].centik[0] ) {
          zamanyaz("PASSE COMPOSE"); verbeyaz( fiil );
          puanyaz( puan );
		  pcompose(tablo, avet, pronor, verbe, kisi);
		  maxpuan+=zamanlar[5]*8;
          bos( boskisi, farklar );
		  if ( tumfilal( verbe, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
          karsilastir( kisi, boskisi, farklar );
		  puan=puanhesapla( puan, farklar[8], 5 );
      }


      if ( menu[1].centik[1] ) {
          zamanyaz("PLUS-QUE-PARFAIT"); verbeyaz( fiil );
          puanyaz( puan );
		  pparfait(tablo, avet, pronor, verbe, kisi);
		  maxpuan+=zamanlar[6]*8;
          bos( boskisi, farklar );
		  if ( tumfilal( verbe, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
          karsilastir( kisi, boskisi, farklar );
		  puan=puanhesapla( puan, farklar[8], 6 );
      }


      if ( menu[1].centik[2] ) {
          zamanyaz("FUTUR ANTERIEUR"); verbeyaz( fiil );
          puanyaz( puan );
		  fanterieur(tablo, avet, pronor, verbe, kisi);
		  maxpuan+=zamanlar[7]*8;
          bos( boskisi, farklar );
		  if ( tumfilal( verbe, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
          karsilastir( kisi, boskisi, farklar );
		  puan=puanhesapla( puan, farklar[8], 7 );
      }


      if ( menu[1].centik[3] ) {
          zamanyaz("PASSE SIPMLE"); verbeyaz( fiil );
          puanyaz( puan );
		  psimple(tablo, pronor, verbe, kisi);
		  maxpuan+=zamanlar[8]*8;
          bos( boskisi, farklar );
		  if ( tumfilal( verbe, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
          karsilastir( kisi, boskisi, farklar );
		  puan=puanhesapla( puan, farklar[8], 8 );
      }


      if ( menu[2].centik[0] ) {
          zamanyaz("SUBJONCTIF PRESENT"); verbeyaz( fiil );
          puanyaz( puan );
		  subpresent(tablo, pronor, verbe, kisi);
		  maxpuan+=zamanlar[9]*8;
          bos( boskisi, farklar );
		  if ( tumfilal( verbe, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
          karsilastir( kisi, boskisi, farklar );
		  puan=puanhesapla( puan, farklar[8], 9 );
      }


      if ( menu[2].centik[1] ) {
          zamanyaz("SUBJONCTIF PASSE"); verbeyaz( fiil );
          puanyaz( puan );
		  subpasse(tablo, avet, pronor, verbe, kisi);
		  maxpuan+=zamanlar[10]*8;
          bos( boskisi, farklar );
		  if ( tumfilal( verbe, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
          karsilastir( kisi, boskisi, farklar );
		  puan=puanhesapla( puan, farklar[8], 10 );
       }


       if ( menu[2].centik[2] ) {
          zamanyaz("CONDITIONNEL PRESENT"); verbeyaz( fiil );
          puanyaz( puan );
		  conpresent(tablo, pronor, verbe, kisi);
		  maxpuan+=zamanlar[11]*8;
          bos( boskisi, farklar );
		  if ( tumfilal( verbe, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
          karsilastir( kisi, boskisi, farklar );
		  puan=puanhesapla( puan, farklar[8], 11 );
       }


       if ( menu[2].centik[3] ) {
          zamanyaz("CONDITIONNEL PASSE"); verbeyaz( fiil );
          puanyaz( puan );
		  conpasse(tablo, avet, pronor, verbe, kisi);
		  maxpuan+=zamanlar[12]*8;
          bos( boskisi, farklar );
		  if ( tumfilal( verbe, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
          karsilastir( kisi, boskisi, farklar );
		  puan=puanhesapla( puan, farklar[8], 12 );
       }
    }
	fl1=(float)puan; fl2=(float)maxpuan;
	window(2, 4, 79, 23 ); clrscr(); ekranyeni();
	textattr( LIGHTGREEN + (CYAN<<4) );
	gotoxy( 9, 2 ); cprintf(" Le Nombre de Temps Est: %d ", zs);
	gotoxy( 40, 2); cprintf(" Le Nombre de Verbes Est: %d ", fs);
	textattr( WHITE + (MAGENTA<<4) );
	gotoxy( 3, 3); cprintf(" Les Points Maximums Etaient: %.0f ", fl2 );
	gotoxy( 38, 3); cprintf(" Vous Avez Eu: %.0f  points  %.0f / 1000 ", fl1, (fl1/fl2)*1000 );
	textattr(esrn);

	if ( sampiyonmu( puan ) ) {
		cerceve(26-1, 10-1, 26+20, 10+1 );
		gotoxy(23, 8); cputs("Ecrivez Votre Prenom et Nom");
		if ( -1==cumleal(1, isim, 26, 10, 20 ) ) return;
		sampiyonayaz( isim, puan, (fl1/fl2)*1000 );
	}
	sampiyonlar( 18, 5);
}
void gagnants()
{
	sampiyonlar( 18, 5);
}




