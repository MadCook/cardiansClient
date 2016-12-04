#ifndef heartsArea_H
#define heartsArea_H

#include "GameLogic/Card.hpp"
#include "clientInfo.h"
#include "playerCard.h"
#include <functional>
#include <string>
#include <vector>
#include <wx/wx.h>

class heartsArea : public wxPanel {
  int thePlayerHandSize;
  int playerOneHandSize;
  int playerTwoHandSize;
  int playerThreeHandSize;
  wxBoxSizer *theMainSizer;

  wxBoxSizer *upperPortion;
  wxBoxSizer *middlePortion;
  wxBoxSizer *lowerPortion;

  wxBoxSizer *fieldArea;      // Horizontal 3 sections
  wxBoxSizer *leftFieldArea;  // Vertical 3 sections
  wxBoxSizer *midFieldArea;   // Verical 3 sections
  wxBoxSizer *rightFieldArea; // Vertical 3 sections

  wxBoxSizer *yourHand;
  wxBoxSizer *playerOne;
  wxBoxSizer *playerTwo;
  wxBoxSizer *playerThree;

  playerCard *playerZeroChoice;
  playerCard *playerOneChoice;
  playerCard *playerTwoChoice;
  playerCard *playerThreeChoice;
  std::vector<playerCard *> handCards;
  clientInfo *screenInfo;

  void setUpScreen(wxFrame *parent);

  std::function<void(Card)> humanMadeMove;
  void updateMiddleCards(std::vector<Card> centerPile);

public:
  heartsArea(wxFrame *parent, clientInfo *client);
  heartsArea(wxFrame *parent);
  ~heartsArea();
  void initializePlayArea(std::vector<Card> humanHand);
  void updatePlayArea(int playerId, std::vector<Card> hand,
                      std::array<Card, 4> centerPile);

  void updateOnlinePlayArea(std::vector<Card> hand, std::vector<int> handSizes,
                            std::vector<Card> field);
  void playerZero(std::vector<Card> hand);
  void playerAi(int playerId, int handSize);

  void invalidMoveDialog();
  bool endOfRoundDialog(std::vector<int> allPlayersRoundScores,
                        std::vector<int> allPlayersTotalScores);
  bool endOfGameDialog(std::vector<int> allPlayersRoundScores,
                       std::vector<int> allPlayersTotalScores);
  void setMadeMoveFunction(std::function<void(Card)>);
  std::vector<Card> requestCardsPassed(std::vector<Card> hand);
  void hideGame();
  void showGame();
};

#endif
