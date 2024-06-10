#include <iostream>
//#include <unistd.h>
#include "Planeta.h"
#include "Robot.h"
#include "Alienigena.h"
#include "Piloto.h"
#include "Sephiroth.h"
#include "Enigma.h"

int main() {
    int jugar, eleccion_batalla, ver_planeta, ver_personajes_p, ver_personaje, ver_hist_juego;
    int edad_robot, edad_alien, edad_piloto, edad_sephiroth;
    std::string nombre_robot, nombre_piloto, nombre_alien, nombre_sephiroth, nombre_planeta;
    std::string habilidad_robot, habilidad_alien;
    std::string vehiculo_piloto;
    std::string puesto;
    std::string personaje1;
    std::string personaje2;
    Robot* robot1 = new Robot();
    Alienigena* alien = new Alienigena() ;
    Piloto* poe = new Piloto();
    Sephiroth* sephiroth = new Sephiroth();
    Enigma enig("Enigma del fuego", "Soy mas ligero que el aire, pero cientos de personas no pueden levantarme. Que soy?", "burbuja");

    while (true){
        std::cout << "Este juego es totalmente ficticio, esta bajo tu responsabilidad si lo juegas o no.";
        std::cout << "\nIngresa 0 si no quieres jugar\nIngresa 1 si quieres jugar" << std::endl;
        std::cin >> jugar;
        if (jugar == 0) {
            std::cout << "Saliendo del juego..." << std::endl;
            break;
        } else if (jugar == 1) {
            std::cin.ignore(); // Ignora el salto de línea después de la lectura de jugar
            //poner la historia del juego de rol 
            std::cout << "Debemos de crear los personajes a usar." << std::endl;
            std::cout << "Nuestro primer personaje es un robot. Dime cual es su nombre: ";
            std::getline(std::cin, nombre_robot);
            robot1->setNombre(nombre_robot);

            std::cout << "Nuestro segundo personaje es un alienigena. Dime cual es su nombre: ";
            std::getline(std::cin, nombre_alien);
            alien -> setNombre(nombre_alien);

            std::cout << "Nuestro tercer personaje es un piloto. Dime cual es su nombre: ";
            std::getline(std::cin, nombre_piloto);
            poe -> setNombre(nombre_piloto);

            std::cout << "Nuestro cuarto personaje es un villano. Dime cual es su nombre: ";
            std::getline(std::cin, nombre_sephiroth);
            sephiroth -> setNombre(nombre_sephiroth);

            std::cout << "Dame el nombre del planeta: " << std::endl;
            std::getline(std::cin, nombre_planeta);
            Planeta aura(nombre_planeta," Fue descubierto por exploradores humanos en el año 2300 durante una misión de búsqueda de planetas habitables. Los habitantes recibieron a los humanos con curiosidad y hospitalidad, compartiendo conocimientos y tecnología. Los dos pueblos han coexistido en paz, intercambiando cultura y explorando juntos los secretos del vasto universo.", robot1, alien, poe, sephiroth, enig);
            aura.agregarPersonaje(0, robot1);
            aura.agregarPersonaje(1, alien);
            aura.agregarPersonaje(2, poe);
            aura.agregarPersonaje(3, sephiroth);

            std::cout << "Te gustaria ver las caracteristicas de tu planeta?\nIngresa 1 para verlos. " << std::endl;
            std::cin >> ver_planeta;
            
            if (ver_planeta == 1) {
                aura.mostrarEstado();
            } else {
                std::cout << "De acuerdo, proseguimos.\n\n " << std::endl;
            }

            std::cout << "------------------------------------------------------------------------------------" << std::endl;
            std::cout << "Te gustaria ver los personajes que creaste y sus atributos? :\nIngresa 1 para verlos" << std::endl;
            std::cin >> ver_personajes_p ;

            if (ver_personajes_p == 1) {
                std::cout << "Te gustaria ver la informacion de algun personaje en especifico? " << std::endl;
                std::cout << "\n- Ingresa 0 para ver la informacion de todos." << std::endl;
                std::cout << "\n- Ingresa 1 para ver la informacion de " << robot1->getNom() << "." << std::endl;
                std::cout << "\n- Ingresa 2 para ver la informacion de " << alien->getNom() << "." << std::endl;
                std::cout << "\nIngresa 3 para ver la informacion de " << poe->getNom() << "." << std::endl;
                std::cout << "\n- Ingresa 4 para ver la informacion de " << sephiroth->getNom() << "." << std::endl;
                std::cin >> ver_personaje;
                if(ver_personaje == 0){
                    std::cout << "\n";
                    aura.imprimirPersonajes();
                } else if(ver_personaje == 1){
                    robot1->imprimir_personaje();
                } else if(ver_personaje == 2){
                    alien->imprimir_personaje();
                } else if(ver_personaje == 3){
                    poe->imprimir_personaje();
                } else if(ver_personaje == 4){
                    sephiroth->imprimir_personaje();
                } else{
                    std::cout << "De acuerdo, proseguiremos con el juego." << std::endl;
                }
            }
            
            std::cout << "Te gustaria ver la historia del juego??\nIngresa 1 para verla :) = ";
            std::cin >> ver_hist_juego;
            if (ver_hist_juego == 1){
                //Historia del juego
                std::cout << "----------------------------------------------------------------------------------------------- " << std::endl;
                std::cout << "En el planeta " << aura.getNombre() << ", una antigua profecia ha comenzado a manifestarse. " << std::endl;
                std::cout << "El equilibrio natural que ha sostenido la vida en este mundo esta en peligro, y un grupo de valientes\n"; 
                std::cout << "heroes deben embarcarse en una epica aventura para salvar su hogar." << std::endl;
                std::cout << "Entre ellos, se encuentran un humano piloto cuyo nombre es " << poe->getNom() << ". " ;
                std::cout << "El segundo personaje en aparecer es un robot cuyo nombre es " << robot1->getNom() << ".\nDespues esta " << alien->getNom();
                std::cout << " el cual es un alienigena, todos estos personajes estan dispuestos a combatir las amenazas,\ndescubriendo secretos, "; 
                std::cout << " todo esto por un destino en comun..." << std::endl;
                std::cout << "SALVAR SU PLANETA\n\n" << std::endl;

                std::cout << "En este planeta, " << aura.getNombre() << ", un lugar de belleza incomparable y misterios antiguos, se ha desatado ";
                std::cout << "una fuerza maligna que amenaza con destruir todo lo que conocen sus habitantes.\nLa profecia ancestral habla de un ser ";
                std::cout << "llamado " << sephiroth->getNom() << ", un poderoso villano que ha despertado de su largo suenio y buscar dominar el planeta." << std::endl;
                std::cout << "Los valientes heroes se enfrentan sin precedentes.\n" << std::endl;

                std::cout << poe->getNom() << ", un intrepido piloto humano que ha surcado los cielos de " << aura.getNombre() << " y conoce sus secretos ";
                std::cout << "mejor que nadie.\n" << robot1->getNom() << ", un robot de ultima generacion con habilidad de combate y estrategia ";
                std::cout << "excepcionales.\n" << alien->getNom() << ", un misterioso alienigena con poderes cosmicos y una conexion profunda con los ";
                std::cout << "misterios de universo.\n\nEstos cuatro heroes, junto con otros aliados que se uniran en el camino, deben descubrir los secretos";
                std::cout << " antiguos de " << aura.getNombre() << ",\nreunir artefactos poderosos y fortalecer sus habilidades para enfrentar a " << sephiroth->getNom();
                std::cout << " y su ejercito de criaturas oscuras.\n" << std::endl;
                std::cout << "La batalla final la jugaras para poder derrotar a nuestro villano, deberas de ser sabio y derrotar a " << sephiroth->getNom() << std::endl;  
            } else {
                std::cout << "De acuerdo, contuniaremos..." << std::endl;
            }

            std::cout << "------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "\n\nExplicacion del juego: " << std::endl;
            std::cout << "El juego consiste en utilizar a tus personajes que acabas de crear para atacar a " << sephiroth->getNom() << " ." << std::endl;
            std::cout << "La rutina es utilizar las acciones que te indica que le pertenece a cada personaje y asi atacar" << std::endl;
            std::cout << "Despues de atacar tendras que adivinar el enigma, si logras adivinarlo, el combate se acaba " << std::endl;
            std::cout << "sino seguiras hasta adivinar el enigma o que tu salud se acabe." << std::endl;
            std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
            
            aura.simularCombate(robot1, alien,poe, sephiroth, enig);

            break;
            delete robot1; // Libera la memoria después de usar el objeto
            delete alien; // Libera la memoria después de usar el objeto
            delete poe; // Libera la memoria después de usar el objeto
            delete sephiroth; // Libera la memoria después de usar el objeto

        } else {
            std::cout << "Debes ingresar un valor valido" << std::endl;
            std::cout << "---------------------------------------------" << std::endl;
        }
    }
    return 0;
}
