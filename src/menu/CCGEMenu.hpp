#include <iostream>
#include <cstring>
#include <fstream>

#include "../private/HKeyboard.hpp"




// Константы
static const int C_ROWS = 10;
static const int C_COLUMNS = 30;




static std::string g_menu_lines[ 10 ] = { "Root:\\" };




int f_SumArray( int num, int lay, int( &mas )[ C_ROWS ][ C_COLUMNS ] ) {
    auto sum = 0;
    for ( int counter = 0; counter < num - 1; counter++ ) {
        sum += mas[ lay ][ counter ];
    }

    return sum;
}



int f_MakeSubmenu(
    int lay
    , int num
    , std::string( &masstr )[ C_ROWS ][ C_COLUMNS ]
    , int sizemas[]
    , int( &numMas )[ C_ROWS ][ C_COLUMNS ] ) {

    // char g;
    while ( true ) {
        bool exitflag = false;
        int counter = 0;
        std::string back = "<-- ... ";
        system( "clear" );
        for ( auto ml: g_menu_lines ) {
            if ( ml != "" ) std::cout << ml << std::endl;
        }


        std::cout << std::endl;
        std::cout << back << std::endl;
        for (
            int i = f_SumArray( num + 1, lay - 1, numMas )
            ; i < f_SumArray( num + 1, lay - 1, numMas ) + numMas[ lay - 1 ][ num ]
            ; i++ ) {
            std::cout << masstr[ lay ][ i ] << std::endl;
        }


        while ( true ) {

            int ascii = getch() + getch();

            if ( static_cast< KEYS >( ascii ) == KEYS::KEY_CONTROL ) {
                switch ( static_cast<KEYS>( getchar() ) ) {
                    case KEYS::KEY_UP:{
                        counter--;
                        if ( counter < 0 ) {
                            counter = 0;
                        }

                        if ( counter == 0 ) {
                            back = "<-- ... ";
                        }

                        system( "clear" );
                        for ( auto ml: g_menu_lines ) {
                            if ( ml != "" ) {
                                std::cout << ml << std::endl;
                            }
                        }

                        std::cout << std::endl;
                        std::cout << back << std::endl;
                        for (
                            int i = f_SumArray( num + 1, lay - 1, numMas )
                            ; i < f_SumArray( num + 1, lay - 1, numMas ) + numMas[ lay - 1 ][ num ]
                            ; i++ ) {
                            if ( counter != 0 && counter - 1 + f_SumArray( num + 1, lay - 1, numMas ) == i ) {
                                std::cout<<"<--";
                                std::cout<< masstr[ lay ][ i ] << std::endl;
                            } else {
                                std::cout << masstr[ lay ][ i ] << std::endl;
                            }
                        }

                        break;
                    }

                    case KEYS::KEY_DOWN:{
                        counter++;
                        if ( counter > numMas[ lay - 1 ][ num ] ) {
                            counter = numMas[ lay - 1 ][ num ];
                        }

                        if ( counter != 0 ) {
                            back = " ... ";
                        }

                        system( "clear" );
                        for ( auto ml: g_menu_lines ) {
                            if ( ml != "" ) std::cout << ml << std::endl;
                        }

                        std::cout << std::endl;
                        std::cout << back << std::endl;
                        for (
                            int i = f_SumArray( num + 1, lay - 1, numMas )
                            ; i < f_SumArray( num + 1, lay - 1, numMas ) + numMas[ lay - 1 ][ num ]
                            ; i++ ) {

                            if ( counter != 0
                                && counter - 1 + f_SumArray( num + 1, lay - 1, numMas ) == i ) {
                                std::cout<<"<--";
                                std::cout<< masstr[ lay ][ i ] << std::endl;
                            } else {
                                std::cout << masstr[ lay ][ i ] << std::endl;
                            }
                        }

                        break;
                    }

                    case KEYS::KEY_LEFT: {
                        exitflag = true;
                        break;
                    }
                }
            }


            if ( exitflag ) {
                break;
            }
        }

        if ( counter == 0 ) {
            g_menu_lines[ lay ] = "";
            break;
        }

        if ( counter != 0 ) {
            g_menu_lines[ lay + 1 ]
                = masstr[ lay ][ counter - 1 + f_SumArray( num + 1, lay - 1, numMas ) ];
            f_MakeSubmenu(
                lay + 1
                , counter - 1 + f_SumArray( num + 1, lay - 1, numMas )
                , masstr
                , sizemas
                , numMas );
        }
    }


    return 0;
}



int f_MakeMenu(
    int lay
    , std::string( &masstr )[ C_ROWS ][ C_COLUMNS ]
    , int sizemas[]
    , int( &numMasref )[ C_ROWS ][ C_COLUMNS ] ) {

    while ( true ) {
        bool exitflag = false;
        int counter = 0;
        std::string back = "<-- ... ";
        system( "clear" );
        std::cout << g_menu_lines[ 0 ] << std::endl;
        std::cout << back << std::endl;
        for ( int i = 0; i < sizemas[ lay ]; i++ ) {
            std::cout << masstr[ lay ][ i ] << std::endl;
        }

        while ( true ) {
            int ascii = getch() + getch();

            if ( static_cast< KEYS >( ascii ) == KEYS::KEY_CONTROL ) {
                switch ( static_cast<KEYS>( getchar() ) ) {
                    case KEYS::KEY_UP:{
                        counter--;
                        if ( counter < 0 ) counter = 0;
                        if ( counter == 0 ) back = "<-- ... ";
                        system( "clear" );
                        std::cout << g_menu_lines[ 0 ] << std::endl;
                        std::cout << back << std::endl;
                        for ( int i = 0; i < sizemas[ lay ]; i++ )
                        {
                            if ( counter != 0 && counter - 1 == i ) {
                                std::cout<<"<--";
                                std::cout<< masstr[ lay ][ i ] << std::endl;
                            } else {
                                std::cout << masstr[ lay ][ i ] << std::endl;
                            }
                        }
                        break;
                    }
                    case KEYS::KEY_DOWN:{
                        counter++;
                        if ( counter > sizemas[ lay ] ) counter = sizemas[ lay ];
                        if ( counter != 0 ) back = " ... ";
                        system( "clear" );
                        std::cout << g_menu_lines[ 0 ] << std::endl;
                        std::cout << back << std::endl;
                        for ( int i = 0; i < sizemas[ lay ]; i++ )
                        {
                            if ( counter != 0 && counter - 1 == i ) {
                                std::cout<<"<--";
                                std::cout<< masstr[ lay ][ i ] << std::endl;
                            }
                            else {
                                std::cout << masstr[ lay ][ i ] << std::endl;
                            }
                        }
                        break;
                    }
                    case KEYS::KEY_LEFT: {
                        exitflag = true;
                        break;
                    }
                }
            }

            if ( exitflag ) {
                break;
            }
        }

        if ( counter == 0 ) {
            break;
        }

        if ( counter != 0 ) {
            g_menu_lines[ 1 ] = masstr[ lay ][ counter - 1 ];
            f_MakeSubmenu( lay + 1, counter - 1, masstr, sizemas, numMasref );
        }
    }


    return 0;
}



int f_Test() {
    setlocale( LC_ALL, "Ru" );
    int y[ C_ROWS ] = {};
    int valmas[ C_ROWS ][ C_COLUMNS ] = {};
    int counter = 0;

    std::ifstream fil;
    std::string str;
    std::string mstr[ C_ROWS ][ C_COLUMNS ];


    // Todo
    fil.open( "../../src/menu/menu_example.txt" );
    while ( true ) {
        getline( fil, str );
        if ( fil.eof() ) {
            break;
        }

        int k = 0, i = 0;
        while ( str[ i ] == ' ' ) {
            k++;
            i++;
        }

        for ( int i = 0; i < C_ROWS; i++ ) {

            // Каждый слой отделяется 3 пробелами от предыдущего
            if ( k == 3*  i ) {
                mstr[ i ][ y[ i ] ] = str.erase( 0, 3*  i );
                if ( i != 0 ) valmas[ i - 1 ][ y[ i - 1 ] - 1 ]++;
                y[ i ]++;
                break;
            }
        }

    }

    fil.close();


    f_MakeMenu( 0, mstr, y, valmas );


    std::cout << "It works correctly!" << std::endl;

    // system( "pause" );
}
