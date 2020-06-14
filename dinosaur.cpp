#include "dinosaur.hpp"
#include <string>
#include <iostream>

Dinosaur::Dinosaur()
{
    name = "Unknown";
    gender = "Unkown";
    era = "Unknown";
    type = "Unknown";
    species = "Unknown";
    food = "Unknown";
}

Dinosaur::Dinosaur(std::string name, std::string gender, std::string era, std::string type, std::string species)
{
    this->name = name;
    this->gender = gender;
    this->era = era;
    this->type = type;
    this->species = species;
    if (type == "Herbivore")
    {
        this->food = "Grass";
    }
    if (type == "Carnivore" || type == "Flying")
    {
        this->food = "Meat";
    }
    if (type == "Aquatic")
    {
        this->food = "Fish";
    }
}

Dinosaur::Dinosaur(const Dinosaur &other)
{
    name = other.name;
    gender = other.gender;
    era = other.era;
    type = other.type;
    species = other.species;
    food = other.food;
}

Dinosaur &Dinosaur::operator=(const Dinosaur &other)
{
    if (this != &other)
    {
        name = other.name;
        gender = other.gender;
        era = other.era;
        type = other.type;
        species = other.species;
        food = other.food;
    }
    return *this;
}

void Dinosaur::set_name(std::string name)
{
    this->name = name;
}

void Dinosaur::set_gender(std::string gender)
{
    this->gender = gender;
}

void Dinosaur::set_era(std::string era)
{
    this->era = era;
}

void Dinosaur::set_type(std::string type)
{
    this->type = type;
    if (type == "Herbivore")
    {
        this->food = "Grass";
    }
    if (type == "Carnivore" || type == "Flying")
    {
        this->food = "Meat";
    }
    if (type == "Aquatic")
    {
        this->food = "Fish";
    }
}

void Dinosaur::set_species(std::string species)
{
    this->species = species;
}

void Dinosaur::set_food(std::string food)
{
    this->food = food;
}

std::string Dinosaur::get_name() const
{
    return name;
}

std::string Dinosaur::get_gender() const
{
    return gender;
}

std::string Dinosaur::get_era() const
{
    return era;
}

std::string Dinosaur::get_type() const
{
    return type;
}

std::string Dinosaur::get_species() const
{
    return species;
}

std::string Dinosaur::get_food() const
{
    return food;
}

std::ostream &operator<<(std::ostream &out, const Dinosaur &dinosaur)
{
    out << "Name: " << dinosaur.name << std::endl
        << "Gender: " << dinosaur.gender << std::endl
        << "Era: " << dinosaur.era << std::endl
        << "Type: " << dinosaur.type << std::endl
        << "Species: " << dinosaur.species << std::endl
        << "Food: " << dinosaur.food << std::endl
        << std::endl;
    return out;
}
