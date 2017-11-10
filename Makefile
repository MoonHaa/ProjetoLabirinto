#main compiler
CC := gcc

#diretorios
PRT1 := Parte1
PRT2 := Parte2

#flags de compilação #-Ox define nivel de otimização (0-3)
CFLAGS := -std=c11 -g -O3 -Wno-unused-result

#define os targets
all: ComponenteConexo Labirinto

#target componente conexo
ComponenteConexo:
	$(CC) $(CFLAGS) $(PRT1)/Fila.c $(PRT1)/Imagem.c $(PRT1)/ComponenteConexo.c -o $(PRT1)/ComponenteConexo
	
#target Labirinto
Labirinto:
	$(CC) $(CFLAGS) $(PRT2)/Pilha.c $(PRT2)/ArquivoLabirinto.c $(PRT2)/Labirinto.c -o $(PRT2)/Labirinto
	
#limpar os arquivos compilados
clean:
	$(RM) -rf $(PRT1)/ComponenteConexo $(PRT2)/Labirinto
	
.PHONY: clean Labirinto ComponenteConexo
