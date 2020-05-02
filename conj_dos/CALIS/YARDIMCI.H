#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <ctype.h>

#define RETURN 7181
#define ESC 283
#define BACKSPACE 3592
#define DEL 21248
#define SAG 19712
#define SOL 19200
#define GERI 15104
#define ILERI 15616
#define SEC 15360
#define ASAGI 20480
#define YUKARI 18432

void cursor( int option );
void  cerceve( int solx, int soly, int sagx, int sagy );
void  fiilciz( int, int, int, int );
int  cumleal( int, char *, int, int, int );
void  gerial( char *, int );
void  sagakaydir( char *, int );
void  cumleyaz( int, char *, int ,int );
int tusoku( void );
int  harfvarmi( char * );
int  verbeal(char *, int, int );
int eskirenk( void );
void  islevyaz( char * );
void  zamanyaz( char * );
void sesiyi(void);
void seskotu(void);

int  cumlealtum( char *, char *, int , int , int , int , int  );
int  tumfilal( char *, char *, char *, int , int  );
int  tumfilal1( int *, char * );

void ekranyeni( void );
void ekraneski( void );
int tusbekle( void );
void  karsilastir( char *, char *, int * );
void  verbeyaz( char * );
int  cekimyazex( char *, char *, int , int , int * );
int  cekimyaz( char *, char *, int , int );
void  bos( char *, int * );
void  ortayayaz( char *, int );

int  oku( int hangi, char *verbe );
int verbesayisi( void );
int  ikiliara( char [], int );

void help( void );
void helpyaz(int sec, char *help);