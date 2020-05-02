#include "tanimlar.h"
#include "cekimler.h"
#include "bilgiler.h"
#include "yardimci.h"

void  turkce( char * );

void conjugaison()
{
	char verbe[MAXFILUZ], kisi[9*MAXCEKUZ], fiil[MAXFILUZ]="se";
	int num, avet, pronor;
	struct tt *tablo, tbl;
	extern struct men menu[6];

	ekranyeni(); clrscr();

	islevyaz("CONJUGUER UN VERBE");

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

	if ( menu[0].centik[0] ) {
		zamanyaz("PRESENT"); turkce(" seviyorum, severim ");
		present(tablo, pronor, verbe, kisi);
		if ( cekimyaz(fiil, kisi, 5, 6)==-1 ) return;
	}

	if ( menu[0].centik[1] ) {
		zamanyaz("IMPARFAIT"); turkce(" seviyordum, severdim ");
		imparfait(tablo, pronor, verbe, kisi);
		if ( cekimyaz(fiil, kisi, 5, 6)==-1 ) return;
	}

	if ( menu[0].centik[2] && pronor != 'i' ) {
		zamanyaz("IMPERATIF"); turkce(" sev ");
		imperatif(tablo, pronor, verbe, kisi);
		if ( cekimyaz(fiil, kisi, 5, 6)==-1 ) return;
	}

	if ( menu[0].centik[3] ) {
		zamanyaz("FUTUR SIMPLE"); turkce(" sevecegim ");
		fsimple(tablo, pronor, verbe, kisi);
		if ( cekimyaz(fiil, kisi, 5, 6)==-1 ) return;
	}

	if ( menu[2].centik[2] ) {
		zamanyaz("CONDITIONNEL PRESENT"); turkce(" sevecektim ");
		conpresent(tablo, pronor, verbe, kisi);
		if ( cekimyaz(fiil, kisi, 5, 6)==-1 ) return;
	}

	if ( menu[1].centik[3] ) {
		zamanyaz("PASSE SIMPLE"); turkce(" sevdim ");
		psimple(tablo, pronor, verbe, kisi);
		if ( cekimyaz(fiil, kisi, 5, 6)==-1 ) return;
	}

	if ( menu[2].centik[0] ) {
		zamanyaz("SUBJONCTIF PRESENT"); turkce(" seveyim ");
		subpresent(tablo, pronor, verbe, kisi);
		if ( cekimyaz(fiil, kisi, 5, 6)==-1 ) return;
	}

	if ( menu[1].centik[0] ) {
		zamanyaz("PASSE COMPOSE"); turkce(" sevdim ");
		pcompose(tablo, avet, pronor, verbe, kisi);
		if ( cekimyaz(fiil, kisi, 5, 6)==-1 ) return;
	}

	if ( menu[1].centik[1] ) {
		zamanyaz("PLUS-QUE-PARFAIT"); turkce(" sevmistim ");
		pparfait(tablo, avet, pronor, verbe, kisi);
		if ( cekimyaz(fiil, kisi, 5, 6)==-1 ) return;
	}

	if ( menu[1].centik[2] ) {
		zamanyaz("FUTUR ANTERIEUR"); turkce(" sevmis olacagim ");
		fanterieur(tablo, avet, pronor, verbe, kisi);
		if ( cekimyaz(fiil, kisi, 5, 6)==-1 ) return;
	}

	if ( menu[2].centik[1] ) {
		zamanyaz("SUBJONCTIF PASSE"); turkce(" sevmis olayim ");
		subpasse(tablo, avet, pronor, verbe, kisi);
		if ( cekimyaz(fiil, kisi, 5, 6)==-1 ) return;
	}

	if ( menu[2].centik[3] ) {
		zamanyaz("CONDITIONNEL PASSE"); turkce(" sevmis olacaktim ");
		conpasse(tablo, avet, pronor, verbe, kisi);
		if ( cekimyaz(fiil, kisi, 5, 6)==-1 ) return;
	}
}

void  turkce( char *turk )
{
	int esrn=eskirenk();
	gotoxy(10,3); cputs("                                                           ");
	textattr( RED+(LIGHTGRAY<<4) );
	ortayayaz(turk,3);
	textattr(esrn);
}