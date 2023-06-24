#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

constexpr int N = 10;  // número máximo de porções de missionário cozido no caldeirão
int porcoes = N;  // variável compartilhada para controlar o número de porções no caldeirão
std::mutex mtx;  // mutex para controlar o acesso ao caldeirão
std::condition_variable empty_pot;  // variável de condição para indicar que o caldeirão está vazio
std::condition_variable full_pot;  // variável de condição para indicar que o caldeirão está cheio
bool parar = false;  // variável de controle para parar a execução dos canibais

void canibal(int id)
{
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);  // obtém o acesso exclusivo ao caldeirão
        if (porcoes > 0) {
            --porcoes;  // serve-se no caldeirão
            std::cout << "Canibal " << id << " se servindo do caldeirão. Porções restantes: " << porcoes << std::endl;
            lock.unlock();  // libera o acesso ao caldeirão

            // comer a porção de missionário
            std::cout << "Canibal " << id << " comendo." << std::endl;

            lock.lock();  // obtém o acesso exclusivo ao caldeirão
            ++porcoes;  // coloca o prato vazio de volta no caldeirão
            std::cout << "Canibal " << id << " devolvendo prato vazio ao caldeirão. Porções restantes: " << porcoes << std::endl;
            if (porcoes == 1) {
                empty_pot.notify_one();  // acorda o cozinheiro para encher o caldeirão
            }
            lock.unlock();  // libera o acesso ao caldeirão
        }
        else {
            if (parar) {
                break;  // para a execução do canibal
            }
        }
    }
}

void cozinheiro()
{
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);  // obtém o acesso exclusivo ao caldeirão
        empty_pot.wait(lock, [] { return porcoes == 0 || parar; });  // aguarda o caldeirão estar vazio ou parar a execução
        if (parar) {
            break;  // para a execução do cozinheiro
        }
        std::cout << "Cozinheiro enchendo o caldeirão." << std::endl;
        porcoes = N;  // enche o caldeirão com N porções de missionário cozido
        full_pot.notify_all();  // indica que o caldeirão está cheio
        lock.unlock();  // libera o acesso ao caldeirão
        // dormir ou realizar outra atividade qualquer
    }
}

int main()
{
    const int num_canibais = 5;  // substitua 5 pelo número desejado de canibais
    std::thread canibal_threads[num_canibais];
    for (int i = 0; i < num_canibais; ++i) {
        canibal_threads[i] = std::thread(canibal, i + 1);
    }

    std::thread cozinheiro_thread(cozinheiro);

    // Aguarde algum tempo antes de parar a execução
    std::this_thread::sleep_for(std::chrono::seconds(5));
    parar = true;  // define a variável de controle para parar a execução dos canibais e cozinheiro

    for (int i = 0; i < num_canibais; ++i) {
        canibal_threads[i].join();
    }
    cozinheiro_thread.join();

    return 0;
}
