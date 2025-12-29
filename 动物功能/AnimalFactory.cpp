#Refactored with Factory Pattern
#include "AnimalFactory.h"

Animal* AnimalFactory::create(AnimalType type) {
    switch (type) {
        case AnimalType::Cow:
            return Cow::create();
        case AnimalType::Pig:
            return Pig::create();
        case AnimalType::Sheep:
            return Sheep::create();
        case AnimalType::Rabbit:
            return Rabbit::create();
        case AnimalType::Chicken:
            return Chicken::create();
        case AnimalType::Dog:
            return Dog::create();
        default:
            return nullptr;
    }
}

Animal* AnimalFactory::createById(const std::string& id) {
    if (id == "cow") {
        return create(AnimalType::Cow);
    }
    if (id == "pig") {
        return create(AnimalType::Pig);
    }
    if (id == "sheep") {
        return create(AnimalType::Sheep);
    }
    if (id == "rabbit") {
        return create(AnimalType::Rabbit);
    }
    if (id == "chicken") {
        return create(AnimalType::Chicken);
    }
    if (id == "dog") {
        return create(AnimalType::Dog);
    }
    return nullptr;
}

