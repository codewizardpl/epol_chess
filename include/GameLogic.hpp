#ifndef GAME_LOGIC_HPP
#define GAME_LOGIC_HPP

class Board;
class Player;
class Move;

class GameLogic {
public: GameLogic() {};
  void startGame(Board& board, Player& white, Player& black);
  void makeMove(Board& board, Player& player);
private:
  
  bool validateMove(Board& board, Player& player, Move& move);
  void updateBoard(Board& board, Move&  move);
};

#endif
