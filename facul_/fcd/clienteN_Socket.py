from socket import socket, AF_INET, SOCK_STREAM

# Número de números a serem enviados
N = 10

# Cria o socket TCP
client_socket = socket(AF_INET, SOCK_STREAM)

# Define o endereço do servidor
server_name = '127.0.0.1'
server_port = 12000

# Conecta ao servidor
client_socket.connect((server_name, server_port))

# Envia os N primeiros números naturais para o servidor
for i in range(N):
    client_socket.send(str(i).encode())

# Fecha o socket
client_socket.close()
