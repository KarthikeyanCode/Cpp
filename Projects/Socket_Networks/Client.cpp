// Client C++ program
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include<iostream>

using namespace std;

#define port 8080

int main(void)
{
	//socket connection
	FILE* image;
	FILE* file;
	int soc, bytes, opt, status, size, read_size, write_size;
	char image_buff[10241];
	char file_buff[500];
	char file_opt[500];
	struct sockaddr_in addr;
	char msg[100];
	char query[100];
	int msg_number[100];
	char buffer[1024] = {0};
	
	soc = socket(AF_INET, SOCK_STREAM, 0);
	addr.sin_family = AF_INET; //IPV4
	addr.sin_port = htons(port); //port 8080

	inet_pton(AF_INET, "127.0.01", &addr.sin_addr);

	connect:
	printf("Connecting to the server....\n");
	connect(soc, (struct sockaddr*)&addr, sizeof(addr));
	//client input/processing
	bytes = read(soc, buffer, 1024);
	printf("%s \n", buffer);
	while(1)
	{
		//connect(soc, (struct sockaddr*)&addr, sizeof(addr));
		printf("Choose: \n");
		printf("1. Ping\n");
		printf("2. Date, Day and Time \n");
		printf("3. Image\n");
		printf("4. Document\n");
		printf("5. Exit\n");
		scanf("%d", &opt);

		switch (opt)
		{
			case 1:
			{
				strcpy(query, "ping");
				send(soc, query, strlen(query)+1, 0);
				bytes = read(soc, buffer, 1024);
				printf("test\n");
				if(bytes < 0)
				{
					printf("Ping failed\n");
					goto connect;
				}
				else
				{
					printf("Ping succesful\n");
					printf("%s", buffer);
				}	
				break;
			}
			case 2:
			{
				strcpy(query, "time");
				printf("Fetching the information...\n");
				send(soc, query, strlen(query)+1, 0); //terminate using NULL character 
				bytes = read(soc, buffer, 1024);
				printf("%s \n", buffer);
				break;
			}
			case 3:
			{
				strcpy(query, "image");
				send(soc, query, strlen(query)+1, 0);
				do
				{
					status = read(soc, &size, sizeof(int));

				}while(status <0);
				printf("Image size received\n");
				image = fopen("received.jpeg", "w");
				if(image == NULL)
				{
					printf("Image file could not be created\n");

				}

				//receive the file data bytes
				do
				{
					read_size = read(soc, image_buff, 10241);
				}while(read_size<0);
				//writing the data into the files
				write_size = fwrite(image_buff, 1, read_size, image);
				printf("Data Received = %d bytes\n", read_size);
				printf("Data Written = %d bytes\n", write_size);
				fclose(image); 
				printf("Image Received\n");
				break;
			}
			case 4:
			{
				file = fopen("read_doc.txt", "r+");
				strcpy(query, "file");
				send(soc, query, strlen(query)+1, 0);
				printf("Fetching the data\n");
				do
				{
					bytes = read(soc, file_buff, sizeof(file_buff));

				}while(bytes<0);
				//writing to the file 
				printf("Writing to the file\n");
				fwrite(file_buff, 1, bytes, file);	
				system("gedit read_doc.txt &");
				bzero(file_buff, sizeof(file_buff));
				file_edit:
				fseek(file, 0, SEEK_SET);
				printf("Choose:\n");
				printf("1. Upload the changes to server\n");
				printf("2. Exit\n");
				scanf("%d", &opt);
				if(opt == 1)
				{
					strcmp(file_opt, "upload");
					send(soc, file_opt, strlen(file_opt)+1, 0);
					fread(file_buff, 1, sizeof(file_buff), file);
					send(soc, file_buff, strlen(file_buff)+1, 0);
					do
					{
						status = read(soc, buffer, 1024);
					}while(status<0);
					if(strcmp(buffer, "done")==0)
					{
						printf("Changes Uploaded successfully\n");
					}
					else
					{
						printf("Uploading failed, please try again\n");
					}
					printf("\n");
				}
				else if(opt == 2)
				{
					strcmp(file_opt, "exit");
					printf("Exiting file application\n");
				}
				else
				{
					printf("Enter only valid numbers\n");
					goto file_edit;
				}
				break;
			}
			case 5:
			{
				strcpy(query, "exit");
				printf("Exiting...\n");
				send(soc, query, strlen(query)+1, 0);
				goto exit;
				break;
			}
			default:
			{
				printf("Enter only valid numbers \n");
				continue;
			}
		}
		//clearing all the buffers
		bzero(query, sizeof(query));
		bzero(buffer, sizeof(buffer));
		bzero(file_buff, sizeof(file_buff));
		bzero(file_opt, sizeof(file_opt));
	}
	exit:
	printf("Closing the client\n");
	return 0;
}