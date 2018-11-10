#include <SFML/Graphics.hpp>
#include "textures.hpp"

using namespace All;

Textures::Textures( ) {
  Background_Castle_1.loadFromFile( "res/background/castle_1.png" );
  Player_Dragon_1.loadFromFile( "res/player/dragon_1.png" );
  Player_Skeleton_1.loadFromFile( "res/player/skeleton_1.png" );
  Player_Skeleton_2.loadFromFile( "res/player/skeleton_2.png" );
  Player_Armsheet.loadFromFile( "res/player/armsheet.png" );
  Player_Bodysheet.loadFromFile( "res/player/bodysheet.png" );
  Player_Headsheet.loadFromFile( "res/player/headsheet.png" );
  Player_Legsheet.loadFromFile( "res/player/legsheet.png" );
}