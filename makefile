# Variáveis que armazenam diretórios da source, objetos e headers
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include

# Compilador e flags de compilação
CC = gcc
CFLAGS = -Wall -Werror -g -I$(INC_DIR)	
# Ativa todos os avisos, transforma-os em erros, gera informações para o debugger e inclui headers

# Arquivos fonte e objetos, cria uma lista iterando por todos os arquivos de cada pasta
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Nome do executável
TARGET = $(BIN_DIR)/main

# Regras de compilação
all: directories $(TARGET)

# Compila todos os objetos para um arquivo executável
$(TARGET): $(OBJS)
	$(CC) $^ -o $@

# Compila cada arquivo de objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Cria diretórios obj/ e bin/ caso não existam
directories: $(OBJ_DIR) $(BIN_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Limpa todos os .o dentro do diretório obj/
clean:
	rm -rf $(OBJ_DIR)/*.o

# Executa o executável
run: $(TARGET)
	./$(TARGET)
