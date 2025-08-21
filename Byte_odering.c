#include<stdio.h>
#include<winsock.h>
#include<windows.h>

int APIENTERY WinMain(HINSTANCE hinstance ,HINSTANCE hPrevvinstance, LPSTR lpCmdLine, int nCmdShow)
{
    WSADATA ws;
    char buff[1000],buf1[100],buf2[100],buf3[100],buf4[100],buf5[100],buf6[100];

    WSAStartup (0x0101, &ws);

    buf[0] = "";

    sprint(buf1,"\n winsock ver requested : %d.%d",HIBYTE(ws.wVersion),LOBYTE(ws.wVersion));
    sprint(buf2,"\n winsock ver requested : %d.%d",HIBYTE(ws.wVersion),LOBYTE(ws.wVersion));
    sprint(buf3,"\n Current Winsock Implementation : %s",&ws.szDescription);
    sprint(buf4,"\n System status : %s",&ws.szSystemStatus);
    sprint(buf5,"\n Maximum socket : %u",&ws.szMaxSocket);
    sprint(buf6,"\n Maximum message : %u",&ws.iMaxUdDg);
    stcat(stcat(stcat(stcat(stcat(stcat(buf,buf1),buf2),buf3),buf4),buf5),buf6);
    MessageBox(0,buf,"Info",0);
    WSACleanup();

    return 0;
}