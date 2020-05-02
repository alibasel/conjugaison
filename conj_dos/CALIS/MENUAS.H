#include <conio.h>
#include <dos.h>
#include <alloc.h>
#include <stdio.h>

#define N (YELLOW + (BLUE<<4) )
#define M (BLACK+(LIGHTGRAY<<4) ) /*(WHITE + (RED<<4) ) */
#define B (BLACK+(LIGHTGRAY<<4) ) /*(LIGHTRED + (BLUE<<4) )*/

void menuyap( char *menusatirlar[], char *yazi, int satsay, int satuz,
			  char *bas, const char *baslik);
static void  menuhazirla(void);
static int  sicaklar(int tus, int m);
static int  menuler(int tus);
static void  menuic(int m);
static void  menuindir(int m);
static void  menukaldir(int m);
static int  menureturn(int m);
static int  menuyukari(int m);
static int  menuasagi(int m);
static int  menusag(int m);
static int  menusol(int m);
static void  parlat(int yeni, int eski, int m);
static void  baslik(int m);
static void  dallanislev(int *secim);
static void  anaekr(void);
static void  yatayciz(int sut, int sat, int uz);

void centik00(void);
void centik01(void);
void centik02(void);
void centik03(void);
void centik10(void);
void centik11(void);
void centik12(void);
void centik13(void);
void centik20(void);
void centik21(void);
void centik22(void);
void centik23(void);
void voix(void);
static void centikat(int mn, int kac, char *deg);

void conjugaison(void);
void exercices(void);
void teste(void);
void programme(void);
void sortie(void);
void voir(void);
void chercher(void);
void ajouter(void);
void effacer(void);
void gagnants(void);

static void zamyaz( char * );
static void zamanlar( void );
static void ekyaz( int, int, int );
static void emir( int, int, int );
static void gecmis( int, int );

static unsigned int video;
static const int mensay=5;
struct men menu[6];

// 0 nolu menu bilgileri
static char *menusatirlar0[]={
	   "Pr‚sent   * F1",
	   "Imparfait * F2",
	   "Imp‚ratif * F3",
	   "F.Simple  * F4"
};
static char diger00[]="Pr‚sent     F1";
static char diger01[]="Imparfait   F2";
static char diger02[]="Imp‚ratif   F3";
static char diger03[]="F. Simple   F4";

static const char baslik0[]="1-Les Temps";

static char *yazi0, *bas0;



// 1 nolu menunun tanimlari
static char *menusatirlar1[]={
	   "P.Compos‚   * F5",
	   "P.Parfait   * F6",
	   "F.Ant‚rieur * F7",
	   "P.Simple    * F8"
};

static char diger10[]="P.Compos‚     F5";
static char diger11[]="P.Parfait     F6";
static char diger12[]="F.Ant‚rieur   F7";
static char diger13[]="P.Simple      F8";

static const char baslik1[]="2-Les Temps";

static char *yazi1, *bas1;

//2 nolu menu bilgileri
static char *menusatirlar2[]={
       "S.Pr‚sent * F9 ",
       "S.Pass‚   * F10",
       "C.Pr‚sent * SF1",
	   "C.Pass‚   * SF2"
};
static char diger20[]="S.Pr‚sent   F9 ";
static char diger21[]="S.Pass‚     F10";
static char diger22[]="C.Pr‚sent   SF1";
static char diger23[]="C.Pass‚     SF2";

static const char baslik2[]="3-Les Temps";

static char *yazi2, *bas2;


//3 nolu menu bilgileri
static char *menusatirlar3[]={
	   "Conjugaison  Ctrl-c",
	   "Exercices    Ctrl-e",
	   "Teste        Ctrl-t"
};

static const char baslik3[]="Fonctions";

static char *yazi3, *bas3;


// 4 nolu menu bilgileri
static char *menusatirlar4[]={
	   "Voir    ",
	   "Chercher",
	   "Ajouter ",
	   "Effacer "
};

static char diger40[]="Voir    ";
static char diger41[]="Chercher";
static char diger42[]="Ajouter ";
static char diger43[]="Effacer ";

static const char baslik4[]="Verbes";

static char *yazi4, *bas4;

// 5 nolu menu bilgileri
static char *menusatirlar5[]={
	   "Voix  Off",
	   "Programme",
	   "Gagnants ",
	   "Quitter  "
};

static char diger50[]="Voix   On";
static char diger51[]="Programme";
static char diger52[]="Gagnants ";
static char diger53[]="Quitter  ";

static const char baslik5[]="Programme";

static char *yazi5, *bas5;

static int enterilemi;

static char *altyazilar;

