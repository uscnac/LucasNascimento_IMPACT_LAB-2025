#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream image_Input;
    // Certifique-se de que o diretório existe. Caso contrário, crie-o
    image_Input.open("./images/Imagem.ppm");

    // Verifica se o arquivo foi aberto com sucesso
    if (image_Input.is_open()) {
        // Cabeçalho da imagem PPM
        image_Input << "P3" << endl;    // P3 significa que é uma imagem RGB em ASCII
        image_Input << "70 50" << endl;  // Tamanho da imagem: 70x50 pixels
        image_Input << "255" << endl;    // Valor máximo para cada cor (255)

        // Preenchendo a imagem com metade vermelha e metade azul
        for (int ImgH = 0; ImgH < 50; ImgH++) {  // 50 linhas
            if (ImgH < 25) {  // Primeiras 25 linhas - Vermelho
                for (int ImhV = 0; ImhV < 70; ImhV++) {  // 70 colunas
                    image_Input << "255 0 0 ";  // RGB para vermelho
                }
            } else {  // Últimas 25 linhas - Azul
                for (int ImhV = 0; ImhV < 70; ImhV++) {
                    image_Input << "0 0 255 ";  // RGB para azul
                }
            }
            image_Input << endl;  // Quebra de linha após cada linha de pixels
        }

        // Fechar o arquivo de imagem
        image_Input.close();
        cout << "Imagem criada com sucesso!" << endl;
    } else {
        cout << "Erro ao criar o arquivo da imagem." << endl;
    }

    return 0;
}
