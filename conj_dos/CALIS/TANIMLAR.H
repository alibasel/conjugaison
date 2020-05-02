#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mem.h>

#define MAXFILUZ 20
#define MAXCEKUZ 40
struct tt{
	int k1; char *ara1; int ek1;
	int k2; char *ara2; int ek2;
	int k3; char *ara3; int ek3;
	int k4; char *ara4; int ek4;
	int k5; char *ara5; int ek5;
	int k6; char *ara6; int ek6;
	int k7; char *ara7; int ek7;
	int k8; char *ara8; int ek8;
	int k9; char *ara9; int ek9;
	int k10; char *ara10; int ek10;
	int k11; char *ara11; int ek11;
	int k12; char *ara12; int ek12;
	int k13; char *ara13; int ek13;
	int k14; char *ara14; int ek14;
	int k15; char *ara15; int ek15;
	int k16; char *ara16; int ek16;
	int k17; char *ara17; int ek17;
	int k18; char *ara18; int ek18;
};
struct men {
	char solx;     /*   menunun konacagi yer                              */
	char sagx;
	char sagy;
	char *adr;     /*   menu listesinin bulundugu yerin adresi            */
	const char *baslik;  /*   menu basliginin      "      "      "              */
	char bsagx;    /*   menu basliginin  sutun  numarasi                  */
	char bsolx;
	char par;      /*   menude o anda parlak olan satr                   */
	int alt;       /*   menu bu tusla aktif olacak                        */
	int sicak[4];  /*   menudeki secenekler bu tuslarla da secilebilecek  */
	void (*islevler[4]) (void);   /* menu islevlerinin adresleri          */
	char centik[4]; /*  menudeki hangi secenege centik atilmis            */
};
struct aux{
	char *aux1, *aux2, *aux3, *aux4, *aux5, *aux6, *aux7, *aux8;
};
struct ek{
	char *ek1, *ek2, *ek3, *ek4, *ek5, *ek6, *ek7, *ek8;
};
