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
};