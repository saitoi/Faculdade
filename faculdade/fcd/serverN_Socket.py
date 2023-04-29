from socket import socket, AF_INET, SOCK_STREAM

# Cria o socket TCP
server_socket = socket(AF_INET, SOCK_STREAM)

# Liga o socket a uma porta específica
server_port = 12000
server_socket.bind(('', server_port))

# Torna o socket passivo e espera por conexões
server_socket.listen(1)

print("Aguardando conexão...")

# Aceita a conexão de um cliente
connection_socket, address = server_socket.accept()

print("Conexão estabelecida com o endereço", address)

# Recebe e imprime os números enviados pelo cliente
while True:
    number = connection_socket.recv(1024).decode()
    if not number:
        break
    print("Recebido:", number)

# Fecha a conexão com o cliente
connection_socket.close()

# Fecha o socket
server_socket.close()
