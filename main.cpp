#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<sstream>
using namespace sf;
using namespace std;
vector<int>xx, yy;
Music pno;
SoundBuffer click, rol, mv, dead, scored, win, ops;
Sound snd;
int charofplayer[7], flagofvalidmove, victory[5];
Font font1, font2, font3;
Text test("", font3, 75);
int mora[7][6]= {{0, 0, 0, 0, 0, 0}, {0, 79, 80, 81, 82, 0}, {0, 83, 84, 85, 86, 0}, {0, 87, 88, 89, 90, 0}, {0, 91, 92, 93, 94, 0}, {0, 95, 96, 97, 98, 0}, {0, 99, 100, 101, 102, 0}};
int position[7][6]= {{0, 0, 0, 0, 0, 0}, {0, 79, 80, 81, 82, 0}, {0, 83, 84, 85, 86, 0}, {0, 87, 88, 89, 90, 0}, {0, 91, 92, 93, 94, 0}, {0, 95, 96, 97, 98, 0}, {0, 99, 100, 101, 102, 0}};
int timer, f=1, f1=0, f2=0, f3=0, flag=1, entr, p=1;
int initialpos[7]= {0, 1, 14, 27, 40, 53, 66}, criticalpos[7]= {0, 77, 12, 25, 38, 51, 64}, home[7]= {0, 103, 109, 115, 121, 127, 133}, goal[7]= {0, 108, 114, 120, 126, 132, 138};
int ppx[200]= {0, 142, 163, 188, 211, 235, 266, 266, 265, 267, 267, 265, 297, 326, 328, 329, 327, 326, 329, 367, 390, 411, 433, 458, 480, 495, 513, 488, 468, 444, 420, 399, 401, 423, 448, 468, 492, 516, 499, 483, 459, 438, 416, 392, 371, 332, 333, 335, 334, 334, 332, 302, 275, 274, 271, 272, 272, 272, 238, 218, 194, 168, 149, 125, 110, 94, 117, 139, 162, 186, 207, 205, 181, 160, 135, 113, 89, 103, 122, 197, 217, 224, 194, 370, 395, 398, 372, 470, 498, 495, 473, 376, 406, 404, 376, 199, 230, 225, 196, 93, 118, 122, 93, 128, 150, 173, 197, 219, 251, 297, 297, 296, 296, 297, 301, 473, 448, 427, 405, 381, 345, 475, 454, 429, 408, 387, 351, 302, 301, 301, 301, 301, 304, 131, 152, 176, 199, 223, 256, 256, 984};
int ppy[200]= {0, 156, 171, 184, 197, 209, 190, 165, 138, 110, 85, 58, 59, 59, 81, 109, 134, 161, 188, 211, 195, 182, 167, 155, 140, 165, 189, 205, 217, 232, 246, 260, 303, 322, 334, 348, 360, 375, 402, 428, 412, 399, 384, 368, 353, 377, 403, 432, 460, 483, 510, 508, 508, 484, 460, 430, 403, 377, 357, 368, 381, 396, 409, 425, 399, 375, 360, 345, 333, 318, 303, 265, 248, 236, 222, 207, 194, 171, 143, 108, 108, 132, 132, 107, 105, 134, 135, 262, 263, 290, 291, 425, 428, 454, 450, 422, 425, 452, 446, 259, 265, 292, 290, 183, 197, 211, 222, 238, 257, 85, 110, 136, 163, 191, 234, 181, 193, 209, 220, 236, 258, 387, 373, 359, 347, 330, 313, 486, 460, 431, 404, 380, 337, 386, 371, 358, 343, 329, 313, 314, -13};
void spos(int player, int score, int pn)
{
    flagofvalidmove=1;
    char a=player+'0', b=score+'0', c=pn+'0';
    string s=" ,  ,  ";
    s[0]=a, s[3]=b, s[5]=c;
    test.setString(s);
    int nowpos=position[player][pn];

    if(nowpos==79||nowpos==80||nowpos==81||nowpos==82)
    {
        if(score==6)
            position[player][pn]=initialpos[1];
        else
            flagofvalidmove=0;
    }
    else  if(nowpos==83||nowpos==84||nowpos==85||nowpos==86)
    {
        if(score==6)
            position[player][pn]=initialpos[2];
        else
            flagofvalidmove=0;
    }
    else if(nowpos==87||nowpos==88||nowpos==89||nowpos==90)
    {
        if(score==6)
            position[player][pn]=initialpos[3];
        else
            flagofvalidmove=0;
    }
    else if(nowpos==91||nowpos==92||nowpos==93||nowpos==94)
    {
        if(score==6)
            position[player][pn]=initialpos[4];
        else
            flagofvalidmove=0;
    }
    else if(nowpos==95||nowpos==96||nowpos==97||nowpos==98)
    {
        if(score==6)
            position[player][pn]=initialpos[5];
        else
            flagofvalidmove=0;
    }
    else if(nowpos==99||nowpos==100||nowpos==101||nowpos==102)
    {
        if(score==6)
            position[player][pn]=initialpos[6];
        else
            flagofvalidmove=0;
    }
    else
    {
        position[player][pn]+=score;
        if(position[player][pn]>=criticalpos[player]&&position[player][pn]-score<=criticalpos[player])
            position[player][pn]=position[player][pn]-criticalpos[player]+home[player];
        if(position[player][pn]>goal[player])
        {
            position[player][pn]-=score;
            flagofvalidmove=0;
        }
        if(player>1)
        {
            if(position[player][pn]<=78&&position[player][pn]+score>78)
                position[player][pn]=78-position[player][pn]+score-1;
        }
    }
    if(position[player][1]==goal[player]&&position[player][2]==goal[player]&&position[player][3]==goal[player]&&position[player][4]==goal[player])
    {
        victory[player]=1;
        snd.setBuffer(win);
        snd.play();
    }
    else if(position[player][pn]==goal[player])
        snd.play();

    if(pn!=5)
    {
        for(int i=1; i<7; i++)
        {
            if(position[player][pn]==initialpos[i])
                return;
            if(i==player)
                continue;
            for(int j=1; j<5; j++)
                if(position[player][pn]==position[i][j])
                {
                    position[i][j]=mora[i][j];
                    snd.setBuffer(dead);
                    snd.play();
                }
        }
    }
}

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
    mv.loadFromFile("data/move.WAV");
    rol.loadFromFile("data/rol.WAV");
    ops.loadFromFile("data/ops.WAV");
    win.loadFromFile("data/win.WAV");
    dead.loadFromFile("data/dead.WAV");
    pno.openFromFile("data/He's a pirate3.WAV");
    pno.setLoop(1);
    pno.play();


    playerClass logoObj, t1_o, t2_o, t3_o;
    //Font font1, font2, font3;
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
        //if(Keyboard::isKeyPressed(Keyboard::Enter))
        if(static_cast<int>(event.text.unicode)==13)
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

        Texture pickachu, background, welcome, Namebackground, naruto, baby, ironman, cap, bat, hulk, dp, ang, arya, bart, panda, opm, sup, spidy, el, micky, angry, chchar;
        playerClass PlayerObject;
        bool PlayerUp, PlayerDown, PlayerRight, PlayerLeft;
        int TotalPlayer=4;
        Text SPN("4 Players\n6 Players\n8 Players", font3, 75);
        SPN.setPosition(200, 175);
        RenderWindow ManuWindow(VideoMode(1010, 564), "Manu");
        pickachu.loadFromFile("data/image/pickachu.png");
        ironman.loadFromFile("data/image/Ironman.png");
        cap.loadFromFile("data/image/Cap.png");
        bat.loadFromFile("data/image/Batman.png");
        hulk.loadFromFile("data/image/Hulk.png");
        dp.loadFromFile("data/image/Deadpool.png");
        ang.loadFromFile("data/image/Aang.png");
        arya.loadFromFile("data/image/Arya.png");
        bart.loadFromFile("data/image/Bart.png");
        panda.loadFromFile("data/image/Panda.png");
        opm.loadFromFile("data/image/Saitama.png");
        sup.loadFromFile("data/image/Sup.png");
        spidy.loadFromFile("data/image/Spidy.png");
        el.loadFromFile("data/image/El.png");
        micky.loadFromFile("data/image/Micky.png");
        angry.loadFromFile("data/image/Angry Bird.png");
        naruto.loadFromFile("data/image/Naruto.png");
        baby.loadFromFile("data/image/boss baby.png");
        welcome.loadFromFile("data/image/pnb.jpg");
        chchar.loadFromFile("data/image/cc.jpg");
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



            //if(Keyboard::isKeyPressed(Keyboard::Space))
            if(static_cast<int>(event.text.unicode)==13)
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
        Text Blinker("|", font2, 40);
        int name_window_counter=0, name_window_exit_properly=1;

        //Show.setColor(Color::Cyan);
        int cchoose=0;
        Sprite cchar(chchar);
        while(NameWindow.isOpen())
        {
            Vector2i mpos=Mouse::getPosition(NameWindow);
            int x=(int)mpos.x, y=(int)mpos.y;
            name_window_counter++;
            Event Event;
            NameWindow.draw(NB);

            while(NameWindow.pollEvent(Event))
            {
                switch (Event.type)
                {
                case Event::Closed:
                    NameWindow.close();
                case Event::MouseButtonPressed:
                {

                    if(y>62)
                    {
                        if(y<212)
                        {
                            if(x<165)
                                charofplayer[p]=1;
                            else if(x<343)
                                charofplayer[p]=2;
                            else if(x<472)
                                charofplayer[p]=3;
                            else if(x<622)
                                charofplayer[p]=4;
                            else if(x<733)
                                charofplayer[p]=5;
                            else if(x<862)
                                charofplayer[p]=6;
                            else
                                charofplayer[p]=7;
                        }
                        else if(y<362)
                        {
                            if(x<140)
                                charofplayer[p]=8;
                            else if(x<275)
                                charofplayer[p]=9;
                            else if(x<425)
                                charofplayer[p]=10;
                            else if(x<584)
                                charofplayer[p]=11;
                            else if(x<720)
                                charofplayer[p]=12;
                            else if(x<822)
                                charofplayer[p]=13;
                            else if(x<900)
                                charofplayer[p]=14;
                            else
                                charofplayer[p]=15;
                        }
                    }


                    p++;
                    if(p>TotalPlayer)
                    {
                        p=1;
                        NameWindow.close();
                    }
                    cchoose=0;
                }
                case Event::TextEntered:
                {
                    if(static_cast<int>(Event.text.unicode)==27)
                    {
                        name_window_exit_properly=0;
                        p=1;
                        NameWindow.close();
                    }
                    else if(static_cast<int>(Event.text.unicode)==13)
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
                        Blinker.setString(NameTemp+"|");
                        cchoose=1;
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
                            Blinker.setString(NameTemp+"|");
                        }
                    }
                    else if(static_cast<int>(Event.text.unicode)==0)
                        continue;
                    else
                    {
                        if(NameTemp.size()<7)
                            NameTemp+=static_cast<char>(Event.text.unicode);
                        CurrentName.setString(NameTemp);
                        Blinker.setString(NameTemp+"|");
                    }
                }
                }
            }


            if(TotalPlayer==4)
            {
                if(p==1)
                {
                    CurrentName.setPosition(410, 100);
                    Blinker.setPosition(393, 100);
                }
                if(p==2)
                {
                    Name1.setPosition(410, 100);
                    CurrentName.setPosition(410, 200);
                    Blinker.setPosition(393, 200);
                }
                if(p==3)
                {
                    Name2.setPosition(410, 200);
                    CurrentName.setPosition(410, 300);
                    Blinker.setPosition(393, 300);
                }
                if(p==4)
                {
                    Name3.setPosition(410, 300);
                    CurrentName.setPosition(410, 400);
                    Blinker.setPosition(393, 400);
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

                if(p==1)
                {
                    CurrentName.setPosition(410, 100);
                    Show.setColor(Color(0, 255, 0));
                    Blinker.setPosition(410, 100);
                }
                if(p==2)
                {
                    Name1.setPosition(410, 100);
                    CurrentName.setPosition(410, 160);
                    Show.setColor(Color(237, 28, 36));
                    Blinker.setPosition(410, 160);
                }
                if(p==3)
                {
                    Name2.setPosition(410, 160);
                    CurrentName.setPosition(410, 220);
                    Show.setColor(Color(63, 72, 204));
                    Blinker.setPosition(410, 220);
                }
                if(p==4)
                {
                    Name3.setPosition(410, 220);
                    CurrentName.setPosition(410, 280);
                    Show.setColor(Color(255, 242, 0));
                    Blinker.setPosition(410, 280);
                }
                if(p==5)
                {
                    Name4.setPosition(410, 280);
                    CurrentName.setPosition(410, 340);
                    Show.setColor(Color(163, 73, 164));
                    Blinker.setPosition(410, 340);
                }
                if(p==6)
                {
                    Name5.setPosition(410, 340);
                    CurrentName.setPosition(410, 400);
                    Show.setColor(Color(0, 255, 255));
                    Blinker.setPosition(410, 400);
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
            if(name_window_counter%400>200)
                NameWindow.draw(Blinker);
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
            if(cchoose)
                NameWindow.draw(cchar);
            NameWindow.display();
        }



        if(TotalPlayer==8)
            background.loadFromFile("data/image/backgroundp8.png");
        if(TotalPlayer==6)
            background.loadFromFile("data/image/backgroundp6.png");
        if(TotalPlayer==4)
            background.loadFromFile("data/image/backgroundp4.png");
        //vector<float>x, y;
        RenderWindow GameWindow(VideoMode(1004, 564), "LUDO!!!!!");
        Sprite character11, character12, character13, character14, bg(background), proj1, proj2, proj3, proj4, proj5, proj6;
        Sprite character21, character22, character23, character24;
        Sprite character31, character32, character33, character34;
        Sprite character41, character42, character43, character44;
        Sprite character51, character52, character53, character54;
        Sprite character61, character62, character63, character64;
        if(true)
        {
            if(charofplayer[1]==1)
            {
                character11.setTexture(ang);
                character12.setTexture(ang);
                character13.setTexture(ang);
                character14.setTexture(ang);
                proj1.setTexture(ang);
            }
            else if(charofplayer[1]==2)
            {
                character11.setTexture(hulk);
                character12.setTexture(hulk);
                character13.setTexture(hulk);
                character14.setTexture(hulk);
                proj1.setTexture(hulk);
            }
            else if(charofplayer[1]==3)
            {
                character11.setTexture(spidy);
                character12.setTexture(spidy);
                character13.setTexture(spidy);
                character14.setTexture(spidy);
                proj1.setTexture(spidy);
            }
            else if(charofplayer[1]==4)
            {
                character11.setTexture(panda);
                character12.setTexture(panda);
                character13.setTexture(panda);
                character14.setTexture(panda);
                proj1.setTexture(panda);
            }
            else if(charofplayer[1]==5)
            {
                character11.setTexture(micky);
                character12.setTexture(micky);
                character13.setTexture(micky);
                character14.setTexture(micky);
                proj1.setTexture(micky);
            }
            else if(charofplayer[1]==6)
            {

                character11.setTexture(bart);
                character12.setTexture(bart);
                character13.setTexture(bart);
                character14.setTexture(bart);
                proj1.setTexture(bart);
            }
            else if(charofplayer[1]==8)
            {
                character11.setTexture(bat);
                character12.setTexture(bat);
                character13.setTexture(bat);
                character14.setTexture(bat);
                proj1.setTexture(bat);
            }
            else if(charofplayer[1]==9)
            {
                character11.setTexture(ironman);
                character12.setTexture(ironman);
                character13.setTexture(ironman);
                character14.setTexture(ironman);
                proj1.setTexture(ironman);
            }
            else if(charofplayer[1]==10)
            {
                character11.setTexture(naruto);
                character12.setTexture(naruto);
                character13.setTexture(naruto);
                character14.setTexture(naruto);
                proj1.setTexture(naruto);
            }
            else if(charofplayer[1]==11)
            {
                character11.setTexture(pickachu);
                character12.setTexture(pickachu);
                character13.setTexture(pickachu);
                character14.setTexture(pickachu);
                proj1.setTexture(pickachu);
            }
            else if(charofplayer[1]==12)
            {
                character11.setTexture(angry);
                character12.setTexture(angry);
                character13.setTexture(angry);
                character14.setTexture(angry);
                proj1.setTexture(angry);
            }
            else if(charofplayer[1]==13)
            {
                character11.setTexture(arya);
                character12.setTexture(arya);
                character13.setTexture(arya);
                character14.setTexture(arya);
                proj1.setTexture(arya);
            }





            if(charofplayer[2]==1)
            {
                character21.setTexture(ang);
                character22.setTexture(ang);
                character23.setTexture(ang);
                character24.setTexture(ang);
                proj2.setTexture(ang);
            }
            else if(charofplayer[2]==2)
            {
                character21.setTexture(hulk);
                character22.setTexture(hulk);
                character23.setTexture(hulk);
                character24.setTexture(hulk);
                proj2.setTexture(hulk);
            }
            else if(charofplayer[2]==3)
            {
                character21.setTexture(spidy);
                character22.setTexture(spidy);
                character23.setTexture(spidy);
                character24.setTexture(spidy);
                proj2.setTexture(spidy);
            }
            else if(charofplayer[2]==4)
            {
                character21.setTexture(panda);
                character22.setTexture(panda);
                character23.setTexture(panda);
                character24.setTexture(panda);
                proj2.setTexture(panda);
            }
            else if(charofplayer[2]==5)
            {
                character21.setTexture(micky);
                character22.setTexture(micky);
                character23.setTexture(micky);
                character24.setTexture(micky);
                proj2.setTexture(micky);
            }
            else if(charofplayer[2]==6)
            {

                character21.setTexture(bart);
                character22.setTexture(bart);
                character23.setTexture(bart);
                character24.setTexture(bart);
                proj2.setTexture(bart);
            }
            else if(charofplayer[2]==8)
            {
                character21.setTexture(bat);
                character22.setTexture(bat);
                character23.setTexture(bat);
                character24.setTexture(bat);
                proj2.setTexture(bat);
            }
            else if(charofplayer[2]==9)
            {
                character21.setTexture(ironman);
                character22.setTexture(ironman);
                character23.setTexture(ironman);
                character24.setTexture(ironman);
                proj2.setTexture(ironman);
            }
            else if(charofplayer[2]==10)
            {
                character21.setTexture(naruto);
                character22.setTexture(naruto);
                character23.setTexture(naruto);
                character24.setTexture(naruto);
                proj2.setTexture(naruto);
            }
            else if(charofplayer[2]==11)
            {
                character21.setTexture(pickachu);
                character22.setTexture(pickachu);
                character23.setTexture(pickachu);
                character24.setTexture(pickachu);
                proj2.setTexture(pickachu);
            }
            else if(charofplayer[2]==12)
            {
                character21.setTexture(angry);
                character22.setTexture(angry);
                character23.setTexture(angry);
                character24.setTexture(angry);
                proj2.setTexture(angry);
            }
            else if(charofplayer[2]==13)
            {
                character21.setTexture(arya);
                character22.setTexture(arya);
                character23.setTexture(arya);
                character24.setTexture(arya);
                proj2.setTexture(arya);
            }




            if(charofplayer[3]==1)
            {
                character31.setTexture(ang);
                character32.setTexture(ang);
                character33.setTexture(ang);
                character34.setTexture(ang);
                proj3.setTexture(ang);
            }
            else if(charofplayer[3]==2)
            {
                character31.setTexture(hulk);
                character32.setTexture(hulk);
                character33.setTexture(hulk);
                character34.setTexture(hulk);
                proj3.setTexture(hulk);
            }
            else if(charofplayer[3]==3)
            {
                character31.setTexture(spidy);
                character32.setTexture(spidy);
                character33.setTexture(spidy);
                character34.setTexture(spidy);
                proj3.setTexture(spidy);
            }
            else if(charofplayer[3]==4)
            {
                character31.setTexture(panda);
                character32.setTexture(panda);
                character33.setTexture(panda);
                character34.setTexture(panda);
                proj3.setTexture(panda);
            }
            else if(charofplayer[3]==5)
            {
                character31.setTexture(micky);
                character32.setTexture(micky);
                character33.setTexture(micky);
                character34.setTexture(micky);
                proj3.setTexture(micky);
            }
            else if(charofplayer[3]==6)
            {

                character31.setTexture(bart);
                character32.setTexture(bart);
                character33.setTexture(bart);
                character34.setTexture(bart);
                proj3.setTexture(bart);
            }
            else if(charofplayer[3]==8)
            {
                character31.setTexture(bat);
                character32.setTexture(bat);
                character33.setTexture(bat);
                character34.setTexture(bat);
                proj3.setTexture(bat);
            }
            else if(charofplayer[3]==9)
            {
                character31.setTexture(ironman);
                character32.setTexture(ironman);
                character33.setTexture(ironman);
                character34.setTexture(ironman);
                proj3.setTexture(ironman);
            }
            else if(charofplayer[3]==10)
            {
                character31.setTexture(naruto);
                character32.setTexture(naruto);
                character33.setTexture(naruto);
                character34.setTexture(naruto);
                proj3.setTexture(naruto);
            }
            else if(charofplayer[3]==11)
            {
                character31.setTexture(pickachu);
                character32.setTexture(pickachu);
                character33.setTexture(pickachu);
                character34.setTexture(pickachu);
                proj3.setTexture(pickachu);
            }
            else if(charofplayer[3]==12)
            {
                character31.setTexture(angry);
                character32.setTexture(angry);
                character33.setTexture(angry);
                character34.setTexture(angry);
                proj3.setTexture(angry);
            }
            else if(charofplayer[3]==13)
            {
                character31.setTexture(arya);
                character32.setTexture(arya);
                character33.setTexture(arya);
                character34.setTexture(arya);
                proj3.setTexture(arya);
            }





            if(charofplayer[4]==1)
            {
                character41.setTexture(ang);
                character42.setTexture(ang);
                character43.setTexture(ang);
                character44.setTexture(ang);
                proj4.setTexture(ang);
            }
            else if(charofplayer[4]==2)
            {
                character41.setTexture(hulk);
                character42.setTexture(hulk);
                character43.setTexture(hulk);
                character44.setTexture(hulk);
                proj4.setTexture(hulk);
            }
            else if(charofplayer[4]==3)
            {
                character41.setTexture(spidy);
                character42.setTexture(spidy);
                character43.setTexture(spidy);
                character44.setTexture(spidy);
                proj4.setTexture(spidy);
            }
            else if(charofplayer[4]==4)
            {
                character41.setTexture(panda);
                character42.setTexture(panda);
                character43.setTexture(panda);
                character44.setTexture(panda);
                proj4.setTexture(panda);
            }
            else if(charofplayer[4]==5)
            {
                character41.setTexture(micky);
                character42.setTexture(micky);
                character43.setTexture(micky);
                character44.setTexture(micky);
                proj4.setTexture(micky);
            }
            else if(charofplayer[4]==6)
            {

                character41.setTexture(bart);
                character42.setTexture(bart);
                character43.setTexture(bart);
                character44.setTexture(bart);
                proj4.setTexture(bart);
            }
            else if(charofplayer[4]==8)
            {
                character41.setTexture(bat);
                character42.setTexture(bat);
                character43.setTexture(bat);
                character44.setTexture(bat);
                proj4.setTexture(bat);
            }
            else if(charofplayer[4]==9)
            {
                character41.setTexture(ironman);
                character42.setTexture(ironman);
                character43.setTexture(ironman);
                character44.setTexture(ironman);
                proj4.setTexture(ironman);
            }
            else if(charofplayer[4]==10)
            {
                character41.setTexture(naruto);
                character42.setTexture(naruto);
                character43.setTexture(naruto);
                character44.setTexture(naruto);
                proj4.setTexture(naruto);
            }
            else if(charofplayer[4]==11)
            {
                character41.setTexture(pickachu);
                character42.setTexture(pickachu);
                character43.setTexture(pickachu);
                character44.setTexture(pickachu);
                proj4.setTexture(pickachu);
            }
            else if(charofplayer[4]==12)
            {
                character41.setTexture(angry);
                character42.setTexture(angry);
                character43.setTexture(angry);
                character44.setTexture(angry);
                proj4.setTexture(angry);
            }
            else if(charofplayer[4]==13)
            {
                character41.setTexture(arya);
                character42.setTexture(arya);
                character43.setTexture(arya);
                character44.setTexture(arya);
                proj4.setTexture(arya);
            }





            if(charofplayer[5]==1)
            {
                character51.setTexture(ang);
                character52.setTexture(ang);
                character53.setTexture(ang);
                character54.setTexture(ang);
                proj5.setTexture(ang);
            }
            else if(charofplayer[5]==2)
            {
                character51.setTexture(hulk);
                character52.setTexture(hulk);
                character53.setTexture(hulk);
                character54.setTexture(hulk);
                proj5.setTexture(hulk);
            }
            else if(charofplayer[5]==3)
            {
                character51.setTexture(spidy);
                character52.setTexture(spidy);
                character53.setTexture(spidy);
                character54.setTexture(spidy);
                proj5.setTexture(spidy);
            }
            else if(charofplayer[5]==4)
            {
                character51.setTexture(panda);
                character52.setTexture(panda);
                character53.setTexture(panda);
                character54.setTexture(panda);
                proj5.setTexture(panda);
            }
            else if(charofplayer[5]==5)
            {
                character51.setTexture(micky);
                character52.setTexture(micky);
                character53.setTexture(micky);
                character54.setTexture(micky);
                proj5.setTexture(micky);
            }
            else if(charofplayer[5]==6)
            {

                character51.setTexture(bart);
                character52.setTexture(bart);
                character53.setTexture(bart);
                character54.setTexture(bart);
                proj5.setTexture(bart);
            }
            else if(charofplayer[5]==8)
            {
                character51.setTexture(bat);
                character52.setTexture(bat);
                character53.setTexture(bat);
                character54.setTexture(bat);
                proj5.setTexture(bat);
            }
            else if(charofplayer[5]==9)
            {
                character51.setTexture(ironman);
                character52.setTexture(ironman);
                character53.setTexture(ironman);
                character54.setTexture(ironman);
                proj5.setTexture(ironman);
            }
            else if(charofplayer[5]==10)
            {
                character51.setTexture(naruto);
                character52.setTexture(naruto);
                character53.setTexture(naruto);
                character54.setTexture(naruto);
                proj5.setTexture(naruto);
            }
            else if(charofplayer[5]==11)
            {
                character51.setTexture(pickachu);
                character52.setTexture(pickachu);
                character53.setTexture(pickachu);
                character54.setTexture(pickachu);
                proj5.setTexture(pickachu);
            }
            else if(charofplayer[5]==12)
            {
                character51.setTexture(angry);
                character52.setTexture(angry);
                character53.setTexture(angry);
                character54.setTexture(angry);
                proj5.setTexture(angry);
            }
            else if(charofplayer[5]==13)
            {
                character51.setTexture(arya);
                character52.setTexture(arya);
                character53.setTexture(arya);
                character54.setTexture(arya);
                proj5.setTexture(arya);
            }







            if(charofplayer[6]==1)
            {
                character61.setTexture(ang);
                character62.setTexture(ang);
                character63.setTexture(ang);
                character64.setTexture(ang);
                proj6.setTexture(ang);
            }
            else if(charofplayer[6]==2)
            {
                character61.setTexture(hulk);
                character62.setTexture(hulk);
                character63.setTexture(hulk);
                character64.setTexture(hulk);
                proj6.setTexture(hulk);
            }
            else if(charofplayer[6]==3)
            {
                character61.setTexture(spidy);
                character62.setTexture(spidy);
                character63.setTexture(spidy);
                character64.setTexture(spidy);
                proj6.setTexture(spidy);
            }
            else if(charofplayer[6]==4)
            {
                character61.setTexture(panda);
                character62.setTexture(panda);
                character63.setTexture(panda);
                character64.setTexture(panda);
                proj6.setTexture(panda);
            }
            else if(charofplayer[6]==5)
            {
                character61.setTexture(micky);
                character62.setTexture(micky);
                character63.setTexture(micky);
                character64.setTexture(micky);
                proj6.setTexture(micky);
            }
            else if(charofplayer[6]==6)
            {

                character61.setTexture(bart);
                character62.setTexture(bart);
                character63.setTexture(bart);
                character64.setTexture(bart);
                proj6.setTexture(bart);
            }
            else if(charofplayer[6]==8)
            {
                character61.setTexture(bat);
                character62.setTexture(bat);
                character63.setTexture(bat);
                character64.setTexture(bat);
                proj6.setTexture(bat);
            }
            else if(charofplayer[6]==9)
            {
                character61.setTexture(ironman);
                character62.setTexture(ironman);
                character63.setTexture(ironman);
                character64.setTexture(ironman);
                proj6.setTexture(ironman);
            }
            else if(charofplayer[6]==10)
            {
                character61.setTexture(naruto);
                character62.setTexture(naruto);
                character63.setTexture(naruto);
                character64.setTexture(naruto);
                proj6.setTexture(naruto);
            }
            else if(charofplayer[6]==11)
            {
                character61.setTexture(pickachu);
                character62.setTexture(pickachu);
                character63.setTexture(pickachu);
                character64.setTexture(pickachu);
                proj6.setTexture(pickachu);
            }
            else if(charofplayer[6]==12)
            {
                character61.setTexture(angry);
                character62.setTexture(angry);
                character63.setTexture(angry);
                character64.setTexture(angry);
                proj6.setTexture(angry);
            }
            else if(charofplayer[6]==13)
            {
                character61.setTexture(arya);
                character62.setTexture(arya);
                character63.setTexture(arya);
                character64.setTexture(arya);
                proj6.setTexture(arya);
            }
        }
        Texture one, two, three, four, five, six, rnd1, rnd2, dlogo, cmov1, cmov2, cmov3, cmov4, cmov5, cmov6, cmov7, cmov8, cmov9, cmov10, cmov11, cmov12, cmov13, ptr;
        dlogo.loadFromFile("data/image/dice logo.png");
        rnd1.loadFromFile("data/image/Dice a.png");
        rnd2.loadFromFile("data/image/dice b.png");
        one.loadFromFile("data/image/1.png");
        two.loadFromFile("data/image/2.png");
        three.loadFromFile("data/image/3.png");
        four.loadFromFile("data/image/4.png");
        five.loadFromFile("data/image/5.png");
        six.loadFromFile("data/image/6.png");
        ptr.loadFromFile("data/image/ponit.png");
        cmov1.loadFromFile("data/image/m1.png");
        cmov2.loadFromFile("data/image/m2.png");
        cmov3.loadFromFile("data/image/m3.png");
        cmov4.loadFromFile("data/image/m4.png");
        cmov5.loadFromFile("data/image/m5.png");
        cmov6.loadFromFile("data/image/m6.png");
        cmov7.loadFromFile("data/image/m7.png");
        cmov8.loadFromFile("data/image/m8.png");
        cmov9.loadFromFile("data/image/m9.png");
        cmov10.loadFromFile("data/image/m10.png");
        cmov11.loadFromFile("data/image/m11.png");
        cmov12.loadFromFile("data/image/m12.png");
        cmov13.loadFromFile("data/image/m13.png");
        Sprite p1rep, p2rep, p3rep, p4rep, dicean, dclogo(dlogo), cmov, dicean2, pointer(ptr);
        proj1.setColor(Color(30, 30, 30));
        proj6.setColor(Color(30, 30, 30));
        proj5.setColor(Color(30, 30, 30));
        proj4.setColor(Color(30, 30, 30));
        proj3.setColor(Color(30, 30, 30));
        proj2.setColor(Color(30, 30, 30));
        dclogo.setPosition(Vector2f(0, 460));
        dicean.setPosition(Vector2f(28, 500));
        dicean2.setPosition(Vector2f(10, 482));
        cmov.setPosition(Vector2f(566, 412));
        int gtimer=0, playertimer=-1, currentplayer=1, score, dice=0, pn=0, ice=1;
        int ptrpos[7]= {1530, 100, 151, 202, 253, 304, 355};
        while (GameWindow.isOpen())
        {

            gtimer++;
            if(gtimer>500)
            {
                if(score==6)
                    dicean.setTexture(six);
                else if(score==1)
                    dicean.setTexture(one);
                else if(score==2)
                    dicean.setTexture(two);
                else if(score==3)
                    dicean.setTexture(three);
                else if(score==4)
                    dicean.setTexture(four);
                else if(score==5)
                    dicean.setTexture(five);
            }
            else if((gtimer/150)%6==0)
                dicean.setTexture(six);
            else if((gtimer/150)%6==1)
                dicean.setTexture(one);
            else if((gtimer/150)%6==2)
                dicean.setTexture(two);
            else if((gtimer/150)%6==3)
                dicean.setTexture(three);
            else if((gtimer/150)%6==4)
                dicean.setTexture(four);
            else if((gtimer/150)%6==5)
                dicean.setTexture(five);

            if((gtimer/150)%2)
                dicean2.setTexture(rnd1);
            else
                dicean2.setTexture(rnd2);

            Event Event;
            while(GameWindow.pollEvent(Event))
            {
                switch (Event.type)
                {
                case Event::Closed:
                    NameWindow.close();
                }
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
            if(Keyboard::isKeyPressed(Keyboard::BackSpace))
                GameWindow.close();
            if(Keyboard::isKeyPressed(Keyboard::Escape))
            {
                GameWindow.close();
                flag++;
            }






            character11.setPosition(Vector2f(ppx[position[1][1]]-20, ppy[position[1][1]]-20));
            character12.setPosition(Vector2f(ppx[position[1][2]]-20, ppy[position[1][2]]-20));
            character13.setPosition(Vector2f(ppx[position[1][3]]-20, ppy[position[1][3]]-20));
            character14.setPosition(Vector2f(ppx[position[1][4]]-20, ppy[position[1][4]]-20));
            character21.setPosition(Vector2f(ppx[position[2][1]]-20, ppy[position[2][1]]-20));
            character22.setPosition(Vector2f(ppx[position[2][2]]-20, ppy[position[2][2]]-20));
            character23.setPosition(Vector2f(ppx[position[2][3]]-20, ppy[position[2][3]]-20));
            character24.setPosition(Vector2f(ppx[position[2][4]]-20, ppy[position[2][4]]-20));
            character31.setPosition(Vector2f(ppx[position[3][1]]-20, ppy[position[3][1]]-20));
            character32.setPosition(Vector2f(ppx[position[3][2]]-20, ppy[position[3][2]]-20));
            character33.setPosition(Vector2f(ppx[position[3][3]]-20, ppy[position[3][3]]-20));
            character34.setPosition(Vector2f(ppx[position[3][4]]-20, ppy[position[3][4]]-20));
            character41.setPosition(Vector2f(ppx[position[4][1]]-20, ppy[position[4][1]]-20));
            character42.setPosition(Vector2f(ppx[position[4][2]]-20, ppy[position[4][2]]-20));
            character43.setPosition(Vector2f(ppx[position[4][3]]-20, ppy[position[4][3]]-20));
            character44.setPosition(Vector2f(ppx[position[4][4]]-20, ppy[position[4][4]]-20));
            character51.setPosition(Vector2f(ppx[position[5][1]]-20, ppy[position[5][1]]-20));
            character52.setPosition(Vector2f(ppx[position[5][2]]-20, ppy[position[5][2]]-20));
            character53.setPosition(Vector2f(ppx[position[5][3]]-20, ppy[position[5][3]]-20));
            character54.setPosition(Vector2f(ppx[position[5][4]]-20, ppy[position[5][4]]-20));
            character61.setPosition(Vector2f(ppx[position[6][1]]-20, ppy[position[6][1]]-20));
            character62.setPosition(Vector2f(ppx[position[6][2]]-20, ppy[position[6][2]]-20));
            character63.setPosition(Vector2f(ppx[position[6][3]]-20, ppy[position[6][3]]-20));
            character64.setPosition(Vector2f(ppx[position[6][4]]-20, ppy[position[6][4]]-20));
            proj1.setPosition(Vector2f(ppx[position[1][5]]-20, ppy[position[1][5]]-20));
            proj2.setPosition(Vector2f(ppx[position[2][5]]-20, ppy[position[2][5]]-20));
            proj3.setPosition(Vector2f(ppx[position[3][5]]-20, ppy[position[3][5]]-20));
            proj4.setPosition(Vector2f(ppx[position[4][5]]-20, ppy[position[4][5]]-20));
            proj5.setPosition(Vector2f(ppx[position[5][5]]-20, ppy[position[5][5]]-20));
            proj6.setPosition(Vector2f(ppx[position[6][5]]-20, ppy[position[6][5]]-20));
            GameWindow.clear();
            GameWindow.draw(bg);
            GameWindow.draw(character11);
            GameWindow.draw(character12);
            GameWindow.draw(character13);
            GameWindow.draw(character14);
            GameWindow.draw(character21);
            GameWindow.draw(character22);
            GameWindow.draw(character23);
            GameWindow.draw(character24);
            GameWindow.draw(character31);
            GameWindow.draw(character32);
            GameWindow.draw(character33);
            GameWindow.draw(character34);
            GameWindow.draw(character41);
            GameWindow.draw(character42);
            GameWindow.draw(character43);
            GameWindow.draw(character44);
            GameWindow.draw(character51);
            GameWindow.draw(character52);
            GameWindow.draw(character53);
            GameWindow.draw(character54);
            GameWindow.draw(character61);
            GameWindow.draw(character62);
            GameWindow.draw(character63);
            GameWindow.draw(character64);
            GameWindow.draw(Name1);
            GameWindow.draw(Name2);
            GameWindow.draw(Name3);
            GameWindow.draw(Name4);
            GameWindow.draw(Name5);
            GameWindow.draw(Name6);
            Vector2i mpos=Mouse::getPosition(GameWindow);
            int x=mpos.x, y=mpos.y;


            if(x<100&&y>460&&Event.type==Event::MouseButtonPressed)
            {
                if(dice==0)
                {
                    snd.setBuffer(rol);
                    snd.play();
                    score=(rand()+x+y+gtimer)%6+1;
                    dice=1;
                    gtimer=0;
                    ice=0;
                    position[currentplayer][5]=position[currentplayer][1];
                    spos(currentplayer, score,5 );
                    ice+=flagofvalidmove;
                    position[currentplayer][5]=position[currentplayer][2];
                    spos(currentplayer, score,5 );
                    ice+=flagofvalidmove;
                    position[currentplayer][5]=position[currentplayer][3];
                    spos(currentplayer, score,5 );
                    ice+=flagofvalidmove;
                    position[currentplayer][5]=position[currentplayer][4];
                    spos(currentplayer, score,5 );
                    ice+=flagofvalidmove;
                }
            }
            if(!ice&&gtimer>1050)
            {
                snd.setBuffer(ops);
                snd.play();
                dice=0;
                ice=1;
                if(score!=6)
                    currentplayer++;
                if(currentplayer==7)
                    currentplayer=1;
                while(victory[currentplayer])
                {
                    currentplayer++;
                    if(currentplayer==7)
                        currentplayer=1;
                }
            }
            if(ice&&x>565&&y>460&&y<555&&x<1000)
            {
                if(x<674)
                {
                    pn=1;
                    position[currentplayer][5]=position[currentplayer][1];
                    if(pn&&dice&&gtimer>500)
                    {
                        if(currentplayer==1)
                        {
                            proj1.setPosition(Vector2f(ppx[position[1][5]]-20, ppy[position[1][5]]-20));
                            GameWindow.draw(proj1);
                        }
                        if(currentplayer==2)
                        {
                            proj2.setPosition(Vector2f(ppx[position[2][5]]-20, ppy[position[2][5]]-20));
                            GameWindow.draw(proj2);
                        }

                        if(currentplayer==3)
                        {
                            proj3.setPosition(Vector2f(ppx[position[3][5]]-20, ppy[position[3][5]]-20));
                            GameWindow.draw(proj3);
                        }
                        if(currentplayer==4)
                        {
                            proj4.setPosition(Vector2f(ppx[position[4][5]]-20, ppy[position[4][5]]-20));
                            GameWindow.draw(proj4);
                        }
                        if(currentplayer==5)
                        {
                            proj5.setPosition(Vector2f(ppx[position[5][5]]-20, ppy[position[5][5]]-20));
                            GameWindow.draw(proj5);
                        }
                        if(currentplayer==6)
                        {
                            proj6.setPosition(Vector2f(ppx[position[6][5]]-20, ppy[position[6][5]]-20));
                            GameWindow.draw(proj6);
                        }
                    }
                    spos(currentplayer, score,5 );
                }
                else if(x<783)
                {
                    pn=2;
                    position[currentplayer][5]=position[currentplayer][2];
                    if(pn&&dice&&gtimer>500)
                    {
                        if(currentplayer==1)
                        {
                            proj1.setPosition(Vector2f(ppx[position[1][5]]-20, ppy[position[1][5]]-20));
                            GameWindow.draw(proj1);
                        }
                        if(currentplayer==2)
                        {
                            proj2.setPosition(Vector2f(ppx[position[2][5]]-20, ppy[position[2][5]]-20));
                            GameWindow.draw(proj2);
                        }

                        if(currentplayer==3)
                        {
                            proj3.setPosition(Vector2f(ppx[position[3][5]]-20, ppy[position[3][5]]-20));
                            GameWindow.draw(proj3);
                        }
                        if(currentplayer==4)
                        {
                            proj4.setPosition(Vector2f(ppx[position[4][5]]-20, ppy[position[4][5]]-20));
                            GameWindow.draw(proj4);
                        }
                        if(currentplayer==5)
                        {
                            proj5.setPosition(Vector2f(ppx[position[5][5]]-20, ppy[position[5][5]]-20));
                            GameWindow.draw(proj5);
                        }
                        if(currentplayer==6)
                        {
                            proj6.setPosition(Vector2f(ppx[position[6][5]]-20, ppy[position[6][5]]-20));
                            GameWindow.draw(proj6);
                        }
                    }
                    spos(currentplayer, score,5 );
                }
                else if(x<892)
                {
                    pn=3;
                    position[currentplayer][5]=position[currentplayer][3];
                    if(pn&&dice&&gtimer>500)
                    {
                        if(currentplayer==1)
                        {
                            proj1.setPosition(Vector2f(ppx[position[1][5]]-20, ppy[position[1][5]]-20));
                            GameWindow.draw(proj1);
                        }
                        if(currentplayer==2)
                        {
                            proj2.setPosition(Vector2f(ppx[position[2][5]]-20, ppy[position[2][5]]-20));
                            GameWindow.draw(proj2);
                        }

                        if(currentplayer==3)
                        {
                            proj3.setPosition(Vector2f(ppx[position[3][5]]-20, ppy[position[3][5]]-20));
                            GameWindow.draw(proj3);
                        }
                        if(currentplayer==4)
                        {
                            proj4.setPosition(Vector2f(ppx[position[4][5]]-20, ppy[position[4][5]]-20));
                            GameWindow.draw(proj4);
                        }
                        if(currentplayer==5)
                        {
                            proj5.setPosition(Vector2f(ppx[position[5][5]]-20, ppy[position[5][5]]-20));
                            GameWindow.draw(proj5);
                        }
                        if(currentplayer==6)
                        {
                            proj6.setPosition(Vector2f(ppx[position[6][5]]-20, ppy[position[6][5]]-20));
                            GameWindow.draw(proj6);
                        }
                    }
                    spos(currentplayer, score,5 );
                }
                else
                {
                    pn=4;
                    position[currentplayer][5]=position[currentplayer][4];
                    if(pn&&dice&&gtimer>500)
                    {
                        if(currentplayer==1)
                        {
                            proj1.setPosition(Vector2f(ppx[position[1][5]]-20, ppy[position[1][5]]-20));
                            GameWindow.draw(proj1);
                        }
                        if(currentplayer==2)
                        {
                            proj2.setPosition(Vector2f(ppx[position[2][5]]-20, ppy[position[2][5]]-20));
                            GameWindow.draw(proj2);
                        }

                        if(currentplayer==3)
                        {
                            proj3.setPosition(Vector2f(ppx[position[3][5]]-20, ppy[position[3][5]]-20));
                            GameWindow.draw(proj3);
                        }
                        if(currentplayer==4)
                        {
                            proj4.setPosition(Vector2f(ppx[position[4][5]]-20, ppy[position[4][5]]-20));
                            GameWindow.draw(proj4);
                        }
                        if(currentplayer==5)
                        {
                            proj5.setPosition(Vector2f(ppx[position[5][5]]-20, ppy[position[5][5]]-20));
                            GameWindow.draw(proj5);
                        }
                        if(currentplayer==6)
                        {
                            proj6.setPosition(Vector2f(ppx[position[6][5]]-20, ppy[position[6][5]]-20));
                            GameWindow.draw(proj6);
                        }
                    }
                    spos(currentplayer, score,5 );
                }
            }
            else
                pn=0;
            if(pn&&Event.type==Event::MouseButtonPressed)
            {
                if(position[currentplayer][pn]!=position[currentplayer][5])
                if(dice)
                {
                    spos(currentplayer, score, pn);
                    snd.setBuffer(mv);
                    snd.play();
                    if(score!=6)
                        currentplayer++;
                    if(currentplayer==7)
                        currentplayer=1;
                    while(victory[currentplayer])
                    {
                        currentplayer++;
                        if(currentplayer==7)
                            currentplayer=1;
                    }
                    dice=0;
                }
            }
            if(pn&&dice&&gtimer>500)
            {
                proj1.setPosition(Vector2f(ppx[position[1][5]]-20, ppy[position[1][5]]-20));
                proj2.setPosition(Vector2f(ppx[position[2][5]]-20, ppy[position[2][5]]-20));
                proj3.setPosition(Vector2f(ppx[position[3][5]]-20, ppy[position[3][5]]-20));
                proj4.setPosition(Vector2f(ppx[position[4][5]]-20, ppy[position[4][5]]-20));
                proj5.setPosition(Vector2f(ppx[position[5][5]]-20, ppy[position[5][5]]-20));
                proj6.setPosition(Vector2f(ppx[position[6][5]]-20, ppy[position[6][5]]-20));
                if(currentplayer==1)
                    GameWindow.draw(proj1);
                if(currentplayer==2)
                    GameWindow.draw(proj2);
                if(currentplayer==3)
                    GameWindow.draw(proj3);
                if(currentplayer==4)
                    GameWindow.draw(proj4);
                if(currentplayer==5)
                    GameWindow.draw(proj5);
                if(currentplayer==6)
                    GameWindow.draw(proj6);
            }

            if(charofplayer[currentplayer]==1)
                cmov.setTexture(cmov1);
            if(charofplayer[currentplayer]==2)
                cmov.setTexture(cmov2);
            if(charofplayer[currentplayer]==3)
                cmov.setTexture(cmov3);
            if(charofplayer[currentplayer]==4)
                cmov.setTexture(cmov4);
            if(charofplayer[currentplayer]==5)
                cmov.setTexture(cmov5);
            if(charofplayer[currentplayer]==6)
                cmov.setTexture(cmov6);
            if(charofplayer[currentplayer]==7)
                cmov.setTexture(cmov7);
            if(charofplayer[currentplayer]==8)
                cmov.setTexture(cmov8);
            if(charofplayer[currentplayer]==9)
                cmov.setTexture(cmov9);
            if(charofplayer[currentplayer]==10)
                cmov.setTexture(cmov10);
            if(charofplayer[currentplayer]==11)
                cmov.setTexture(cmov11);
            if(charofplayer[currentplayer]==12)
                cmov.setTexture(cmov12);
            if(charofplayer[currentplayer]==13)
                cmov.setTexture(cmov13);

            if(!dice)
                GameWindow.draw(dclogo);
            else
            {
                if((gtimer/75)%2&&gtimer<500)
                    GameWindow.draw(dicean2);
                else
                    GameWindow.draw(dicean);
            }
            if(dice&&gtimer>500&&ice)
                GameWindow.draw(cmov);

            pointer.setPosition(Vector2f(510, ptrpos[currentplayer]));
            GameWindow.draw(pointer);
            GameWindow.display();
        }
    }

}
