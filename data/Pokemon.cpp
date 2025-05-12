#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include<SFML/Audio/Sound.hpp>
#include<SFML/Window/Mouse.hpp>
#include<SFML/Window/Cursor.hpp>
#include <SFML/Window.hpp>
#include <optional>

using namespace std;


static const vector<string> typeNames = { "Normal",
    "Feu", "Eau","electrik", "Plante",  "Glace", "Combat", "Poison",
    "Sol", "Vol", "Psy", "Insecte", "Roche", "Spectre", "Dragon",
    "Tenebres", "Acier", "Fee"
};
bool gagnerbadge=false;
bool gagnercombat=false;
bool perdrecombat=false;
class Type {
    private:
        std::string nom;
        int numero; 

    
    public:
    float matrice[18][18] = {
        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 0.0, 1.0, 1.0, 0.5, 1.0},
        {1.0, 0.5, 0.5, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 1.0, 2.0, 1.0},
        {1.0, 2.0, 0.5, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 1.0, 1.0},
        {1.0, 1.0, 2.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0},
        {1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 1.0, 0.5, 2.0, 0.5, 1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 0.5, 1.0},
        {1.0, 0.5, 0.5, 1.0, 2.0, 0.5, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0},
        {2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 0.5, 0.5, 0.5, 2.0, 0.0, 1.0, 2.0, 2.0, 0.5},
        {1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 0.0, 2.0},
        {1.0, 2.0, 1.0, 2.0, 0.5, 1.0, 1.0, 2.0, 1.0, 0.0, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 2.0, 1.0},
        {1.0, 1.0, 1.0, 0.5, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 0.5, 1.0},
        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 0.0, 0.5, 1.0},
        {1.0, 0.5, 1.0, 1.0, 2.0, 1.0, 0.5, 0.5, 1.0, 0.5, 2.0, 1.0, 1.0, 0.5, 1.0, 2.0, 0.5, 0.5},
        {1.0, 2.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0},
        {0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 1.0},
        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 0.0},
        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 0.5},
        {1.0, 0.5, 0.5, 0.5, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.5, 2.0},
        {1.0, 0.5, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 0.5, 1.0}
    };
    


    
        Type(const std::string& nom,int numero)
        : nom(nom), numero(numero) {} 
    
        const std::string& getNom() const { return nom; }
        int getNumero() const { return numero; }
        float matricepokemon(Type i){return matrice[i.getNumero()][numero];}

};



class Pokemon {
    private:
    string name;      
    vector<Type> types;   
    int hp;                   
    string attackName;    
    int attackDamage;  

    public:
 
        Pokemon(string name, vector<Type> types, int hp,string attackName, int attackDamage)
             :name(name), types(types), hp(hp), attackName(attackName), attackDamage(attackDamage) {}
    
  
        string getName() const { return name; }
    
        int getHp() const { return hp; }
        string getAttackName() const { return attackName; }
        vector<Type> gettype() const{ { return types; }}
        int getAttackDamage() const { return attackDamage; }
        void setattackdamage(int a){attackDamage=a;}
        void sethp(int h){hp=h;}
      

        void receiveDamage(int damage) {
            hp -= damage;
            if (hp < 0) hp = 0;  
        }
    

        void printInfo() const {
            std::cout << "Pokemon: " << name << "\n"
                      << "PV: " << hp << "\n"
                      << "type: ";
            for (const Type& t : types) {
                std::cout << t.getNom() << " ";
            }
            std::cout << "\nAttack: " << attackName << " (Damage: " << attackDamage << ")\n";
        }
    
       
    };



class Entraineur {
    protected:
        std::string nom;
        std::vector<Pokemon> equipe;
    public:
        Entraineur(const std::string& nom,std::vector<Pokemon>equipe) : nom(nom),equipe(equipe) {}
    
        virtual void ajouterPokemon(Pokemon p) {
            if (equipe.size() < 6) {
                equipe.push_back(p);
            } else {
                std::cout << "L'équipe est pleine!" << std::endl;
            }
        }
    
        virtual void afficherEquipe() const {
            std::cout << "Équipe de " << nom << " :" << std::endl;
            for (const auto& p : equipe) {
                std::cout << p.getName() << std::endl;
            }
        }
    
        std::string getNom() const { return nom; }
         std::vector<Pokemon>& getEquipe()  { return equipe; }
    };
    
    class Joueur : public Entraineur {
    private:
        int badges;
        int combatsGagnes;
        int combatsPerdus;
    public:
        Joueur(const std::string& nom,const vector<Pokemon>equipe) : Entraineur(nom,equipe), badges(0), combatsGagnes(0), combatsPerdus(0) {}
    
        void gagnerCombat() {
            combatsGagnes++;
        }
    
        void perdreCombat() {
            combatsPerdus++;
        }
    
        void gagnerBadge() {
            badges++;
        }
        
        int getBadge(){return badges;}
    
        void afficherStats() const {
            std::cout << "Joueur " << nom << " : " << std::endl;
            std::cout << "Badges : " << badges << std::endl;
            std::cout << "Combats gagnés : " << combatsGagnes << std::endl;
            std::cout << "Combats perdus : " << combatsPerdus << std::endl;
        }
    };
    
    class LeaderDeGym : public Entraineur {
    private:
        std::string badge;
        std::string gymnase;
    public:
        LeaderDeGym(const std::string& nom,vector<Pokemon>equipe,const std::string& badge, const std::string& gymnase) 
            : Entraineur(nom,equipe), badge(badge), gymnase(gymnase) {}
    string getBadge(){return badge;}
    string getGymnase(){return gymnase;}

        void afficherBadge() const {
            std::cout << nom << " possède le badge " << badge << " du gymnase " << gymnase << "." << std::endl;
        }
    
        void afficherGymnase() const {
            std::cout << nom << " est le leader du gymnase " << gymnase << "." << std::endl;
        }
    };
    
    class MaîtrePokémon : public Entraineur {
        private:
            double boostDegats;
        
        public:
            MaîtrePokémon(const std::string& nom,const vector<Pokemon>equipe) 
                : Entraineur(nom,equipe), boostDegats(1.25) {}
        

            void appliquerBoost(Pokemon& p) const {
                p.setattackdamage(p.getAttackDamage() * boostDegats);
            }
        
        
            void afficherBoost() const {
                std::cout << "Le Maître Pokémon " << getNom() << " applique un boost de " 
                          << (boostDegats * 100 - 100) << "% aux attaques de ses Pokémon." << std::endl;
            }
        };
    
        Type trouveTypeParNom(const std::string& nomType, std::vector<Type>& typeNames) {
            for (auto& typenames:typeNames) {
                if (typenames.getNom() == nomType) {
                    return typenames;  
                }
            }
         
            return typeNames[17];  
        }


       vector<Pokemon> loadPokemons(const string& filename,vector<Type> alltypes) {
        vector<Pokemon> pokemons;
        ifstream file(filename);
        
        if (!file.is_open()) {
            cerr << "Erreur lors de l'ouverture du fichier : " << filename << std::endl;
            return pokemons;
        }
        
        string line;
        getline(file, line);
        while (getline(file, line)) {
            stringstream ss(line);
            string name, type1, type2, attackName;
            int hp, attackDamage;
    
            getline(ss, name, ',');
            getline(ss, type1, ',');
            getline(ss, type2, ',');
            ss >> hp;
            ss.ignore(1, ',');
            getline(ss, attackName, ',');
            ss >> attackDamage;
    
            vector<Type> types;
            types.push_back(trouveTypeParNom(type1,alltypes));
            if (type2 != "Aucun") {
                types.push_back(trouveTypeParNom(type2,alltypes));
            }
            pokemons.push_back(Pokemon(name, types, hp, attackName, attackDamage));
        }
     
        file.close();
        return pokemons;
    }

    vector<Pokemon> loadPokemons2(const string& filename,vector<Type> alltypes) {
        vector<Pokemon> pokemons;
        ifstream file(filename);
        
        if (!file.is_open()) {
            cerr << "Erreur lors de l'ouverture du fichier : " << filename << std::endl;
            return pokemons;
        }
        
        string line;
        getline(file, line);
        while (getline(file, line)) {
            stringstream ss(line);
            string name, type1, type2, attackName;
            int hp, attackDamage;
    
            getline(ss, name, ',');
            getline(ss, type1, ',');
            getline(ss, type2, ',');
            ss >> hp;
            ss.ignore(1, ',');
            getline(ss, attackName, ',');
            ss >> attackDamage;
    
            vector<Type> types;
            types.push_back(trouveTypeParNom(type1,alltypes));
            if (type2 != "Aucun") {
                types.push_back(trouveTypeParNom(type2,alltypes));
            }
            if (name!="")
            {pokemons.push_back(Pokemon(name, types, hp, attackName, attackDamage));}
        }
 
        file.close();
        return pokemons;
    }

    Pokemon trouverPokemonParNom(const std::string& nomPokemon, std::vector<Pokemon>& pokemons) {
        for (auto& pokemon : pokemons) {
            if (pokemon.getName() == nomPokemon) {
                return pokemon;  
            }
        }
        throw runtime_error("Pokémon introuvable");  
    }

    Pokemon trouverPokemonParNom2(const std::string& nomPokemon, std::vector<Pokemon>& pokemons) {
        for (auto& pokemon : pokemons) {
            if (pokemon.getName() == nomPokemon) {
                return pokemon; 
            }
        }
        vector<Type> aucun={};
       return Pokemon("Aucun",aucun,0,"aucun",0); 
    }

  

vector<Joueur> loadJoueurs(const string& filename,  vector<Pokemon> pokemons) {
    vector<Joueur> joueurs;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier : " << filename << std::endl;
        return joueurs;
    }

    string line;

    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string nom,pok1,pok2,pok3,pok4,pok5,pok6;
        vector<Pokemon> pokemonsleader;
        getline(ss, nom, ',');
        getline(ss, pok1, ',');
        if (pok1!="")
        {pokemonsleader.push_back(trouverPokemonParNom2(pok1,pokemons));}
        getline(ss, pok2, ',');
        if (pok2!="")
        {pokemonsleader.push_back(trouverPokemonParNom2(pok2,pokemons));}
        getline(ss, pok3, ',');
        if (pok3!="")
        {pokemonsleader.push_back(trouverPokemonParNom2(pok3,pokemons));}
        getline(ss, pok4, ',');
        if (pok4!="")
        {pokemonsleader.push_back(trouverPokemonParNom2(pok4,pokemons));}
        getline(ss, pok5, ',');
        if (pok5!="")
        {pokemonsleader.push_back(trouverPokemonParNom2(pok5,pokemons));}
        getline(ss, pok6, ',');
        if (pok6!="")
        {pokemonsleader.push_back(trouverPokemonParNom2(pok6,pokemons));}



        
        joueurs.push_back(Joueur(nom,pokemonsleader));


    file.close();
    return joueurs;
}}




vector<LeaderDeGym> loadLeaders(const string& filename,vector<Pokemon> pokemons) {
    vector<LeaderDeGym> leaders;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier : " << filename << std::endl;
        return leaders;
    }

    string line;
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string nom, badge, gymnase,pok1,pok2,pok3,pok4,pok5,pok6;
        getline(ss, nom, ',');
        getline(ss, badge, ',');
        vector<Pokemon> pokemonsleader;
        getline(ss, pok1, ',');
        if (pok1!="")
        {pokemonsleader.push_back(trouverPokemonParNom2(pok1,pokemons));}
        getline(ss, pok2, ',');
        if (pok2!="")
        {pokemonsleader.push_back(trouverPokemonParNom2(pok2,pokemons));}
        getline(ss, pok3, ',');
        if (pok3!="")
        {pokemonsleader.push_back(trouverPokemonParNom2(pok3,pokemons));}
        getline(ss, pok4, ',');
        if (pok4!="")
        {pokemonsleader.push_back(trouverPokemonParNom2(pok4,pokemons));}
        getline(ss, pok5, ',');
        if (pok5!="")
        {pokemonsleader.push_back(trouverPokemonParNom2(pok5,pokemons));}
        getline(ss, pok6, ',');
        if (pok6!="")
        {pokemonsleader.push_back(trouverPokemonParNom2(pok6,pokemons));}
        leaders.push_back(LeaderDeGym(nom,pokemonsleader, badge, gymnase));
     
    }

    file.close();
    return leaders;
}




vector<MaîtrePokémon> loadMaitres(const string& filename,vector<Pokemon> pokemons) {
    vector<MaîtrePokémon> maitres;
    string line;
    ifstream file(filename);
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string nom, badge, gymnase,pok1,pok2,pok3,pok4,pok5,pok6;
        vector<Pokemon> pokemonsleader;
        getline(ss, nom, ',');
        getline(ss, pok1, ',');
        if (pok1!="")
        {pokemonsleader.push_back(trouverPokemonParNom2(pok1,pokemons));}
        getline(ss, pok2, ',');
        if (pok2!="")
        {pokemonsleader.push_back(trouverPokemonParNom2(pok2,pokemons));}
        getline(ss, pok3, ',');
        if (pok3!="")
        {pokemonsleader.push_back(trouverPokemonParNom2(pok3,pokemons));}
        getline(ss, pok4, ',');
        if (pok4!="")
        {pokemonsleader.push_back(trouverPokemonParNom2(pok4,pokemons));}
        getline(ss, pok5, ',');
        if (pok5!="")
        {pokemonsleader.push_back(trouverPokemonParNom2(pok5,pokemons));}
        getline(ss, pok6, ',');
        if (pok6!="")
        {pokemonsleader.push_back(trouverPokemonParNom2(pok6,pokemons));}
        maitres.push_back(MaîtrePokémon(nom,pokemonsleader));

    file.close();
    return maitres;
}
}

int trouverIndexDansCSV(const string& filename, const string& nomPokemonRecherche) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Erreur d'ouverture du fichier : " << filename << endl;
        return -1;
    }

    string line;
    int index = 0;
    getline(file, line); 

    while (getline(file, line)) {
        stringstream ss(line);
        string nom;
        getline(ss, nom, ','); 

        if (nom == nomPokemonRecherche) {
            return index + 1; 
        }
        index++;
    }

    return -1; 
}

    
    
void combat(vector<LeaderDeGym> leaders,vector<Joueur> joueur,int imax,int i2max,int numleader) 
{ int i1=0;int i2=0;
    const auto hand = sf::Cursor::createFromSystem(sf::Cursor::Type::Hand).value();
    const auto arrow = sf::Cursor::createFromSystem(sf::Cursor::Type::Arrow).value();
    string csvFile = "pokemon2.csv";
   

    int numeroSprite = trouverIndexDansCSV(csvFile, leaders[numleader].getEquipe()[i1].getName());
    int numeroSprite2 = trouverIndexDansCSV(csvFile, joueur[0].getEquipe()[i2].getName());
    if (numeroSprite == -1) {
        cerr << "Impossible de trouver " << leaders[numleader].getEquipe()[i1].getName() << " dans le fichier CSV." << endl;
    }


    sf::RenderWindow window(sf::VideoMode({1200, 600}), L"Pokémon Esilv Edition");
    sf::CircleShape shape(1.f);
    shape.setFillColor(sf::Color::Green);

    string spritePath = "sprite/" + to_string(numeroSprite) + ".png";
    string spritePath2 = "sprite/back/" + to_string(numeroSprite2) + ".png";
    string terrainPath = "sprite/terrain1.jpg";
   string typeennemi1path="typeicone/Miniature_Type_"+leaders[numleader].getEquipe()[i1].gettype()[0].getNom()+"_NB.png";
    string typeennemi2path="typeicone/Miniature_Type_"+leaders[numleader].getEquipe()[i1].gettype()[1].getNom()+"_NB.png";

    string typeami1path="typeicone/Miniature_Type_"+joueur[0].getEquipe()[i2].gettype()[0].getNom()+"_NB.png";
    string typeami2path="typeicone/Miniature_Type_"+joueur[0].getEquipe()[i2].gettype()[1].getNom()+"_NB.png";

    sf::Texture spritetext, spritetext2, terraintext,adversairetext,typeami1,typeami2,typennemi1,typeennemi2;
    spritetext.loadFromFile(spritePath);
    spritetext2.loadFromFile(spritePath2);
    terraintext.loadFromFile(terrainPath);
    typennemi1.loadFromFile(typeennemi1path);
    typeennemi2.loadFromFile(typeennemi2path);
    typeami1.loadFromFile(typeami1path);
    typeami2.loadFromFile(typeami2path);



    sf::Sprite sprite(spritetext);
    sf::Sprite sprite2(spritetext2);
    sf::Sprite terrain(terraintext);
    sf::Sprite typennemi1Sprite(typennemi1);
    sf::Sprite typeennemi2Sprite(typeennemi2);
    sf::Sprite typeami1Sprite(typeami1);
    sf::Sprite typeami2Sprite(typeami2);
    sprite.setPosition(sf::Vector2f(670, 50));
    sprite2.setPosition(sf::Vector2f(100, 250));
    typennemi1Sprite.setPosition(sf::Vector2f(905, 60));
    typeennemi2Sprite.setPosition(sf::Vector2f(955, 60));
    typeami1Sprite.setPosition(sf::Vector2f(15, 200));  
    typeami2Sprite.setPosition(sf::Vector2f(65, 200));  
    sprite.setScale(sf::Vector2f(4, 4));
    sprite2.setScale(sf::Vector2f(4, 4));
    sprite.setScale(sf::Vector2f(4, 4));
    typeami1Sprite.setScale(sf::Vector2f(1.5, 1.5));
    typennemi1Sprite.setScale(sf::Vector2f(1.5, 1.5));
    typeami2Sprite.setScale(sf::Vector2f(1.5, 1.5));
    typeennemi2Sprite.setScale(sf::Vector2f(1.5, 1.5));

    sf::Vector2u textureSize = terraintext.getSize();
    sf::Vector2u windowSize = window.getSize();
    sf::RectangleShape rectangle(sf::Vector2f(1100, 150));
    sf::RectangleShape rectanglesprite1(sf::Vector2f(300, 75));
    sf::RectangleShape rectanglesprite2(sf::Vector2f(300, 75));
    rectangle.setPosition(sf::Vector2f(50, 450));
    rectanglesprite2.setPosition(sf::Vector2f(10, 150));
    rectanglesprite1.setPosition(sf::Vector2f(900, 10));
    rectangle.setFillColor(sf::Color(0, 0, 0, 128));
    rectanglesprite1.setFillColor(sf::Color(0, 0, 0, 128));
    rectanglesprite2.setFillColor(sf::Color(0, 0, 0, 128));
  
    sf::Font font;
    if (!font.openFromFile("pokemonfont.otf")) {
        cerr << "Erreur de chargement de la police !" << endl;
    }
   
    sf::Text text(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(100, 470));
    sf::Text PVsprite1=text;
    PVsprite1.setCharacterSize(35);
    PVsprite1.setPosition(sf::Vector2f(910, 15));
    string PVmaxsprite1=to_string(leaders[numleader].getEquipe()[i1].getHp());
    PVsprite1.setString(leaders[numleader].getEquipe()[i1].getName()+"   PV :"+to_string(leaders[numleader].getEquipe()[i1].getHp())+"/"+PVmaxsprite1);
    sf::Text PVsprite2=text;
    PVsprite2.setCharacterSize(35);
    PVsprite2.setPosition(sf::Vector2f(15, 155));
    string PVmaxsprite2=to_string(joueur[0].getEquipe()[0].getHp());
    PVsprite2.setString(joueur[0].getEquipe()[0].getName()+"   PV :"+to_string(joueur[0].getEquipe()[0].getHp())+"/"+PVmaxsprite2);
    terrain.setScale(
        sf::Vector2f(float(windowSize.x) / textureSize.x,
                     float(windowSize.y) / textureSize.y)
    );

    sf::Clock clock;
    int alpha = 0;

    sf::Music combat;
    if (!combat.openFromFile("combat1.ogg")) {
        cerr << "Erreur de chargement de la musique !" << endl;
    }
    combat.setLooping(true);
    combat.play();
    combat.setVolume(40);
    sf::Music effective;
    effective.openFromFile("effective.ogg");
    sf::Music victory;
    victory.openFromFile("Victory.ogg");
    sf::Music defaite;
    defaite.openFromFile("Defeat.ogg");
    sf::Music notveryeffective;
    notveryeffective.setVolume(140);
    notveryeffective.openFromFile("notveryeffective.ogg");
    sf::Music okeffective;
    okeffective.openFromFile("okeffective.ogg");
    okeffective.setVolume(140);

 sf::Music bruitsprite1;
 string cheminbruit;
if (numeroSprite<10)
{cheminbruit="kanto/00"+to_string(numeroSprite)+".ogg";}
else if (numeroSprite<100)
{cheminbruit="kanto/0"+to_string(numeroSprite)+".ogg";}
else{cheminbruit="kanto/"+to_string(numeroSprite)+".ogg";}
 bruitsprite1.openFromFile(cheminbruit);

  sf::Music bruitsprite2;
 string cheminbruit2;
if (numeroSprite2<10)
{cheminbruit2="kanto/00"+to_string(numeroSprite2)+".ogg";}
else if (numeroSprite2<100)
{cheminbruit2="kanto/0"+to_string(numeroSprite2)+".ogg";}
else{cheminbruit2="kanto/"+to_string(numeroSprite2)+".ogg";}
 bruitsprite2.openFromFile(cheminbruit2);
    int index = 0;
    std::string fullText = leaders[numleader].getNom() + " veut se battre !";
    string adversairepath="sprite/0"+to_string(numleader)+".png";
    adversairetext.loadFromFile(adversairepath);
    sf::Sprite adversaire(adversairetext);
    adversaire.setScale(sf::Vector2f(4, 4));
    adversaire.setPosition(sf::Vector2f(670, 20));
    adversaire.setColor(sf::Color(255, 255, 255, 0));
    sprite2.setColor(sf::Color(255, 255, 255, 0));
    sprite.setColor(sf::Color(255, 255, 255, 0));
    rectanglesprite1.setFillColor(sf::Color(255, 255, 255, 0));
    rectanglesprite2.setFillColor(sf::Color(255, 255, 255, 0));
    PVsprite1.setFillColor(sf::Color(255, 255, 255, 0));
    PVsprite2.setFillColor(sf::Color(255, 255, 255, 0));
    typeami1Sprite.setColor(sf::Color(255, 255, 255, 0));
    typeami2Sprite.setColor(sf::Color(255, 255, 255, 0));
    typennemi1Sprite.setColor(sf::Color(255, 255, 255, 0));
    typeennemi2Sprite.setColor(sf::Color(255, 255, 255, 0));



bool affichfini=false;
    enum class PhaseCombat {
        Fondu,
        Attente,
        AffichageTexte,
        Fin,Attenteavantpokemon,AffichagePokemon1,AffichagePokemon2,Menu,Attaque1,Attaque2,KO1,KO2
    };
    PhaseCombat phase = PhaseCombat::Fondu;
    sf::RectangleShape clickableZone(sf::Vector2f(200, 50));
    sf::Color zoneColor(100, 100, 250);
    clickableZone.setPosition(sf::Vector2<float>(550, 480)); 
    clickableZone.setFillColor(sf::Color(255, 255, 255, 0)); 
 bool cligne=false;
 bool ko=false;
int pvapresattaque;
float coeff;
string efficacite="";;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }


        sf::Vector2i mousePos = sf::Mouse::getPosition(window); 
        bool isMouseOver = clickableZone.getGlobalBounds().contains(sf::Vector2<float>(mousePos.x, mousePos.y));
    
        if (isMouseOver) {
            window.setMouseCursor(hand);
        } else {
            window.setMouseCursor(arrow);
        }
        window.clear();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && isMouseOver) {coeff=leaders[numleader].getEquipe()[i1].gettype()[0].matricepokemon(joueur[0].getEquipe()[i2].gettype()[0]); 
            if (coeff==0.5){efficacite=" Ce n'est pas tres efficace... (x0.5)";notveryeffective.play();} 
        else if (coeff==2){efficacite="C'est super efficace ! (x2)";effective.play();}
        else if (coeff==0)efficacite="Ca n'affecte pas le "+leaders[numleader].getEquipe()[i1].getName()+" ennemi.";else{okeffective.play();}
        text.setString("");index=0;fullText = joueur[0].getEquipe()[i2].getName() + " utilise " + joueur[0].getEquipe()[i2].getAttackName() + ".\n"+efficacite;efficacite="";
            text.setString("");  
            clock.restart();pvapresattaque=leaders[numleader].getEquipe()[i1].getHp()-joueur[0].getEquipe()[i2].getAttackDamage()*coeff;
            phase = PhaseCombat::Attaque1; 
        } 
        switch (phase) {
            case PhaseCombat::Fondu:
                if (clock.getElapsedTime().asMilliseconds() > 10 && alpha < 255) {
                    alpha += 1;
                    if (alpha >= 255) {
                        alpha = 255;
                        phase = PhaseCombat::Attente;
                        clock.restart();
                    }
                    terrain.setColor(sf::Color(255, 255, 255, alpha));
                    clock.restart();
                }
                break;

            case PhaseCombat::Attente:
                if (clock.getElapsedTime().asMilliseconds() > 2500) {
                    phase = PhaseCombat::AffichageTexte;
                    alpha = 0;
                    clock.restart();
                }
                break;

            case PhaseCombat::AffichageTexte: 
             
                if (clock.getElapsedTime().asSeconds() > 0.05f & alpha < 255) {alpha+=10;
                    std::string displayedText = text.getString();
                    if (index < fullText.size()&alpha<255) {
                        displayedText += fullText[index];
                        text.setString(displayedText);
                        index++;
                        adversaire.setColor(sf::Color(255, 255, 255, alpha));
                        clock.restart();
                    } else {alpha=255;
                        phase = PhaseCombat::Attenteavantpokemon;clock.restart();
                    }
                }
                break;
                case PhaseCombat::Attenteavantpokemon:
                
                if (clock.getElapsedTime().asMilliseconds() > 1500) { 
                    phase = PhaseCombat::AffichagePokemon1;
                    alpha = 0;
                    index = 0;
                    fullText = leaders[numleader].getNom() + " envoie un " + leaders[numleader].getEquipe()[i1].getName() + "!";
                    text.setString("");
                 phase = PhaseCombat::AffichagePokemon1;bruitsprite1.play();
                    clock.restart();
                
                }
                break;
                case PhaseCombat::AffichagePokemon1: 
                adversaire.setColor(sf::Color(255,255,255,0));
                if (clock.getElapsedTime().asSeconds() > 0.03f && alpha < 255) {alpha+=9;
                    std::string displayedText = text.getString();
                    if (index < fullText.size()&&alpha<255) {
                        displayedText += fullText[index];
                        text.setString(displayedText);
                        index++;
                        sprite.setColor(sf::Color(255, 255, 255, alpha));
                        clock.restart();
                    } else if (ko==true)
                    {sprite.setColor(sf::Color(255,255,255,255));alpha=0;index = 0;
                        sf::sleep(sf::seconds(2)); text.setString("");phase=PhaseCombat::Menu;}
             
                    else {alpha=0;index = 0;rectanglesprite1.setFillColor(sf::Color(0, 0, 0, 128));PVsprite1.setFillColor(sf::Color(255, 255, 255, 255));    typennemi1Sprite.setColor(sf::Color(255, 255, 255, 255));
                        if (leaders[numleader].getEquipe()[i1].gettype()[1].getNom()!="Fee")
                        {
                          typeennemi2Sprite.setColor(sf::Color(255, 255, 255, 255));
                          }
                       sf::sleep(sf::seconds(2)); text.setString("");fullText="Vous envoyez un "+ joueur[0].getEquipe()[i2].getName() + "!"; phase=PhaseCombat::AffichagePokemon2;bruitsprite2.play();}}
                       break;
            case PhaseCombat::AffichagePokemon2:
           
            if (clock.getElapsedTime().asSeconds() > 0.03f && alpha < 255) {alpha+=9;
                std::string displayedText = text.getString();
                if (index < fullText.size()&&alpha<255) {
                    displayedText += fullText[index];
                    text.setString(displayedText);
                    index++;
                    sprite2.setColor(sf::Color(255, 255, 255, alpha));
                    clock.restart();
                } 
                else {alpha=0;index = 0;
                    sf::sleep(sf::seconds(1));rectanglesprite2.setFillColor(sf::Color(0, 0, 0, 128));PVsprite2.setFillColor(sf::Color(255, 255, 255, 255)); typeami1Sprite.setColor(sf::Color(255, 255, 255, 255));
                    
                    if (joueur[0].getEquipe()[i2].gettype()[1].getNom()!="Fee")
                    {
                        typeami2Sprite.setColor(sf::Color(255, 255, 255, 255));
                      }
                      sf::sleep(sf::seconds(1));
                   phase=PhaseCombat::Menu;}}
            
                    
                
               
                break;
            case PhaseCombat::Menu:
               text.setString("Que voulez vous faire ?      Attaquer        Sac \n                                    Pokemons        Fuir");sprite2.setColor(sf::Color(255,255,255,255));sprite.setColor(sf::Color(255,255,255,255));
                break;
         case PhaseCombat::Attaque1:
            if (clock.getElapsedTime().asSeconds() > 0.05f) { std::string displayedText = text.getString();
            if (index < fullText.size()) {
                displayedText += fullText[index];
                text.setString(displayedText);
                index++;if (leaders[numleader].getEquipe()[i1].getHp()>pvapresattaque&&leaders[numleader].getEquipe()[i1].getHp()>0)
                {leaders[numleader].getEquipe()[i1].sethp(leaders[numleader].getEquipe()[i1].getHp()-5);
                PVsprite1.setString(leaders[numleader].getEquipe()[i1].getName()+"   PV :"+to_string(leaders[numleader].getEquipe()[i1].getHp())+"/"+PVmaxsprite1);}
                if (leaders[numleader].getEquipe()[i1].getHp()<0){leaders[numleader].getEquipe()[i1].sethp(0); PVsprite1.setString(leaders[numleader].getEquipe()[i1].getName()+"   PV :"+to_string(leaders[numleader].getEquipe()[i1].getHp())+"/"+PVmaxsprite1);}
                else if (leaders[numleader].getEquipe()[i1].getHp()<pvapresattaque&&leaders[numleader].getEquipe()[i1].getHp()>0)
                {sprite.setColor(sf::Color(255,255,255,255));leaders[numleader].getEquipe()[i1].sethp(pvapresattaque);PVsprite1.setString(leaders[numleader].getEquipe()[i1].getName()+"   PV :"+to_string(pvapresattaque)+"/"+PVmaxsprite1);}
                
                if(!cligne){sprite.setColor(sf::Color(255,255,255,0));sprite2.setPosition(sf::Vector2f(105, 250));cligne=!cligne;}
                else{sprite.setColor(sf::Color(255,255,255,255));sprite2.setPosition(sf::Vector2f(100, 250));cligne=!cligne;}
                clock.restart();
            } else if(leaders[numleader].getEquipe()[i1].getHp()==0){sprite.setColor(sf::Color(255,255,255,255));phase=PhaseCombat::KO1;sf::sleep(sf::seconds(1)); text.setString("");index=0;fullText = leaders[numleader].getEquipe()[i1].getName() + " est totalement K.O !" ;
                text.setString(""); alpha=255;
                clock.restart();bruitsprite1.play();


            }
             else{sprite.setColor(sf::Color(255,255,255,255));sf::sleep(sf::seconds(2));coeff=joueur[0].getEquipe()[i2].gettype()[0].matricepokemon(leaders[numleader].getEquipe()[i1].gettype()[0]); 
                if (coeff==0.5){efficacite=" Ce n'est pas tres efficace... (x0.5)";notveryeffective.play();} 
            else if (coeff==2){efficacite="C'est super efficace !(x2)";effective.play();}
            else if (coeff==0)efficacite="Ca n'affecte pas votre "+joueur[0].getEquipe()[i2].getName()+".";else{okeffective.play();}
                phase=PhaseCombat::Attaque2; text.setString("");index=0;fullText = leaders[numleader].getEquipe()[i1].getName() + " utilise " + leaders[numleader].getEquipe()[i1].getAttackName() + ".\n"+efficacite;
                text.setString(""); 
                clock.restart();
                pvapresattaque=joueur[0].getEquipe()[i2].getHp()-leaders[numleader].getEquipe()[i1].getAttackDamage()*coeff;}      }    
                if (index >= fullText.size()) sprite.setColor(sf::Color(255,255,255,255));
            break;
            case PhaseCombat::Attaque2:
        
            if (clock.getElapsedTime().asSeconds() > 0.05f) { std::string displayedText = text.getString();
            if (index < fullText.size()) {
                displayedText += fullText[index];
                text.setString(displayedText);
                index++;if (joueur[0].getEquipe()[i2].getHp()>pvapresattaque&&joueur[0].getEquipe()[i2].getHp()>0)
                {joueur[0].getEquipe()[i2].sethp(joueur[0].getEquipe()[i2].getHp()-5);
                PVsprite2.setString(joueur[0].getEquipe()[i2].getName()+"   PV :"+to_string(joueur[0].getEquipe()[i2].getHp())+"/"+PVmaxsprite2);}
                else if(joueur[0].getEquipe()[i2].getHp()<pvapresattaque&&joueur[0].getEquipe()[i2].getHp()>0){joueur[0].getEquipe()[i2].sethp(pvapresattaque);PVsprite2.setString(joueur[0].getEquipe()[i2].getName()+"   PV :"+to_string(pvapresattaque)+"/"+PVmaxsprite2);}
                if (joueur[0].getEquipe()[i2].getHp()<0){joueur[0].getEquipe()[i2].sethp(0); PVsprite2.setString(joueur[0].getEquipe()[i2].getName()+"   PV :"+to_string(joueur[0].getEquipe()[i2].getHp())+"/"+PVmaxsprite2);}
                
                
                if(!cligne){sprite2.setColor(sf::Color(255,255,255,0));sprite.setPosition(sf::Vector2f(675, 50));;cligne=!cligne;}  
                else{sprite2.setColor(sf::Color(255,255,255,255));sprite.setPosition(sf::Vector2f(670, 50));cligne=!cligne;}
            }
            
   
    
                
                else if(joueur[0].getEquipe()[i2].getHp()==0){sprite2.setColor(sf::Color(255,255,255,255));phase=PhaseCombat::KO2;sf::sleep(sf::seconds(1)); text.setString("");index=0;fullText = joueur[0].getEquipe()[i2].getName() + " est totalement K.O !" ;
                    text.setString(""); alpha=255;
                    clock.restart();bruitsprite2.play();   clock.restart();}
                else{sprite2.setColor(sf::Color(255,255,255,255));sf::sleep(sf::seconds(2));sprite.setPosition(sf::Vector2f(670, 50));cligne=!cligne;clock.restart();phase=PhaseCombat::Menu;}
                clock.restart();  
               }      if (index >= fullText.size()) sprite2.setColor(sf::Color(255,255,255,255));  
            break;

            case PhaseCombat::KO2: 
        
            if (clock.getElapsedTime().asSeconds() > 0.03f ) {
                std::string displayedText = text.getString();
                if (index < fullText.size()) {
                    displayedText += fullText[index];
                    text.setString(displayedText);
                    index++;
                   
                 
                } 

               else{i2+=1;sprite2.setColor(sf::Color(255,255,255,0));
                if(i2==i2max){combat.stop();defaite.play(); text.setString("")  ;fullText = "Vous avez perdu contre "+leaders[numleader].getNom() + "...";alpha=0; index=0;phase=PhaseCombat::Fin;perdrecombat=true; }
                else{sf::sleep(sf::seconds(2));text.setString(""); ko=true;
                    numeroSprite2 = trouverIndexDansCSV(csvFile, joueur[0].getEquipe()[i2].getName()); spritePath2 = "sprite/back/" + to_string(numeroSprite2) + ".png";
                     spritetext2.loadFromFile(spritePath2);sprite2.setTexture(spritetext2);
                      fullText = "Vous envoyez un " + joueur[0].getEquipe()[i2].getName() + "!";     PVmaxsprite2=to_string(joueur[0].getEquipe()[i2].getHp());
                      PVsprite2.setString(joueur[0].getEquipe()[i2].getName()+"   PV :"+to_string(joueur[0].getEquipe()[i2].getHp())+"/"+PVmaxsprite2);
                      if (numeroSprite2<10)
                            {cheminbruit2="kanto/00"+to_string(numeroSprite2)+".ogg";}
                      else if (numeroSprite2<100)
                            {cheminbruit2="kanto/0"+to_string(numeroSprite2)+".ogg";}
                      else{cheminbruit2="kanto/"+to_string(numeroSprite2)+".ogg";}
                      if (joueur[0].getEquipe()[i2].gettype()[1].getNom()=="Fee")
                      {
                        typeami2Sprite.setColor(sf::Color(255, 255, 255, 0));
                        }
                        else{typeami2Sprite.setColor(sf::Color(255, 255, 255, 255));}
 bruitsprite2.openFromFile(cheminbruit2);typeami1path="typeicone/Miniature_Type_"+joueur[0].getEquipe()[i2].gettype()[0].getNom()+"_NB.png";
 typeami2path="typeicone/Miniature_Type_"+joueur[0].getEquipe()[i2].gettype()[1].getNom()+"_NB.png"; typeami1.loadFromFile(typeami1path);
 typeami2.loadFromFile(typeami2path);
                      index=0;alpha=0; clock.restart();phase=PhaseCombat::AffichagePokemon2;bruitsprite2.play();}
                      sprite2.setColor(sf::Color(255, 255, 255, 0));
                      clock.restart();
               
               }}
                break;


                case PhaseCombat::KO1: 
        
                if (clock.getElapsedTime().asSeconds() > 0.03f ) {
                    std::string displayedText = text.getString();
                    if (index < fullText.size()) {
                        displayedText += fullText[index];
                        text.setString(displayedText);
                        index++;
                       
                     
                    } 
    
                   else{sf::sleep(sf::seconds(2));i1+=1;sprite.setColor(sf::Color(255,255,255,0));
                    if(i1==imax){combat.stop();victory.play(); text.setString("")  ;fullText = "Vous avez battu "+leaders[numleader].getNom() + " !";alpha=0; index=0;phase=PhaseCombat::Fin;gagnerbadge=true;gagnercombat=true;  }
                   
                   else{text.setString(""); ;ko=true;
                        numeroSprite = trouverIndexDansCSV(csvFile, leaders[numleader].getEquipe()[i1].getName()); spritePath = "sprite/" + to_string(numeroSprite) + ".png";
                         spritetext.loadFromFile(spritePath);sprite.setTexture(spritetext);
                          fullText = leaders[numleader].getNom() + " envoie un " + leaders[numleader].getEquipe()[i1].getName() + "!";     PVmaxsprite1=to_string(leaders[numleader].getEquipe()[i1].getHp());
                          PVsprite1.setString(leaders[numleader].getEquipe()[i1].getName()+"   PV :"+to_string(leaders[numleader].getEquipe()[i1].getHp())+"/"+PVmaxsprite1);
                          if (numeroSprite<10)
                                {cheminbruit="kanto/00"+to_string(numeroSprite)+".ogg";}
                          else if (numeroSprite<100)
                                {cheminbruit="kanto/0"+to_string(numeroSprite)+".ogg";}
                          else{cheminbruit="kanto/"+to_string(numeroSprite)+".ogg";} 

                        bruitsprite1.openFromFile(cheminbruit);    typeennemi1path="typeicone/Miniature_Type_"+leaders[numleader].getEquipe()[i1].gettype()[0].getNom()+"_NB.png";
                         typeennemi2path="typeicone/Miniature_Type_"+leaders[numleader].getEquipe()[i1].gettype()[1].getNom()+"_NB.png"; typennemi1.loadFromFile(typeennemi1path);
                         typeennemi2.loadFromFile(typeennemi2path);
                          index=0;alpha=0; clock.restart();phase=PhaseCombat::AffichagePokemon1;bruitsprite1.play();
                          sprite.setColor(sf::Color(255, 255, 255, 0));                         
                           if (leaders[numleader].getEquipe()[i1].gettype()[1].getNom()=="Fee")
                          {
                            typeennemi2Sprite.setColor(sf::Color(255, 255, 255, 0));
                            }
                            else{typeennemi2Sprite.setColor(sf::Color(255, 255, 255, 255));}
                          clock.restart();
                   
                   }}}
                    break;
                    case PhaseCombat::Fin:
                    sprite.setColor(sf::Color(255, 255, 255, 0));
                    sprite2.setColor(sf::Color(255, 255, 255, 0));
                    rectanglesprite1.setFillColor(sf::Color(255, 255, 255,0));
                    rectanglesprite2.setFillColor(sf::Color(255, 255, 255, 0));
                    PVsprite1.setFillColor(sf::Color(255, 255, 255, 0));
                    PVsprite2.setFillColor(sf::Color(255, 255, 255, 0));
                    typeennemi2Sprite.setColor(sf::Color(255, 255, 255, 0));
                    typeami1Sprite.setColor(sf::Color(255, 255, 255, 0));
                    typeami2Sprite.setColor(sf::Color(255, 255, 255, 0));
                    typennemi1Sprite.setColor(sf::Color(255, 255, 255, 0));
                    if (clock.getElapsedTime().asSeconds() > 0.04f ) {
                        std::string displayedText = text.getString();
                        if (index < fullText.size()) 
                        { displayedText += fullText[index];
                            text.setString(displayedText);
                            index++;alpha+=9; adversaire.setColor(sf::Color(255, 255, 255, alpha));
                        }
                        else {adversaire.setColor(sf::Color(255, 255, 255, 255));sf::sleep(sf::seconds(5));window.close();}
                       clock.restart(); }
                        break;


                    
         
        }
        
        window.draw(terrain);
        window.draw(sprite);
        window.draw(sprite2);
        window.draw(rectangle);
        window.draw(text);
        window.draw(adversaire);
        window.draw(clickableZone);
        window.draw(rectanglesprite1);
        window.draw(rectanglesprite2);
        window.draw(PVsprite1);
        window.draw(PVsprite2);
        window.draw(typennemi1Sprite);
        window.draw(typeennemi2Sprite);
        window.draw(typeami1Sprite);
        window.draw(typeami2Sprite);
      
        window.display();

    }
}


void combatmaitre(vector<MaîtrePokémon> leaders,vector<Joueur> joueur,int imax,int i2max) 
{ int i1=0;int i2=0;
    const auto hand = sf::Cursor::createFromSystem(sf::Cursor::Type::Hand).value();
    const auto arrow = sf::Cursor::createFromSystem(sf::Cursor::Type::Arrow).value();
    string csvFile = "pokemon2.csv";
   

    int numeroSprite = trouverIndexDansCSV(csvFile, leaders[0].getEquipe()[i1].getName());
    int numeroSprite2 = trouverIndexDansCSV(csvFile, joueur[0].getEquipe()[i2].getName());
 

    sf::RenderWindow window(sf::VideoMode({1200, 600}), L"Pokémon Esilv Edition");
    sf::CircleShape shape(1.f);
    shape.setFillColor(sf::Color::Green);

    string spritePath = "sprite/" + to_string(numeroSprite) + ".png";
    string spritePath2 = "sprite/back/" + to_string(numeroSprite2) + ".png";
    string terrainPath = "sprite/terrainfinal.jpg";
   string typeennemi1path="typeicone/Miniature_Type_"+leaders[0].getEquipe()[i1].gettype()[0].getNom()+"_NB.png";
    string typeennemi2path="typeicone/Miniature_Type_"+leaders[0].getEquipe()[i1].gettype()[1].getNom()+"_NB.png";

    string typeami1path="typeicone/Miniature_Type_"+joueur[0].getEquipe()[i2].gettype()[0].getNom()+"_NB.png";
    string typeami2path="typeicone/Miniature_Type_"+joueur[0].getEquipe()[i2].gettype()[1].getNom()+"_NB.png";

    sf::Texture spritetext, spritetext2, terraintext,adversairetext,typeami1,typeami2,typennemi1,typeennemi2;
    spritetext.loadFromFile(spritePath);
    spritetext2.loadFromFile(spritePath2);
    terraintext.loadFromFile(terrainPath);
    typennemi1.loadFromFile(typeennemi1path);
    typeennemi2.loadFromFile(typeennemi2path);
    typeami1.loadFromFile(typeami1path);
    typeami2.loadFromFile(typeami2path);



    sf::Sprite sprite(spritetext);
    sf::Sprite sprite2(spritetext2);
    sf::Sprite terrain(terraintext);
    sf::Sprite typennemi1Sprite(typennemi1);
    sf::Sprite typeennemi2Sprite(typeennemi2);
    sf::Sprite typeami1Sprite(typeami1);
    sf::Sprite typeami2Sprite(typeami2);
    sprite.setPosition(sf::Vector2f(670, 70));
    sprite2.setPosition(sf::Vector2f(100, 250));
    typennemi1Sprite.setPosition(sf::Vector2f(905, 60));
    typeennemi2Sprite.setPosition(sf::Vector2f(955, 60));
    typeami1Sprite.setPosition(sf::Vector2f(15, 200));  
    typeami2Sprite.setPosition(sf::Vector2f(65, 200));  
    sprite.setScale(sf::Vector2f(4, 4));
    sprite2.setScale(sf::Vector2f(4, 4));
    sprite.setScale(sf::Vector2f(4, 4));
    typeami1Sprite.setScale(sf::Vector2f(1.5, 1.5));
    typennemi1Sprite.setScale(sf::Vector2f(1.5, 1.5));
    typeami2Sprite.setScale(sf::Vector2f(1.5, 1.5));
    typeennemi2Sprite.setScale(sf::Vector2f(1.5, 1.5));

    sf::Vector2u textureSize = terraintext.getSize();
    sf::Vector2u windowSize = window.getSize();
    sf::RectangleShape rectangle(sf::Vector2f(1100, 150));
    sf::RectangleShape rectanglesprite1(sf::Vector2f(300, 75));
    sf::RectangleShape rectanglesprite2(sf::Vector2f(300, 75));
    rectangle.setPosition(sf::Vector2f(50, 450));
    rectanglesprite2.setPosition(sf::Vector2f(10, 150));
    rectanglesprite1.setPosition(sf::Vector2f(900, 10));
    rectangle.setFillColor(sf::Color(0, 0, 0, 128));
    rectanglesprite1.setFillColor(sf::Color(0, 0, 0, 128));
    rectanglesprite2.setFillColor(sf::Color(0, 0, 0, 128));
  
    sf::Font font;
    if (!font.openFromFile("pokemonfont.otf")) {
        cerr << "Erreur de chargement de la police !" << endl;
    }
   
    sf::Text text(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(sf::Vector2f(100, 470));
    sf::Text PVsprite1=text;
    PVsprite1.setCharacterSize(35);
    PVsprite1.setPosition(sf::Vector2f(910, 15));
    string PVmaxsprite1=to_string(leaders[0].getEquipe()[i1].getHp());
    PVsprite1.setString(leaders[0].getEquipe()[i1].getName()+"   PV :"+to_string(leaders[0].getEquipe()[i1].getHp())+"/"+PVmaxsprite1);
    sf::Text PVsprite2=text;
    PVsprite2.setCharacterSize(35);
    PVsprite2.setPosition(sf::Vector2f(15, 155));
    string PVmaxsprite2=to_string(joueur[0].getEquipe()[0].getHp());
    PVsprite2.setString(joueur[0].getEquipe()[0].getName()+"   PV :"+to_string(joueur[0].getEquipe()[0].getHp())+"/"+PVmaxsprite2);
    terrain.setScale(
        sf::Vector2f(float(windowSize.x) / textureSize.x,
                     float(windowSize.y) / textureSize.y)
    );

    sf::Clock clock;
    int alpha = 0;

    sf::Music combat;
    if (!combat.openFromFile("maitre.ogg")) {
        cerr << "Erreur de chargement de la musique !" << endl;
    }
    combat.setLooping(true);
    combat.play();
    combat.setVolume(40);
    sf::Music effective;
    effective.openFromFile("effective.ogg");
    sf::Music victory;
    victory.openFromFile("Victory.ogg");
    sf::Music defaite;
    defaite.openFromFile("Defeat.ogg");
    sf::Music notveryeffective;
    notveryeffective.setVolume(140);
    notveryeffective.openFromFile("notveryeffective.ogg");
    sf::Music okeffective;
    okeffective.openFromFile("okeffective.ogg");
    okeffective.setVolume(140);

 sf::Music bruitsprite1;
 string cheminbruit;
if (numeroSprite<10)
{cheminbruit="kanto/00"+to_string(numeroSprite)+".ogg";}
else if (numeroSprite<100)
{cheminbruit="kanto/0"+to_string(numeroSprite)+".ogg";}
else{cheminbruit="kanto/"+to_string(numeroSprite)+".ogg";}
 bruitsprite1.openFromFile(cheminbruit);

  sf::Music bruitsprite2;
 string cheminbruit2;
if (numeroSprite2<10)
{cheminbruit2="kanto/00"+to_string(numeroSprite2)+".ogg";}
else if (numeroSprite2<100)
{cheminbruit2="kanto/0"+to_string(numeroSprite2)+".ogg";}
else{cheminbruit2="kanto/"+to_string(numeroSprite2)+".ogg";}
 bruitsprite2.openFromFile(cheminbruit2);
    int index = 0;
    std::string fullText = "Le Maitre "+leaders[0].getNom() + " veut se battre !";
    string adversairepath="sprite/"+leaders[0].getNom()+".png";

    adversairetext.loadFromFile(adversairepath);
    sf::Sprite adversaire(adversairetext);
    adversaire.setScale(sf::Vector2f(4, 4));
    adversaire.setPosition(sf::Vector2f(670, 20));
    adversaire.setColor(sf::Color(255, 255, 255, 0));
    sprite2.setColor(sf::Color(255, 255, 255, 0));
    sprite.setColor(sf::Color(255, 255, 255, 0));
    rectanglesprite1.setFillColor(sf::Color(255, 255, 255, 0));
    rectanglesprite2.setFillColor(sf::Color(255, 255, 255, 0));
    PVsprite1.setFillColor(sf::Color(255, 255, 255, 0));
    PVsprite2.setFillColor(sf::Color(255, 255, 255, 0));
    typeami1Sprite.setColor(sf::Color(255, 255, 255, 0));
    typeami2Sprite.setColor(sf::Color(255, 255, 255, 0));
    typennemi1Sprite.setColor(sf::Color(255, 255, 255, 0));
    typeennemi2Sprite.setColor(sf::Color(255, 255, 255, 0));



bool affichfini=false;
    enum class PhaseCombat {
        Fondu,boost,
        Attente,
        AffichageTexte,
        Fin,Attenteavantpokemon,AffichagePokemon1,AffichagePokemon2,Menu,Attaque1,Attaque2,KO1,KO2
    };
    PhaseCombat phase = PhaseCombat::Fondu;
    sf::RectangleShape clickableZone(sf::Vector2f(200, 50)); 
    sf::Color zoneColor(100, 100, 250);
    clickableZone.setPosition(sf::Vector2<float>(550, 480)); 
    clickableZone.setFillColor(sf::Color(255, 255, 255,0)); 
 bool cligne=false;
 bool ko=false;
int pvapresattaque;
float coeff;
string efficacite="";;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }


        sf::Vector2i mousePos = sf::Mouse::getPosition(window); 
        bool isMouseOver = clickableZone.getGlobalBounds().contains(sf::Vector2<float>(mousePos.x, mousePos.y));
    
        if (isMouseOver) {
            window.setMouseCursor(hand);
        } else {
            window.setMouseCursor(arrow);
        }
        window.clear();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && isMouseOver) {coeff=leaders[0].getEquipe()[i1].gettype()[0].matricepokemon(joueur[0].getEquipe()[i2].gettype()[0]); 
            if (coeff==0.5){efficacite=" Ce n'est pas tres efficace... (x0.5)";notveryeffective.play();} 
        else if (coeff==2){efficacite="C'est super efficace ! (x2)";effective.play();}
        else if (coeff==0)efficacite="Ca n'affecte pas le "+leaders[0].getEquipe()[i1].getName()+" du Maitre.";else{okeffective.play();}
            text.setString("");index=0;fullText = joueur[0].getEquipe()[i2].getName() + " utilise " + joueur[0].getEquipe()[i2].getAttackName() + ".\n"+efficacite;efficacite="";
            text.setString("");  
            clock.restart();pvapresattaque=leaders[0].getEquipe()[i1].getHp()-joueur[0].getEquipe()[i2].getAttackDamage()*coeff;
            phase = PhaseCombat::Attaque1; 
        } 
        switch (phase) {
            case PhaseCombat::Fondu:
                if (clock.getElapsedTime().asMilliseconds() > 10 && alpha < 255) {
                    alpha += 1;
                    if (alpha >= 255) {
                        alpha = 255;
                        phase = PhaseCombat::Attente;
                        clock.restart();
                    }
                    terrain.setColor(sf::Color(255, 255, 255, alpha));
                    clock.restart();
                }
                break;

            case PhaseCombat::Attente:
                if (clock.getElapsedTime().asMilliseconds() > 2500) {
                    phase = PhaseCombat::AffichageTexte;
                    alpha = 0;
                    clock.restart();
                }
                break;

            case PhaseCombat::AffichageTexte: 
             
                if (clock.getElapsedTime().asSeconds() > 0.05f) {alpha+=6;
                    std::string displayedText = text.getString();
                    if (index < fullText.size()) {
                        displayedText += fullText[index];
                        text.setString(displayedText);
                        index++;
                        adversaire.setColor(sf::Color(255, 255, 255, alpha));
                        clock.restart();
                    } else { adversaire.setColor(sf::Color(255, 255, 255, 255));sf::sleep(sf::seconds(2));alpha=255;text.setString("");fullText="Le maitre Pokemon augmente ses attaques de 25 %";index=0;alpha=0;
                        phase = PhaseCombat::boost;clock.restart();
                    }
                }
                break;
                case PhaseCombat::boost:
                if (clock.getElapsedTime().asSeconds() > 0.05f ) {
                if (index < fullText.size()) { std::string displayedText = text.getString();
                    displayedText += fullText[index];
                    text.setString(displayedText);
                    index++;
                    clock.restart();
                } else {alpha=255; sf::sleep(sf::seconds(2));
                    phase = PhaseCombat::Attenteavantpokemon;clock.restart();index=0;
                }}
                break;
                case PhaseCombat::Attenteavantpokemon:
                
                if (clock.getElapsedTime().asMilliseconds() > 1500) { 
                    phase = PhaseCombat::AffichagePokemon1;
                    alpha = 0;
                    index = 0;
                    fullText = "Le Maitre "+leaders[0].getNom() + " envoie un " + leaders[0].getEquipe()[i1].getName() + "!";
                    text.setString(""); 
                  phase = PhaseCombat::AffichagePokemon1;bruitsprite1.play();
                    clock.restart();
                
                }
                break;
                case PhaseCombat::AffichagePokemon1: 
                adversaire.setColor(sf::Color(255,255,255,0));
                if (clock.getElapsedTime().asSeconds() > 0.03f) {alpha+=6;
                    std::string displayedText = text.getString();
                    if (index < fullText.size()) {
                        displayedText += fullText[index];
                        text.setString(displayedText);
                        index++;
                        sprite.setColor(sf::Color(255, 255, 255, alpha));
                        clock.restart();
                    } else if (ko==true)
                    {sprite.setColor(sf::Color(255,255,255,255));alpha=0;index = 0;
                        sf::sleep(sf::seconds(2)); text.setString("");phase=PhaseCombat::Menu;}
             
                    else {sprite.setColor(sf::Color(255,255,255,255));alpha=0;index = 0;rectanglesprite1.setFillColor(sf::Color(0, 0, 0, 128));PVsprite1.setFillColor(sf::Color(255, 255, 255, 255));    typennemi1Sprite.setColor(sf::Color(255, 255, 255, 255));
                        if (leaders[0].getEquipe()[i1].gettype()[1].getNom()!="Fee")
                        {
                          typeennemi2Sprite.setColor(sf::Color(255, 255, 255, 255));
                          }
                       sf::sleep(sf::seconds(2)); text.setString("");fullText="Vous envoyez un "+ joueur[0].getEquipe()[i2].getName() + "!"; phase=PhaseCombat::AffichagePokemon2;bruitsprite2.play();}}
                       break;
            case PhaseCombat::AffichagePokemon2:
           
            if (clock.getElapsedTime().asSeconds() > 0.03f && alpha < 255) {alpha+=9;
                std::string displayedText = text.getString();
                if (index < fullText.size()&&alpha<255) {
                    displayedText += fullText[index];
                    text.setString(displayedText);
                    index++;
                    sprite2.setColor(sf::Color(255, 255, 255, alpha));
                    clock.restart();
                } 
                else {alpha=0;index = 0;
                    sf::sleep(sf::seconds(1));rectanglesprite2.setFillColor(sf::Color(0, 0, 0, 128));PVsprite2.setFillColor(sf::Color(255, 255, 255, 255)); typeami1Sprite.setColor(sf::Color(255, 255, 255, 255));
                    
                    if (joueur[0].getEquipe()[i2].gettype()[1].getNom()!="Fee")
                    {
                        typeami2Sprite.setColor(sf::Color(255, 255, 255, 255));
                      }
                      sf::sleep(sf::seconds(1));
                   phase=PhaseCombat::Menu;}}
            
                    
                
               
                break;
            case PhaseCombat::Menu:
               text.setString("Que voulez vous faire ?      Attaquer        Sac \n                                    Pokemons        Fuir");sprite2.setColor(sf::Color(255,255,255,255));sprite.setColor(sf::Color(255,255,255,255));
                break;
         case PhaseCombat::Attaque1:
            if (clock.getElapsedTime().asSeconds() > 0.05f) { std::string displayedText = text.getString();
            if (index < fullText.size()) {
                displayedText += fullText[index];
                text.setString(displayedText);
                index++;if (leaders[0].getEquipe()[i1].getHp()>pvapresattaque&&leaders[0].getEquipe()[i1].getHp()>0)
                {leaders[0].getEquipe()[i1].sethp(leaders[0].getEquipe()[i1].getHp()-6);
                PVsprite1.setString(leaders[0].getEquipe()[i1].getName()+"   PV :"+to_string(leaders[0].getEquipe()[i1].getHp())+"/"+PVmaxsprite1);}
                if (leaders[0].getEquipe()[i1].getHp()<0){leaders[0].getEquipe()[i1].sethp(0); PVsprite1.setString(leaders[0].getEquipe()[i1].getName()+"   PV :"+to_string(leaders[0].getEquipe()[i1].getHp())+"/"+PVmaxsprite1);}
                else if (leaders[0].getEquipe()[i1].getHp()<pvapresattaque&&leaders[0].getEquipe()[i1].getHp()>0)
                {sprite.setColor(sf::Color(255,255,255,255));leaders[0].getEquipe()[i1].sethp(pvapresattaque);PVsprite1.setString(leaders[0].getEquipe()[i1].getName()+"   PV :"+to_string(pvapresattaque)+"/"+PVmaxsprite1);}
                
                if(!cligne){sprite.setColor(sf::Color(255,255,255,0));sprite2.setPosition(sf::Vector2f(105, 250));cligne=!cligne;}
                else{sprite.setColor(sf::Color(255,255,255,255));sprite2.setPosition(sf::Vector2f(100, 250));cligne=!cligne;}
                clock.restart();
            } else if(leaders[0].getEquipe()[i1].getHp()==0){sprite.setColor(sf::Color(255,255,255,255));phase=PhaseCombat::KO1;sf::sleep(sf::seconds(1)); text.setString("");index=0;fullText = leaders[0].getEquipe()[i1].getName() + " est totalement K.O !" ;
                text.setString(""); alpha=255;
                clock.restart();bruitsprite1.play();


            }
             else{sprite.setColor(sf::Color(255,255,255,255));sf::sleep(sf::seconds(2));coeff=joueur[0].getEquipe()[i2].gettype()[0].matricepokemon(leaders[0].getEquipe()[i1].gettype()[0]); 
                if (coeff==0.5){efficacite=" Ce n'est pas tres efficace... (x0.5)";notveryeffective.play();} 
            else if (coeff==2){efficacite="C'est super efficace !(x2)";effective.play();}
            else if (coeff==0)efficacite="Ca n'affecte pas votre "+joueur[0].getEquipe()[i2].getName()+".";else{okeffective.play();}
                phase=PhaseCombat::Attaque2; text.setString("");index=0;fullText = leaders[0].getEquipe()[i1].getName() + " utilise " + leaders[0].getEquipe()[i1].getAttackName() + ".\n"+efficacite;
                text.setString(""); 
                clock.restart();
                double degats = leaders[0].getEquipe()[i1].getAttackDamage() * coeff * 1.25;
                pvapresattaque=joueur[0].getEquipe()[i2].getHp()-(int)degats;}      }    
                if (index >= fullText.size()) sprite.setColor(sf::Color(255,255,255,255));
            break;
            case PhaseCombat::Attaque2:
        
            if (clock.getElapsedTime().asSeconds() > 0.05f) { std::string displayedText = text.getString();
            if (index < fullText.size()) {
                displayedText += fullText[index];
                text.setString(displayedText);
                index++;if (joueur[0].getEquipe()[i2].getHp()>pvapresattaque&&joueur[0].getEquipe()[i2].getHp()>0)
                {joueur[0].getEquipe()[i2].sethp(joueur[0].getEquipe()[i2].getHp()-6);
                PVsprite2.setString(joueur[0].getEquipe()[i2].getName()+"   PV :"+to_string(joueur[0].getEquipe()[i2].getHp())+"/"+PVmaxsprite2);}
                else if(joueur[0].getEquipe()[i2].getHp()<pvapresattaque&&joueur[0].getEquipe()[i2].getHp()>0){joueur[0].getEquipe()[i2].sethp(pvapresattaque);PVsprite2.setString(joueur[0].getEquipe()[i2].getName()+"   PV :"+to_string(pvapresattaque)+"/"+PVmaxsprite2);}
                if (joueur[0].getEquipe()[i2].getHp()<0){joueur[0].getEquipe()[i2].sethp(0); PVsprite2.setString(joueur[0].getEquipe()[i2].getName()+"   PV :"+to_string(joueur[0].getEquipe()[i2].getHp())+"/"+PVmaxsprite2);}
                
                
                if(!cligne){sprite2.setColor(sf::Color(255,255,255,0));sprite.setPosition(sf::Vector2f(675, 70));;cligne=!cligne;}  
                else{sprite2.setColor(sf::Color(255,255,255,255));sprite.setPosition(sf::Vector2f(670, 70));cligne=!cligne;}
            }
            
   
    
                
                else if(joueur[0].getEquipe()[i2].getHp()==0){sprite2.setColor(sf::Color(255,255,255,255));phase=PhaseCombat::KO2;sf::sleep(sf::seconds(1)); text.setString("");index=0;fullText = joueur[0].getEquipe()[i2].getName() + " est totalement K.O !" ;
                    text.setString(""); alpha=255;
                    clock.restart();bruitsprite2.play();   clock.restart();}
                else{sprite2.setColor(sf::Color(255,255,255,255));sf::sleep(sf::seconds(2));sprite.setPosition(sf::Vector2f(670, 20));cligne=!cligne;clock.restart();phase=PhaseCombat::Menu;}
                 clock.restart();  
               }      if (index >= fullText.size()) sprite2.setColor(sf::Color(255,255,255,255));  
            break;

            case PhaseCombat::KO2: 
        
            if (clock.getElapsedTime().asSeconds() > 0.03f ) {
                std::string displayedText = text.getString();
                if (index < fullText.size()) {
                    displayedText += fullText[index];
                    text.setString(displayedText);
                    index++;
                   
                 
                } 

               else{i2+=1;sprite2.setColor(sf::Color(255,255,255,0));
                if(i2==i2max){combat.stop();defaite.play(); text.setString("")  ;fullText = "Vous avez perdu contre "+leaders[0].getNom() + "...";alpha=0; index=0;phase=PhaseCombat::Fin;perdrecombat=true;}
                else{sf::sleep(sf::seconds(2));text.setString(""); ;ko=true;
                    numeroSprite2 = trouverIndexDansCSV(csvFile, joueur[0].getEquipe()[i2].getName()); spritePath2 = "sprite/back/" + to_string(numeroSprite2) + ".png";
                     spritetext2.loadFromFile(spritePath2);sprite2.setTexture(spritetext2);
                      fullText = "Vous envoyez un " + joueur[0].getEquipe()[i2].getName() + "!";     PVmaxsprite2=to_string(joueur[0].getEquipe()[i2].getHp());
                      PVsprite2.setString(joueur[0].getEquipe()[i2].getName()+"   PV :"+to_string(joueur[0].getEquipe()[i2].getHp())+"/"+PVmaxsprite2);
                      if (numeroSprite2<10)
                            {cheminbruit2="kanto/00"+to_string(numeroSprite2)+".ogg";}
                      else if (numeroSprite2<100)
                            {cheminbruit2="kanto/0"+to_string(numeroSprite2)+".ogg";}
                      else{cheminbruit2="kanto/"+to_string(numeroSprite2)+".ogg";}
                      if (joueur[0].getEquipe()[i2].gettype()[1].getNom()=="Fee")
                      {
                        typeami2Sprite.setColor(sf::Color(255, 255, 255, 0));
                        }
                        else{typeami2Sprite.setColor(sf::Color(255, 255, 255, 255));}
 bruitsprite2.openFromFile(cheminbruit2);typeami1path="typeicone/Miniature_Type_"+joueur[0].getEquipe()[i2].gettype()[0].getNom()+"_NB.png";
 typeami2path="typeicone/Miniature_Type_"+joueur[0].getEquipe()[i2].gettype()[1].getNom()+"_NB.png"; typeami1.loadFromFile(typeami1path);
 typeami2.loadFromFile(typeami2path);
                      index=0;alpha=0; clock.restart();phase=PhaseCombat::AffichagePokemon2;bruitsprite2.play();}
                      sprite2.setColor(sf::Color(255, 255, 255, 0));
                      clock.restart();
               
               }}
                break;


                case PhaseCombat::KO1: 
        
                if (clock.getElapsedTime().asSeconds() > 0.03f ) {
                    std::string displayedText = text.getString();
                    if (index < fullText.size()) {
                        displayedText += fullText[index];
                        text.setString(displayedText);
                        index++;
                       
                     
                    } 
    
                   else{sf::sleep(sf::seconds(2));i1+=1;sprite.setColor(sf::Color(255,255,255,0));
                    if(i1==imax){combat.stop();victory.play(); text.setString("")  ;fullText = "Vous avez battu Le maitre "+leaders[0].getNom() + "!\nVous devenez maitre.";alpha=0; index=0;phase=PhaseCombat::Fin;gagnercombat=true; }
                   
                   else{;text.setString(""); ko=true;
                        numeroSprite = trouverIndexDansCSV(csvFile, leaders[0].getEquipe()[i1].getName()); spritePath = "sprite/" + to_string(numeroSprite) + ".png";
                         spritetext.loadFromFile(spritePath);sprite.setTexture(spritetext);
                          fullText = leaders[0].getNom() + " envoie un " + leaders[0].getEquipe()[i1].getName() + "!";     PVmaxsprite1=to_string(leaders[0].getEquipe()[i1].getHp());
                          PVsprite1.setString(leaders[0].getEquipe()[i1].getName()+"   PV :"+to_string(leaders[0].getEquipe()[i1].getHp())+"/"+PVmaxsprite1);
                          if (numeroSprite<10)
                                {cheminbruit="kanto/00"+to_string(numeroSprite)+".ogg";}
                          else if (numeroSprite<100)
                                {cheminbruit="kanto/0"+to_string(numeroSprite)+".ogg";}
                          else{cheminbruit="kanto/"+to_string(numeroSprite)+".ogg";} 

                        bruitsprite1.openFromFile(cheminbruit);    typeennemi1path="typeicone/Miniature_Type_"+leaders[0].getEquipe()[i1].gettype()[0].getNom()+"_NB.png";
                         typeennemi2path="typeicone/Miniature_Type_"+leaders[0].getEquipe()[i1].gettype()[1].getNom()+"_NB.png"; typennemi1.loadFromFile(typeennemi1path);
                         typeennemi2.loadFromFile(typeennemi2path);
                          index=0;alpha=0; clock.restart();phase=PhaseCombat::AffichagePokemon1;bruitsprite1.play();
                          sprite.setColor(sf::Color(255, 255, 255, 0));                         
                           if (leaders[0].getEquipe()[i1].gettype()[1].getNom()=="Fee")
                          {
                            typeennemi2Sprite.setColor(sf::Color(255, 255, 255, 0));
                            }
                            else{typeennemi2Sprite.setColor(sf::Color(255, 255, 255, 255));}
                          clock.restart();
                   
                   }}}
                    break;
                    case PhaseCombat::Fin:
                    sprite.setColor(sf::Color(255, 255, 255, 0));
                    sprite2.setColor(sf::Color(255, 255, 255, 0));
                    rectanglesprite1.setFillColor(sf::Color(255, 255, 255,0));
                    rectanglesprite2.setFillColor(sf::Color(255, 255, 255, 0));
                    PVsprite1.setFillColor(sf::Color(255, 255, 255, 0));
                    PVsprite2.setFillColor(sf::Color(255, 255, 255, 0));
                    typeennemi2Sprite.setColor(sf::Color(255, 255, 255, 0));
                    typeami1Sprite.setColor(sf::Color(255, 255, 255, 0));
                    typeami2Sprite.setColor(sf::Color(255, 255, 255, 0));
                    typennemi1Sprite.setColor(sf::Color(255, 255, 255, 0));

                    if (clock.getElapsedTime().asSeconds() > 0.04f ) {
                        std::string displayedText = text.getString();
                        if (index < fullText.size()) 
                        { displayedText += fullText[index];
                            text.setString(displayedText);
                            index++;if(alpha<255)alpha+=9;else{alpha=255;} adversaire.setColor(sf::Color(255, 255, 255, alpha));
                        }
                        else {adversaire.setColor(sf::Color(255, 255, 255, 255));sf::sleep(sf::seconds(5));window.close();}
                       clock.restart(); }
                        break;


                    
         
        }
        
        window.draw(terrain);
        window.draw(sprite);
        window.draw(sprite2);
        window.draw(rectangle);
        window.draw(text);
        window.draw(adversaire);
        window.draw(clickableZone);
        window.draw(rectanglesprite1);
        window.draw(rectanglesprite2);
        window.draw(PVsprite1);
        window.draw(PVsprite2);
        window.draw(typennemi1Sprite);
        window.draw(typeennemi2Sprite);
        window.draw(typeami1Sprite);
        window.draw(typeami2Sprite);
      
        window.display();

    }
}
LeaderDeGym saisirLeader(vector<Pokemon> pokemonliste) {
    std::string nom, gymnase, badge, pokemon;
    std::vector<Pokemon> pokemons;

    std::cout << "";
    std::getline(cin, nom);
    std::cout << "Nom du leader : ";
    std::getline(cin, nom);
    std::cout << "Nom du gymnase : ";
    std::getline(cin, gymnase);

    std::cout << "Saisir jusqu'à 6 Pokémon (entrez '0' pour arrêter) :\n";
    for (int i = 0; i < 6; ++i) {
        std::cout << "Pokemon " << (i + 1) << " : ";
        std::getline(cin, pokemon);
        if (pokemon == "0") break;
        try{
        pokemons.push_back(trouverPokemonParNom(pokemon,pokemonliste));}
        catch (const std::exception& e) {
            std::cerr << e.what() << '\n';i--;
    }}

  


    return LeaderDeGym (nom, pokemons, badge, gymnase);
} 

MaîtrePokémon saisirMaitre(vector<Pokemon> pokemonliste) {
    std::string nom, gymnase, badge, pokemon;
    std::vector<Pokemon> pokemons;

    std::cout << "";
    nom="Regis";

    std::cout << "Saisir jusqu'à 6 Pokémon (entrez '0' pour arrêter) :\n";
    for (int i = 0; i < 6; ++i) {
        std::cout << "Pokemon " << (i + 1) << " : ";
        std::getline(cin, pokemon);
        if (pokemon == "0") break;
        try{
        pokemons.push_back(trouverPokemonParNom(pokemon,pokemonliste));}
        catch (const std::exception& e) {
            std::cerr << e.what() << '\n';i--;
    }}

    


    return MaîtrePokémon (nom, pokemons);
} 


 class::Joueur saisirJoueur(vector<Pokemon> pokemonliste)
{
    std::string nom, gymnase, badge, pokemon;
    std::vector<Pokemon> pokemons;

    std::cout << "Quel est votre nom ?";
    cin>>nom;

    std::cout << "Saisir jusqu'à 6 Pokémon (entrez '0' pour arrêter) :\n";
    for (int i = 0; i < 6; ++i) {
        std::cout << "Pokemon " << (i + 1) << " : ";
        std::getline(cin, pokemon);
        if (pokemon == "0") break;
        try{
        pokemons.push_back(trouverPokemonParNom(pokemon,pokemonliste));}
        catch (const std::exception& e) {
            std::cerr << e.what() << '\n';i--;
    }}

  return Joueur(nom,pokemons);
}


void ajouterLeaderCSV(const std::string& cheminFichier,  LeaderDeGym leader) {
    std::ofstream fichier(cheminFichier, std::ios::app); int k=0;
    if (!fichier.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier CSV.\n";
        return;
    }
    fichier<<"\n";
    fichier << leader.getNom() << ","
            << leader.getGymnase();

    for (const auto p : leader.getEquipe()) {
        fichier << "," << p.getName();k+=1;
    }
while(k!=6){fichier << ",";k++;}
    fichier.close();
    std::cout << "Leader ajouté avec succès !\n";
}

void modifMaitreCSV(const std::string& cheminFichier,  MaîtrePokémon leader) {
    std::ofstream fichier(cheminFichier, std::ios::app); int k=0;
    if (!fichier.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier CSV.\n";
        return;
    }
    fichier<<"\n";
    fichier << "Regis";

    for (const auto p : leader.getEquipe()) {
        fichier << "," << p.getName();k+=1;
    }
while(k!=6){fichier << ",";k++;}
    fichier.close();
    std::cout << "Maitre modifié avec succès !\n";
}

void modifJoueurCSV(const std::string& cheminFichier,  Joueur leader) {
    std::ofstream fichier(cheminFichier, std::ios::app); int k=0;
    if (!fichier.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier CSV.\n";
        return;
    }
    fichier<<"\n";
    fichier << leader.getNom();

    for (const auto p : leader.getEquipe()) {
        fichier << "," << p.getName();k+=1;
    }
while(k!=6){fichier << ",";k++;}
    fichier.close();
    std::cout << "Joueur modifié avec succès !\n";
}
void supprimerLigneCSV(const std::string& nomFichier, int ligneASupprimer) {
    std::ifstream fichierIn(nomFichier);
    std::vector<std::string> lignes;
    std::string ligne;
    int numero = 1;

  
    while (std::getline(fichierIn, ligne)) {
        if (numero != ligneASupprimer) {
            lignes.push_back(ligne);
        }
        ++numero;
    }
    fichierIn.close();

   
    std::ofstream fichierOut("temp.csv");
    for (size_t i = 0; i < lignes.size(); ++i) {
        fichierOut << lignes[i];
        if (i != lignes.size() - 1) {
            fichierOut << "\n";
        }
    }
    fichierOut.close();

    std::remove(nomFichier.c_str());
    std::rename("temp.csv", nomFichier.c_str());
}
 
int main()
    {      setlocale(LC_ALL, "fr_FR.UTF-8");
       int numerotype=0;
       vector<Type> Alltypes;
        for (const auto& typeName : typeNames) { if (typeNames.empty()) {
            std::cerr << "typeNames est vide !" << std::endl;}
            if (numerotype >= typeNames.size()) {
                std::cerr << "Numerotype est hors limites !" << std::endl;}
         
            Type i(typeName,numerotype);Alltypes.push_back(i);
            cout << typeName << " créé" << endl;numerotype++;
        }
            
        
        
            cout<<"oui";
    
     vector<Pokemon> pokemons = loadPokemons("pokemon2.csv",Alltypes);
     vector<Joueur> joueurs = loadJoueurs("joueur.csv", pokemons);

   
    vector<LeaderDeGym> leaders = loadLeaders("leaders.csv",pokemons);

  
    vector<MaîtrePokémon> maitres = loadMaitres("maitres.csv",pokemons);
    for (const auto& pokemon : pokemons) {
        pokemon.printInfo();
    }  
   for (const auto& joueur : joueurs) {
        joueur.afficherEquipe();
        joueur.afficherStats();  
    }


    for (const auto& leader : leaders) {
        leader.afficherGymnase();
        leader.afficherBadge();
        leader.afficherEquipe();
    }

  
    for (const auto& maitre : maitres) {
        maitre.afficherEquipe();
        maitre.afficherBoost();
        
    }

    
bool vrai=true;

cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n  \n \n \n \n \n \n "<<endl;
cout<< "Bonjour , "+joueurs[0].getNom()<<endl;
while (vrai==true){cout<<"\n \n \n" ;
if(gagnerbadge==true){joueurs[0].gagnerBadge();gagnerbadge=false;}
if(perdrecombat==true){joueurs[0].perdreCombat();perdrecombat=false;}
if(gagnercombat==true){joueurs[0].gagnerCombat();gagnercombat=false;}
joueurs[0].afficherStats();
cout<<"\n \n \n" ;
cout<<"\n"<<"Que voulez vous faire ?"<<endl;
cout<<"1. Ajouter un leader"<<endl;
cout<<"2. Supprimer un leader"<<endl;
cout<<"3. Combattre un leader"<<endl;
cout<<"4. Modifier le maitre"<<endl;
cout<<"5. Combattre le maitre"<<endl;
cout<<"6. Changez vos pokémons"<<endl;
cout<<"0. Sortir"<<endl;
int a;
cin>>a;
if (a==1)
{LeaderDeGym nvleader=saisirLeader(pokemons);
ajouterLeaderCSV("leaders.csv",nvleader);
leaders.push_back(nvleader);
}


if (a==2)
{ cout<<"\n\n\n\n\n\n\n\n";cout<<"Quel Leader souhaitez vous supprimer ?( mettre le numéro) "<<endl;int b=1;
for(const auto& leader : leaders)
{cout<<b<<". "<<leader.getNom()<<endl;b++;}
int a;
cin>>a;
supprimerLigneCSV("leaders.csv",a+1);
leaders = loadLeaders("leaders.csv",pokemons);
}
if(a==4)
{
MaîtrePokémon nvmaitre=saisirMaitre(pokemons);
supprimerLigneCSV("maitres.csv",2);
modifMaitreCSV("maitres.csv",nvmaitre);
maitres=loadMaitres("maitres.csv",pokemons);
cout<<"\n\n\n\n\n\n\n\n";
}
if (a==5)
{  if (maitres[0].getEquipe().size()==0){cout<<"\n\n\n\n";cout<<"Le maitre n'a pas de pokemon impossible de le combattre."<<endl;}
    else if (joueurs[0].getBadge()<leaders.size())
    {   cout<<"\n\n\n\n\n\n\n\n";
        cout<<"Vous n'avez pas le nombre de badge suffisant pour combattre le maitre."<<endl;
        cout<<"Requis :"<<leaders.size()<<endl;
        cout<<"Nombre de badges dont vous disposez : "<<joueurs[0].getBadge()<<endl;
    }
  else{combatmaitre(maitres,joueurs,maitres[0].getEquipe().size(),joueurs[0].getEquipe().size());cout<<"\n\n\n\n\n\n\n\n";}
}
if (a==3)
{       if (joueurs[0].getBadge()==leaders.size())
    {   cout<<"\n\n\n\n\n\n\n\n";
        cout<<"Vous avez battu tous les leaders possible."<<endl;
    }
   else  if (leaders[joueurs[0].getBadge()].getEquipe().size()==0){cout<<"\n\n\n\n";cout<<"Le Leader que vous devez affronter n'a pas de pokemon, impossible de le combattre."<<endl;}

  else{combat(leaders,joueurs,leaders[joueurs[0].getBadge()].getEquipe().size(),joueurs[0].getEquipe().size(),joueurs[0].getBadge());cout<<"\n\n\n\n\n\n\n\n";}


}
if(a==6)
{ cout<<"\n\n\n\n\n\n\n\n";
Joueur nvjoueur=saisirJoueur(pokemons);
supprimerLigneCSV("joueur.csv",2);
modifJoueurCSV("joueur.csv",nvjoueur);
joueurs=loadJoueurs("joueur.csv",pokemons);
cout<<"\n\n\n\n";  
}
if (a==0)return 0;
 
}

    
    

    }

    




