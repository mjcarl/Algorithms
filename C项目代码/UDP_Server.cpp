#include "stdafx.h"  
#include <stdio.h>  
#include <winsock2.h>  

#pragma comment(lib, "ws2_32.lib")   
#define PORT 8848  //本机端口号 

//========================================================
//使用UDP数据包作为传输层协议，此程序为服务器端运行程序
//========================================================
int main(int argc, char* argv[])
{
	WSADATA wsaData;
	WORD sockVersion = MAKEWORD(2, 2);  //2.2是版本号
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}
	//domain指明所用的协议域，我们常用AF_INET（其实只是一个常数），代表IPv4协议，除此之外还有如代表IPv6的AF_INET6等等。
	//type则是连接类型，包括之前说的流（SOCKET_STREAM），数据包（SOCKET_DGRAM）以及一些其它方式。
	//protocol是协议，一般用0，让其自动与type匹配。
	SOCKET serSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);    //socket接口
	if (serSocket == INVALID_SOCKET)
	{
		printf("socket error !");
		return 0;
	}

	sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;  
	serAddr.sin_port = htons(PORT);   //大于1024的4位数作为端口号
	serAddr.sin_addr.S_un.S_addr = INADDR_ANY;//inet_addr("192.168.0.1");  // inet_addr()的功能是将一个点分十进制的IP转换成一个长整数型数（u_long类型）
	if (bind(serSocket, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)   //blind接口
	{
		printf("bind error !");
		closesocket(serSocket);
		return -1;
	}

	sockaddr_in remoteAddr;
	socklen_t nAddrLen = sizeof(remoteAddr);    //因为在64位结构中，size_t和int的长度是不一样的，所以定义了一个新的数据类型socklen_t
	printf("等待接收...\r\n");
	while (true)
	{
		char recvData[255];
		int ret = recvfrom(serSocket, recvData, 255, 0, (sockaddr *)&remoteAddr, &nAddrLen);
		if (ret > 0)
		{
			recvData[ret] = 0x00;		
			printf("\n接收到一个连接：%s  长度为：%d  内容为：\r\n", inet_ntoa(remoteAddr.sin_addr), ret);
			printf(recvData);			
		}
		char buf[255];
		printf("\n输入所回应答：(输入'q'退出系统) \r\n");
		scanf("%s",&buf);
		if(buf[0]=='q')
		{
			char a[]="服务器下线，终止服务！\n";
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