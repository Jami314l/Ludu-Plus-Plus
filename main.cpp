#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<sstream>
using namespace sf;
using namespace std;

int timer, f=1, f1=0, f2=0, f3=0, flag=1, entr, p=1;
string PlayerName[9], NameTemp="";
int thick=0;

class playerClass
{
public:
    float xpos, ypos, xvel, yvel;
    playerClass()
    {
        xvel=yvel=xpos=0;
        ypos=0;
    }
    void update(bool PlayerUp, bool PlayerDown, bool PlayerRight, bool PlayerLeft)
    {
        xvel=0;
        yvel=0;
        if(PlayerRight)
            xvel=1;
        if(PlayerLeft)
            xvel=-1;
        if(PlayerUp)
            yvel=-1;
        if(PlayerDown)
            yvel=1;
        xpos+=xvel;
        ypos+=yvel;
    }
};




int main()
{
//sound
    sf::SoundBuffer buffer;
    if(!buffer.loadFromFile("click.wav"))
    {
        cout<<"ERROR"<<endl;
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();
    //music
    sf::Music music;
    if(!music.openFromFile("MainMusic.ogg"))
    {
        cout<<"ERROR"<<endl;
    }
    music.play();


    playerClass logoObj, t1_o, t2_o, t3_o;
    Font font1, font2, font3;
    font1.loadFromFile("data/fonts/VINERITC.ttf");
    font2.loadFromFile("data/fonts/COOPBL.ttf");
    font3.loadFromFile("data/fonts/ALGER.ttf");
    RenderWindow WelcomeWindow(VideoMode(1003, 564), "Welcome");
    Texture w_background, w_logo, wlcm;
    Text w_t("Welcome To", font1, 75);
    Text t1("LUDU", font2, 100);
    Text t2("PLUS", font2, 75);
    Text t3("PLUS", font2, 75);
    Text dv("Developed By :: Bekama Boys", font1, 30);
    Text ins("(Press ENTER to continue)", font2, 50);
    w_t.setPosition(300, 200);
    t1.setPosition(340, 280);  //340, 280
    t2.setPosition(240, 380);  //240, 380
    t3.setPosition(500, 380);  //500, 380
    dv.setPosition(550, 480);
    ins.setPosition(175, 500);
    w_background.loadFromFile("data/image/ww.png");
    w_logo.loadFromFile("data/image/img1.png");
    wlcm.loadFromFile("data/image/wlcm.png");


    Sprite logo_s(w_logo), b_s(w_background), wwlcm(wlcm);
    logo_s.setPosition(250, 600);
    wwlcm.setScale(Vector2f(0.25, 0.25));
    logoObj.ypos=630;
    logoObj.xpos=250;


    while(WelcomeWindow.isOpen())
    {
        Event event;
        while(WelcomeWindow.pollEvent(event))
        {
            if(event.type==Event::Closed)
                WelcomeWindow.close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Enter))
            WelcomeWindow.close();
        logoObj.update(false, false, false, false);
        if(f)
            logoObj.update(true, false, false, false);
        WelcomeWindow.clear();
        WelcomeWindow.draw(b_s);
        WelcomeWindow.draw(logo_s);
        logo_s.move(Vector2f(logoObj.xvel, logoObj.yvel));
        if(logoObj.ypos<50)
            f=0;
        if(!f)
        {
            t1_o.update(false, false, false, false);
            if(f1)
                t1_o.update(true, false, true, false);
                WelcomeWindow.draw(wwlcm);
            WelcomeWindow.draw(w_t);
            WelcomeWindow.draw(dv);
            timer++;
            if(timer%500<250)
                WelcomeWindow.draw(ins);
            if((timer/100)%6==0)
            {
                //t1.setColor(Color(0, 255, 0));
                //t2.setColor(Color(0, 255, 0));
                //t3.setColor(Color(0, 255, 0));
                logo_s.setColor(Color(0, 255, 0));
            }
            if((timer/100)%6==1)
            {
                //  t1.setColor(Color(237, 28, 36));
                //  t2.setColor(Color(237, 28, 36));
                //t3.setColor(Color(237, 28, 36));
                logo_s.setColor(Color(237, 28, 36));
            }
            if((timer/100)%6==2)
            {
                //t1.setColor(Color(63, 72, 204));
                //t2.setColor(Color(63, 72, 204));
                //t3.setColor(Color(63, 72, 204));
                logo_s.setColor(Color(63, 72, 204));
            }
            if((timer/100)%6==3)
            {
                //t1.setColor(Color(255, 242, 0));
                //t2.setColor(Color(255, 242, 0));
                //t3.setColor(Color(255, 242, 0));
                logo_s.setColor(Color(255, 242, 0));
            }
            if((timer/100)%6==4)
            {
                //t1.setColor(Color(163, 73, 164));
                //t2.setColor(Color(163, 73, 164));
                //t3.setColor(Color(163, 73, 164));
                logo_s.setColor(Color(163, 73, 164));
            }
            if((timer/100)%6==5)
            {
                //t1.setColor(Color(0, 255, 255));
                //t2.setColor(Color(0, 255, 255));
                //t3.setColor(Color(0, 255, 255));
                logo_s.setColor(Color(0, 255, 255));
            }
            if(!(timer%50))
                thick++;
            t1.setOutlineThickness(thick%20);
            //t1.setCharacterSize(100-(thick%10));
            t2.setOutlineThickness(thick%20);
            //t2.setCharacterSize(75-(thick%10));
            t3.setOutlineThickness(thick%20);
            //t3.setCharacterSize(75-(thick%10));
            WelcomeWindow.draw(t2);
            WelcomeWindow.draw(t3);
            WelcomeWindow.draw(t1);
        }
        WelcomeWindow.display();
    }














    while(flag--)
    {

        Texture saitama, background, welcome, Namebackground;
        playerClass PlayerObject;
        bool PlayerUp, PlayerDown, PlayerRight, PlayerLeft;
        int TotalPlayer=4;
        Text SPN("4 Players\n6 Players\n8 Players", font3, 75);
        SPN.setPosition(200, 175);
        RenderWindow ManuWindow(VideoMode(1010, 564), "Manu");
        saitama.loadFromFile("data/image/saitama.png");
        welcome.loadFromFile("data/image/pnb.jpg");
        RectangleShape Rectangle(Vector2f(405, 75));
        Rectangle.setOutlineThickness(5);
        Rectangle.setFillColor(Color(50, 50, 50, 0));
        Rectangle.setPosition(198, 185);
        Rectangle.setOutlineColor(Color(0, 0, 255));
        Sprite manu(welcome);
        int pup=0;
        string String;
        while(ManuWindow.isOpen())
        {
            Event event;
            while(ManuWindow.pollEvent(event))
            {
                if(event.type==Event::Closed)
                    ManuWindow.close();
            }
            if(Keyboard::isKeyPressed(Keyboard::Down))
                pup=-2;
            if(Keyboard::isKeyPressed(Keyboard::Up))
                pup=2;
            if(event.type==Event::KeyReleased)
            {
                TotalPlayer-=pup;
                pup=0;
                if(TotalPlayer>8)
                    TotalPlayer=4;
                if(TotalPlayer<4)
                    TotalPlayer=8;
            }
            if(TotalPlayer==4)
                Rectangle.setPosition(198, 185);
            else if(TotalPlayer==6)
                Rectangle.setPosition(198, 285);
            else if(TotalPlayer==8)
                Rectangle.setPosition(198, 385);



            if(Keyboard::isKeyPressed(Keyboard::Space))
                ManuWindow.close();

            ManuWindow.clear();
            ManuWindow.draw(manu);
            ManuWindow.draw(SPN);
            ManuWindow.draw(Rectangle);
            ManuWindow.display();
        }






        Namebackground.loadFromFile("data/image/NameInputBg.png");
        Sprite NB(Namebackground);
        RenderWindow NameWindow(VideoMode(1024, 512), "Name");
        Text Show("Enter Player Names",font3,  50);
        Text p1("Player 1 :", font3, 40);
        Text p2("Player 2 :", font3, 40);
        Text p3("Player 3 :", font3, 40);
        Text p4("Player 4 :", font3, 40);
        Text p5("Player 5 :", font3, 40);
        Text p6("Player 6 :", font3, 40);
        Text p7("Player 7 :", font3, 40);
        Text p8("Player 8 :", font3, 40);
        Text CurrentName("", font2, 40);
        Text Name1("", font2, 40);
        Text Name2("", font2, 40);
        Text Name3("", font2, 40);
        Text Name4("", font2, 40);
        Text Name5("", font2, 40);
        Text Name6("", font2, 40);
        Text Name7("", font2, 40);
        Text Name8("", font2, 40);


        //Show.setColor(Color::Cyan);
        while(NameWindow.isOpen())
        {
            Event Event;

            NameWindow.draw(NB);

            while(NameWindow.pollEvent(Event))
            {
                switch (Event.type)
                {

                case Event::Closed:
                    NameWindow.close();
                case Event::TextEntered:
                {
                    if(static_cast<int>(Event.text.unicode)==13)
                    {
                        if(p==1)
                            Name1.setString(NameTemp);
                        else if(p==2)
                            Name2.setString(NameTemp);
                        else if(p==3)
                            Name3.setString(NameTemp);
                        else if(p==4)
                            Name4.setString(NameTemp);
                        else if(p==5)
                            Name5.setString(NameTemp);
                        else if(p==6)
                            Name6.setString(NameTemp);
                        else if(p==7)
                            Name7.setString(NameTemp);
                        else if(p==8)
                            Name8.setString(NameTemp);
                        PlayerName[p]=NameTemp;
                        NameTemp="";
                        CurrentName.setString(NameTemp);
                        p++;
                        if(p>TotalPlayer)
                        {
                            p=1;
                            NameWindow.close();
                        }
                    }
                    else if(static_cast<int>(Event.text.unicode)==8)
                    {
                        if(NameTemp!="")
                        {
                            string nts="";
                            for(int i=0; i<NameTemp.size()-1; i++)
                                nts+=NameTemp[i];
                            NameTemp=nts;
                            CurrentName.setString(NameTemp);
                        }
                    }
                    else
                    {
                        NameTemp+=static_cast<char>(Event.text.unicode);
                        CurrentName.setString(NameTemp);
                    }
                }
                }
            }




            if(TotalPlayer==4)
            {
                if(p==1)
                    CurrentName.setPosition(410, 100);
                if(p==2)
                {
                    Name1.setPosition(410, 100);
                    CurrentName.setPosition(410, 200);
                }
                if(p==3)
                {
                    Name2.setPosition(410, 200);
                    CurrentName.setPosition(410, 300);
                }
                if(p==4)
                {
                    Name3.setPosition(410, 300);
                    CurrentName.setPosition(410, 400);
                }


                p1.setPosition(150, 100);
                p2.setPosition(150, 200);
                p3.setPosition(150, 300);
                p4.setPosition(150, 400);


                RectangleShape TBox (Vector2f(500, 60));
                TBox.setOutlineThickness(5);
                TBox.setFillColor(Color(255, 255, 255, 50));
                TBox.setOutlineColor(Color(255, 255, 255));
                TBox.setPosition(400, 100);
                NameWindow.draw(TBox);
                TBox.setPosition(400, 200);
                NameWindow.draw(TBox);
                TBox.setPosition(400, 300);
                NameWindow.draw(TBox);
                TBox.setPosition(400, 400);
                NameWindow.draw(TBox);


                NameWindow.draw(p1);
                NameWindow.draw(p2);
                NameWindow.draw(p3);
                NameWindow.draw(p4);
            }
            else  if(TotalPlayer==6)
            {

                if(p==1){
                    CurrentName.setPosition(410, 100);
                    Show.setColor(Color(0, 255, 0));
                }
                if(p==2)
                {
                    Name1.setPosition(410, 100);
                    CurrentName.setPosition(410, 160);
                    Show.setColor(Color(237, 28, 36));
                }
                if(p==3)
                {
                    Name2.setPosition(410, 160);
                    CurrentName.setPosition(410, 220);
                    Show.setColor(Color(63, 72, 204));
                }
                if(p==4)
                {
                    Name3.setPosition(410, 220);
                    CurrentName.setPosition(410, 280);
                    Show.setColor(Color(255, 242, 0));
                }
                if(p==5)
                {
                    Name4.setPosition(410, 280);
                    CurrentName.setPosition(410, 340);
                    Show.setColor(Color(163, 73, 164));
                }
                if(p==6)
                {
                    Name5.setPosition(410, 340);
                    CurrentName.setPosition(410, 400);
                    Show.setColor(Color(0, 255, 255));
                }


                p1.setPosition(150, 97);
                p2.setPosition(150, 160);
                p3.setPosition(150, 220);
                p4.setPosition(150, 280);
                p5.setPosition(150, 340);
                p6.setPosition(150, 400);


                p1.setColor(Color(0, 255, 0));
                p2.setColor(Color(237, 28, 36));
                p3.setColor(Color(63, 72, 204));
                p4.setColor(Color(255, 242, 0));
                p5.setColor(Color(163, 73, 164));
                p6.setColor(Color(0, 255, 255));


                Name1.setColor(Color(0, 255, 0));
                Name2.setColor(Color(237, 28, 36));
                Name3.setColor(Color(63, 72, 204));
                Name4.setColor(Color(255, 242, 0));
                Name5.setColor(Color(163, 73, 164));
                Name6.setColor(Color(0, 255, 255));


                RectangleShape TBox (Vector2f(500, 45));
                TBox.setOutlineThickness(3);
                TBox.setFillColor(Color(255, 255, 255, 50));
                TBox.setOutlineColor(Color(237, 28, 36));
                TBox.setPosition(400, 400);
                NameWindow.draw(TBox);
                TBox.setOutlineColor(Color(0, 255, 0));
                TBox.setPosition(400, 100);
                NameWindow.draw(TBox);
                TBox.setOutlineColor(Color(63, 72, 204));
                TBox.setPosition(400, 160);
                NameWindow.draw(TBox);
                TBox.setOutlineColor(Color(255, 242, 0));
                TBox.setPosition(400, 220);
                NameWindow.draw(TBox);
                TBox.setOutlineColor(Color(163, 73, 164));
                TBox.setPosition(400, 280);
                NameWindow.draw(TBox);
                TBox.setOutlineColor(Color(0, 255, 255));
                TBox.setPosition(400, 340);
                NameWindow.draw(TBox);


                NameWindow.draw(p1);
                NameWindow.draw(p2);
                NameWindow.draw(p3);
                NameWindow.draw(p4);
                NameWindow.draw(p5);
                NameWindow.draw(p6);
            }
            else if(TotalPlayer==8)
            {
                if(p==1)
                    CurrentName.setPosition(410, 100);
                if(p==2)
                {
                    Name1.setPosition(410, 100);
                    CurrentName.setPosition(410, 150);
                }
                if(p==3)
                {
                    Name2.setPosition(410, 150);
                    CurrentName.setPosition(410, 200);
                }
                if(p==4)
                {
                    Name3.setPosition(410, 200);
                    CurrentName.setPosition(410, 250);
                }
                if(p==5)
                {
                    Name4.setPosition(410, 250);
                    CurrentName.setPosition(410, 300);
                }
                if(p==6)
                {
                    Name5.setPosition(410, 300);
                    CurrentName.setPosition(410, 350);
                }
                if(p==7)
                {
                    Name6.setPosition(410, 350);
                    CurrentName.setPosition(410, 400);
                }
                if(p==8)
                {
                    Name7.setPosition(410, 400);
                    CurrentName.setPosition(410, 450);
                }



                p1.setPosition(150, 100);
                p2.setPosition(150, 150);
                p3.setPosition(150, 200);
                p4.setPosition(150, 250);
                p5.setPosition(150, 300);
                p6.setPosition(150, 350);
                p7.setPosition(150, 400);
                p8.setPosition(150, 450);


                RectangleShape TBox (Vector2f(500, 40));
                TBox.setOutlineThickness(2);
                TBox.setFillColor(Color(255, 255, 255, 50));
                TBox.setOutlineColor(Color(237, 28, 36));
                TBox.setPosition(400, 105);
                NameWindow.draw(TBox);
                TBox.setPosition(400, 155);
                NameWindow.draw(TBox);
                TBox.setPosition(400, 205);
                NameWindow.draw(TBox);
                TBox.setPosition(400, 255);
                NameWindow.draw(TBox);
                TBox.setPosition(400, 305);
                NameWindow.draw(TBox);
                TBox.setPosition(400, 355);
                NameWindow.draw(TBox);
                TBox.setPosition(400, 405);
                NameWindow.draw(TBox);
                TBox.setPosition(400, 455);
                NameWindow.draw(TBox);


                NameWindow.draw(p1);
                NameWindow.draw(p2);
                NameWindow.draw(p3);
                NameWindow.draw(p4);
                NameWindow.draw(p5);
                NameWindow.draw(p6);
                NameWindow.draw(p7);
                NameWindow.draw(p8);
            }
            Show.setPosition(250, 10);

            NameWindow.draw(CurrentName);
            NameWindow.draw(Name1);
            NameWindow.draw(Name2);
            NameWindow.draw(Name3);
            NameWindow.draw(Name4);
            NameWindow.draw(Name5);
            NameWindow.draw(Name6);
            NameWindow.draw(Name7);
            NameWindow.draw(Name8);
            //NameWindow.clear();
            NameWindow.draw(Show);
            NameWindow.display();
        }



        if(TotalPlayer==8)
            background.loadFromFile("data/image/backgroundp8.png");
        if(TotalPlayer==6)
            background.loadFromFile("data/image/backgroundp6.png");
        if(TotalPlayer==4)
            background.loadFromFile("data/image/backgroundp4.png");
        RenderWindow GameWindow(VideoMode(1004, 564), "LUDO!!!!!");
        Sprite character(saitama), bg(background);
        character.setScale(Vector2f(0.3,0.3));
        while (GameWindow.isOpen())
        {
            Event event;
            while(GameWindow.pollEvent(event))
            {
                if(event.type==Event::Closed)
                    GameWindow.close();
            }


            if(TotalPlayer==6)
            {
                Name1.setPosition(580, 100);
                Name2.setPosition(580, 150);
                Name3.setPosition(580, 200);
                Name4.setPosition(580, 250);
                Name5.setPosition(580, 300);
                Name6.setPosition(580, 350);
            }




            PlayerRight = Keyboard::isKeyPressed(Keyboard::Right);
            PlayerLeft = Keyboard::isKeyPressed(Keyboard::Left);
            PlayerUp = Keyboard::isKeyPressed(Keyboard::Up);
            PlayerDown = Keyboard::isKeyPressed(Keyboard::Down);
            if(Keyboard::isKeyPressed(Keyboard::Escape))
                GameWindow.close();
            if(Keyboard::isKeyPressed(Keyboard::Backspace))
            {
                GameWindow.close();
                flag++;
            }
            PlayerObject.update(PlayerUp, PlayerDown, PlayerRight, PlayerLeft);
            GameWindow.clear();
            GameWindow.draw(bg);
            GameWindow.draw(character);
            character.move(Vector2f(PlayerObject.xvel, PlayerObject.yvel));
            GameWindow.draw(Name1);
            GameWindow.draw(Name2);
            GameWindow.draw(Name3);
            GameWindow.draw(Name4);
            GameWindow.draw(Name5);
            GameWindow.draw(Name6);
            GameWindow.display();
        }
    }
    for(int i=1; i<9; i++)
        cout<<PlayerName[i]<<"...\n";
}
