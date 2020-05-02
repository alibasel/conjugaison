#include "tanimlar.h"
#include "cekimler.h"
#include "bilgiler.h"
#include "yardimci.h"

void  turkce( char *turk );

void exercices()
{
   char verbe[MAXFILUZ], kisi[9*MAXCEKUZ], boskisi[9*MAXCEKUZ], fiil[MAXFILUZ]="se";
   int num, farklar[9], a, avet, pronor, i, j;
   struct tt *tablo, tbl;
   extern struct men menu[6];

   ekranyeni(); clrscr();
   islevyaz("EXERCICES DE CONJUGAISON");

   pronor=verbeal( verbe, 27, 5 );
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

   present(tablo, pronor, verbe, kisi);
   while ( menu[0].centik[0] ) {
	  zamanyaz("PRESENT"); turkce(" seviyorum, severim ");
	  bos( boskisi, farklar );
	  if ( -1==tumfilal( fiil, &kisi[0], &boskisi[0], 5, 6 ) ) return;
	  karsilastir( kisi, boskisi, farklar );
	  if ( !farklar[8] ) {
		 sesiyi(); break;
	  }
	  if ( cekimyazex( fiil, kisi, 5, 6, farklar )==-1 ) return;
   }


   imparfait(tablo, pronor, verbe, kisi);
   while ( menu[0].centik[1] ) {
	  zamanyaz("IMPARFAIT"); turkce(" seviyordum, severdim ");
	  bos( boskisi, farklar );
	  if ( -1==tumfilal( fiil, &kisi[0], &boskisi[0], 5, 6 ) ) return;
	  karsilastir( kisi, boskisi, farklar );
	  if ( !farklar[8] ) {
		 sesiyi(); break;
	  }
	  if ( cekimyazex( fiil, kisi, 5, 6, farklar )==-1 ) return;
   }

	imperatif(tablo, pronor, verbe, kisi);
	while ( menu[0].centik[2] && pronor != 'i' ) {
		zamanyaz("IMPERATIF"); turkce(" sev ");
		bos( boskisi, farklar );
		if ( tumfilal( fiil, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
		karsilastir( kisi, boskisi, farklar );
		if ( !farklar[8] ) {
			sesiyi(); break;
		}
		if ( cekimyazex( fiil, kisi, 5, 6, farklar )==-1 ) return;
	}

	fsimple(tablo, pronor, verbe, kisi);
	while ( menu[0].centik[3] ) {
		zamanyaz("FUTUR SIMPLE"); turkce(" sevecegim ");
		bos( boskisi, farklar );
		if ( tumfilal( fiil, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
		karsilastir( kisi, boskisi, farklar );
		if ( !farklar[8] ) {
			sesiyi(); break;
		}
		if ( cekimyazex( fiil, kisi, 5, 6, farklar )==-1 ) return;
	}

	pcompose(tablo, avet, pronor, verbe, kisi);
	while ( menu[1].centik[0] ) {
		zamanyaz("PASSE COMPOSE"); turkce(" sevdim ");
		bos( boskisi, farklar );
		if ( tumfilal( fiil, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
		karsilastir( kisi, boskisi, farklar );
		if ( !farklar[8] ) {
			sesiyi(); break;
		}
		if ( cekimyazex( fiil, kisi, 5, 6, farklar )==-1 ) return;
	}

	pparfait(tablo, avet, pronor, verbe, kisi);
	while ( menu[1].centik[1] ) {
		zamanyaz("PLUS-QUE-PARFAIT"); turkce(" sevmistim ");
		bos( boskisi, farklar );
		if ( tumfilal( fiil, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
		karsilastir( kisi, boskisi, farklar );
		if ( !farklar[8] ) {
			sesiyi(); break;
		}
		if ( cekimyazex( fiil, kisi, 5, 6, farklar )==-1 ) return;
	}

	fanterieur(tablo, avet, pronor, verbe, kisi);
	while ( menu[1].centik[2] ) {
		zamanyaz("FUTUR ANTERIEUR"); turkce(" sevmis olacagim ");
		bos( boskisi, farklar );
		if ( tumfilal( fiil, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
		karsilastir( kisi, boskisi, farklar );
		if ( !farklar[8] ) {
			sesiyi(); break;
		}
		if ( cekimyazex( fiil, kisi, 5, 6, farklar )==-1 ) return;
	}

	psimple(tablo, pronor, verbe, kisi);
	while ( menu[1].centik[3] ) {
		zamanyaz("PASSE SIMPLE"); turkce(" sevdim ");
		bos( boskisi, farklar );
		if ( tumfilal( fiil, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
		karsilastir( kisi, boskisi, farklar );
		if ( !farklar[8] ) {
			sesiyi(); break;
		}
		if ( cekimyazex( fiil, kisi, 5, 6, farklar )==-1 ) return;
	}

	subpresent(tablo, pronor, verbe, kisi);
	while ( menu[2].centik[0] ) {
		zamanyaz("SUBJONCTIF PRESENT"); turkce(" seveyim ");
		bos( boskisi, farklar );
		if ( tumfilal( fiil, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
		karsilastir( kisi, boskisi, farklar );
		if ( !farklar[8] ) {
			 sesiyi(); break;
		}
		if ( cekimyazex( fiil, kisi, 5, 6, farklar )==-1 ) return;
	 }

	 subpasse(tablo, avet, pronor, verbe, kisi);
	 while ( menu[2].centik[1] ) {
		zamanyaz("SUBJONCTIF PASSE"); turkce(" sevmis olayim ");
		bos( boskisi, farklar );
		if ( tumfilal( fiil, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
		karsilastir( kisi, boskisi, farklar );
		if ( !farklar[8] ) {
			 sesiyi(); break;
		}
		if ( cekimyazex( fiil, kisi, 5, 6, farklar )==-1 ) return;
	 }

	 conpresent(tablo, pronor, verbe, kisi);
	 while ( menu[2].centik[2] ) {
		zamanyaz("CONDITIONNEL PRESENT"); turkce(" sevecektim ");
		bos( boskisi, farklar );
		if ( tumfilal( fiil, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
		karsilastir( kisi, boskisi, farklar );
		if ( !farklar[8] ) {
			 sesiyi(); break;
		}
		if ( cekimyazex( fiil, kisi, 5, 6, farklar )==-1 ) return;
	 }

	 conpasse(tablo, avet, pronor, verbe, kisi);
	 while ( menu[2].centik[3] ) {
		zamanyaz("CONDITIONNEL PASSE"); turkce(" sevmis olacaktim ");
		bos( boskisi, farklar );
		if ( tumfilal( fiil, &kisi[0], &boskisi[0], 5, 6 )==-1 ) return;
		karsilastir( kisi, boskisi, farklar );
		if ( !farklar[8] ) {
			 sesiyi(); break;
		}
		if ( cekimyazex( fiil, kisi, 5, 6, farklar )==-1 ) return;
	 }
}