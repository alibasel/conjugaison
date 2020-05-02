#include "tanimlar.h"
#include "voir.h"
#include "yardimci.h"

void voir()
{
    div_t kacotuz, kacon;

    FILE *dosya;
	int kac, i, ks=verbesayisi(), sut, esrn=eskirenk();
	char orn[ MAXFILUZ ], laf[80], cev[6];

	ekranyeni(); clrscr();
	strcpy(laf, "VOIR LES VERBES FONDAMENTAUX  NOMBRE:");
	itoa( ks, cev, 10); strcat( laf, cev );
	islevyaz( laf );

	dosya=fopen( "cekim.dat","r" );
	if ( ! dosya ) {
        gotoxy( 9, 16 );
        cputs("Le Fichier CEKIM.DAT n'existe pas Dans Le Disquette!");
		tusbekle(); return;
    }


	kacotuz=div( ks, 3*9 ); kacon=div( kacotuz.rem, 9);

	if ( -1==otuz( kacotuz.quot, dosya ) ) {
		fclose( dosya ); return;
	}

	window(2, 4, 79, 23); clrscr(); ekranyeni();
	sut=on( kacon.quot, dosya );
	fiilciz( sut, 3, 9, 20 );
	yedi( kacon.rem, sut, dosya );
	tusbekle();

	fclose(dosya);
	textattr(esrn);
}

static int  otuz( int kacotuz, FILE *dosya )
{
    int k;

    for( k=0; k<kacotuz; k++ ) {
		window(2, 4, 79, 23); clrscr(); ekranyeni();
        on( 3, dosya );
		if ( -1==tusbekle() ) return;
    }
}

static int  on( int kacon, FILE *dosya )
{
    int i;

    for( i=0; i<kacon; i++ ) {
		fiilciz( 4+i*25, 3, 9, 20 );
		yedi( 9, 4+i*25, dosya );
	}
	return( 4+i*25 );
}

static void  yedi( int kac, int sut, FILE *dosya )
{
	int j, esrn=eskirenk();
	char orn[MAXFILUZ];

	textattr( BLACK + (LIGHTGRAY<<4) );
    for( j=0; j<kac; j++ ) {
        fread( orn, MAXFILUZ, 1, dosya );
		gotoxy( sut, 3+2*j ); cputs( orn );
	}
	textattr(esrn);
}
