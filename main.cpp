#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <memory>

#include "Midia.hpp"
#include "Musica.hpp"
#include "Podcast.hpp"
#include "Catalogo.hpp"
#include "Playlist.hpp"
#include "avaliacao_basica_streaming.hpp"

int main() {
    Catalogo catalogo;
    std::map<std::string, Playlist> playlists; 
    std::string linha;
    while (true) {
        std::getline(std::cin, linha);
        if (linha.empty()) continue;
        std::istringstream iss(linha);
        std::string cmd;
        iss >> cmd;
        if (cmd == "quit") {
            break;
        }
        else if (cmd == "add_musica") {
            std::string titulo, artista, genero;
            int duracao;
            iss >> titulo >> duracao >> artista >> genero;
            catalogo.add_musica(titulo, duracao, artista, genero);
        }
        else if (cmd == "add_podcast") {
            std::string titulo, host;
            int duracao, episodio;
            iss >> titulo >> duracao >> host >> episodio;
            catalogo.add_podcast(titulo, duracao, host, episodio);
        }
        else if (cmd == "list_all") {
            catalogo.list_all();
        }
        else if (cmd == "pl_new") {
            std::string nome;
            iss >> nome;
            playlists[nome] = Playlist(nome);
            std::cout << "OK: playlist " << nome << " criada" << std::endl;
        }
        else if (cmd == "pl_add") {
            std::string nome, titulo;
            iss >> nome >> titulo;
            if (playlists.find(nome) == playlists.end()) {
                playlists[nome] = Playlist(nome);
                std::cout << "OK: playlist " << nome << " criada" << std::endl;
            }
            auto midia = catalogo.get(titulo);
            if (midia == nullptr) {
                std::cout << "Erro: midia " << titulo << " inexistente" << std::endl;
            } else {
                playlists[nome].add(midia);
            }
        }
        else if (cmd == "pl_list") {
            std::string nome;
            iss >> nome;
            if (playlists.find(nome) == playlists.end()) {
                std::cout << "Info: (vazio)" << std::endl;
            } else {
                playlists[nome].list();
            }
        }
        else if (cmd == "pl_play") {
            std::string nome;
            iss >> nome;
            if (playlists.find(nome) == playlists.end()) {
                std::cout << "Info: (vazio)" << std::endl;
            } else {
                playlists[nome].play_all();
            }
        }
        else if (cmd == "play") {
            std::string titulo;
            iss >> titulo;
            auto midia = catalogo.get(titulo);
            if (midia == nullptr) {
                std::cout << "Erro: midia " << titulo << " inexistente" << std::endl;
            } else {
                midia->play();
            }
        }
        else if (cmd == "b") {
            avaliacao_basica();
        }
        else {
            std::cout << "Comando desconhecido: " << cmd << std::endl;
        }
    }
    return 0;
}