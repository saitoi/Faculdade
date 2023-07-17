from socket import socket, AF_INET, SOCK_DGRAM

#Cria o socket UDP
server_socket = socket(AF_INET, SOCK_DGRAM)

#Liga o socket a uma porta específica
server_port = 12000
server_socket.bind(('', server_port))

print("Aguardando por dados...")

#Recebe e imprime os números enviados pelo cliente
while True:
    number, address = server_socket.recvfrom(1024)
    if not number:
        break
    print("Recebido de {}: {}".format(address, number.decode()))

#Fecha o socket
server_socket.close()