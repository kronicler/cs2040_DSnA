#include <iostream>

// function to determine who is the winner given the hand of the two players
int winner (int player11, int player12, int player21, int player22);

int main(void) {
    int player11 = 99, player12 = 99, player21 = 99, player22 = 99;
    int count = 1;
    
    //while loop that continues to read the data inputs until a row of zeroes
    while (1) {
        std::cin >> player11 >> player12 >> player21 >> player22;
        if (count == 1) {
            std::cout << std::endl;
        }
        count++;
        
        //condition to check for the terminating line of zeroes
        if (player11 == 0 && player12 == 0 && player21 == 0 && player22 == 0) {
            exit(0);
        }
        
        winner(player11, player12, player21, player22);
    }

    return 0;
}

int winner (int player11, int player12, int player21, int player22) {
    //two integers to determine the largest digit between each pair, if they are distinct
    int largest1, largest2;

    //checking if Mia is rolled
    if ((player11 == 1 && player12 == 2) || (player11 == 2 && player12 == 1)) {
        std::cout << "Player 1 wins." << std::endl;
        return 0;
    }
    else if ((player21 == 1 && player22 == 2) || (player21 == 2 && player22 == 1)) {
       std::cout << "Player 2 wins." << std::endl;
        return 0;
    }
    
    //checking for a double between both roles
    if (player11 == player12 && player21 != player22) {
        std::cout << "Player 1 wins." << std::endl;
        return 0;
    }
    else if (player21 == player22 && player11 != player12) {
        std::cout << "Player 2 wins." << std::endl;
        return 0;
    }
    //comparing the size of two double rolls
    else if (player11 == player12 && player21 == player22) {
        if (player11 > player21) {
            std::cout << "Player 1 wins." << std::endl;
            return 0;
        }
        else if (player11 < player21) {
            std::cout << "Player 2 wins." << std::endl;
            return 0;
        }
        else {
            std::cout << "Tie." << std::endl;
            return 0;
        }
    }
    
    //organising the roll depending on the larger integer
    if (player11 > player12) {
        largest1 = player11;
    }
    else {
        largest1 = player12;
    }
    
    if (player21 > player22) {
        largest2 = player21;
    }
    else {
        largest2 = player22;
    }
    
    //comparing the largest integers from each player
    if (largest1 > largest2) {
        std::cout << "Player 1 wins." << std::endl;
    }
    else if (largest2 > largest1){
        std::cout << "Player 2 wins." << std::endl;
    }
    else {
        std::cout << "Tie." << std::endl;
    }

    return 0;
}
