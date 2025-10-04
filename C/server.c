#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd, nuevo_sock;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(sockfd, 1);
    nuevo_sock = accept(sockfd, NULL, NULL);

    while (1) {
        read(nuevo_sock, buffer, sizeof(buffer));
        printf("Cliente: %s\n", buffer);
        printf("Servidor: ");
        fgets(buffer, sizeof(buffer), stdin);
        write(nuevo_sock, buffer, strlen(buffer));
    }

    close(nuevo_sock);
    close(sockfd);
    return 0;
}
