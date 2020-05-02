#include "tanimlar.h"
#include "bilgiler.h"

int  numbul( char *verbe )
{
	#include "verbenum.h"

	int verbuz, yerk, yerv, i;

	verbuz=strlen(verbe);
	for(i=0; kokler[i].fil[0] != '*'; i++) {
		yerk=strlen( kokler[i].fil )-kokler[i].ek;
		yerv=verbuz-kokler[i].ek;
		if ( ! strcmp( &kokler[i].fil[yerk], &verbe[yerv] ) )
			return( kokler[i].num );
	}
	return(-1);
}

int  auxilbul( char verbe[] )
{
static const char auxiliaire[26][11]={
"advenir","aller","arriver","d‚c‚der","‚choir","‚clore",
"entrer","intervenir","monter","mourir","naŒtre","partir",
"parvenir","passer","provenir","redevenir","rentrer",
"repartir","rester","retourner","revenir","sortir",
"survenir","tomber","venir"
};

	int i;

	for( i=0; i<26; i++)
		if ( ! strcmp( verbe, auxiliaire[i] ) )
			return ('e');
	return ('a');
}
