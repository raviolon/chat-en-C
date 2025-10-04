#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    while (1) {
        printf("Cliente: ");
        fgets(buffer, sizeof(buffer), stdin);
        write(sockfd, buffer, strlen(buffer));
        read(sockfd, buffer, sizeof(buffer));
        printf("Servidor: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}
