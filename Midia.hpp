#ifndef MIDIA_HPP
#define MIDIA_HPP

#include <iostream>
#include <string>

class Midia {
    protected:
    std::string _titulo;
    int _duracao_s;

    public:
    Midia(std::string titulo, int duracao_s);
    
    virtual ~Midia() = default;
    virtual void print_info() const;
    virtual void play() const = 0;
    virtual std::string tipo() const;
    std::string get_titulo() const;
    friend std::ostream& operator<<(std::ostream& os, const Midia& m);
};

#endif