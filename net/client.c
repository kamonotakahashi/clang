#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

int main(void) {
    struct sockaddr_in server;
    int sock;
    char buf[32];

    int n;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(12345);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    int result;
    while(1) {
        result = connect(sock, (struct sockaddr *)&server, sizeof(server));
        if(result == 0) {
            memset(buf, 0, sizeof(buf));
            n = read(sock, buf, sizeof(buf));
            if(n > 0) {
                printf("%d %s", n, buf);
            }
        } else {
            break;
        }
    }
    close(sock);
    return 0;
}
