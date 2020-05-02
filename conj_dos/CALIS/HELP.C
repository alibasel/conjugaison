#include <dos.h>
#include "yardimci.h"

void help()
{
	#define T BLACK
	#define Y WHITE
	#define P RED

	char *secim[13]={"Genel Bilgiler", "Iner Menuler", "Zamanlar",
		"Conjugaison", "Exercice", "Teste", "Voir", "Ajouter", "Chercher",
		"Effacer", "Programme", "Gagnants", "Sortie"
	};
	int sut=32, sat=4, sec=0, tus, i;

	textattr(Y+(T<<4)); clrscr();
	islevyaz("PROGRAMIN ACIKLAMASI");
	cerceve(sut-1, sat-1, sut+15, sat+13);
	for(i=0; i<13; i++) {
		gotoxy(sut, sat+i); cputs( secim[i] );
	}
	ortayayaz("Ana Secim Ekranina Donmek Icin  ESC  Tusuna Basiniz",19);
	textbackground(P); gotoxy(sut, sat); cputs( secim[0] );

	do {
		tus=tusoku();
		switch (tus) {
			case 7181: helpyaz(sec, secim[sec]);
					   textattr(Y+(T<<4));
					   clrscr(); islevyaz("PROGRAMIN ACIKLAMASI");
					   cerceve(sut-1, sat-1, sut+15, sat+13);
					   for(i=0; i<13; i++) {
						   gotoxy(sut, sat+i); cputs( secim[i] );
					   }
					   ortayayaz("Ana Secim Ekranina Donmek Icin  ESC  Tusuna Basiniz",19);
					   textbackground(P); gotoxy(sut, sat+sec); cputs( secim[sec] );
					   textattr( WHITE+(BLACK<<4)); continue;
			case 283  : return;
			case 18432: textbackground(T); gotoxy(sut, sat+sec);
						cputs( secim[sec] );
						sec=sec>0 ? sec-1 : 12; gotoxy(sut, sat+sec);
						textbackground(P); cputs( secim[sec] );
						continue;
			case 20480: textbackground(T); gotoxy(sut, sat+sec);
						cputs( secim[sec] );
						sec=sec<12 ? sec+1 : 0; gotoxy(sut, sat+sec);
						textbackground(P); cputs( secim[sec] );
						continue;
		}
	}while(1);
}

void helpyaz(int sec, char *help)
{
	int c, sat=3;
	FILE *dosya;
	char *secim[13]={"genel.hlp", "inerm.hlp", "zaman.hlp",
		"conj.hlp", "exerc.hlp", "test.hlp", "voir.hlp", "ajouter.hlp", "chercher.hlp",
		"effacer.hlp", "prog.hlp", "gagnants.hlp", "sortie.hlp"
	};
	textattr(WHITE+(BLACK<<4)); clrscr();
	dosya=fopen( secim[sec],"r" );
	if ( ! dosya ) {
		gotoxy( 9, 16 );
		cputs("Aciklama Dosyalari Diskette Yok!");
		fclose(dosya); tusbekle(); return;
	}
	islevyaz("PROGRAMIN ACIKLAMASI"); ortayayaz(help,2);gotoxy(1,3);
	while( (c=getc(dosya)) !=EOF ) {
		if ( c=='\n' ) {
			gotoxy( 1, ++sat );
			continue;
		}
		putchar(c);
	}
	fclose(dosya); tusbekle();
}



