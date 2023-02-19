//file name: AI_BTH2_22022604


/*playable 3x3 tic tac toe
1.Ai engine
    + state representation : vector<vector<char>> (3x3)
    + checking if game is end
    + detect winner or draw if game end
    + render (text screen)
    + valid moves
        + detect current player
        + calculate valid moves
    + calculate state score
        + final state score
        + not-final state score
    + calculate best move
2.User interface
    + asking play or exit.
    + asking x or o.
    + input move cordinate start from 0.
    + delay a several times if state is invalid
    + response if illegal move
    + response game result when end
    + print current game
    + print machine's move
*/

#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char> > State; //Dinh nghia 1 kieu du lieu moi.
const int SIZE = 3; //Kich co tro choi

/*Ham mo dau tro troi.
input: your choose
output : continue or exit   */
void gameStart()
{
    char choose = ' ';
    while (choose != 'C' && choose != 'E')
    {
        cout << "Press C to choose player." << endl << "Press E to exit game." << endl;
        cin >> choose;
        if (choose == 'E')
        {
            exit(0);
        }
        else if (choose == 'C')
        {
            system("cls");
        }
        else
        {
            cout << "\a";
            system("cls");
        }
    }
}

/*Ham chon nguoi choi:
input: human player, player who move first
output: your player, player turn*/
void choosePlayer(char& humanPlayer, char currentPlayer){
    cout << "Choose your player (X or O): ";
    cin >> humanPlayer;
    cout << "You are " << humanPlayer << " player." << endl;
    humanPlayer == currentPlayer ? cout << "Your turn: " << endl : cout << "My turn: " << endl;
}

/*Ham tao khung tro choi Caro 3x3.
input: state
output: print game on screen  */
void renderGame(State state)
{
    cout << "   0   1   2" << endl;
    cout << " ------------- " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << " | " << state[i][j];
        }
        cout << " | " << i << endl << " ------------- " << endl;
    }
}

/*Ham di nuoc co.
input: State s, int i(row), int j(col), player(X or O)
output:new state   */
State play(State s, int i, int j, char player)
{
    State newState = State(3, vector<char>(3, ' '));
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            newState[i][j] = s[i][j];
        }
    }
    newState[i][j] = player;
    return newState;
}

/*Ham tao thoi gian cho.
input: time ( an integer num )
output: non-   */
void delay(int time)
{
    for (int i = 1; i < time; i++)
    {
        for (int j = 1; j < 8 * time; j++) {/*Dont do anything.*/ }
    }
}

/*Ham kiem tra nuoc co da het hay chua.
input: state
output: is final state (bool)    */
bool isFinalState(State s){
    // check rows
    for (int i = 0; i < SIZE; i++){
        if (s[i][0] == s[i][1] && s[i][0] == s[i][2] && s[i][0] != ' '){
            return true;
        }
    }
    // check cols
    for (int i = 0; i < SIZE; i++){
        if (s[0][i] == s[1][i] && s[0][i] == s[2][i] && s[0][i] != ' '){
            return true;
        }
    }
    // check diagonals
    if (s[0][0] == s[1][1] && s[0][0] == s[2][2] && s[0][0] != ' '){
        return true;
    }
    if (s[0][2] == s[1][1] && s[0][2] == s[2][0] && s[0][2] != ' '){
        return true;
    }
    // check full
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (s[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

/*Ham tinh ket qua.
input: final state
output: score    */
int getScoreFinalState(State s){
    // check rows
    for (int i = 0; i < SIZE; i++){
        if (s[i][0] == s[i][1] && s[i][0] == s[i][2] && s[i][0] != ' '){
            return s[i][0] == 'X' ? 1 : -1;
        }
    }
    // check cols
    for (int i = 0; i < SIZE; i++){
        if (s[0][i] == s[1][i] && s[0][i] == s[2][i] && s[0][i] != ' '){
            return s[0][i] == 'X' ? 1 : -1;
        }
    }
    //check diagonals
    if (s[0][0] == s[1][1] && s[0][0] == s[2][2] && s[0][0] != ' '){
        return s[0][0] == 'X' ? 1 : -1;
    }
    if (s[0][2] == s[1][1] && s[0][2] == s[2][0] && s[0][2] != ' '){
        return s[0][2] == 'X' ? 1 : -1;
    }
    return 0;
}

/*Ham check nguoi choi tiep theo.
input: number of X & O
output: next player = X : O    */
char getNextPlayer(State s){
    int countX = 0, countO = 0;
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (s[i][j] == 'X'){
                countX++;
            }
            else if (s[i][j] == 'O'){
                countO++;
            }
        }
    }
    if (countX == countO) return 'X';
    else return 'O';
}

/*Ham check cac nuoc co the di tiep theo.
(Tao 1 khong gian gom ban co voi cac nuoc co co the di tiep)
input: next player
output: valid states   */
vector<State> getNextStates(State s){
    char nextPlayer = getNextPlayer(s);
    vector<State> states;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (s[i][j] == ' ') {
                State nextState = play(s, i, j, nextPlayer);
                states.push_back(nextState);
            }
        }
    }
    return states;
}


/*Ham tinh 'diem' cua nuoc di trung gian.
input: this state
output: true state  & its score     */
pair<int, State> getScore(State s)
{
    if (isFinalState(s))    //Neu la nuoc cuoi cung thi in ra ket qua va van co da choi.
    {
        return make_pair(getScoreFinalState(s), s);
    }

    /*Neu khong:
            -->Tim nuoc di phu hop nhat.*/
    char player = getNextPlayer(s);
    vector<State> states = getNextStates(s);
    int bestScore = -10;
    State bestState;
    for (State nstate : states){
        pair<int, State> p = getScore(nstate);  //Khoi tao nhom chua 'diem' cua nuoc di va 
        int score = p.first;
        if (player == 'X') //Vi X la max.
        {
            if (bestScore < score || bestScore == -10){
                bestScore = score;
                bestState = nstate;
            }
        }
        else //O la min.
        {
            if (bestScore > score || bestScore == -10){
                bestScore = score;
                bestState = nstate;
            }
        }
    }
    return make_pair(bestScore, bestState);
}

/*Ham tao 1 AI choi co.
input: state
output: state    */
pair<int, int> getComputerPlay(State s) {
    int count = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(s[i][j] == ' ') count++;
            else break;
        }
    }
    if(count == 3*3) return make_pair(1, 1);
    
    pair<int, State> p = getScore(s);
    int score = p.first;
    State newState = p.second;
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (newState[i][j] != s[i][j]) return make_pair(i, j);
        }
    }
    return make_pair(-1, -1);
}


//Ham in ket qua.
/*input: final state, player
output: result */
void printResult(State s, char humanPlayer) {
    if (isFinalState(s))
    {
        int score = getScoreFinalState(s);
        if (score > 0) {
            if (humanPlayer == 'X') {
                cout << "You won" << endl;
            }
            else {
                cout << "You lost" << endl;
            }
        }
        else if (score < 0) {
            if (humanPlayer == 'O') {
                cout << "You won" << endl;
            }
            else {
                cout << "You lost" << endl;
            }
        }
        else {
            cout << "A draw" << endl;
        }
        //exit(0);
    }
}


//Ham di co.
/* input: state, human player , current player
output: pair i, j to move
*/
pair<int, int> getMove(State s, char humanPlayer, char currentPlayer) {
    int i = -1, j = -1;
    if (humanPlayer == currentPlayer) {
        do {
            cout << "Enter your play (row - col): ";
            cin >> i >> j;
            if (s[i][j] == 'X' || s[i][j] == 'O') {
                cout << "Your play is invalid, please try agian." << endl;
                delay(15000);
            }
            system("cls");
            cout << "You are " << humanPlayer << " player, your turn: " << endl;
            renderGame(s);
        } while (s[i][j] != ' ');
        system("cls");
        //cout << "You play (" << i << ", " << j << ")" << endl;
        // TODO check legal move
    }
    else {
        pair<int, int> move = getComputerPlay(s);
        i = move.first;
        j = move.second;
        system("cls");
        cout << "I play (" << i << ", " << j << ")" << endl;
    }
    return make_pair(i, j);
}

/*Ham chay tro choi
input: state, human, current player
output: End Game    */
void playGame(State s, char humanPlayer, char currentPlayer){
    while (true){
        pair<int, int> move = getMove(s, humanPlayer, currentPlayer);
        int i = move.first, j = move.second;

        s = play(s, i, j, currentPlayer);
        renderGame(s);

        //Doi nguoi choi.
        currentPlayer = currentPlayer == 'X' ? 'O' : 'X';
        
        //Check kthuc
        if (isFinalState(s)) break;
    }
    //In ra ket qua.
    printResult(s, humanPlayer);
}


int main()
{
    //Update1: Mo dau tro choi.
    gameStart();

    //Chon nguoi choi.
    char humanPlayer = ' ', currentPlayer = 'X';
    choosePlayer(humanPlayer, currentPlayer);

    //Tao khung voi o trong.
    State s = State(3, vector<char>(3, ' '));
    renderGame(s);

    //Chay tro choi.
    playGame(s, humanPlayer, currentPlayer);

    system("pause");

    return 0;
}