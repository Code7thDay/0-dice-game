#include "Dice.h"

std::string
Dice::getPips(int point)
{
    std::string pips;

    switch (point) {
        case 1:
            pips = "┌───────┐"
                   "│       │"
                   "│   ●   │"
                   "│       │"
                   "└───────┘";
        case 2:
            pips = "┌───────┐"
                   "│       │"
                   "│ ●   ● │"
                   "│       │"
                   "└───────┘";
        case 3:
            pips = "┌───────┐"
                   "│ ●     │"
                   "│   ●   │"
                   "│     ● │"
                   "└───────┘";
        case 4:
            pips = "┌───────┐"
                   "│ ●   ● │"
                   "│       │"
                   "│ ●   ● │"
                   "└───────┘";
        case 5:
            pips = "┌───────┐"
                   "│ ●   ● │"
                   "│   ●   │"
                   "│ ●   ● │"
                   "└───────┘";
        case 6:
            pips = "┌───────┐"
                   "│ ●   ● │"
                   "│ ●   ● │"
                   "│ ●   ● │"
                   "└───────┘";

        default:
            break;
    }

    return pips;
}

Dice::Dice()
  : dicePoint(0)
{
    generator = std::default_random_engine(r());
    uniform_dist = std::uniform_int_distribution<int>(1, 6);
}

Dice::Dice(const Dice& dice) {
    generator = std::default_random_engine(r());
    uniform_dist = std::uniform_int_distribution<int>(1, 6);

	dicePoint = dice.dicePoint;
}

Dice::~Dice() {}

int
Dice::printPips()
{
    return printPips(dicePoint);
}

int
Dice::printPips(int point)
{
    if (point < 1 || point > 6) {
        throw std::range_error("Dice point must be in range 1 to 6!");
        return -1;
    }

    std::string pips = getPips(point);

    std::cout << pips;
    return 0;
}

int
Dice::setDicePoint(int point)
{
    if (point < 1 || point > 6) {
        throw std::range_error("Dice point must be in range 1 to 6!");
        return -1;
    }

    dicePoint = point;
    return 0;
}

int
Dice::getPoint() const
{
    return dicePoint;
}

int
Dice::roll()
{
    dicePoint = uniform_dist(generator);
    return dicePoint;
}

Dice&
Dice::operator=(const Dice& _dice)
{
    generator = std::default_random_engine(r());
    uniform_dist = std::uniform_int_distribution<int>(1, 6);

    dicePoint = _dice.dicePoint;

    return *this;
}
