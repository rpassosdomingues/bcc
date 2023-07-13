#include <stdio.h>
#include <stdlib.h>

void converter_pgm_p5_para_p2(const char *nome_arquivo_entrada, const char *nome_arquivo_saida) {
    FILE *arquivo_entrada = fopen(nome_arquivo_entrada, "rb");
    if (arquivo_entrada == NULL) {
        printf("Erro: Não foi possível abrir o arquivo de entrada.\n");
        return;
    }

    // Ler o cabeçalho PGM
    char cabecalho[3];
    fgets(cabecalho, sizeof(cabecalho), arquivo_entrada);
    if (cabecalho[0] != 'P' || cabecalho[1] != '5') {
        printf("Erro: O formato do arquivo de entrada não é P5.\n");
        fclose(arquivo_entrada);
        return;
    }

    // Ignorar os comentários
    char linha[256];
    do {
        fgets(linha, sizeof(linha), arquivo_entrada);
    } while (linha[0] == '#');

    // Ler as dimensões da imagem
    int largura, altura;
    sscanf(linha, "%d %d", &largura, &altura);

    // Ler o valor máximo dos pixels
    int valor_maximo;
    fgets(linha, sizeof(linha), arquivo_entrada);
    sscanf(linha, "%d", &valor_maximo);

    // Abrir o arquivo de saída
    FILE *arquivo_saida = fopen(nome_arquivo_saida, "w");
    if (arquivo_saida == NULL) {
        printf("Erro: Não foi possível criar o arquivo de saída.\n");
        fclose(arquivo_entrada);
        return;
    }

    // Escrever o cabeçalho PGM
    fprintf(arquivo_saida, "P2\n");
    fprintf(arquivo_saida, "# Convertido de P5 para P2\n");
    fprintf(arquivo_saida, "%d %d\n", largura, altura);
    fprintf(arquivo_saida, "%d\n", valor_maximo);

    // Converter e escrever os dados dos pixels
    unsigned char *dados_pixels = (unsigned char*)malloc(largura * altura * sizeof(unsigned char));
    fread(dados_pixels, sizeof(unsigned char), largura * altura, arquivo_entrada);

    for (int i = 0; i < largura * altura; i++) {
        fprintf(arquivo_saida, "%d ", dados_pixels[i]);
    }

    free(dados_pixels);

    // Fechar os arquivos
    fclose(arquivo_entrada);
    fclose(arquivo_saida);

    printf("Conversão concluída.\n");
}

// Exemplo de uso
int main() {
    converter_pgm_p5_para_p2("image_p5.pgm", "image_p2.pgm");
    return 0;
}
