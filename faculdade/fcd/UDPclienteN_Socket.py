from socket import socket, AF_INET, SOCK_DGRAM

#Número de números a serem enviados
N = 10

#Cria o socket UDP
client_socket = socket(AF_INET, SOCK_DGRAM)

#Define o endereço do servidor
server_name = '127.0.0.1'
server_port = 12000

#Envia os N primeiros números naturais para o servidor
for i in range(N):
    client_socket.sendto(str(i).encode(), (server_name, server_port))

#Fecha o socket
client_socket.close()

