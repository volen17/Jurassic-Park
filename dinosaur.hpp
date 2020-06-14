#include <string>

#pragma once

class Dinosaur
{
public:
    Dinosaur();
    Dinosaur(std::string, std::string, std::string, std::string, std::string);
    Dinosaur(const Dinosaur &);
    Dinosaur &operator=(const Dinosaur &);

    void set_name(std::string);
    void set_gender(std::string);
    void set_era(std::string);
    void set_type(std::string);
    void set_species(std::string);
    void set_food(std::string);

    std::string get_name() const;
    std::string get_gender() const;
    std::string get_era() const;
    std::string get_type() const;
    std::string get_species() const;
    std::string get_food() const;

    friend std::ostream &operator<<(std::ostream &, const Dinosaur &);

private:
    std::string name;
    std::string gender;
    std::string era;
    std::string type;
    std::string species;
    std::string food;
};