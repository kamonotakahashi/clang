#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
int main(void) {

    struct sockaddr_in addr;
    struct sockaddr_in client;

    socklen_t len;

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(12345);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sock, (struct sockaddr *)&addr, sizeof(addr));

    listen(sock, 5);

    len = sizeof(client);
    int sock1 = accept(sock, (struct sockaddr *)&client, &len);

    write(sock1, "hello", 5);
    close(sock1);
    close(sock);

    return 0;
}
