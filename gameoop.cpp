#include <iostream>
using namespace std;

class Hero {
protected:
    string name, type;
    int health;
    double power;
    int experience;

 public:
    Hero(string n, string t, int h, double p, int e) {
        name = n;
        type = t;
        health = h;
        power = p;
        experience = e;
    }
    
    void showGameMessage() {
        cout << "\n===== Welcome to fantasy battle Arena =====\n";
        cout << "Each hero has unique abilities. Fight wisely!\n";
    }

    virtual double attack() = 0;
    virtual double defend() = 0;

    void displayBasic() {
        cout << "\nHero Name: " << name;
        cout << "\nHero Type: " << type;
        cout << "\nHealth: " << health;
        cout << "\nPower: " << power;
        cout << "\nExperience: " << experience << endl;
    }
};

class Warrior : public Hero {
private:
    string weapon;
    int armor;
    double rage;

public:
    Warrior(string n, int h, double p, int e,
            string w, int a, double r)
        : Hero(n,"Warrior",h,p,e) {
          weapon = w;
           armor = a;
           rage = r;
    }

    void display() {
        displayBasic();
        cout << "Weapon: " << weapon;
        cout << "\nArmor Strength: " << armor;
        cout << "\nRage Level: " << rage << endl;
    }

    double attack() {
          return power * rage+experience;
    }

    double defend() {
         return armor+ (health * 0.2);
    }
};

class Mage : public Hero {
private:
      string spell;
      int mana;
      double multiplier;

public:
    Mage(string n, int h, double p, int e,
         string s, int m, double mul)
        : Hero(n, "Mage",h,p,e) {
        spell = s;
        mana = m;
        multiplier = mul;
    }

    void display() {
        displayBasic();
        cout << "Spell: " << spell;
        cout << "\nMana Points: " << mana;
        cout << "\nMagic Multiplier: " << multiplier << endl;
    }

    double attack() {
      return power * multiplier + mana;
    }

    double defend() {
      return mana * 0.5 + health * 0.1;
    }
};
class Archer : public Hero {
 private:
    string bow;
    int arrows;
    double accuracy;
    
 public:
    Archer(string n, int h, double p, int e,
           string b, int a, double acc)
         : Hero(n, "Archer",h,p,e) {
        bow = b;
        arrows = a;
        accuracy = acc;
    }

    void display() {
         displayBasic();
        cout << "Bow Type: " << bow;
         cout << "\nArrows: " << arrows;
        cout << "\nAccuracy: "<< accuracy << endl;
    }

    double attack() {
     return power * accuracy+arrows;
    }
    double defend() {
    return accuracy * 10+ health * 0.15;
    }
};

  int main() {
  
    Warrior w("Thor",150,50,20, "Axe",40, 1.5);
     Mage m("Merlin",100,60,25, "Fireball",80, 2.0);
    Archer a("Robin", 120,45,18,"Longbow",30, 1.8);

   
     w.showGameMessage();

    
    cout << "\n\n===== WARRIOR =====";
    w.display();
     double wAttack = w.attack();
    double wDefense = w.defend();
     cout << "Attack Value: " << wAttack;
    cout << "\nDefense Value: " << wDefense << endl;
    
    cout << "\n\n===== MAGE =====";
    m.display();
     double mAttack = m.attack();
    double mDefense = m.defend();
       cout << "Attack Value: " << mAttack;
    cout << "\nDefense Value: " << mDefense << endl;

    cout << "\n\n===== ARCHER =====";
    a.display();
      double aAttack = a.attack();
     double aDefense = a.defend();
     cout <<"Attack Value:" << aAttack;
    cout <<"\nDefense Value:" << aDefense << endl;

    
        cout << "\n\n===== SUMMARY =====\n";
    if  (wAttack > mAttack && wAttack > aAttack)
        cout << "Warrior has the highest attack!\n";
          else if (mAttack > wAttack && mAttack > aAttack)
        cout <<"Mage has the highest attack!\n";
    else
        cout << "Archer has the highest attack!\n";

return 0;
}