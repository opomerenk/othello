//p
#include "player.hpp"
#include <iostream>

//opomerenk making small change

//eli pinkus making change

/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */
Player::Player(Side s) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;
    side = s;
    board = new Board();
				 
    /*
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be
 * nullptr.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return nullptr.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /*
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */

	int heuristic[8][8] = {{10000, -3500, 1000, 800, 800, 1000, -3500, 10000},
							 {-3500, -5000, -450, -500, -500, -450, -5000, -3500},
							 {1000, -450, 30, 10, 10, 30, -450, 1000},
							 {800, -500, 10, 100, 100, 10, -500, 800},
							 {800, -500, 10, 100, 100, 10, -500, 800}, 
							 {1000, -450, 30, 10, 10, 30, -450, 1000},
							 {-3500, -5000, -450, -500, -500, -450, -5000, -3500},
							 {10000, -3500, 1000, 800, 800, 1000, -3500, 10000}};

     if (side == BLACK)
     {
     	board->doMove(opponentsMove, WHITE);
     }
     else
     {
     	board->doMove(opponentsMove, BLACK);
     }

    
    int bestn = -5000;
    Move *best = nullptr;
	for (int i = 0; i < 8; i++) 
	{
        for (int j = 0; j < 8; j++) 
        {
            Move *move = new Move(i, j);
            if ((board->checkMove(move, side)) && (heuristic[i][j] >= bestn))
            {
            	bestn = heuristic[i][j];
            	best = move;
        	}
        }

    }
    board->doMove(best, side);
    return best;
}
