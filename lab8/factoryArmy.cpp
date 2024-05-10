#include <iostream>
#include <vector>

// Абстрактні класи усіх можливих видів воїнів
class Infantryman {
public:
  virtual void info() = 0;
  virtual ~Infantryman() {}
};

class Archer {
public:
  virtual void info() = 0;
  virtual ~Archer() {}
};

class Horseman {
public:
  virtual void info() = 0;
  virtual ~Horseman() {}
};

// Класи усіх видів воїнів Римскої армії
class RomanInfantryman : public Infantryman {
public:
  void info() { std::cout << "RomanInfantryman" << std::endl; }
};

class RomanArcher : public Archer {
public:
  void info() { std::cout << "RomanArcher" << std::endl; }
};

class RomanHorseman : public Horseman {
public:
  void info() { std::cout << "RomanHorseman" << std::endl; }
};

// Класи усіх видів воїнів армії Карфагена
class CarthaginianInfantryman : public Infantryman {
public:
  void info() { std::cout << "CarthaginianInfantryman" << std::endl; }
};

class CarthaginianArcher : public Archer {
public:
  void info() { std::cout << "CarthaginianArcher" << std::endl; }
};

class CarthaginianHorseman : public Horseman {
public:
  void info() { std::cout << "CarthaginianHorseman" << std::endl; }
};

// Абстрактна фабрика для формування воїнів
class ArmyFactory {
public:
  virtual Infantryman *createInfantryman() = 0;
  virtual Archer *createArcher() = 0;
  virtual Horseman *createHorseman() = 0;
  virtual ~ArmyFactory() {}
};

// Фабрика для створення воїнів Римскої армії
class RomanArmyFactory : public ArmyFactory {
public:
  Infantryman *createInfantryman() { return new RomanInfantryman; }
  Archer *createArcher() { return new RomanArcher; }
  Horseman *createHorseman() { return new RomanHorseman; }
};

// Фабрика для створення воїнів армії Карфагена
class CarthaginianArmyFactory : public ArmyFactory {
public:
  Infantryman *createInfantryman() { return new CarthaginianInfantryman; }
  Archer *createArcher() { return new CarthaginianArcher; }
  Horseman *createHorseman() { return new CarthaginianHorseman; }
};

// Клас, який містить воїнів будь-якої армії
class Army {
public:
  std::vector<Infantryman *> vi;
  std::vector<Archer *> va;
  std::vector<Horseman *> vh;


  ~Army() {
    int i;
    for (i = 0; i < vi.size(); ++i) {
      delete vi[i];
    }

    for (i = 0; i < va.size(); ++i) {
      delete va[i];
    }

    for (i = 0; i < vh.size(); ++i) {
      delete vh[i];
    }
  }

  void info() {
    int i;
    for (i = 0; i < vi.size(); ++i) {
      vi[i]->info();
    }

    for (i = 0; i < va.size(); ++i) {
      va[i]->info();
    }

    for (i = 0; i < vh.size(); ++i) {
      vh[i]->info();
    }
  }
};

// Створення армії будь-якої держави
class Game {
public:
  Army *createArmy(ArmyFactory &factory) {
    Army *p = new Army;
    p->vi.push_back(factory.createInfantryman());
    p->va.push_back(factory.createArcher());
    p->vh.push_back(factory.createHorseman());
    return p;
  }
};

int main() {
  Game game;
  RomanArmyFactory ra_factory;
  CarthaginianArmyFactory ca_factory;

  Army *ra = game.createArmy(ra_factory);
  Army *ca = game.createArmy(ca_factory);
  std::cout << "Roman army:" << std::endl;
  ra->info();
  std::cout << "\nCarthaginian army:" << std::endl;
  ca->info();
  return 0;
}
