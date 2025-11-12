#include <iostream>
#include <vector>
#include<memory>
#include"Midia.hpp"

class Playlist {
    private:
    std::string _nome;
    std::vector<std::shared_ptr<Midia>> _faixas;

    public:
    Playlist(std::string nome);
    void add(std::shared_ptr<Midia> faixa);
    void list() const;
    void play_all() const;
};