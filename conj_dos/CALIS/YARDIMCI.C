#include "tanimlar.h"
#include "yardimci.h"
#include "bilgiler.h"

void cursor(int option)
{
	union REGS r;

	r.h.ah=1;
	if ( option==1 ) {
		   r.h.ch=4;
		   r.h.cl=11;
	}
	else r.x.cx=-1;
	int86(	0x10,&r,&r );
}

void  fiilciz( int sut, int sat, int fsay, int maxuz )
{
	register i,j,k;
	cursor( 0 );
	sat--; sut--;
    if ( fsay==0  || maxuz==0 ) return;

	gotoxy( sut, sat ); putch( 'Ú' );
    for( j=0; j<maxuz; j++ ) putch( 'Ä' ); putch( '¿' );

	for( i=1, k=1; i<fsay; i++, k+=2 ) {
		gotoxy( sut, sat+k ); putch( '³' );
		gotoxy( sut+maxuz+1, sat+k ); putch( '³' );

		gotoxy( sut, sat+k+1 ); putch( 'Ã' );
        for( j=0; j<maxuz; j++ ) putch( 'Ä' ); putch( '´' );
    }
	gotoxy( sut, sat+k ); putch( '³' );
	gotoxy( sut+maxuz+1, sat+k ); putch( '³' );

	gotoxy( sut, sat+k+1 ); putch( 'À' );
    for( j=0; j<maxuz; j++ ) putch( 'Ä' ); putch( 'Ù' );
}


int  cumleal( int fran, char *cumle, int sut, int sat, int uz )
{
    union scan{
        int ts;
        char hf[2];
    }tus;
	char fransizca[20]="‚ Š ˆ ' “ – Œ ‹ ‡ ƒ";
    int esrn=eskirenk(), sec=0;

    register i,j;
    int eimlec=sut, eimlecson=sut, hv, cimlec=0, son=sut+uz;

	gotoxy(sut, sat);
	for( i=0; i<uz; i++ ) {
		cumle[i]=' ';
		putch(' ');
	}
	cumle[i]=NULL;

	if ( fran ) {
		textattr( WHITE + (RED<<4) );
		gotoxy( sut+sec, sat+3 ); putch(' '); cputs( fransizca );
		textattr( esrn );
		cerceve( sut+sec-1, sat+2, sut+sec+20, sat+7 );
		gotoxy( sut+sec+1, sat+4 ); putch('¯');
		gotoxy( sut+sec+9,  sat+5 ); cputs("F2");
		gotoxy( sut+sec+2, sat+6); cputs("F1");
		gotoxy( sut+sec+17, sat+6); cputs("F3");
	}

    while( 1 ) {
		gotoxy( eimlec, sat ); cursor( 1 );
        tus.ts=tusoku();

		if ( isprint( tus.hf[0] ) && eimlecson<son ) {
            hv=harfvarmi( &cumle[cimlec] );
            if ( hv && cumle[uz-1]==' ' ) {
                sagakaydir( cumle, cimlec );
                cumle[cimlec]=tus.hf[0];
				cumleyaz( sat, cumle, eimlec++, cimlec++ );
				eimlecson++;
                continue;
            }
            if ( !hv ) {
				gotoxy( eimlec++, sat ); putch( tus.ts);
				cumle[cimlec++]=tus.hf[0];
				eimlecson++;
                continue;
            }
            continue;
        }
		if ( tus.ts==DEL )
			if ( harfvarmi( &cumle[cimlec] ) ) {
				gerial( cumle, cimlec );
				cumleyaz( sat, cumle, eimlec, cimlec );
				eimlecson--;
				continue;
			}
		if ( tus.ts==BACKSPACE && cimlec>0 )  {
			gerial( cumle, --cimlec );
			eimlecson--;
			cumleyaz( sat, cumle, --eimlec, cimlec );
			continue;
		}
		switch ( tus.ts ) {
			case SAG :  if ( eimlec<eimlecson && eimlecson<=son ) {
							eimlec++; cimlec++;
						}
						continue;

			case SOL :  if ( eimlec>sut ) {
							eimlec--; cimlec--;
						}
						continue;

			case RETURN:for( i=uz-1; cumle[i] == ' '; i-- );
						cumle[i+1]=NULL;
						return ( 1 );

			case ESC   :return ( -1 );

			case GERI  :if ( fran ) {
							cursor( 0 );
							gotoxy( sut+sec+1, sat+4 ); putch(' ');
							sec=( sec>0 ? sec-2 : 18 );
							gotoxy( sut+sec+1, sat+4 ); putch('¯');
							cursor( 1 ); continue;
						}

			case ILERI :if ( fran ) {
							cursor( 0 );
							gotoxy( sut+sec+1, sat+4 ); putch(' ');
							sec=( sec<18 ? sec+2 : 0 );
							gotoxy( sut+sec+1, sat+4 ); putch('¯');
							continue;
						}

			case SEC   :if ( eimlec<=eimlecson && eimlecson<son && fran ) {
							hv=harfvarmi( &cumle[cimlec] );
							if ( hv && cumle[uz-1]==' ' ) {
								cursor( 0 );
								sagakaydir( cumle, cimlec );
								cumle[cimlec]=fransizca[sec];
								cumleyaz( sat, cumle, eimlec++, cimlec++ );
								eimlecson++; continue;
							}
							if ( !hv ) {
								cursor( 0 );
								gotoxy( eimlec++, sat ); putch( fransizca[sec]);
								cumle[cimlec++]=fransizca[sec];
								eimlecson++; continue;
							}
						}
		}
	}
}

void  gerial( char *cumle, int cimlec )
{
    register i;

    for( i=cimlec; cumle[i] != NULL; i++ )
        cumle[i]=cumle[i+1];
    cumle[i-1]=' ';
}

void  sagakaydir( char *cumle, int cimlec )
{
    register i;
    int uzek, uz;

    uz=strlen( cumle );
    uzek=strlen( &cumle[cimlec] );

    for( i=uz+uzek; i>=cimlec; i-- )
        cumle[i]=cumle[i-1];
    cumle[uz]=NULL;
}

int  harfvarmi( char *cumle )
{
    register i;
    for( i=0; cumle[i]==' '; i++);
    if ( cumle[i]==NULL ) return (0);
    return (1);
}

void  cumleyaz( int sat, char *cumle, int eimlec, int cimlec )
{
    gotoxy( eimlec, sat ); cputs( &cumle[cimlec] );
}

int tusoku()
{
    union REGS r;
    r.h.ah=0;
    return int86(0x16,&r,&r);
}

int  verbeal(char *verbe, int sut, int sat )
{
	struct tt *tablo, tbl;
    int num;

	gotoxy( sut+1, sat-2 );	cputs("Ecrivez Le Verbe");

	cerceve( sut-1, sat-1, sut+MAXFILUZ, sat+1 );
	if ( cumleal( 1, verbe, sut, sat, MAXFILUZ ) == -1 )  return (-1);
    if ( verbe[0]=='s' ) {
        if ( verbe[1]==39 ) {
            strcpy(verbe, &verbe[2]);
            return ('p');
        }
        if ( verbe[1]=='e' && verbe[2]==' ' ) {
            strcpy(verbe, &verbe[3]);
            return ('p');
        }
    }

	num=numbul(verbe);

	tbl=tablobul(num); tablo=&tbl;

	if ( ! strcmp( tablo->ara1, "#" ) ) return ('i') ;
    else return ('n');
}

int  tumfilal( char *verbe, char *kisi, char *boskisi, int sut, int sat )
{
	int a, uz=0, uz1, esrn, fsay=0, bilgi[4];
	register i, j;

	window( 2, 6, 78, 23 );  clrscr();
	ekranyeni();


	for( i=0; i<7*MAXCEKUZ+1; i+=MAXCEKUZ ) {
        if ( kisi[i] != NULL ) fsay++;
        uz1=strlen( &kisi[i] );
        if ( uz1>uz ) uz=uz1;
	}

	verbeyaz( verbe );

	bilgi[0]=fsay; bilgi[1]=uz;
	bilgi[2]=sut; bilgi[3]=sat;

	a=tumfilal1( bilgi, boskisi );
	if ( a==-1 ) return( -1 );

	for( i=0; i<fsay; i++ ) {
		uz=strlen( &boskisi[i*MAXCEKUZ] );
		for( j=uz-1; j>0; j-- )
			if ( boskisi[i*MAXCEKUZ+j] != ' ' ) {
				boskisi[i*MAXCEKUZ+j+1]=NULL;
				break;
			}
	}
	return(1);
}

int  tumfilal1( int *bilgi, char *boskisi )
{
	char fransizca[20]="‚ Š ˆ ' “ – Œ ‹ ‡ ƒ";
	int esrn=eskirenk(), x=0, y=0, j;
	int fransut, fransat, a, atla;
    register i;
	int fsay=bilgi[0], uz=bilgi[1], sut=bilgi[2], sat=bilgi[3];

	fransut=sut + uz + 6; fransat=sat + fsay;
    textattr( WHITE + (RED<<4) );
    gotoxy( fransut, fransat );	cputs( fransizca );
    textattr( esrn );
	cerceve( fransut-1, fransat-1, fransut+19, fransat+4 );
	gotoxy( fransut, fransat + 1 ); putch('¯');
	gotoxy( fransut+9, fransat+2 ); cputs("F2");
	gotoxy( fransut+1, fransat+3); cputs("F1");
	gotoxy( fransut+16, fransat+3); cputs("F3");

	for( i=0; i<fsay; i++ ) boskisi[i*MAXCEKUZ+uz]=NULL;

    fiilciz( sut, sat, fsay, uz );

    do {
		a=cumlealtum( &boskisi[x*MAXCEKUZ], fransizca, fransut, fransat+1, sut, sat+y, uz );

		atla=0;
		while ( a==1 ) {
			if ( x==fsay-1 ) return(1);
            x++; y+=2;
			if ( boskisi[x*41]==NULL ) {
				if ( x==fsay-1 ) return(1);
                x++; y+=2;
            }
			atla=10; break;
        }
		if (atla==10) continue;

        if ( a==2 ) {
			x=( x<fsay-1 ? x+1 : 0 );
			y=( y<fsay*2-2 ? y+2 : 0 );
            continue;
        }

        if ( a==3 ) {
			x=( x>0 ? x-1 : fsay-1 );
			y=( y>0 ? y-2 : 2*fsay-2 );
            continue;
        }

		if ( a==-1 ) return( a );

    }while(1);
}

int  cumlealtum( char *cumle, char *fransizca, int fransut, int fransat, int sut, int sat, int uz )
{
    union scan{
        int ts;
        char hf[2];
    }tus;

    register i,j;
	int eimlec=sut, eimlecson=sut, hv, cimlec=0, son=sut+uz, sec=0;

	gotoxy( fransut, fransat ); cputs("                  ");
	gotoxy( fransut, fransat ); putch('¯');

	for( i=uz-1; i>0; i-- )	  if ( cumle[i] != ' ' )  break;

	if ( i ) {
		eimlec=eimlecson=sut+i+1;
		cimlec=eimlec-sut;
	}

    while( 1 ) {
		cursor( 1 ); gotoxy( eimlec, sat );
        tus.ts=tusoku();

		if ( isprint( tus.hf[0] ) ) {
            hv=harfvarmi( &cumle[cimlec] );
            if ( hv && cumle[uz-1]==' ' ) {
                sagakaydir( cumle, cimlec );
                cumle[cimlec]=tus.hf[0];
				cumleyaz( sat, cumle, eimlec++, cimlec++ );
				if ( ++eimlecson==son ) return( 1 );
				continue;
            }
            if ( !hv ) {
				gotoxy( eimlec++, sat ); putch( tus.ts);
				cumle[cimlec++]=tus.hf[0];
                if ( ++eimlecson==son ) return( 1 );
                continue;
            }
            continue;
        }
            if ( tus.ts==DEL )
                if ( harfvarmi( &cumle[cimlec] ) ) {
                    gerial( cumle, cimlec );
                    cumleyaz( sat, cumle, eimlec, cimlec );
                    eimlecson--;
                    continue;
                }
            if ( tus.ts==BACKSPACE && cimlec>0 )  {
				gerial( cumle, --cimlec );
				eimlecson--;
				cumleyaz( sat, cumle, --eimlec, cimlec );
                continue;
            }
            switch ( tus.ts ) {
                case SAG :  if ( eimlec<eimlecson && eimlecson<=son ) {
                                eimlec++; cimlec++;
                            }
                            continue;

                case SOL :  if ( eimlec>sut ) {
                                eimlec--; cimlec--;
                            }
                            continue;

				case RETURN:return ( 1 );

                case ESC   :return ( -1 );

				case GERI  :gotoxy( fransut+sec, fransat ); putch(' ');
                            sec=( sec>0 ? sec-2 : 18 );
							gotoxy( fransut+sec, fransat ); putch('¯');
                            continue;

				case ILERI :gotoxy( fransut+sec, fransat ); putch(' ');
                            sec=( sec<18 ? sec+2 : 0 );
							gotoxy( fransut+sec, fransat ); putch('¯');
                            continue;

                case SEC   :if ( eimlec<=eimlecson && eimlecson<son ) {
                                hv=harfvarmi( &cumle[cimlec] );
                                if ( hv && cumle[uz-1]==' ' ) {
                                    sagakaydir( cumle, cimlec );
                                    cumle[cimlec]=fransizca[sec];
									cumleyaz( sat, cumle, eimlec++, cimlec++ );
									eimlecson++;
                                    continue;
                                }
                                if ( !hv ) {
									gotoxy( eimlec++, sat ); putch( fransizca[sec]);
									cumle[cimlec++]=fransizca[sec];
									eimlecson++;
                                    continue;
                                }
                            }
                case ASAGI  : return (2);
                case YUKARI : return (3);
           }
        }
}

int  cekimyaz(char *verbe, char *kisi, int sut, int sat)
{
			int i, j, uz1, uz=0, fsay=0;

			window( 2, 6, 78, 23 );  clrscr(); ekranyeni();

			for (i=0; i<8*MAXCEKUZ; i+=MAXCEKUZ )  {
				if ( kisi[i] != NULL )  fsay++;
				uz1=strlen( &kisi[i] );
				if ( uz1>uz ) uz=uz1;
			}

			if ( ! fsay ) return(1);
			verbeyaz( verbe );

			fiilciz( sut, sat, fsay, uz );

			for (j=0, i=0; i<fsay*MAXCEKUZ; i+=MAXCEKUZ, j+=2 ) {
				gotoxy( sut, sat+j ); cputs(&kisi[i]);
			}
			return ( tusbekle() );
}

int  cekimyazex(char *verbe, char *kisi, int sut, int sat, int *farklar)
{
			int i, j, k, uz1, y=0, uz=0, fsay=0, esrn=eskirenk();
			char a;

			for(i=0; i<8; i++)
				if ( farklar[i] != -1 ) y++;

			textcolor(LIGHTGREEN);
			gotoxy(60, 6); cputs("C'est Faux !");
			gotoxy(56, 7); cprintf("Vous avez fait %d fautes", y);
			seskotu(); textattr( esrn ); tusbekle();

			window( 2, 5, 78, 23 );  clrscr();
			ekranyeni();

			textcolor(LIGHTGREEN);
			gotoxy( 60, 6 ); puts("Maintenant");
			gotoxy(56, 7); cputs("Ecrivez le Justement ! ");
			textattr( esrn );

			for (i=0; i<8*MAXCEKUZ; i+=MAXCEKUZ )  {
				if ( kisi[i] != NULL )  fsay++;
				uz1=strlen( &kisi[i] );
				if ( uz1>uz ) uz=uz1;
			}

			if ( ! fsay ) return(1);

			verbeyaz( verbe );

			fiilciz( sut, sat, fsay, uz );

			for( i=0, k=0; i<fsay; i++, k+=2 ) {
				gotoxy( sut, sat+k );

				j=farklar[i];

				if ( j>-1 && j<strlen( &kisi[i*MAXCEKUZ] ) ) {
					a=kisi[i*MAXCEKUZ+j]; kisi[i*MAXCEKUZ+j]=NULL;
					cputs(&kisi[i*MAXCEKUZ]); kisi[i*MAXCEKUZ+j]=a;
					textcolor( LIGHTRED );
					gotoxy( sut+j, sat+k );
					cputs( &kisi[i*MAXCEKUZ+j] );
					textattr( esrn );
					continue;
				}
				cputs( &kisi[i*MAXCEKUZ] );
			}
			return( tusbekle() );
}

void  bos( char *boskisi, int *farklar )
{
   int i,j;

   for( i=0; i<8; i++ )  {
      farklar[i]=-1;
	  for( j=0; j<39; j++ )  boskisi[i*MAXCEKUZ+j]=' ';
	  boskisi[i*MAXCEKUZ-1]=NULL; boskisi[i*MAXCEKUZ]=NULL;
   }
   farklar[i]=0;
}
void  cerceve(int solx, int soly, int sagx, int sagy)
{
	register i;
	cursor( 0 ); gotoxy(solx, soly);
	putch('É');
	for (i=solx;i<sagx-1;++i)
			putch('Í');
	putch('»');
	for (i=soly+1;i<sagy;++i) {
			gotoxy(sagx,i); putch('º');
			gotoxy(solx,i); putch('º');
	}
	gotoxy(solx,sagy); putch('È');
	for (i=solx+1;i<sagx;++i)
			putch('Í');
	putch('¼');
}

int  ikiliara(char verbe[], int n)
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
		else return (orta);
	}
	return (-2);
}
int  oku( int hangi, char *verbe )
{
	FILE *dosya;
	int kac, i, ks;
	long yer;
	char orn[20];

	dosya=fopen( "cekim.dat","r" );
	if ( ! dosya ) {
		gotoxy(16, 9);
		cputs("Le Fichier CEKIM.DAT N'Existe Pas Dans Le Disquette !");
		tusbekle();	return(1);
	}
	ks=verbesayisi();
	if (hangi > ks ) {
		puts("hata");
		fclose(dosya); return(-2);
	}
	yer=hangi*MAXFILUZ;
	fseek(dosya, yer, SEEK_SET );
	fread( verbe, MAXFILUZ, 1, dosya );
	fclose(dosya);
}

int verbesayisi()
{
	FILE *dosya;
	long uz;

	dosya=fopen( "cekim.dat","r" );
	if ( ! dosya ) {
		gotoxy(16, 9);
        cputs("Le Fichier CEKIM.DAT N'Existe Pas Dans Le Disquette !");
		tusbekle();	return(1);
	}
	fseek( dosya, 0L, SEEK_END );
	uz=ftell(dosya);
	fclose(dosya);
	return (uz/MAXFILUZ);
}
void  ortayayaz( char *yazi, int sat )
{
	struct text_info bilgi;
	int sut;

	gettextinfo( &bilgi );
	sut=( bilgi.screenwidth - strlen( yazi )-2 ) / 2;
	gotoxy( sut, sat ); cputs( yazi );
}
int eskirenk()
{
    struct text_info a;
    gettextinfo( &a );
    return ( a.attribute );
}

void  islevyaz( char *islev )
{
	int i, esrk=eskirenk();

    textattr( YELLOW + (RED<<4) );

	cursor( 0 ); gotoxy(1, 1);
    for(i=0; i<78; i++) putch(' ');
	ortayayaz( islev, 1 );

    textattr( esrk );
}

void  zamanyaz( char *zaman )
{
	int i, esrk=eskirenk();

	textattr( WHITE + (BLUE<<4) );

	cursor( 0 ); gotoxy(1, 2);
    for(i=0; i<78; i++) putch(' ');
	ortayayaz( zaman, 2 );

    textattr( esrk );
}
void ekranyeni( void )
{
	window( 2, 3, 79, 23 );
}
void ekraneski( void )
{
	window( 1, 1, 80, 25);
}
void  verbeyaz( char *verbe )
{
			int esrn=eskirenk(), uz=strlen( verbe );

			textattr( YELLOW + (CYAN<<4) ); cursor( 0 );
			gotoxy( 59, 3 ); cputs("       VERBE        ");
			gotoxy( 59, 4 ); cputs("--------------------");
			gotoxy( 59, 5 ); cputs("                    ");
			gotoxy( (MAXFILUZ-uz)/2+59, 5 ); cputs(verbe);
			textattr( esrn );
}

int tusbekle()
{
	int i, uz, x, esrk=eskirenk();

	textattr( RED + (GREEN<<4) );
	window(1, 1, 80, 25 );
	cursor( 0 ); gotoxy(77, 23);
	cputs("TUS"); x=tusoku();

	textattr( esrk );
	gotoxy(77, 23); cputs("   ");
	ekranyeni();
	if ( x==283 ) return(-1);
	if ( x==21248 ) return(-2);
}

void  karsilastir( char *kisi, char *boskisi,int *farklar )
{
	register i,j;
	int fsay=0;

	for (i=0; i<8; i++ )
		if ( kisi[i*MAXCEKUZ] != NULL )  fsay++;

	for( i=0; i<fsay; i++ )
		for( j=0; j<strlen( &kisi[i*MAXCEKUZ] ); j++ )
			if ( kisi[i*MAXCEKUZ+j] != boskisi[i*MAXCEKUZ+j] ) {
				farklar[i]=j;
				break;
			}
	for( i=0; i<8; i++ ) if( farklar[i]!=-1 ) farklar[8]++;
}
void sesiyi()
{
	int i;
	extern struct men menu[6];

	if( !menu[5].centik[0] ) return;

	for(i=2000; i<4500; i+=15) {
		sound(i);
		delay(10);
	}
	nosound();
}
void seskotu()
{
	int i;
	extern struct men menu[6];

	if( !menu[5].centik[0] ) return;

	for(i=4500; i>2000; i-=15) {
		sound(i);
		delay(10);
	}
	nosound();
}
