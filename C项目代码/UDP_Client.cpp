#include "stdafx.h"  
#include <stdio.h>  
#include <winsock2.h>  

#pragma comment(lib, "ws2_32.lib")   
#define PORT 8848  //端口号 
//========================================================
//使用UDP数据包作为传输层协议，此程序为客户端运行程序
//========================================================
int main(int argc, char* argv[])
{
	WORD socketVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(socketVersion, &wsaData) != 0)
	{
		return 0;
	}
	SOCKET sclient = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORT);
	sin.sin_addr.S_un.S_addr = inet_addr("10.170.57.68");  //目的IP
	int len = sizeof(sin);

	while (true)
	{
		printf("\n请输入UDP数据报文：(输入'q'退出)\n");
		char buf[255];
		scanf("%s", &buf);
		if (buf[0] == 'q'&&strlen(buf) == 1)
		{
			char a[100] = "客户端下线，断开连接！\n";
			sendto(sclient, a, strlen(a), 0, (struct sockaddr*)&sin, len);
			break;
		}
		else
		{
			sendto(sclient, buf, strlen(buf), 0, (struct sockaddr*)&sin, len);

			char recvData[255];
			while (true)
			{
				int ret = recvfrom(sclient, recvData, 255, 0, (sockaddr *)&sin, &len);
				if (ret > 0)
				{
					recvData[ret] = 0x00;
					printf("\n收到来自服务器的应答！\n");
					printf(recvData);
					break;
				}
			}
		}	
	}
	
	closesocket(sclient);
	WSACleanup();
	return 0;
}