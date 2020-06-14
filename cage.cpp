#include "cage.hpp"
#include <cstdlib>
#include <iostream>

Cage::Cage()
{
    short rCapacity = (short)rand() % 3;
    short rClimate = (short)rand() % 3;
    switch (rCapacity)
    {
    case 0:
        capacity = 3;
        size = "medium";
        break;
    case 1:
        capacity = 10;
        size = "big";
        break;
    default:
        capacity = 1;
        size = "small";
    }
    switch (rClimate)
    {
    case 0:
        climate = "Land";
        type = "Unknown";
        break;
    case 1:
        type = "Flying";
        climate = "Aerial";
        break;
    default:
        climate = "Hydro";
        type = "Aquatic";
    }
    era = "Unkown";
}

Cage::Cage(std::string size, std::string climate)
{
    this->size = size;
    this->climate = climate;
    this->era = "Unknown";
    if (size == "small")
    {
        this->capacity = 1;
    }
    if (size == "medium")
    {
        this->capacity = 3;
    }
    if (size == "big")
    {
        this->capacity = 10;
    }
    if (climate == "Land")
    {
        this->type = "Unknown";
    }
    if (climate == "Aerial")
    {
        this->type = "Flying";
    }
    if (climate == "Hydro")
    {
        this->type = "Aquatic";
    }
}

Cage::Cage(std::string size, std::string era, std::string type)
{
    this->size = size;
    if (size == "small")
    {
        this->capacity = 1;
    }
    if (size == "medium")
    {
        this->capacity = 3;
    }
    if (size == "big")
    {
        this->capacity = 10;
    }
    this->era = era;
    this->type = type;
    if (type == "Herbivore")
    {
        this->climate = "Land";
    }
    if (type == "Carnivore")
    {
        this->climate = "Land";
    }
    if (type == "Flying")
    {
        this->climate = "Aerial";
    }
    if (type == "Aquatic")
    {
        this->climate = "Hydro";
    }
}

void Cage::set_capacity(short capacity)
{
    this->capacity = capacity;
    if (capacity == 1)
    {
        this->size = "small";
    }
    if (capacity == 3)
    {
        this->size = "medium";
    }
    if (capacity == 10)
    {
        this->size = "big";
    }
}

void Cage::set_size(std::string size)
{
    this->size = size;
    if (size == "small")
    {
        this->capacity = 1;
    }
    if (size == "medium")
    {
        this->capacity = 3;
    }
    if (size == "big")
    {
        this->capacity = 10;
    }
}

void Cage::set_climate(std::string climate)
{
    this->climate = climate;
}

void Cage::set_era(std::string era)
{
    this->era = era;
}

void Cage::set_type(std::string type)
{
    this->type = type;
}

void Cage::set_dinosaurs(std::vector<Dinosaur> dinosaurs)
{
    this->dinosaurs = dinosaurs;
}

short Cage::get_capacity() const
{
    return capacity;
}

std::string Cage::get_size() const
{
    return size;
}

std::string Cage::get_climate() const
{
    return climate;
}

std::string Cage::get_era() const
{
    return era;
}

std::string Cage::get_type() const
{
    return type;
}

std::vector<Dinosaur> Cage::get_dinosaurs() const
{
    return dinosaurs;
}

void Cage::addDinosaur(Dinosaur dinosaur)
{
    dinosaurs.push_back(dinosaur);
}

void Cage::removeDinosaur(int position)
{
    dinosaurs.erase(dinosaurs.begin() + position);
}

bool Cage::isFull()
{
    if (dinosaurs.size() <= capacity)
    {
        return false;
    }
    return true;
}

std::ostream &operator<<(std::ostream &out, const Cage &cage)
{
    out << "Size: " << cage.size << std::endl
        << "Climate: " << cage.climate << std::endl
        << "Number of dinosaurs inside: " << cage.dinosaurs.size() << std::endl;
    if (cage.dinosaurs.size() == 0)
    {
        out << std::endl;
    }
    else
    {
        out << "   Dinosaurs inside: " << std::endl;
        for (int i = 0; i < cage.dinosaurs.size(); i++)
        {
            out << cage.dinosaurs[i];
        }
    }
    return out;
}
