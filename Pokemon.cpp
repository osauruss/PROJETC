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
    "Feu", "Eau", "Plante", "Électrik", "Glace", "Combat", "Poison",
    "Sol", "Vol", "Psy", "Insecte", "Roche", "Spectre", "Dragon",
    "Tenebres", "Acier", "Fee"
};

class Type {
    private:
        std::string nom;
        int numero; 

    
    public:
    float matrice[18][18] = {
        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 0.0, 1.0, 1.0, 0.5, 1.0},
        {1.0, 0.5, 0.5, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 1.0, 2.0, 1.0},
        {1.0, 2.0, 0.5, 0.5, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0, 1.0, 1.0},
        {1.0, 0.5, 2.0, 0.5, 1.0, 1.0, 1.0, 0.5, 2.0, 0.5, 1.0, 0.5, 2.0, 1.0, 0.5, 1.0, 0.5, 1.0},
        {1.0, 1.0, 2.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0},
        {1.0, 0.5, 0.5, 2.0, 1.0, 0.5, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0},
        {2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 0.5, 0.5, 0.5, 0.5, 2.0, 0.0, 1.0, 2.0, 2.0, 1.0},
        {1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 1.0, 0.5, 0.5, 1.0, 1.0, 0.0, 1.0},
        {1.0, 2.0, 1.0, 0.5, 2.0, 1.0, 1.0, 2.0, 1.0, 0.0, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 2.0, 1.0},
        {1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 1.0, 1.0, 0.5, 1.0},
        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 2.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 0.0, 0.5, 1.0, 1.0},
        {1.0, 0.5, 1.0, 2.0, 1.0, 1.0, 0.5, 0.5, 1.0, 0.5, 2.0, 1.0, 1.0, 0.5, 1.0, 2.0, 0.5, 1.0},
        {1.0, 2.0, 1.0, 1.0, 1.0, 2.0, 0.5, 1.0, 0.5, 2.0, 1.0, 2.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0},
        {0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 0.5, 0.5, 1.0},
        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 0.5, 1.0},
        {1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.5, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 2.0, 1.0, 0.5, 0.5, 1.0},
        {1.0, 0.5, 0.5, 1.0, 0.5, 2.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0, 1.0, 1.0, 0.5, 1.0},
        {1.0, 0.5, 0.5, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 2.0, 1.0}
    };
        Type(const std::string& nom,int numero)
            : nom(nom), numero(numero) {} // Incrémenter et assigner
    
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
            // Constructeur
            MaîtrePokémon(const std::string& nom,const vector<Pokemon>equipe) 
                : Entraineur(nom,equipe), boostDegats(1.25) {}
        
            // Appliquer le boost de dégâts à un Pokémon
            void appliquerBoost(Pokemon& p) const {
                p.setattackdamage(p.getAttackDamage() * boostDegats);
            }
        
            // Afficher des informations supplémentaires pour le Maître Pokémon si nécessaire
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
            cout<<"yes";
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
        while (getline(file, line)) {cout<<"oui";
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
        cout<<"OUI";
        file.close();
        return pokemons;
    }

    Pokemon trouverPokemonParNom(const std::string& nomPokemon, std::vector<Pokemon>& pokemons) {
        for (auto& pokemon : pokemons) {
            if (pokemon.getName() == nomPokemon) {
                return pokemon;  // Retourne un pointeur vers le Pokémon trouvé
            }
        }
        return pokemons[0];  // Aucun Pokémon trouvé avec ce nom
    }

  
// Chargement des Joueurs
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
        getline(ss, nom, ',');
        getline(ss, pok1, ',');
        getline(ss, pok2, ',');
        getline(ss, pok3, ',');
        getline(ss, pok4, ',');
        getline(ss, pok5, ',');
        getline(ss, pok6, ',');
        vector<Pokemon> pokemonsleader={trouverPokemonParNom(pok1,pokemons),
            trouverPokemonParNom(pok2,pokemons),
            trouverPokemonParNom(pok3,pokemons),
            trouverPokemonParNom(pok4,pokemons),
            trouverPokemonParNom(pok5,pokemons),
            trouverPokemonParNom(pok6,pokemons)};
        joueurs.push_back(Joueur(nom,pokemonsleader));


    file.close();
    return joueurs;
}}



// Chargement des Leaders de Gym
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
        getline(ss, pok1, ',');
        getline(ss, pok2, ',');
        getline(ss, pok3, ',');
        getline(ss, pok4, ',');
        getline(ss, pok5, ',');
        getline(ss, pok6, ',');
        vector<Pokemon> pokemonsleader={trouverPokemonParNom(pok1,pokemons),
            trouverPokemonParNom(pok2,pokemons),
            trouverPokemonParNom(pok3,pokemons),
            trouverPokemonParNom(pok4,pokemons),
            trouverPokemonParNom(pok5,pokemons),
            trouverPokemonParNom(pok6,pokemons)};
        leaders.push_back(LeaderDeGym(nom,pokemonsleader, badge, gymnase));
     
    }

    file.close();
    return leaders;
}



// Chargement des Maîtres Pokémon
vector<MaîtrePokémon> loadMaitres(const string& filename,vector<Pokemon> pokemons) {
    vector<MaîtrePokémon> maitres;
    string line;
    ifstream file(filename);
    getline(file, line);
    while (getline(file, line)) {
        stringstream ss(line);
        string nom, badge, gymnase,pok1,pok2,pok3,pok4,pok5,pok6;
        getline(ss, nom, ',');
        getline(ss, badge, ',');
        getline(ss, pok1, ',');
        getline(ss, pok2, ',');
        getline(ss, pok3, ',');
        getline(ss, pok4, ',');
        getline(ss, pok5, ',');
        getline(ss, pok6, ',');
        vector<Pokemon> pokemonsleader={trouverPokemonParNom(pok1,pokemons),
            trouverPokemonParNom(pok2,pokemons),
            trouverPokemonParNom(pok3,pokemons),
            trouverPokemonParNom(pok4,pokemons),
            trouverPokemonParNom(pok5,pokemons),
            trouverPokemonParNom(pok6,pokemons)};
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
    getline(file, line); // Sauter l'en-tête

    while (getline(file, line)) {
        stringstream ss(line);
        string nom;
        getline(ss, nom, ','); // On lit le nom du Pokémon

        if (nom == nomPokemonRecherche) {
            return index + 1; // Les sprites commencent à 1.png donc on ajoute +1
        }
        index++;
    }

    return -1; // Pas trouvé
}

    
    
void combat(vector<LeaderDeGym> leaders,vector<Joueur> joueur) 
{ int i1=0;int i2=0;
    const auto hand = sf::Cursor::createFromSystem(sf::Cursor::Type::Hand).value();
    const auto arrow = sf::Cursor::createFromSystem(sf::Cursor::Type::Arrow).value();
    string csvFile = "pokemon.csv";
   

    int numeroSprite = trouverIndexDansCSV(csvFile, leaders[0].getEquipe()[i1].getName());
    int numeroSprite2 = trouverIndexDansCSV(csvFile, joueur[0].getEquipe()[i2].getName());
    if (numeroSprite == -1) {
        cerr << "Impossible de trouver " << leaders[0].getEquipe()[i1].getName() << " dans le fichier CSV." << endl;
    }

    cout << leaders[0].getEquipe()[i1].getName() << " est le " << numeroSprite << "eme Pokémon dans le CSV." << endl;

    sf::RenderWindow window(sf::VideoMode({1200, 600}), "Pokemon Esilv Edition");
    sf::CircleShape shape(1.f);
    shape.setFillColor(sf::Color::Green);

    string spritePath = "sprite/" + to_string(numeroSprite) + ".png";
    string spritePath2 = "sprite/back/" + to_string(numeroSprite2) + ".png";
    string terrainPath = "sprite/terrain1.jpeg";
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


    cout << spritePath;

    sf::Sprite sprite(spritetext);
    sf::Sprite sprite2(spritetext2);
    sf::Sprite terrain(terraintext);
    sf::Sprite typennemi1Sprite(typennemi1);
    sf::Sprite typeennemi2Sprite(typeennemi2);
    sf::Sprite typeami1Sprite(typeami1);
    sf::Sprite typeami2Sprite(typeami2);
    sprite.setPosition(sf::Vector2f(670, 20));
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
    if (!combat.openFromFile("combat1.ogg")) {
        cerr << "Erreur de chargement de la musique !" << endl;
    }
    combat.setLooping(true);
    combat.play();
    combat.setVolume(40);
    sf::Music effective;
    effective.openFromFile("effective.ogg");
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
    std::string fullText = leaders[0].getNom() + " veut se battre !";
    string adversairepath="sprite/"+leaders[0].getNom()+".png";
    cout << adversairepath;
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
    sf::RectangleShape clickableZone(sf::Vector2f(200, 50)); // Taille de la zone cliquable (ex : 200x50)
    sf::Color zoneColor(100, 100, 250);
    clickableZone.setPosition(sf::Vector2<float>(550, 480)); // Position de la zone (ex : en bas à droite)
    clickableZone.setFillColor(sf::Color(255, 255, 255, 160)); // Vérifier si la souris est sur la zone
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


        sf::Vector2i mousePos = sf::Mouse::getPosition(window); // Obtenir la position de la souris
        bool isMouseOver = clickableZone.getGlobalBounds().contains(sf::Vector2<float>(mousePos.x, mousePos.y));
    
        if (isMouseOver) {
            window.setMouseCursor(hand);
        } else {
            window.setMouseCursor(arrow);
        }
        window.clear();
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && isMouseOver) {coeff=leaders[0].getEquipe()[i1].gettype()[0].matricepokemon(joueur[0].getEquipe()[i2].gettype()[0]); 
            if (coeff==0.5){efficacite=" Ce n est pas tres efficace... (x0.5)";notveryeffective.play();} 
        else if (coeff==2){efficacite="C est super efficace !(x2)";effective.play();}
        else if (coeff==0)efficacite="Ca n affecte pas le "+leaders[0].getEquipe()[i1].getName()+" ennemi.";else{okeffective.play();}
            std::cout << "Zone cliquée!" << std::endl;text.setString("");index=0;fullText = joueur[0].getEquipe()[i2].getName() + " utilise " + joueur[0].getEquipe()[i2].getAttackName() + ".\n"+efficacite;efficacite="";
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
             
                if (clock.getElapsedTime().asSeconds() > 0.05f & alpha < 255) {alpha+=10;
                    std::string displayedText = text.getString();
                    if (index < fullText.size()&alpha<255) {
                        displayedText += fullText[index];
                        text.setString(displayedText);
                        index++;
                        adversaire.setColor(sf::Color(255, 255, 255, alpha));
                        clock.restart();
                    } else {alpha=255;cout<<"OK!";
                        phase = PhaseCombat::Attenteavantpokemon;clock.restart();
                    }
                }
                break;
                case PhaseCombat::Attenteavantpokemon:
                
                if (clock.getElapsedTime().asMilliseconds() > 1500) { 
                    phase = PhaseCombat::AffichagePokemon1;
                    alpha = 0;
                    index = 0;
                    fullText = leaders[0].getNom() + " envoie un " + leaders[0].getEquipe()[i1].getName() + "!";
                    text.setString(""); // Reset le texte
                    cout<<fullText;phase = PhaseCombat::AffichagePokemon1;bruitsprite1.play();
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
                    {sprite.setColor(sf::Color(255,255,255,255));alpha=0;index = 0;cout<<"okidoki!";
                        sf::sleep(sf::seconds(2)); text.setString("");phase=PhaseCombat::Menu;}
             
                    else {alpha=0;index = 0;cout<<"ok!";rectanglesprite1.setFillColor(sf::Color(0, 0, 0, 128));PVsprite1.setFillColor(sf::Color(255, 255, 255, 255));    typennemi1Sprite.setColor(sf::Color(255, 255, 255, 255));
                        typeennemi2Sprite.setColor(sf::Color(255, 255, 255, 255));
                       sf::sleep(sf::seconds(2)); text.setString("");fullText="Vous envoyez un "+ joueur[0].getEquipe()[i2].getName() + "!";cout<<fullText; phase=PhaseCombat::AffichagePokemon2;bruitsprite2.play();}}
                       break;
            case PhaseCombat::AffichagePokemon2:
           
            if (clock.getElapsedTime().asSeconds() > 0.03f && alpha < 255) {alpha+=9;cout<<"ok!!!";
                std::string displayedText = text.getString();
                if (index < fullText.size()&&alpha<255) {
                    displayedText += fullText[index];
                    text.setString(displayedText);
                    index++;
                    sprite2.setColor(sf::Color(255, 255, 255, alpha));
                    clock.restart();
                } 
                else {alpha=0;index = 0;cout<<"ok!";
                    sf::sleep(sf::seconds(1));cout<<"ok!";rectanglesprite2.setFillColor(sf::Color(0, 0, 0, 128));PVsprite2.setFillColor(sf::Color(255, 255, 255, 255)); typeami1Sprite.setColor(sf::Color(255, 255, 255, 255));
                    typeami2Sprite.setColor(sf::Color(255, 255, 255, 255));sf::sleep(sf::seconds(1));
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
                {leaders[0].getEquipe()[i1].sethp(leaders[0].getEquipe()[i1].getHp()-4);
                PVsprite1.setString(leaders[0].getEquipe()[i1].getName()+"   PV :"+to_string(leaders[0].getEquipe()[i1].getHp())+"/"+PVmaxsprite1);}
                if (leaders[0].getEquipe()[i1].getHp()<0){leaders[0].getEquipe()[i1].sethp(0); PVsprite1.setString(leaders[0].getEquipe()[i1].getName()+"   PV :"+to_string(leaders[0].getEquipe()[i1].getHp())+"/"+PVmaxsprite1);}
                else if (leaders[0].getEquipe()[i1].getHp()<pvapresattaque&&leaders[0].getEquipe()[i1].getHp()>0)
                {sprite.setColor(sf::Color(255,255,255,255));leaders[0].getEquipe()[i1].sethp(pvapresattaque);PVsprite1.setString(leaders[0].getEquipe()[i1].getName()+"   PV :"+to_string(pvapresattaque)+"/"+PVmaxsprite1);}
                
                if(!cligne){sprite.setColor(sf::Color(255,255,255,0));sprite2.setPosition(sf::Vector2f(105, 250));cligne=!cligne;}
                else{sprite.setColor(sf::Color(255,255,255,255));sprite2.setPosition(sf::Vector2f(100, 250));cligne=!cligne;}
                clock.restart();
            } else if(sprite.setColor(sf::Color(255,255,255,255));leaders[0].getEquipe()[i1].getHp()==0){phase=PhaseCombat::KO1;sf::sleep(sf::seconds(1)); text.setString("");index=0;fullText = leaders[0].getEquipe()[i1].getName() + " est totalement K.O !" ;
                text.setString(""); alpha=255;
                clock.restart();bruitsprite1.play();cout<<"oui";


            }
             else{sf::sleep(sf::seconds(2));coeff=leaders[0].getEquipe()[i1].gettype()[0].matricepokemon(joueur[0].getEquipe()[i2].gettype()[0]); 
                if (coeff==0.5){efficacite=" Ce n est pas tres efficace... (x0.5)";notveryeffective.play();} 
            else if (coeff==2){efficacite="C est super efficace !(x2)";effective.play();}
            else if (coeff==0)efficacite="Ca n affecte pas votre "+joueur[0].getEquipe()[i2].getName()+".";else{okeffective.play();}
                
                sf::Color(255,255,255,255);phase=PhaseCombat::Attaque2; text.setString("");index=0;fullText = leaders[0].getEquipe()[i1].getName() + " utilise " + leaders[0].getEquipe()[i1].getAttackName() + ".\n"+efficacite;
                text.setString(""); cout<<"non";
                clock.restart();
                pvapresattaque=joueur[0].getEquipe()[i2].getHp()-leaders[0].getEquipe()[i1].getAttackDamage()*coeff;}      }    
            break;
            case PhaseCombat::Attaque2:
        
            if (clock.getElapsedTime().asSeconds() > 0.05f) { std::string displayedText = text.getString();
            if (index < fullText.size()) {
                displayedText += fullText[index];
                text.setString(displayedText);
                index++;if (joueur[0].getEquipe()[i2].getHp()>pvapresattaque&&joueur[0].getEquipe()[i2].getHp()>0)
                {joueur[0].getEquipe()[i2].sethp(joueur[0].getEquipe()[i2].getHp()-2);
                PVsprite2.setString(joueur[0].getEquipe()[i2].getName()+"   PV :"+to_string(joueur[0].getEquipe()[i2].getHp())+"/"+PVmaxsprite2);}
                else if(joueur[0].getEquipe()[i2].getHp()<pvapresattaque&&joueur[0].getEquipe()[i2].getHp()>0){joueur[0].getEquipe()[i2].sethp(pvapresattaque);PVsprite2.setString(joueur[0].getEquipe()[i2].getName()+"   PV :"+to_string(pvapresattaque)+"/"+PVmaxsprite2);}
                if (joueur[0].getEquipe()[i2].getHp()<0){joueur[0].getEquipe()[i2].sethp(0); PVsprite2.setString(joueur[0].getEquipe()[i2].getName()+"   PV :"+to_string(joueur[0].getEquipe()[i2].getHp())+"/"+PVmaxsprite2);}
                
                
                if(!cligne){sprite2.setColor(sf::Color(255,255,255,0));sprite.setPosition(sf::Vector2f(675, 20));;cligne=!cligne;}  
                else{sprite2.setColor(sf::Color(255,255,255,255));sprite.setPosition(sf::Vector2f(670, 20));cligne=!cligne;}
            }
            
   
    
                
                else if(joueur[0].getEquipe()[i2].getHp()==0){sprite2.setColor(sf::Color(255,255,255,0));phase=PhaseCombat::KO2;sf::sleep(sf::seconds(1)); text.setString("");index=0;fullText = joueur[0].getEquipe()[i2].getName() + " est totalement K.O !" ;
                    text.setString(""); alpha=255;
                    clock.restart();bruitsprite2.play();cout<<"oui";   clock.restart();}
                else{sf::sleep(sf::seconds(2));sprite2.setColor(sf::Color(255,255,255,255));sprite.setPosition(sf::Vector2f(670, 20));cligne=!cligne;clock.restart();phase=PhaseCombat::Menu;}
                cout<<"a";  clock.restart();  
               }       
            break;

            case PhaseCombat::KO2: 
        
            if (clock.getElapsedTime().asSeconds() > 0.03f ) {
                std::string displayedText = text.getString();
                if (index < fullText.size()) {
                    displayedText += fullText[index];
                    text.setString(displayedText);
                    index++;
                   
                 
                } 

               else{sf::sleep(sf::seconds(2));i2+=1;cout<<"test1";text.setString(""); sprite2.setColor(sf::Color(255,255,255,0));cout<<"test2";ko=true;
                    numeroSprite2 = trouverIndexDansCSV(csvFile, joueur[0].getEquipe()[i2].getName()); spritePath2 = "sprite/back/" + to_string(numeroSprite2) + ".png";
                     spritetext2.loadFromFile(spritePath2);sprite2.setTexture(spritetext2);
                      fullText = "Vous envoyez un " + joueur[0].getEquipe()[i2].getName() + "!";     PVmaxsprite2=to_string(joueur[0].getEquipe()[i2].getHp());
                      PVsprite2.setString(joueur[0].getEquipe()[i2].getName()+"   PV :"+to_string(joueur[0].getEquipe()[i2].getHp())+"/"+PVmaxsprite2);
                      if (numeroSprite2<10)
                            {cheminbruit2="kanto/00"+to_string(numeroSprite2)+".ogg";}
                      else if (numeroSprite2<100)
                            {cheminbruit2="kanto/0"+to_string(numeroSprite2)+".ogg";}
                      else{cheminbruit2="kanto/"+to_string(numeroSprite2)+".ogg";}
 bruitsprite2.openFromFile(cheminbruit2);typeami1path="typeicone/Miniature_Type_"+joueur[0].getEquipe()[i2].gettype()[0].getNom()+"_NB.png";
 typeami2path="typeicone/Miniature_Type_"+joueur[0].getEquipe()[i2].gettype()[1].getNom()+"_NB.png"; typeami1.loadFromFile(typeami1path);
 typeami2.loadFromFile(typeami2path);
                      index=0;alpha=0; clock.restart();phase=PhaseCombat::AffichagePokemon2;bruitsprite2.play();}
                      sprite2.setColor(sf::Color(255, 255, 255, 0));
                      clock.restart();
               
            }
                break;


                case PhaseCombat::KO1: 
        
                if (clock.getElapsedTime().asSeconds() > 0.03f ) {
                    std::string displayedText = text.getString();
                    if (index < fullText.size()) {
                        displayedText += fullText[index];
                        text.setString(displayedText);
                        index++;
                       
                     
                    } 
    
                   else{sf::sleep(sf::seconds(2));i1+=1;cout<<"test1";text.setString(""); sprite.setColor(sf::Color(255,255,255,0));cout<<"test2";ko=true;
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
                          index=0;alpha=0; clock.restart();phase=PhaseCombat::AffichagePokemon1;bruitsprite1.play();}
                          sprite.setColor(sf::Color(255, 255, 255, 0));
                          clock.restart();
                   
                }
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


    
    
    int main()
    {  try {    setlocale(LC_ALL, "fr_FR.UTF-8");
       int numerotype=0;
       vector<Type> Alltypes;
        for (const auto& typeName : typeNames) { if (typeNames.empty()) {
            std::cerr << "typeNames est vide !" << std::endl;}
            if (numerotype >= typeNames.size()) {
                std::cerr << "Numerotype est hors limites !" << std::endl;}
            // Gestion d'erreur ici// attention : "typeName" au singulier ici
            Type i(typeName,numerotype);Alltypes.push_back(i);
            cout << typeName << " créé" << endl;numerotype++;
        }
            
        
        
            cout<<"oui";
     vector<Pokemon> pokemons = loadPokemons("pokemon.csv",Alltypes);
     vector<Joueur> joueurs = loadJoueurs("joueur.csv", pokemons);

    // Charger les Leaders de Gym depuis un fichier CSV
    vector<LeaderDeGym> leaders = loadLeaders("leaders.csv",pokemons);

    // Charger les Maîtres Pokémon depuis un fichier CSV
    vector<MaîtrePokémon> maitres = loadMaitres("maitres.csv",pokemons);
    
   for (const auto& joueur : joueurs) {
        joueur.afficherEquipe();
        joueur.afficherStats();  // Afficher les stats des joueurs
    }

    // Exemple d'affichage des leaders de gym
    for (const auto& leader : leaders) {
        leader.afficherGymnase();
        leader.afficherBadge();
        leader.afficherEquipe();
    }

    // Exemple d'affichage des maîtres Pokémon
    for (const auto& maitre : maitres) {
        maitre.afficherEquipe();
        maitre.afficherBoost();
        // Vous pouvez aussi appliquer un boost de dégâts aux Pokémon d'un Maître si nécessaire
    }

    // Exemple d'affichage des informations des Pokémon
    for (const auto& pokemon : pokemons) {
        pokemon.printInfo();
    }
    cout<<leaders[0].getEquipe()[0].getName();
    combat(leaders,joueurs);}
    catch (const std::exception& e) {
        std::cerr << "Exception capturée : " << e.what() << std::endl; // pause de 2 secondes
    } catch (...) {
        std::cerr << "Une erreur inconnue est survenue." << std::endl;
    }
    
    

    }

    




