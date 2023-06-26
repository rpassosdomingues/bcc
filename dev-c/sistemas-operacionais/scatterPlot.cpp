#include <opencv2/opencv.hpp>

int main()
{
    // Dados para o gráfico scatter
    std::vector<cv::Point2f> pontos;
    pontos.push_back(cv::Point2f(1.0f, 2.0f));
    pontos.push_back(cv::Point2f(3.0f, 4.0f));
    pontos.push_back(cv::Point2f(5.0f, 6.0f));
    pontos.push_back(cv::Point2f(7.0f, 8.0f));

    // Cria uma imagem para exibir o gráfico
    cv::Mat imagem(800, 800, CV_8UC3, cv::Scalar(255, 255, 255));

    // Desenha os pontos no gráfico
    for (const auto& ponto : pontos)
    {
        cv::Point2i posicao(static_cast<int>(ponto.x * 100), static_cast<int>(ponto.y * 100));
        cv::circle(imagem, posicao, 5, cv::Scalar(0, 0, 255), cv::FILLED);
    }

    // Exibe o gráfico
    cv::imshow("Gráfico Scatter", imagem);
    cv::waitKey(0);

    return 0;
}
