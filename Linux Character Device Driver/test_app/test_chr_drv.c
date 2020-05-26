#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>


int8_t write_buf[1024];
int8_t read_buf[1024];

int main()
{
	int fd;
	char option;
	
	printf("Welcome to the demo of character device driver...\n");

	fd = open("/dev/my_device", O_RDWR, 0);
	if(fd < 0){
		printf("Cannot open device file...\n");
		return 0;
	}

	while(1){
		printf("**** Please Enter Your Option *****");
		printf("            1. Write               ");
		printf("            2. Read                ");
		printf("            3. Exit                ");
		scanf("%c", &option);
		printf("Your Option = %c\n", option);


		switch(option){
			case '1':
				printf("Enter the string to write into the driver:\n");
				scanf(" %[^\t\n]s",write_buf);
				printf("Data Written...");
				write(fd,write_buf,strlen(write_buf)+1);
				printf("DONE...\n");
				break;
			case '2':
				printf("Data is reading...");
				read(fd,read_buf,1024);
				printf("Done...\n\n");
				printf("Data = %s\n\n",read_buf);
				break;
			case '3':
				close(fd);
				exit(1);
				break;

			default:
				printf("Enter valid option = %c\n", option);
				break;

		}
	}
	close(fd);
}


