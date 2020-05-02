#include "tanimlar.h"
#include "yardimci.h"

void chercher()
{
	int sayi, bul, esrn=eskirenk();
	char verbe[ MAXFILUZ ], ornek[ MAXFILUZ ];

    ekranyeni(); clrscr();
    islevyaz("CHERCHER UN VERBE");

    sayi=verbesayisi();

	if ( -1==verbeal( verbe, 27, 6 ) ) return;

    bul=ikiliara(verbe, sayi);
	textattr( YELLOW + (RED<<4) );
	if (bul>-1) {
		cerceve( 24-1, 16-1, 24+28, 16+1 );
		gotoxy( 24, 16 ); cputs(" Oui, Je Connais Ce Verbe ! ");
		sesiyi();
	}
	else {
		cerceve( 22-1, 16-1, 22+35, 16+1 );
		gotoxy( 22, 16 ); cputs(" Non, Je Ne Connais Pas Ce Verbe ! ");
		seskotu();
	}
	tusbekle(); textattr( esrn );
}

