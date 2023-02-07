#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
int main()
{
    srand(time(0));
    int s_sock;
    char msg[256];
    s_sock = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server, other;
    server.sin_family = AF_INET;
    server.sin_port = htons(9001);
    server.sin_addr.s_addr = INADDR_ANY;
    socklen_t add;
    bind(s_sock, (struct sockaddr *)&server, sizeof(server));
    add = sizeof(other);
    recvfrom(s_sock, msg, sizeof(msg), 0, (struct sockaddr *)&other, &add);
    printf("server recieved:%s", msg);
    for (int i = 0; i < 4; i++)
    {
        int x = rand() % 10;
        msg[i] = x + '0';
    }
    msg[4] = '\0';
    sendto(s_sock, msg, sizeof(msg), 0, (struct sockaddr *)&other, sizeof(other));
    printf("server send:%s\n", msg);

    return 0;
}