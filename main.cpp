#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <time.h>
#include <algorithm>

class Card{
protected:
    int attackPower, maxHP;
    std::string Name,Type,color,manaCost;
    bool isTapped,isUnTapped,isInPlay,isInHand,isInDiscards,isDestroyed,hasTrample,hasFirstStrike;
public:
    Card(){
        Name = "Name";
        color = "";
        manaCost = "";
        Type = "";
        isTapped = false;
        isUnTapped = true;
        isInPlay = false;
        isInHand = false;
        isInDiscards = false;
        isDestroyed = false;
    }
    explicit Card(std::string n):Name(n){
        manaCost = "";
        Type = "";
        color = "colorless";
        isTapped = false;
        isUnTapped = true;
        isInPlay = false;
        isInHand = false;
        isInDiscards = false;
        isDestroyed = false;
    }
    Card(const Card &obj){
        Name=obj.Name;
        color =obj.color;
        manaCost = obj.manaCost;
        Type = obj.Type;
        isTapped = obj.isTapped;
        isUnTapped = obj.isUnTapped;
        isInPlay = obj.isInPlay;
        isInHand = obj.isInHand;
        isInDiscards = obj.isInDiscards;
        isDestroyed = obj.isDestroyed;

    }
    const std::string &getColor() const {
        return color;
    }

    const std::string &getType() const {
        return Type;
    }

    void Tap(){
        isTapped = true;
    };

    virtual void unTap() {
        isTapped = false;
        isUnTapped = true;
    }
    virtual bool isHasBeenBoosted() const{
        return false;
    }
    virtual void setHasBeenBoosted(bool){}
    bool isTapped1() const {
        return isTapped;
    }

    bool isUnTapped1() const {
        return isUnTapped;
    }
    virtual void resetHealth(std::string name){
    }
    void setIsInPlay(){
        isInPlay = true;
        isInHand = false;
    }
    void setIsInHand(){
        isInHand = true;
    }
    void setIsInDiscards(){
        isInDiscards = true;
        isInPlay = false;
    }
    std::string getMana(){
        return manaCost;
    }
    virtual int getAttackPower(){
        return 0;
    }
    virtual void setAttackPower(int aP){
    }
    virtual void sustainDamage(int dmg){
    }

    virtual bool getHasTrample(){
        return true;
    }
    virtual void setHasTrample(bool hasTrample){}
    virtual bool getHasFirstStrike(){
        return true;
    }
    virtual void setHasFirstStrike(bool hasFirstStrike) {
    }

    virtual int getHealth(){
        return 0 ;
    }
    virtual void setHealth(int hp){

    }
    virtual bool hasBeenDestroyed(){
        return isDestroyed;
    }
    virtual void setIsDestroyed(){
        isDestroyed = true;
    }
    virtual void setTarget(std::string  const & t){}
    virtual std::string getTarget(){
        return "";
    }

    const std::string &getName() const {
        return Name;
    }

    void printCreatureInfo(){
        std::string valueTrample = " ";
        std::string valueFirstStrike = " ";
        if(hasTrample && hasFirstStrike){
            valueTrample = "Yes";
            valueFirstStrike = "Yes";
        }else if(hasTrample && !hasFirstStrike){
            valueTrample = "Yes";
            valueFirstStrike = "No";
        }else if(!hasTrample && hasFirstStrike){
            valueTrample = "No";
            valueFirstStrike = "Yes";
        }else{
            valueTrample = "No";
            valueFirstStrike = "No";
        }
        std::cout << "Name: " << Name <<"\nAttack Power: "<<attackPower << "\nHp: " << maxHP << "\nHas Trample: " <<
                  valueTrample << "\nHas FirstStrike: " << valueFirstStrike << std::endl;
    }
    void printName(){
        std::cout << Name<<"\n";
    }

};

class landCard : public Card{
public:

    explicit landCard(std::string name):Card(name){
        Type = "Land";
    }

    landCard(const landCard &t)  : Card(t) {
        Type = t.Type;
    }
    ~landCard(){

    }
};

class creatureCard : public Card{
protected:
    int attackPower,maxHP;
    bool hasFirstStrike, hasTrample, hasBeenBoosted;
public:
    explicit creatureCard(std::string n):Card(n) {
        Type = "Creature";
        if (Name == "Soldier") {
            attackPower = 1;
            maxHP = 1;
            color = "White";
            manaCost = "W";
            hasFirstStrike = false;
            hasTrample = false;
            hasBeenBoosted = false;
        } else if (Name == "Armored Pegasus") {
            attackPower = 1;
            maxHP = 2;
            color = "White";
            manaCost = "1W";
            hasFirstStrike = false;
            hasTrample = false;
        } else if (Name == "White Knight") {
            attackPower = 2;
            maxHP = 2;
            color = "White";
            manaCost = "WW";
            hasFirstStrike = true;
            hasTrample = false;
        } else if (Name == "Angry Bear") {
            attackPower = 3;
            maxHP = 2;
            color = "Green";
            manaCost = "2G";
            hasFirstStrike = false;
            hasTrample = true;
        } else if (Name == "Guard") {
            attackPower = 2;
            maxHP = 5;
            color = "White";
            manaCost = "2WW";
            hasFirstStrike = false;
            hasTrample = false;
        } else if (Name == "Werewolf") {
            attackPower = 4;
            maxHP = 6;
            color = "Green";
            manaCost = "2GW";
            hasFirstStrike = false;
            hasTrample = true;
        } else if (Name == "Skeleton") {
            attackPower = 1;
            maxHP = 1;
            color = "Black";
            manaCost = "B";
            hasFirstStrike = false;
            hasTrample = false;
        } else if (Name == "Ghost") {
            attackPower = 2;
            maxHP = 1;
            color = "Black";
            manaCost = "1B";
            hasFirstStrike = false;
            hasTrample = false;
        } else if (Name == "Black Knight") {
            attackPower = 2;
            maxHP = 2;
            color = "Black";
            manaCost = "BB";
            hasFirstStrike = true;
            hasTrample = false;
        } else if (Name == "Orc Maniac") {
            attackPower = 4;
            maxHP = 1;
            color = "Red";
            manaCost = "2R";
            hasFirstStrike = false;
            hasTrample = false;
        } else if (Name == "Hobgoblin") {
            attackPower = 3;
            maxHP = 3;
            color = "Red";
            manaCost = "1RB";
            hasFirstStrike = false;
            hasTrample = false;
        } else if (Name == "Vampire") {
            attackPower = 6;
            maxHP = 3;
            color = "Black";
            manaCost = "3B";
            hasFirstStrike = false;
            hasTrample = false;
        }
    }
    void setIsDestroyed() override {
        if(maxHP <= 0){
            isDestroyed = true;
        }
    }
    void resetHealth(std::string name) override {
        if (name == "Soldier") {
            maxHP = 1;
        } else if (name == "Armored Pegasus") {
            maxHP = 2;
        } else if (name == "White Knight") {
            maxHP = 2;
        } else if (name == "Angry Bear") {
            maxHP = 2;
        } else if (name == "Guard") {
            maxHP = 5;
        } else if (name == "Werewolf") {
            maxHP = 6;
        } else if (name == "Skeleton") {
            maxHP = 1;
        } else if (name == "Ghost") {
            maxHP = 1;
        } else if (name == "Black Knight") {
            maxHP = 2;
        } else if (name == "Orc Maniac") {
            maxHP = 1;
        } else if (name == "Hobgoblin") {
            maxHP = 3;
        } else if (name == "Vampire") {
            maxHP = 3;
        }
    }
    bool isHasBeenBoosted() const override {
        return hasBeenBoosted;
    }

    void setHasBeenBoosted(bool hasBeenBoosted) override {
        hasBeenBoosted = hasBeenBoosted;
    }

    int getAttackPower() override {
        return attackPower;
    }

    void setAttackPower(int aP) override {
        attackPower = aP;
    }
    int getHealth() override {
        return maxHP;
    }
    void setHealth(int hp) override {}
    void sustainDamage(int dmg) override {
        maxHP -= dmg;
    }

    bool getHasTrample() override {
        return hasTrample;
    }

    void setHasTrample(bool hasTrample) override {
        hasTrample = hasTrample;
    }
    bool getHasFirstStrike() override {
        return hasFirstStrike;
    }

    void setHasFirstStrike(bool hasFirstStrike) override{
        hasFirstStrike = hasFirstStrike;
    }

};

class  sorceryCard: public Card{
protected:
    std::string target;
public:
    explicit  sorceryCard(const std::string &n) : Card(n) {
        Type = "Sorcery";
        target = "";
        if(Name=="Disenchant"){
            color="White";
            manaCost="1W";
        }else if(Name=="Lightning Bolt"){
            color="Green";
            manaCost="1G";
        }else if(Name=="Flood"){
            color="Green";
            manaCost="1GW";
        }else if(Name=="Reanimate"){
            color="Black";
            manaCost="B";
        }else if(Name=="Plague"){
            color="Black";
            manaCost="2B";
        }else if(Name=="Terror"){
            color="Black";
            manaCost="1B";
        }
    }
    void setTarget(std::string const  &t) override {
        target = t;
    }
    std::string getTarget() override{
        return target;
    }
};

class enchantmentCard : public Card{
protected:
    std::string target;
public:

    explicit enchantmentCard(const std::string &n) : Card(n) {
        Type = "Enchantment";
        target = "";
        if (Name=="Rage"){
            color="Green";
            manaCost="G";
        }else if(Name=="Holy War"){
            color="White";
            manaCost="1W";
        }else if(Name=="Holy Light"){
            color="White";
            manaCost="1W";
        }else if(Name=="Unholy War"){
            color="Black";
            manaCost="1B";
        }else if(Name=="Restrain"){
            color="Red";
            manaCost="2R";
        }else if(Name=="Slow"){
            color="Black";
            manaCost="B";
        }
    }
    void setTarget(std::string const &t) override {
        target = t;
    }
    std::string getTarget() override{
        return target;
    }
};

class Player{
protected:
    int HP;
    int whiteMana,blackMana,greenMana,redMana,blueMana;
    std::vector<Card> Hand; // Cards in the hand of the player.
    std::vector<Card> Deck; // Cards in the Deck/Library.
    std::vector<Card> InPlay; // Cards in-play pile.
    std::vector<Card> Discards; // Cards in Discard pile.
public:
    Player(){
        whiteMana=0;
        blackMana=0;
        greenMana=0;
        redMana=0;
        blueMana=0;
        HP = 15;
        Deck.reserve(26);
        Hand.reserve(7);
        InPlay.reserve(26);
        Discards.reserve(26);
    }
    Player(const Player &obj){
        whiteMana=obj.whiteMana;
        blackMana=obj.blackMana;
        greenMana=obj.greenMana;
        redMana=obj.redMana;
        blueMana=obj.blueMana;
        HP = obj.HP;

        for(auto &d : obj.Deck){
            Deck.emplace_back(d);
        }
        for(auto &d : obj.Hand){
            Hand.emplace_back(d);
        }
        for(auto &d : obj.InPlay){
            InPlay.emplace_back(d);
        }
        for(auto &d : obj.Discards){
            Discards.emplace_back(d);
        }

    }

    std::vector<Card> getDeck(){
        return Deck;
    }
    int getHp() const {
        return HP;
    }

    void takeDmg(int dmg) {
        HP -= dmg;
    }

    std::vector<Card> getInPlay(){
        return InPlay;
    }
    std::vector<Card> getDiscards(){
        return Discards;
    }

    virtual void DeckForPlayer(){}
    void fill(std::vector<std::string> landNames, std::vector<std::string> creatureNames,
              std::vector<std::string> sorceryNames, std::vector<std::string> enchantmentNames) {

        srand(time(nullptr));
        for (int i = 0; i < 9; i++) {
            std::string random = landNames[rand() % landNames.size()];
            this->Deck.emplace_back((landCard) landCard(random));
        }
        for (int i = 0; i < 10; i++) {
            std::string random = creatureNames[rand() % creatureNames.size()];
            this->Deck.emplace_back(creatureCard(random));
        }
        for (int i = 0; i < 4; i++) {
            std::string random = sorceryNames[rand() % sorceryNames.size()];
            this->Deck.emplace_back(sorceryCard(random));
        }
        for (int i = 0; i < 3; i++) {
            std::string random = enchantmentNames[rand() % enchantmentNames.size()];
            this->Deck.emplace_back(enchantmentCard(random));
        }
        std::random_shuffle(this->Deck.begin(), this->Deck.end());
    }

    void fillHand() {
        for (int i = 26; i > 21; i--) {
            this->Hand.emplace_back(this->Deck.at(i-1));
            this->Hand.back().setIsInHand();
            this->Deck.pop_back();
        }
        if((Hand[0].getType() != "Land" && Hand[1].getType() != "Land" && Hand[2].getType() != "Land"
            && Hand[3].getType() != "Land" && Hand[4].getType() != "Land") ||(Hand[0].getType() == "Land"
                                                                              && Hand[1].getType() == "Land" && Hand[2].getType() == "Land"
                                                                              && Hand[3].getType() == "Land" && Hand[4].getType() == "Land")) {
            for (int i = 4; i >= 0; i--) {
                this->Deck.emplace_back(this->Hand.at(i));
                this->Hand.pop_back();
            }
            std::random_shuffle(this->Deck.begin(), this->Deck.end());
            for (int i = 26; i > 21; i--) {
                this->Hand.emplace_back(this->Deck.at(i-1));
                this->Hand.back().setIsInHand();
                this->Deck.pop_back();
            }
        }
    }
    void draw() {
        int size = Hand.size();
        if (!this->Deck.empty() && Hand.size() < 7 && size == Hand.size()) {
            this->Hand.emplace_back(this->Deck.back());
            this->Hand.back().setIsInHand();
            this->Deck.pop_back();
        }
    }
    void increaseMana(){
        int index;
        std::cout<<"What land mana do you want to tap?";
        printInPlayForLand();
        std::cin>>index;
        if(InPlay.at(index).isUnTapped1()) {
            InPlay.at(index).Tap();
        if (InPlay.at(index).getName() == "Forest") {
            greenMana++;
        } else if (InPlay.at(index).getName() == "Island") {
            blueMana++;
        } else if (InPlay.at(index).getName() == "Mountain") {
            redMana++;
        } else if (InPlay.at(index).getName() == "Plains") {
            whiteMana++;
        } else if (InPlay.at(index).getName() == "Swamp") {
            blackMana++;
        }
        }else{
            std::cout << "Land is already tapped, pick another one: ";
            std::cin >> index;
        }
    }
    void decreaseMana(){
        int index;
        std::string manaType;
        std::cout<<"What land mana do you want to use? you can enter the number of it\n";
        printInPlayForLand();
        std::cin>>index;
        if(InPlay.at(index).isTapped1()) {
            manaType = InPlay.at(index).getName();
            if (manaType == "Forest") {
                greenMana--;
            } else if (manaType == "Island") {
                blueMana--;
            } else if (manaType == "Mountain") {
                redMana--;
            } else if (manaType == "Plains") {
                whiteMana--;
            } else if (manaType == "Swamp") {
                blackMana--;
            } else {
                std::cout << "please choose land type card\n";
            }
        }
    }
    bool checkEnoughMana(const std::vector<Card>::iterator k) {
        int sum;
        sum=0;
        if(k->getMana() =="W" && whiteMana>=1){
           sum = blackMana+redMana+greenMana+blackMana;
            whiteMana--;
            return true;
        }else if (k->getMana() == "1W") {
            sum = blackMana + redMana + greenMana + blackMana;
            if (sum >= 1 && whiteMana >= 1) {
                whiteMana--;
                decreaseMana();
                return true;
            }
        }else if ((k->getMana() =="WW")  && whiteMana>=2){
            whiteMana-=2;
            return true;
        }else if (k->getMana() =="2G"){
            sum = whiteMana + blackMana+redMana+blackMana;
            if(sum>=2 && greenMana >=1) {
                greenMana--;
                decreaseMana();
                decreaseMana();
                return true;
            }
        }else if (k->getMana() =="2WW" && whiteMana >=2){
            sum = greenMana+ blackMana+redMana+blackMana;
            if (sum>=2) {
                whiteMana -= 2;
                decreaseMana();
                decreaseMana();
                return true;
            }
        }else if ((k->getMana() =="2GW") && (whiteMana >=1 && greenMana>=1)){
            sum = blackMana + blueMana + redMana;
            if(sum>=2) {
                whiteMana--;
                greenMana--;
                decreaseMana();
                decreaseMana();
                return true;
            }
        } else  if(k->getMana() =="B" && blackMana>=1){
            blackMana--;
            return true;
        }else if ((k->getMana() == "1B" && blackMana >=1)) {
            sum = whiteMana + redMana + blueMana + greenMana;
            if(sum>=1) {
                blackMana--;
                decreaseMana();
                return true;
            }
        }else if ((k->getMana() =="BB") && blackMana>=2){
            blackMana-=2;
            return true;
        }else if ((k->getMana() =="2R" && redMana >=1)){
            sum = whiteMana + blackMana + blueMana + greenMana;
            if(sum >= 2) {
                redMana--;
                decreaseMana();
                decreaseMana();
                return true;
            }
        }else if ((k->getMana() =="1RB") && (redMana >=1 && blackMana>=1 )){
            sum = whiteMana + blueMana + greenMana;
            if(sum >= 1) {
                redMana--;
                blackMana--;
                decreaseMana();
                return true;
            }
        }else if ((k->getMana() == "3B" && blackMana >=1)) {
            sum = whiteMana + redMana + blueMana + greenMana;
            if(sum >= 3) {
                blackMana--;
                decreaseMana();
                decreaseMana();
                decreaseMana();
                return true;
            }
        }else if ((k->getMana() == "1G" && greenMana >=1)) {
            sum = whiteMana + blackMana + redMana + blackMana;
            if(sum >= 1) {
                greenMana--;
                decreaseMana();
                return true;
            }
        }else if ((k->getMana() =="1GW") && (whiteMana >=1 && greenMana>=1)){
            sum = blackMana + redMana + blueMana;
            if(sum >= 1) {
                greenMana--;
                whiteMana--;
                decreaseMana();
                return true;
            }
        }else if ((k->getMana() =="2B" && blackMana >=1)){
            sum = whiteMana + redMana + blueMana + greenMana;
            if(sum >= 2) {
                blackMana--;
                decreaseMana();
                decreaseMana();
                return true;
            }
        }else  if(k->getMana() =="G" && greenMana>=1){;
            greenMana--;
            return true;
        }
        return false;
    }
    void Play(){
        std::string name = "";
        printHand();
        std::cout << "Which card do you want to play?: ";
        std::getline(std::cin, name);
        for(auto findIndex = Hand.begin(); findIndex != Hand.end(); findIndex++) {
            if (name == findIndex->getName()) {
                if (findIndex->getType() == "Land") {
                    InPlay.emplace_back(*findIndex);
                    InPlay.back().setIsInPlay();
                    Hand.erase(findIndex);
                    std::cout << InPlay.back().getName() << " was played\n";
                    break;
                }
                else if(findIndex->getType() == "Creature"){
                    std::cout<< "Creature's name: " << findIndex->getName() << " Mana cost: " << findIndex->getMana() <<std::endl;
                    increaseMana();
                    if(checkEnoughMana(findIndex)) {
                        InPlay.emplace_back(*findIndex);
                        InPlay.back().setIsInPlay();
                        Hand.erase(findIndex);
                        std::cout <<"  " <<InPlay.back().getName() << " was played\n";
                        break;
                    }else{
                        std::cout << "You don't have enough mana to play this card.\n";
                        break;
                    }
                }else if(findIndex->getType() == "Sorcery"){
                    std::cout<< "Sorcery's name: " << findIndex->getName() << " Mana cost: " << findIndex->getMana() <<std::endl;
                    increaseMana();
                    if(checkEnoughMana(findIndex)) {
                        Discards.emplace_back(*findIndex);
                        Discards.back().setIsInDiscards();
                        Hand.erase(findIndex);
                        std::cout <<"  " << Discards.back().getName() << " was played\n";
                        break;
                    }else{
                        std::cout << "You don't have enough mana to play this card.\n";
                        break;
                    }
                }else if(findIndex->getType() == "Enchantment") {
                    std::cout<< "Enchanment's name: " << findIndex->getName() << " Mana cost: " << findIndex->getMana() <<std::endl;
                    increaseMana();
                    if (checkEnoughMana(findIndex)) {
                        InPlay.emplace_back(*findIndex);
                        InPlay.back().setIsInPlay();
                        Hand.erase(findIndex);
                        std::cout <<"  " << InPlay.back().getName() << " was played\n";
                        break;
                    }else{
                        std::cout << "You don't have enough mana to play this card.\n";
                        break;
                    }
                }
            }
        }

    }
    void moveItToDiscards() {
        for (auto findIndex = InPlay.begin(); findIndex != InPlay.end(); findIndex++) {
            if (findIndex->getHealth() <= 0) {
                Discards.emplace_back(*findIndex);
                InPlay.erase(findIndex);
            }
        }
    }
    bool attack(){
        return true;
    }
    void resetMana(){
        whiteMana = 0;
        blackMana = 0;
        redMana = 0;
        greenMana = 0;
        blueMana = 0;
    }

    void unPlay() {
        if (InPlay.back().getType() == "Land") {
            Hand.emplace_back(InPlay.back());
            InPlay.pop_back();
            std::cout << "You can only play a maximum of 1 land card per round, please choose another card\n";
        }
    }
    void printPlayer(){
        std::cout<<" HP "<< this->getHp();
    }
    virtual void printDeck(){
        std::vector<Card>::iterator d;
        for(d = this->Deck.begin();d != this->Deck.end(); d++){
            d->printName();
        }

    }
    virtual void printHand(){
        std::vector<Card>::iterator f;
        for(f = this->Hand.begin();f != this->Hand.end(); f++){
            f->printName();
        }
    }
    virtual void printInPlay(){
        std::vector<Card>::iterator f;
        for(f = this->InPlay.begin();f != this->InPlay.end(); f++){
            f->printName();
        }
    }
    virtual void printDiscards(){
        std::vector<Card>::iterator f;
        for(f = this->Discards.begin();f != this->Discards.end(); f++){
            f->printName();
        }

    }
    virtual void printInPlayForLand(){
        int index=0;
        std::vector<Card>::iterator f;
        for(f = this->InPlay.begin();f != this->InPlay.end(); f++){
            if(f->getType()== "Land" && f->isUnTapped1()){
                std::cout<<index<<"- ";
                f->printName();
                index++;
            }
        }
    }
};

class player1: public Player {
public:
    player1() : Player() {}

    void DeckForPlayer() override{
        std::vector<std::string>landNames;
        landNames.emplace_back("Plains");
        landNames.emplace_back("Plains");
        landNames.emplace_back("Plains");
        landNames.emplace_back("Plains");
        landNames.emplace_back("Plains");
        landNames.emplace_back("Forest");
        landNames.emplace_back("Forest");
        landNames.emplace_back("Forest");
        landNames.emplace_back("Island");

        std::vector<std::string>creatureNames;
        creatureNames.emplace_back("Soldier");
        creatureNames.emplace_back("Soldier");
        creatureNames.emplace_back("Soldier");
        creatureNames.emplace_back("Armored Pegasus");
        creatureNames.emplace_back("Armored Pegasus");
        creatureNames.emplace_back("White Knight");
        creatureNames.emplace_back("White Knight");
        creatureNames.emplace_back("Angry Bear");
        creatureNames.emplace_back("Guard");
        creatureNames.emplace_back("Werewolf");

        std::vector<std::string>SorceryNames;
        SorceryNames.emplace_back("Disenchant");
        SorceryNames.emplace_back("Lightning Bolt");
        SorceryNames.emplace_back("Flood");
        SorceryNames.emplace_back("Flood");

        std::vector<std::string>enchantmentNames;
        enchantmentNames.emplace_back("Rage");
        enchantmentNames.emplace_back("Holy War");
        enchantmentNames.emplace_back("Holy Light");


        fill(landNames, creatureNames, SorceryNames, enchantmentNames);
    }
    void printDeck() override{
        std::cout<<"---------------------\tDeck for Player 1\t---------------------\n";
        Player::printDeck();
    }
    void printHand() override{
        std::cout << "---------------------\tHand for Player 1\t---------------------\n"<<std::endl;
        Player::printHand();
    }
    void printInPlay() override{
        std::cout << "---------------------\tInPlay for Player 1\t---------------------\n"<<std::endl;
        Player::printInPlay();
    }
    void printDiscards() override{
        std::cout << "---------------------\tDiscards for Player 1\t---------------------\n"<<std::endl;
        Player::printDiscards();
    }
    void printInPlayForLand() override {
        std::cout << "---------------------\tInPlay for Player 1\t---------------------\n" << std::endl;
        Player::printInPlayForLand();
    }
};

class player2: public Player{
public:
    player2():Player() {}
    void DeckForPlayer() override{
        std::vector<std::string>landNames;
        landNames.emplace_back("Swamp");
        landNames.emplace_back("Swamp");
        landNames.emplace_back("Swamp");
        landNames.emplace_back("Swamp");
        landNames.emplace_back("Swamp");
        landNames.emplace_back("Mountain");
        landNames.emplace_back("Mountain");
        landNames.emplace_back("Mountain");
        landNames.emplace_back("Island");

        std::vector<std::string>creatureNames;
        creatureNames.emplace_back("Skeleton");
        creatureNames.emplace_back("Skeleton");
        creatureNames.emplace_back("Skeleton");
        creatureNames.emplace_back("Ghost");
        creatureNames.emplace_back("Ghost");
        creatureNames.emplace_back("Black Knight");
        creatureNames.emplace_back("Black Knight");
        creatureNames.emplace_back("Orc Maniac");
        creatureNames.emplace_back("Hobgoblin");
        creatureNames.emplace_back("Vampire");

        std::vector<std::string>SorceryNames;
        SorceryNames.emplace_back("Reanimate");
        SorceryNames.emplace_back("Plague");
        SorceryNames.emplace_back("Terror");
        SorceryNames.emplace_back("Terror");

        std::vector<std::string>enchantmentNames;
        enchantmentNames.emplace_back("Unholy War");
        enchantmentNames.emplace_back("Restrain");
        enchantmentNames.emplace_back("Slow");

        fill(landNames, creatureNames, SorceryNames, enchantmentNames);

    }
    void printDeck() override{
        std::cout<<"---------------------\tDeck for Player 2\t---------------------\n";
        Player::printDeck();
    }
    void printHand() override{
        std::cout << "---------------------\tHand for Player 2\t---------------------\n"<<std::endl;
        Player::printHand();
    }
    void printInPlay() override{
        std::cout << "---------------------\tInPlay for Player 2\t---------------------\n"<<std::endl;
        Player::printInPlay();
    }
    void printDiscards() override{
        std::cout << "---------------------\tDiscards for Player 2\t---------------------\n"<<std::endl;
        Player::printDiscards();
    }
    void printInPlayForLand() override {
        std::cout << "---------------------\tInPlay for Player 2\t---------------------\n" << std::endl;
        Player::printInPlayForLand();
    }
};

class effect: public Player{
public:

    effect():Player(){}
    virtual void destroyCard(std::vector<Card> inPlayVec,std::string spellName,std::string target){}
};
class gameStatus : public effect{
public:
    gameStatus():effect(){}
    bool Lose(std::unique_ptr<player1> &p1,std::unique_ptr<player2> &p2){
        if(p1->getDeck().empty() || p1->getHp() <=0){
            std::cout << "Player 1 has lost with  ";
            p1->printPlayer();
            return true;
        }else if(p2->getDeck().empty()|| p2->getHp()<=0){
            std::cout << "Player 2 has lost with ";
            p2->printPlayer();
            return true;
        }
        return false;
    }
    bool Win(std::unique_ptr<player1> &p1,std::unique_ptr<player2> &p2){
        if((p1->getHp() > 0 && p2->getHp() <=0) || p2->getDeck().empty()){
            std::cout << "Player 1 has won with " ;
            p1->printPlayer();
            Lose(p1,p2);
            return true;
        }else if((p2->getHp() > 0 && p1->getHp() <= 0) || p1->getDeck().empty()){
            std::cout << "Player 2 has won with  ";
            p2->printPlayer();
            Lose(p1,p2);
            return true;
        }
        return false;
    }
};
class ability : public effect{
public:
    ability():effect(){}
    void loseFirstStrike(std::vector<Card> inPlayVec, std::string target){
        for(auto findIndex = inPlayVec.begin(); findIndex != inPlayVec.end(); findIndex++){
            if ( findIndex->getType() == "Creature" && findIndex->getName() == target) {
                findIndex->setHasFirstStrike(false);
            }
        }
    }
    void loseTrample(std::vector<Card> inPlayVec) {
        for(auto findIndex = inPlayVec.begin(); findIndex != inPlayVec.end(); findIndex++){
            if ( findIndex->getType() == "Creature" && findIndex->getColor() == "Green") {
                if (findIndex->getHasTrample()) {
                    findIndex->setHasTrample(false);
                }
            }
        }
    }
    void gainTrample(std::vector<Card> inPlayVec, std::string target){
        for(auto findIndex = inPlayVec.begin(); findIndex != inPlayVec.end(); findIndex++){
            if ( findIndex->getType() == "Creature" && findIndex->getName() == target) {
                findIndex->setHasTrample(true);
            }
        }
    }
};
class power : public effect{
public:
    power():effect(){}
    void gainPower(std::vector<Card> inPlayVec, std::string name) {
        for (auto findIndex = inPlayVec.begin(); findIndex != inPlayVec.end(); findIndex++) {
            if(name == "Holy War") {
                if (findIndex->getType() == "Creature" && findIndex->getColor() == "White") {
                    findIndex->setAttackPower(findIndex->getAttackPower() + 1);
                    findIndex->setHealth(findIndex->getHealth() + 1);
                    findIndex->setHasBeenBoosted(true);
                }
            }else if(name == "Unholy War"){
                if (findIndex->getType() == "Creature" && findIndex->getColor() == "Black") {
                    findIndex->setAttackPower(findIndex->getAttackPower() + 2);
                    findIndex->setHasBeenBoosted(true);
                }
            }
        }
    }
    void revertGainPower(std::vector<Card> inPlayVec){
        for (auto findIndex = inPlayVec.begin(); findIndex != inPlayVec.end(); findIndex++) {
            if (findIndex->getType() == "Creature" && findIndex->getColor() == "Black" &&
                findIndex->isHasBeenBoosted()) {
                findIndex->setAttackPower(findIndex->getAttackPower() - 2);
                findIndex->setHasBeenBoosted(false);
            }
        }
    }
    void losePower(std::vector<Card> inPlayVec) {
        for (auto findIndex = inPlayVec.begin(); findIndex != inPlayVec.end(); findIndex++) {
            if (findIndex->getType() == "Creature" && findIndex->getColor() == "Black") {
                findIndex->setAttackPower(findIndex->getAttackPower() - 1);
                findIndex->setHealth(findIndex->getHealth() - 1);
            }
        }
    }
};
class DestroyCreatureEffect: public effect{
public:
    DestroyCreatureEffect():effect(){}
    void destroyCard(std::vector<Card> inPlayVec,std::string spellName,std::string target) {
        if (spellName == "Terror") {
            for (auto findIndex = inPlayVec.begin(); findIndex != inPlayVec.end(); findIndex++) {
                if (findIndex->getName() == target) {
                    Discards.emplace_back(*findIndex);
                    Discards.back().setIsInDiscards();
                    InPlay.erase(findIndex);
                    std::cout << "Target Creature card destroyed" << std::endl;
                    break;
                }
            }
        }
    }
};
class DestroyLandEffect: public effect{
public:
    DestroyLandEffect() : effect(){}
    void destroyCard(std::vector<Card> inPlayVec,std::string spellName,std::string target) {
        if(spellName == "Flood") {
            for (auto findIndex=inPlayVec.begin(); findIndex != inPlayVec.end(); findIndex++) {
                if (findIndex->getName() == target) {
                    Discards.emplace_back(*findIndex);
                    Discards.back().setIsInDiscards();
                    InPlay.erase(findIndex);
                    std::cout << "Target Land card destroyed" << std::endl;
                    break;
                }
            }
        }
    }
};
class DestroyEnchantmentEffect: public effect{
public:
    DestroyEnchantmentEffect(): effect(){}
    void destroyCard(std::vector<Card> inPlayVec,std::string spellName,std::string target){
        if(spellName == "Disenchant") {
            for (auto findIndex=inPlayVec.begin(); findIndex != inPlayVec.end(); findIndex++) {
                if (findIndex->getName() == target) {
                    Discards.emplace_back(*findIndex);
                    Discards.back().setIsInDiscards();
                    InPlay.erase(findIndex);
                    std::cout << "Target Enchantment card destroyed" << std::endl;
                    break;
                }
            }
        }
    }
};
class DamageEffect: public effect{
public:
    DamageEffect():effect(){}
    void damageCard(std::vector<Card> inPlayVec,std::string spellName, std::string target) {
        if (spellName == "Lightning Bolt" && target != "player") {
            for (auto findIndex = inPlayVec.begin(); findIndex != inPlayVec.end(); findIndex++) {
                if (findIndex->getName() == target && findIndex->getType() == "Creature") {
                    Discards.emplace_back(*findIndex);
                    Discards.back().setIsInDiscards();
                    InPlay.erase(findIndex);
                    std::cout << "Target Creature suffered 2 damage" << std::endl;
                    break;
                }
            }
        }
    }
    void damageAllCreatures(std::vector<Card> inPlayVec){
        for (auto findIndex = inPlayVec.begin(); findIndex != inPlayVec.end(); findIndex++) {
            if (findIndex->getType() == "Creature") {
                findIndex->setHealth(findIndex->getHealth() - 1);
            }
        }
    }
    void damagePlayer(std::unique_ptr<player2> &p2){
        p2->takeDmg(2);
    }
};
class ReAnimateEffect: public effect{
public:
    ReAnimateEffect(): effect(){}
    void reAnimate(std::vector<Card>discard, std::string target){
        int i = 0;
        for (auto get=discard.begin();get!=discard.end();get++) {
            if(get->getName() == target){
                if(Hand.size() < 7) {
                    Hand.emplace_back(Discards.at(i));
                    Hand.back().setIsInHand();
                    Discards.erase(get);
                    break;
                }else{
                    std::cout <<"You cannot add card. Your hand is full" <<std::endl;
                }
            }else{
                i++;
            }
        }
    }
};
void sufferDamage(std::vector<Card> p1Inplay,std::vector<Card> p2Inplay, bool p1attacks,bool p2attacks, std::unique_ptr<player1> &p1, std::unique_ptr<player2> &p2) {
    std::vector<Card>::iterator victim;
    std::vector<Card>::iterator attacker;
    if (p1attacks) {
        std::string wantsToDefend = " ";
        int defenderIndex = 0;
        for (victim = p2Inplay.begin(); victim != p2Inplay.end(); victim++) {
            if (victim->getType() == "Creature" && victim->isUnTapped1()) {
                for (attacker = p1Inplay.begin(); attacker != p1Inplay.end(); attacker++) {
                    if (attacker->getType() == "Creature" && attacker->isTapped1()) {
                        std::cout << "You're being attacked by: ";
                        attacker->printCreatureInfo();
                        std::cout << "Do you want to defend?: ";
                        std::cin >> wantsToDefend;
                        if (wantsToDefend == "yes") {
                            std::cout << "Which card do you want to defend with?: ";
                            for (victim; victim != p2Inplay.end(); victim++) {
                                if (victim->getType() == "Creature") {
                                    victim->printCreatureInfo();
                                }
                            }
                            std::cin >> defenderIndex;
                            if (attacker->getHasTrample() && attacker->getHasFirstStrike() &&
                                !victim[defenderIndex].getHasFirstStrike()) {
                                int dmg = (attacker->getAttackPower() - victim[defenderIndex].getHealth());
                                std::cout << "Player 1 attacked using: " << attacker->getName() <<
                                          ", Player 2 defended using: " << victim[defenderIndex].getName();
                                victim[defenderIndex].sustainDamage(attacker->getAttackPower());
                                p2->moveItToDiscards();
                                if(!victim[defenderIndex].hasBeenDestroyed()){
                                    victim[defenderIndex].resetHealth(victim[defenderIndex].getName());
                                }
                                p2->takeDmg(dmg);
                            } else if (attacker->getHasTrample() && attacker->getHasFirstStrike() &&
                                       victim[defenderIndex].getHasFirstStrike()) {
                                int dmg = (attacker->getAttackPower() - victim[defenderIndex].getHealth());
                                victim[defenderIndex].sustainDamage(attacker->getAttackPower());
                                attacker->sustainDamage(victim[defenderIndex].getAttackPower());
                                std::cout << "Player 1 attacked using: " << attacker->getName() <<
                                          ", Player 2 defended using: " << victim[defenderIndex].getName();
                                p2->moveItToDiscards();
                                if(!victim[defenderIndex].hasBeenDestroyed()){
                                    victim[defenderIndex].resetHealth(victim[defenderIndex].getName());
                                }
                                p1->moveItToDiscards();
                                if(!attacker->hasBeenDestroyed()){
                                    attacker->resetHealth(attacker->getName());
                                }
                                p2->takeDmg(dmg);
                            } else if (!attacker->getHasTrample() && attacker->getHasFirstStrike() &&
                                       !victim[defenderIndex].getHasFirstStrike()) {
                                victim[defenderIndex].sustainDamage(attacker->getAttackPower());
                                std::cout << "Player 1 attacked using: " << attacker->getName() <<
                                          ", Player 2 defended using: " << victim[defenderIndex].getName();
                                p2->moveItToDiscards();
                                if(!victim[defenderIndex].hasBeenDestroyed()){
                                    victim[defenderIndex].resetHealth(victim[defenderIndex].getName());
                                }
                            } else if (!attacker->getHasTrample() && !attacker->getHasFirstStrike() &&
                                       victim[defenderIndex].getHasFirstStrike()) {
                                attacker->sustainDamage(victim[defenderIndex].getAttackPower());
                                std::cout << "Player 1 attacked using: " << attacker->getName() <<
                                          ", Player 2 defended using: " << victim[defenderIndex].getName();
                                p1->moveItToDiscards();
                                if(!attacker->hasBeenDestroyed()){
                                    attacker->resetHealth(attacker->getName());
                                }
                            } else {
                                victim[defenderIndex].sustainDamage(attacker->getAttackPower());
                                attacker->sustainDamage(victim[defenderIndex].getAttackPower());
                                std::cout << "Player 1 attacked using: " << attacker->getName() <<
                                          ", Player 2 defended using: " << victim[defenderIndex].getName();
                                p2->moveItToDiscards();
                                if(!victim[defenderIndex].hasBeenDestroyed()){
                                    victim[defenderIndex].resetHealth(victim[defenderIndex].getName());
                                }
                                p1->moveItToDiscards();
                                if(!attacker->hasBeenDestroyed()){
                                    attacker->resetHealth(attacker->getName());
                                }
                            }
                        }else if (wantsToDefend == "No") {
                            int dmg = attacker->getAttackPower();
                            p2->takeDmg(dmg);
                        }
                    }
                }
            } else if ((victim->getType() == "Creature" && victim->isTapped1()) || victim->getType() != "Creature") {
                for (attacker; attacker != p1Inplay.end(); attacker++) {
                    if (attacker->getType() == "Creature" && attacker->isTapped1()) {
                        int dmg = attacker->getAttackPower();
                        p2->takeDmg(dmg);
                    }
                }
            }
        }
    } else if(p2attacks) {
        std::string wantsToDefend = " ";
        int defenderIndex = 0;
        for (victim = p1Inplay.begin(); victim != p1Inplay.end(); victim++) {
            if (victim->getType() == "Creature" && victim->isUnTapped1()) {
                for (attacker = p2Inplay.begin(); attacker != p2Inplay.end(); attacker++) {
                    if (attacker->getType() == "Creature" && attacker->isTapped1()) {
                        std::cout << "You're being attacked by: ";
                        attacker->printCreatureInfo();
                        std::cout << "Do you want to defend?: ";
                        std::cin >> wantsToDefend;
                        if (wantsToDefend == "Yes") {
                            std::cout << "Which card do you want to defend with?: ";
                            for (victim; victim != p1Inplay.end(); victim++) {
                                if (victim->getType() == "Creature") {
                                    victim->printCreatureInfo();
                                }
                            }
                            std::cin >> defenderIndex;
                            if (attacker->getHasTrample() && attacker->getHasFirstStrike() &&
                                victim[defenderIndex].getHasFirstStrike()) {
                                int dmg = (attacker->getAttackPower() - victim[defenderIndex].getHealth());
                                victim[defenderIndex].sustainDamage(attacker->getAttackPower());
                                attacker->sustainDamage(victim[defenderIndex].getAttackPower());
                                std::cout << "Player 2 attacked using: " << attacker->getName() <<
                                          ", Player 1 defended using: " << victim[defenderIndex].getName();
                                p2->moveItToDiscards();
                                p1->moveItToDiscards();
                                p1->takeDmg(dmg);
                            } else if (!attacker->getHasTrample() && attacker->getHasFirstStrike() &&
                                       !victim[defenderIndex].getHasFirstStrike()) {
                                victim[defenderIndex].sustainDamage(attacker->getAttackPower());
                                std::cout << "Player 2 attacked using: " << attacker->getName() <<
                                          ", Player 1 defended using: " << victim[defenderIndex].getName();
                                p1->moveItToDiscards();
                            } else if (!attacker->getHasTrample() && !attacker->getHasFirstStrike() &&
                                       victim[defenderIndex].getHasFirstStrike()) {
                                attacker->sustainDamage(victim[defenderIndex].getAttackPower());
                                std::cout << "Player 2 attacked using: " << attacker->getName() <<
                                          ", Player 1 defended using: " << victim[defenderIndex].getName();
                                p2->moveItToDiscards();
                            } else {
                                victim[defenderIndex].sustainDamage(attacker->getAttackPower());
                                attacker->sustainDamage(victim[defenderIndex].getAttackPower());
                                std::cout << "Player 2 attacked using: " << attacker->getName() <<
                                          ", Player 1 defended using: " << victim[defenderIndex].getName();
                                p2->moveItToDiscards();
                                p1->moveItToDiscards();
                            }
                        } else if (wantsToDefend == "No") {
                            int dmg = attacker->getAttackPower();
                            p1->takeDmg(dmg);
                        }
                    }
                }
            } else if ((victim->getType() == "Creature" && victim->isTapped1()) || victim->getType() != "Creature") {
                for (attacker; attacker != p2Inplay.end(); attacker++) {
                    if (attacker->getType() == "Creature" && attacker->isTapped1()) {
                        int dmg = attacker->getAttackPower();
                        p1->takeDmg(dmg);
                    }
                }
            }
        }
    }
}
void Game() {
    std::shared_ptr<gameStatus> gS = std::make_shared<gameStatus>();
    std::unique_ptr<player1> p1 = std::make_unique<player1>();
    std::unique_ptr<player2> p2 = std::make_unique<player2>();
    std::shared_ptr<ability> a = std::make_shared<ability>();
    std::shared_ptr<power> p = std::make_shared<power>();
    std::shared_ptr<DestroyCreatureEffect> DCE = std::make_shared<DestroyCreatureEffect>();
    std::shared_ptr<DestroyLandEffect> DLE = std::make_shared<DestroyLandEffect>();
    std::shared_ptr<DestroyEnchantmentEffect> DEE = std::make_shared<DestroyEnchantmentEffect>();
    std::shared_ptr<DamageEffect> DE = std::make_shared<DamageEffect>();
    std::shared_ptr<ReAnimateEffect> RE = std::make_shared<ReAnimateEffect>();
    p1->DeckForPlayer();
    p1->fillHand();
    p2->DeckForPlayer();
    p2->fillHand();
    bool playedLandInPhaseThree = false;
    std::string wantsToAttack = "";
    bool p1Attacks = false;
    bool p2Attacks = false;
    std::string attacker = "";
    int RoundCounter = 1 ;
    for(int i = 0; i<=RoundCounter; i++){
        int Phase = 2;
        int turn = 1;
        std::cout << "Player 1's HP: " << p1->getHp() << std::endl;
        if(RoundCounter > 1) {
            p1->draw();
        }
        p1->printHand();
        p1->printInPlay();
        std::cout << "Player 2's HP: " << p2->getHp() << std::endl;
        if(RoundCounter > 1) {
            p2->draw();
        }
        p2->printHand();
        p2->printInPlay();
        if (turn == 1) {
            if (RoundCounter != 1 && Phase == 2) {
                for (auto player1InPlay = p1->getInPlay().begin();
                     player1InPlay != p1->getInPlay().end(); player1InPlay++) {
                     player1InPlay->unTap();
                }
            }
            if(RoundCounter == 1) {
                std::cout << "Please play a land card first\n";
            }
            Phase = 3;
            if (Phase == 3) {
                p1->Play();
                    if (p1->getInPlay().back().getType() == "Creature") {
                        for (auto findIndex = p1->getInPlay().begin();
                             findIndex != p1->getInPlay().end(); findIndex++) {
                            if (findIndex->getName() == "Holy War") {
                                p->gainPower(p1->getInPlay(), findIndex->getName());
                            }
                        }
                    } else if (p1->getInPlay().back().getType() == "Land") {
                        playedLandInPhaseThree = true;
                    }
                    else if (p1->getDiscards().back().getType() == "Sorcery") {
                        if (p1->getDiscards().back().getName() == "Disenchant") {
                            std::string target = "";
                            p2->printInPlay();
                            std::cout << "Select target name: ";
                            std::cin >> target;
                            p1->getInPlay().back().setTarget(target);
                            DEE->destroyCard(p2->getInPlay(), "Disenchant", target);
                            if (target == "Unholy War") {
                                p->revertGainPower(p2->getInPlay());
                            }
                        } else if (p1->getDiscards().back().getName() == "Lightning Bolt") {
                            std::string target = "";
                            p2->printInPlay();
                            std::cout << "Select target name (either creature's name or player): ";
                            std::cin >> target;
                            p1->getInPlay().back().setTarget(target);
                            if (target == "player") {
                                DE->damagePlayer(p2);
                            } else {
                                DE->damageCard(p2->getInPlay(), p1->getInPlay().back().getName(), target);
                            }
                        } else if (p1->getDiscards().back().getName() == "Flood") {
                            std::string target = "";
                            p2->printInPlay();
                            std::cout << "Select target name: ";
                            std::cin >> target;
                            p1->getInPlay().back().setTarget(target);
                            DLE->destroyCard(p2->getInPlay(), "Flood", target);
                        }
                    } else if (p1->getInPlay().back().getType() == "Enchantment") {
                        if (p1->getInPlay().back().getName() == "Rage") {
                            std::string target = "";
                            p1->printInPlay();
                            std::cout << "Select target name: ";
                            std::cin >> target;
                            p1->getInPlay().back().setTarget(target);
                            a->gainTrample(p1->getInPlay(), target);
                        } else if (p1->getInPlay().back().getName() == "Holy War") {
                            p->gainPower(p1->getInPlay(), p1->getInPlay().back().getName());
                        } else if (p1->getInPlay().back().getName() == "Holy Light") {
                            p->losePower(p2->getInPlay());
                        }
                    }
                }
            Phase = 4;
            if (Phase == 4) {
                if (RoundCounter == 1) {
                    Phase = 5;
                } else if (RoundCounter > 1) {
                    std::cout << "Do you want to attack? ";
                    std::cin >> wantsToAttack;
                    if (wantsToAttack == "yes") {
                        p1Attacks = p1->attack();
                        for (auto player1InPlay = p1->getInPlay().begin();
                             player1InPlay != p1->getInPlay().end(); player1InPlay++) {
                            if (player1InPlay->getType() == "Creature") {
                                std::cout << "Do you want to attack with " << player1InPlay->getName() << std::endl;
                                std::cin >> attacker;
                                if (attacker == "yes"){
                                    player1InPlay->Tap();
                                } else if (attacker == "no") {
                                    continue;
                                }
                            }
                        }
                        sufferDamage(p1->getInPlay(), p2->getInPlay(), p1Attacks, p2Attacks, p1, p2);
                    } else if (wantsToAttack == "no") {
                        Phase = 5;
                    }
                }
            }
            Phase = 5;
            if (Phase == 5) {
                int numberToPlay = 1;
                std::string wantsToPlayMore = "";
                p1->Play();
                for(int k = 0; k < numberToPlay; k++){
                    if(numberToPlay > 1){
                        p1->Play();
                    }
                    if (playedLandInPhaseThree) {
                        p1->Play();
                    } else if (p1->getDiscards().back().getType() == "Sorcery") {
                        if (p1->getDiscards().back().getName() == "Disenchant") {
                            std::string target = "";
                            p2->printInPlay();
                            std::cout << "Select target name: ";
                            std::cin >> target;
                            p1->getInPlay().back().setTarget(target);
                            DEE->destroyCard(p2->getInPlay(), "Disenchant", target);
                            if (target == "Unholy War") {
                                p->revertGainPower(p2->getInPlay());
                            }
                        } else if (p1->getDiscards().back().getName() == "Lightning Bolt") {
                            std::string target = "";
                            p2->printInPlay();
                            std::cout << "Select target name (either creature's name or player): ";
                            std::cin >> target;
                            p1->getInPlay().back().setTarget(target);
                            if (target == "player") {
                                DE->damagePlayer(p2);
                            } else {
                                DE->damageCard(p2->getInPlay(), p1->getInPlay().back().getName(), target);
                            }
                        } else if (p1->getDiscards().back().getName() == "Flood") {
                            std::string target = "";
                            p2->printInPlay();
                            std::cout << "Select target name: ";
                            std::cin >> target;
                            p1->getInPlay().back().setTarget(target);
                            DLE->destroyCard(p2->getInPlay(), "Flood", target);
                        }
                    } else if (p1->getInPlay().back().getType() == "Enchantment") {
                        if (p1->getInPlay().back().getName() == "Rage") {
                            std::string target = "";
                            p1->printInPlay();
                            std::cout << "Select target name: ";
                            std::cin >> target;
                            p1->getInPlay().back().setTarget(target);
                            a->gainTrample(p1->getInPlay(), target);
                        } else if (p1->getInPlay().back().getName() == "Holy War") {
                            p->gainPower(p1->getInPlay(), p1->getInPlay().back().getName());
                        } else if (p1->getInPlay().back().getName() == "Holy Light") {
                            p->losePower(p2->getInPlay());
                        }
                    }
                    std::cout << "Do you want to play another card?";
                    std::cin >> wantsToPlayMore;
                    if(wantsToPlayMore == "yes"){
                        numberToPlay++;
                    }
                    if(wantsToPlayMore == "no"){
                        break;
                    }
                }
            }
            Phase = 6;
            if (Phase == 6) {
                p1->resetMana();
                playedLandInPhaseThree = false;
                turn = 2;
                Phase = 2;
            }
        }
        if (turn == 2) {
            Phase = 2;
            if (RoundCounter != 1 && Phase == 2) {
                for (auto player2InPlay = p2->getInPlay().begin();
                     player2InPlay != p2->getInPlay().end(); player2InPlay++) {
                     player2InPlay->unTap();
                }
            }else if(RoundCounter == 1 && Phase == 2) {
                std::cout << "Please play a land card first\n";
            }
            Phase = 3;
            if (Phase == 3) {
                p2->Play();
                    p2->Play();
                    if (p2->getInPlay().back().getType() == "Creature") {
                        for (auto findIndex = p2->getInPlay().begin();
                             findIndex != p2->getInPlay().end(); findIndex++) {
                            if (findIndex->getName() == "Unholy War") {
                                p->gainPower(p2->getInPlay(), findIndex->getName());
                            }else{
                                continue;
                            }
                        }
                    } else if (p2->getInPlay().back().getType() == "Land") {
                        playedLandInPhaseThree = true;
                    }else if (p2->getDiscards().back().getType() == "Sorcery") {
                        if (p2->getDiscards().back().getName() == "Reanimate") {
                            std::string target = "";
                            p2->printDiscards();
                            std::cout << "Select target name: ";
                            std::cin >> target;
                            p2->getInPlay().back().setTarget(target);
                            RE->reAnimate(p2->getDiscards(), target);
                        }else if (p2->getDiscards().back().getName() == "Plague") {
                            DE->damageAllCreatures(p1->getInPlay());
                        }else if (p2->getDiscards().back().getName() == "Terror") {
                            std::string target = "";
                            p1->printInPlay();
                            std::cout << "Select target name: ";
                            std::cin >> target;
                            DCE->destroyCard(p1->getInPlay(), "Terror", target);
                        }
                    } else if (p1->getInPlay().back().getType() == "Enchantment") {
                        if (p2->getInPlay().back().getName() == "Unholy War") {
                            p->gainPower(p2->getInPlay(), p2->getInPlay().back().getName());
                        } else if (p2->getInPlay().back().getName() == "Restrain") {
                            a->loseTrample(p1->getInPlay());
                        } else if (p2->getInPlay().back().getName() == "Slow") {
                            std::string target = "";
                            p1->printInPlay();
                            std::cout << "Select target name: ";
                            std::cin >> target;
                            a->loseFirstStrike(p1->getInPlay(), target);
                        }
                    }
                }
            Phase = 4;
            if (Phase == 4) {
                if (RoundCounter == 1) {
                    Phase = 5;
                } else if (RoundCounter > 1) {
                    std::cout << "Do you want to attack? ";
                    std::cin >> wantsToAttack;
                    if (wantsToAttack == "yes") {
                        p2Attacks = p2->attack();
                        for (auto player2InPlay = p2->getInPlay().begin();
                             player2InPlay != p2->getInPlay().end(); player2InPlay++) {
                            if (player2InPlay->getType() == "Creature") {
                                std::cout << "Do you want to attack with " << player2InPlay->getName() << std::endl;
                                std::cin >> attacker;
                                if (attacker == "yes"){
                                    player2InPlay->Tap();
                                } else if (attacker == "no") {
                                    continue;
                                }
                            }
                        }
                        sufferDamage(p1->getInPlay(), p2->getInPlay(), p1Attacks, p2Attacks, p1, p2);
                    } else if (wantsToAttack == "no") {
                        p2Attacks = false;
                        Phase = 5;
                    }
                }
            }
            Phase = 5;
            if (Phase == 5) {
                int numberToPlay = 1;
                std::string wantsToPlayMore = "";
                for(int j = 0; j < numberToPlay; j++){
                    p2->Play();
                    if (playedLandInPhaseThree) {
                        p2->Play();
                    }else if (p2->getInPlay().back().getType() == "Creature") {
                        for (auto findIndex = p2->getInPlay().begin();
                             findIndex != p2->getInPlay().end(); findIndex++) {
                            if (findIndex->getName() == "Unholy War") {
                                p->gainPower(p2->getInPlay(), findIndex->getName());
                            }
                        }
                    } else if (p2->getInPlay().back().getType() == "Land") {
                        playedLandInPhaseThree = true;
                    } else if(playedLandInPhaseThree && j > 0) {
                        p2->Play();
                        p2->unPlay();
                    }else if (p2->getDiscards().back().getType() == "Sorcery") {
                        if (p2->getDiscards().back().getName() == "Reanimate") {
                            std::string target = "";
                            p2->printDiscards();
                            std::cout << "Select target name: ";
                            std::cin >> target;
                            p2->getInPlay().back().setTarget(target);
                            RE->reAnimate(p2->getDiscards(), target);
                        }else if (p2->getDiscards().back().getName() == "Plague") {
                            DE->damageAllCreatures(p1->getInPlay());
                        }else if (p2->getDiscards().back().getName() == "Terror") {
                            std::string target = "";
                            p1->printInPlay();
                            std::cout << "Select target name: ";
                            std::cin >> target;
                            DCE->destroyCard(p1->getInPlay(), "Terror", target);
                        }
                    } else if (p1->getInPlay().back().getType() == "Enchantment") {
                        if (p2->getInPlay().back().getName() == "Unholy War") {
                            p->gainPower(p2->getInPlay(), p2->getInPlay().back().getName());
                        } else if (p2->getInPlay().back().getName() == "Restrain") {
                            a->loseTrample(p1->getInPlay());
                        } else if (p2->getInPlay().back().getName() == "Slow") {
                            std::string target = "";
                            p1->printInPlay();
                            std::cout << "Select target name: ";
                            std::cin >> target;
                            a->loseFirstStrike(p1->getInPlay(), target);
                        }
                    }
                    std::cout << "Do you want to play another card?";
                    std::cin >> wantsToPlayMore;
                    if(wantsToPlayMore == "yes"){
                        numberToPlay++;
                    }
                    if(wantsToPlayMore == "no"){
                        break;
                    }
                }
            }
            Phase = 6;
            if (Phase == 6) {
                p2->resetMana();
                playedLandInPhaseThree = false;
            }
            RoundCounter++;
            std::cout << "End of Round: " << RoundCounter << std::endl;
        }
        if(gS->Win(p1,p2)) {
            break;
        }else{
            continue;
        }
    }
}
int main() {
    Game();
    return 0;
}
