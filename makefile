# Variáveis que armazenam diretórios da source, objetos e headers
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Compilador e flags de compilação
CC = gcc
CFLAGS = -Wall -Werror -g -I$(INC_DIR)	
# Ativa todos avisos, transforma-os em erros, gera informações para o debugger e inclui headers

# Arquivos fonte e objetos, cria uma lista iterando por todos os arquivos de cada pasta
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Nome do executável
TARGET = main

# Regras de compilação
all: $(TARGET)

# Compila todos os objetos para um arquivo executável
$(TARGET): $(OBJS)
	$(CC) $^ -o $@

# Compila cada arquivo de objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpa todos os .o dentro do diretório obj/
clean:
	rm -rf $(OBJ_DIR)/*.o

# Executa o executável
run: $(TARGET)
	./$(TARGET)