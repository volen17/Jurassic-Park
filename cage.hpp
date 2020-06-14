#include "dinosaur.hpp"
#include <vector>
#pragma once

class Cage
{
public:
    Cage();
    Cage(std::string, std::string);
    Cage(std::string, std::string, std::string);

    void set_capacity(short);
    void set_size(std::string);
    void set_climate(std::string);
    void set_era(std::string);
    void set_type(std::string);
    void set_dinosaurs(std::vector<Dinosaur>);

    short get_capacity() const;
    std::string get_size() const;
    std::string get_climate() const;
    std::string get_era() const;
    std::string get_type() const;
    std::vector<Dinosaur> get_dinosaurs() const;

    friend std::ostream &operator<<(std::ostream &, const Cage &);

    void addDinosaur(Dinosaur);
    void removeDinosaur(int);
    bool isFull();

private:
    short capacity = 1;
    std::string size = "Unknown";
    std::string climate = "Unknown";
    std::string era = "Unknown";
    std::string type = "Unknown";
    std::vector<Dinosaur> dinosaurs;
};