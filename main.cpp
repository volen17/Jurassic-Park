#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <iterator>
#include "dinosaur.hpp"
#include "cage.hpp"

const std::string zoo = "jurassicPark.txt";
std::pair<const std::string, double> grass("Grass", 0.0);
std::pair<const std::string, double> meat("Meat", 0.0);
std::pair<const std::string, double> fish("Fish", 0.0);
std::vector<Cage> cages;

std::string toValidInputFormat(std::string s)
{
    if (s[0] >= 'a' && s[0] <= 'z')
    {
        s[0] -= ('z' - 'Z');
    }
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += ('z' - 'Z');
        }
    }
    return s;
}

bool isValidGender(std::string gender)
{
    if (toValidInputFormat(gender) == "Male" || toValidInputFormat(gender) == "Female")
    {
        return true;
    }
    return false;
}

bool isValidEra(std::string era)
{
    if (toValidInputFormat(era) == "Triassic" || toValidInputFormat(era) == "Cretaceous" || toValidInputFormat(era) == "Jurassic")
    {
        return true;
    }
    return false;
}

bool isValidType(std::string type)
{
    if (toValidInputFormat(type) == "Herbivore" || toValidInputFormat(type) == "Carnivore" || toValidInputFormat(type) == "Flying" || toValidInputFormat(type) == "Aquatic")
    {
        return true;
    }
    return false;
}

bool isValidClimate(std::string climate)
{
    if (toValidInputFormat(climate) == "Land" || toValidInputFormat(climate) == "Aerial" || toValidInputFormat(climate) == "Hydro")
    {
        return true;
    }
    return false;
}

bool isValidFood(std::string food)
{
    if (toValidInputFormat(food) == "Grass" || toValidInputFormat(food) == "Meat" || toValidInputFormat(food) == "Fish")
    {
        return true;
    }
    return false;
}

bool isEmpty()
{
    for (int i = 0; i < cages.size(); i++)
    {
        if (cages[i].get_dinosaurs().size() != 0)
        {
            return false;
        }
    }
    return true;
}

void printInstructions()
{
    std::cout << std::endl
              << "Firstly, here's a little bit of information:" << std::endl
              << std::endl
              << "Available dinosaur specifications:" << std::endl
              << " > Type     -   Herbivore / Carnivore / Flying / Aquatic" << std::endl
              << " > Era      -   Triassic / Cretaceous / Jurassic" << std::endl
              << " > Climate  -   Land / Aerial / Hydro" << std::endl
              << " > Food     -   Grass / Meat / Fish" << std::endl
              << std::endl
              << "Available cage sizes:" << std::endl
              << " > small    -   1 dinosaur" << std::endl
              << " > medium   -   up to 3 dinosaurs" << std::endl
              << " > big      -   up to 10 dinosaurs" << std::endl
              << std::endl
              << "Available zoo operations:" << std::endl
              << " > add      -   adds new dinosaur to the park" << std::endl
              << " > build    -   builds new cage" << std::endl
              << " > remove   -   removes dinosaur" << std::endl
              << " > food     -   fills the storage with food" << std::endl
              << " > print    -   prints the cages and the dinosaurs inside" << std::endl
              << " > exit     -   saves the information and exits the program" << std::endl
              << std::endl;
}

void foodConsume(Dinosaur d, double consumption)
{
    if (d.get_food() == grass.first)
    {
        grass.second = grass.second - consumption;
    }
    if (d.get_food() == meat.first)
    {
        meat.second = meat.second - consumption;
    }
    if (d.get_food() == fish.first)
    {
        fish.second = fish.second - consumption;
    }
}

bool addDinosaur(Dinosaur d, double consumption)
{
    for (int i = 0; i < cages.size(); i++)
    {
        if (cages[i].get_era() == d.get_era() && cages[i].get_type() == d.get_type() && !cages[i].isFull())
        {
            cages[i].addDinosaur(d);
            foodConsume(d, consumption);
            return true;
        }
        if (cages[i].get_era() == d.get_era() && cages[i].get_type() == "Unknown" && (d.get_type() == "Harbivore" || d.get_type() == "Carnivore"))
        {
            cages[i].addDinosaur(d);
            foodConsume(d, consumption);
            cages[i].set_type(d.get_type());
            return true;
        }
        if (cages[i].get_era() == "Unknown" && cages[i].get_type() == d.get_type() && !cages[i].isFull())
        {
            cages[i].addDinosaur(d);
            foodConsume(d, consumption);
            cages[i].set_era(d.get_era());
            return true;
        }
        if (cages[i].get_era() == "Unknown" && cages[i].get_type() == "Unknown" && (d.get_type() == "Harbivore" || d.get_type() == "Carnivore"))
        {
            cages[i].addDinosaur(d);
            foodConsume(d, consumption);
            cages[i].set_type(d.get_type());
            cages[i].set_era(d.get_era());
            return true;
        }
    }
    return false;
}

double randDouble(double min, double max)
{
    double random = (double)rand() / RAND_MAX;
    return min + random * (max - min);
}

void loadPark()
{
    std::ifstream in(zoo);
    std::string line;
    if (in.good())
    {
        getline(in, line); // number of cages
        int countCages = std::stoi(line.substr(17));
        //
        getline(in, line); // grass
        grass.second = std::stoi(line.substr(7));
        //
        getline(in, line); // meat
        meat.second = std::stoi(line.substr(6));
        //
        getline(in, line); // fish
        fish.second = std::stoi(line.substr(6));
        //
        getline(in, line); // new line
        //
        for (int i = 0; i < countCages; i++)
        {
            Cage c;
            int countDinosaurs;
            //
            getline(in, line); // size
            c.set_size(line.substr(6));
            //
            getline(in, line); // climate
            c.set_climate(line.substr(9));
            //
            getline(in, line); // number of dinosaurs
            countDinosaurs = std::stoi(line.substr(28));
            //
            if (countDinosaurs == 0)
            {
                getline(in, line); // new line
                cages.push_back(c);
                continue;
            }
            else
            {
                getline(in, line); // dinosaurs:
                for (short i = 0; i < countDinosaurs; i++)
                {
                    Dinosaur d;
                    getline(in, line); // name
                    d.set_name(line.substr(6));
                    //
                    getline(in, line); // gender
                    d.set_gender(line.substr(8));
                    //
                    getline(in, line); // era
                    d.set_era(line.substr(5));
                    //
                    getline(in, line); // type
                    d.set_type(line.substr(6));
                    //
                    getline(in, line); // species
                    d.set_species(line.substr(9));
                    //
                    getline(in, line); // food
                    d.set_food(line.substr(6));
                    //
                    getline(in, line); // new line
                    //
                    c.addDinosaur(d);
                }
            }
            cages.push_back(c);
        }
        grass.second = randDouble(0.0, grass.second);
        meat.second = randDouble(0.0, meat.second);
        fish.second = randDouble(0.0, fish.second);
        in.close();
    }
    else
    {
        for (short i = 0; i < (short)rand() % 10; i++)
        {
            cages.push_back(Cage());
        }
        grass.second = randDouble(100.0, 200.0);
        meat.second = randDouble(100.0, 200.0);
        fish.second = randDouble(100.0, 200.0);
    }
}

void parkSystem()
{
    printInstructions();
    loadPark();
    while (true)
    {
        std::string command;
        std::cout << "Command:" << std::endl;
        std::cin >> command;
        if (command == "add")
        {
            std::string s;
            if (cages.size() == 0)
            {
                std::cout << std::endl
                          << "There aren't any cages in the zoo!" << std::endl
                          << "Are you sure you want to continue with adding dinosaur? (yes/no)" << std::endl;
                do
                {
                    std::cin >> s;
                } while (!(s == "yes" || s == "no"));
                if (s == "no")
                {
                    std::cout << std::endl;
                    continue;
                }
            }
            Dinosaur d;
            //
            std::cout << std::endl
                      << "   Add" << std::endl;
            //
            std::cout << std::endl
                      << "Name:" << std::endl;
            std::cin >> s;
            d.set_name(s);
            //
            std::cout << std::endl
                      << "Gender: (male/female)" << std::endl;
            do
            {
                std::cin >> s;

            } while (!isValidGender(s));
            d.set_gender(toValidInputFormat(s));
            //
            std::cout << std::endl
                      << "Era: (Triassic / Cretaceous / Jurassic)" << std::endl;
            do
            {
                std::cin >> s;

            } while (!isValidEra(s));
            d.set_era(toValidInputFormat(s));
            //
            std::cout << std::endl
                      << "Type: (Herbivore / Carnivore / Flying / Aquatic)" << std::endl;
            do
            {
                std::cin >> s;

            } while (!isValidType(s));
            d.set_type(toValidInputFormat(s));
            //
            std::cout << std::endl
                      << "Species: (Plesiosaurus, Brontosaurus, Tyrannosaurus, etc...)" << std::endl;
            std::cin >> s;
            d.set_species(toValidInputFormat(s));
            //
            double consumption = randDouble(30.0, 50.0);
            if (((d.get_food() == grass.first) && (consumption > grass.second)) || ((d.get_food() == meat.first) && (consumption > meat.second)) || ((d.get_food() == fish.first) && (consumption > fish.second)))
            {
                std::cout << std::endl
                          << "There is not enough food to feed this dinosaur, you've got to add more food first!" << std::endl
                          << std::endl;
                continue;
            }
            //
            if (!addDinosaur(d, consumption))
            {
                std::cout << std::endl
                          << "There is not a suitable cage for this dinosaur" << std::endl
                          << "Do you want to build one? (yes/no)" << std::endl;
                do
                {
                    std::cin >> s;
                } while (!(s == "yes" || s == "no"));
                if (s == "no")
                {
                    std::cout << std::endl;
                    continue;
                }
                std::cout << std::endl
                          << "Cage size:    (  small  /   medium   /   big    )" << std::endl
                          << "                 for 1     up to 3     up to 10  " << std::endl;
                do
                {
                    std::cin >> s;
                } while (!(s == "small" || s == "medium" || s == "big"));
                cages.push_back(Cage(s, d.get_era(), d.get_type()));
                std::cout << std::endl
                          << "Successfully built cage!" << std::endl;
                cages.back().addDinosaur(d);
                foodConsume(d, consumption);
            }
            std::cout << std::endl
                      << "The dinosaur is successfully added!" << std::endl
                      << std::endl;
            continue;
        }
        if (command == "build")
        {
            std::string size;
            std::string climate;
            std::cout << std::endl
                      << "   Build cage" << std::endl
                      << std::endl
                      << "Cage size:    (  small  /   medium   /   big    )" << std::endl
                      << "                 for 1     up to 3     up to 10  " << std::endl;
            do
            {
                std::cin >> size;
            } while (!(size == "small" || size == "medium" || size == "big"));
            //
            std::cout << std::endl
                      << "Climate: (Land / Aerial / Hydro)" << std::endl;
            do
            {
                std::cin >> climate;

            } while (!isValidClimate(climate));
            //
            cages.push_back(Cage(size, toValidInputFormat(climate)));
            std::cout << std::endl
                      << "Successfully built cage!" << std::endl
                      << std::endl;
            continue;
        }
        if (command == "remove")
        {
            if (isEmpty())
            {
                std::cout << std::endl
                          << "There aren't any dinosaurs in the zoo!" << std::endl
                          << std::endl;
                continue;
            }
            bool notFind = true;
            std::string name;
            std::cout << std::endl
                      << "   Remove" << std::endl
                      << std::endl
                      << "Name:" << std::endl;
            std::cin >> name;
            std::cout << std::endl
                      << "Removed:" << std::endl
                      << std::endl;
            for (int i = 0; i < cages.size(); i++)
            {
                for (int j = 0; j < cages[i].get_dinosaurs().size(); j++)
                {
                    if (cages[i].get_dinosaurs()[j].get_name() == name)
                    {
                        std::cout << cages[i].get_dinosaurs()[j] << std::endl;
                        cages[i].removeDinosaur(j);
                        notFind = false;
                    }
                }
            }
            if (notFind)
            {
                std::cout << std::endl
                          << "No dinosaurs with the given name were found!" << std::endl
                          << std::endl;
            }
            continue;
        }
        if (command == "food")
        {
            double g = randDouble(50.0, 100.0);
            double m = randDouble(50.0, 100.0);
            double f = randDouble(50.0, 100.0);
            std::cout << std::endl
                      << "You've just added:" << std::endl
                      << " >   Grass  -  " << grass.second << " + " << g << " = " << grass.second + g << " kg" << std::endl
                      << " >   Meat   -  " << meat.second << " + " << m << " = " << meat.second + m << " kg" << std::endl
                      << " >   Fish   -  " << fish.second << " + " << f << " = " << fish.second + f << " kg" << std::endl
                      << std::endl;
            grass.second += g;
            meat.second += m;
            fish.second += f;
            continue;
        }
        if (command == "print")
        {
            if (isEmpty())
            {
                std::cout << std::endl
                          << "There aren't any dinosaurs in the zoo!" << std::endl
                          << std::endl;
                continue;
            }
            std::cout << std::endl
                      << "   Print" << std::endl
                      << std::endl;
            for (int i = 0; i < cages.size(); i++)
            {
                if (cages[i].get_dinosaurs().size() == 0)
                {
                    continue;
                }
                for (int j = 0; j < cages[i].get_dinosaurs().size(); j++)
                {
                    std::cout << cages[i].get_dinosaurs()[j];
                }
            }
            continue;
        }
        if (command == "exit")
        {
            std::ofstream out(zoo);
            out << "Number of cages: " << cages.size() << std::endl
                << toValidInputFormat(grass.first) << ": " << grass.second << std::endl
                << toValidInputFormat(meat.first) << ": " << meat.second << std::endl
                << toValidInputFormat(fish.first) << ": " << fish.second << std::endl
                << std::endl;
            for (int i = 0; i < cages.size(); i++)
            {
                out << cages[i];
            }
            out.close();
            std::cout << std::endl
                      << "Exiting the program...";
            exit(0);
        }
        std::cout << std::endl
                  << "Wrong command!" << std::endl
                  << std::endl;
    }
}

int main()
{
    srand(time(NULL));
    parkSystem();

    return 0;
}