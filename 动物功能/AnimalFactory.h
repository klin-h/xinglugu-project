#Refactored with Factory Pattern
#ifndef ANIMAL_FACTORY_H
#define ANIMAL_FACTORY_H

#include "Animal.h"
#include "Cow.h"
#include "Pig.h"
#include "Chicken.h"

#include <string>

enum class AnimalType {
    Cow,
    Pig,
    Sheep,
    Rabbit,
    Chicken,
    Dog,
};

class AnimalFactory {
public:
    static Animal* create(AnimalType type);
    static Animal* createById(const std::string& id);
private:
    AnimalFactory() = default;
    AnimalFactory(const AnimalFactory&) = delete;
    AnimalFactory& operator=(const AnimalFactory&) = delete;
};

#endif // ANIMAL_FACTORY_H

