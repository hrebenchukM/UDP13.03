#pragma comment(lib, "Ws2_32.lib")
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;






int main()
{
    WSADATA wsadata;

    int res = WSAStartup(MAKEWORD(2, 2), &wsadata);
    if (res != NO_ERROR)
    {
        cout << "WSAStartup failked with error " << res << endl;
        return 1;
    }

    SOCKET udpSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (udpSocket == INVALID_SOCKET)
    {
        cout << "socket failed with error " << WSAGetLastError() << endl;
        return 2;
    }

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(23000);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr.s_addr);

    if (bind(udpSocket, (SOCKADDR*)&addr, sizeof(addr)) != NO_ERROR)
    {
        cout << "bind failed with error " << WSAGetLastError() << endl;
        return 3;
    }

    const size_t receiveBufSize = 1024;
    char receiveBuf[receiveBufSize];

    sockaddr_in senderAddr;
    int senderAddrSize = sizeof(senderAddr);

    cout << "Receiving data...." << endl;
    int bytesReceived = recvfrom(udpSocket, receiveBuf, receiveBufSize, 0, (SOCKADDR*)&senderAddr, &senderAddrSize);

    if (bytesReceived == SOCKET_ERROR)
    {
        cout << "recvfrom failed with error " << WSAGetLastError() << endl;
        return 4;
    }

    receiveBuf[bytesReceived] = '\0';











    /////////////////////////////////////////////////////TASK1+ TASK2
    string input(receiveBuf);
    string clientNick = input.substr(0, input.find(' '));
    input = input.substr(input.find(' ') + 1);

    
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    int clientColor = stoi(input.substr(0, input.find(' ')));
    string message = input.substr(input.find(' ') + 1);

    cout << "Server: ";
    SetConsoleTextAttribute(h, clientColor);
    cout << clientNick << " : ";
    SetConsoleTextAttribute(h, 7); 

    int startPos = 0;
    while (startPos < message.size()) {
        
        if (message[startPos] == '*') {
            int endPos = message.find(' ', startPos); // Найдем следующий пробел
            if (endPos == -1) {
                endPos = message.size(); // Если пробела нет, то слово заканчивается в конце строки
            }
            string starredWord = message.substr(startPos, endPos - startPos); // Выделяем слово начиная с *
            SetConsoleTextAttribute(h, 14); 
            cout << starredWord << " ";
            SetConsoleTextAttribute(h, clientColor); 
            startPos = endPos + 1; // Переходим к следующему слову после *
        }
        else {
          
            int endPos = message.find(' ', startPos); // Найдем следующий пробел
            if (endPos == -1) {
                endPos = message.size(); // Если пробела нет, то слово заканчивается в конце строки
            }
            string word = message.substr(startPos, endPos - startPos);
            SetConsoleTextAttribute(h, clientColor);
            cout << word << " ";
            startPos = endPos + 1; // Переходим к следующему слову
        }
    }
    SetConsoleTextAttribute(h, 7); 
     ///////////////////////////////////////////////////////////TASK1 + TASK2








    /* cout << "Received from " << senderAddr.sin_addr.s_host << endl;
     cout << "Data: " << receiveBuf << endl;


     const size_t sendBufSize = 1024;
     char sendBuf[sendBufSize] = "Hello from UDPExample";

     int sendResult = sendto(udpSocket, sendBuf, strlen(sendBuf), 0, (SOCKADDR*)&senderAddr, senderAddrSize);
     if (sendResult == SOCKET_ERROR)
     {
         cout << "sendto failed with error " << WSAGetLastError() << endl;
         return 4;
     }
     */

    closesocket(udpSocket);
    WSACleanup();
}



