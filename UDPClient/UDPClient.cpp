#pragma comment(lib, "Ws2_32.lib")
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <iostream>
#include <string>
using namespace std;



///////////////////////////////////////////TASK2
void searchForbiddenWords(string& message) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 14); // Желтый цвет

    string forbiddenWords[4] = { "end", "start", "error" ,"hello" };

    for (int i = 0; i < 4; i++) {
        int pos = message.find(forbiddenWords[i]);
        while (pos != -1) {
            message.replace(pos, forbiddenWords[i].length(), string(forbiddenWords[i].length(), '*'));
            pos = message.find(forbiddenWords[i], pos + 1);
        }
    }

    SetConsoleTextAttribute(h, 7); // Возвращение стандартного цвета
}
////////////////////////////////////////////TASK2






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

    sockaddr_in addrTo;
    addrTo.sin_family = AF_INET;
    addrTo.sin_port = htons(23000);
    inet_pton(AF_INET, "127.0.0.1", &addrTo.sin_addr.s_addr);

    const size_t sendBufSize = 1024;
   // char sendBuf[sendBufSize] = "Hello from UDPClient";
    char sendBuf[sendBufSize];








    /////////////////////////////////////////////////////////TASK1
    string message;
    string clientNick;
    string input;
    int clientColor;

    cout << "Enter your nickname, color (number between 1 and 15), and message : ";
    getline(cin, input);


    clientNick = input.substr(0, input.find(' '));//получаем ник до первого пробела
    input = input.substr(input.find(' ') + 1);//обрезаем строку удаляя ник и получаем номер цвета и сообщение

    clientColor = stoi(input.substr(0, input.find(' ')));//выделяем номер с подстроки и преобразовываем в целое число
    message = input.substr(input.find(' ') + 1);//получаем сообщение из оставшейся части


    searchForbiddenWords(message);
  
    string fullMessage = clientNick + " " + to_string(clientColor) + " " + message;

    strcpy_s(sendBuf, fullMessage.c_str());
    //////////////////////////////////////////////////////////TASK1









   // cout << "Sending data...." << endl;
    int sendResult = sendto(udpSocket, sendBuf, strlen(sendBuf), 0, (SOCKADDR*)&addrTo, sizeof(addrTo));
    if (sendResult == SOCKET_ERROR)
    {
        cout << "sendto failed with error " << WSAGetLastError() << endl;
        return 4;
    }

    const size_t receiveBufSize = 1024;
    char receiveBuf[receiveBufSize];

    sockaddr_in addrFrom;
    int addrFromSize = sizeof(addrFrom);

    cout << "Receiving data...." << endl;
    int bytesReceived = recvfrom(udpSocket, receiveBuf, receiveBufSize, 0, (SOCKADDR*)&addrFrom, &addrFromSize);

    if (bytesReceived == SOCKET_ERROR)
    {
        cout << "recvfrom failed with error " << WSAGetLastError() << endl;
        return 4;
    }

    receiveBuf[bytesReceived] = '\0';
    cout << "Received from " << addrFrom.sin_addr.s_host << endl;
    cout << "Data: " << receiveBuf << endl;

    closesocket(udpSocket);
    WSACleanup();
}

