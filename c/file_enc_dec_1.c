#include <stdio.h>
#include <stdlib.h>
/*
*	argv[1] "--encode"/"--decode"
*	argv[2] source filename
*	argv[3] destination filename
*/
int main(int argc, char *argv[])
{
	FILE *in, *out;
	char ch,i;
	if( (argc == 2) && (!strcmp(argv[1],"/?") ||!strcmp(argv[1],"help")) ){
		printf("\n"
			"	Utility to encode/decode source file to destination\n"
			"	ops <source filename> <destination file name>\n"
			"\n"
			"	--encode	- to encode the the source file to destination file\n"
			"	--decode	- to decode the the source file to destination file\n"
			"	/? or help	- to help\n");
		return 0;
	}
	if(argc<3){
		printf("	INVALID OPERATIONS no src/dest files and ops\n");
		printf("\n"
			"	ops <source filename> <destination file name>\n"
			"\n"
			"	--encode	- to encode the the source file to destination file\n"
			"	--decode	- to decode the the source file to destination file\n"
			"	/?		- to help\n");
		exit(1);
	}
	
	if((in=fopen(argv[2], "rb")) == NULL) {
		printf("Cannot open input file <%s>.\n",argv[2]);
		exit(1);
	}
	if((out=fopen(argv[3], "wb")) == NULL) {
		printf("Cannot open input file <%s>.\n",argv[3]);
		exit(1);
	}
	if(!strcmp(argv[1],"--encode")){
		printf("ENCODING\n");
		for(i=0;i<100;i++){
			ch = 'a';
			putc(ch, out);
		}
	}
	else{
		printf("DECODING\n");
		for(i=0;i<100;i++){
			ch = getc(in);
			//printf("%d %c %d\n",buf[0],buf[0],i);
		}
	}
	while(!feof(in)) {
		ch = getc(in);
		if(ferror(in)) {
			printf("Read Error");
			clearerr(in);
			break;
		} else {
			if(!feof(in))
				putc(ch, out);
			if(ferror(out)) {
				printf("Write Error");
				clearerr(out);
				break;
			}
		}
	}
	fclose(in);
	fclose(out);
	return 0;
}