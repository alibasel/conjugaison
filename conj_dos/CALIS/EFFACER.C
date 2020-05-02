#include "tanimlar.h"
#include "yardimci.h"

void effacer()
{
   int sayi=verbesayisi(), bul, esrn=eskirenk();
   char ver[MAXFILUZ], fil[300*MAXFILUZ], *fiil=fil;
   FILE *dosya, *dosyagec;

    ekranyeni(); clrscr();
    islevyaz("EFFACER UN VERBE");

	if ( sayi>499 ) return;

	if ( -1==verbeal( ver, 27, 6 ) ) return;

	bul=ikiliara(ver, sayi);
	if (bul==-2) {
		cerceve( 22-1, 16-1, 22+30, 16+1 );
		gotoxy( 22, 16 ); textattr( YELLOW + (RED<<4) );
		cputs(" Je Ne Connais Pas Ce Verbe ! ");
		seskotu(); tusbekle(); textattr( esrn ); return;
    }

   if (bul>-1) {
		dosya=fopen( "cekim.dat","r" );
		if ( ! dosya ) {
			clrscr();gotoxy(20, 9);
            cputs("Le Fichier CEKIM.DAT N'Existe Pas Dans Le Disquette !");
            tusbekle(); return;
        }
		fread( fiil, MAXFILUZ, bul+1, dosya );

		dosyagec=fopen( "cekimgec.dat","w" );
		if ( ! dosyagec ) {
			clrscr(); gotoxy(20, 9);
            cputs("Erreur Dans Le Disquette !");
            tusbekle(); return;
        }
		fwrite( fiil, MAXFILUZ, bul, dosyagec );
		fread( fiil, MAXFILUZ, sayi-bul-1, dosya );
		fwrite( fiil, MAXFILUZ, sayi-bul-1, dosyagec );

		fclose(dosya); fclose(dosyagec);
		remove( "cekim.dat" ); rename( "cekimgec.dat", "cekim.dat" );
		sesiyi(); tusbekle();
    }
}
