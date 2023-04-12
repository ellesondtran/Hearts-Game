//Elleson Tran
//Roberts
//Hearts! Project
//A program creates a guessing game for hearts
//FINAL

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

const string RED = "❤️";
const string BLUE = "💙";
const string GREEN="💚";
const string YELLOW="💛";
const string PURPLE="💜";
const string ONE="1️⃣";
const string TWO="2️⃣";
const string THREE="3️⃣";
const string FOUR="4️⃣";
const string FIVE="5️⃣";


const vector<string> HEARTS = {"spacer", RED, BLUE, GREEN, YELLOW, PURPLE};
const vector<string> NUMS={"spacer", ONE, TWO, THREE, FOUR, FIVE};

//function that shows the rules
void showRules(){
  cout<<"Rule of Hearts!:"<<endl<<"The computer has selected hearts of three colors and placed them in 3 positions. "<<endl<<"Your task is to guess which color hearts are used AND in what positions they have been placed."<<endl<<"You have 10 tries."<<endl<<"While there are 5 possible colors , only 3 are used."<<endl<<"There is only one heart of each color."<<endl;
}

//function that creates the random hearts 
//make sure that the sequence that is returned here, stays the same until the game is over
vector<int> makeHearts(vector<int> &randomHearts){
  int randomNum;
  randomHearts[1] = rand()%5 + 1;
  for(int x = 2; x <= 3;x++){
    randomNum = rand()%5 + 1;
    if(randomHearts[x - 1] == randomNum){//if the new number is the same as the one before that
      while(randomHearts[x - 1] == randomNum){//keeps generating a new number if it is ^^
        randomNum = rand()%5 + 1;
        randomHearts[x] = randomNum;
      }
    }
    if(randomHearts[1] == randomNum){//if the new number is the same as the first number
      while(randomHearts[1] == randomNum){//keeps generating a new number if it is ^^
        randomNum = rand()%5 + 1;
        if(randomNum == randomHearts[2]){//if the number is the same as the second one
          randomNum = rand()%5 + 1;
          randomHearts[x] = randomNum;
        }
        randomHearts[x] = randomNum;
      }
    }
    randomHearts[x] = randomNum;
  }
  return randomHearts;
}

//function that asks the user to guessing
//returns whatever they typed
vector<int> turn(vector<int> &guesses){
  cout<<endl<<endl<<endl<<"Enter your guesses:"<<endl;
  for(int x = 1; x <= 5; x++){//prints the number emojis
    cout<<NUMS[x]<<"  ";
  }
  cout<<endl;
  for(int x = 1; x <= 5; x++){//prints the heart emojis
    cout<<HEARTS[x]<<"  ";
  }
  cout<<endl;
  for(int x = 1; x <= 3; x++){//asks for their three guesses
    cin>>guesses[x];
  }
  return guesses;
}

//function that checks if they had any right colors
//returns how many of the colors were right, int
int correctColors(int &numOfCorrectCOLOR, vector<int> randomHearts, vector<int> guesses){
  numOfCorrectCOLOR = 0;

  if(randomHearts[1] == guesses[1] || randomHearts[1] == guesses[2] || randomHearts[1] == guesses[3]){//first heart color is the same as any of the guesses
    numOfCorrectCOLOR = numOfCorrectCOLOR + 1;
  }
  if(randomHearts[2] == guesses[1] || randomHearts[2] == guesses[2] || randomHearts[2] == guesses[3]){//second heart color is the same as any of the guesses
    numOfCorrectCOLOR = numOfCorrectCOLOR + 1;
  }
  if(randomHearts[3] == guesses[1] || randomHearts[3] == guesses[2] || randomHearts[3] == guesses[3]){//third heart color is the same as any of the guesses
    numOfCorrectCOLOR = numOfCorrectCOLOR + 1;
  }
  return numOfCorrectCOLOR;
}

//function that checks if the order is right
//returns how many of the colors were in the right position, int
int correctOrder(int &numOfCorrectORDER, vector<int> randomHearts, vector<int> guesses){
  numOfCorrectORDER = 0;

  if(randomHearts[1] == guesses[1]){
    numOfCorrectORDER = numOfCorrectORDER + 1;
  }
  if(randomHearts[2] == guesses[2]){
    numOfCorrectORDER = numOfCorrectORDER + 1;
  }
  if(randomHearts[3] == guesses[3]){
    numOfCorrectORDER = numOfCorrectORDER + 1;
  }
  return numOfCorrectORDER;
}

//function that displays the correct colors, positions, and attempts
//doesnt return anything
void display(int attempts, int numOfCorrectCOLOR, int numOfCorrectORDER){//prints the display
  cout<<endl<<"--------------------";
  cout<<endl<<"Colors correct: "<<numOfCorrectCOLOR;
  cout<<endl<<"Positions correct: "<<numOfCorrectORDER;
  cout<<endl<<"Attempts left:"<<attempts;
  cout<<endl<<"--------------------";  
}

//function that displays the correct solution
//doesnt return anything
void correctSolution(vector<int> randomHearts){//prints the solution
  cout<<endl<<"Correct Solution:";
  cout<<endl<<"---- ---- ----";
  cout<<endl<<HEARTS[randomHearts[1]]<<"  |  "<<HEARTS[randomHearts[2]]<<"  |  "<<HEARTS[randomHearts[3]];
  cout<<endl<<"---- ---- ----";
  
}



//function that displays how many they are right, or if they win
//returns how many attempts they have
int check(int &attempts, int numOfCorrectCOLOR, int numOfCorrectORDER, vector<int> randomHearts){
  attempts = attempts - 1;
  if(numOfCorrectORDER == 3){//if they get it correct
    correctSolution(randomHearts);
    cout<<endl<<"Pretty decent";
    attempts = 0;
    return attempts;
  }
  if(numOfCorrectORDER == 3 && attempts == 0){//if they get it correct ON THE LAST TRY
    correctSolution(randomHearts);
    cout<<endl<<"Pretty decent";
    attempts = 0;
    return attempts;
  }
  if(numOfCorrectORDER != 3 && attempts != 0){//if they have attempts left AND did not guess the hearts correctly, continue the game
    display(attempts, numOfCorrectCOLOR, numOfCorrectORDER);
    return attempts;
  }
  return attempts;
}



int main() {
  srand(time(0));

  //rules
  cout<<"Rules of Hearts!:"<<endl<<"The computer has selected hearts of three colors and placed them in 3 positions. Your task is to guess which color hearts are used AND in what positions they have been placed."<<endl<<"You have 10 tries."<<endl<<"While there are 5 possible colors , only 3 are used."<<endl<<"There is only one heart of each color."<<endl;

  bool playAgain = true;
  char yesOrNo;

  do{//keeps going until the player doesnt want to play anymore
    int attempts = 10; //return this in check function
    int numOfCorrectCOLOR = 0; //return this in correct colors function
    int numOfCorrectORDER = 0;///return this in correct order function

    //makes the random hearts
    vector<int> tempRandomHearts(4); 
    const vector<int> randomHearts = makeHearts(tempRandomHearts);

    while(attempts != 0){//keeps going until they have no attempts left
      //asks the user to guess
      vector<int> tempGuesses(4);
      const vector<int> guesses = turn(tempGuesses);

      //checks if the colors are right
      correctColors(numOfCorrectCOLOR, randomHearts, guesses);

      //checks if the order is right
      correctOrder(numOfCorrectORDER, randomHearts, guesses);

      check(attempts, numOfCorrectCOLOR, numOfCorrectORDER, randomHearts);

    }

    //once the player gets it correct or if they use all off their attempts, it asks if they want to play again
    cout<<endl<<"Want to play again? y/n: ";
    cin>>yesOrNo;
    if(yesOrNo == 'n'){
      playAgain = false;
      cout<<endl<<"Bye!";
      break;
    }
    if(yesOrNo == 'y'){
      playAgain = true;
    }

    
  }while(playAgain != false);//keeps going until the player doesnt want to play anymore

}