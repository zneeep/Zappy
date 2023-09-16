cmake_minimum_required(VERSION 3.12)
project(zappy_gui)

set(CMAKE_CXX_STANDARD 14)

# Recherche de SFML
# set(SFML_DIR "/chemin/vers/SFML/cmake")  # Remplacez "/chemin/vers/SFML/cmake" par le chemin d'installation de SFML sur votre système

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Inclusion des fichiers source
set(SOURCES
    source/main.cpp

    source/math/Complex3D.cpp
    source/math/Random.cpp

    source/core/Core.cpp
    source/core/parser/Parser.cpp
    source/core/parser/Error.cpp
    source/core/socket/Socket.cpp
    source/core/uielement/UiElements.cpp
    source/core/camera/Camera.cpp

    source/game/Game.cpp
    source/game/team/Team.cpp
    source/game/team/player/Player.cpp
    source/game/map/Map.cpp
    source/game/map/Ressources.cpp
    source/game/map/Tile.cpp
    source/game/Broadcast.cpp

    source/events/events.cpp

    source/routes/SpriteRouteConstants.cpp

    source/renderer/SFML.cpp
)

# Création de l'exécutable
add_executable(zappy_gui ${SOURCES})

# Lier les bibliothèques SFML
target_link_libraries(zappy_gui sfml-graphics sfml-window sfml-system)
