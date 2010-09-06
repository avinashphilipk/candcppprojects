#include <stdio.h>
#include <fcntl.h>
/*
*	argv[1] "encode"/"decode"
*	argv[2] source filename
*	argv[3] output filename
*/
int main(int argc,char *argv[])
{
	FILE *fo,*fs;
	char buf[2];
	int i,retval;
	if(argc<=1){
		printf("INVALID OPERATIONS\n");
		return 0;
	}
	fs = fopen(argv[2],"rb");
	if(fs == NULL){
		printf("OPENING file %s FAILURE\n",argv[2]);
		return 0;
	}
	fo = fopen(argv[3],"wb");
		
	if(fo== NULL){
		printf("OPENING file %s FAILURE\n",argv[3]);
		return 0;
	}
	if(!strcmp(argv[1],"encode")){
		printf("ENCODING\n");
		for(i=0;i<100;i++){
			buf[0] = 'a';//*(char *)&i;
			fwrite(buf,1,1,fo);
		}
	}
	else{
		printf("DECODING\n");
		for(i=0;i<100;i++){
			fread(buf,1,1,fs);
			//printf("%d %c %d\n",buf[0],buf[0],i);
		}
	}
	while((retval = fread(buf,1,1,fs))>=0){
		
		if(!retval)
			if(feof(fs))
				break;
		fwrite(buf,1,1,fo);
		
	}
	printf("%d %x\n",retval,retval);
	/*if(!strcmp(argv[1],"encode")){
		printf("ENCODING\n");
		for(i=0;i<100;i++){
			buf[0] = 'a';//*(char *)&i;
			fwrite(buf,1,1,fo);
		}
	}
	else{
		printf("DECODING\n");
		for(i=0;i<100;i++){
			fread(buf,1,1,fs);
			printf("%d %c %d\n",buf[0],buf[0],i);
			//putchar(buf[0]);
		}
	}*/	
	fclose(fo);
	fclose (fs);
	return 0;
}