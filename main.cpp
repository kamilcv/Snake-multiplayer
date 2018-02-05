#include <time.h>
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <sstream>
#include <fstream>

#include "kody_klawiszy.h"

#define MENU 1
#define GRA 2

#define USTAWIENIA 3
#define AUTOR 4
#define WYJSCIE 5

#define USTAWIENIA_GRACZY 6
#define ZMIANA_STEROWANIA 7

using namespace std;

class snake
{
    sf::RectangleShape kwadrat;
    sf::Vector2f pozycja;
    sf::Vector2f stara_pozycja;
    sf::Vector2f rozmiar = sf::Vector2f( 50, 50 );

public:

    snake();
    void setPosition( sf::Vector2f poz );
    void setPosition( float x, float y );
    sf::Vector2f getPosition();
    sf::Vector2f getStaraPozycja();
    void przeusn( int kierunek, int );
    void rysuj( sf::RenderWindow& );
    void ustaw_kolor( sf::Color );
    void ustaw_rozmiar( sf::Vector2f );
    void ustaw_rozmiar( float );
};

snake::snake()
{
    kwadrat.setSize( rozmiar );
    kwadrat.setFillColor( sf::Color::Red );
    kwadrat.setOutlineThickness( 1 );
    kwadrat.setOutlineColor( sf::Color::Black );
}

void snake::setPosition( sf::Vector2f poz )
{
    pozycja = poz;
    kwadrat.setPosition( pozycja );
}
void snake::setPosition( float x, float y )
{
    pozycja.x = x;
    pozycja.y = y;
    kwadrat.setPosition( pozycja );
}

sf::Vector2f snake::getPosition()
{
    return pozycja;
}

sf::Vector2f snake::getStaraPozycja()
{
    return stara_pozycja;
}

void snake::przeusn( int kierunek, int rozmiar_gracza )
{
    switch( kierunek )
    {
    case 1:
        pozycja.y -= rozmiar_gracza;
        break;

    case 2:
        pozycja.x -= rozmiar_gracza;
        break;

    case 3:
        pozycja.y += rozmiar_gracza;
        break;

    case 4:
        pozycja.x += rozmiar_gracza;
        break;
    }
    kwadrat.setPosition( pozycja );
}

void snake::rysuj( sf::RenderWindow & okno )
{
    stara_pozycja = pozycja;
    okno.draw( kwadrat );
}

void snake::ustaw_kolor( sf::Color kolor )
{
    kwadrat.setFillColor( kolor );
}

void snake::ustaw_rozmiar( sf::Vector2f rozmiar_metoda )
{
    rozmiar = rozmiar_metoda;
    kwadrat.setSize( rozmiar );
}

void snake::ustaw_rozmiar( float rozmiar_metoda )
{
    rozmiar.x = rozmiar_metoda;
    rozmiar.y = rozmiar_metoda;

    kwadrat.setSize( rozmiar );
}

int main()
{
    srand( time( NULL ) );
    sf::RenderWindow okno( sf::VideoMode( 1280, 720, 32 ), "Snake", sf::Style::Fullscreen );

    int status_gry = MENU;

    //int dlugosc_weza = 3;
    //int dlugosc_weza_2 = 3;
    //int kierunek = 4;
    //int kierunek_2 = 4;

    int dlugosc_weza_menu = 3;
    int kierunek_weza_menu = 4;

    int dlugosc_weza[ 8 ];
    int kierunek[ 8 ];

    for( int i = 0; i < 8; i++ )
    {
        dlugosc_weza[ i ] = 3;

        if( i < 4 )
            kierunek[ i ] = 4;
        else
            kierunek[ i ] = 2;
    }

    sf::Text wynik;

    sf::String swynik;

    sf::Font czcionka;
    czcionka.loadFromFile( "arial.ttf" );

    ostringstream ss;

    //std::vector <snake> waz;

    //waz.push_back();

    //snake waz[ 100 ];
    //snake waz_2[ 100 ];

    //for( int i = 0 ; i < 100; i++ )
        //waz[ i ].ustaw_kolor( sf::Color::Red );
    //for( int i = 0 ; i < 100; i++ )
        //waz_2[ i ].ustaw_kolor( sf::Color( 255, 0, 255 ) );


    //waz[ 0 ].setPosition( 200, 200 );
    //waz[ 1 ].setPosition( 150, 200 );
    //waz[ 2 ].setPosition( 100, 200 );

    //waz_2[ 0 ].setPosition( 200, 400 );
    //waz_2[ 1 ].setPosition( 150, 400 );
    //waz_2[ 2 ].setPosition( 100, 400 );

    snake waz_przykladowy;
    waz_przykladowy.ustaw_kolor( sf::Color::Red );
    waz_przykladowy.setPosition( -100, -100 );

    std::vector <snake> waz_menu;
    waz_menu.push_back( waz_przykladowy );
    waz_menu.push_back( waz_przykladowy );
    waz_menu.push_back( waz_przykladowy );

    waz_menu[ 0 ].setPosition( 200, 200 );
    waz_menu[ 1 ].setPosition( 150, 200 );
    waz_menu[ 2 ].setPosition( 100, 200 );

    //snake **waz = new snake *[ 8 ];


    vector< vector<snake> > waz( 8, vector<snake>( 3 ) );

    //vector <snake> jakis_vector( 8 );
    //vector < vector<snake> >waz( 3, jakis_vector );

    //waz[ 0 ][ 0 ];
    //waz[ 0 ][ 1 ] = 150;
    //waz[ 0 ][ 2 ] = 250;

    sf::Clock zegar;

    sf::RectangleShape jedzenie( sf::Vector2f( 50, 50 ) );
    jedzenie.setFillColor( sf::Color::Blue );
    jedzenie.setOutlineThickness( 1 );
    jedzenie.setOutlineColor( sf::Color::Black );

    sf::Vector2f pozycja_jedzenia;
    bool losuj = true;
    bool kolizja_jedzenia = false;

    //bool najechano_start = true;
    //bool najechano_ustawienia = false;
    //bool najechano_autor = false;
    //bool najechano_wyjscie = false;

    int dzielnik;

    int liczba_graczy = 1;
    int rozmiar_graczy = 50;

    int ktore_najechano = 0;
    int ktore_najechano_ustawienia = 0;
    int ktore_najechano_ustawienia_graczy = 0;
    int ktore_najechano_ustawienia_graczy_2 = 0;
    int ktory_kolor_najechano = 0;
    int ktory_klawisz_najechano = 0;

    int zmiana_sterowanie_ktorego_gracza = 0;

    int zmiana_koloru = 0;

    bool przenikanie_sciany = false;
    bool przenikanie_weze = false;

    int jakis_kolor;

    sf::Color kolor_gracza[ 8 ];

    kolor_gracza[ 0 ] = sf::Color( 0, 0, 0 );
    kolor_gracza[ 1 ] = sf::Color( 255, 0, 0 );
    kolor_gracza[ 2 ] = sf::Color( 0, 255, 0 );
    kolor_gracza[ 3 ] = sf::Color( 0, 0, 255 );
    kolor_gracza[ 4 ] = sf::Color( 255, 255, 0 );
    kolor_gracza[ 5 ] = sf::Color( 0, 255, 255 );
    kolor_gracza[ 6 ] = sf::Color( 255, 0, 255 );
    kolor_gracza[ 7 ] = sf::Color( 255, 255, 255 );

    sf::Event klawisze_gracza[ 8 ][ 4 ];
    int klawisze_gracza_kody[ 8 ][ 4 ];
    char klawisze_gracza_kody_char[ 8 ][ 4 ];

    for( int i = 0; i < 8; i++ )
    {
        for( int j = 0; j < 4; j++ )
        {
            klawisze_gracza[ i ][ j ].key.code = sf::Keyboard::Unknown;
            klawisze_gracza_kody[ i ][ j ] = -1;
            klawisze_gracza_kody_char[ i ][ j ] = -1;
        }
    }

    klawisze_gracza[ 0 ][ 0 ].key.code = sf::Keyboard::W;
    klawisze_gracza[ 0 ][ 1 ].key.code = sf::Keyboard::A;
    klawisze_gracza[ 0 ][ 2 ].key.code = sf::Keyboard::S;
    klawisze_gracza[ 0 ][ 3 ].key.code = sf::Keyboard::D;

    klawisze_gracza_kody[ 0 ][ 0 ] = 22;
    klawisze_gracza_kody[ 0 ][ 1 ] = 0;
    klawisze_gracza_kody[ 0 ][ 2 ] = 18;
    klawisze_gracza_kody[ 0 ][ 3 ] = 3;

    klawisze_gracza_kody_char[ 0 ][ 0 ] = 22;
    klawisze_gracza_kody_char[ 0 ][ 1 ] = 0;
    klawisze_gracza_kody_char[ 0 ][ 2 ] = 18;
    klawisze_gracza_kody_char[ 0 ][ 3 ] = 3;

    klawisze_gracza[ 1 ][ 0 ].key.code = sf::Keyboard::Up;
    klawisze_gracza[ 1 ][ 1 ].key.code = sf::Keyboard::Left;
    klawisze_gracza[ 1 ][ 2 ].key.code = sf::Keyboard::Down;
    klawisze_gracza[ 1 ][ 3 ].key.code = sf::Keyboard::Right;

    klawisze_gracza_kody[ 1 ][ 0 ] = 73;
    klawisze_gracza_kody[ 1 ][ 1 ] = 71;
    klawisze_gracza_kody[ 1 ][ 2 ] = 74;
    klawisze_gracza_kody[ 1 ][ 3 ] = 72;

    klawisze_gracza_kody_char[ 1 ][ 0 ] = 73;
    klawisze_gracza_kody_char[ 1 ][ 1 ] = 71;
    klawisze_gracza_kody_char[ 1 ][ 2 ] = 74;
    klawisze_gracza_kody_char[ 1 ][ 3 ] = 72;

    ifstream plik;
    ofstream plik_zapisu;
    string linijka;
    int ktory_gracz_plik;
    int kod_klawisza_plik;
    plik.open( "klawisze.ini" );
    if( !plik.good() )
        cout << "Blad pliku klawisze.ini" << endl;

    while( !plik.eof() )
    {
        linijka = "";
        plik >> linijka;

        ktory_gracz_plik = linijka[ 1 ] - 48;


        plik >> klawisze_gracza_kody[ ktory_gracz_plik ][ 0 ];
        klawisze_gracza_kody_char[ ktory_gracz_plik ][ 0 ] = klawisze_gracza_kody[ ktory_gracz_plik ][ 0 ];
        plik >> klawisze_gracza_kody[ ktory_gracz_plik ][ 1 ];
        klawisze_gracza_kody_char[ ktory_gracz_plik ][ 1 ] = klawisze_gracza_kody[ ktory_gracz_plik ][ 1 ];
        plik >> klawisze_gracza_kody[ ktory_gracz_plik ][ 2 ];
        klawisze_gracza_kody_char[ ktory_gracz_plik ][ 2 ] = klawisze_gracza_kody[ ktory_gracz_plik ][ 2 ];
        plik >> klawisze_gracza_kody[ ktory_gracz_plik ][ 3 ];
        klawisze_gracza_kody_char[ ktory_gracz_plik ][ 3 ] = klawisze_gracza_kody[ ktory_gracz_plik ][ 3 ];
    }
    plik.close();

    int liczba_plik;

    int linijka_int;

    plik.open( "ustawienia.ini" );
    if( !plik.good() )
        cout << "blad pliku ustawienia.ini" << endl;


    plik >> liczba_graczy;
    for( int i = 0; i < 8; i++ )
    {
        plik >> liczba_plik;
        kolor_gracza[ i ].r = liczba_plik;

        plik >> liczba_plik;
        kolor_gracza[ i ].g = liczba_plik;

        plik >> liczba_plik;
        kolor_gracza[ i ].b = liczba_plik;
    }

    plik >> rozmiar_graczy;

    plik >> linijka_int;

    if( linijka_int == 0 )
        przenikanie_sciany = false;
    else
        przenikanie_sciany = true;

    plik >> linijka_int;

    if( linijka_int == 0 )
        przenikanie_weze = false;
    else
        przenikanie_weze = true;

    plik.close();

    bool czy_zmiana_sterowania = false;

    sf::RectangleShape przyklad_koloru[ 8 ];

    for( int i = 0; i < 8; i++ )
    {
        przyklad_koloru[ i ].setSize( sf::Vector2f( 100, 50 ) );
        przyklad_koloru[ i ].setOutlineThickness( 2 );
        przyklad_koloru[ i ].setOutlineColor( sf::Color::Black );
        przyklad_koloru[ i ].setFillColor( kolor_gracza[ i ] );
    }

    sf::Vector2f pozycja_startowa[ 8 ];
    pozycja_startowa[ 0 ].x = 200; pozycja_startowa[ 0 ].y = 100;
    pozycja_startowa[ 1 ].x = 200; pozycja_startowa[ 1 ].y = 250;
    pozycja_startowa[ 2 ].x = 200; pozycja_startowa[ 2 ].y = 400;
    pozycja_startowa[ 3 ].x = 200; pozycja_startowa[ 3 ].y = 550;

    pozycja_startowa[ 4 ].x = 900; pozycja_startowa[ 4 ].y = 100;
    pozycja_startowa[ 5 ].x = 900; pozycja_startowa[ 5 ].y = 250;
    pozycja_startowa[ 6 ].x = 900; pozycja_startowa[ 6 ].y = 400;
    pozycja_startowa[ 7 ].x = 900; pozycja_startowa[ 7 ].y = 550;


    sf::Event zdarzenie;

    while( okno.isOpen() )
    {
        while( okno.pollEvent( zdarzenie ) )
        {
            /*if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::W )
                kierunek = 1;
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::A )
                kierunek = 2;
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::S )
                kierunek = 3;
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::D )
                kierunek = 4;

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Up )
                kierunek_2 = 1;
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Left )
                kierunek_2 = 2;
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Down )
                kierunek_2 = 3;
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Right )
                kierunek_2 = 4;*/

            if( status_gry == MENU )
            {
                if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Down )
                    ktore_najechano++;
                if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Up )
                    ktore_najechano--;
                if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Return )
                {
                    status_gry = ktore_najechano + 2;
                    ktore_najechano = 0;

                    if( status_gry == GRA )
                    {
                        losuj = true;

                        for( int i = 0; i < liczba_graczy; i++ )
                        {
                            dzielnik = 200 / rozmiar_graczy;
                            pozycja_startowa[ i ].x = rozmiar_graczy * dzielnik;
                            dzielnik = ( 150 + i * 150 ) / rozmiar_graczy;
                            pozycja_startowa[ i ].y = rozmiar_graczy * dzielnik;
                        }

                        jedzenie.setSize( sf::Vector2f( rozmiar_graczy, rozmiar_graczy ) );

                        for( int i = 0; i < liczba_graczy; i++ )
                        {

                            //waz[ i ] = new snake [ 3 ];
                            for( int j = 0; j < 3; j++ )
                            {
                                //waz_przykladowy.ustaw_kolor( kolor_gracza[ i ] );
                                //if( i < 4 )
                                //{
                                  //  waz_przykladowy.setPosition( pozycja_startowa[ i ].x - j * rozmiar_graczy, pozycja_startowa[ i ].y );
                                   // cout << waz_przykladowy.getPosition().x << " " << waz_przykladowy.getPosition().y << endl;
                                //}
                                //else
                                  //  waz_przykladowy.setPosition( pozycja_startowa[ i ].x + j * rozmiar_graczy, pozycja_startowa[ i ].y );
                                //waz[ i ][ j ] = waz_przykladowy;

                                //waz[ i ].push_back( waz_przykladowy );
                                waz[ i ][ j ].ustaw_kolor( kolor_gracza[ i ] );
                                if( i < 4 )
                                    waz[ i ][ j ].setPosition( pozycja_startowa[ i ].x - j * rozmiar_graczy, pozycja_startowa[ i ].y );
                                else
                                    waz[ i ][ j ].setPosition( pozycja_startowa[ i ].x + j * rozmiar_graczy, pozycja_startowa[ i ].y );

                                waz[ i ][ j ].ustaw_rozmiar( rozmiar_graczy );
                            }
                        }
                    }
                }

            }
            else if( status_gry == USTAWIENIA )
            {
                if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Down )
                    ktore_najechano_ustawienia++;
                if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Up )
                    ktore_najechano_ustawienia--;
                if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Right )
                {
                    switch( ktore_najechano_ustawienia )
                    {
                    case 0:
                        liczba_graczy++;
                        if( liczba_graczy > 8 )
                            liczba_graczy = 8;
                        break;
                    case 2:
                        rozmiar_graczy++;
                        if( rozmiar_graczy > 100 )
                            rozmiar_graczy = 100;
                        break;
                    case 3:
                        if( przenikanie_sciany == false )
                            przenikanie_sciany = true;
                        else
                            przenikanie_sciany = false;
                        break;
                    case 4:
                        if( przenikanie_weze == false )
                            przenikanie_weze = true;
                        else
                            przenikanie_weze = false;
                        break;
                    }
                }
                if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Left )
                {
                    switch( ktore_najechano_ustawienia )
                    {
                    case 0:
                        liczba_graczy--;
                        if( liczba_graczy <= 0)
                            liczba_graczy = 1;
                        break;
                    case 2:
                        rozmiar_graczy--;
                        if( rozmiar_graczy <= 0 )
                            rozmiar_graczy = 1;
                        break;
                    case 3:
                        if( przenikanie_sciany == false )
                            przenikanie_sciany = true;
                        else
                            przenikanie_sciany = false;
                        break;
                    case 4:
                        if( przenikanie_weze == false )
                            przenikanie_weze = true;
                        else
                            przenikanie_weze = false;
                        break;
                    }
                }
                if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Return )
                {
                    switch( ktore_najechano_ustawienia )
                    {
                    case 1:
                        status_gry = USTAWIENIA_GRACZY;
                        ktore_najechano_ustawienia = 0;
                        break;
                    case 5:
                        ktore_najechano_ustawienia = 0;

                        plik_zapisu.open( "ustawienia.ini", ios::in | ios::trunc );

                        plik_zapisu << liczba_graczy << endl;

                        for( int i = 0; i < 8; i++ )
                        {
                            liczba_plik = kolor_gracza[ i ].r;
                            plik_zapisu << liczba_plik << " ";
                            liczba_plik = kolor_gracza[ i ].g;
                            plik_zapisu << liczba_plik << " ";
                            liczba_plik = kolor_gracza[ i ].b;
                            plik_zapisu << liczba_plik << endl;
                        }

                        plik_zapisu << rozmiar_graczy << endl;

                        if( przenikanie_sciany == false )
                            plik_zapisu << 0 << endl;
                        else
                            plik_zapisu << 1 << endl;

                        if( przenikanie_weze == false )
                            plik_zapisu << 0 << endl;
                        else
                            plik_zapisu << 1 << endl;

                        plik_zapisu.close();

                        status_gry = MENU;
                        break;
                    }
                }
            }
            else if( status_gry == USTAWIENIA_GRACZY )
            {
                if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Down )
                {
                    if( ktore_najechano_ustawienia_graczy_2 == 0 && ktory_kolor_najechano > 0 )
                    {
                        switch( ktory_kolor_najechano )
                        {
                        case 1:
                            kolor_gracza[ ktore_najechano_ustawienia_graczy ].r--;
                            break;
                        case 2:
                            kolor_gracza[ ktore_najechano_ustawienia_graczy ].g--;
                            break;
                        case 3:
                            kolor_gracza[ ktore_najechano_ustawienia_graczy ].b--;
                            break;
                        }
                    }
                    else
                    {
                        ktore_najechano_ustawienia_graczy_2++;
                        if( ktore_najechano_ustawienia_graczy_2 == 2 )
                        {
                            ktore_najechano_ustawienia_graczy++;
                            ktore_najechano_ustawienia_graczy_2 = 0;
                        }
                    }

                }
                if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Up )
                {
                    if( ktore_najechano_ustawienia_graczy_2 == 0 && ktory_kolor_najechano > 0 )
                    {
                        switch( ktory_kolor_najechano )
                        {
                        case 1:
                            kolor_gracza[ ktore_najechano_ustawienia_graczy ].r++;
                            break;
                        case 2:
                            kolor_gracza[ ktore_najechano_ustawienia_graczy ].g++;
                            break;
                        case 3:
                            kolor_gracza[ ktore_najechano_ustawienia_graczy ].b++;
                            break;
                        }
                    }
                    else
                    {
                        ktore_najechano_ustawienia_graczy_2--;
                        if( ktore_najechano_ustawienia_graczy_2 == -1 )
                        {
                            ktore_najechano_ustawienia_graczy--;
                            ktore_najechano_ustawienia_graczy_2 = 1;
                        }
                    }

                }
                if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Right )
                {
                    if( ktore_najechano_ustawienia_graczy_2 == 0 )
                    {
                        ktory_kolor_najechano++;
                        if( ktory_kolor_najechano > 3 )
                            ktory_kolor_najechano = 3;
                    }
                }
                if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Left )
                {
                    if( ktore_najechano_ustawienia_graczy_2 == 0 )
                    {
                        ktory_kolor_najechano--;
                        if( ktory_kolor_najechano < 0 )
                            ktory_kolor_najechano = 0;
                    }
                }
                if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Return )
                {
                    if( ktore_najechano_ustawienia_graczy_2 == 1 )
                    {
                        status_gry = ZMIANA_STEROWANIA;

                    }
                    if( ktore_najechano_ustawienia_graczy == liczba_graczy )
                    {
                        ktore_najechano_ustawienia_graczy = 0;
                        ktore_najechano_ustawienia_graczy_2 = 0;
                        status_gry = USTAWIENIA;
                    }
                }
            }
            else if( status_gry == ZMIANA_STEROWANIA )
            {
                if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Down )
                {
                    if( czy_zmiana_sterowania == false )
                    {
                        ktory_klawisz_najechano++;
                        if( ktory_klawisz_najechano > 4 )
                            ktory_klawisz_najechano = 4;
                    }

                }
                if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Up )
                {
                    if( czy_zmiana_sterowania == false )
                    {
                        ktory_klawisz_najechano--;
                        if( ktory_klawisz_najechano < 0 )
                            ktory_klawisz_najechano = 0;
                    }

                }
                if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Return )
                {
                    if( ktory_klawisz_najechano == 4 )
                    {
                        plik_zapisu.open( "klawisze.ini", ios::in | ios::trunc );
                        if( !plik_zapisu.good() )
                            cout << "Blad pliku klawisze.ini" << endl;

                        for( int i = 0; i < 8; i++ )
                        {
                            plik_zapisu << "#";
                            plik_zapisu << i <<endl;

                            for( int j = 0; j < 4; j++ )
                            {
                                plik_zapisu << klawisze_gracza_kody[ i ][ j ] << endl;
                            }
                        }

                        plik_zapisu.close();
                        ktory_klawisz_najechano = 0;
                        status_gry = USTAWIENIA_GRACZY;
                    }
                    else if( ktory_klawisz_najechano <= 3 )
                    {
                        cout << "Wcisnieto " << ktory_klawisz_najechano << endl;
                        czy_zmiana_sterowania = true;
                    }
                }
                else if( zdarzenie.type == sf::Event::KeyPressed && czy_zmiana_sterowania == true )
                {
                    klawisze_gracza_kody_char[ ktore_najechano_ustawienia_graczy ][ ktory_klawisz_najechano ] = zdarzenie.key.code;
                    klawisze_gracza_kody[ ktore_najechano_ustawienia_graczy ][ ktory_klawisz_najechano ] = zdarzenie.key.code;
                    czy_zmiana_sterowania = false;
                }
            }

            if( status_gry == GRA )
            {
                for( int i = 0; i < liczba_graczy; i++ )
                {
                    for( int j = 0; j < 4; j++ )
                    {
                        if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == klawisze_gracza_kody_char[ i ][ j ] )
                        {
                            kierunek[ i ] = j + 1;
                            /*switch( j )
                            {
                            case 1:
                                break;
                            case 2:
                                break;
                            case 3:
                                break;
                            case 4:
                                break;
                            }*/
                        }
                    }

                }
            }

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                okno.close();
            if( zdarzenie.type == sf::Event::Closed )
                okno.close();
        }

        okno.clear( sf::Color( 28, 217, 70 ) );


        if( status_gry == MENU || status_gry == USTAWIENIA || status_gry == AUTOR || status_gry == USTAWIENIA_GRACZY || status_gry == ZMIANA_STEROWANIA )
        {
            if( pozycja_jedzenia.x < waz_menu[ 0 ].getPosition().x )
                kierunek_weza_menu = 2;
            else if( pozycja_jedzenia.x > waz_menu[ 0 ].getPosition().x )
                kierunek_weza_menu = 4;
            else if( pozycja_jedzenia.y < waz_menu[ 0 ].getPosition().y )
                kierunek_weza_menu = 1;
            else if( pozycja_jedzenia.y > waz_menu[ 0 ].getPosition().y )
                kierunek_weza_menu = 3;

            if( losuj == true )
            {
                for( ;; )
                {
                    pozycja_jedzenia.x = rand() % 24 + 1;
                    pozycja_jedzenia.y = rand() % 13 + 1;

                    pozycja_jedzenia.x *= 50;
                    pozycja_jedzenia.y *= 50;

                    for( int i = 0; i < dlugosc_weza_menu; i++ )
                    {
                        if( pozycja_jedzenia == waz_menu[ i ].getPosition() )
                            kolizja_jedzenia = true;
                    }
                    if( kolizja_jedzenia == true )
                    {
                        kolizja_jedzenia = false;
                        continue;
                    }
                    else
                    {
                        kolizja_jedzenia = false;
                        break;
                    }
                }
                losuj = false;
            }

            jedzenie.setPosition( pozycja_jedzenia );
            okno.draw( jedzenie );

            if( zegar.getElapsedTime().asSeconds() >= 0.1 )
            {
                for( int i = 0; i < dlugosc_weza_menu; i++ )
                {
                    if( i == 0 )
                    {
                        waz_menu[ i ].przeusn( kierunek_weza_menu, 50 );
                    }
                    else
                    {
                        waz_menu[ i ].setPosition( waz_menu[ i - 1 ].getStaraPozycja() );
                    }
                }
                zegar.restart();
            }

            for( int i = 0; i < dlugosc_weza_menu; i++ )
            {
                for( int j = 0; j < dlugosc_weza_menu; j++ )
                {
                    if( waz_menu[ i ].getPosition() == waz_menu[ j ].getPosition() && i != j )
                    {
                        dlugosc_weza_menu = 3;
                        waz_menu.resize( 3 );
                        losuj = true;
                        waz_menu[ 0 ].setPosition( 200, 200 );
                        waz_menu[ 1 ].setPosition( 150, 200 );
                        waz_menu[ 2 ].setPosition( 100, 200 );
                    }
                }
            }

            if( waz_menu[ 0 ].getPosition().x < 0 || waz_menu[ 0 ].getPosition().x > 1280 || waz_menu[ 0 ].getPosition().y < 0 || waz_menu[ 0 ].getPosition().y > 700 )
                    okno.close();

            for( int i = 0; i < dlugosc_weza_menu; i++ )
            {
                if( waz_menu[ i ].getPosition() == pozycja_jedzenia )
                {
                    losuj = true;
                    dlugosc_weza_menu++;
                    waz_menu.push_back( waz_przykladowy );
                    //waz_menu[ dlugosc_weza_menu - 1 ].setPosition( -100, -100 );
                }
            }

            for( int i = 0; i < dlugosc_weza_menu; i++ )
            {
                waz_menu[ i ].rysuj( okno );
            }

           ss.str( "" );
           ss << dlugosc_weza_menu - 3;

           wynik.setFont( czcionka );
           wynik.setColor( sf::Color::Red );
           wynik.setCharacterSize( 20 );
           wynik.setPosition( 10, 10 );
           wynik.setString( ss.str() );
           okno.draw( wynik );
        }

        if( status_gry == MENU )
        {
           if( ktore_najechano > 3 )
            ktore_najechano = 3;
           if( ktore_najechano < 0 )
            ktore_najechano = 0;

           wynik.setString( "Snake" );
           wynik.setFont( czcionka );
           wynik.setColor( sf::Color::Blue );
           wynik.setCharacterSize( 150 );
           wynik.setPosition( 400, 10 );
           okno.draw( wynik );

           wynik.setString( "Start" );
           wynik.setFont( czcionka );
           if( ktore_najechano == 0 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 500, 300 );
           okno.draw( wynik );

           wynik.setString( "Ustawienia" );
           wynik.setFont( czcionka );
           if( ktore_najechano == 1 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 500, 400 );
           okno.draw( wynik );

           wynik.setString( "Autor" );
           wynik.setFont( czcionka );
           if( ktore_najechano == 2 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 500, 500 );
           okno.draw( wynik );

           wynik.setString( "Wyjscie" );
           wynik.setFont( czcionka );
           if( ktore_najechano == 3 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 500, 600 );
           okno.draw( wynik );

        }

        if( status_gry == USTAWIENIA )
        {
            if( ktore_najechano_ustawienia < 0 )
                ktore_najechano_ustawienia = 0;
            if( ktore_najechano_ustawienia > 5 )
                ktore_najechano_ustawienia = 5;

            //ss.str( "" );
           //ss << dlugosc_weza_menu - 3;

           if( ktore_najechano_ustawienia < 0 )
                ktore_najechano_ustawienia = 0;
           //if( ktore_najechano_ustawienia > )
                //ktore_najechano_ustawienia =


            wynik.setString( "Liczba graczy: " );
           wynik.setFont( czcionka );
           if( ktore_najechano_ustawienia == 0 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 50, 50 );
           okno.draw( wynik );

            ss.str( "" );
            ss << liczba_graczy;

            wynik.setString( ss.str() );
           wynik.setFont( czcionka );
           if( ktore_najechano_ustawienia == 0 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 400, 50 );
           okno.draw( wynik );

           wynik.setString( "Ustawienia graczy" );
           wynik.setFont( czcionka );
           if( ktore_najechano_ustawienia == 1 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 50, 150 );
           okno.draw( wynik );


           wynik.setString( "Rozmiar graczy (px): " );
           wynik.setFont( czcionka );
           if( ktore_najechano_ustawienia == 2 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 50, 250 );
           okno.draw( wynik );


            ss.str( "" );
            ss << rozmiar_graczy;

            wynik.setString( ss.str() );
           wynik.setFont( czcionka );
           if( ktore_najechano_ustawienia == 2 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 550, 250 );
           okno.draw( wynik );


           wynik.setString( "Przenikanie przez sciany: " );
           wynik.setFont( czcionka );
           if( ktore_najechano_ustawienia == 3 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 50, 350 );
           okno.draw( wynik );


            if( przenikanie_sciany == true )
                wynik.setString( "Tak" );
            else
                wynik.setString( "Nie" );
           wynik.setFont( czcionka );
           if( ktore_najechano_ustawienia == 3 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 650, 350 );
           okno.draw( wynik );


           wynik.setString( "Przenikanie przez przeciwnikow: " );
           wynik.setFont( czcionka );
           if( ktore_najechano_ustawienia == 4 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 50, 450 );
           okno.draw( wynik );


            if( przenikanie_weze == true )
                wynik.setString( "Tak" );
            else
                wynik.setString( "Nie" );
           wynik.setFont( czcionka );
           if( ktore_najechano_ustawienia == 4 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 800, 450 );
           okno.draw( wynik );


           wynik.setString( "Powrot" );
           wynik.setFont( czcionka );
           if( ktore_najechano_ustawienia == 5 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 50, 550 );
           okno.draw( wynik );
        }

        if( status_gry == USTAWIENIA_GRACZY )
        {
            if( ktore_najechano_ustawienia_graczy < 0 )
            {
                ktore_najechano_ustawienia_graczy = 0;
                ktore_najechano_ustawienia_graczy_2 = 0;
            }
            if( ktore_najechano_ustawienia_graczy > liczba_graczy )
            {
                ktore_najechano_ustawienia_graczy = liczba_graczy;
                ktore_najechano_ustawienia_graczy_2 = 1;
            }



            for( int i = 0; i < liczba_graczy; i++ )
            {

                if( ktore_najechano_ustawienia_graczy <= 3 )
                {
                    ss.str( "" );
                    ss << "Gracz ";
                    ss << i+1;
                    wynik.setString( ss.str() );
                   wynik.setFont( czcionka );
                   wynik.setColor( sf::Color::Black );
                   wynik.setCharacterSize( 30 );
                   wynik.setPosition( 50, 30 + i * 150 );
                   okno.draw( wynik );



                    wynik.setString( "Kolor ( RGB ): " );
                   wynik.setFont( czcionka );
                   if( ktore_najechano_ustawienia_graczy == i && ktore_najechano_ustawienia_graczy_2 == 0 && ktory_kolor_najechano == 0 )
                        wynik.setColor( sf::Color::White );
                    else
                        wynik.setColor( sf::Color::Black );
                   wynik.setCharacterSize( 30 );
                   wynik.setPosition( 50, 60 + i * 150 );
                   okno.draw( wynik );

                   ss.str( "" );
                   jakis_kolor = kolor_gracza[ i ].r;
                    ss << jakis_kolor;
                    wynik.setString( ss.str() );
                   wynik.setFont( czcionka );
                   if( ktore_najechano_ustawienia_graczy == i && ktore_najechano_ustawienia_graczy_2 == 0 && ktory_kolor_najechano == 1 )
                        wynik.setColor( sf::Color::White );
                    else
                        wynik.setColor( sf::Color::Black );
                   wynik.setCharacterSize( 30 );
                   wynik.setPosition( 400, 60 + i * 150 );
                   okno.draw( wynik );

                   ss.str( "" );
                   jakis_kolor = kolor_gracza[ i ].g;
                    ss << jakis_kolor;
                    wynik.setString( ss.str() );
                   wynik.setFont( czcionka );
                   if( ktore_najechano_ustawienia_graczy == i && ktore_najechano_ustawienia_graczy_2 == 0 && ktory_kolor_najechano == 2 )
                        wynik.setColor( sf::Color::White );
                    else
                        wynik.setColor( sf::Color::Black );
                   wynik.setCharacterSize( 30 );
                   wynik.setPosition( 500, 60 + i * 150 );
                   okno.draw( wynik );

                   ss.str( "" );
                   jakis_kolor = kolor_gracza[ i ].b;
                    ss << jakis_kolor;
                    wynik.setString( ss.str() );
                   wynik.setFont( czcionka );
                   if( ktore_najechano_ustawienia_graczy == i && ktore_najechano_ustawienia_graczy_2 == 0 && ktory_kolor_najechano == 3 )
                        wynik.setColor( sf::Color::White );
                    else
                        wynik.setColor( sf::Color::Black );
                   wynik.setCharacterSize( 30 );
                   wynik.setPosition( 600, 60 + i * 150 );
                   okno.draw( wynik );

                    przyklad_koloru[ i ].setFillColor( kolor_gracza[ i ] );
                   przyklad_koloru[ i ].setPosition( 700, 60 + i * 150 );
                   okno.draw( przyklad_koloru[ i ] );




                   wynik.setString( "Zmien sterowanie" );
                   wynik.setFont( czcionka );
                   if( ktore_najechano_ustawienia_graczy == i && ktore_najechano_ustawienia_graczy_2 == 1 )
                        wynik.setColor( sf::Color::White );
                    else
                        wynik.setColor( sf::Color::Black );
                   wynik.setCharacterSize( 30 );
                   wynik.setPosition( 50, 90 + i * 150 );
                   okno.draw( wynik );
                }

                if( ktore_najechano_ustawienia_graczy >= 4 )
                {
                    ss.str( "" );
                    ss << "Gracz ";
                    ss << i+1;
                    wynik.setString( ss.str() );
                   wynik.setFont( czcionka );
                   wynik.setColor( sf::Color::Black );
                   wynik.setCharacterSize( 30 );
                   wynik.setPosition( 50, 30 + ( i - 4 ) * 150 );
                   okno.draw( wynik );



                    wynik.setString( "Kolor ( RGB ): " );
                   wynik.setFont( czcionka );
                   if( ktore_najechano_ustawienia_graczy == i && ktore_najechano_ustawienia_graczy_2 == 0 && ktory_kolor_najechano == 0 )
                        wynik.setColor( sf::Color::White );
                    else
                        wynik.setColor( sf::Color::Black );
                   wynik.setCharacterSize( 30 );
                   wynik.setPosition( 50, 60 + ( i - 4 ) * 150 );
                   okno.draw( wynik );

                   ss.str( "" );
                   jakis_kolor = kolor_gracza[ i ].r;
                    ss << jakis_kolor;
                    wynik.setString( ss.str() );
                   wynik.setFont( czcionka );
                   if( ktore_najechano_ustawienia_graczy == i && ktore_najechano_ustawienia_graczy_2 == 0 && ktory_kolor_najechano == 1 )
                        wynik.setColor( sf::Color::White );
                    else
                        wynik.setColor( sf::Color::Black );
                   wynik.setCharacterSize( 30 );
                   wynik.setPosition( 400, 60 + ( i - 4 ) * 150 );
                   okno.draw( wynik );

                   ss.str( "" );
                   jakis_kolor = kolor_gracza[ i ].g;
                    ss << jakis_kolor;
                    wynik.setString( ss.str() );
                   wynik.setFont( czcionka );
                   if( ktore_najechano_ustawienia_graczy == i && ktore_najechano_ustawienia_graczy_2 == 0 && ktory_kolor_najechano == 2 )
                        wynik.setColor( sf::Color::White );
                    else
                        wynik.setColor( sf::Color::Black );
                   wynik.setCharacterSize( 30 );
                   wynik.setPosition( 500, 60 + ( i - 4 ) * 150 );
                   okno.draw( wynik );

                   ss.str( "" );
                   jakis_kolor = kolor_gracza[ i ].b;
                    ss << jakis_kolor;
                    wynik.setString( ss.str() );
                   wynik.setFont( czcionka );
                   if( ktore_najechano_ustawienia_graczy == i && ktore_najechano_ustawienia_graczy_2 == 0 && ktory_kolor_najechano == 3 )
                        wynik.setColor( sf::Color::White );
                    else
                        wynik.setColor( sf::Color::Black );
                   wynik.setCharacterSize( 30 );
                   wynik.setPosition( 600, 60 + ( i - 4 ) * 150 );
                   okno.draw( wynik );

                    przyklad_koloru[ i ].setFillColor( kolor_gracza[ i ] );
                   przyklad_koloru[ i ].setPosition( 700, 60 + ( i - 4 ) * 150 );
                   okno.draw( przyklad_koloru[ i ] );




                   wynik.setString( "Zmien sterowanie" );
                   wynik.setFont( czcionka );
                   if( ktore_najechano_ustawienia_graczy == i && ktore_najechano_ustawienia_graczy_2 == 1 )
                        wynik.setColor( sf::Color::White );
                    else
                        wynik.setColor( sf::Color::Black );
                   wynik.setCharacterSize( 30 );
                   wynik.setPosition( 50, 90 + ( i - 4 ) * 150 );
                   okno.draw( wynik );
                }

            }

            wynik.setString( "Powrot" );
           wynik.setFont( czcionka );
           if( ktore_najechano_ustawienia_graczy == liczba_graczy )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 30 );
           wynik.setPosition( 50,wynik.getPosition().y + 100 );
           okno.draw( wynik );

        }

        if( status_gry == ZMIANA_STEROWANIA )
        {
            ss.str( "" );
            ss << "Gracz: ";
            ss << ktore_najechano_ustawienia_graczy + 1;

            wynik.setString( ss.str() );
           wynik.setFont( czcionka );
            wynik.setColor( sf::Color::Black );
            wynik.setCharacterSize( 50 );
           wynik.setPosition( 50, 100 );
           okno.draw( wynik );

           wynik.setString( "Gora: " );
           wynik.setFont( czcionka );
           if( ktory_klawisz_najechano == 0 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 50, 150 );
           okno.draw( wynik );

           ss.str( "" );
            ss << nazwa_klawisza( klawisze_gracza_kody[ ktore_najechano_ustawienia_graczy ][ 0 ] );

            wynik.setString( ss.str() );
           wynik.setFont( czcionka );
            if( ktory_klawisz_najechano == 0 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
            wynik.setCharacterSize( 50 );
           wynik.setPosition( 250, 150 );
           okno.draw( wynik );

           wynik.setString( "Lewo: " );
           wynik.setFont( czcionka );
           if( ktory_klawisz_najechano == 1 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 50, 200 );
           okno.draw( wynik );

           ss.str( "" );
            ss << nazwa_klawisza( klawisze_gracza_kody[ ktore_najechano_ustawienia_graczy ][ 1 ] );

            wynik.setString( ss.str() );
           wynik.setFont( czcionka );
           if( ktory_klawisz_najechano == 1 )
                wynik.setColor( sf::Color::White );
           else
            wynik.setColor( sf::Color::Black );
            wynik.setCharacterSize( 50 );
           wynik.setPosition( 250, 200 );
           okno.draw( wynik );

           wynik.setString( "Dol: " );
           wynik.setFont( czcionka );
           if( ktory_klawisz_najechano == 2 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 50, 250 );
           okno.draw( wynik );

           ss.str( "" );
            ss << nazwa_klawisza( klawisze_gracza_kody[ ktore_najechano_ustawienia_graczy ][ 2 ] );

            wynik.setString( ss.str() );
           wynik.setFont( czcionka );
            if( ktory_klawisz_najechano == 2 )
                wynik.setColor( sf::Color::White );
           else
            wynik.setColor( sf::Color::Black );
            wynik.setCharacterSize( 50 );
           wynik.setPosition( 250, 250 );
           okno.draw( wynik );

           wynik.setString( "Prawo: " );
           wynik.setFont( czcionka );
           if( ktory_klawisz_najechano == 3 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 50, 300 );
           okno.draw( wynik );

           ss.str( "" );
            ss << nazwa_klawisza( klawisze_gracza_kody[ ktore_najechano_ustawienia_graczy ][ 3 ] );

            wynik.setString( ss.str() );
           wynik.setFont( czcionka );
            if( ktory_klawisz_najechano == 3 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
            wynik.setCharacterSize( 50 );
           wynik.setPosition( 250, 300 );
           okno.draw( wynik );


           wynik.setString( "Powrot" );
           wynik.setFont( czcionka );
           if( ktory_klawisz_najechano == 4 )
                wynik.setColor( sf::Color::White );
            else
                wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 50 );
           wynik.setPosition( 50, 350 );
           okno.draw( wynik );

           if( czy_zmiana_sterowania == true )
           {
               wynik.setString( "Nacisnij klawisz \nktory chesz przypisac" );
               wynik.setFont( czcionka );
                wynik.setColor( sf::Color::Black );
               wynik.setCharacterSize( 50 );
               wynik.setPosition( 600, 200 );
               okno.draw( wynik );
           }


        }

        if( status_gry == WYJSCIE )
        {
            okno.close();
        }

        if( status_gry == GRA )
        {
            if( losuj == true )
            {
                for( ;; )
                {
                    pozycja_jedzenia.x = rand() % ( 1280 / rozmiar_graczy ) - 1  + 1;
                    pozycja_jedzenia.y = rand() % ( 720 / rozmiar_graczy ) - 1 + 1;

                    cout << pozycja_jedzenia.x << " " << pozycja_jedzenia.y << endl;

                    pozycja_jedzenia.x *= rozmiar_graczy;
                    pozycja_jedzenia.y *= rozmiar_graczy;

                    /*for( int i = 0; i < dlugosc_weza; i++ )
                    {
                        if( pozycja_jedzenia == waz[ i ].getPosition() )
                            kolizja_jedzenia = true;
                    }
                    for( int i = 0; i < dlugosc_weza_2; i++ )
                    {
                        if( pozycja_jedzenia == waz_2[ i ].getPosition() )
                            kolizja_jedzenia = true;
                    }*/

                    for( int i = 0; i < liczba_graczy; i++ )
                    {
                        for( int j = 0; j < dlugosc_weza[ i ]; j++ )
                        {
                            if( pozycja_jedzenia == waz[ i ][ j ].getPosition() )
                                kolizja_jedzenia = true;
                        }
                    }

                    if( kolizja_jedzenia == true )
                    {
                        kolizja_jedzenia = false;
                        continue;
                    }
                    else
                    {
                        kolizja_jedzenia = false;
                        break;
                    }
                }
                losuj = false;
            }

            //cout << rozmiar_graczy << " " << jedzenie.getSize().x << endl;

            jedzenie.setPosition( pozycja_jedzenia );
            okno.draw( jedzenie );

            if( zegar.getElapsedTime().asSeconds() >= 0.1 )
            {
                /*for( int i = 0; i < dlugosc_weza; i++ )
                {
                    if( i == 0 )
                    {
                        waz[ i ].przeusn( kierunek );
                    }
                    else
                    {
                        waz[ i ].setPosition( waz[ i - 1 ].getStaraPozycja() );
                    }
                }

                for( int i = 0; i < dlugosc_weza_2; i++ )
                {
                    if( i == 0 )
                    {
                        waz_2[ i ].przeusn( kierunek_2 );
                    }
                    else
                    {
                        waz_2[ i ].setPosition( waz_2[ i - 1 ].getStaraPozycja() );
                    }
                }*/

                for( int i = 0; i < liczba_graczy; i++ )
                {
                    for( int j = 0; j < dlugosc_weza[ i ]; j++ )
                    {
                        if( j == 0 )
                        {
                            waz[ i ][ j ].przeusn( kierunek[ i ], rozmiar_graczy );
                        }
                        else
                        {
                            waz[ i ][ j ].setPosition( waz[ i ][ j - 1 ].getStaraPozycja() );
                        }
                    }
                }

                if( przenikanie_weze == false )
                {
                    for( int i = 0; i < liczba_graczy; i++ )
                   {
                       for( int j = 0; j < dlugosc_weza[ i ]; j++ )
                       {
                           for( int o = 0; o < dlugosc_weza[ i ]; o++ )
                           {
                               if( waz[ i ][ j ].getPosition() == waz[ i ][ o ].getPosition() && j != o )
                               {
                                   //cout << i << "\t" <<  waz[ i ][ j ].getPosition().x << " " << waz[ i ][ j ].getPosition().y << "\t" <<  waz[ i ][ o ].getPosition().x << " " <<  waz[ i ][ o ].getPosition().y<< endl;
                                   okno.close();
                               }
                           }
                       }
                   }

                   for( int i = 0; i < liczba_graczy; i++ )
                   {
                       for( int j = 0; j < liczba_graczy; j++ )
                       {
                           for( int o = 0; o < dlugosc_weza[ i ]; o++ )
                           {
                               for( int p = 0; p < dlugosc_weza[ j ]; p++ )
                               {
                                    if( waz[ i ][ o ].getPosition() == waz[ j ][ p ].getPosition() && i != j )
                                   {
                                       //cout << i << "\t" <<  waz[ i ][ j ].getPosition().x << " " << waz[ i ][ j ].getPosition().y << "\t" <<  waz[ i ][ o ].getPosition().x << " " <<  waz[ i ][ o ].getPosition().y<< endl;
                                       okno.close();
                                   }
                               }
                           }
                       }
                   }
                }

                if( przenikanie_sciany == false )
                {
                    for( int i = 0; i < liczba_graczy; i++ )
                    {
                        if( waz[ i ][ 0 ].getPosition().x < 0 || waz[ i ][ 0 ].getPosition().x > 1280 || waz[ i ][ 0 ].getPosition().y < 0 || waz[ i ][ 0 ].getPosition().y > 700 )
                            okno.close();
                    }
                }

                for( int i = 0; i < liczba_graczy; i++ )
                {
                    if( waz[ i ][ 0 ].getPosition() == pozycja_jedzenia )
                    {
                        waz_przykladowy.ustaw_kolor( kolor_gracza[ i ] );
                        waz_przykladowy.setPosition( -100, -100 );
                        waz_przykladowy.ustaw_rozmiar( rozmiar_graczy );
                        waz[ i ].push_back( waz_przykladowy );
                        losuj = true;
                        dlugosc_weza[ i ]++;
                    }
                }

                zegar.restart();
            }

            /*for( int i = 0; i < dlugosc_weza; i++ )
            {
                for( int j = 0; j < dlugosc_weza; j++ )
                {
                    if( waz[ i ].getPosition() == waz[ j ].getPosition() && i != j )
                        okno.close();
                }
            }

            for( int i = 0; i < dlugosc_weza_2; i++ )
            {
                for( int j = 0; j < dlugosc_weza_2; j++ )
                {
                    if( waz_2[ i ].getPosition() == waz_2[ j ].getPosition() && i != j )
                        okno.close();
                }
            }

            for( int i = 0; i < dlugosc_weza; i++ )
            {
                for( int j = 0; j < dlugosc_weza_2; j++ )
                {
                    if( waz[ i ].getPosition() == waz_2[ j ].getPosition() )
                        okno.close();
                }
            }

            if( waz[ 0 ].getPosition().x < 0 || waz[ 0 ].getPosition().x > 1280 || waz[ 0 ].getPosition().y < 0 || waz[ 0 ].getPosition().y > 700 )
                    okno.close();
            if( waz_2[ 0 ].getPosition().x < 0 || waz_2[ 0 ].getPosition().x > 1280 || waz_2[ 0 ].getPosition().y < 0 || waz_2[ 0 ].getPosition().y > 700 )
                    okno.close();

            for( int i = 0; i < dlugosc_weza; i++ )
            {
                if( waz[ i ].getPosition() == pozycja_jedzenia )
                {
                    losuj = true;
                    dlugosc_weza++;
                    waz[ dlugosc_weza - 1 ].setPosition( -100, -100 );
                }
            }

            for( int i = 0; i < dlugosc_weza_2; i++ )
            {
                if( waz_2[ i ].getPosition() == pozycja_jedzenia )
                {
                    losuj = true;
                    dlugosc_weza_2++;
                    waz_2[ dlugosc_weza_2 - 1 ].setPosition( -200, -200 );
                }
            }

           for( int i = 0; i < dlugosc_weza; i++ )
           {
               waz[ i ].rysuj( okno );
           }
           for( int i = 0; i < dlugosc_weza_2; i++ )
           {
               waz_2[ i ].rysuj( okno );
           }*/

            for( int i = 0; i < liczba_graczy; i++ )
            {
                for( int j = 0; j < dlugosc_weza[ i ]; j++ )
                {
                    waz[ i ][ j ].rysuj( okno );
                }
            }


           /*ss.str( "" );
           ss << dlugosc_weza - 3;

           wynik.setFont( czcionka );
           wynik.setColor( sf::Color::Black );
           wynik.setCharacterSize( 20 );
           wynik.setPosition( 10, 10 );
           wynik.setString( ss.str() );
           okno.draw( wynik );

            ss.str( "" );
            ss << dlugosc_weza_2 - 3;

            wynik.setFont( czcionka );
            wynik.setColor( sf::Color::Black );
            wynik.setCharacterSize( 20 );
            wynik.setPosition( 1260, 10 );
            wynik.setString( ss.str() );
            okno.draw( wynik );*/

            for( int i = 0; i < liczba_graczy; i++ )
            {
                ss.str( "" );
               ss << dlugosc_weza[ i ] - 3;

               wynik.setFont( czcionka );
               wynik.setColor( kolor_gracza[ i ] );
               wynik.setCharacterSize( 20 );
               wynik.setPosition( i * 160, 10 );
               wynik.setString( ss.str() );
               okno.draw( wynik );
            }
        }



        okno.display();
    }

    /*for( int i = 0; i < 8; i++ )
    {
        try {
            delete [] waz[ i ];
        }
        catch(int msg) {
            ;
        }
    }

    try {
        delete [
        ] waz;
    }
    catch(string msg) {
    }

    waz = NULL; */

    return 0;
}
