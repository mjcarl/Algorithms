#include "stdafx.h"  
#include <stdio.h>  
#include <winsock2.h>  

#pragma comment(lib, "ws2_32.lib")   
#define PORT 8848  //�����˿ں� 

//========================================================
//ʹ��UDP���ݰ���Ϊ�����Э�飬�˳���Ϊ�����������г���
//========================================================
int main(int argc, char* argv[])
{
	WSADATA wsaData;
	WORD sockVersion = MAKEWORD(2, 2);  //2.2�ǰ汾��
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}
	//domainָ�����õ�Э�������ǳ���AF_INET����ʵֻ��һ��������������IPv4Э�飬����֮�⻹�������IPv6��AF_INET6�ȵȡ�
	//type�����������ͣ�����֮ǰ˵������SOCKET_STREAM�������ݰ���SOCKET_DGRAM���Լ�һЩ������ʽ��
	//protocol��Э�飬һ����0�������Զ���typeƥ�䡣
	SOCKET serSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);    //socket�ӿ�
	if (serSocket == INVALID_SOCKET)
	{
		printf("socket error !");
		return 0;
	}

	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;  
	serAddr.sin_port = htons(PORT);   //����1024��4λ����Ϊ�˿ں�
	serAddr.sin_addr.S_un.S_addr = INADDR_ANY;//inet_addr("192.168.0.1");  // inet_addr()�Ĺ����ǽ�һ�����ʮ���Ƶ�IPת����һ��������������u_long���ͣ�
	if (bind(serSocket, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)   //blind�ӿ�
	{
		printf("bind error !");
		closesocket(serSocket);
		return -1;
	}

	sockaddr_in remoteAddr;
	socklen_t nAddrLen = sizeof(remoteAddr);    //��Ϊ��64λ�ṹ�У�size_t��int�ĳ����ǲ�һ���ģ����Զ�����һ���µ���������socklen_t
	printf("�ȴ�����...\r\n");
	while (true)
	{
		char recvData[255];
		int ret = recvfrom(serSocket, recvData, 255, 0, (sockaddr *)&remoteAddr, &nAddrLen);
		if (ret > 0)
		{
			recvData[ret] = 0x00;		
			printf("\n���յ�һ�����ӣ�%s  ����Ϊ��%d  ����Ϊ��\r\n", inet_ntoa(remoteAddr.sin_addr), ret);
			printf(recvData);			
		}
		char buf[255];
		printf("\n��������Ӧ��(����'q'�˳�ϵͳ) \r\n");
		scanf("%s",&buf);
		if(buf[0]=='q')
		{
			char a[]="���������ߣ���ֹ����\n";
			sendto(serSocket, a, strlen(a), 0, (sockaddr *)&remoteAddr, nAddrLen);
			break;
		}
		else
			sendto(serSocket, buf, strlen(buf), 0, (sockaddr *)&remoteAddr, nAddrLen);

	}
	closesocket(serSocket);
	WSACleanup();
	return 0;
}

//void main()
//{
//	printf("%zu", sizeof(char*));   //4
//}