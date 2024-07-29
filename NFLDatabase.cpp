#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player {  
    private:
    // player variables 
    int age;
    string college;
    string currentTeam;
    string conference;
    int experience;
    string height;
    string name;
    int number;
    string position;
    int weight;
    string state;
    string rangeHeight; 
    string ballSide;

    public:
    // getters
    int getAge() const { return age; }
    string getState() const {return state;}
    string getrangeHeight() const {return rangeHeight;}
    string getCollege() const { return college; }
    string getConference() const {return conference;}
    string getCurrentTeam() const { return currentTeam; }
    int getExperience() const { return experience; }
    string getHeight() const { return height; }
    string getBallSide() const {return ballSide;}
    string getName() const { return name; }
    int getNumber() const { return number; }
    
    string getPosition() const { return position; }
    int getWeight() const { return weight; }
    
    void displayerName() const{
        cout<<"Name: "<<name<<endl;
    }
    void displayPlayer() const {
        cout << "Name: " << name << "\n"
             << "Age: " << age << "\n"
             << "College: " << college << "\n"
             << "Current Team: " << currentTeam << "\n"
             << "Experience: " << experience << "\n"
             << "Height: " << height << "\n"
             << "Jersey Number: " << number << "\n"
             << "Weight: " << weight << "\n";
    }

    // Default constructor
    Player() : age(0), height(" "), number(0), weight(0), name(" "), college(" "), currentTeam(" "), experience(0), position(" "){}

    // Parameterized constructor
    Player(int number, const string& position, const string& ballSide, const string& height, int weight, int age, int experience,
       const string& college, const string& currentTeam, const string& name, const string& state, const string& rangeHeight, const string& conference) 
       : number(number), position(position), height(height), weight(weight), age(age),
         experience(experience), college(college), currentTeam(currentTeam), name(name), state(state), rangeHeight(rangeHeight), conference(conference), ballSide(ballSide){}

};  

class RandomPlayer {
    private:
    Player randomPlayer;
    vector<Player> playerList;

    public:
    const vector<Player>& getPlayerList() const { return playerList; }
    const Player& getRandomPlayer() const { return randomPlayer; }

    void addPlayer(const Player& player) {
        playerList.push_back(player);
    }

    void displayPlayerList() const{
        if (playerList.empty()){
            cout<<"Player List is empty display"<<endl;
            return;
        }

        for (const Player& player : playerList){
            player.displayerName();
            cout<<"---------------------"<<endl;
        }

    }

    void setRandomPlayer() {
        if (!playerList.empty()) {
            srand(static_cast<unsigned>(time(0)));
            int randomIndex = rand() % playerList.size();
            this->randomPlayer = playerList[randomIndex];
        } else {
            cout << "List is empty" << endl;
        }
    }

    const Player* validCheck(const string& guess){
        for (const Player& person : playerList){
            if (guess == person.getName()){
                return &person;
            }
    
        
        }

            cout<<"Sorry, player "<<guess<< " is NOT in our database. Try again"<<endl;
                return nullptr;
        }

    
    
    
};

class Game{
    private:
    string playerGuess;
    RandomPlayer correctPlayer;
    int numberOfGuess = 1;

    public:
    Game(const RandomPlayer& rp) : correctPlayer(rp) {}
    
    void startGame(){
            
            correctPlayer.setRandomPlayer();
        cout<<"Welcome to Weddle! Guess a current NFL player based on the given hints! Here are all the players!"<<endl;
        correctPlayer.displayPlayerList();
        while (numberOfGuess<10){
            string playerSelected;
            getline(cin, playerSelected); 
            if (checkWin(playerSelected)){
                break;
            }

        }
        if (numberOfGuess==10){
                cout<<"The player was: "<<endl;
                correctPlayer.getRandomPlayer().displayPlayer();
            }
    }

    bool checkWin(string& guess){
        const Player* guessedPlayer = correctPlayer.validCheck(guess); 
        if (guessedPlayer){ 
        if (guess == correctPlayer.getRandomPlayer().getName()){
            correctPlayer.getRandomPlayer().displayPlayer();
            return true;
            
        }else{
            cout<<"---------------------"<<endl<<"Sorry Wrong Player. You have "<< 10- numberOfGuess << " guesses left."<<endl ;
            if (guessedPlayer->getCollege()==correctPlayer.getRandomPlayer().getCollege()){
                cout<<"---------------------------------------------------------------------------------------------------------"<<endl<<"| The player did attend: "<<guessedPlayer->getCollege()<<endl;
            }
            if (guessedPlayer->getCollege()!=correctPlayer.getRandomPlayer().getCollege()){
                cout<<"---------------------------------------------------------------------------------------------------------"<<endl<<"| This player attended college located in the state of: " <<correctPlayer.getRandomPlayer().getState()<< endl<<"                                                                                                        |"<<endl;
            }

            if (guessedPlayer->getHeight() == correctPlayer.getRandomPlayer().getHeight()){
                cout<<"| The player is: " <<guessedPlayer->getHeight()<<endl<<"                                                                                                        |"<<endl;
            }
            if (guessedPlayer->getHeight() != correctPlayer.getRandomPlayer().getHeight()){
                cout<<"| This player's height ranges from: "<<guessedPlayer->getrangeHeight()<<endl<<"                                                                                                        |"<<endl;
            }
            if (guessedPlayer->getNumber() == correctPlayer.getRandomPlayer().getNumber()){
                cout<<"| The player's jersey number is: " <<guessedPlayer->getNumber()<<endl<<"                                                                                                        |"<<endl;
            }

            if (abs(guessedPlayer->getNumber() - correctPlayer.getRandomPlayer().getNumber()) <= 2 && guessedPlayer->getNumber() != correctPlayer.getRandomPlayer().getNumber()){
                cout<<"| The player's jersey number ranges between "<<correctPlayer.getRandomPlayer().getNumber()-1 <<" and "<<correctPlayer.getRandomPlayer().getNumber()+1<<endl<<"                                                                                                        |"<<endl;
            }
            if (abs(guessedPlayer->getNumber() - correctPlayer.getRandomPlayer().getNumber()) >2 && guessedPlayer->getNumber() != correctPlayer.getRandomPlayer().getNumber()){
                cout<<"| The player's jersey number is NOT "<<guessedPlayer->getNumber()<<endl<<"                                                                                                        |"<<endl;
            }
            if (abs(guessedPlayer->getExperience() - correctPlayer.getRandomPlayer().getExperience())<=2 && guessedPlayer->getExperience() != correctPlayer.getRandomPlayer().getExperience()){
                cout<<"| The player has played between "<<correctPlayer.getRandomPlayer().getExperience()-1<<" and " <<correctPlayer.getRandomPlayer().getExperience()+1<<" years"<<endl<<"                                                                                                        |"<<endl;
            }
            if (abs(guessedPlayer->getExperience() - correctPlayer.getRandomPlayer().getExperience())>2 && guessedPlayer->getExperience() != correctPlayer.getRandomPlayer().getExperience()){
                cout<<"| The player has NOT played for "<<guessedPlayer->getExperience()<< " years"<<endl<<"                                                                                                        |"<<endl;
            }
            if (guessedPlayer->getExperience() == correctPlayer.getRandomPlayer().getExperience()){
                cout<<"| The player has played for " <<correctPlayer.getRandomPlayer().getExperience()<<endl<< " years"<<endl<<"                                                                                                        |"<<endl;
            }
            if (guessedPlayer->getCurrentTeam() == correctPlayer.getRandomPlayer().getCurrentTeam()){
                cout<<"| The player plays for the " <<correctPlayer.getRandomPlayer().getCurrentTeam()<<endl<<"                                                                                                        |"<<endl;

            }
            if (guessedPlayer->getCurrentTeam() != correctPlayer.getRandomPlayer().getCurrentTeam() && guessedPlayer->getConference() == correctPlayer.getRandomPlayer().getConference()){
                cout<<"| The player does NOT play for "<<guessedPlayer->getCurrentTeam()<< " but the team is located in the "<<correctPlayer.getRandomPlayer().getConference()<<endl<<"                                                                                                        |"<<endl;
            }
            if (guessedPlayer->getCurrentTeam() != correctPlayer.getRandomPlayer().getCurrentTeam() && guessedPlayer->getConference() != correctPlayer.getRandomPlayer().getConference()){
                cout<<"| The player does NOT play for "<<guessedPlayer->getCurrentTeam()<< " and the team is NOT located in the "<<correctPlayer.getRandomPlayer().getConference()<<endl<<"                                                                                                        |"<<endl;
            }
            if (guessedPlayer->getWeight() == correctPlayer.getRandomPlayer().getWeight()){
                cout<<"| This player weighs "<<correctPlayer.getRandomPlayer().getWeight()<<" lbs"<<endl<<"                                                                                                        |"<<endl;

            }if (abs(guessedPlayer->getWeight() - correctPlayer.getRandomPlayer().getWeight())<=10 && guessedPlayer->getWeight() != correctPlayer.getRandomPlayer().getWeight()){
                cout<<"| The player weights between "<<correctPlayer.getRandomPlayer().getWeight()-10<<" and " <<correctPlayer.getRandomPlayer().getWeight()+10<<" lbs"<<endl<<"                                                                                                        |"<<endl;
            }
            if (abs(guessedPlayer->getWeight() - correctPlayer.getRandomPlayer().getWeight())>10 && guessedPlayer->getWeight() != correctPlayer.getRandomPlayer().getWeight()){
                cout<<"| The player does NOT weight "<<guessedPlayer->getWeight()<<" lbs"<<endl<<"                                                                                                        |"<<endl;
            }
            if (guessedPlayer->getPosition() == correctPlayer.getRandomPlayer().getPosition()){
                cout<<"| The player's position is "<<correctPlayer.getRandomPlayer().getPosition()<<endl<<"---------------------------------------------------------------------------------------------------------"<<endl;
            }
            if (guessedPlayer->getPosition() != correctPlayer.getRandomPlayer().getPosition() && (guessedPlayer->getBallSide() == correctPlayer.getRandomPlayer().getBallSide())){
                cout<<"| The player does NOT play "<<guessedPlayer->getPosition()<< " but does play on " <<correctPlayer.getRandomPlayer().getBallSide()<<endl<<"---------------------------------------------------------------------------------------------------------"<<endl;
            }
            if (guessedPlayer->getPosition() != correctPlayer.getRandomPlayer().getPosition() && (guessedPlayer->getBallSide() != correctPlayer.getRandomPlayer().getBallSide())){
                cout<<"| The player does NOT play on "<< guessedPlayer->getBallSide()<<endl<<"---------------------------------------------------------------------------------------------------------"<<endl;
            }
            numberOfGuess++;
            return false;
        }
        }
        return false;    


}

    
};


int main() {
    fstream inputFile;
    inputFile.open("C:/Users/Andy Nguyen/Downloads/Projects/Roster.txt");
    if (!inputFile.is_open()) {
        cerr << "Failed to open file" << endl;
        return 1;
    }

    string line;
    RandomPlayer randomPlayerManager;

    while (getline(inputFile, line)) {
        string name = line;

        if (!getline(inputFile, line)) {
            cerr << "Error reading player details" << endl;
            break;
        }

        int number;
        string position;
        string ballSide;
        string height;
        int weight;
        int age;
        int experience;
        string college;
        string currentTeam;
        string state;
        string rangeHeight;
        string conference;
        stringstream inputString(line);
        char delimiter;

        inputString >> number >> delimiter;
        if (delimiter != ',') {
            cerr << "Expected comma after number" << endl;
            continue;
        }

        getline(inputString, position, ',');
        
        getline(inputString, ballSide, ',');

        getline(inputString, height, ',');

        inputString >> weight >> delimiter;
        if (delimiter != ',') {
            cerr << "Expected comma after weight" << endl;
            continue;
        }

        inputString >> age >> delimiter;
        if (delimiter != ',') {
            cerr << "Expected comma after age" << endl;
            continue;
        }

        inputString >> experience >> delimiter;
        if (delimiter != ',') {
            cerr << "Expected comma after experience" << endl;
            continue;
        }

        getline(inputString, college, ',');

        getline(inputString, currentTeam, ',');

        getline(inputString, state, ',');

        getline(inputString, rangeHeight, ',');

        getline(inputString, conference);
        Player player(number, position, ballSide, height, weight, age, experience, college, currentTeam, name, state, rangeHeight, conference);
        randomPlayerManager.addPlayer(player);

        getline(inputFile, line);
    }

    inputFile.close();

    Game game(randomPlayerManager);
    game.startGame();

    return 0;
}






