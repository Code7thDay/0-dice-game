/*
 *  @file		Player.h
 *  @brief		Define the player class in the game.
 *  @author		Zachariah Hou
 *  @email		code7thday@outlook.com
 *  @version	1.0.0
 *  @date		2019-06-12
 */

#pragma once
#include "stdafx.h"

#include <map>
#include <vector>

#include "CombiSchema.h"
#include "Dice.h"

class Player
{
  private:
    int userID;
    std::string username;

    // The dices in current round.
    std::vector<Dice> currDiceList;

    // The dices asided.
    std::vector<Dice> asideDiceList;

    // Scores per round.
    std::vector<int> scoreList;

    // Score of current round.
    int currScore;

    // Total score of all passed round.
    int totalScore;

    // Score Rules Table
    std::map<CombiSchema, int>& scoreTable;

    // Reset the lists to the initialized state.
    void initRound();

    // Roll the dices in `currDiceList`.
    void rollDices();

    // Input a list of number. For `i` in the list, `currDiceList[i]` will be
    // insert to `asideDiceList`, and then be erased.
    void selectCombination(const std::vector<int>& selectList);

    // Evaluate the score of dices combination given.
    int evaluateCombination(const std::vector<int>& selectList);

    // Judging whether it's a FARKLE.
    bool isFarkle();

    // Judging whether it's a BONUS ROLL.
    bool isBonus();

    // Statistics the current schema of dice points.
    CombiSchema getCurrSchema();

    // Statistics the current number of given dice points.
    CombiSchema getSchema(const std::vector<int>& selectList);

    // If all the dices are put aside, take a BONUS ROLL.
    int getBonusRoll();

	// Print the result after `rollDices()` performed.
	void printRollRst();

	// A formatted output.
	void printTips(std::string tips);

  public:
    Player(int userID,
           std::string& username,
           std::map<CombiSchema, int>& scoreTable);

    ~Player();

    // Return the name of the player.
    const std::string& getName();

    // The MAIN process, start a new round.
    int playNewRound();

    // Calculate the score of dices combination in `currDiceList`.
    int calculateScore();
};
