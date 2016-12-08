
#include <algorithm>
#include <iterator>
#include <iostream>

#include "FigureBishop.hpp"
#include "Position.hpp"

FigureBishop::FigureBishop(FigureColour colour) : Figure(FigureType::Bishop, colour)
{
}


FigurePath FigureBishop::validateMove(Move _move, FigureMoveType _moveType)
{
    return FigurePath(false);
}


std::set<Position> FigureBishop::getPossibleMoves(Position start)
{
	std::set<Position> result;
	std::vector<Position> movers{ Position(-1,+1), Position(-1,-1), Position(+1,+1), Position(+1,-1)};

	PositionValidator validator(0, 7, 0, 7);

	for_each(movers.cbegin(), movers.cend(),
			[&result, &validator, &start] (const Position& mover) {

				Position temp = (start + mover);
				while (validator(temp))
				{
					result.insert(temp);
					temp = temp + mover;
				}
			}
	);

    return result;
}

void test()
{
    Position p(1,1);
	std::cout << "Point: " << p << std::endl;
	std::set<Position> r = FigureBishop(FigureColour::White).getPossibleMoves(p);
	std::copy(r.begin(), r.end(), std::ostream_iterator<Position>(std::cout, ", "));
	std::cout << std::endl;

}



