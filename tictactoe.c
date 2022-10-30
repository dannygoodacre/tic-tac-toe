#include <stdio.h>

int optimalPositions[] = {4, 0, 2, 6, 8, 1, 3, 5, 7};
const int rowStartPositions[] = {0, 3, 6};
char board[] = "         "; // 9 spaces


void displayBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = rowStartPositions[i]; j < rowStartPositions[i] + 3; j++)
        {
            printf("%c", board[j]);
        }
        printf("%c", '\n');
    }
}


int containsIconAt(int pos, char icon)
{
    return board[pos] == icon;
}


int isEmptyAt(int pos)
{
    return containsIconAt(pos, ' ');
}


int isBoardFull()
{
    for (int i = 0; i < 9; i++)
    {
        if (isEmptyAt(i)) return 0;
    }

    return 1;
}


int isValidMove(int pos)
{
    return pos >=0 && pos < 9 && isEmptyAt(pos);
}


int getPlayerMove()
{
    int move;
    printf("Your move: ");
    scanf(" %i", &move);

    return move;
}


int getWinningPositionFor(char icon)
{
    for (int i = 0; i < 3; i++)
    {
        // rows
        if (
            containsIconAt(rowStartPositions[i], icon) 
            && containsIconAt(rowStartPositions[i] + 1, icon) 
            && isEmptyAt(rowStartPositions[i] + 2))
        {
            return rowStartPositions[i] + 2;
        }
        else if (
            containsIconAt(rowStartPositions[i], icon) 
            && containsIconAt(rowStartPositions[i] + 2, icon) 
            && isEmptyAt(rowStartPositions[i] + 1))
        {
            return rowStartPositions[i] + 1;
        }
        else if (
            containsIconAt(rowStartPositions[i] + 1, icon) 
            && containsIconAt(rowStartPositions[i] + 2, icon) 
            && isEmptyAt(rowStartPositions[i]))
        {
            return rowStartPositions[i]; 
        }

        // columns
        else if (
            containsIconAt(i, icon) 
            && containsIconAt(i + 3, icon) 
            && isEmptyAt(i + 6))
        {
            return i + 6;
        }
        else if (
            containsIconAt(i, icon) 
            && containsIconAt(i + 6, icon) 
            && isEmptyAt(i + 3))
        {
            return i + 3;
        }
        else if (
            containsIconAt(i + 3, icon) 
            && containsIconAt(i + 6, icon) 
            && isEmptyAt(i))
        {
            return i;
        }
    }

    if (
        containsIconAt(0, icon) 
        && containsIconAt(4, icon) 
        && isEmptyAt(8))
    {
        return 8;
    }
    else if (
        containsIconAt(0, icon) 
        && containsIconAt(8, icon) 
        && isEmptyAt(4))
    {
        return 4;
    }
    else if (
        containsIconAt(4, icon) 
        && containsIconAt(8, icon) 
        && isEmptyAt(0))
    {
        return 0;
    }
    else if (
        containsIconAt(2, icon) 
        && containsIconAt(4, icon) 
        && isEmptyAt(6))
    { 
        return 6;
    }
    else if (
        containsIconAt(2, icon) 
        && containsIconAt(6, icon) 
        && isEmptyAt(4))
    {
        return 4;
    }
    else if (
        containsIconAt(4, icon) 
        && containsIconAt(6, icon) 
        && isEmptyAt(2))
    {
        return 2;
    }

    return -1;
}


int getOptimalPosition()
{
    for (int i = 0; i < 9; i++)
    {
        if (isEmptyAt(optimalPositions[i])) return optimalPositions[i];
    }

    return -1;
}


int getBotPositionToPlay() ///
{
    int pos = getWinningPositionFor('O');

    if (pos == -1) // no bot two-in-a-row
    {
        pos = getWinningPositionFor('X');
        return pos == -1 ? (isBoardFull() ? -1 : getOptimalPosition()) : pos;
    }
    else // bot wins
    {
        board[pos] = 'O';
        return -2;
    }
}


int isGoingFirst()
{
    char choice;
    int valid = 0, first;
    while (!valid)
    {
        printf("Would you like to go first or second (1/2)? ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case '1': 
                first = 1;
                valid = 1;
                break;
            case '2':
                first = 0;
                valid = 1;
                break;
            default:
                printf("Invalid choice\n");
        }

        return first;
    }
}


int main()
{
    if (!isGoingFirst()) 
    {
        board[4] = 'O';
        displayBoard();
    }

    char* outcome;
    int finished = 0, move, botMove;

    while (!finished)
    {
        move = getPlayerMove() - 1; // enter 0 to exit

        finished = move == -1 || isBoardFull();

        if (!finished)
        {
            if (isValidMove(move))
            {
                board[move] = 'X';
                botMove = getBotPositionToPlay();

                if (botMove >= 0) 
                {
                    board[botMove] = 'O';
                    isBoardFull() ? botMove = -1 : displayBoard();
                }
                
                if (botMove == -1)
                {
                    outcome = "DRAW";
                    finished = 1;
                }
                else if (botMove == -2) 
                {
                    outcome = "LOSS";
                    finished = 1;
                }
            }
            else printf("Invalid move\n");
        }
    }

    if (outcome) 
    {
        displayBoard();
        printf("\n%s", outcome);
    }

    printf("\nGoodbye!\n");
    return 0;
}