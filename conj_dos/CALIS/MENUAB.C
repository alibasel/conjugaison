#include "tanimlar.h"
#include "menuas.h"
#include "yardimci.h"
#include <malloc.h>

#define XX 200
#define ESRENK textattr( WHITE + (BLACK<<4) )


void menuyap( char *menusatirlar[], char yazi[], int satsay, int satuz,
			  char bas[], const char baslik[])
{
	int gsatsay=satsay+1, gsatuz=satuz*2+8, i, j, x, k;

	yazi[0]='Ú'; yazi[1]=N;
	for(i=1; i<gsatsay; i++) {
			 x=i*gsatuz;
			 yazi[x]='³'; yazi[x+1]=N;
			 yazi[x+2]=' '; yazi[x+3]=N;
			 for(k=0, j=4; j<gsatuz-4; j+=2, k++) {
					  yazi[x+j]=menusatirlar[i-1][k];
					  yazi[x+j+1]=N;
			 }
			 yazi[x+gsatuz-4]=' '; yazi[x+gsatuz-3]=N;
			 yazi[x+gsatuz-2]='³'; yazi[x+gsatuz-1]=N;
	}
	yazi[gsatsay*gsatuz]='À'; yazi[gsatsay*gsatuz+1]=N;
    for(i=2; i<gsatuz; i+=2) {
             yazi[i]='Ä'; yazi[i+1]=N;
             yazi[gsatsay*gsatuz+i]='Ä'; yazi[gsatsay*gsatuz+i+1]=N;
	}
    yazi[gsatsay*gsatuz]='À'; yazi[gsatsay*gsatuz+1]=N;
    yazi[gsatuz-2]='¿'; yazi[gsatuz-1]=N;
    yazi[gsatsay*gsatuz+gsatuz-2]='Ù';
    yazi[gsatsay*gsatuz+gsatuz-1]=N;

    bas[0]=baslik[0]; bas[1]=B;
	for(i=0; i<strlen(baslik)*2; i+=2) {
             bas[i+2]=baslik[1+i/2];
			 bas[i+3]=N;
	}
}
static void  menuhazirla()
{
	int i, satuz, satsay, u;


	satuz=strlen(menusatirlar0[1]);
	satsay=4;
	yazi0=(char *)malloc( (strlen(menusatirlar0[1])+4) *(satsay+2)*2 );
	bas0=(char *)malloc( strlen(baslik0)*2 );
	menuyap(menusatirlar0, yazi0, satsay, satuz, bas0, baslik0);
	menu[0].solx=2;
	menu[0].sagx=menu[0].solx+satuz+3;
	menu[0].sagy=satsay+3;
	menu[0].adr=yazi0;
	menu[0].baslik=bas0;
	menu[0].bsolx=4;
	menu[0].bsagx=menu[0].bsolx+strlen(baslik0)-1;
	menu[0].par=0;
	menu[0].alt=30720;
	menu[0].sicak[0]=15104;
	menu[0].sicak[1]=15360;
	menu[0].sicak[2]=15616;
	menu[0].sicak[3]=15872;
	menu[0].islevler[0]=centik00;
	menu[0].islevler[1]=centik01;
	menu[0].islevler[2]=centik02;
	menu[0].islevler[3]=centik03;
	menu[0].centik[0]=1;
	menu[0].centik[1]=1;
	menu[0].centik[2]=1;
	menu[0].centik[3]=1;


	satuz=strlen(menusatirlar1[1]);
	satsay=4;
	yazi1=(char *)malloc( (strlen(menusatirlar1[1])+4) *(satsay+2)*2 );
	bas1=(char *)malloc( strlen(baslik1)*2 );
	menuyap(menusatirlar1, yazi1, satsay, satuz, bas1, baslik1);
	menu[1].solx=17;
	menu[1].sagx=menu[1].solx+satuz+3;
	menu[1].sagy=satsay+3;
	menu[1].adr=yazi1;
	menu[1].baslik=bas1;
	menu[1].bsolx=19;
	menu[1].bsagx=menu[1].bsolx+strlen(baslik1)-1;
	menu[1].par=0;
	menu[1].alt=30976;
	menu[1].sicak[0]=16128;
	menu[1].sicak[1]=16384;
	menu[1].sicak[2]=16640;
	menu[1].sicak[3]=16896;
	menu[1].islevler[0]=centik10;
	menu[1].islevler[1]=centik11;
	menu[1].islevler[2]=centik12;
	menu[1].islevler[3]=centik13;
	menu[1].centik[0]=1;
	menu[1].centik[1]=1;
	menu[1].centik[2]=1;
	menu[1].centik[3]=1;


	satuz=strlen(menusatirlar2[1]);
	satsay=4;
	yazi2=(char *)malloc( (strlen(menusatirlar2[1])+4) *(satsay+2)*2 );
	bas2=(char *)malloc( strlen(baslik2)*2 );
	menuyap(menusatirlar2, yazi2, satsay, satuz, bas2, baslik2);
	menu[2].solx=33;
	menu[2].sagx=menu[2].solx+satuz+3;
	menu[2].sagy=satsay+3;
	menu[2].adr=yazi2;
	menu[2].baslik=bas2;
	menu[2].bsolx=34;
	menu[2].bsagx=menu[2].bsolx+strlen(baslik2)-1;
	menu[2].par=0;
	menu[2].alt=31232;
	menu[2].sicak[0]=17152;
	menu[2].sicak[1]=17408;
	menu[2].sicak[2]=21504;
	menu[2].sicak[3]=21760;
	menu[2].islevler[0]=centik20;
	menu[2].islevler[1]=centik21;
	menu[2].islevler[2]=centik22;
	menu[2].islevler[3]=centik23;
	menu[2].centik[0]=1;
	menu[2].centik[1]=1;
	menu[2].centik[2]=1;
	menu[2].centik[3]=1;


	satuz=strlen(menusatirlar3[0]);
	satsay=3;
	yazi3=(char *)malloc( (strlen(menusatirlar3[1])+4) *(satsay+2)*2 );
	bas3=(char *)malloc( strlen(baslik3)*2 );
	menuyap(menusatirlar3, yazi3, satsay, satuz, bas3, baslik3);
	menu[3].solx=45;
	menu[3].sagx=menu[3].solx+satuz+3;
	menu[3].sagy=satsay+3;
	menu[3].adr=yazi3;
	menu[3].baslik=bas3;
	menu[3].bsolx=49;
	menu[3].bsagx=menu[3].bsolx+strlen(baslik3)-1;
	menu[3].par=0;
	menu[3].alt=8448;
	menu[3].sicak[0]=11779;
	menu[3].sicak[1]=4613;
	menu[3].sicak[2]=5140;
	menu[3].sicak[3]=-1;
	menu[3].islevler[0]=conjugaison;
	menu[3].islevler[1]=exercices;
	menu[3].islevler[2]=teste;


	satuz=strlen(menusatirlar4[2]);
	satsay=4;
	yazi4=(char *)malloc( (strlen(menusatirlar4[1])+4) *(satsay+2)*2 );
	bas4=(char *)malloc( strlen(baslik4)*2 );
	menuyap(menusatirlar4, yazi4, satsay, satuz, bas4, baslik4);
	menu[4].solx=59;
	menu[4].sagx=menu[4].solx+satuz+3;
	menu[4].sagy=satsay+3;
	menu[4].adr=yazi4;
	menu[4].baslik=bas4;
	menu[4].bsolx=61;
	menu[4].bsagx=menu[4].bsolx+strlen(baslik4)-1;
	menu[4].par=0;
	menu[4].alt=12032;
	menu[4].sicak[0]=-1;
	menu[4].sicak[1]=-1;
	menu[4].sicak[2]=-1;
	menu[4].sicak[3]=-1;
	menu[4].islevler[0]=voir;
	menu[4].islevler[1]=chercher;
	menu[4].islevler[2]=ajouter;
	menu[4].islevler[3]=effacer;


	satuz=strlen(menusatirlar5[0]);
	satsay=4;
	yazi5=(char *)malloc( (strlen(menusatirlar5[1])+4) *(satsay+2)*2 );
	bas5=(char *)malloc( strlen(baslik5)*2 );
	menuyap(menusatirlar5, yazi5, satsay, satuz, bas5, baslik5);
	menu[5].solx=67;
	menu[5].sagx=menu[5].solx+satuz+3;
	menu[5].sagy=satsay+3;
	menu[5].sagx=79;
	menu[5].adr=yazi5;
	menu[5].baslik=bas5;
	menu[5].bsolx=70;
	menu[5].bsagx=menu[5].bsolx+strlen(baslik5)-1;
	menu[5].par=0;
	menu[5].alt=6400;
	menu[5].sicak[0]=-1;
	menu[5].sicak[1]=-1;
	menu[5].sicak[2]=-1;
	menu[5].sicak[3]=-1;
	menu[5].islevler[0]=voix;
	menu[5].islevler[1]=programme;
	menu[5].islevler[2]=gagnants;
	menu[5].islevler[3]=sortie;
	menu[5].centik[0]=0;

		// Buraya en uzun menu satiri yazilacak-->
	altyazilar=(char *)malloc( strlen(menusatirlar1[1]) );
}


main(int argc, char *argv[] )
{
	int tus, esrn=eskirenk(), directvideo=1;
	char sifre1[4]="ali", sifre2[6]="basel";
	menuhazirla(); anaekr();

	if ( strlen(sifre1)!=3 || strlen(sifre2)!=5
		|| sifre1[0]!='a' || sifre1[1]!='l' || sifre1[2]!='i'
		|| sifre2[0]!='b' || sifre2[1]!='a' || sifre2[2]!='s'
		|| sifre2[3]!='e' || sifre2[4]!='l' ) {
		clrscr(); seskotu(); gotoxy(2,19);
		puts("LUTFEN PROGRAMIN SIFRESINI DEGISTIRMEYE CALISMAYIN !!!");
		seskotu(); exit(0);
	}
	cursor( 0 );
	menuindir(0); delay(XX); menuasagi(0); delay(XX); menuasagi(0); delay(XX);
	menuasagi(0); delay(XX); menusag(0); delay(XX);

	menuasagi(1); delay(XX); menuasagi(1); delay(XX);
	menuasagi(1); delay(XX); menusag(1); delay(XX);

	menuasagi(2); delay(XX); menuasagi(2); delay(XX);
	menuasagi(2); delay(XX); menusag(2); delay(XX);

	menuasagi(3); delay(XX); menuasagi(3); delay(XX);
	menusag(3); delay(XX);

	menuasagi(4); delay(XX); menuasagi(4); delay(XX);
	menusag(4); delay(XX); menuasagi(5); delay(XX); menureturn(5);

	if ( argc!=3 || strcmp(argv[1], sifre1) || strcmp(argv[2], sifre2) ){
		clrscr(); gotoxy(2,10);
		puts("Vous n'avez pas le droit d'utiliser cet EXTRAORDINAIRE programme !");
		puts("Je suis triste pour vous !!!");
		seskotu(); exit(0);
	}

	while(1) {
		ekranyeni(); clrscr(); textattr( YELLOW +(RED<<4) );
		cursor( 0 );
		ortayayaz("UTILISER LES CHOIX DESCENDANTS POUR CHOISIR UNE FONCTION...", 10);
		ortayayaz("ou",11);
		ortayayaz("Appuyez sur  ?  Pour Voir Les informations d'utilisation.",12);
		textattr( esrn );

		tus=tusoku(); enterilemi=0;
		if ( tus==3135 || tus==13631) {
			help();
			continue;
		}
		if (menuler(tus)) continue;
		sicaklar(tus,-1);
	}
}

static int  sicaklar(int tus, int m)
{
	int secim[2];
	register i,j;
	if (tus==283 && m>=0) {
		menukaldir(m);
		return 0;
	}
	for (i=0;i<=mensay;++i)
		for (j=0;j<=3;++j)
			if (tus==menu[i].sicak[j]) {
				secim[0]=i;
				secim[1]=j;
				if (m>=0) menukaldir(m);
				enterilemi=0; dallanislev(secim);
				return 0;
			}
	return 1;
}
static int  menuler(int tus)
{
	int i;

	for (i=0;i<=mensay;++i)
		if (tus==menu[i].alt) {
			menuic(i);
			return 1;
		}
	return 0;
}

static void  menuic(int m)
{
	int don=1, tus;
	menuindir(m);
	while (don) {
		tus=tusoku();
		switch (tus) {
			case 7181 : don=menureturn(m);
						break;
			case 18432: don=menuyukari(m);
						break;
			case 20480: don=menuasagi(m);
						break;
			case 19712: m=menusag(m);
						break;
			case 19200: m=menusol(m);
						break;
			default:    don=sicaklar(tus,m);
		}
	}
}
static void  menuindir(int m)
{
	baslik(m);
	gettext(menu[m].solx, 2, menu[m].sagx, menu[m].sagy, altyazilar);
	puttext(menu[m].solx, 2, menu[m].sagx, menu[m].sagy, menu[m].adr);
	parlat(menu[m].par, menu[m].par, m);
}
static void  menukaldir(int m)
{
	puttext(menu[m].solx, 2, menu[m].sagx, menu[m].sagy, altyazilar);
	puttext(menu[m].bsolx, 1, menu[m].bsagx, 1, menu[m].baslik);
}

static int  menureturn(int m)
{
	int secim[2];
	secim[0]=m;
	secim[1]=menu[m].par;
	menukaldir(m);
	enterilemi=1; dallanislev(secim);
	return 0;
}
static int  menuyukari(int m)
{
	int sayi=menu[m].sagy-2-2;
	int yer=menu[m].par;
	if (yer>0) yer--;
	else if (yer==0) yer=sayi;
	parlat(yer, menu[m].par, m);
	menu[m].par=yer;
	return 1;
}
static int  menuasagi(int m)
{
	int sayi=menu[m].sagy-2-2;
	int yer=menu[m].par;
	if (yer<sayi) yer++;
	else if (yer==sayi) yer=0;
	parlat(yer, menu[m].par, m);
	menu[m].par=yer;
	return 1;
}
static int  menusag(int m)
{
	int em=m;
	if (m==mensay) m=0;
	else if (m<mensay) m++;
	menukaldir(em);
	menuindir(m);
	return m;
}
static int  menusol(int m)
{
	int em=m;
	if (m==0) m=mensay;
	else if (m>0) m--;
	menukaldir(em);
	menuindir(m);
	return m;
}
static void  parlat(int yeni, int eski, int m)
{
	int satesk=3+eski, sutesk=menu[m].solx+1, yer, baslaesk, baslayen;
	int satyen=3+yeni, sutyen=sutesk, uz;
	register i;

	baslaesk=((satesk-1)*80+(sutesk-1))*2+1;
	baslayen=((satyen-1)*80+(sutyen-1))*2+1;
	uz=menu[m].sagx-menu[m].solx-1;

	for (i=0;i<uz*2;i+=2) {
		pokeb(video,baslaesk+i,N);
		pokeb(video,baslayen+i,M);
	}
	menu[m].par=yeni;
}

static void  baslik(int m)
{
	int basla=menu[m].bsolx*2+1-2;
	int uz=menu[m].bsagx-menu[m].bsolx+1;
	register i;

	for (i=0;i<uz*2;i+=2)
		pokeb(video,basla+i,M);
}

static void  dallanislev(int *secim)
{
	menu[secim[0]].islevler[secim[1]] ();
}




static void  anaekr()
{
	struct text_info bilgi;
	char bas[160];
	register i;

	gettextinfo(&bilgi);
	switch (bilgi.currmode) {
		case 3: video=0xb800;
				break;
		case 7: video=0xb000;
				break;
	}

	ESRENK;	clrscr();
	cerceve(1,3,80,25);	yatayciz(2,22,78);
	textattr( YELLOW +(RED<<4) + BLINK );
	ortayayaz("CONJUGAISON (c) Copyright 1990, ALI BASEL GSL Tel:313 91 76", 23);
	ESRENK;
	for (i=0;i<160;i+=2) {
		bas[i]=' '; bas[i+1]=N;
	}
	puttext(1,1,80,1,bas);
	for (i=0;i<=mensay;++i)
		puttext(menu[i].bsolx, 1, menu[i].bsagx, 1, menu[i].baslik);
}

void programme()
{
	ESRENK;
	window(2,3,79,21); clrscr(); window(1,1,80,24);
	textattr( YELLOW+(RED<<4) );
	ortayayaz(" ÍÍ CONJUGAISON DE TOUS LES VERBES EN FRAN€AIS ÍÍ ", 3);
	ortayayaz("A l'aide de ce programme vouz pouvez : ",4);
	textattr( WHITE +(RED<<4) ); gotoxy(3, 6); cputs("* CONJUGUER");
	ESRENK; gotoxy(15,6); cputs("n'importe quel verbe aux 12 temps:");
	ortayayaz("- pr‚sent       - pass‚ compos‚     - subjonctif pr‚sent  ", 8);
	ortayayaz("- imparfait     - plus-que-parfait  - subjonctif pass‚    ", 9);
	ortayayaz("- imp‚ratif     - futur ant‚rieur   - conditionnel pr‚sent", 10);
	ortayayaz("- futur simple  - pass‚ simple      - conditionnel pass‚  ", 11);
	textattr( WHITE +(RED<<4) ); gotoxy(3, 13);cputs("* FAIRE DES EXERCICES");
	ESRENK; gotoxy(25,13); cputs("de conjugaison");
	textattr( WHITE +(RED<<4) );gotoxy(3, 15);cputs("* TESTER");
	ESRENK; gotoxy(12, 15); cputs("votre connaissance de conjugaison parmi des verbes fondamentaux");
	textattr( WHITE +(RED<<4) );gotoxy(3, 17);cputs("* AJOUTER ou EFFACER");
	ESRENK; gotoxy(24, 17);cputs("des verbes au liste du programme");
	textattr( LIGHTRED +(BLUE<<4) );
	ortayayaz("Ce Programme a ‚t‚ fait par ALI BASEL en octobre 1990", 19);
	ortayayaz("Avec La Langue Turbo C", 20);
	ESRENK;
	sesiyi(); seskotu();
	tusbekle(); ekranyeni();
}


static void  yatayciz(int sut, int sat, int uz)
{
	register i;
	gotoxy(sut, sat);
	for (i=0; i<uz; ++i) putch('Í');
}


void centik00()
{
	centikat( 0, 0, diger00);
	if ( !enterilemi ) return;

	zamyaz("PRESENT"); zamanlar();
	ekyaz(1,27,2); ekyaz(6,27,9);
	ekyaz(11,27,16); ekyaz(14,37,16); ekyaz(15,47,16);
	tusbekle();
}
void centik01()
{
	centikat( 0, 1, diger01);
	if ( !enterilemi ) return;

	zamyaz("IMPARFAT"); zamanlar();
	ekyaz(2,27,2); ekyaz(7,27,9); ekyaz(2,27,16);
	tusbekle();
}
void centik02()
{
	centikat( 0, 2, diger02);
	if ( !enterilemi ) return;

	zamyaz("IMPERATIF"); zamanlar();
	emir(1,27,2); emir(6,27,9);
	emir(11,27,16); emir(14,37,16); emir(15,47,16);
	tusbekle();
}
void centik03()
{
	centikat( 0, 3, diger03);
	if ( !enterilemi ) return;

	zamyaz("FUTUR SIMPLE"); zamanlar();
	ekyaz(3,27,2); ekyaz(3,27,9); ekyaz(3,27,16);
	tusbekle();
}
void centik10()
{
	centikat( 1, 0, diger10);
	if ( !enterilemi ) return;

	zamyaz("PASSE COMPOSE"); zamanlar();
	gecmis(25,3); gecmis(25,9); gecmis(25,16);
	tusbekle();
}
void centik11()
{
	centikat( 1, 1, diger11);
	if ( !enterilemi ) return;

	zamyaz("PLUS-QUE-PARFAIT"); zamanlar();
	gecmis(25,3); gecmis(25,9); gecmis(25,16);
	tusbekle();
}
void centik12()
{
	centikat( 1, 2, diger12);
	if ( !enterilemi ) return;

	zamyaz("FUTUR ANTERIEUR"); zamanlar();
	gecmis(25,3); gecmis(25,9); gecmis(25,16);
	tusbekle();
}
void centik13()
{
	centikat( 1, 3, diger13);
	if ( !enterilemi ) return;

	zamyaz("PASSE SIMPLE"); zamanlar();
	ekyaz(5,27,2); ekyaz(9,27,9); ekyaz(19,27,16); ekyaz(20,37,16);
	tusbekle();
}
void centik20()
{
	centikat( 2, 0, diger20);
	if ( !enterilemi ) return;

	zamyaz("SUBJONCTIF PRESENT"); zamanlar();
	ekyaz(4,27,2); ekyaz(7,27,9); ekyaz(8,27,16);
	tusbekle();
}
void centik21()
{
	centikat( 2, 1, diger21);
	if ( !enterilemi ) return;

	zamyaz("SUBJONCTIF PASSE"); zamanlar();
	gecmis(25,3); gecmis(25,9); gecmis(25,16);
	tusbekle();
}
void centik22()
{
	centikat( 2, 2, diger22);
	if ( !enterilemi ) return;

	zamyaz("CONDITIONNEL PRESENT"); zamanlar();
	ekyaz(2,27,2); ekyaz(2,27,9); ekyaz(2,27,16);
	tusbekle();
}
void centik23()
{
	centikat( 2, 3, diger23);
	if ( !enterilemi ) return;

	zamyaz("CONDITIONNEL PASSE"); zamanlar();
	gecmis(25,3); gecmis(25,9); gecmis(25,16);
	tusbekle();
}

void voix(void)
{
	centikat(5, 0, diger50);
}

static void  centikat(int mn, int kac, char *deg)
{
	int i, uz=strlen(deg), yr=uz*2+10+kac*(2*uz+8);
	char tekharf;

	for (i=0;i<uz;i++) {
		yr+=2;
		tekharf=menu[mn].adr[yr];
		menu[mn].adr[yr]=deg[i];
		deg[i]=tekharf;
	}
	( (menu[mn].centik[kac]) ? (menu[mn].centik[kac]=0) : (menu[mn].centik[kac]=1) );
}

static void  zamanlar()
{
	textattr(BLACK+(LIGHTGRAY<<4)); gotoxy(3,2); cputs(" Premier Groupe ");
	ESRENK; gotoxy(3,5); cputs("Verbes en");
	textattr(YELLOW+(RED<<4)); gotoxy(15,5); cputs("-er");

	textattr(BLACK+(LIGHTGRAY<<4)); gotoxy(3,9); cputs(" DeuxiŠme Groupe ");
	ESRENK; gotoxy(3,12); cputs("Verbes en");
	textattr(YELLOW+(RED<<4)); gotoxy(15,12); cputs("-ir");

	textattr(BLACK+(LIGHTGRAY<<4)); gotoxy(3,16); cputs(" TroisiŠme Groupe ");
	ESRENK; gotoxy(3,19); cputs("Verbes en");
	textattr(YELLOW+(RED<<4)); gotoxy(15,19); cputs("-oir");
	ESRENK; gotoxy(3,21); cputs("Verbes en");
	textattr(YELLOW+(RED<<4)); gotoxy(15,21); cputs("-re");
	ESRENK;
}

static void  ekyaz(int x, int sut, int sat)
{
	#include "auxek.h"

	ESRENK;
	textcolor(LIGHTRED);
	gotoxy(sut,sat++); cputs(ekler[x].ek1);
	gotoxy(sut,sat++); cputs(ekler[x].ek2);
	gotoxy(sut,sat++); cputs(ekler[x].ek3);
	gotoxy(sut,sat++); cputs(ekler[x].ek5);
	gotoxy(sut,sat++); cputs(ekler[x].ek6);
	gotoxy(sut,sat); cputs(ekler[x].ek7);
	ESRENK;
}
static void  emir(int x, int sut, int sat)
{
	#include "auxek.h"
	ESRENK;
	textcolor(LIGHTRED);
	gotoxy(sut,sat++); cputs(ekler[x].ek1);
	gotoxy(sut,sat++); cputs(ekler[x].ek5);
	gotoxy(sut,sat++); cputs(ekler[x].ek6);
	ESRENK;
}
static void  gecmis(int sut, int sat)
{
	ESRENK;
	textattr(LIGHTMAGENTA+(CYAN<<4));
	gotoxy(sut,sat+2); cputs(" On conjuge l'auxiliaire au temps voulu   ");
	textattr(CYAN+(MAGENTA<<4));
	gotoxy(sut,sat+3); cputs(" et on ajoute le participe pass‚ du verbe ");
	ESRENK;
}
static void  zamyaz( char *zaman )
{
    int i, uz;

    ESRENK;
	ekranyeni(); clrscr();
	textattr( WHITE + (RED<<4) );

	gotoxy(1, 1);
    for(i=0; i<78; i++) putch(' ');
    uz=strlen( zaman );
	gotoxy( 37-(uz/2), 1 ); cputs( zaman );

    ESRENK;
}


void sortie()
{
	exit (0);
}
