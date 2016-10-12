#include <iostream>
#include "header.h"
#include "Guard.h"
#include "Assasin.h"
#include "Deck.h"
#include "BattleField.h"
#include "attackSkill.h"
#include "healingSkill.h"
#include "BigFireBall.h"
#include "postponeSkill.h"
#include "Player.h"

/*
    Stoev Martin
    No.855240
    Code::Blocks 13.12
    Windows 7 64bits
*/

// operator == and copy cons are needed for the Spells in order to copy them to from card to deck vice verce;
// make Card of guard and assasin in Deck !!
int main()
{
    BattleField bf;




//    Assasin a1("Pero" , 100 , 20);
//    Assasin a2("Risto" , 50 , 100);
//    Assasin a3("Gisha" , 20 , 150);
//    Guard g1("Maricka" , 20 , 150);
//    Guard g2("Petranka", 30 , 200);
//    Guard g3("Mirza" , 400 , 4000);
//
//    attackSkill s1("FireBall" , 300);
//    attackSkill b1("Frosting" , 200);
//    healingSkill s2("Cure" , 500);
//    postponeSkill s3("Sleepo" , 2);
//    Deck d("testing1.txt");
//    d += a1;
//    d += a2;
//    d += a3;
//    d += g1;
//    d += g2;
//    d += g3;
//
//    ofstream output("testing1.txt" , ios::binary);
//
//    d.saveDeckBinary(output);
//
//    output.close();
//
//    ifstream input("testing1.txt" , ios::binary);
//
//    Deck c("asd");
//    c.loadDeckBinary(input);
//
//    c.printDeck();
//    cout << "Stage 1" << endl;
//    Assasin a1("Pero" , 100 , 20);
//    Assasin a2("Risto" , 50 , 100);
//    Assasin a3("Gisha" , 20 , 150);
//    Guard g1("Maricka" , 20 , 150);
//    Guard g2("Petranka", 30 , 200);
//    Guard g3("Mirza" , 400 , 4000);
////    Guard g2("Ogre" , 40 , 400);
//    cout << "Stage 2" << endl;
//    attackSkill s1("FireBall" , 300);
//    attackSkill b1("Frosting" , 200);
//    healingSkill s2("Cure" , 500);
//    postponeSkill s3("Sleepo" , 2);
//    cout << "Stage 3" << endl;
//    a1.addSkill(s1);
//    a1.addSkill(s2);
//    a1.addSkill(s3);
//    a2.addSkill(s1);
//    a3.addSkill(s3);
//    Deck d("adgdfg");
//    d += a1;
//    d += a2;
//    d += a3;
//    d += g1;
//    d += g2;
//    d += g3;
//
//    d -= a2;
//    a2.addSkill(s2);
//    d += a2;
//    cout << d;
//    cout << "END" << endl;
//    Card c("ChaosDragon" , 100 , 500 );
//
//    attackSkill a("FireBall" , 200);
//    postponeSkill p("asdsd", 2 );
//    healingSkill h("adsada" , 12);
//    c.addSkill(a);
//    c[0]->printInfo();
//    cout << "asdasd" << endl;


    //    a.printInfo();
//    cout << c;
    // d.printDeck();
/*
    d.addCard("BountyHunter" , 40 , 400);
    d.addCard("PhantomLancer" , 50 , 350);
    d.addCard("Pudge" , 40 , 1000);
    d.addCard("Riki Maru" , 45 , 400);
    d.addCard("Storm Spirit" , 40 , 300);
    d.addCard("Lina" , 50 , 350);
    d.addCard("Furion" , 40 , 300);
    d.addCard("FacelesVoid" , 60 , 400);
    d.printDeck();
    d.saveDeck("test.txt");

     Card p("Tiny" , 60 , 600);
    d+p;

    Card c("ChaosDragon" , 100 , 500 );
    Card b(c);
    c.printCard();
    b.setAttack(20);
    b.setHealth(100);
    b.setCardName("BountyHunter");
    b.printCard();
    Card a;
    a.printCard();
    */

    return 0;
}
