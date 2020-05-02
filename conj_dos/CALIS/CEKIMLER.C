#include "tanimlar.h"
#include "cekimler.h"
#include "bilgiler.h"
#include "auxek.h"
#include "yardimci.h"
									/**************/
									/*  present   */
									/**************/
void  present(struct tt *tablo, int pronor, char *verbe, char *kisi)
{
	char suj[10], kes, kok[MAXCEKUZ];
	int term;
	bosalt( kisi );
						/* je */
	kokbul(tablo->k1, verbe, kok);
	strcpy(suj, "je");
	kes=kok[0];
	term=tablo->ek1;
	if ( strlen( verbe ) == tablo->k1 ) {
		if ( tablo->ara1[0]==NULL ) kes=ekler[ term ].ek1[0];
		else kes=tablo->ara1[0];
	}
	kesme(suj, kes);
	birlestir( &kisi[0], suj, kok, tablo->ara1, ekler[ term ].ek1 );
							/* tu */
	strcpy(suj, "tu ");
	birlestir( &kisi[1*MAXCEKUZ], suj, kok, tablo->ara1, ekler[ term ].ek2 );
	if ( ! strcmp( tablo->ara1, "*" ) ) {
		kisi[0]=NULL; kisi[MAXCEKUZ]=NULL;
	}
							/* il */
	kokbul(tablo->k2, verbe, kok);
	strcpy(suj, "il ");
	term=tablo->ek2;
	birlestir( &kisi[2*MAXCEKUZ], suj, kok, tablo->ara2, ekler[ term ].ek3 );
							/* elle */
	strcpy(suj, "elle ");
	birlestir( &kisi[3*MAXCEKUZ], suj, kok, tablo->ara2, ekler[ term ].ek4 );
	if ( ! strcmp( tablo->ara2, "*" ) ) {
		kisi[2*MAXCEKUZ]=NULL; kisi[3*MAXCEKUZ]=NULL;
	}
							/* nous */
	kokbul(tablo->k3, verbe, kok);
	strcpy(suj, "nous ");
	term=tablo->ek3;
	birlestir( &kisi[4*MAXCEKUZ], suj, kok, tablo->ara3, ekler[ term ].ek5 );
							/* vous */
	kokbul(tablo->k4, verbe, kok);
	strcpy(suj, "vous ");
	term=tablo->ek4;
	birlestir( &kisi[5*MAXCEKUZ], suj, kok, tablo->ara4, ekler[ term ].ek6 );
	if ( ! strcmp( tablo->ara3, "*" ) ) {
		kisi[4*MAXCEKUZ]=NULL; kisi[5*MAXCEKUZ]=NULL;
	}
							/* ils */
	kokbul(tablo->k5, verbe, kok);
	strcpy(suj, "ils ");
	term=tablo->ek5;
	birlestir( &kisi[6*MAXCEKUZ], suj, kok, tablo->ara5, ekler[ term ].ek7 );
							/* elles */
	strcpy(suj, "elles ");
	birlestir( &kisi[7*MAXCEKUZ], suj, kok, tablo->ara5, ekler[ term ].ek8 );
	if ( ! strcmp( tablo->ara5, "*" ) ) {
		kisi[6*MAXCEKUZ]=NULL; kisi[7*MAXCEKUZ]=NULL;
	}

	if ( pronor=='p' ) pronominale( kisi );
	if ( pronor=='i' ) impersonnel( kisi );
	duzelt( kisi );
}
									/**************/
									/*  imparfait */
									/**************/
void  imparfait(struct tt  *tablo, int pronor, char *verbe, char *kisi)
{
	char suj[10], kes, kok[MAXCEKUZ];
	int term;
	bosalt( kisi );

							/* je */
	kokbul(tablo->k6, verbe, kok);
	strcpy(suj, "je");
	kes=kok[0];
	if ( strlen( verbe ) == tablo->k6 ) {
		if ( tablo->ara6[0]==NULL ) kes=ekler[ tablo->ek6 ].ek1[0];
		else kes=tablo->ara6[0];
	}
	kesme(suj, kes);
	term=tablo->ek6;
	birlestir( &kisi[0], suj, kok, tablo->ara6, ekler[ term ].ek1 );
							/* tu */
	strcpy(suj, "tu ");
	birlestir( &kisi[1*MAXCEKUZ], suj, kok, tablo->ara6, ekler[ term ].ek2 );
							/* il */
	strcpy(suj, "il ");
	birlestir( &kisi[2*MAXCEKUZ], suj, kok, tablo->ara6, ekler[ term ].ek3 );
							/* elle */
	strcpy(suj, "elle ");
	birlestir( &kisi[3*MAXCEKUZ], suj, kok, tablo->ara6, ekler[ term ].ek4 );
							/* ils */
	strcpy(suj, "ils ");
	birlestir( &kisi[6*MAXCEKUZ], suj, kok, tablo->ara6, ekler[ term ].ek7 );
							/* elles */
	strcpy(suj, "elles ");
	birlestir( &kisi[7*MAXCEKUZ], suj, kok, tablo->ara6, ekler[ term ].ek8 );
	if ( ! strcmp( tablo->ara6, "*" ) ) {
		kisi[0]=NULL; kisi[1*MAXCEKUZ]=NULL;
		kisi[2*MAXCEKUZ]=NULL; kisi[3*MAXCEKUZ]=NULL;
		kisi[6*MAXCEKUZ]=NULL; kisi[7*MAXCEKUZ]=NULL;
	}
							/* nous */
	kokbul(tablo->k7, verbe, kok);
	strcpy(suj, "nous ");
	term=tablo->ek7;
	birlestir( &kisi[4*MAXCEKUZ], suj, kok, tablo->ara7, ekler[ term ].ek5 );
							/* vous */
	strcpy(suj, "vous ");
	birlestir( &kisi[5*MAXCEKUZ], suj, kok, tablo->ara7, ekler[ term ].ek6 );
	if ( ! strcmp( tablo->ara7, "*" ) ) {
	  kisi[4*MAXCEKUZ]=NULL; kisi[5*MAXCEKUZ]=NULL;
	}
	if ( pronor=='p' ) pronominale( kisi );
	if ( pronor=='i' ) impersonnel( kisi );
	duzelt( kisi );
}
							/*****************/
							/*  futur simple */
							/*****************/
void  fsimple(struct tt  *tablo, int pronor, char *verbe, char *kisi)
{
	char suj[10], kes, kok[MAXCEKUZ];
	bosalt( kisi );

							/* je */
	kokbul(tablo->k8, verbe, kok);
	strcpy(suj, "je");
	kes=kok[0];
	if ( strlen( verbe ) == tablo->k8 ) {
		if ( tablo->ara8[0]==NULL ) kes=ekler[ tablo->ek8 ].ek1[0];
		else kes=tablo->ara8[0];
	}
	kesme(suj, kes);
	birlestir( &kisi[0], suj, kok, tablo->ara8, ekler[ tablo->ek8 ].ek1 );
							/* tu */
	strcpy(suj, "tu ");
	birlestir( &kisi[1*MAXCEKUZ], suj, kok, tablo->ara8, ekler[ tablo->ek8 ].ek2 );
							/* il */
	strcpy(suj, "il ");
	birlestir( &kisi[2*MAXCEKUZ], suj, kok, tablo->ara8, ekler[ tablo->ek8 ].ek3 );
							/* elle */
	strcpy(suj, "elle ");
	birlestir( &kisi[3*MAXCEKUZ], suj, kok, tablo->ara8, ekler[ tablo->ek8 ].ek4 );
							/* nous */
	strcpy(suj, "nous ");
	birlestir( &kisi[4*MAXCEKUZ], suj, kok, tablo->ara8, ekler[ tablo->ek8 ].ek5 );
							/* vous */
	strcpy(suj, "vous ");
	birlestir( &kisi[5*MAXCEKUZ], suj, kok, tablo->ara8, ekler[ tablo->ek8 ].ek6 );
							/* ils */
	strcpy(suj, "ils ");
	birlestir( &kisi[6*MAXCEKUZ], suj, kok, tablo->ara8, ekler[ tablo->ek8 ].ek7 );
							/* elles */
	strcpy(suj, "elles ");
	birlestir( &kisi[7*MAXCEKUZ], suj, kok, tablo->ara8, ekler[ tablo->ek8 ].ek8 );

	if ( ! strcmp( tablo->ara8, "*" ) ) bosalt( kisi );

	if ( pronor=='p' ) pronominale( kisi );
	if ( pronor=='i' ) impersonnel( kisi );
	duzelt( kisi );
}

							/************************/
							/*  subjonctif present  */
							/************************/
void  subpresent(struct tt  *tablo, int pronor, char *verbe, char *kisi)
{
	char suj[10], kes, kok[MAXCEKUZ];
	bosalt( kisi );

							/* je */
	kokbul(tablo->k10, verbe, kok);
	strcpy(suj, "que je");
	kes=kok[0];
	if ( strlen( verbe ) == tablo->k10 ) {
		if ( tablo->ara10[0]==NULL ) kes=ekler[ tablo->ek10 ].ek1[0];
		else kes=tablo->ara10[0];
	}
	kesme(suj, kes);
	birlestir( &kisi[0], suj, kok, tablo->ara10, ekler[ tablo->ek10 ].ek1 );
							/* tu */
	strcpy(suj, "que tu ");
	birlestir( &kisi[1*MAXCEKUZ], suj, kok, tablo->ara10, ekler[ tablo->ek10 ].ek2 );
							/* il */
	strcpy(suj, "qu'il ");
	birlestir( &kisi[2*MAXCEKUZ], suj, kok, tablo->ara10, ekler[ tablo->ek10 ].ek3 );
							/* elle */
	strcpy(suj, "qu'elle ");
	birlestir( &kisi[3*MAXCEKUZ], suj, kok, tablo->ara10, ekler[ tablo->ek10 ].ek4 );
							/* ils */
	strcpy(suj, "qu'ils ");
	birlestir( &kisi[6*MAXCEKUZ], suj, kok, tablo->ara10, ekler[ tablo->ek10 ].ek7 );
							/* elles */
	strcpy(suj, "qu'elles ");
	birlestir( &kisi[7*MAXCEKUZ], suj, kok, tablo->ara10, ekler[ tablo->ek10 ].ek8 );
	if ( ! strcmp( tablo->ara10, "*" ) ) {
		kisi[0]=NULL; kisi[1*MAXCEKUZ]=NULL;
		kisi[2*MAXCEKUZ]=NULL; kisi[3*MAXCEKUZ]=NULL;
		kisi[6*MAXCEKUZ]=NULL; kisi[7*MAXCEKUZ]=NULL;
	}
							/* nous */
	kokbul(tablo->k11, verbe, kok);
	strcpy(suj, "que nous ");
	birlestir( &kisi[4*MAXCEKUZ], suj, kok, tablo->ara11, ekler[ tablo->ek11 ].ek5 );
							/* vous */
	strcpy(suj, "que vous ");
	birlestir( &kisi[5*MAXCEKUZ], suj, kok, tablo->ara11, ekler[ tablo->ek11 ].ek6 );
	if ( ! strcmp( tablo->ara11, "*" ) ) {
		kisi[4*MAXCEKUZ]=NULL; kisi[5*MAXCEKUZ]=NULL;
	}
	if ( pronor=='p' ) subpronominale( kisi );
	if ( pronor=='i' ) impersonnel( kisi );
	duzelt( kisi );
}
								/*****************/
								/*  passe simple */
								/*****************/
void  psimple(struct tt  *tablo, int pronor, char *verbe, char *kisi)
{
	char suj[10], kes, kok[MAXCEKUZ];
	bosalt( kisi );

							/* je */
	kokbul(tablo->k16, verbe, kok);
	strcpy(suj, "je");
	kes=kok[0];
	if ( strlen( verbe ) == tablo->k16 ) {
		if ( tablo->ara16[0]==NULL ) kes=ekler[ tablo->ek16 ].ek1[0];
		else kes=tablo->ara16[0];
	}
	kesme(suj, kes);
	birlestir( &kisi[0], suj, kok, tablo->ara16, ekler[ tablo->ek16 ].ek1 );
							/* tu */
	strcpy(suj, "tu ");
	birlestir( &kisi[1*MAXCEKUZ], suj, kok, tablo->ara16, ekler[ tablo->ek16 ].ek2 );
							/* il */
	strcpy(suj, "il ");
	birlestir( &kisi[2*MAXCEKUZ], suj, kok, tablo->ara16, ekler[ tablo->ek16 ].ek3 );
							/* elle */
	strcpy(suj, "elle ");
	birlestir( &kisi[3*MAXCEKUZ], suj, kok, tablo->ara16, ekler[ tablo->ek16 ].ek4 );
	if ( ! strcmp( tablo->ara16, "*" ) ) {
		kisi[0]=NULL; kisi[1*MAXCEKUZ]=NULL;
		kisi[2*MAXCEKUZ]=NULL; kisi[3*MAXCEKUZ]=NULL;
	}
							/* nous */
	kokbul(tablo->k17, verbe, kok);
	strcpy(suj, "nous ");
	birlestir( &kisi[4*MAXCEKUZ], suj, kok, tablo->ara17, ekler[ tablo->ek17 ].ek5 );
							/* vous */
	strcpy(suj, "vous ");
	birlestir( &kisi[5*MAXCEKUZ], suj, kok, tablo->ara17, ekler[ tablo->ek17 ].ek6 );
							/* ils */
	kokbul(tablo->k18, verbe, kok);
	strcpy(suj, "ils ");
	birlestir( &kisi[6*MAXCEKUZ], suj, kok, tablo->ara18, ekler[ tablo->ek18 ].ek7 );
							/* elles */
	strcpy(suj, "elles ");
	birlestir( &kisi[7*MAXCEKUZ], suj, kok, tablo->ara18, ekler[ tablo->ek18 ].ek8 );
	if ( ! strcmp( tablo->ara18, "*" ) ) {
		kisi[4*MAXCEKUZ]=NULL; kisi[5*MAXCEKUZ]=NULL;
		kisi[6*MAXCEKUZ]=NULL; kisi[7*MAXCEKUZ]=NULL;
	}
	if ( pronor=='p' ) pronominale( kisi );
	if ( pronor=='i' ) impersonnel( kisi );
	duzelt( kisi );
}

									/**************/
									/*  imperatif */
									/**************/
void  imperatif(struct tt  *tablo, int pronor, char *verbe, char *kisi)
{
	char suj[10], kok[MAXCEKUZ];
	int term;
	bosalt( kisi );
	if (pronor=='i' ) return;

							/* tu */
	kokbul(tablo->k13, verbe, kok);
	term=tablo->ek13;
	birlestir( &kisi[0], "", kok, tablo->ara13, ekler[ term ].ek1 );
	if ( ! strcmp( tablo->ara13, "*" ) )  kisi[0]=NULL;
							/* nous */
	kokbul(tablo->k14, verbe, kok);
	term=tablo->ek14;
	birlestir( &kisi[1*MAXCEKUZ], "", kok, tablo->ara14, ekler[ term ].ek5 );
	if ( ! strcmp( tablo->ara14, "*" ) )  kisi[1*MAXCEKUZ]=NULL;
							/* vous */
	kokbul(tablo->k15, verbe, kok);
	term=tablo->ek15;
	birlestir( &kisi[2*MAXCEKUZ], "", kok, tablo->ara15, ekler[ term ].ek6 );
	if ( ! strcmp( tablo->ara15, "*" ) )  kisi[2*MAXCEKUZ]=NULL;
	if ( pronor=='p' ) {
		if ( kisi[0]!=NULL ) strcat( &kisi[0], "-toi" );
		if ( kisi[1*MAXCEKUZ]!=NULL ) strcat( &kisi[1*MAXCEKUZ], "-nous" );
		if ( kisi[2*MAXCEKUZ]!=NULL ) strcat( &kisi[2*MAXCEKUZ], "-vous" );
	}
}

								/*************************/
								/*  conditionnel present */
								/*************************/
void  conpresent(struct tt  *tablo, int pronor, char *verbe, char *kisi)
{
	char suj[10], kes, kok[MAXCEKUZ];
	bosalt( kisi );

							/* je */
	kokbul(tablo->k12, verbe, kok);
	strcpy(suj, "je");
	kes=kok[0];
	if ( strlen( verbe ) == tablo->k12 ) {
		if ( tablo->ara12[0]==NULL ) kes=ekler[ tablo->ek12 ].ek1[0];
		else kes=tablo->ara12[0];
	}
	kesme(suj, kes);
	birlestir( &kisi[0], suj, kok, tablo->ara12, ekler[ tablo->ek12 ].ek1 );
							/* tu */
	strcpy(suj, "tu ");
	birlestir( &kisi[1*MAXCEKUZ], suj, kok, tablo->ara12, ekler[ tablo->ek12 ].ek2 );
							/* il */
	strcpy(suj, "il ");
	birlestir( &kisi[2*MAXCEKUZ], suj, kok, tablo->ara12, ekler[ tablo->ek12 ].ek3 );
							/* elle */
	strcpy(suj, "elle ");
	birlestir( &kisi[3*MAXCEKUZ], suj, kok, tablo->ara12, ekler[ tablo->ek12 ].ek4 );
							/* nous */
	strcpy(suj, "nous ");
	birlestir( &kisi[4*MAXCEKUZ], suj, kok, tablo->ara12, ekler[ tablo->ek12 ].ek5 );
							/* vous */
	strcpy(suj, "vous ");
	birlestir( &kisi[5*MAXCEKUZ], suj, kok, tablo->ara12, ekler[ tablo->ek12 ].ek6 );
							/* ils */
	strcpy(suj, "ils ");
	birlestir( &kisi[6*MAXCEKUZ], suj, kok, tablo->ara12, ekler[ tablo->ek12 ].ek7 );
							/* elles */
	strcpy(suj, "elles ");
	birlestir( &kisi[7*MAXCEKUZ], suj, kok, tablo->ara12, ekler[ tablo->ek12 ].ek8 );

	if ( ! strcmp( tablo->ara12, "*" ) ) bosalt( kisi );

	if ( pronor=='p' ) pronominale( kisi );
	if ( pronor=='i' ) impersonnel( kisi );
	duzelt( kisi );
}

static void  tempscomp(int han, struct tt  *tablo, int avet, int pronor, char *verbe ,char *kisi)
{
   int ae=0;
   extern struct aux auxil[];
   char kok[20]=" ", kok1[MAXCEKUZ], fems[2]={NULL}, feme[2]={NULL}, femes[3]={NULL};
   bosalt( kisi );

   ae=( (avet=='e') ? 1 : 0);
   kokbul(tablo->k9, verbe, kok1);
   strcat(kok, kok1);

	if ( avet=='e' ) {
		strcpy(feme, "e");
		strcpy(fems, "s");
		strcpy(femes, "es");
	}
	birlestir( &kisi[0], auxil[han+ae].aux1, kok, tablo->ara9, "");
	birlestir( &kisi[1*MAXCEKUZ], auxil[han+ae].aux2, kok, tablo->ara9, "");
	birlestir( &kisi[2*MAXCEKUZ], auxil[han+ae].aux3, kok, tablo->ara9, "");
	birlestir( &kisi[3*MAXCEKUZ], auxil[han+ae].aux4, kok, tablo->ara9, feme);
	birlestir( &kisi[4*MAXCEKUZ], auxil[han+ae].aux5, kok, tablo->ara9, fems);
	birlestir( &kisi[5*MAXCEKUZ], auxil[han+ae].aux6, kok, tablo->ara9, fems);
	birlestir( &kisi[6*MAXCEKUZ], auxil[han+ae].aux7, kok, tablo->ara9, fems);
	birlestir( &kisi[7*MAXCEKUZ], auxil[han+ae].aux8, kok, tablo->ara9, femes);

	if ( ! strcmp( tablo->ara9, "*" ) ) bosalt( kisi );

	if ( pronor=='p' && han!=6 ) pronominale( kisi );
	if ( pronor=='i' ) impersonnel( kisi );
	duzelt( kisi );
}

void  pcompose(struct tt  *tablo, int avet, int pronor, char *verbe, char *kisi)
{
   tempscomp( 0, tablo, avet, pronor, verbe, kisi);
}

void  pparfait(struct tt  *tablo, int avet, int pronor, char *verbe, char *kisi)
{
   tempscomp( 2, tablo, avet, pronor, verbe, kisi);
}

void  fanterieur(struct tt  *tablo, int avet, int pronor, char *verbe, char *kisi)
{
   tempscomp( 4, tablo, avet, pronor, verbe, kisi);
}

void  subpasse(struct tt  *tablo, int avet, int pronor, char *verbe, char *kisi)
{
   tempscomp( 6, tablo, avet, pronor, verbe, kisi);
   if ( pronor=='p' ) subpronominale( kisi );
}

void  conpasse(struct tt  *tablo, int avet, int pronor, char *verbe, char *kisi)
{
   tempscomp( 8, tablo, avet, pronor, verbe, kisi);
}

static void  pronominale( char *kisi )
{
	char satir[MAXCEKUZ], kes;

	if ( kisi[1]==39 ) {
		strcpy( satir, "je m'" );
		strcat( satir, &kisi[2] );
	}
	else {
		strcpy( satir, "je me" );
		kes=kisi[3]; kesme( satir, kes );
		strcat( satir, &kisi[3] );
	}
	strcpy( &kisi[0], satir );

	strcpy( satir, "tu te");
	kes=kisi[1*MAXCEKUZ+3]; kesme( satir, kes);
	strcat( satir, &kisi[1*MAXCEKUZ+3] );
	strcpy( &kisi[1*MAXCEKUZ], satir );

	strcpy( satir, "il se");
	kes=kisi[2*MAXCEKUZ+3]; kesme( satir, kes);
	strcat( satir, &kisi[2*MAXCEKUZ+3] );
	strcpy( &kisi[2*MAXCEKUZ], satir );

	strcpy( satir, "elle se");
	kesme( satir, kes);
	strcat( satir, &kisi[3*MAXCEKUZ+5] );
	strcpy( &kisi[3*MAXCEKUZ], satir );

	strcpy( satir, "nous nous");
	strcat( satir, &kisi[4*MAXCEKUZ+4] );
	strcpy( &kisi[4*MAXCEKUZ], satir );

	strcpy( satir, "vous vous");
	strcat( satir, &kisi[5*MAXCEKUZ+4] );
	strcpy( &kisi[5*MAXCEKUZ], satir );

	strcpy( satir, "ils se");
	kes=kisi[6*MAXCEKUZ+4]; kesme( satir, kes);
	strcat( satir, &kisi[6*MAXCEKUZ+4] );
	strcpy( &kisi[6*MAXCEKUZ], satir );

	strcpy( satir, "elles se");
	kesme( satir, kes);
	strcat( satir, &kisi[7*MAXCEKUZ+6] );
	strcpy( &kisi[7*MAXCEKUZ], satir );
}

static void  subpronominale( char *kisi )
{
	char satir[MAXCEKUZ], kes;

	if ( kisi[5]==39 ) {
		strcpy( satir, "que je m'" );
		strcat( satir, &kisi[6] );
	}
	else {
		strcpy( satir, "que je me" );
		kes=kisi[7]; kesme( satir, kes );
		strcat( satir, &kisi[7] );
	}
	strcpy( &kisi[0], satir );

	strcpy( satir, "que tu te");
	kes=kisi[1*MAXCEKUZ+7]; kesme( satir, kes);
	strcat( satir, &kisi[1*MAXCEKUZ+7] );
	strcpy( &kisi[1*MAXCEKUZ], satir );

	strcpy( satir, "qu'il se");
	kes=kisi[2*MAXCEKUZ+6]; kesme( satir, kes);
	strcat( satir, &kisi[2*MAXCEKUZ+6] );
	strcpy( &kisi[2*MAXCEKUZ], satir );

	strcpy( satir, "qu'elle se");
	kesme( satir, kes);
	strcat( satir, &kisi[3*MAXCEKUZ+8] );
	strcpy( &kisi[3*MAXCEKUZ], satir );

	strcpy( satir, "que nous nous");
	strcat( satir, &kisi[4*MAXCEKUZ+8] );
	strcpy( &kisi[4*MAXCEKUZ], satir );

	strcpy( satir, "que vous vous");
	strcat( satir, &kisi[5*MAXCEKUZ+8] );
	strcpy( &kisi[5*MAXCEKUZ], satir );

	strcpy( satir, "qu'ils se");
	kes=kisi[6*MAXCEKUZ+7]; kesme( satir, kes);
	strcat( satir, &kisi[6*MAXCEKUZ+7] );
	strcpy( &kisi[6*MAXCEKUZ], satir );

	strcpy( satir, "qu'elles se");
	kesme( satir, kes);
	strcat( satir, &kisi[7*MAXCEKUZ+9] );
	strcpy( &kisi[7*MAXCEKUZ], satir );
}

static void  impersonnel( char *kisi)
{
	char a[MAXCEKUZ];
	strcpy( a, &kisi[2*MAXCEKUZ] );
	bosalt( kisi );
	strcpy( &kisi[0], a );
}

static void  kokbul(int x, char *verbe, char *kok)
{
	int i;
	int uz,y;

	uz=strlen(verbe);
	y=uz-x;
	for (i=0;i<y;++i) kok[i]=verbe[i];
	kok[i]=NULL;
}

void  kesme(char *suj, char kes)
{
	int uz;
	char sujson;

	uz=strlen(suj);
	sujson=suj[uz-1];
	if (sujson != 'e') {
		strcat(suj, " ");
		return;
	}
	if (kes=='h' || kes=='a' || kes=='o' || kes=='e' || kes=='‚' || kes=='ˆ'|| kes=='i' || kes=='u') {
		suj[uz-1]=39;
		return;
	}
	strcat(suj, " ");
}

static void  birlestir(char *hedef, char *a, char *b, char *c, char *d)
{
	strcpy(hedef, a);
	strcat(hedef, b);
	strcat(hedef, c);
	strcat(hedef, d);
}
static void  duzelt( char *kisi )
{
	register i,j;

	for( i=0; i<8; i++ )
		while( kisi[i*MAXCEKUZ]==NULL ) {
			for( j=i+1; kisi[j*MAXCEKUZ]==NULL; j++ );
			if ( j>7 ) break;
			strcpy( &kisi[i*MAXCEKUZ], &kisi[j*MAXCEKUZ] );
			kisi[j*MAXCEKUZ]=NULL;
		}
}
void  bosalt( char *kisi )
{
   int i;
   for( i=0; i<8; i++ ) {
	kisi[i*MAXCEKUZ-1]=NULL; kisi[i*MAXCEKUZ]=NULL;
   }
}