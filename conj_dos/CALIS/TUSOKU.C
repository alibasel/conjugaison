

 #include <dos.h>

main()
{
	union scan {
		int c;
		char ch[2];
	}sc;

	do {
		sc.c=tus_oku();   /* Kesme ile yazilan islev */
		printf("%d\n", sc.c);
		if(sc.ch[0]==0)   /* Ozel tus mu ? denetimi */
			printf("OZEL BiR TUSA BASILDI, no= %d\n",sc.ch[1]);
		else
			printf("NORMAL BiR TUS, BASILAN TUS; %c\n",sc.ch[0]);
	}while(sc.ch[0]!='q');
}


tus_oku()
{
	union REGS r;

	r.h.ah=0;
	return int86(0x16,&r,&r);
}