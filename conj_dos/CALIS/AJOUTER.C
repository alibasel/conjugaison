#include "tanimlar.h"
#include "yardimci.h"

static int ikiliarayer( char [], int );

void ajouter()
{
   int sayi=verbesayisi(), bul, esrn=eskirenk();
   char ver[MAXFILUZ], acaba[MAXFILUZ], fil[500*MAXFILUZ], *fiil=fil;
   FILE *dosya, *dosyagec;

   ekranyeni(); clrscr();
   islevyaz("AJOUTER UN VERBE");

   if ( sayi>499 ) return;

   if ( -1==verbeal( ver, 27, 5 ) ) return;

   bul=ikiliarayer(ver, sayi);

   if (bul==-1) {
	  cerceve( 22-1, 16-1, 22+28, 16+1 );
	  gotoxy( 22, 16 ); textattr( YELLOW + (RED<<4) );
	  cputs(" Je Connais D‚j… Ce Verbe ! ");
	  seskotu(); tusbekle(); textattr( esrn ); return;
   }

   if (bul>-1) {
	   if ( !bul ) {
			oku( 0, acaba );
			if ( strcmp( ver, acaba ) > 0 ) bul=1;
	   }

	   strcpy( fiil+MAXFILUZ*bul, ver );

		dosya=fopen( "cekim.dat","r" );
		if ( ! dosya ) {
            gotoxy(20, 9);
            cputs("Le Fichier CEKIM.DAT N'Existe Pas Dans Le Disquette !");
            tusbekle(); return;
        }
		fread( fiil, MAXFILUZ, bul, dosya );


		dosyagec=fopen( "cekimgec.dat","w" );
		if ( ! dosyagec ) {
            gotoxy(20, 9);
            cputs("Erreur Dans Le Disquette !");
            tusbekle(); return;
        }
		fwrite( fiil, MAXFILUZ, bul+1, dosyagec );

        fread( fiil, MAXFILUZ, sayi-bul, dosya );

        fwrite( fiil, MAXFILUZ, sayi-bul, dosyagec );

        fclose(dosya);
        fclose(dosyagec);
        remove( "cekim.dat" );
        rename( "cekimgec.dat", "cekim.dat" );
		sesiyi(); tusbekle();
    }
}

static int  ikiliarayer(char verbe[], int n)
{
	char fil[MAXFILUZ];
    int dur, alt=0, ust=n-1, orta;

    while( alt <= ust ) {
        orta=(alt+ust)/2;
		oku( orta, fil );
        if ( (dur=strcmp( verbe, fil) ) < 0 )
            ust=orta-1;
        else if (dur>0)
            alt=orta+1;
		else return (-1);
    }
	return (orta);
}
