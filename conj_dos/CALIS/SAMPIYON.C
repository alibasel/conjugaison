#include "tanimlar.h"
#include "sampiyon.h"
#include "yardimci.h"

static void sifirla( void );

void  sampiyonlar( int sut, int sat )
{
	struct ch sampiyon[6];

    FILE *dosya;
	int i, j, a, uz=sizeof( struct ch ), esrn=eskirenk();

	dosya=fopen( "champs.dat","r" );
	if ( ! dosya ) {
		sifirla(); dosya=fopen( "champs.dat","r" );
    }


	a=fread( &sampiyon[0], uz, 6, dosya );
    fclose( dosya );
	if ( a!=6 ) {
		clrscr(); gotoxy(20, 9); cputs("Erreur Dans Le Disquette !");
		tusbekle(); return;
    }

	window(2, 6, 79, 23); clrscr();	ekranyeni();

	fiilciz( sut, sat, 8, 34 );

	gotoxy(sut+21, sat+1); putch('Â');
	gotoxy(sut+21+7, sat+1); putch('Â');

	for( i=0; i<6; i++ ) {
		gotoxy(sut+21, sat+2+i*2); putch('³');
		gotoxy(sut+21, sat+3+i*2); putch('Å');

		gotoxy(sut+21+7, sat+2+i*2); putch('³');
		gotoxy(sut+21+7, sat+3+i*2); putch('Å');
    }

	gotoxy(sut+21, sat+2+i*2); putch('³');
	gotoxy(sut+21+7, sat+2+i*2); putch('³');

	gotoxy(sut+21, sat+3+i*2); putch('Á');
	gotoxy(sut+21+7, sat+3+i*2); putch('Á');


	textattr( YELLOW + (RED<<4) );
    gotoxy(sut+9, sat); cputs("LES CHAMPIONS");
    gotoxy(sut, sat+2); cputs("Noms et Prenoms");
    gotoxy(sut+22, sat+2); cputs("Points");
    gotoxy(sut+29, sat+2); cputs("/1000");

    textattr( WHITE + (RED<<4) );
	for( i=0; i<6; i++ ) {
        gotoxy(sut, sat+4+i*2); cputs(sampiyon[i].isim);
        gotoxy(sut+22, sat+4+i*2); cprintf("%d",sampiyon[i].puan);
        gotoxy(sut+29, sat+4+i*2); cprintf("%d",sampiyon[i].binde);
    }

	textattr( esrn );
	if ( tusbekle()==-2 ) {
		sifirla();
        sampiyonlar( sut, sat );
	}
}

static void sifirla()
{
    struct ch sampiyon[6];
	int i, uz=sizeof( struct ch );
	FILE *dosya;

	for( i=0; i<6; i++ ) {
            strcpy( sampiyon[i].isim, "XXX YYYYY" );
			sampiyon[i].puan=500-i*50;
			sampiyon[i].binde=400-6*i;
	}
	strcpy( sampiyon[0].isim, "ALI BASEL" );
	sampiyon[0].puan=1000;
	sampiyon[0].binde=1000;
	dosya=fopen( "champs.dat","w" );
	fwrite( &sampiyon[0], uz, 6, dosya );
	fclose( dosya );
}

int  sampiyonmu( int puan )
{
	struct ch sampiyon[6];

    FILE *dosya;
    int i, j, a, uz=sizeof( struct ch );

	dosya=fopen( "champs.dat","r" );
	if ( ! dosya ) {
		sifirla(); dosya=fopen( "champs.dat","r" );
    }


	a=fread( &sampiyon[0], uz, 6, dosya );
    fclose( dosya );
	if ( a!=6 ) {
		clrscr(); gotoxy(20, 9);
		cputs("Erreur Dans Le Disquette !");
		tusbekle();	return(0);
    }

	for( i=0; i<6; i++ )
        if ( puan>sampiyon[i].puan ) return( 1 );
    return( 0 );
}

void  sampiyonayaz( char *ad, int puan, int binde )
{
	struct ch sampiyon[6];

    FILE *dosya;
    int i, j, a, uz=sizeof( struct ch );

	dosya=fopen( "champs.dat","r" );
	if ( ! dosya ) {
		sifirla(); dosya=fopen( "champs.dat","r" );
    }


	a=fread( &sampiyon[0], uz, 6, dosya );
    fclose( dosya );
	if ( a!=6 ) {
		clrscr(); gotoxy(20, 9);
		cputs("Erreur Dans Le Disquette !");
		tusbekle();	return;
    }
    a=-1;
	for( i=0; i<6; i++ )
        if ( puan>sampiyon[i].puan ) {
            a=i; break;
        }

    if ( a==-1 ) return;
	for( i=4; i>=a; i-- ) {
        sampiyon[i+1].puan=sampiyon[i].puan;
        sampiyon[i+1].binde=sampiyon[i].binde;
		strcpy( &sampiyon[i+1].isim[0], &sampiyon[i].isim[0] );
    }
    sampiyon[a].puan=puan;
    sampiyon[a].binde=binde;
	strcpy( &sampiyon[a].isim[0], ad );

    dosya=fopen( "champs.dat","w" );
	fwrite( &sampiyon[0], uz, 6, dosya );
    fclose( dosya );
}

