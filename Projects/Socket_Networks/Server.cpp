//server side code for socket - Cpp program

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<time.h>

#define PORT 8080

int main(void)
{
	FILE* img;
	time_t current_time;
	int server, inc_socket, no_of_bytes, addrlen, status;
	int opt=1;
	int size, read_size;
	char buff[5000];
	char image_buff[10240];
	char msg[] = "Hello, connection has been established with Server";
	char ping[] = "Connection Alive\n";
	char time_[25];
	struct sockaddr_in addr; //addr is object of struct sockaddr_in
	addrlen = sizeof(addr);
	server = socket(AF_INET, SOCK_STREAM, 0);
	setsockopt(server, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = INADDR_ANY;
	addr.sin_port = htons(PORT);

	bind(server, (struct sockaddr*)&addr, sizeof(addr));
	printf("Socket bound to port 8080 and is listening to incoming connection\n");
	listen(server, 5);//listen to incoming connection
	inc_socket = accept(server,(struct sockaddr*) &addr, (socklen_t*)&addrlen);
	printf("Socket connection received\n");
	send(inc_socket, msg, strlen(msg)+1, 0);
	while(1)
	{
//		listen(server, 5);//listen to incoming connection
//		inc_socket = accept(server,(struct sockaddr*) &addr, (socklen_t*)&addrlen);
		no_of_bytes = read(inc_socket, buff, 1024);
		printf("Message received: %s \n", buff);
		//printf("%ld\n", strlen(buff));
		if(strcmp(buff, "exit") == 0)
		{
			printf("Client Disconnected\n");
			break;
		}
		else if(strcmp(buff, "ping")==0)
		{
			printf("Pinged\n");
			send(inc_socket, ping, strlen(ping)+1, 0);	
			printf("Ping Reply Sent\n");
		}
		else if(strcmp(buff, "time")==0)
		{
			printf("Fetching time ..\n");
			time(&current_time);
			memcpy(time_, ctime(&current_time), strlen(ctime(&current_time))+1);
			printf("Sending information ... \n");
			send(inc_socket, time_, strlen(time_)+1, 0);	
			printf("Message Sent\n");
		}
		else if(strcmp(buff, "image")==0)
		{
			img = fopen("image.jpeg", "r");
			
			//computing the size of image to send
			fseek(img, 0, SEEK_END);
			size = ftell(img);
			fseek(img, 0, SEEK_SET);

			//sending the image size
			printf("Sending the image size \n");
			do
			{
				status = write(inc_socket, (void*)&size, sizeof(int));
			}while(status<0);
			
			while(!feof(img))
			{
				printf("Reading from the file\n");
				//reading from the file stream into buffer
				read_size = fread(image_buff, 1, sizeof(image_buff)-1, img);			
				printf("Writing to the socket stream\n");
				//sending buffer bytes through the socket
				do
				{
					status = write(inc_socket, image_buff, read_size);

				}while(status<0);
			
				bzero(image_buff, sizeof(image_buff));//clearing the buffer 
			}
			printf("Image Sent\n");
		}
		//send(inc_socket, msg, strlen(msg), 0);
		//printf("Message Sent \n");
       	}
	printf("Closing the server\n");	
	return 0;
}