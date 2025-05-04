cmake_minimum_required(VERSION 3.24)
project(curs7_LSI)

set(CMAKE_CXX_STANDARD 17)

add_executable(curs7_LSI main.cpp Node.h Colectie.h Iterator.h Colectie.tpp
        MultimeElementeGenericeOrdonata.cpp
        MultimeElementeGenericeOrdonata.tpp
        Tranzactie.cpp
        Tranzactie.h
        UI.cpp
        UI.h)
